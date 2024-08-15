---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: graph/diameter.hpp
    title: graph/diameter.hpp
  - icon: ':heavy_check_mark:'
    path: graph/dijkstra.hpp
    title: graph/dijkstra.hpp
  - icon: ':heavy_check_mark:'
    path: graph/tree/heavy_light_decomposition.hpp
    title: graph/tree/heavy_light_decomposition.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/verify/yosupo-shortest-path.test.cpp
    title: test/verify/yosupo-shortest-path.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/verify/yosupo-tree-diameter.test.cpp
    title: test/verify/yosupo-tree-diameter.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/verify/yosupo-vertex-add-path-sum.test.cpp
    title: test/verify/yosupo-vertex-add-path-sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/verify/yosupo-vertex-add-subtree-sum.test.cpp
    title: test/verify/yosupo-vertex-add-subtree-sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/verify/yosupo-vertex-set-path-composite.test.cpp
    title: test/verify/yosupo-vertex-set-path-composite.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/graph_template.hpp\"\n\n\n\n#include <vector>\n\n\
    template <typename T>\nstruct Edge {\n  int from; int to;\n  T cost;\n\n  Edge(int\
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
    \    (*this)[_from].push_back(Edge(_from, _to, T(1)));\n  }\n\n};\n\n\n"
  code: "#ifndef HARUILIB_GRAPH_TEMPLATE_HPP\n#define HARUILIB_GRAPH_TEMPLATE_HPP\n\
    \n#include <vector>\n\ntemplate <typename T>\nstruct Edge {\n  int from; int to;\n\
    \  T cost;\n\n  Edge(int _from, int _to, T _cost) : from(_from), to(_to), cost(_cost)\
    \ {}\n\n  // unweighted\n  Edge(int _from, int _to) : from(_from), to(_to), cost(T(1))\
    \ {}\n\n  bool operator==(const Edge& rhs) const {\n    return from == rhs.from\
    \ && to == rhs.to && cost == rhs.cost;\n  }\n\n  bool operator<(const Edge& rhs)\
    \ const {\n    return cost < rhs.cost;\n  }\n  \n  bool operator>(const Edge&\
    \ rhs) const {\n    return cost > rhs.cost;\n  }\n\n};\n\n\ntemplate <typename\
    \ T>\nstruct Graph : std::vector<std::vector<Edge<T>>> {\n\n  using std::vector<std::vector<Edge<T>>>::vector;\
    \ // inherit constructors\n\n  void add_edge(int i, Edge<T> e) {\n    (*this)[i].push_back(e);\n\
    \  }\n\n  void add_edge(Edge<T> e) {\n    (*this)[e.from].push_back(e);\n  }\n\
    \n  // weighted\n  void add_edge(int _from, int _to, T _cost) {\n    (*this)[_from].push_back(Edge(_from,\
    \ _to, _cost));\n  }\n\n  // unweighted\n  void add_edge(int _from, int _to) {\n\
    \    (*this)[_from].push_back(Edge(_from, _to, T(1)));\n  }\n\n};\n\n#endif //\
    \ HARUILIB_GRAPH_TEMPLATE_HPP"
  dependsOn: []
  isVerificationFile: false
  path: graph/graph_template.hpp
  requiredBy:
  - graph/tree/heavy_light_decomposition.hpp
  - graph/dijkstra.hpp
  - graph/diameter.hpp
  timestamp: '2024-08-15 16:38:21+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/verify/yosupo-shortest-path.test.cpp
  - test/verify/yosupo-vertex-add-subtree-sum.test.cpp
  - test/verify/yosupo-tree-diameter.test.cpp
  - test/verify/yosupo-vertex-add-path-sum.test.cpp
  - test/verify/yosupo-vertex-set-path-composite.test.cpp
documentation_of: graph/graph_template.hpp
layout: document
redirect_from:
- /library/graph/graph_template.hpp
- /library/graph/graph_template.hpp.html
title: graph/graph_template.hpp
---
