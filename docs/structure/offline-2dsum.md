---
title: Offline 2D Sum (Rectangle Sum)
documentation_of: //structure/offline_2dsum.hpp
---

2次元平面上の点に重みを加え、長方形領域内の重みの総和を求めるクエリをオフラインで処理します。

## コンストラクタ

```
offline_2dsum<T, W>()
```
T: 座標の型, W: 重みの型

座標・重みの比較、加算と減算（および重みの `0` 初期化）ができる型を指定する。

## add_point

```
void add_point(T x, T y, W w)
```
点 $(x, y)$ に重み $w$ を追加する。

- 引数: `x`, `y` は点の座標、`w` は加算する重み。

### 計算量
- $O(1)$

## add_query

```
void add_query(T l, T r, T d, T u)
```
領域 $[l, r) \times [d, u)$ の重みの総和を求めるクエリを追加する。
つまり、$l \le x < r, d \le y < u$ を満たす点の重みの総和を求める。

- 引数: 長方形の左・右・下・上の境界。`l <= r`, `d <= u` を満たすこと。

### 計算量
- $O(1)$

## solve

```
std::vector<W> solve()
```
追加されたすべてのクエリに対する解答を計算し、追加された順に返す。

### 計算量
点の個数を $N$、クエリの個数を $Q$ とすると
- $O(N \log N + Q \log Q + (N + Q) \log N)$
- 空間: $O(N+Q)$
