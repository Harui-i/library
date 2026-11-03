---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: structure/offline_2dsum.hpp
    title: Offline 2D Sum (Rectangle Sum)
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/verify/structure/yosupo-rectangle-sum.test.cpp
    title: test/verify/structure/yosupo-rectangle-sum.test.cpp
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
    links:
    - https://harui-i.github.io/library/structure/fenwick_tree.hpp.html
  bundledCode: "#line 1 \"structure/fenwick_tree.hpp\"\n\n\n// https://harui-i.github.io/library/structure/fenwick_tree.hpp.html\n\
    \n#include <vector>\n#include <cassert>\n\ntemplate <class T> struct FenwickTree\
    \ {\n  FenwickTree(): _n(0) {}\n  explicit FenwickTree(int n): _n(n), data(n)\
    \ {}\n\n  // point add\n  void add(int p, T x) {\n    assert(0 <= p && p < _n);\n\
    \    p++;\n    while (p <= _n) {\n      data[p-1] += T(x);\n      p += p & -p;\n\
    \    }\n  } \n\n  T sum(int l, int r) {\n    assert(0 <= l && l <= r && r <= _n);\n\
    \    return sum(r) - sum(l);\n  }\n\nprivate:\n  int _n;\n  std::vector<T> data;\n\
    \  T sum(int r) {\n    T ret(0);\n    while (r > 0) {\n      ret += data[r-1];\n\
    \      r -= r & -r;\n    }\n\n    return ret;\n  }\n};\n\n\n"
  code: "#ifndef HARUILIB_STRUCTURE_FENWICK_TREE_HPP\n#define HARUILIB_STRUCTURE_FENWICK_TREE_HPP\n\
    // https://harui-i.github.io/library/structure/fenwick_tree.hpp.html\n\n#include\
    \ <vector>\n#include <cassert>\n\ntemplate <class T> struct FenwickTree {\n  FenwickTree():\
    \ _n(0) {}\n  explicit FenwickTree(int n): _n(n), data(n) {}\n\n  // point add\n\
    \  void add(int p, T x) {\n    assert(0 <= p && p < _n);\n    p++;\n    while\
    \ (p <= _n) {\n      data[p-1] += T(x);\n      p += p & -p;\n    }\n  } \n\n \
    \ T sum(int l, int r) {\n    assert(0 <= l && l <= r && r <= _n);\n    return\
    \ sum(r) - sum(l);\n  }\n\nprivate:\n  int _n;\n  std::vector<T> data;\n  T sum(int\
    \ r) {\n    T ret(0);\n    while (r > 0) {\n      ret += data[r-1];\n      r -=\
    \ r & -r;\n    }\n\n    return ret;\n  }\n};\n\n#endif // HARUILIB_STRUCTURE_FENWICK_TREE_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: structure/fenwick_tree.hpp
  requiredBy:
  - structure/offline_2dsum.hpp
  timestamp: '2026-11-03 12:09:05+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/verify/yosupo-point-add-range-sum.test.cpp
  - test/verify/structure/yosupo-rectangle-sum.test.cpp
  - test/verify/yosupo-vertex-add-path-sum.test.cpp
documentation_of: structure/fenwick_tree.hpp
layout: document
redirect_from:
- /library/structure/fenwick_tree.hpp
- /library/structure/fenwick_tree.hpp.html
title: structure/fenwick_tree.hpp
---
