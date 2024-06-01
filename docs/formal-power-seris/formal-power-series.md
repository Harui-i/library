---
title: Formal Power Series (形式的べき級数)
documentation_of: //formal-power-series/formal-power-series.hpp
---

mod 998244353のみに対応！！！！！！！！！！！！！！！！
他のmodが出たら諦めろ！！！！！！！！！！！！！！！！！

## コンストラクタ
```
FPS(vector<mint> vec)
```
はい

```
FPS(initializer_list<mint> ilist)
```
波括弧とかで初期化するやつにも対応！

```
FPS(int sz)
```
項の数で初期化(最大の次数とは1ズレる)

## inv系

### 計算量
下の3つのどれも、FPSのサイズ(最大次数+1)を $N$ として
- $O(N \log N)$

### inv_fast2
これが最速のはず。
Library Checkerでは500msほど。

### inv_fast1
逆元を(体数倍の分だけ)速めに求める
Library Checkerでは650msほど。

### inv_naive
逆元を(定数倍の分だけ)遅めに求める
Library Checkerでは920msほど。

## diff
微分。

### 計算量
mintが四則演算 $O(1)$ なら、
- $O\left(N\right)$


## integral
積分。

### 計算量
mintが四則演算 $O(1)$ なら、
- $O\left(N\right)$

## log
logを求める。定数項が`1`でないことを要求する。

### 計算量
$O(N \log N)$

## exp
expを求める。定数項が`0`であることを要求する。
~~現在はバグっている！~~ → 治りました`

### 計算量

- $O(N \log N)$