#ifndef HARUILIB_DP_AUTOMATON_REMAINDER_HPP
#define HARUILIB_DP_AUTOMATON_REMAINDER_HPP

#include "dp/automaton/automaton.hpp"

class DecimalRemainderDfa : public Dfa<int> {
  int mod;

public:
  explicit DecimalRemainderDfa(int mod) : mod(mod) {}

  int state_count() const override {
    return mod;
  }

  int initial_state() const override {
    return 0;
  }

  int next_state(int state, int digit) const override {
    return ((long long)state * 10 + digit) % mod;
  }

  bool accept(int state) const override {
    return state == 0;
  }
};

using RemainderAutomaton = DecimalRemainderDfa;

#endif
