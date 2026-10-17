---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: dp/automaton/automaton.hpp
    title: "\u6C7A\u5B9A\u6027\u6709\u9650\u30AA\u30FC\u30C8\u30DE\u30C8\u30F3(DFA,\
      \ Deterministic Finite Automaton)"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/verify/aoj-0570.test.cpp
    title: test/verify/aoj-0570.test.cpp
  - icon: ':x:'
    path: test/verify/yuki-372-itsautomatic.test.cpp
    title: test/verify/yuki-372-itsautomatic.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links:
    - https://harui-i.github.io/library/dp/automaton/remainder.hpp.html
  bundledCode: "#line 1 \"dp/automaton/remainder.hpp\"\n\n\n// https://harui-i.github.io/library/dp/automaton/remainder.hpp.html\n\
    \n#line 1 \"dp/automaton/automaton.hpp\"\n\n\n// https://harui-i.github.io/library/dp/automaton/automaton.hpp.html\n\
    \n#include <functional>\n#include <memory>\n#include <string>\n#include <unordered_map>\n\
    #include <utility>\n#include <vector>\n\ntemplate <typename Alphabet = int>\n\
    struct Dfa {\n  using alphabet_type = Alphabet;\n  using state_type = int;\n\n\
    \  virtual int state_count() const = 0;\n  virtual int initial_state() const =\
    \ 0;\n  virtual int next_state(int state, Alphabet c) const = 0;\n  virtual bool\
    \ accept(int state) const = 0;\n  virtual ~Dfa() = default;\n};\n\ntemplate <typename\
    \ Alphabet = int>\nusing DfaPtr = std::shared_ptr<Dfa<Alphabet>>;\n\ntemplate\
    \ <typename Alphabet = int>\nclass ProductPolicyDfa : public Dfa<Alphabet> {\n\
    \  std::vector<DfaPtr<Alphabet>> dfas;\n  std::vector<int> base;\n  int states;\n\
    \  std::function<bool(const std::vector<bool>&)> policy;\n\npublic:\n  ProductPolicyDfa(std::vector<DfaPtr<Alphabet>>\
    \ dfas,\n                   std::function<bool(const std::vector<bool>&)> policy)\n\
    \      : dfas(std::move(dfas)), states(1), policy(std::move(policy)) {\n    base.resize(this->dfas.size());\n\
    \    for(int i = 0; i < (int)this->dfas.size(); i++) {\n      base[i] = states;\n\
    \      states *= this->dfas[i]->state_count();\n    }\n  }\n\n  int encode(const\
    \ std::vector<int>& component_states) const {\n    int state = 0;\n    for(int\
    \ i = 0; i < (int)dfas.size(); i++) {\n      state += component_states[i] * base[i];\n\
    \    }\n    return state;\n  }\n\n  std::vector<int> decode(int state) const {\n\
    \    std::vector<int> component_states(dfas.size());\n    for(int i = 0; i < (int)dfas.size();\
    \ i++) {\n      component_states[i] = (state / base[i]) % dfas[i]->state_count();\n\
    \    }\n    return component_states;\n  }\n\n  int state_count() const override\
    \ {\n    return states;\n  }\n\n  int initial_state() const override {\n    std::vector<int>\
    \ component_states(dfas.size());\n    for(int i = 0; i < (int)dfas.size(); i++)\
    \ {\n      component_states[i] = dfas[i]->initial_state();\n    }\n    return\
    \ encode(component_states);\n  }\n\n  int next_state(int state, Alphabet c) const\
    \ override {\n    std::vector<int> component_states = decode(state);\n    for(int\
    \ i = 0; i < (int)dfas.size(); i++) {\n      component_states[i] = dfas[i]->next_state(component_states[i],\
    \ c);\n    }\n    return encode(component_states);\n  }\n\n  bool accept(int state)\
    \ const override {\n    std::vector<int> component_states = decode(state);\n \
    \   std::vector<bool> accepted(dfas.size());\n    for(int i = 0; i < (int)dfas.size();\
    \ i++) {\n      accepted[i] = dfas[i]->accept(component_states[i]);\n    }\n \
    \   return policy(accepted);\n  }\n};\n\ntemplate <typename Alphabet = int>\n\
    class AndDfa : public Dfa<Alphabet> {\n  DfaPtr<Alphabet> lhs;\n  DfaPtr<Alphabet>\
    \ rhs;\n  int rhs_states;\n\npublic:\n  AndDfa(DfaPtr<Alphabet> lhs, DfaPtr<Alphabet>\
    \ rhs)\n      : lhs(std::move(lhs)), rhs(std::move(rhs)), rhs_states(this->rhs->state_count())\
    \ {}\n\n  int encode(int lhs_state, int rhs_state) const {\n    return lhs_state\
    \ * rhs_states + rhs_state;\n  }\n\n  std::pair<int, int> decode(int state) const\
    \ {\n    return {state / rhs_states, state % rhs_states};\n  }\n\n  int state_count()\
    \ const override {\n    return lhs->state_count() * rhs->state_count();\n  }\n\
    \n  int initial_state() const override {\n    return encode(lhs->initial_state(),\
    \ rhs->initial_state());\n  }\n\n  int next_state(int state, Alphabet c) const\
    \ override {\n    auto [a, b] = decode(state);\n    return encode(lhs->next_state(a,\
    \ c), rhs->next_state(b, c));\n  }\n\n  bool accept(int state) const override\
    \ {\n    auto [a, b] = decode(state);\n    return lhs->accept(a) && rhs->accept(b);\n\
    \  }\n};\n\ntemplate <typename T, typename Alphabet = int>\nT count_fixed_length(const\
    \ Dfa<Alphabet>& dfa, const std::vector<Alphabet>& alphabet, int length) {\n \
    \ std::unordered_map<int, T> dp, next_dp;\n  dp[dfa.initial_state()] = T(1);\n\
    \n  for(int i = 0; i < length; i++) {\n    next_dp.clear();\n    for(const auto&\
    \ [state, value] : dp) {\n      for(const Alphabet& c : alphabet) {\n        next_dp[dfa.next_state(state,\
    \ c)] += value;\n      }\n    }\n    dp.swap(next_dp);\n  }\n\n  T answer = T(0);\n\
    \  for(const auto& [state, value] : dp) {\n    if(dfa.accept(state)) answer +=\
    \ value;\n  }\n  return answer;\n}\n\nclass DecimalLessEqualDfa : public Dfa<int>\
    \ {\n  std::vector<int> digits;\n\npublic:\n  explicit DecimalLessEqualDfa(const\
    \ std::string& n) {\n    digits.reserve(n.size());\n    for(char c : n) digits.push_back(c\
    \ - '0');\n  }\n\n  int encode(int pos, int rel) const {\n    return pos * 3 +\
    \ rel;\n  }\n\n  std::pair<int, int> decode(int state) const {\n    return {state\
    \ / 3, state % 3};\n  }\n\n  int state_count() const override {\n    return ((int)digits.size()\
    \ + 1) * 3;\n  }\n\n  int initial_state() const override {\n    return encode(0,\
    \ 0);\n  }\n\n  int next_state(int state, int digit) const override {\n    auto\
    \ [pos, rel] = decode(state);\n    if(pos == (int)digits.size()) return encode(pos,\
    \ 2);\n\n    if(rel == 0) {\n      if(digit < digits[pos]) rel = 1;\n      if(digit\
    \ > digits[pos]) rel = 2;\n    }\n    return encode(pos + 1, rel);\n  }\n\n  bool\
    \ accept(int state) const override {\n    auto [pos, rel] = decode(state);\n \
    \   return pos == (int)digits.size() && rel != 2;\n  }\n};\n\ntemplate <typename\
    \ Alphabet = int>\nclass LeadingZeroSkipDfa : public Dfa<Alphabet> {\n  DfaPtr<Alphabet>\
    \ inner;\n  Alphabet zero;\n  int inner_states;\n\npublic:\n  LeadingZeroSkipDfa(DfaPtr<Alphabet>\
    \ inner, Alphabet zero = Alphabet())\n      : inner(std::move(inner)), zero(zero),\
    \ inner_states(this->inner->state_count()) {}\n\n  int encode(bool started, int\
    \ inner_state) const {\n    return (started ? inner_states : 0) + inner_state;\n\
    \  }\n\n  std::pair<bool, int> decode(int state) const {\n    if(state < inner_states)\
    \ return {false, state};\n    return {true, state - inner_states};\n  }\n\n  int\
    \ state_count() const override {\n    return inner_states * 2;\n  }\n\n  int initial_state()\
    \ const override {\n    return encode(false, inner->initial_state());\n  }\n\n\
    \  int next_state(int state, Alphabet c) const override {\n    auto [started,\
    \ inner_state] = decode(state);\n    if(!started && c == zero) return encode(false,\
    \ inner_state);\n    return encode(true, inner->next_state(inner_state, c));\n\
    \  }\n\n  bool accept(int state) const override {\n    auto [started, inner_state]\
    \ = decode(state);\n    if(started) return inner->accept(inner_state);\n\n   \
    \ int zero_state = inner->next_state(inner->initial_state(), zero);\n    return\
    \ inner->accept(zero_state);\n  }\n};\n\n\n#line 6 \"dp/automaton/remainder.hpp\"\
    \n\nclass DecimalRemainderDfa : public Dfa<int> {\n  int mod;\n\npublic:\n  explicit\
    \ DecimalRemainderDfa(int mod) : mod(mod) {}\n\n  int state_count() const override\
    \ {\n    return mod;\n  }\n\n  int initial_state() const override {\n    return\
    \ 0;\n  }\n\n  int next_state(int state, int digit) const override {\n    return\
    \ ((long long)state * 10 + digit) % mod;\n  }\n\n  bool accept(int state) const\
    \ override {\n    return state == 0;\n  }\n};\n\nusing RemainderAutomaton = DecimalRemainderDfa;\n\
    \n\n"
  code: "#ifndef HARUILIB_DP_AUTOMATON_REMAINDER_HPP\n#define HARUILIB_DP_AUTOMATON_REMAINDER_HPP\n\
    // https://harui-i.github.io/library/dp/automaton/remainder.hpp.html\n\n#include\
    \ \"dp/automaton/automaton.hpp\"\n\nclass DecimalRemainderDfa : public Dfa<int>\
    \ {\n  int mod;\n\npublic:\n  explicit DecimalRemainderDfa(int mod) : mod(mod)\
    \ {}\n\n  int state_count() const override {\n    return mod;\n  }\n\n  int initial_state()\
    \ const override {\n    return 0;\n  }\n\n  int next_state(int state, int digit)\
    \ const override {\n    return ((long long)state * 10 + digit) % mod;\n  }\n\n\
    \  bool accept(int state) const override {\n    return state == 0;\n  }\n};\n\n\
    using RemainderAutomaton = DecimalRemainderDfa;\n\n#endif\n"
  dependsOn:
  - dp/automaton/automaton.hpp
  isVerificationFile: false
  path: dp/automaton/remainder.hpp
  requiredBy: []
  timestamp: '2026-10-17 23:49:45+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/verify/yuki-372-itsautomatic.test.cpp
  - test/verify/aoj-0570.test.cpp
documentation_of: dp/automaton/remainder.hpp
layout: document
title: "\u3042\u307E\u308A\u3092\u7BA1\u7406\u3059\u308B\u30AA\u30FC\u30C8\u30DE\u30C8\
  \u30F3(remainder.hpp)"
---

10 進表記を左から読んで、値の `mod` での余りを状態として持つ DFA。

```cpp
DecimalRemainderDfa dfa(mod);
```

状態数は `mod`。受理状態は余り `0`。

```cpp
int next_state(int state, int digit) {
  return (state * 10 + digit) % mod;
}
```

固定長 0 埋めの桁 DP で「通常の 10 進表記としての値」を扱いたい場合は、`LeadingZeroSkipDfa` で包む。

```cpp
DfaPtr<int> multiple_of_m = make_shared<LeadingZeroSkipDfa<int>>(
    make_shared<DecimalRemainderDfa>(m));
```

余りだけなら先頭 0 を読んでも値は変わらないが、他の通常表記向け DFA と同じ形で合成できるので、桁 DP では包んでおくと扱いが揃う。
