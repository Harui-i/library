---
title : Tree Diameter(木の直径)
documentation_of: //graph/diameter.hpp
---

木の直径を求める。

## `diameter_path`

```cpp
pair<vector<int>, T> diameter_path(const Graph<T>& graph)
```

重み付き木 `graph` の直径を構成する頂点列と、その長さを返す。返り値の `first` は直径の一方の端点からもう一方までの頂点番号列、`second` はその経路長。

### 引数

- `graph`: 連結な木を隣接リストで表したもの。各辺は両方向に登録し、辺重みは非負とする。頂点数は 1 以上。

### 計算量

- 時間: $O(V)$（木の走査を 2 回）
- 空間: $O(V)$
