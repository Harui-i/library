---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/graph_template.hpp
    title: graph/graph_template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/verify/yosupo-shortest-path.test.cpp
    title: test/verify/yosupo-shortest-path.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/dijkstra.hpp\"\n\n\n\n#line 1 \"graph/graph_template.hpp\"\
    \n\n\n\n#include <vector>\n\ntemplate <typename T>\nstruct Edge {\n  int from;\
    \ int to;\n  T cost;\n\n  Edge(int _from, int _to, T _cost) : from(_from), to(_to),\
    \ cost(_cost) {}\n\n  // unweighted\n  Edge(int _from, int _to) : from(_from),\
    \ to(_to), cost(T(1)) {}\n\n  bool operator==(const Edge& rhs) {\n    return from\
    \ == rhs.from && to == rhs.to && cost == rhs.cost;\n  }\n\n};\n\n\ntemplate <typename\
    \ T>\nstruct Graph : std::vector<std::vector<Edge<T>>> {\n\n  using std::vector<std::vector<Edge<T>>>::vector;\
    \ // inherit constructors\n\n  void add_edge(int i, Edge<T> e) {\n    (*this)[i].push_back(e);\n\
    \  }\n\n  // weighted\n  void add_edge(int _from, int _to, T _cost) {\n    (*this)[_from].push_back(Edge(_from,\
    \ _to, _cost));\n  }\n\n  // unweighted\n  void add_edge(int _from, int _to) {\n\
    \    (*this)[_from].push_back(Edge(_from, _to, T(1)));\n  }\n\n};\n\n\n#line 5\
    \ \"graph/dijkstra.hpp\"\n\ntemplate <typename T>\nstd::vector<T> dijkstra(const\
    \ Graph<T>& graph, int start) {\n  int N = (int)graph.size();\n  vector<T>dist(N,\
    \ T(-1));\n  using P = pair<T, int>;\n\n  priority_queue<P, vector<P>, greater<P>>que;\n\
    \n  que.push(make_pair(T(0), start));\n  dist[start] = T(0);\n\n  while (!que.empty())\
    \ {\n    P front = que.top(); que.pop();\n\n    if (dist[front.second] < front.first)\
    \ continue;\n\n    for (Edge ed : graph[front.second]) {\n\n      if (dist[ed.to]\
    \ == T(-1) || dist[ed.to] > front.first + ed.cost) {\n        dist[ed.to] = front.first\
    \ + ed.cost;\n        que.emplace(dist[ed.to], ed.to);\n      }\n    }\n  }\n\n\
    \  return dist;\n}\n\ntemplate <typename T>\npair<vector<T>, vector<int>> dijkstra_path(const\
    \ Graph<T>& graph, int start) {\n  int N = (int)graph.size();\n\n  using P = pair<T,\
    \ int>;\n  vector<T>dist(N, T(-1));\n  vector<int>prev(N, -1);\n\n  priority_queue<P,\
    \ vector<P>, greater<P>>que;\n  que.push(make_pair(T(0), start));\n  dist[start]\
    \ = T(0);\n\n  while (!que.empty()) {\n    P front = que.top(); que.pop();\n\n\
    \    if (dist[front.second] < front.first) continue;\n\n    for (Edge ed : graph[front.second])\
    \ {\n      if (dist[ed.to] == T(-1) || dist[ed.to] > front.first + ed.cost) {\n\
    \        dist[ed.to] = front.first + ed.cost;\n        prev[ed.to] = front.second;\n\
    \        que.emplace(dist[ed.to], ed.to);\n      }\n    }\n  }\n\n  return make_pair(dist,\
    \ prev);\n}\n\n\n"
  code: "#ifndef HARUILIB_GRAPH_DIJKSTRA_HPP\n#define HARUILIB_GRAPH_DIJKSTRA_HPP\n\
    \n#include \"graph/graph_template.hpp\"\n\ntemplate <typename T>\nstd::vector<T>\
    \ dijkstra(const Graph<T>& graph, int start) {\n  int N = (int)graph.size();\n\
    \  vector<T>dist(N, T(-1));\n  using P = pair<T, int>;\n\n  priority_queue<P,\
    \ vector<P>, greater<P>>que;\n\n  que.push(make_pair(T(0), start));\n  dist[start]\
    \ = T(0);\n\n  while (!que.empty()) {\n    P front = que.top(); que.pop();\n\n\
    \    if (dist[front.second] < front.first) continue;\n\n    for (Edge ed : graph[front.second])\
    \ {\n\n      if (dist[ed.to] == T(-1) || dist[ed.to] > front.first + ed.cost)\
    \ {\n        dist[ed.to] = front.first + ed.cost;\n        que.emplace(dist[ed.to],\
    \ ed.to);\n      }\n    }\n  }\n\n  return dist;\n}\n\ntemplate <typename T>\n\
    pair<vector<T>, vector<int>> dijkstra_path(const Graph<T>& graph, int start) {\n\
    \  int N = (int)graph.size();\n\n  using P = pair<T, int>;\n  vector<T>dist(N,\
    \ T(-1));\n  vector<int>prev(N, -1);\n\n  priority_queue<P, vector<P>, greater<P>>que;\n\
    \  que.push(make_pair(T(0), start));\n  dist[start] = T(0);\n\n  while (!que.empty())\
    \ {\n    P front = que.top(); que.pop();\n\n    if (dist[front.second] < front.first)\
    \ continue;\n\n    for (Edge ed : graph[front.second]) {\n      if (dist[ed.to]\
    \ == T(-1) || dist[ed.to] > front.first + ed.cost) {\n        dist[ed.to] = front.first\
    \ + ed.cost;\n        prev[ed.to] = front.second;\n        que.emplace(dist[ed.to],\
    \ ed.to);\n      }\n    }\n  }\n\n  return make_pair(dist, prev);\n}\n\n#endif\
    \ // HARUILIB_GRAPH_DIJKSTRA_HPP"
  dependsOn:
  - graph/graph_template.hpp
  isVerificationFile: false
  path: graph/dijkstra.hpp
  requiredBy: []
  timestamp: '2024-07-31 19:55:29+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/verify/yosupo-shortest-path.test.cpp
documentation_of: graph/dijkstra.hpp
layout: document
titel: "Dijkstra(\u30C0\u30A4\u30AF\u30B9\u30C8\u30E9\u6CD5)"
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