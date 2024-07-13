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
    \ g \u3092\u6C42\u3081\u308B\u3002\n  template <typename T, T(*op)(T, T) >\n \
    \ std::vector<T> zeta_transform_naive(const std::vector<T>& f) {\n    int N =\
    \ f.size() - 1;\n    std::vector<T> g = f;\n\n    for (int i = 1; i <= N; i++)\
    \ {\n      for (int j = 2 * i; j <= N; j += i) {\n        g[j] = op(g[j], f[i]);\n\
    \      }\n    }\n\n    return g;\n  }\n\n  // \u7D04\u6570\u306B\u3064\u3044\u3066\
    \u306E\u30E1\u30D3\u30A6\u30B9\u5909\u63DB\u3002 f_n = \\Sigma_{m|n} g_m \u306A\
    \u308B g \u3092\u6C42\u3081\u308B\u3002\n  template <typename T, T(*invop)(T,\
    \ T)>\n  std::vector<T> moebius_transform_naive(const std::vector<T>& f) {\n \
    \   int N = f.size() - 1;\n    std::vector<T> g = f;\n\n    for (int i = 1; i\
    \ <= N; i++) {\n      for (int j = i * 2; j <= N; j += i) {\n        g[j] = invop(g[j],\
    \ g[i]);\n      }\n    }\n\n    return g;\n  }\n\n  template <typename I, typename\
    \ T, T(*op)(T, T)>\n  std::map<I, T> zeta_transform(const std::map<I, T>& mp)\
    \ {\n    std::map<I, T> ret = mp;\n    for (auto p2itr = mp.rbegin(); p2itr !=\
    \ mp.rend(); p2itr++) {\n      for (auto p1itr = next(p2itr); p1itr != mp.rend();\
    \ p1itr++) {\n        if ((*p2itr).first % (*p1itr).first == 0) {\n          ret[(*p2itr).first]\
    \ = op(ret[(*p2itr).first], ret[(*p1itr).first]);\n        }\n      }\n    }\n\
    \n    return ret;\n  }\n\n\n  template <typename I, typename T, T(*op)(T, T)>\n\
    \  std::map<I, T> moebius_transform(const std::map<I, T>& mp) {\n    std::map<I,\
    \ T> ret = mp;\n\n    for (auto p1itr = ret.begin(); p1itr != ret.end(); p1itr++)\
    \ {\n      for (auto p2itr = next(p1itr); p2itr != ret.end(); p2itr++) {\n   \
    \     if ((*p2itr).first % (*p1itr).first == 0) {\n          ret[(*p2itr).first]\
    \ = invop(ret[(*p2itr).first], ret[(*p1itr).first]);\n        }\n      }\n   \
    \ }\n\n    return ret;\n  }\n} // namespace divisor\n\n\n"
  code: "#ifndef HARUILIB_CONVOLUTION_DIVISOR_ZETA_MOEBIUS_TRANSFORM_HPP\n#define\
    \ HARUILIB_CONVOLUTION_DIVISOR_ZETA_MOEBIUS_TRANSFORM_HPP\n\n#include <vector>\n\
    \nnamespace divisor {\n  // \u7D04\u6570\u306B\u3064\u3044\u3066\u306E\u30BC\u30FC\
    \u30BF\u5909\u63DB\u3002 g_n = \\Sigma_{m|n} f_m \u306A\u308B g \u3092\u6C42\u3081\
    \u308B\u3002\n  template <typename T, T(*op)(T, T) >\n  std::vector<T> zeta_transform_naive(const\
    \ std::vector<T>& f) {\n    int N = f.size() - 1;\n    std::vector<T> g = f;\n\
    \n    for (int i = 1; i <= N; i++) {\n      for (int j = 2 * i; j <= N; j += i)\
    \ {\n        g[j] = op(g[j], f[i]);\n      }\n    }\n\n    return g;\n  }\n\n\
    \  // \u7D04\u6570\u306B\u3064\u3044\u3066\u306E\u30E1\u30D3\u30A6\u30B9\u5909\
    \u63DB\u3002 f_n = \\Sigma_{m|n} g_m \u306A\u308B g \u3092\u6C42\u3081\u308B\u3002\
    \n  template <typename T, T(*invop)(T, T)>\n  std::vector<T> moebius_transform_naive(const\
    \ std::vector<T>& f) {\n    int N = f.size() - 1;\n    std::vector<T> g = f;\n\
    \n    for (int i = 1; i <= N; i++) {\n      for (int j = i * 2; j <= N; j += i)\
    \ {\n        g[j] = invop(g[j], g[i]);\n      }\n    }\n\n    return g;\n  }\n\
    \n  template <typename I, typename T, T(*op)(T, T)>\n  std::map<I, T> zeta_transform(const\
    \ std::map<I, T>& mp) {\n    std::map<I, T> ret = mp;\n    for (auto p2itr = mp.rbegin();\
    \ p2itr != mp.rend(); p2itr++) {\n      for (auto p1itr = next(p2itr); p1itr !=\
    \ mp.rend(); p1itr++) {\n        if ((*p2itr).first % (*p1itr).first == 0) {\n\
    \          ret[(*p2itr).first] = op(ret[(*p2itr).first], ret[(*p1itr).first]);\n\
    \        }\n      }\n    }\n\n    return ret;\n  }\n\n\n  template <typename I,\
    \ typename T, T(*op)(T, T)>\n  std::map<I, T> moebius_transform(const std::map<I,\
    \ T>& mp) {\n    std::map<I, T> ret = mp;\n\n    for (auto p1itr = ret.begin();\
    \ p1itr != ret.end(); p1itr++) {\n      for (auto p2itr = next(p1itr); p2itr !=\
    \ ret.end(); p2itr++) {\n        if ((*p2itr).first % (*p1itr).first == 0) {\n\
    \          ret[(*p2itr).first] = invop(ret[(*p2itr).first], ret[(*p1itr).first]);\n\
    \        }\n      }\n    }\n\n    return ret;\n  }\n} // namespace divisor\n\n\
    #endif // HARUILIB_CONVOLUTION_DIVISOR_ZETA_MOEBIUS_TRANSFORM_HPP"
  dependsOn: []
  isVerificationFile: false
  path: convolution/divisor-zeta-moebius-transform.hpp
  requiredBy: []
  timestamp: '2024-06-20 21:09:39+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/verify/convolution/yosupo-lcm-convolution.test.cpp
  - test/unittest/unittest-multiple-divisor-moebius-transform.test.cpp
