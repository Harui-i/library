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
    path: test/verify/yuki-372-itsautomatic.test.cpp
    title: test/verify/yuki-372-itsautomatic.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"dp/automaton/automaton.hpp\"\n// https://shino16.github.io/blog/post/algo/%E3%82%AA%E3%83%BC%E3%83%88%E3%83%9E%E3%83%88%E3%83%B3/\n\
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
    \ next(State s, char c, int i) const override {\n    State ret = ((long long)s*10\
    \ + (long long)(c - '0') )%M; \n\n    return ret;\n  }\n\n  bool accept(State\
    \ s) const override {\n    return s == 0;\n  }\n\n  bool successful ([[maybe_unused]]\
    \ State  s) const override {\n    return false;\n  }\n\n  bool unsuccessful([[maybe_unused]]\
    \ State s) const override {\n    return false;\n  }\n  \n};\n"
  code: "#include \"automaton.hpp\"\n\n// next\u306F\u6570\u5B57\u306E\u53F3\u7AEF\
    \u306B\u66F8\u304D\u52A0\u3048\u308B\u30A4\u30E1\u30FC\u30B8\u3002\u3064\u307E\
    \u308A\u3001\u3044\u308D\u3044\u308D\u306A\u6841\u6570\u3092\u8003\u3048\u3089\
    \u308C\u308B\u3002\n// \u3057\u304B\u3057\u3001\u56FA\u5B9A\u3057\u305F\u6841\u6570\
    \u306B\u5BFE\u3057\u3066\u5DE6\u304B\u3089\u57CB\u3081\u3066\u3044\u304F\u30D1\
    \u30BF\u30FC\u30F3\u3067\u4F7F\u3044\u305F\u3044\u5834\u5408\u3082\u3042\u308A\
    \u305D\u3046\u3002\n// \u6570\u5B57\u306EM\u306E\u500D\u6570\u306E\u307F\u53D7\
    \u7406\u3059\u308B\u30AA\u30FC\u30C8\u30DE\u30C8\u30F3\ntemplate <typename Alphabet>\
    \ \nclass RemainderAutomaton : public Dfa<Alphabet, int> {\n  const int M;\n \
    \ const int N_siz;\n\npublic:\n  using State = int;\n  RemainderAutomaton(int\
    \ _N_siz, int _M) : M(_M), N_siz(_N_siz) {}\n\n  State init() const override {\n\
    \    return State(0);\n  }\n\n  State next(State s, char c, int i) const override\
    \ {\n    State ret = ((long long)s*10 + (long long)(c - '0') )%M; \n\n    return\
    \ ret;\n  }\n\n  bool accept(State s) const override {\n    return s == 0;\n \
    \ }\n\n  bool successful ([[maybe_unused]] State  s) const override {\n    return\
    \ false;\n  }\n\n  bool unsuccessful([[maybe_unused]] State s) const override\
    \ {\n    return false;\n  }\n  \n};"
  dependsOn:
  - dp/automaton/automaton.hpp
  isVerificationFile: false
  path: dp/automaton/remainder.hpp
  requiredBy: []
  timestamp: '2024-05-29 17:51:14+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/verify/yuki-372-itsautomatic.test.cpp
documentation_of: dp/automaton/remainder.hpp
layout: document
title: "\u3042\u307E\u308A\u3092\u7BA1\u7406\u3059\u308B\u30AA\u30FC\u30C8\u30DE\u30C8\
  \u30F3(remainder.hpp)"
---

これいるか？　nextは、数字の右側に桁を加えるような操作を考えている。 '998'に'2'を与えてnextすると'9982'に対応する状態が返ってくるイメージ。
わざわざライブラリにするほどのものでもなくね？？？
ライブラリにするほど複雑でもないから、1から書けばいいし、ライブラリにするなら「よく出るオートマトンは事前に書いておく」かつ「オートマトンのAND合成もライブラリにある」という状態が望ましいけど、
AND合成のオートマトンは書くの難しいし、どうせなら2つだけじゃなくて任意個の合成もできたほうが便利だけどそれもやっぱり難しいしで、オートマトンをライブラリにして有効に使うのは難しそう。