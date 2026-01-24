---
title: Offline 2D Sum (Rectangle Sum)
documentation_of: //structure/offline_2dsum.hpp
---

2次元平面上の点に重みを加え、長方形領域内の重みの総和を求めるクエリをオフラインで処理します。

## 使い方

1. `offline_2dsum<T, W> g;` で初期化する。`T` は座標の型、`W` は重みの型。
2. `g.add_point(x, y, w)` で点 $(x, y)$ に重み $w$ を追加する。
3. `g.add_query(l, d, r, u)` で領域 $[l, r) 	imes [d, u)$ の重みの総和を求めるクエリを追加する。
4. `g.solve()` で各クエリに対する解答を `std::vector<W>` で返す。

## 計算量
点の個数を $N$、クエリの個数を $Q$ とすると：
- $O((N + Q) \log N)$

## アルゴリズム
平面走査と Fenwick Tree を用いて実装されています。
$y$ 座標は内部で座標圧縮されます。

