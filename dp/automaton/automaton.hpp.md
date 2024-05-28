---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://shino16.github.io/blog/post/algo/%E3%82%AA%E3%83%BC%E3%83%88%E3%83%9E%E3%83%88%E3%83%B3/
  bundledCode: "#line 1 \"dp/automaton/automaton.hpp\"\n// https://shino16.github.io/blog/post/algo/%E3%82%AA%E3%83%BC%E3%83%88%E3%83%9E%E3%83%88%E3%83%B3/\n\
    // Dfa\u30A4\u30F3\u30BF\u30FC\u30D5\u30A7\u30FC\u30B9\ntemplate <typename Alphabet,\
    \ typename State>\nclass Dfa {\npublic:\n  virtual State init() const = 0; //\
    \ \u521D\u671F\u72B6\u614B\u3092\u8FD4\u3059\n  virtual State next(State s, Alphabet\
    \ a, int i) const = 0; // s\u306Ba\u3092\u5165\u529B\u3068\u3057\u3066\u4E0E\u3048\
    \u305F\u6642\u306E\u6B21\u306E\u72B6\u614B\u3092\u8FD4\u3059\n  virtual bool accept(State\
    \ s) const = 0; // s\u3092\u30AA\u30FC\u30C8\u30DE\u30C8\u30F3\u304C\u53D7\u7406\
    \u3059\u308B\u304B\u3069\u3046\u304B\n  virtual bool successful(State s) const\
    \ { return false; } // \u3069\u3046\u3044\u3046\u3075\u3046\u306Bnext\u3057\u3066\
    \u3044\u3053\u3046\u304C\u3001\u7D76\u5BFE\u306Baccept\u3055\u308C\u308B\u72B6\
    \u614B\u304B\u3069\u3046\u304B\n  virtual bool unsuccessful(State s) const { return\
    \ false; } // \u3069\u3046\u3044\u3046\u3075\u3046\u306Bnext\u3057\u3066\u3044\
    \u3053\u3046\u304C\u3001\u7D76\u5BFE\u306Baccpet\u3055\u308C\u306A\u3044\u72B6\
    \u614B\u304B\u3069\u3046\u304B\n};\n"
  code: "// https://shino16.github.io/blog/post/algo/%E3%82%AA%E3%83%BC%E3%83%88%E3%83%9E%E3%83%88%E3%83%B3/\n\
    // Dfa\u30A4\u30F3\u30BF\u30FC\u30D5\u30A7\u30FC\u30B9\ntemplate <typename Alphabet,\
    \ typename State>\nclass Dfa {\npublic:\n  virtual State init() const = 0; //\
    \ \u521D\u671F\u72B6\u614B\u3092\u8FD4\u3059\n  virtual State next(State s, Alphabet\
    \ a, int i) const = 0; // s\u306Ba\u3092\u5165\u529B\u3068\u3057\u3066\u4E0E\u3048\
    \u305F\u6642\u306E\u6B21\u306E\u72B6\u614B\u3092\u8FD4\u3059\n  virtual bool accept(State\
    \ s) const = 0; // s\u3092\u30AA\u30FC\u30C8\u30DE\u30C8\u30F3\u304C\u53D7\u7406\
    \u3059\u308B\u304B\u3069\u3046\u304B\n  virtual bool successful(State s) const\
    \ { return false; } // \u3069\u3046\u3044\u3046\u3075\u3046\u306Bnext\u3057\u3066\
    \u3044\u3053\u3046\u304C\u3001\u7D76\u5BFE\u306Baccept\u3055\u308C\u308B\u72B6\
    \u614B\u304B\u3069\u3046\u304B\n  virtual bool unsuccessful(State s) const { return\
    \ false; } // \u3069\u3046\u3044\u3046\u3075\u3046\u306Bnext\u3057\u3066\u3044\
    \u3053\u3046\u304C\u3001\u7D76\u5BFE\u306Baccpet\u3055\u308C\u306A\u3044\u72B6\
    \u614B\u304B\u3069\u3046\u304B\n};"
  dependsOn: []
  isVerificationFile: false
  path: dp/automaton/automaton.hpp
  requiredBy: []
  timestamp: '2024-05-28 18:21:35+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: dp/automaton/automaton.hpp
layout: document
title: "\u6C7A\u5B9A\u6027\u6709\u9650\u30AA\u30FC\u30C8\u30DE\u30C8\u30F3(DFA, Deterministic\
  \ Finite Automaton)"
---

桁DPとかをわりと簡潔(?)に解くための仕組み？データ構造？

有限な状態数で、状態と入力が決まると次の状態も一意に決まりますよでおなじみの、決定性有限オートマトン(Deterministic Finite Automaton)を扱うことを考えている。
決定性じゃない(状態と入力に対して、次の状態が複数考えられるような)場合は、遷移先を集合としてみて(?)bitDPをすると有限な場合に帰着できるらしいですよ。

めちゃめちゃ参考にしました 1: [https://kuretchi.github.io/blog/entries/automaton-dp/]
めちゃめちゃ参考にしました 2: [https://shino16.github.io/blog/post/algo/%E3%82%AA%E3%83%BC%E3%83%88%E3%83%9E%E3%83%88%E3%83%B3/] 
めちゃめちゃ参考にしました 3: [https://ja.wikipedia.org/wiki/%E6%B1%BA%E5%AE%9A%E6%80%A7%E6%9C%89%E9%99%90%E3%82%AA%E3%83%BC%E3%83%88%E3%83%9E%E3%83%88%E3%83%B3]


定義は3に書いてある。 1は"~な数の個数"だけではなくて"~な数についてxxした総和"みたいなものも扱えることを取り上げている(実際、ジグザグ数の総和を(個数ではなく!!)求めている)が、ちょっとよくわからない部分も多い。

2は実装の参考になった。

オートマトンで考えることの嬉しさは、状態の管理が比較的らくになったり、「２つのオートマトンが受理する文字列のみを受理するオートマトン」などを簡単に[^1]扱えるところにあるんじゃないか。

Verify用の問題をどうすればいいかに悩んでいる。実装例があったほうがわかりやすいだろうし。AtCoderの問題をVerifyに使うにはDropboxのAPIキーがないといけないし、yukicoderは使ったことがないし、AOJにある問題はジグザグ数(苦行)しか知らない。

[^1]: 要出典
