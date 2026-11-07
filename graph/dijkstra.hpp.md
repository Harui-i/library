---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/template.hpp
    title: graph/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/verify/yosupo-shortest-path.test.cpp
    title: test/verify/yosupo-shortest-path.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://harui-i.github.io/library/graph/dijkstra.hpp.html
  bundledCode: "#line 1 \"graph/dijkstra.hpp\"\n\n\n// https://harui-i.github.io/library/graph/dijkstra.hpp.html\n\
    \n#include <queue>\n#include <vector>\n#include <limits>\n#include <utility>\n\
    \n#line 1 \"graph/template.hpp\"\n\n\n// https://harui-i.github.io/library/graph/template.hpp.html\n\
    \n#line 6 \"graph/template.hpp\"\n\ntemplate <typename T>\nstruct Edge {\n  int\
    \ from; int to;\n  T cost;\n\n  // default constructor\n  Edge () : from(-1),\
    \ to(-1), cost(T(0)) {}\n\n  Edge(int _from, int _to, T _cost) : from(_from),\
    \ to(_to), cost(_cost) {}\n\n  // unweighted\n  Edge(int _from, int _to) : from(_from),\
    \ to(_to), cost(T(1)) {}\n\n  bool operator==(const Edge& rhs) const {\n    return\
    \ from == rhs.from && to == rhs.to && cost == rhs.cost;\n  }\n\n  bool operator<(const\
    \ Edge& rhs) const {\n    return cost < rhs.cost;\n  }\n  \n  bool operator>(const\
    \ Edge& rhs) const {\n    return cost > rhs.cost;\n  }\n\n};\n\n\ntemplate <typename\
    \ T>\nstruct Graph : std::vector<std::vector<Edge<T>>> {\n\n  using std::vector<std::vector<Edge<T>>>::vector;\
    \ // inherit constructors\n\n  void add_edge(int i, Edge<T> e) {\n    (*this)[i].push_back(e);\n\
    \  }\n\n  void add_edge(Edge<T> e) {\n    (*this)[e.from].push_back(e);\n  }\n\
    \n  // weighted\n  void add_edge(int _from, int _to, T _cost) {\n    (*this)[_from].push_back(Edge(_from,\
    \ _to, _cost));\n  }\n\n  // unweighted\n  void add_edge(int _from, int _to) {\n\
    \    (*this)[_from].push_back(Edge(_from, _to, T(1)));\n  }\n\n};\n\n\n#line 11\
    \ \"graph/dijkstra.hpp\"\n\ntemplate <typename T>\nstd::vector<T> dijkstra(const\
    \ Graph<T>& graph, int start) {\n  int N = (int)graph.size();\n  constexpr T INF\
    \ = numeric_limits<T>::max();\n  std::vector<T>dist(N, INF);\n  using P = std::pair<T,\
    \ int>;\n\n  std::priority_queue<P, std::vector<P>, std::greater<P>>que;\n\n \
    \ que.push(make_pair(T(0), start));\n  dist[start] = T(0);\n\n  while (!que.empty())\
    \ {\n    P front = que.top(); que.pop();\n\n    if (dist[front.second] < front.first)\
    \ continue;\n\n    for (Edge ed : graph[front.second]) {\n\n      if (dist[ed.to]\
    \ > front.first + ed.cost) {\n        dist[ed.to] = front.first + ed.cost;\n \
    \       que.emplace(dist[ed.to], ed.to);\n      }\n    }\n  }\n\n  return dist;\n\
    }\n\ntemplate <typename T>\nstd::pair<std::vector<T>, std::vector<int>> dijkstra_path(const\
    \ Graph<T>& graph, int start) {\n  int N = (int)graph.size();\n  constexpr T INF\
    \ = numeric_limits<T>::max();\n\n  using P = std::pair<T, int>;\n  std::vector<T>dist(N,\
    \ INF);\n  std::vector<int>prev(N, -1);\n\n  std::priority_queue<P, std::vector<P>,\
    \ std::greater<P>>que;\n  que.push(make_pair(T(0), start));\n  dist[start] = T(0);\n\
    \n  while (!que.empty()) {\n    P front = que.top(); que.pop();\n\n    if (dist[front.second]\
    \ < front.first) continue;\n\n    for (Edge ed : graph[front.second]) {\n    \
    \  if (dist[ed.to] > front.first + ed.cost) {\n        dist[ed.to] = front.first\
    \ + ed.cost;\n        prev[ed.to] = front.second;\n        que.emplace(dist[ed.to],\
    \ ed.to);\n      }\n    }\n  }\n\n  return make_pair(dist, prev);\n}\n\n\n"
  code: "#ifndef HARUILIB_GRAPH_DIJKSTRA_HPP\n#define HARUILIB_GRAPH_DIJKSTRA_HPP\n\
    // https://harui-i.github.io/library/graph/dijkstra.hpp.html\n\n#include <queue>\n\
    #include <vector>\n#include <limits>\n#include <utility>\n\n#include \"graph/template.hpp\"\
    \n\ntemplate <typename T>\nstd::vector<T> dijkstra(const Graph<T>& graph, int\
    \ start) {\n  int N = (int)graph.size();\n  constexpr T INF = numeric_limits<T>::max();\n\
    \  std::vector<T>dist(N, INF);\n  using P = std::pair<T, int>;\n\n  std::priority_queue<P,\
    \ std::vector<P>, std::greater<P>>que;\n\n  que.push(make_pair(T(0), start));\n\
    \  dist[start] = T(0);\n\n  while (!que.empty()) {\n    P front = que.top(); que.pop();\n\
    \n    if (dist[front.second] < front.first) continue;\n\n    for (Edge ed : graph[front.second])\
    \ {\n\n      if (dist[ed.to] > front.first + ed.cost) {\n        dist[ed.to] =\
    \ front.first + ed.cost;\n        que.emplace(dist[ed.to], ed.to);\n      }\n\
    \    }\n  }\n\n  return dist;\n}\n\ntemplate <typename T>\nstd::pair<std::vector<T>,\
    \ std::vector<int>> dijkstra_path(const Graph<T>& graph, int start) {\n  int N\
    \ = (int)graph.size();\n  constexpr T INF = numeric_limits<T>::max();\n\n  using\
    \ P = std::pair<T, int>;\n  std::vector<T>dist(N, INF);\n  std::vector<int>prev(N,\
    \ -1);\n\n  std::priority_queue<P, std::vector<P>, std::greater<P>>que;\n  que.push(make_pair(T(0),\
    \ start));\n  dist[start] = T(0);\n\n  while (!que.empty()) {\n    P front = que.top();\
    \ que.pop();\n\n    if (dist[front.second] < front.first) continue;\n\n    for\
    \ (Edge ed : graph[front.second]) {\n      if (dist[ed.to] > front.first + ed.cost)\
    \ {\n        dist[ed.to] = front.first + ed.cost;\n        prev[ed.to] = front.second;\n\
    \        que.emplace(dist[ed.to], ed.to);\n      }\n    }\n  }\n\n  return make_pair(dist,\
    \ prev);\n}\n\n#endif // HARUILIB_GRAPH_DIJKSTRA_HPP"
  dependsOn:
  - graph/template.hpp
  isVerificationFile: false
  path: graph/dijkstra.hpp
  requiredBy: []
  timestamp: '2026-11-03 12:08:18+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/verify/yosupo-shortest-path.test.cpp
documentation_of: graph/dijkstra.hpp
layout: document
title: "Dijkstra(\u30C0\u30A4\u30AF\u30B9\u30C8\u30E9\u6CD5)"
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
