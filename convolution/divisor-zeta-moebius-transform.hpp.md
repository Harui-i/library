---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"convolution/divisor-zeta-moebius-transform.hpp\"\n\n\n\n\
    #include <vector>\n\nnamespace divisor {\n  // \u7D04\u6570\u306B\u3064\u3044\u3066\
    \u306E\u30BC\u30FC\u30BF\u5909\u63DB\u3002 g_n = \\Sigma_{m|n} f_m \u306A\u308B\
    \ g \u3092\u6C42\u3081\u308B\u3002\n  template <typename T>\n  std::vector<T>\
    \ zeta_transform_naive(const std::vector<T>& f) {\n    int N = f.size() - 1;\n\
    \    std::vector<T> g = f;\n\n    for(int i=1; i<=N; i++) {\n      for(int j=2*i;\
    \ j<=N; j+=i) {\n        g[j] += f[i];\n      }\n    }\n\n    return g;\n  }\n\
    \n  // \u7D04\u6570\u306B\u3064\u3044\u3066\u306E\u30E1\u30D3\u30A6\u30B9\u5909\
    \u63DB\u3002 f_n = \\Sigma_{m|n} g_m \u306A\u308B g \u3092\u6C42\u3081\u308B\u3002\
    \n  template <typename T>\n  std::vector<T> moebius_transform_naive(const std::vector<T>&\
    \ f) {\n    int N = f.size() - 1;\n    std::vector<T> g = f;\n\n    for (int i=1;\
    \ i<=N; i++) {\n      for (int j=i*2; j<= N; j+=i) {\n        g[j] -= g[i];\n\
    \      }\n    }\n\n    return g;\n  }\n}\n\n\n\n"
  code: "#ifndef HARUILIB_CONVOLUTION_DIVISOR_ZETA_MOEBIUS_TRANSFORM_HPP\n#define\
    \ HARUILIB_CONVOLUTION_DIVISOR_ZETA_MOEBIUS_TRANSFORM_HPP\n\n#include <vector>\n\
    \nnamespace divisor {\n  // \u7D04\u6570\u306B\u3064\u3044\u3066\u306E\u30BC\u30FC\
    \u30BF\u5909\u63DB\u3002 g_n = \\Sigma_{m|n} f_m \u306A\u308B g \u3092\u6C42\u3081\
    \u308B\u3002\n  template <typename T>\n  std::vector<T> zeta_transform_naive(const\
    \ std::vector<T>& f) {\n    int N = f.size() - 1;\n    std::vector<T> g = f;\n\
    \n    for(int i=1; i<=N; i++) {\n      for(int j=2*i; j<=N; j+=i) {\n        g[j]\
    \ += f[i];\n      }\n    }\n\n    return g;\n  }\n\n  // \u7D04\u6570\u306B\u3064\
    \u3044\u3066\u306E\u30E1\u30D3\u30A6\u30B9\u5909\u63DB\u3002 f_n = \\Sigma_{m|n}\
    \ g_m \u306A\u308B g \u3092\u6C42\u3081\u308B\u3002\n  template <typename T>\n\
    \  std::vector<T> moebius_transform_naive(const std::vector<T>& f) {\n    int\
    \ N = f.size() - 1;\n    std::vector<T> g = f;\n\n    for (int i=1; i<=N; i++)\
    \ {\n      for (int j=i*2; j<= N; j+=i) {\n        g[j] -= g[i];\n      }\n  \
    \  }\n\n    return g;\n  }\n}\n\n\n#endif // HARUILIB_CONVOLUTION_DIVISOR_ZETA_MOEBIUS_TRANSFORM_HPP"
  dependsOn: []
  isVerificationFile: false
  path: convolution/divisor-zeta-moebius-transform.hpp
  requiredBy: []
  timestamp: '2024-06-18 23:58:45+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: convolution/divisor-zeta-moebius-transform.hpp
layout: document
title: "\u7D04\u6570\u306B\u3064\u3044\u3066\u306E\u30BC\u30FC\u30BF\u5909\u63DB/\u30E1\
  \u30D3\u30A6\u30B9\u5909\u63DB"
---

## 概要

計算量は $ O(N \log \log N) $ にできるけど、よくわからないので妥協。

### 約数についてのゼータ変換
長さ$N$の数列$A$が与えられたときに、 $ A^{\prime}_{i} = \Sigma_{j \mid i} A_j $を求める。

### 計算量

- $O(N \log N) $

### 約数についてのメビウス変換
長さ$N$の数列$B$が与えられたときに、$B_i = \Sigma_{j \mid i} A_j $なる$A$を求める。


### 計算量

- $O(N \log N) $
