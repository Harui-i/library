---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: graph/graph_template.hpp
    title: graph/graph_template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/verify/yosupo-tree-diameter.test.cpp
    title: test/verify/yosupo-tree-diameter.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/diameter.hpp\"\n\n\n\n\n#include <vector>\n#include\
    \ <queue>\n#line 1 \"graph/graph_template.hpp\"\n\n\n\n#line 5 \"graph/graph_template.hpp\"\
    \n\ntemplate <typename T>\nstruct Edge {\n  int from; int to;\n  T cost;\n\n \
    \ // default constructor\n  Edge () : from(-1), to(-1), cost(T(0)) {}\n\n  Edge(int\
    \ _from, int _to, T _cost) : from(_from), to(_to), cost(_cost) {}\n\n  // unweighted\n\
    \  Edge(int _from, int _to) : from(_from), to(_to), cost(T(1)) {}\n\n  bool operator==(const\
    \ Edge& rhs) const {\n    return from == rhs.from && to == rhs.to && cost == rhs.cost;\n\
    \  }\n\n  bool operator<(const Edge& rhs) const {\n    return cost < rhs.cost;\n\
    \  }\n  \n  bool operator>(const Edge& rhs) const {\n    return cost > rhs.cost;\n\
    \  }\n\n};\n\n\ntemplate <typename T>\nstruct Graph : std::vector<std::vector<Edge<T>>>\
    \ {\n\n  using std::vector<std::vector<Edge<T>>>::vector; // inherit constructors\n\
    \n  void add_edge(int i, Edge<T> e) {\n    (*this)[i].push_back(e);\n  }\n\n \
    \ void add_edge(Edge<T> e) {\n    (*this)[e.from].push_back(e);\n  }\n\n  // weighted\n\
    \  void add_edge(int _from, int _to, T _cost) {\n    (*this)[_from].push_back(Edge(_from,\
    \ _to, _cost));\n  }\n\n  // unweighted\n  void add_edge(int _from, int _to) {\n\
    \    (*this)[_from].push_back(Edge(_from, _to, T(1)));\n  }\n\n};\n\n\n#line 8\
    \ \"graph/diameter.hpp\"\n\nnamespace mylib {\n\n  using std::vector;\n  using\
    \ std::pair;\n  using std::queue;\n\n  template <typename T>\n  pair<vector<int>,\
    \ T> diameter_path(const Graph<T>& graph) {\n    int N = (int)graph.size();\n\n\
    \    // first sweep\n    pair<T, int> farest1 = make_pair(T(0), 0);\n    {\n \
    \     vector<T> dist(N, T(-1));\n      dist[0] = T(0);\n\n      queue<int> que;\n\
    \      que.push(0);\n      while (!que.empty()) {\n        int front = que.front();\
    \ que.pop();\n\n        for (Edge e: graph[front]) {\n          if (dist[e.to]\
    \ == T(-1)) {\n            dist[e.to] = dist[front] + e.cost;\n            que.push(e.to);\n\
    \            if (farest1.first == -1 || farest1.first < dist[e.to]) {\n      \
    \        farest1 = make_pair(dist[e.to], e.to);\n            }\n          }\n\
    \        }\n      }\n    }\n\n\n    pair<T, int> farest2 = make_pair(T(0), farest1.second);\n\
    \    // second sweep\n    vector<int> prev(N, -1);\n    {\n      int start = farest1.second;\n\
    \      vector<T> dist(N, T(-1));\n      dist[start] = T(0);\n\n      queue<int>\
    \ que;\n      que.push(start);\n\n      while (!que.empty()) {\n        int front\
    \ = que.front(); que.pop();\n\n        for (Edge e: graph[front]) {\n        \
    \  if (dist[e.to] == T(-1)) {\n            dist[e.to] = dist[front] + e.cost;\n\
    \            prev[e.to] = front;\n            que.push(e.to);\n          }\n\n\
    \          if (farest2.second == -1 || farest2.first < dist[e.to]) {\n       \
    \     farest2 = make_pair(dist[e.to], e.to);\n          }\n        }\n      }\n\
    \    }\n\n    vector<int> diameter_path;\n    {\n      int now = farest2.second;\n\
    \      while (now != -1) {\n        diameter_path.push_back(now);\n        now\
    \ = prev[now];\n      }\n\n      reverse(diameter_path.begin(), diameter_path.end());\n\
    \    }\n\n    return make_pair(diameter_path, farest2.first);\n  }\n\n} // namespace\
    \ mylib\n\n\n"
  code: "#ifndef HARUILIB_GRAPH_DIAMETER_HPP\n#define HARUILIB_GRAPH_DIAMETER_HPP\n\
    \n\n#include <vector>\n#include <queue>\n#include \"graph/graph_template.hpp\"\
    \n\nnamespace mylib {\n\n  using std::vector;\n  using std::pair;\n  using std::queue;\n\
    \n  template <typename T>\n  pair<vector<int>, T> diameter_path(const Graph<T>&\
    \ graph) {\n    int N = (int)graph.size();\n\n    // first sweep\n    pair<T,\
    \ int> farest1 = make_pair(T(0), 0);\n    {\n      vector<T> dist(N, T(-1));\n\
    \      dist[0] = T(0);\n\n      queue<int> que;\n      que.push(0);\n      while\
    \ (!que.empty()) {\n        int front = que.front(); que.pop();\n\n        for\
    \ (Edge e: graph[front]) {\n          if (dist[e.to] == T(-1)) {\n           \
    \ dist[e.to] = dist[front] + e.cost;\n            que.push(e.to);\n          \
    \  if (farest1.first == -1 || farest1.first < dist[e.to]) {\n              farest1\
    \ = make_pair(dist[e.to], e.to);\n            }\n          }\n        }\n    \
    \  }\n    }\n\n\n    pair<T, int> farest2 = make_pair(T(0), farest1.second);\n\
    \    // second sweep\n    vector<int> prev(N, -1);\n    {\n      int start = farest1.second;\n\
    \      vector<T> dist(N, T(-1));\n      dist[start] = T(0);\n\n      queue<int>\
    \ que;\n      que.push(start);\n\n      while (!que.empty()) {\n        int front\
    \ = que.front(); que.pop();\n\n        for (Edge e: graph[front]) {\n        \
    \  if (dist[e.to] == T(-1)) {\n            dist[e.to] = dist[front] + e.cost;\n\
    \            prev[e.to] = front;\n            que.push(e.to);\n          }\n\n\
    \          if (farest2.second == -1 || farest2.first < dist[e.to]) {\n       \
    \     farest2 = make_pair(dist[e.to], e.to);\n          }\n        }\n      }\n\
    \    }\n\n    vector<int> diameter_path;\n    {\n      int now = farest2.second;\n\
    \      while (now != -1) {\n        diameter_path.push_back(now);\n        now\
    \ = prev[now];\n      }\n\n      reverse(diameter_path.begin(), diameter_path.end());\n\
    \    }\n\n    return make_pair(diameter_path, farest2.first);\n  }\n\n} // namespace\
    \ mylib\n\n#endif // HARUILIB_GRAPH_DIAMETER_HPP"
  dependsOn:
  - graph/graph_template.hpp
  isVerificationFile: false
  path: graph/diameter.hpp
  requiredBy: []
  timestamp: '2024-09-07 20:55:28+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/verify/yosupo-tree-diameter.test.cpp
documentation_of: graph/diameter.hpp
layout: document
title: "Tree Diameter(\u6728\u306E\u76F4\u5F84)"
---

木の直径を求める。