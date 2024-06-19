---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/unittest/unittest-multiple-divisor-moebius-transform.test.cpp
    title: test/unittest/unittest-multiple-divisor-moebius-transform.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/verify/convolution/yosupo-lcm-convolution.test.cpp
    title: test/verify/convolution/yosupo-lcm-convolution.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
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
    \      }\n    }\n\n    return g;\n  }\n\n  template <typename I, typename T>\n\
    \  std::map<I, T> zeta_transform(const std::map<I, T>& mp) {\n    std::map<I,\
    \ T> ret = mp;\n    for (auto p2itr = mp.rbegin(); p2itr!=mp.rend(); p2itr++)\
    \ {\n      for (auto p1itr = next(p2itr); p1itr != mp.rend(); p1itr++) {\n   \
    \     if ((*p2itr).first % (*p1itr).first == 0) ret[(*p2itr).first] += ret[(*p1itr).first];\n\
    \      }\n    }\n\n    return ret;\n  }\n\n\n  template <typename I, typename\
    \ T>\n  std::map<I, T> moebius_transform(const std::map<I, T>& mp) {\n    std::map<I,\
    \ T> ret = mp;\n\n    for (auto p1itr = ret.begin(); p1itr != ret.end(); p1itr++)\
    \ {\n      for (auto p2itr = next(p1itr); p2itr != ret.end(); p2itr++) {\n   \
    \     if ( (*p2itr).first % (*p1itr).first == 0) ret[(*p2itr).first] -= ret[(*p1itr).first];\n\
    \      }\n    }\n\n    return ret;\n  }\n} // namespace divisor\n\n\n"
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
    \  }\n\n    return g;\n  }\n\n  template <typename I, typename T>\n  std::map<I,\
    \ T> zeta_transform(const std::map<I, T>& mp) {\n    std::map<I, T> ret = mp;\n\
    \    for (auto p2itr = mp.rbegin(); p2itr!=mp.rend(); p2itr++) {\n      for (auto\
    \ p1itr = next(p2itr); p1itr != mp.rend(); p1itr++) {\n        if ((*p2itr).first\
    \ % (*p1itr).first == 0) ret[(*p2itr).first] += ret[(*p1itr).first];\n      }\n\
    \    }\n\n    return ret;\n  }\n\n\n  template <typename I, typename T>\n  std::map<I,\
    \ T> moebius_transform(const std::map<I, T>& mp) {\n    std::map<I, T> ret = mp;\n\
    \n    for (auto p1itr = ret.begin(); p1itr != ret.end(); p1itr++) {\n      for\
    \ (auto p2itr = next(p1itr); p2itr != ret.end(); p2itr++) {\n        if ( (*p2itr).first\
    \ % (*p1itr).first == 0) ret[(*p2itr).first] -= ret[(*p1itr).first];\n      }\n\
    \    }\n\n    return ret;\n  }\n} // namespace divisor\n\n#endif // HARUILIB_CONVOLUTION_DIVISOR_ZETA_MOEBIUS_TRANSFORM_HPP"
  dependsOn: []
  isVerificationFile: false
  path: convolution/divisor-zeta-moebius-transform.hpp
  requiredBy: []
  timestamp: '2024-06-19 23:53:19+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/unittest/unittest-multiple-divisor-moebius-transform.test.cpp
  - test/verify/convolution/yosupo-lcm-convolution.test.cpp
documentation_of: convolution/divisor-zeta-moebius-transform.hpp
layout: document
title: "\u7D04\u6570\u306B\u3064\u3044\u3066\u306E\u30BC\u30FC\u30BF\u5909\u63DB/\u30E1\
  \u30D3\u30A6\u30B9\u5909\u63DB"
---

## 概要

計算量は $ O(N \log \log N) $ にできるけど、よくわからないので妥協。

### 約数についてのゼータ変換

```
vector<T> zeta_transform_naive(const vector<T>& A)
```

長さ$N$の数列$A$が与えられたときに、 $ B_{i} = \Sigma_{j \mid i} A_j $ なる数列 $B$ を求める。

### 計算量

- $O(N \log N) $

### 約数についてのメビウス変換
長さ$N$の数列$B$が与えられたときに、$B_i = \Sigma_{j \mid i} A_j $ なる数列 $A$ を求める。

```
vector<T> moebius_transform_naive(const vector<T>& B)
``` 

### 計算量

- $O(N \log N) $



## mapでやるやつ

```
map<I,T> zeta_transform(const map<I,T>& mp)
```

```
map<I,T> moebius_transform(const map<I, T>& mp)
```

どちらもゼータ変換/メビウス変換を行うが、`vector`で変換する場合と違い、`map`のkeyだけを添え字として扱う。

### 計算量

`map`のサイズを$N$として

- $O(N^2 \log N) $

## 何が嬉しいのか

一言で : 添字lcmで畳み込みができる

約数についてメビウス変換んしたあと各点積とってゼータ変換取ったらlcm畳み込みになる。TODO: 書く