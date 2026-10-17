---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':question:'
    path: dp/automaton/remainder.hpp
    title: "\u3042\u307E\u308A\u3092\u7BA1\u7406\u3059\u308B\u30AA\u30FC\u30C8\u30DE\
      \u30C8\u30F3(remainder.hpp)"
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
    - https://harui-i.github.io/library/dp/automaton/automaton.hpp.html
  bundledCode: "#line 1 \"dp/automaton/automaton.hpp\"\n\n\n// https://harui-i.github.io/library/dp/automaton/automaton.hpp.html\n\
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
    \ inner->accept(zero_state);\n  }\n};\n\n\n"
  code: "#ifndef HARUILIB_DP_AUTOMATON_AUTOMATON_HPP\n#define HARUILIB_DP_AUTOMATON_AUTOMATON_HPP\n\
    // https://harui-i.github.io/library/dp/automaton/automaton.hpp.html\n\n#include\
    \ <functional>\n#include <memory>\n#include <string>\n#include <unordered_map>\n\
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
    \ inner->accept(zero_state);\n  }\n};\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: dp/automaton/automaton.hpp
  requiredBy:
  - dp/automaton/remainder.hpp
  timestamp: '2026-10-17 23:49:45+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/verify/yuki-372-itsautomatic.test.cpp
  - test/verify/aoj-0570.test.cpp
documentation_of: dp/automaton/automaton.hpp
layout: document
title: "\u6C7A\u5B9A\u6027\u6709\u9650\u30AA\u30FC\u30C8\u30DE\u30C8\u30F3(DFA, Deterministic\
  \ Finite Automaton)"
---

有限個の状態を `int` で管理する DFA。

桁 DP などで、「上限以下」「余りが 0」「パターンを満たす」のような条件をそれぞれ DFA として書き、それらを積 DFA で合成して使うことを想定している。

## 使い方の流れ

1. 条件を 1 つずつ DFA として書く
2. `AndDfa` や `ProductPolicyDfa` で条件を合成する
3. `count_fixed_length` で長さ固定の列を全部流して数える

「`0 <= x <= N` かつ `x` が条件を満たす数を数える」タイプの桁 DP では、`N` の桁数に合わせて 0 埋めした文字列を考える。

```cpp
vector<int> alphabet = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

DfaPtr<int> less_equal = make_shared<DecimalLessEqualDfa>(N);
DfaPtr<int> condition = make_shared<LeadingZeroSkipDfa<int>>(
    make_shared<MyDecimalConditionDfa>());

DfaPtr<int> whole = make_shared<AndDfa<int>>(less_equal, condition);
mint ans = count_fixed_length<mint>(*whole, alphabet, N.size());
```

`DecimalLessEqualDfa` は 0 埋めされた固定長文字列をそのまま `N` と比較する。
一方で、通常の 10 進表記に対する条件 DFA は先頭 0 を読ませると意味が変わることがあるので、必要なら `LeadingZeroSkipDfa` で包む。

例: `N = "123"` のとき、DP は `"000"` から `"999"` までの長さ 3 の文字列を読む。
`DecimalLessEqualDfa("123")` は `"007"` を 7 として `<= 123` と判定できる。
`LeadingZeroSkipDfa` は内側の DFA に `"007"` を `"7"` として読ませる。

## DFA の書き方

```cpp
template <typename Alphabet = int>
struct Dfa {
  virtual int state_count() const = 0;
  virtual int initial_state() const = 0;
  virtual int next_state(int state, Alphabet c) const = 0;
  virtual bool accept(int state) const = 0;
};
```

状態は `0, 1, ..., state_count() - 1` の整数にエンコードする。

- `state_count()`: 状態数
- `initial_state()`: 初期状態
- `next_state(state, c)`: 状態 `state` で文字 `c` を読んだ後の状態
- `accept(state)`: 最終状態 `state` を受理するか

問題固有の条件はこの 4 つだけ実装すればよい。

```cpp
class Contains3Dfa : public Dfa<int> {
public:
  int state_count() const override { return 2; }
  int initial_state() const override { return 0; }

  int next_state(int state, int digit) const override {
    return state || digit == 3;
  }

  bool accept(int state) const override {
    return state == 1;
  }
};
```

## 合成

- `AndDfa`: 2 つの DFA の両方が受理する文字列を受理する積 DFA
- `ProductPolicyDfa`: 任意個の DFA を積にして、受理状態の真偽列から受理判定を決める DFA

```cpp
DfaPtr<int> a = make_shared<A>();
DfaPtr<int> b = make_shared<B>();
DfaPtr<int> both = make_shared<AndDfa<int>>(a, b);
```

「3 つの条件のうちちょうど 1 つを満たす」のような受理条件は `ProductPolicyDfa` を使う。

```cpp
vector<DfaPtr<int>> conditions = {a, b, c};

DfaPtr<int> exactly_one = make_shared<ProductPolicyDfa<int>>(
    conditions,
    [](const vector<bool>& ok) {
      int cnt = 0;
      for(bool x : ok) if(x) cnt++;
      return cnt == 1;
    });
```

## 用意してある DFA / wrapper

### `DecimalLessEqualDfa`

固定長 0 埋め 10 進文字列として読んだ値が `N` 以下なら受理する。
桁 DP の tight に相当する。

```cpp
DfaPtr<int> less_equal = make_shared<DecimalLessEqualDfa>(N);
```

### `LeadingZeroSkipDfa`

先頭 0 を内側の DFA に流さない wrapper。
全桁が 0 の場合は、内側の DFA に 0 を 1 回だけ読ませた状態で受理判定する。

```cpp
DfaPtr<int> normal_decimal_condition = make_shared<LeadingZeroSkipDfa<int>>(
    make_shared<MyDecimalConditionDfa>());
```

`DecimalRemainderDfa` やジグザグ数 DFA のように「普通の 10 進表記」を読む DFA は、固定長 DP で使うとき基本的にこれで包む。

## 数え上げ

`count_fixed_length<T>(dfa, alphabet, length)` は、長さ `length` の列をすべて DFA に流し、受理されるものの個数を `T` で返す。
`T` は `+=` と `T(0)`, `T(1)` が使えればよいので、`modint` を渡せる。

```cpp
mint ans = count_fixed_length<mint>(*dfa, alphabet, L);
```

## Verify

- `test/verify/aoj-0570.test.cpp`

AOJ 0570 は「`A <= x <= B`」「`x % M == 0`」「`x` がジグザグ数」の 3 条件を DFA として合成して解いている。
区間 `[A, B]` は `count(<= B) - count(<= A - 1)` で処理している。
