---
title: Cumulative Sum 2D (二次元累積和)
documentation_of: //dp/cumulative-sum-2d.hpp
---

## コンストラクタ

```
CumulativeSum2D< T >(int H, int W)
```
サイズ$H \times W$の二次元グリッドを作成する。`H`, `W` は行数と列数。

### 計算量
- 時間: $O(HW)$
- 空間: $O(HW)$

## add
```
void add(int i, int j, T x)
```

座標 $(i,j)$に$x$を加算する。

### 引数・制約

- `i`, `j`: セルの行・列番号。$0 \leq i < H$, $0 \leq j < W$。
- `x`: セルに加算する値。`build()` より前に呼ぶ。

### 計算量
- O(1)

## build
```
void build()
```
二次元累積和を計算する。
### 計算量
- 時間: $O(HW)$
- 空間: $O(1)$（作業領域）

## query
```
T query(int si, int sj, int gi, int gj)
```

半開区間 $[si, gi) \times [sj, gj)$ の要素和を求める（0-indexed）。

### 引数・制約

- `si`, `sj`: 区間の開始位置。$0 \leq si < H$, $0 \leq sj < W$。
- `gi`, `gj`: 区間の終端（含まない）。$si \leq gi \leq H$, $sj \leq gj \leq W$。
- `build()` の後に呼ぶ。

### 計算量
- 時間: $O(1)$
- 空間: $O(1)$
