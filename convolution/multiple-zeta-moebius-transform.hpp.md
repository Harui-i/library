---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/verify/convolution/yosupo-gcd-convolution.test.cpp
    title: test/verify/convolution/yosupo-gcd-convolution.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"convolution/multiple-zeta-moebius-transform.hpp\"\n\n\n\n\
    #include <vector>\n\nnamespace multiple {\n\n  // \u500D\u6570\u306B\u3064\u3044\
    \u3066\u306E\u30BC\u30FC\u30BF\u5909\u63DB\u3002 g_n = \\Sigma_{n|m} f_m \u306A\
    \u308B g \u3092\u6C42\u3081\u308B\u3002\n  // n|m\u3068\u3044\u3046\u306E\u306F\
    \u3001m%n==0\u3068\u3044\u3046\u610F\u5473\u3002\n  // O(N log N) (\u8ABF\u548C\
    \u7D1A\u6570)\n  // \u3046\u307E\u304F\u3084\u308B\u3068O(Nlog(log(N)))\u306B\u3067\
    \u304D\u308B\u3053\u3068\u304C\u3088\u304F\u77E5\u3089\u308C\u3066\u3044\u308B\
    \u304C\u3001\u96E3\u3057\u3044\u3057log\u306F\u5B9A\u6570\u306A\u306E\u3067\u59A5\
    \u5354\u3059\u308B\u3002\n  template <typename T>\n  std::vector<T> zeta_transform_naive(const\
    \ std::vector<T>& f) {\n    int N = f.size() - 1;\n    std::vector<T> g = f;\n\
    \    for (int i = 1; i <= N; i++) {\n      for (int j = 2 * i; j <= N; j += i)\
    \ {\n        g[i] += f[j];\n      }\n    }\n\n    return g;\n  }\n\n  // \u500D\
    \u6570\u306B\u3064\u3044\u3066\u306E\u30E1\u30D3\u30A6\u30B9\u5909\u63DB\n  //\
    \ f_n = \\Sigma_{n|m} g_m \u306A\u308B g \u3092\u6C42\u3081\u308B\u3002\n  //\
    \ O(N log N) (\u8ABF\u548C\u7D1A\u6570)\n  template <typename T>\n  std::vector<T>\
    \ moebius_transform_naive(const std::vector<T>& f) {\n    int N = f.size() - 1;\n\
    \    std::vector<T> g = f;\n    for (int i = N; i >= 1; i--) {\n      for (int\
    \ j = 2 * i; j <= N; j += i) {\n        g[i] -= g[j];\n      }\n    }\n    return\
    \ g;\n  }\n\n\n  template <typename I, typename T>\n  std::map<I, T> zeta_transform(const\
    \ std::map<I, T>& mp) {\n    std::map<I, T> ret = mp;\n    for (std::pair<I, T>&\
    \ pit : ret) {\n      for (typename std::map<I, T>::iterator p2itr = ret.rbegin();\
    \ (*p2itr).first != pit.first; p2itr++) {\n        if ((*p2itr).first % pit.first\
    \ == 0) {\n          pit.second += (*p2itr).second;\n        }\n      }\n    }\n\
    \n    return ret;\n  }\n\n\n  template <typename I, typename T>\n  std::map<I,\
    \ T> moebius_transform(const std::map<I, T>& mp) {\n    std::map<I, T> ret = mp;\n\
    \    for (auto p1itr = ret.rbegin(); p1itr != ret.rend(); p1itr++) {\n      for\
    \ (auto p2itr = ret.rbegin(); p2itr != p1itr; p2itr++) {\n        if ((*p2itr).first\
    \ % (*p1itr).first == 0) (*p1itr).second -= (*p2itr).second;\n      }\n    }\n\
    \n    return ret;\n  }\n\n} // namespace multiple\n\n\n"
  code: "#ifndef HARUILIB_CONVOLUTION_MULTIPLE_ZETA_MOEBIUS_TRANSFORM_HPP\n#define\
    \ HARUILIB_CONVOLUTION_MULTIPLE_ZETA_MOEBIUS_TRANSFORM_HPP\n\n#include <vector>\n\
    \nnamespace multiple {\n\n  // \u500D\u6570\u306B\u3064\u3044\u3066\u306E\u30BC\
    \u30FC\u30BF\u5909\u63DB\u3002 g_n = \\Sigma_{n|m} f_m \u306A\u308B g \u3092\u6C42\
    \u3081\u308B\u3002\n  // n|m\u3068\u3044\u3046\u306E\u306F\u3001m%n==0\u3068\u3044\
    \u3046\u610F\u5473\u3002\n  // O(N log N) (\u8ABF\u548C\u7D1A\u6570)\n  // \u3046\
    \u307E\u304F\u3084\u308B\u3068O(Nlog(log(N)))\u306B\u3067\u304D\u308B\u3053\u3068\
    \u304C\u3088\u304F\u77E5\u3089\u308C\u3066\u3044\u308B\u304C\u3001\u96E3\u3057\
    \u3044\u3057log\u306F\u5B9A\u6570\u306A\u306E\u3067\u59A5\u5354\u3059\u308B\u3002\
    \n  template <typename T>\n  std::vector<T> zeta_transform_naive(const std::vector<T>&\
    \ f) {\n    int N = f.size() - 1;\n    std::vector<T> g = f;\n    for (int i =\
    \ 1; i <= N; i++) {\n      for (int j = 2 * i; j <= N; j += i) {\n        g[i]\
    \ += f[j];\n      }\n    }\n\n    return g;\n  }\n\n  // \u500D\u6570\u306B\u3064\
    \u3044\u3066\u306E\u30E1\u30D3\u30A6\u30B9\u5909\u63DB\n  // f_n = \\Sigma_{n|m}\
    \ g_m \u306A\u308B g \u3092\u6C42\u3081\u308B\u3002\n  // O(N log N) (\u8ABF\u548C\
    \u7D1A\u6570)\n  template <typename T>\n  std::vector<T> moebius_transform_naive(const\
    \ std::vector<T>& f) {\n    int N = f.size() - 1;\n    std::vector<T> g = f;\n\
    \    for (int i = N; i >= 1; i--) {\n      for (int j = 2 * i; j <= N; j += i)\
    \ {\n        g[i] -= g[j];\n      }\n    }\n    return g;\n  }\n\n\n  template\
    \ <typename I, typename T>\n  std::map<I, T> zeta_transform(const std::map<I,\
    \ T>& mp) {\n    std::map<I, T> ret = mp;\n    for (std::pair<I, T>& pit : ret)\
    \ {\n      for (typename std::map<I, T>::iterator p2itr = ret.rbegin(); (*p2itr).first\
    \ != pit.first; p2itr++) {\n        if ((*p2itr).first % pit.first == 0) {\n \
    \         pit.second += (*p2itr).second;\n        }\n      }\n    }\n\n    return\
    \ ret;\n  }\n\n\n  template <typename I, typename T>\n  std::map<I, T> moebius_transform(const\
    \ std::map<I, T>& mp) {\n    std::map<I, T> ret = mp;\n    for (auto p1itr = ret.rbegin();\
    \ p1itr != ret.rend(); p1itr++) {\n      for (auto p2itr = ret.rbegin(); p2itr\
    \ != p1itr; p2itr++) {\n        if ((*p2itr).first % (*p1itr).first == 0) (*p1itr).second\
    \ -= (*p2itr).second;\n      }\n    }\n\n    return ret;\n  }\n\n} // namespace\
    \ multiple\n\n#endif // HARUILIB_CONVOLUTION_MULTIPLE_ZETA_MOEBIUS_TRANSFORM_HPP"
  dependsOn: []
  isVerificationFile: false
  path: convolution/multiple-zeta-moebius-transform.hpp
  requiredBy: []
  timestamp: '2024-06-19 18:05:48+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/verify/convolution/yosupo-gcd-convolution.test.cpp