documentation_of: convolution/divisor-zeta-moebius-transform.hpp
layout: document
title: "\u7D04\u6570\u306B\u3064\u3044\u3066\u306E\u30BC\u30FC\u30BF\u5909\u63DB/\u30E1\
  \u30D3\u30A6\u30B9\u5909\u63DB"
---

## 概要

計算量は $ O(N \log \log N) $ にできるけど、よくわからないので妥協。

### 約数についてのゼータ変換

```
vector<T> zeta_transform_naive<T, op>(const vector<T>& A)
```

可換な二項演算(大抵の場合、数の和) $\oplus$ があるとき、
長さ$N$の数列$A$が与えられたときに、 $ B_{i} = \bigoplus_{j \mid i} A_j$ なる数列 $B$ を求める。

`op`は、例えば`T=int`で二項演算が和なら
```
int op(int a, int b){
  return a + b;
}
```

などとして定義された関数を渡す。
### 計算量

- $O(N \log N) $

### 約数についてのメビウス変換

可換な二項演算(大抵の場合、数の和) $\oplus$ に逆元があるとき、
長さ$N$の数列$B$が与えられたときに、$B_i = \bigoplus_{j \mid i} A_j $ なる数列 $A$ を求める。

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

`vector`で変換するときは $ 1 \leq i \leq N $ なすべての $i$ について求めたが、mapを使うと$N$の約数に付いてだけ求める！とかもできるようになる。

ちなみに、メビウス関数を使うと、

$ g(n) = \bigoplus_{d \mid n} f(d)  \Leftrightarrow f(n) = \bigoplus_{d \mid n} \mu (\fran n d) g(d) $ という関係があるので、それを使って求めることもできる。その場合、蟻本P267にあるように、

```C++
map<ll, ll> moebius(ll n) {
  std::map<ll, ll> res;
  std::vector<ll> primes;

  for (ll i=2; i*i <=n; i++) {
    if (n%i == 0) {
      primes.push_back(i);
      while (n%i == 0) n /= i;
    }
  }
  if (n != 1) primes.push_back(n);

  int m = primes.size();

  for (int s = 0; s < (1 << M); s++ ) {
    ll mu = 1, d = 1;
    for (int j=0; j<m; j++) {
      if ( i >> j & 1) {
        mu *= -1;
        d *= primes[j];
      }
    }

    res[d] = mu;
  }

  return res;
}

```

とするといいんじゃないか。書いていて思ったけど、結局メビウス関数を陽に扱わないやつのほうがシンプルでわかりやすいし、約数の個数の2乗の計算量がかかるといっても、どちらの方法もそもそも約数の計算に $\sqrt N $ かかるわけで、蟻本のようにやってもmapでやっても速度に大差は無い気がする。


### 計算量

`map`のサイズを $N$ として

- $O(N^2 \log N) $


## 何が嬉しいのか

一言で : 添字lcmで畳み込みができる

約数についてメビウス変換んしたあと各点積とってゼータ変換取ったらlcm畳み込みになる。TODO: 書く