---
title: 倍数/約数関係についてのゼータ変換/メビウス変換
documentation_of: //convolution/divisor-multiple-zeta-moebius-transform.hpp
---

## 概要

計算量は $ O(N \log \log N) $ にできるけど、よくわからないので妥協。

### 倍数についてのゼータ変換
長さ$N$の数列$A$が与えられたときに、 $A^{\star}_i = \Sigma_{i | j} A_j $を求める。

### 計算量

- $O(N \log N) $

### 倍数についてのメビウス変換
長さ$N$の数列$B$が与えられたときに、$B_i = \Sigma_{i | j} A_j $なる$A$を求める。


### 計算量

- $O(N \log N) $

### 何が嬉しいのか

数列$A$と$B$が与えられたとして、倍数についてのゼータ変換をすることで
$ A^{\star}$と$B^{\star} $を得る。 $ A^{\star}_i B^{\star}_i = \Sigma_{i | j , i | k} A_j B_k $ であり、

$ {i | j , i | k}$ とは $ i | gcd(j,k) $ と言い換えられるから、$A^{\star} B^{\star} $ を倍数についてメビウス変換することで、gcd畳み込みができる、みたいな感じ。(書いてて自信なくなってきたな。間違ってるかも)
