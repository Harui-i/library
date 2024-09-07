---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: graph/graph_template.hpp
    title: graph/graph_template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/verify/aoj-grl-1b.test.cpp
    title: test/verify/aoj-grl-1b.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links:
    - https://ei1333.github.io/library/graph/shortest-path/bellman-ford.hpp
  bundledCode: "#line 1 \"graph/bellmanford.hpp\"\n\n\n\n#include <cassert>\n#include\
    \ <queue>\n#include <vector>\n#include <limits>\n\n#line 1 \"graph/graph_template.hpp\"\
    \n\n\n\n#line 5 \"graph/graph_template.hpp\"\n\ntemplate <typename T>\nstruct\
    \ Edge {\n  int from; int to;\n  T cost;\n\n  // default constructor\n  Edge ()\
    \ : from(-1), to(-1), cost(T(0)) {}\n\n  Edge(int _from, int _to, T _cost) : from(_from),\
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
    \    (*this)[_from].push_back(Edge(_from, _to, T(1)));\n  }\n\n};\n\n\n#line 10\
    \ \"graph/bellmanford.hpp\"\n\n// \u5B8C\u5168\u306B\u30D1\u30AF\u30EA\u307E\u3057\
    \u305F\n// https://ei1333.github.io/library/graph/shortest-path/bellman-ford.hpp\n\
    template <typename T> \nstd::vector<T> bellman_ford(const std::vector<Edge<T>>&\
    \ edges, int N, int start) {\n  assert(0 <= start && start < N);\n\n  const int\
    \ M = int(edges.size());\n  constexpr T PLINF = std::numeric_limits<T>::max();\n\
    \  constexpr T MNINF = std::numeric_limits<T>::min();\n\n  std::vector<T> dist(N,\
    \ PLINF);\n  dist[start] = T(0);\n\n  for (int i=0; i<N-1; i++) {\n    for (int\
    \ j=0; j<M; j++) {\n      Edge e = edges[j];\n      if (dist[e.from] >= PLINF)\
    \ continue;\n\n      if (dist[e.to] > dist[e.from] + e.cost) {\n        dist[e.to]\
    \ = dist[e.from] + e.cost;\n      }\n    }\n  }\n\n  std::vector<bool> negative(N,\
    \ false);\n\n  for (int i=0; i<N; i++) {\n    for (int j=0; j<M; j++) {\n    \
    \  Edge e = edges[j];\n\n      if (dist[e.from] >= PLINF) continue;\n      if\
    \ (dist[e.to] > dist[e.from] + e.cost) {\n        dist[e.to] = dist[e.from] +\
    \ e.cost;\n        negative[e.to] = true;\n      }\n\n      if (negative[e.from])\
    \ negative[e.to] = true;\n    }\n  }\n\n  for (int i=0; i<N; i++) if (negative[i])\
    \ dist[i] = MNINF;\n\n  return dist;\n}\n\n\n"
  code: "#ifndef HARUILIB_GRAPH_BELLMANFORD_HPP\n#define HARUILIB_GRAPH_BELLMANFORD_HPP\n\
    \n#include <cassert>\n#include <queue>\n#include <vector>\n#include <limits>\n\
    \n#include \"graph/graph_template.hpp\"\n\n// \u5B8C\u5168\u306B\u30D1\u30AF\u30EA\
    \u307E\u3057\u305F\n// https://ei1333.github.io/library/graph/shortest-path/bellman-ford.hpp\n\
    template <typename T> \nstd::vector<T> bellman_ford(const std::vector<Edge<T>>&\
    \ edges, int N, int start) {\n  assert(0 <= start && start < N);\n\n  const int\
    \ M = int(edges.size());\n  constexpr T PLINF = std::numeric_limits<T>::max();\n\
    \  constexpr T MNINF = std::numeric_limits<T>::min();\n\n  std::vector<T> dist(N,\
    \ PLINF);\n  dist[start] = T(0);\n\n  for (int i=0; i<N-1; i++) {\n    for (int\
    \ j=0; j<M; j++) {\n      Edge e = edges[j];\n      if (dist[e.from] >= PLINF)\
    \ continue;\n\n      if (dist[e.to] > dist[e.from] + e.cost) {\n        dist[e.to]\
    \ = dist[e.from] + e.cost;\n      }\n    }\n  }\n\n  std::vector<bool> negative(N,\
    \ false);\n\n  for (int i=0; i<N; i++) {\n    for (int j=0; j<M; j++) {\n    \
    \  Edge e = edges[j];\n\n      if (dist[e.from] >= PLINF) continue;\n      if\
    \ (dist[e.to] > dist[e.from] + e.cost) {\n        dist[e.to] = dist[e.from] +\
    \ e.cost;\n        negative[e.to] = true;\n      }\n\n      if (negative[e.from])\
    \ negative[e.to] = true;\n    }\n  }\n\n  for (int i=0; i<N; i++) if (negative[i])\
    \ dist[i] = MNINF;\n\n  return dist;\n}\n\n#endif // HARUILIB_GRAPH_BELLMANFORD_HPP"
  dependsOn:
  - graph/graph_template.hpp
  isVerificationFile: false
  path: graph/bellmanford.hpp
  requiredBy: []
  timestamp: '2024-09-07 20:55:28+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/verify/aoj-grl-1b.test.cpp
documentation_of: graph/bellmanford.hpp
layout: document
title: "Bellmanford(\u30D9\u30EB\u30DE\u30F3\u30D5\u30A9\u30FC\u30C9\u6CD5)"
---

負辺のあるグラフでも最短距離を求められるアルゴリズム。
めちゃめちゃ参考にしました: [https://ei1333.github.io/library/graph/shortest-path/bellman-ford.hpp](https://ei1333.github.io/library/graph/shortest-path/bellman-ford.hpp)

## bellman_ford
```
vector<T> bellman_ford(const vector<Edge<T>>& edges, int N, int start)
```

ベルマンフォード法を行い、頂点`start`から各頂点`v`までの最短距離が格納された`vector`
である`dist`を返す。

`dist[v]`は、vが到達できない頂点のとき正の無限大が格納され、`start`から`v`までの経路に負の閉路があったときは負の無限大が格納される。

無限大と書いたが、実際には型`T`で表せる最大/最小の数が使われている。

### 計算量

頂点数を $V$、辺の数を$E$として
- $ O(VE) $

