---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/verify/yosupo-gcd-convolution.test.cpp
    title: test/verify/yosupo-gcd-convolution.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"convolution/divisor-multiple-zeta-moebius-transform.hpp\"\
    \n\n\n\n#include <vector>\n\nnamespace multiple {\n\n  // \u500D\u6570\u306B\u3064\
    \u3044\u3066\u306E\u30BC\u30FC\u30BF\u5909\u63DB\u3002 g_n = \\Sigma_{n|m} f_m\
    \ \u306A\u308B g \u3092\u6C42\u3081\u308B\u3002\n  // n|m\u3068\u3044\u3046\u306E\
    \u306F\u3001m%n==0\u3068\u3044\u3046\u610F\u5473\u3002\n  // O(N log N) (\u8ABF\
    \u548C\u7D1A\u6570)\n  // \u3046\u307E\u304F\u3084\u308B\u3068O(Nlog(log(N)))\u306B\
    \u3067\u304D\u308B\u3053\u3068\u304C\u3088\u304F\u77E5\u3089\u308C\u3066\u3044\
    \u308B\u304C\u3001\u96E3\u3057\u3044\u3057log\u306F\u5B9A\u6570\u306A\u306E\u3067\
    \u59A5\u5354\u3059\u308B\u3002\n  template <typename T>\n  std::vector<T> zeta_transform_naive(const\
    \ std::vector<T>& f) {\n    int N = f.size()-1;\n    std::vector<T> g = f;\n \
    \   for (int i=1; i<=N; i++) {\n      for (int j=2*i; j<=N; j+=i) {\n        g[i]\
    \ += f[j];\n      }\n    }\n\n    return g;\n  }\n\n  // \u500D\u6570\u306B\u3064\
    \u3044\u3066\u306E\u30E1\u30D3\u30A6\u30B9\u5909\u63DB\n  // f_n = \\Sigma_{n|m}\
    \ g_m \u306A\u308B g \u3092\u6C42\u3081\u308B\u3002\n  // O(N log N) (\u8ABF\u548C\
    \u7D1A\u6570)\n  template <typename T>\n  std::vector<T> moebius_transform_naive(const\
    \ std::vector<T>& f) {\n    int N = f.size()-1;\n    std::vector<T> g = f;\n \
    \   for (int i=N; i>=1; i--) {\n      for (int j=2*i; j<=N; j+=i) {\n        g[i]\
    \ -= g[j];\n      }\n    }\n    return g;\n  }\n\n}\n\n\n\n"
  code: "#ifndef HARUILIB_CONVOLUTION_DIVISOR_MULTIPLE_ZETA_MOEBIUS_TRANSFORM_HPP\n\
    #define HARUILIB_CONVOLUTION_DIVISOR_MULTIPLE_ZETA_MOEBIUS_TRANSFORM_HPP\n\n#include\
    \ <vector>\n\nnamespace multiple {\n\n  // \u500D\u6570\u306B\u3064\u3044\u3066\
    \u306E\u30BC\u30FC\u30BF\u5909\u63DB\u3002 g_n = \\Sigma_{n|m} f_m \u306A\u308B\
    \ g \u3092\u6C42\u3081\u308B\u3002\n  // n|m\u3068\u3044\u3046\u306E\u306F\u3001\
    m%n==0\u3068\u3044\u3046\u610F\u5473\u3002\n  // O(N log N) (\u8ABF\u548C\u7D1A\
    \u6570)\n  // \u3046\u307E\u304F\u3084\u308B\u3068O(Nlog(log(N)))\u306B\u3067\u304D\
    \u308B\u3053\u3068\u304C\u3088\u304F\u77E5\u3089\u308C\u3066\u3044\u308B\u304C\
    \u3001\u96E3\u3057\u3044\u3057log\u306F\u5B9A\u6570\u306A\u306E\u3067\u59A5\u5354\
    \u3059\u308B\u3002\n  template <typename T>\n  std::vector<T> zeta_transform_naive(const\
    \ std::vector<T>& f) {\n    int N = f.size()-1;\n    std::vector<T> g = f;\n \
    \   for (int i=1; i<=N; i++) {\n      for (int j=2*i; j<=N; j+=i) {\n        g[i]\
    \ += f[j];\n      }\n    }\n\n    return g;\n  }\n\n  // \u500D\u6570\u306B\u3064\
    \u3044\u3066\u306E\u30E1\u30D3\u30A6\u30B9\u5909\u63DB\n  // f_n = \\Sigma_{n|m}\
    \ g_m \u306A\u308B g \u3092\u6C42\u3081\u308B\u3002\n  // O(N log N) (\u8ABF\u548C\
    \u7D1A\u6570)\n  template <typename T>\n  std::vector<T> moebius_transform_naive(const\
    \ std::vector<T>& f) {\n    int N = f.size()-1;\n    std::vector<T> g = f;\n \
    \   for (int i=N; i>=1; i--) {\n      for (int j=2*i; j<=N; j+=i) {\n        g[i]\
    \ -= g[j];\n      }\n    }\n    return g;\n  }\n\n}\n\n\n#endif // HARUILIB_CONVOLUTION_DIVISOR_MULTIPLE_ZETA_MOEBIUS_TRANSFORM_HPP"
  dependsOn: []
  isVerificationFile: false
  path: convolution/divisor-multiple-zeta-moebius-transform.hpp
  requiredBy: []
  timestamp: '2024-06-18 18:48:26+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/verify/yosupo-gcd-convolution.test.cpp
documentation_of: convolution/divisor-multiple-zeta-moebius-transform.hpp
layout: document
title: "\u500D\u6570/\u7D04\u6570\u95A2\u4FC2\u306B\u3064\u3044\u3066\u306E\u30BC\u30FC\
  \u30BF\u5909\u63DB/\u30E1\u30D3\u30A6\u30B9\u5909\u63DB"
---

## 概要

### 倍数についてのゼータ変換
長さ$N$の数列$A$が与えられたときに、 $A^'_i = \Sum_{i | j} A_j $を求める。

### 倍数についてのメビウス変換
長さ$N$の数列$B$が与えられたときに、$B_i = \Sum_{i | j} A_j $なる$A$を求める。



### 何が嬉しいのか

数列$A$と$B$が与えられたとして、倍数についてのゼータ変換をすることで
$A^'$と$B^'$を得る。 $A^'_i B^'_i = \Sum_{i | j , i | k} A_j B_k$ であり、

${i | j , i | k}$とは$i | gcd(j,k)$と言い換えられるから、$A^' B^'$を倍数についてメビウス変換することで、gcd畳み込みができる、みたいな感じ。(書いてて自信なくなってきたな。間違ってるかも)
