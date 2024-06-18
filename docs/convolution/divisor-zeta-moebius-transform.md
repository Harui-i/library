---
title: 約数についてのゼータ変換/メビウス変換
documentation_of: //convolution/divisor-zeta-moebius-transform.hpp
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


## 何が嬉しいのか

一言で : 添字lcmで畳み込みができる

約数についてメビウス変換んしたあと各点積とってゼータ変換取ったらlcm畳み込みになる。TODO: 書く