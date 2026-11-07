---
title: Dijkstra(ダイクストラ法)
documentation_of: //graph/dijkstra.hpp
---

負辺のないグラフでの最短距離を求めるアルゴリズム。
負辺があっても負閉路がない場合は正しい答えを返すが、計算量はめちゃめちゃ悪くなるらしい。
cf: [https://theory-and-me.hatenablog.com/entry/2019/09/08/182442](https://theory-and-me.hatenablog.com/entry/2019/09/08/182442)

## dijkstra
```
vector<T> dijkstra(const Graph<T>& graph, int start)
```

`start`からの各頂点`v`までの最短距離が`dist[v]`に入っているような`vector`である`dist`を返す。
到達不可能な頂点については、最短距離は無限大となっている(実際には、型`T`で表せる最大のもの)。

### 引数・戻り値

- `graph`: 重み付きグラフの隣接リスト。辺重みは非負であること。
- `start`: 始点の頂点番号（`0 <= start < graph.size()`）。
- 戻り値: `dist[v]` が `start` から `v` までの最短距離。到達不能なら `numeric_limits<T>::max()`。


### 計算量
頂点の数を$V$、辺の数を$E$として

- $O((V+E) \log V)$

## dijkstra_path

```cpp
pair<vector<T>, vector<int>> dijkstra_path(const Graph<T>& graph, int start)
```

`dijkstra` と同じ最短距離に加えて、各頂点への最短路木を表す `prev` を返す。`prev[v]` は最短路上で `v` の直前にある頂点で、始点と到達不能頂点では `-1`。経路を復元するには、目的頂点から `prev` をたどって逆順にする。

### 引数

- `graph`: `dijkstra` と同じ条件の重み付きグラフ。
- `start`: 始点（`0 <= start < graph.size()`）。

### 計算量

- 時間: $O((V+E) \log V)$
- 空間: $O(V+E)$（入力グラフを除けば $O(V)$）
