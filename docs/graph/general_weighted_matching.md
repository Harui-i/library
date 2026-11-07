---
title: General Weighted Matching
documentation_of: //graph/general_weighted_matching.hpp
---

一般グラフの最大重みマッチング（Blossom / 花アルゴリズム）を解く。
重み付き辺を受け取り、重み和が最大となるマッチングを返す。
辺重みは非負整数を想定する。

## 使い方

```cpp
haruilib::GeneralWeightedMatching wm(N);
wm.add_edge(u, v, w);
auto [sum, mate] = wm.solve();
```

- `sum`: 最大重み
- `mate[i]`: 頂点 `i` とマッチした頂点番号（未マッチは `-1`）

同じ 2 頂点間に複数回 `add_edge` した場合は、最大の重みだけを使う。

## API

- `GeneralWeightedMatching(int n)`: 頂点数 `n`（頂点番号は `0` から `n-1`）。
- `add_edge(int u, int v, long long cost)`: 頂点 `u`, `v` 間に重み `cost` の無向辺を追加する。自己ループは無視され、重みは非負整数を想定する。重複辺は最大重みが採用される。
- `solve()`: `{最大重み, mate}` を返す。`mate[i]` は相手頂点、未マッチなら `-1`。最大重みが同じ解のうち、どれが返るかは固定されない。

## 計算量

- $O(N^3)$
- 空間: $O(N^2)$
