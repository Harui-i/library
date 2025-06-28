---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/unittest/unittest-multiple-divisor-moebius-transform.test.cpp
    title: test/unittest/unittest-multiple-divisor-moebius-transform.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/verify/convolution/yosupo-gcd-convolution.test.cpp
    title: test/verify/convolution/yosupo-gcd-convolution.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"convolution/multiple-zeta-moebius-transform.hpp\"\n\n\n\n\
    #include <vector>\n#include <map>\n\nnamespace multiple {\n\n  // \u500D\u6570\
    \u306B\u3064\u3044\u3066\u306E\u30BC\u30FC\u30BF\u5909\u63DB\u3002 g_n = \\Sigma_{n|m}\
    \ f_m \u306A\u308B g \u3092\u6C42\u3081\u308B\u3002\n  // n|m\u3068\u3044\u3046\
    \u306E\u306F\u3001m%n==0\u3068\u3044\u3046\u610F\u5473\u3002\n  // O(N log N)\
    \ (\u8ABF\u548C\u7D1A\u6570)\n  // \u3046\u307E\u304F\u3084\u308B\u3068O(Nlog(log(N)))\u306B\
    \u3067\u304D\u308B\u3053\u3068\u304C\u3088\u304F\u77E5\u3089\u308C\u3066\u3044\
    \u308B\u304C\u3001\u96E3\u3057\u3044\u3057log\u306F\u5B9A\u6570\u306A\u306E\u3067\
    \u59A5\u5354\u3059\u308B\u3002\n  template <typename T, T (*op)(T, T)>\n  std::vector<T>\
    \ zeta_transform_naive(const std::vector<T>& f) {\n    int N = f.size() - 1;\n\
    \    std::vector<T> g = f;\n    for (int i = 1; i <= N; i++) {\n      for (int\
    \ j = 2 * i; j <= N; j += i) {\n        g[i] = op(g[i], f[j]);\n      }\n    }\n\
    \n    return g;\n  }\n\n  // \u500D\u6570\u306B\u3064\u3044\u3066\u306E\u30E1\u30D3\
    \u30A6\u30B9\u5909\u63DB\n  // f_n = \\Sigma_{n|m} g_m \u306A\u308B g \u3092\u6C42\
    \u3081\u308B\u3002\n  // O(N log N) (\u8ABF\u548C\u7D1A\u6570)\n  template <typename\
    \ T, T(*invop)(T, T)>\n  std::vector<T> moebius_transform_naive(const std::vector<T>&\
    \ f) {\n    int N = f.size() - 1;\n    std::vector<T> g = f;\n    for (int i =\
    \ N; i >= 1; i--) {\n      for (int j = 2 * i; j <= N; j += i) {\n        g[i]\
    \ = invop(g[i], g[j]);\n      }\n    }\n    return g;\n  }\n\n\n  template <typename\
    \ I, typename T, T(*op)(T, T)>\n  std::map<I, T> zeta_transform(const std::map<I,\
    \ T>& mp) {\n    std::map<I, T> ret = mp;\n    for (std::pair<I, T> pit : ret)\
    \ {\n      for (auto p2itr = ret.rbegin(); (*p2itr).first != pit.first; p2itr++)\
    \ {\n        if ((*p2itr).first % pit.first == 0) {\n          ret[pit.first]\
    \ = op(ret[pit.first], (*p2itr).second);\n        }\n      }\n    }\n\n    return\
    \ ret;\n  }\n\n\n  template <typename I, typename T, T (*invop)(T, T)>\n  std::map<I,\
    \ T> moebius_transform(const std::map<I, T>& mp) {\n    std::map<I, T> ret = mp;\n\
    \    for (auto p1itr = ret.rbegin(); p1itr != ret.rend(); p1itr++) {\n      for\
    \ (auto p2itr = ret.rbegin(); p2itr != p1itr; p2itr++) {\n        if ((*p2itr).first\
    \ % (*p1itr).first == 0) {\n          (*p1itr).second = invop((*p1itr).second,\
    \ (*p2itr).second);\n        }\n      }\n    }\n\n    return ret;\n  }\n\n} //\
    \ namespace multiple\n\n\n"
  code: "#ifndef HARUILIB_CONVOLUTION_MULTIPLE_ZETA_MOEBIUS_TRANSFORM_HPP\n#define\
    \ HARUILIB_CONVOLUTION_MULTIPLE_ZETA_MOEBIUS_TRANSFORM_HPP\n\n#include <vector>\n\
    #include <map>\n\nnamespace multiple {\n\n  // \u500D\u6570\u306B\u3064\u3044\u3066\
    \u306E\u30BC\u30FC\u30BF\u5909\u63DB\u3002 g_n = \\Sigma_{n|m} f_m \u306A\u308B\
    \ g \u3092\u6C42\u3081\u308B\u3002\n  // n|m\u3068\u3044\u3046\u306E\u306F\u3001\
    m%n==0\u3068\u3044\u3046\u610F\u5473\u3002\n  // O(N log N) (\u8ABF\u548C\u7D1A\
    \u6570)\n  // \u3046\u307E\u304F\u3084\u308B\u3068O(Nlog(log(N)))\u306B\u3067\u304D\
    \u308B\u3053\u3068\u304C\u3088\u304F\u77E5\u3089\u308C\u3066\u3044\u308B\u304C\
    \u3001\u96E3\u3057\u3044\u3057log\u306F\u5B9A\u6570\u306A\u306E\u3067\u59A5\u5354\
    \u3059\u308B\u3002\n  template <typename T, T (*op)(T, T)>\n  std::vector<T> zeta_transform_naive(const\
    \ std::vector<T>& f) {\n    int N = f.size() - 1;\n    std::vector<T> g = f;\n\
    \    for (int i = 1; i <= N; i++) {\n      for (int j = 2 * i; j <= N; j += i)\
    \ {\n        g[i] = op(g[i], f[j]);\n      }\n    }\n\n    return g;\n  }\n\n\
    \  // \u500D\u6570\u306B\u3064\u3044\u3066\u306E\u30E1\u30D3\u30A6\u30B9\u5909\
    \u63DB\n  // f_n = \\Sigma_{n|m} g_m \u306A\u308B g \u3092\u6C42\u3081\u308B\u3002\
    \n  // O(N log N) (\u8ABF\u548C\u7D1A\u6570)\n  template <typename T, T(*invop)(T,\
    \ T)>\n  std::vector<T> moebius_transform_naive(const std::vector<T>& f) {\n \
    \   int N = f.size() - 1;\n    std::vector<T> g = f;\n    for (int i = N; i >=\
    \ 1; i--) {\n      for (int j = 2 * i; j <= N; j += i) {\n        g[i] = invop(g[i],\
    \ g[j]);\n      }\n    }\n    return g;\n  }\n\n\n  template <typename I, typename\
    \ T, T(*op)(T, T)>\n  std::map<I, T> zeta_transform(const std::map<I, T>& mp)\
    \ {\n    std::map<I, T> ret = mp;\n    for (std::pair<I, T> pit : ret) {\n   \
    \   for (auto p2itr = ret.rbegin(); (*p2itr).first != pit.first; p2itr++) {\n\
    \        if ((*p2itr).first % pit.first == 0) {\n          ret[pit.first] = op(ret[pit.first],\
    \ (*p2itr).second);\n        }\n      }\n    }\n\n    return ret;\n  }\n\n\n \
    \ template <typename I, typename T, T (*invop)(T, T)>\n  std::map<I, T> moebius_transform(const\
    \ std::map<I, T>& mp) {\n    std::map<I, T> ret = mp;\n    for (auto p1itr = ret.rbegin();\
    \ p1itr != ret.rend(); p1itr++) {\n      for (auto p2itr = ret.rbegin(); p2itr\
    \ != p1itr; p2itr++) {\n        if ((*p2itr).first % (*p1itr).first == 0) {\n\
    \          (*p1itr).second = invop((*p1itr).second, (*p2itr).second);\n      \
    \  }\n      }\n    }\n\n    return ret;\n  }\n\n} // namespace multiple\n\n#endif\
    \ // HARUILIB_CONVOLUTION_MULTIPLE_ZETA_MOEBIUS_TRANSFORM_HPP"
  dependsOn: []
  isVerificationFile: false
  path: convolution/multiple-zeta-moebius-transform.hpp
  requiredBy: []
  timestamp: '2024-08-21 21:41:37+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/verify/convolution/yosupo-gcd-convolution.test.cpp
  - test/unittest/unittest-multiple-divisor-moebius-transform.test.cpp
