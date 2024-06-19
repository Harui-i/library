---
title: 約数についてのゼータ変換/メビウス変換
documentation_of: //convolution/divisor-zeta-moebius-transform.hpp
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