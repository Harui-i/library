---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: dp/automaton/automaton.hpp
    title: "\u6C7A\u5B9A\u6027\u6709\u9650\u30AA\u30FC\u30C8\u30DE\u30C8\u30F3(DFA,\
      \ Deterministic Finite Automaton)"
  - icon: ':heavy_check_mark:'
    path: dp/automaton/remainder.hpp
    title: "\u3042\u307E\u308A\u3092\u7BA1\u7406\u3059\u308B\u30AA\u30FC\u30C8\u30DE\
      \u30C8\u30F3(remainder.hpp)"
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
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://yukicoder.me/problems/no/372
    links:
    - https://yukicoder.me/problems/no/372
  bundledCode: "#line 1 \"test/verify/yuki-372-itsautomatic.test.cpp\"\n#define PROBLEM\
    \ \"https://yukicoder.me/problems/no/372\"\n\n#line 1 \"template/template.hpp\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\ntypedef long long ll;\ntypedef\
    \ unsigned int uint;\ntemplate<class T> inline bool chmax(T& a, const T& b) {if\
    \ (a<b) {a=b; return true;} return false;}\ntemplate<class T> inline bool chmin(T&\
    \ a, const T& b) {if (b<a) {a=b; return true;} return false;}\nconst int INTINF\
    \ = 1000001000;\nconst int INTMAX = 2147483647;\nconst ll LLMAX = 9223372036854775807;\n\
    const ll LLINF = 1000000000000000000;\n#line 1 \"math/modint.hpp\"\n\n\n\ntemplate<int\
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
    \  = modint<998244353>;\nusing modint1000000007 = modint<1000000007>;\n\n\n#line\
    \ 1 \"dp/automaton/automaton.hpp\"\n// https://shino16.github.io/blog/post/algo/%E3%82%AA%E3%83%BC%E3%83%88%E3%83%9E%E3%83%88%E3%83%B3/\n\
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
    \u306A\u3044\u72B6\u614B\u304B\u3069\u3046\u304B\n};\n#line 2 \"dp/automaton/remainder.hpp\"\
    \n\n// next\u306F\u6570\u5B57\u306E\u53F3\u7AEF\u306B\u66F8\u304D\u52A0\u3048\u308B\
    \u30A4\u30E1\u30FC\u30B8\u3002\u3064\u307E\u308A\u3001\u3044\u308D\u3044\u308D\
    \u306A\u6841\u6570\u3092\u8003\u3048\u3089\u308C\u308B\u3002\n// \u3057\u304B\u3057\
    \u3001\u56FA\u5B9A\u3057\u305F\u6841\u6570\u306B\u5BFE\u3057\u3066\u5DE6\u304B\
    \u3089\u57CB\u3081\u3066\u3044\u304F\u30D1\u30BF\u30FC\u30F3\u3067\u4F7F\u3044\
    \u305F\u3044\u5834\u5408\u3082\u3042\u308A\u305D\u3046\u3002\n// \u6570\u5B57\u306E\
    M\u306E\u500D\u6570\u306E\u307F\u53D7\u7406\u3059\u308B\u30AA\u30FC\u30C8\u30DE\
    \u30C8\u30F3\ntemplate <typename Alphabet> \nclass RemainderAutomaton : public\
    \ Dfa<Alphabet, int> {\n  const int M;\n  const int N_siz;\n\npublic:\n  using\
    \ State = int;\n  RemainderAutomaton(int _N_siz, int _M) : M(_M), N_siz(_N_siz)\
    \ {}\n\n  State init() const override {\n    return State(0);\n  }\n\n  State\
    \ next(State s, char c, [[maybe_unused]] int i) const override {\n    State ret\
    \ = ((long long)s*10 + (long long)(c - '0') )%M; \n\n    return ret;\n  }\n\n\
    \  bool accept(State s) const override {\n    return s == 0;\n  }\n\n  bool successful\
    \ ([[maybe_unused]] State  s) const override {\n    return false;\n  }\n\n  bool\
    \ unsuccessful([[maybe_unused]] State s) const override {\n    return false;\n\
    \  }\n  \n};\n#line 6 \"test/verify/yuki-372-itsautomatic.test.cpp\"\n\nusing\
    \ mint = modint1000000007;\n\nint main() {\n  ios::sync_with_stdio(0); cin.tie(0);\
    \ cout.tie(0);\n\n  string S; cin >> S;\n  vector<char> svec(S.begin(), S.end());\n\
    \n  int M; cin >> M;\n\n  vector<char> alphabet = { '0', '1', '2', '3', '4', '5',\
    \ '6', '7', '8', '9' };\n\n  RemainderAutomaton<char> ra(S.size(), M);\n\n\n \
    \ mint ans = 0;\n  vector<mint>dp1(M), dp2(M);\n\n\n  for (int i = 0; i < (int)\
    \ S.size(); i++) {\n    if (S[i] == '0') ans += 1;\n    else {\n      dp2[(S[i]\
    \ - '0') % M] += 1; // only one word substring, 'S[i]' .\n    }\n    for (int\
    \ j = 0; j < M; j++) {\n\n      dp2[j] += dp1[j]; // the case when S[i] is not\
    \ choosed\n\n      dp2[(j * 10 + S[i] - '0') % M] += dp1[j]; // the case when\
    \ S[i] is choosen and added into past substrings\n\n    }\n\n    swap(dp1, dp2);\n\
    \    dp2.assign(M, 0);\n  }\n  for(int i=0; i<M; i++) {\n    if (ra.accept(i))\
    \ ans += dp1[i];\n  }\n  cout << ans.val() << endl;\n\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/372\"\n\n#include \"template/template.hpp\"\
    \n#include \"math/modint.hpp\"\n#include \"dp/automaton/remainder.hpp\"\n\nusing\
    \ mint = modint1000000007;\n\nint main() {\n  ios::sync_with_stdio(0); cin.tie(0);\
    \ cout.tie(0);\n\n  string S; cin >> S;\n  vector<char> svec(S.begin(), S.end());\n\
    \n  int M; cin >> M;\n\n  vector<char> alphabet = { '0', '1', '2', '3', '4', '5',\
    \ '6', '7', '8', '9' };\n\n  RemainderAutomaton<char> ra(S.size(), M);\n\n\n \
    \ mint ans = 0;\n  vector<mint>dp1(M), dp2(M);\n\n\n  for (int i = 0; i < (int)\
    \ S.size(); i++) {\n    if (S[i] == '0') ans += 1;\n    else {\n      dp2[(S[i]\
    \ - '0') % M] += 1; // only one word substring, 'S[i]' .\n    }\n    for (int\
    \ j = 0; j < M; j++) {\n\n      dp2[j] += dp1[j]; // the case when S[i] is not\
    \ choosed\n\n      dp2[(j * 10 + S[i] - '0') % M] += dp1[j]; // the case when\
    \ S[i] is choosen and added into past substrings\n\n    }\n\n    swap(dp1, dp2);\n\
    \    dp2.assign(M, 0);\n  }\n  for(int i=0; i<M; i++) {\n    if (ra.accept(i))\
    \ ans += dp1[i];\n  }\n  cout << ans.val() << endl;\n\n\n  return 0;\n}"
  dependsOn:
  - template/template.hpp
  - math/modint.hpp
  - dp/automaton/remainder.hpp
  - dp/automaton/automaton.hpp
  isVerificationFile: true
  path: test/verify/yuki-372-itsautomatic.test.cpp
  requiredBy: []
  timestamp: '2024-06-14 19:04:40+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/verify/yuki-372-itsautomatic.test.cpp
layout: document
redirect_from:
- /verify/test/verify/yuki-372-itsautomatic.test.cpp
- /verify/test/verify/yuki-372-itsautomatic.test.cpp.html
title: test/verify/yuki-372-itsautomatic.test.cpp
---
