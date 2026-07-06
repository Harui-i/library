#ifndef HARUILIB_DP_AUTOMATON_AUTOMATON_HPP
#define HARUILIB_DP_AUTOMATON_AUTOMATON_HPP

#include <functional>
#include <memory>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

template <typename Alphabet = int>
struct Dfa {
  using alphabet_type = Alphabet;
  using state_type = int;

  virtual int state_count() const = 0;
  virtual int initial_state() const = 0;
  virtual int next_state(int state, Alphabet c) const = 0;
  virtual bool accept(int state) const = 0;
  virtual ~Dfa() = default;
};

template <typename Alphabet = int>
using DfaPtr = std::shared_ptr<Dfa<Alphabet>>;

template <typename Alphabet = int>
class ProductPolicyDfa : public Dfa<Alphabet> {
  std::vector<DfaPtr<Alphabet>> dfas;
  std::vector<int> base;
  int states;
  std::function<bool(const std::vector<bool>&)> policy;

public:
  ProductPolicyDfa(std::vector<DfaPtr<Alphabet>> dfas,
                   std::function<bool(const std::vector<bool>&)> policy)
      : dfas(std::move(dfas)), states(1), policy(std::move(policy)) {
    base.resize(this->dfas.size());
    for(int i = 0; i < (int)this->dfas.size(); i++) {
      base[i] = states;
      states *= this->dfas[i]->state_count();
    }
  }

  int encode(const std::vector<int>& component_states) const {
    int state = 0;
    for(int i = 0; i < (int)dfas.size(); i++) {
      state += component_states[i] * base[i];
    }
    return state;
  }

  std::vector<int> decode(int state) const {
    std::vector<int> component_states(dfas.size());
    for(int i = 0; i < (int)dfas.size(); i++) {
      component_states[i] = (state / base[i]) % dfas[i]->state_count();
    }
    return component_states;
  }

  int state_count() const override {
    return states;
  }

  int initial_state() const override {
    std::vector<int> component_states(dfas.size());
    for(int i = 0; i < (int)dfas.size(); i++) {
      component_states[i] = dfas[i]->initial_state();
    }
    return encode(component_states);
  }

  int next_state(int state, Alphabet c) const override {
    std::vector<int> component_states = decode(state);
    for(int i = 0; i < (int)dfas.size(); i++) {
      component_states[i] = dfas[i]->next_state(component_states[i], c);
    }
    return encode(component_states);
  }

  bool accept(int state) const override {
    std::vector<int> component_states = decode(state);
    std::vector<bool> accepted(dfas.size());
    for(int i = 0; i < (int)dfas.size(); i++) {
      accepted[i] = dfas[i]->accept(component_states[i]);
    }
    return policy(accepted);
  }
};

template <typename Alphabet = int>
class AndDfa : public Dfa<Alphabet> {
  DfaPtr<Alphabet> lhs;
  DfaPtr<Alphabet> rhs;
  int rhs_states;

public:
  AndDfa(DfaPtr<Alphabet> lhs, DfaPtr<Alphabet> rhs)
      : lhs(std::move(lhs)), rhs(std::move(rhs)), rhs_states(this->rhs->state_count()) {}

  int encode(int lhs_state, int rhs_state) const {
    return lhs_state * rhs_states + rhs_state;
  }

  std::pair<int, int> decode(int state) const {
    return {state / rhs_states, state % rhs_states};
  }

  int state_count() const override {
    return lhs->state_count() * rhs->state_count();
  }

  int initial_state() const override {
    return encode(lhs->initial_state(), rhs->initial_state());
  }

  int next_state(int state, Alphabet c) const override {
    auto [a, b] = decode(state);
    return encode(lhs->next_state(a, c), rhs->next_state(b, c));
  }

  bool accept(int state) const override {
    auto [a, b] = decode(state);
    return lhs->accept(a) && rhs->accept(b);
  }
};

template <typename T, typename Alphabet = int>
T count_fixed_length(const Dfa<Alphabet>& dfa, const std::vector<Alphabet>& alphabet, int length) {
  std::unordered_map<int, T> dp, next_dp;
  dp[dfa.initial_state()] = T(1);

  for(int i = 0; i < length; i++) {
    next_dp.clear();
    for(const auto& [state, value] : dp) {
      for(const Alphabet& c : alphabet) {
        next_dp[dfa.next_state(state, c)] += value;
      }
    }
    dp.swap(next_dp);
  }

  T answer = T(0);
  for(const auto& [state, value] : dp) {
    if(dfa.accept(state)) answer += value;
  }
  return answer;
}

class DecimalLessEqualDfa : public Dfa<int> {
  std::vector<int> digits;

public:
  explicit DecimalLessEqualDfa(const std::string& n) {
    digits.reserve(n.size());
    for(char c : n) digits.push_back(c - '0');
  }

  int encode(int pos, int rel) const {
    return pos * 3 + rel;
  }

  std::pair<int, int> decode(int state) const {
    return {state / 3, state % 3};
  }

  int state_count() const override {
    return ((int)digits.size() + 1) * 3;
  }

  int initial_state() const override {
    return encode(0, 0);
  }

  int next_state(int state, int digit) const override {
    auto [pos, rel] = decode(state);
    if(pos == (int)digits.size()) return encode(pos, 2);

    if(rel == 0) {
      if(digit < digits[pos]) rel = 1;
      if(digit > digits[pos]) rel = 2;
    }
    return encode(pos + 1, rel);
  }

  bool accept(int state) const override {
    auto [pos, rel] = decode(state);
    return pos == (int)digits.size() && rel != 2;
  }
};

template <typename Alphabet = int>
class LeadingZeroSkipDfa : public Dfa<Alphabet> {
  DfaPtr<Alphabet> inner;
  Alphabet zero;
  int inner_states;

public:
  LeadingZeroSkipDfa(DfaPtr<Alphabet> inner, Alphabet zero = Alphabet())
      : inner(std::move(inner)), zero(zero), inner_states(this->inner->state_count()) {}

  int encode(bool started, int inner_state) const {
    return (started ? inner_states : 0) + inner_state;
  }

  std::pair<bool, int> decode(int state) const {
    if(state < inner_states) return {false, state};
    return {true, state - inner_states};
  }

  int state_count() const override {
    return inner_states * 2;
  }

  int initial_state() const override {
    return encode(false, inner->initial_state());
  }

  int next_state(int state, Alphabet c) const override {
    auto [started, inner_state] = decode(state);
    if(!started && c == zero) return encode(false, inner_state);
    return encode(true, inner->next_state(inner_state, c));
  }

  bool accept(int state) const override {
    auto [started, inner_state] = decode(state);
    if(started) return inner->accept(inner_state);

    int zero_state = inner->next_state(inner->initial_state(), zero);
    return inner->accept(zero_state);
  }
};

#endif
