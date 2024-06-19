---
title: 倍数についてのゼータ変換/メビウス変換
documentation_of: //convolution/multiple-zeta-moebius-transform.hpp
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