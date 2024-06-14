---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: graph/dijkstra.hpp
    title: graph/dijkstra.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/verify/yosupo-shortest-path.test.cpp
    title: test/verify/yosupo-shortest-path.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/graph_template.hpp\"\n#include <vector>\ntemplate\
    \ <typename T>\nstruct Edge {\n  int from; int to;\n  T cost;\n\n  Edge(int _from,\
    \ int _to, T _cost) : from(_from), to(_to), cost(_cost) {}\n\n  // unweighted\n\
    \  Edge(int _from, int _to) : from(_from), to(_to), cost(T(1)) {}\n\n};\n\n\n\
    template <typename T>\nstruct Graph : vector<vector<Edge<T>>> {\n\n  using vector<vector<Edge<T>>>::vector;\
    \ // inherit constructors\n\n  void add_edge(int i, Edge<T> e) {\n    (*this)[i].push_back(e);\n\
    \  }\n\n  // weighted\n  void add_edge(int _from, int _to, T _cost) {\n    (*this)[_from].push_back(Edge(_from,\
    \ _to, _cost));\n  }\n\n  // unweighted\n  void add_edge(int _from, int _to) {\n\
    \    (*this)[_from].push_back(Edge(_from, _to, T(1)));\n  }\n\n};\n"
  code: "#pragma once\n#include <vector>\ntemplate <typename T>\nstruct Edge {\n \
    \ int from; int to;\n  T cost;\n\n  Edge(int _from, int _to, T _cost) : from(_from),\
    \ to(_to), cost(_cost) {}\n\n  // unweighted\n  Edge(int _from, int _to) : from(_from),\
    \ to(_to), cost(T(1)) {}\n\n};\n\n\ntemplate <typename T>\nstruct Graph : vector<vector<Edge<T>>>\
    \ {\n\n  using vector<vector<Edge<T>>>::vector; // inherit constructors\n\n  void\
    \ add_edge(int i, Edge<T> e) {\n    (*this)[i].push_back(e);\n  }\n\n  // weighted\n\
    \  void add_edge(int _from, int _to, T _cost) {\n    (*this)[_from].push_back(Edge(_from,\
    \ _to, _cost));\n  }\n\n  // unweighted\n  void add_edge(int _from, int _to) {\n\
    \    (*this)[_from].push_back(Edge(_from, _to, T(1)));\n  }\n\n};"
  dependsOn: []
  isVerificationFile: false
  path: graph/graph_template.hpp
  requiredBy:
  - graph/dijkstra.hpp
  timestamp: '2024-06-14 18:26:48+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/verify/yosupo-shortest-path.test.cpp
documentation_of: graph/graph_template.hpp
layout: document
redirect_from:
- /library/graph/graph_template.hpp
- /library/graph/graph_template.hpp.html
title: graph/graph_template.hpp
---
