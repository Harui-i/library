---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/verify/yosupo-point-add-range-sum.test.cpp
    title: test/verify/yosupo-point-add-range-sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/verify/yosupo-vertex-add-path-sum.test.cpp
    title: test/verify/yosupo-vertex-add-path-sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"structure/fenwick_tree.hpp\"\n\n\n\n#include <vector>\n\
    #include <cassert>\n\ntemplate <class T> struct fenwick_tree {\n  fenwick_tree():\
    \ _n(0) {}\n  explicit fenwick_tree(int n): _n(n), data(n) {}\n\n  // point add\n\
    \  void add(int p, T x) {\n    assert(0 <= p && p < _n);\n    p++;\n    while\
    \ (p <= _n) {\n      data[p-1] += T(x);\n      p += p & -p;\n    }\n  } \n\n \
    \ T sum(int l, int r) {\n    assert(0 <= l && l <= r && r <= _n);\n    return\
    \ sum(r) - sum(l);\n  }\n\nprivate:\n  int _n;\n  std::vector<T> data;\n  T sum(int\
    \ r) {\n    T ret(0);\n    while (r > 0) {\n      ret += data[r-1];\n      r -=\
    \ r & -r;\n    }\n\n    return ret;\n  }\n};\n\n\n"
  code: "#ifndef HARUILIB_STRUCTURE_FENWICK_TREE_HPP\n#define HARUILIB_STRUCTURE_FENWICK_TREE_HPP\n\
    \n#include <vector>\n#include <cassert>\n\ntemplate <class T> struct fenwick_tree\
    \ {\n  fenwick_tree(): _n(0) {}\n  explicit fenwick_tree(int n): _n(n), data(n)\
    \ {}\n\n  // point add\n  void add(int p, T x) {\n    assert(0 <= p && p < _n);\n\
    \    p++;\n    while (p <= _n) {\n      data[p-1] += T(x);\n      p += p & -p;\n\
    \    }\n  } \n\n  T sum(int l, int r) {\n    assert(0 <= l && l <= r && r <= _n);\n\
    \    return sum(r) - sum(l);\n  }\n\nprivate:\n  int _n;\n  std::vector<T> data;\n\
    \  T sum(int r) {\n    T ret(0);\n    while (r > 0) {\n      ret += data[r-1];\n\
    \      r -= r & -r;\n    }\n\n    return ret;\n  }\n};\n\n#endif // HARUILIB_STRUCTURE_FENWICK_TREE_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: structure/fenwick_tree.hpp
  requiredBy: []
  timestamp: '2025-03-23 14:07:18+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/verify/yosupo-vertex-add-path-sum.test.cpp
  - test/verify/yosupo-point-add-range-sum.test.cpp
documentation_of: structure/fenwick_tree.hpp
layout: document
redirect_from:
- /library/structure/fenwick_tree.hpp
- /library/structure/fenwick_tree.hpp.html
title: structure/fenwick_tree.hpp
---
