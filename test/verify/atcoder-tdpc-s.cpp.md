---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: dp/automaton/automaton.hpp
    title: "\u6C7A\u5B9A\u6027\u6709\u9650\u30AA\u30FC\u30C8\u30DE\u30C8\u30F3(DFA,\
      \ Deterministic Finite Automaton)"
  - icon: ':question:'
    path: math/modint.hpp
    title: modint
  - icon: ':question:'
    path: template/template.hpp
    title: template/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://atcoder.jp/contests/dp/tasks/dp_s
  bundledCode: "#line 1 \"test/verify/atcoder-tdpc-s.cpp\"\n//#de   fi  n e PRO  LE\
    \  M \"https://atcoder.jp/contests/dp/tasks/dp_s\"\n\n#line 1 \"template/template.hpp\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\ntypedef long long ll;\ntypedef\
    \ unsigned int uint;\ntemplate<class T> inline bool chmax(T& a, const T& b) {if\
    \ (a<b) {a=b; return true;} return false;}\ntemplate<class T> inline bool chmin(T&\
    \ a, const T& b) {if (b<a) {a=b; return true;} return false;}\nconst int INTINF\
    \ = 1000001000;\nconst int INTMAX = 2147483647;\nconst ll LLMAX = 9223372036854775807;\n\
    const ll LLINF = 1000000000000000000;\n#line 2 \"math/modint.hpp\"\ntemplate<int\
    \ MOD>\nstruct static_modint {\n    int value;\n\n    constexpr static_modint()\
    \ : value(0) {}\n\n    constexpr static_modint(long long v) {\n        value =\
    \ int(((v % MOD) + MOD) % MOD);\n    }\n\n    constexpr static_modint& operator+=(const\
    \ static_modint& other) {\n        if ((value += other.value) >= MOD) value -=\
    \ MOD;\n        return *this;\n    }\n\n    constexpr static_modint& operator-=(const\
    \ static_modint& other) {\n        if ((value -= other.value) < 0) value += MOD;\n\
    \        return *this;\n    }\n\n    constexpr static_modint& operator*=(const\
    \ static_modint& other) {\n        value = int((long long)value * other.value\
    \ % MOD);\n        return *this;\n    }\n\n    constexpr static_modint operator+(const\
    \ static_modint& other) const {\n        return static_modint(*this) += other;\n\
    \    }\n\n    constexpr static_modint operator-(const static_modint& other) const\
    \ {\n        return static_modint(*this) -= other;\n    }\n\n    constexpr static_modint\
    \ operator*(const static_modint& other) const {\n        return static_modint(*this)\
    \ *= other;\n    }\n\n    constexpr static_modint pow(long long exp) const {\n\
    \        static_modint base = *this, res = 1;\n        while (exp > 0) {\n   \
    \         if (exp & 1) res *= base;\n            base *= base;\n            exp\
    \ >>= 1;\n        }\n        return res;\n    }\n\n    constexpr static_modint\
    \ inv() const {\n        return pow(MOD - 2);\n    }\n\n    constexpr static_modint&\
    \ operator/=(const static_modint& other) {\n        return *this *= other.inv();\n\
    \    }\n\n    constexpr static_modint operator/(const static_modint& other) const\
    \ {\n        return static_modint(*this) /= other;\n    }\n\n    constexpr bool\
    \ operator!=(const static_modint& other) const {\n        return val() != other.val();\n\
    \    }\n\n    constexpr bool operator==(const static_modint& other) const {\n\
    \        return val() == other.val();\n    }\n\n    int val() const {\n      return\
    \ this->value;\n    }\n\n    friend std::ostream& operator<<(std::ostream& os,\
    \ const static_modint& mi) {\n        return os << mi.value;\n    }\n\n    friend\
    \ std::istream& operator>>(std::istream& is, static_modint& mi) {\n        long\
    \ long x;\n        is >> x;\n        mi = static_modint(x);\n        return is;\n\
    \    }\n};\n\ntemplate <int mod>\nusing modint = static_modint<mod>;\nusing modint998244353\
    \ = modint<998244353>;\nusing modint100000007 = modint<1000000007>;\n#line 1 \"\
    dp/automaton/automaton.hpp\"\n// https://shino16.github.io/blog/post/algo/%E3%82%AA%E3%83%BC%E3%83%88%E3%83%9E%E3%83%88%E3%83%B3/\n\
    // Dfa\u30A4\u30F3\u30BF\u30FC\u30D5\u30A7\u30FC\u30B9\ntemplate <typename Alphabet,\
    \ typename State>\nclass Dfa {\npublic:\n  virtual State init() const = 0; //\
    \ \u521D\u671F\u72B6\u614B\u3092\u8FD4\u3059\n  virtual State next([[maybe_unused]]\
    \ State s, [[maybe_unused]] Alphabet a, [[maybe_unused]]int i) const = 0; // s\u306B\
    a\u3092\u5165\u529B\u3068\u3057\u3066\u4E0E\u3048\u305F\u6642\u306E\u6B21\u306E\
    \u72B6\u614B\u3092\u8FD4\u3059\n  virtual bool accept([[maybe_unused]] State s)\
    \ const = 0; // s\u3092\u30AA\u30FC\u30C8\u30DE\u30C8\u30F3\u304C\u53D7\u7406\u3059\
    \u308B\u304B\u3069\u3046\u304B\n  virtual bool successful([[maybe_unused]] State\
    \ s) const { return false; } // \u3069\u3046\u3044\u3046\u3075\u3046\u306Bnext\u3057\
    \u3066\u3044\u3053\u3046\u304C\u3001\u7D76\u5BFE\u306Baccept\u3055\u308C\u308B\
    \u72B6\u614B\u304B\u3069\u3046\u304B\n  virtual bool unsuccessful([[maybe_unused]]\
    \ State s) const { return false; } // \u3069\u3046\u3044\u3046\u3075\u3046\u306B\
    next\u3057\u3066\u3044\u3053\u3046\u304C\u3001\u7D76\u5BFE\u306Baccpet\u3055\u308C\
    \u306A\u3044\u72B6\u614B\u304B\u3069\u3046\u304B\n};\n#line 6 \"test/verify/atcoder-tdpc-s.cpp\"\
    \n\nusing mint = modint100000007;\n\nstruct dpState {\n  int cmp_state; // -1:\
    \ less than K, 0: equal to K, 1: greater than K\n  int digsum_remainder; // digit\
    \ sum % D\n\n  dpState(int _cmp_state, int _digsum_remainder) : cmp_state(_cmp_state),\
    \ digsum_remainder(_digsum_remainder) {}\n\n  bool operator<(const dpState& other)\
    \ const {\n    return make_pair(cmp_state, digsum_remainder) < make_pair(other.cmp_state,\
    \ other.digsum_remainder);\n  }\n};\n\n// K\u4EE5\u4E0B\u306E\u3001\u6841\u548C\
    \u304CD\u306E\u500D\u6570\u306E\u6570\u306E\u307F\u3092\u53D7\u7406\u3059\u308B\
    \u30AA\u30FC\u30C8\u30DE\u30C8\u30F3\nclass Automaton : public Dfa<char, dpState>\
    \ { \n  const vector<char> K_vec;\n  const int D; \n  \npublic:\n  using State\
    \ = dpState;\n\n  Automaton (const vector<char> _K_vec, int _d) : K_vec(_K_vec),\
    \ D(_d) {}\n\n  State init() const override {\n    return State(0, 0);\n  }\n\n\
    \  State next(State s, char c, int i) const {\n    State ret = s;\n    if (s.cmp_state\
    \ == 0) {\n      if (c > K_vec[i]) ret.cmp_state = 1;\n      if (c < K_vec[i])\
    \ ret.cmp_state = -1;\n    }\n\n    ret.digsum_remainder += c - '0';\n    ret.digsum_remainder\
    \ %= D;\n\n    return ret;\n  }\n\n  bool accept(State s) const override {\n \
    \   return s.cmp_state != 1 && s.digsum_remainder % D == 0;\n  }\n\n  bool unsuccessful(State\
    \ s) const override {\n    return s.cmp_state == 1;\n  }\n\n  bool successful([[maybe_unused]]\
    \ State s) const override {\n    return false;\n  }\n\n};\n\nint main() {\n  ios::sync_with_stdio(0);\
    \ cin.tie(0); cout.tie(0);\n  string K_str; cin >> K_str;\n  vector<char> K_vec(K_str.begin(),\
    \ K_str.end());\n\n  int D; cin >> D; \n  \n  Automaton atm(K_vec, D);\n\n  vector<char>\
    \ alphabet = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};\n\n  int Ksize\
    \ = K_vec.size();\n  map<dpState, mint> dp1, dp2; \n  mint ans = 0;\n\n  dp1[atm.init()]\
    \ = 1;\n\n  for(int i=0; i<Ksize; i++) {\n    for (char c : alphabet) {\n    \
    \  for (pair<dpState, mint> st_cnt : dp1) {\n        dpState state = st_cnt.first;\n\
    \        mint cnt = st_cnt.second;        \n\n        dpState newState = atm.next(state,\
    \ c, i);\n        if (atm.unsuccessful(newState)) continue;\n\n        dp2[newState]\
    \ += cnt;\n      }\n    }\n\n    swap(dp1,dp2);\n    dp2.clear();\n  }\n\n\n \
    \ for (pair<dpState, mint> st_cnt: dp1) {\n    if (atm.accept(st_cnt.first)) {\n\
    \      ans += st_cnt.second;\n    }\n  }\n  ans -= 1;// 0\u3092\u30AB\u30A6\u30F3\
    \u30C8\u3057\u3066\u3057\u307E\u3063\u3066\u3044\u308B\u304C\u3001\u30BC\u30ED\
    \u306F\u6B63\u6574\u6570\u3067\u306F\u306A\u3044\u306E\u3067\u7B54\u3048\u304B\
    \u30891\u5F15\u304F\n  cout << ans.val() << endl; \n  return 0;\n}\n"
  code: "//#de   fi  n e PRO  LE  M \"https://atcoder.jp/contests/dp/tasks/dp_s\"\n\
    \n#include \"../../template/template.hpp\"\n#include \"../../math/modint.hpp\"\
    \n#include \"../../dp/automaton/automaton.hpp\"\n\nusing mint = modint100000007;\n\
    \nstruct dpState {\n  int cmp_state; // -1: less than K, 0: equal to K, 1: greater\
    \ than K\n  int digsum_remainder; // digit sum % D\n\n  dpState(int _cmp_state,\
    \ int _digsum_remainder) : cmp_state(_cmp_state), digsum_remainder(_digsum_remainder)\
    \ {}\n\n  bool operator<(const dpState& other) const {\n    return make_pair(cmp_state,\
    \ digsum_remainder) < make_pair(other.cmp_state, other.digsum_remainder);\n  }\n\
    };\n\n// K\u4EE5\u4E0B\u306E\u3001\u6841\u548C\u304CD\u306E\u500D\u6570\u306E\u6570\
    \u306E\u307F\u3092\u53D7\u7406\u3059\u308B\u30AA\u30FC\u30C8\u30DE\u30C8\u30F3\
    \nclass Automaton : public Dfa<char, dpState> { \n  const vector<char> K_vec;\n\
    \  const int D; \n  \npublic:\n  using State = dpState;\n\n  Automaton (const\
    \ vector<char> _K_vec, int _d) : K_vec(_K_vec), D(_d) {}\n\n  State init() const\
    \ override {\n    return State(0, 0);\n  }\n\n  State next(State s, char c, int\
    \ i) const {\n    State ret = s;\n    if (s.cmp_state == 0) {\n      if (c > K_vec[i])\
    \ ret.cmp_state = 1;\n      if (c < K_vec[i]) ret.cmp_state = -1;\n    }\n\n \
    \   ret.digsum_remainder += c - '0';\n    ret.digsum_remainder %= D;\n\n    return\
    \ ret;\n  }\n\n  bool accept(State s) const override {\n    return s.cmp_state\
    \ != 1 && s.digsum_remainder % D == 0;\n  }\n\n  bool unsuccessful(State s) const\
    \ override {\n    return s.cmp_state == 1;\n  }\n\n  bool successful([[maybe_unused]]\
    \ State s) const override {\n    return false;\n  }\n\n};\n\nint main() {\n  ios::sync_with_stdio(0);\
    \ cin.tie(0); cout.tie(0);\n  string K_str; cin >> K_str;\n  vector<char> K_vec(K_str.begin(),\
    \ K_str.end());\n\n  int D; cin >> D; \n  \n  Automaton atm(K_vec, D);\n\n  vector<char>\
    \ alphabet = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};\n\n  int Ksize\
    \ = K_vec.size();\n  map<dpState, mint> dp1, dp2; \n  mint ans = 0;\n\n  dp1[atm.init()]\
    \ = 1;\n\n  for(int i=0; i<Ksize; i++) {\n    for (char c : alphabet) {\n    \
    \  for (pair<dpState, mint> st_cnt : dp1) {\n        dpState state = st_cnt.first;\n\
    \        mint cnt = st_cnt.second;        \n\n        dpState newState = atm.next(state,\
    \ c, i);\n        if (atm.unsuccessful(newState)) continue;\n\n        dp2[newState]\
    \ += cnt;\n      }\n    }\n\n    swap(dp1,dp2);\n    dp2.clear();\n  }\n\n\n \
    \ for (pair<dpState, mint> st_cnt: dp1) {\n    if (atm.accept(st_cnt.first)) {\n\
    \      ans += st_cnt.second;\n    }\n  }\n  ans -= 1;// 0\u3092\u30AB\u30A6\u30F3\
    \u30C8\u3057\u3066\u3057\u307E\u3063\u3066\u3044\u308B\u304C\u3001\u30BC\u30ED\
    \u306F\u6B63\u6574\u6570\u3067\u306F\u306A\u3044\u306E\u3067\u7B54\u3048\u304B\
    \u30891\u5F15\u304F\n  cout << ans.val() << endl; \n  return 0;\n}"
  dependsOn:
  - template/template.hpp
  - math/modint.hpp
  - dp/automaton/automaton.hpp
  isVerificationFile: false
  path: test/verify/atcoder-tdpc-s.cpp
  requiredBy: []
  timestamp: '2024-05-29 18:35:44+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: test/verify/atcoder-tdpc-s.cpp
layout: document
redirect_from:
- /library/test/verify/atcoder-tdpc-s.cpp
- /library/test/verify/atcoder-tdpc-s.cpp.html
title: test/verify/atcoder-tdpc-s.cpp
---