documentation_of: convolution/multiple-zeta-moebius-transform.hpp
layout: document
title: "\u500D\u6570\u306B\u3064\u3044\u3066\u306E\u30BC\u30FC\u30BF\u5909\u63DB/\u30E1\
  \u30D3\u30A6\u30B9\u5909\u63DB"
---

## 概要

計算量は $ O(N \log \log N) $ にできるけど、よくわからないので妥協。

### 倍数についてのゼータ変換
長さ$N$の数列$A$が与えられたときに、 $ A^{\prime}_i = \Sigma_{i \mid j} A_j $ を求める。

### 計算量

- $O(N \log N) $

### 倍数についてのメビウス変換
長さ$N$の数列$B$が与えられたときに、$B_i = \Sigma_{i \mid j} A_j $ なる $A$ を求める。


### 計算量

- $O(N \log N) $

### 何が嬉しいのか

数列$A$と$B$が与えられたとして、倍数についてのゼータ変換をすることで
$ A^{\prime}$と$B^{\prime} $を得る。 $ A^{\prime}_i B^{\prime}_i = \Sigma_{i \mid j , i \mid k} A_j B_k $ であり、

$ {i \mid j , i \mid k} $ とは $ i \mid gcd(j,k) $ と言い換えられるから、$A^{\prime} B^{\prime} $ を倍数についてメビウス変換することで、gcd畳み込みができる、みたいな感じ。(書いてて自信なくなってきたな。間違ってるかも)
