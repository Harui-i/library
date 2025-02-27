---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"structure/dual-fenwick-tree.hpp\"\n\n\n\n#include <cassert>\n\
    #include <vector>\n\ntemplate <class T> struct dual_fenwick_tree {\npublic:\n\
    \  dual_fenwick_tree(): _n(0) {}\n  explicit dual_fenwick_tree(int n): _n(n),\
    \ data(n) {}\n\n  // point sum\n  T sum(int p) {\n    assert(0 <= p && p < _n);\n\
    \    T ret = T(0);\n    p++;\n    while (p <= _n) {\n      ret += data[p-1];\n\
    \      p += p & -p;\n    }\n\n    return ret;\n  }\n\n  void add(int l, int r,\
    \ T x) {\n     assert(0 <= l && l <= r && r <= _n);\n     add(r, x);\n     add(l,\
    \ -x);\n  }\nprivate:\n  int _n;\n  std::vector<T> data;\n  void add(int r, T\
    \ x) {\n    while (r > 0) {\n      data[r-1] += x;\n      r -= r & -r;\n    }\n\
    \    \n  }\n};\n\n\n"
  code: "#ifndef HARUILIB_STRUCTURE_DUAL_FENWICK_TREE_HPP\n#define HARUILIB_STRUCTURE_DUAL_FENWICK_TREE_HPP\n\
    \n#include <cassert>\n#include <vector>\n\ntemplate <class T> struct dual_fenwick_tree\
    \ {\npublic:\n  dual_fenwick_tree(): _n(0) {}\n  explicit dual_fenwick_tree(int\
    \ n): _n(n), data(n) {}\n\n  // point sum\n  T sum(int p) {\n    assert(0 <= p\
    \ && p < _n);\n    T ret = T(0);\n    p++;\n    while (p <= _n) {\n      ret +=\
    \ data[p-1];\n      p += p & -p;\n    }\n\n    return ret;\n  }\n\n  void add(int\
    \ l, int r, T x) {\n     assert(0 <= l && l <= r && r <= _n);\n     add(r, x);\n\
    \     add(l, -x);\n  }\nprivate:\n  int _n;\n  std::vector<T> data;\n  void add(int\
    \ r, T x) {\n    while (r > 0) {\n      data[r-1] += x;\n      r -= r & -r;\n\
    \    }\n    \n  }\n};\n\n#endif // HARUILIB_STRUCTURE_DUALFENWICK_TREE_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: structure/dual-fenwick-tree.hpp
  requiredBy: []
  timestamp: '2025-02-28 00:31:43+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: structure/dual-fenwick-tree.hpp
layout: document
redirect_from:
- /library/structure/dual-fenwick-tree.hpp
- /library/structure/dual-fenwick-tree.hpp.html
title: structure/dual-fenwick-tree.hpp
---
