---
title: Formal Power Series (形式的べき級数)
documentation_of: //formal-power-series/formal-power-series.hpp
---

modによらない(さすがに合成数とかだと厳しいが)共通した処理を実装している。

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
