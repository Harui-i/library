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

## inv_fast1
逆元を(体数倍の分だけ)速めに求める

## inv_naive
逆元を(定数倍の分だけ)遅めに求める