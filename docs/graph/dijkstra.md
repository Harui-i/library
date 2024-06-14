---
titel: Dijkstra(ダイクストラ法)
documentation_of: //graph/dijkstra.md
---

負辺のないグラフでの最短距離を求めるアルゴリズム。

## dijkstra
```
vector<T> dijkstra(const Graph<T>& graph, int start)
```

`start`からの各頂点までの最短距離を求める。

### 計算量
頂点の数を$V$、辺の数を$E$として

- $O(E \log V)$ $(E+V) \log V$とする文献(`Wikipedia`など)もあるけど、大抵$E >= V$なので結局おなじ何だと思う[^1]

[^1] : 要考察