documentation_of: convolution/multiple-zeta-moebius-transform.hpp
layout: document
title: "\u500D\u6570\u306B\u3064\u3044\u3066\u306E\u30BC\u30FC\u30BF\u5909\u63DB/\u30E1\
  \u30D3\u30A6\u30B9\u5909\u63DB"
---

TODO: `map`で渡すタイプのゼータ/メビウス変換について書く

## 概要

計算量は $ O(N \log \log N) $ にできるけど、よくわからないので妥協。

### 倍数についてのゼータ変換

```
vector<T> zeta_transform_naive<T, op>(const vector<T>& A)
```

可換な二項演算(大抵の場合、数の和) $\oplus$ があるとき、
長さ$N$の数列$A$が与えられたときに、 $ B_i = \bigoplus_{i \mid j} A_j $ なる数列 $B$ を求める。

`op`は、例えば`T=int`で二項演算が和なら
```
int op(int a, int b){
  return a + b;
}
```

などとして定義された関数を渡す。

### 計算量

- $O(N \log N) $

### 倍数についてのメビウス変換

可換な二項演算(大抵の場合、数の和) $\oplus$ に逆元があるとき、
長さ$N$の数列$B$が与えられたときに、$B_i = \bigoplus_{i \mid j} A_j $ なる 数列$A$ を求める。

```
vector<T> moebius_transform_naive<T, invop>(const vector<T>& B)
``` 

invopは、例えば`T=int`で、二項演算が和なら
```
int invop(int a, int b) {
  return a - b;
}
```

などとして定義された関数を渡す。

### 計算量

- $O(N \log N) $

## mapでやるやつ

```
map<I,T> zeta_transform<I,T,op>(const map<I,T>& mp)
```

```
map<I,T> moebius_transform<I,T,invop>(const map<I, T>& mp)
```

どちらもゼータ変換/メビウス変換を行うが、`vector`で変換する場合と違い、`map`のkeyだけを添え字として扱う。


メビウス関数を使うと、

$ g(n) = \bigoplus_{n \mid i} f(i) \Leftrightarrow f(n) = \bigoplus_{ n \mid i} \mu (\frac i n) g(i) $ と表せるらしい。


### 計算量

`map`のサイズを$N$として

- $O(N^2 \log N) $


### 何が嬉しいのか

数列$A$と$B$が与えられたとして、倍数についてのゼータ変換をすることで
$ A^{\prime}$と $B^{\prime}$ を得る。 $ A^{\prime}_i B^{\prime}_i = \Sigma_{i \mid j , i \mid k} A_j B_k $ であり、

$ {i \mid j , i \mid k} $ とは $ i \mid gcd(j,k) $ と言い換えられるから、$A^{\prime} B^{\prime} $ を倍数についてメビウス変換することで、gcd畳み込みができる、みたいな感じ。(書いてて自信なくなってきたな。間違ってるかも)
