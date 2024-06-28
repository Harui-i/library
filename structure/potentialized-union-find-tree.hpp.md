---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/verify/structure/aoj-dsl1-b.test.cpp
    title: test/verify/structure/aoj-dsl1-b.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"structure/potentialized-union-find-tree.hpp\"\n\n\n\n#include\
    \ <vector>\n\ntemplate <typename T, T(*op)(T, T), T(*invop)(T, T), T(*e)()>\n\
    struct PotentializedUnionFindTree {\nprivate:\n  int n;\n  std::vector<int> parent;\n\
    \  std::vector<int> rank;\n  std::vector<T> potential;\n\npublic:\n  explicit\
    \ PotentializedUnionFindTree(int _n) : n(_n), parent(_n), rank(_n, 0), potential(_n,\
    \ e()) {\n    for (int i = 0; i < n; ++i) {\n      parent[i] = i;\n    }\n  }\n\
    \  \n  int merge(int a, int b, T d) {\n    assert(0 <= a && a < n);\n    assert(0\
    \ <= b && b < n);\n    int rootA = leader(a);\n    int rootB = leader(b);\n\n\
    \    if (rootA == rootB) return rootA;\n\n    T new_potential = invop(potential[a],\
    \ op(d, potential[b]));\n\n    if (rank[rootA] < rank[rootB]) {  \n      std::swap(rootA,\
    \ rootB);\n      new_potential = invop(e(), new_potential);\n    }\n\n    parent[rootB]\
    \ = rootA;\n    potential[rootB] = new_potential;\n\n    if (rank[rootA] == rank[rootB])\
    \ {\n      rank[rootA]++;\n    }\n\n    return rootA;\n  }\n\n  bool same(int\
    \ a, int b) {\n    assert(0 <= a && a < n);\n    assert(0 <= b && b < n);\n  \
    \  return leader(a) == leader(b);\n  }\n\n  int leader(int a) {\n    assert(0\
    \ <= a && a < n);\n    if (parent[a] != a) {\n      int root = leader(parent[a]);\n\
    \      potential[a] = op(potential[a], potential[parent[a]]);\n      parent[a]\
    \ = root;\n    }\n    return parent[a];\n  }\n\n  int size(int a) {\n    assert(0\
    \ <= a && a < n);\n    int root = leader(a);\n    int size = 0;\n    for (int\
    \ i = 0; i < n; ++i) {\n      if (leader(i) == root) {\n        ++size;\n    \
    \  }\n    }\n    return size;\n  }\n\n  T diff(int a, int b) {\n    assert(0 <=\
    \ a && a < n);\n    assert(0 <= b && b < n);\n    assert(same(a,b));\n    return\
    \ invop(potential[a], potential[b]);\n  }\n};\n\n\n"
  code: "#ifndef HARUILIB_STRUCTURE_POTENTIALIZED_UNION_FIND_TREE_HPP\n#define HARUILIB_STRUCTURE_POTENTIALIZED_UNION_FIND_TREE_HPP\n\
    \n#include <vector>\n\ntemplate <typename T, T(*op)(T, T), T(*invop)(T, T), T(*e)()>\n\
    struct PotentializedUnionFindTree {\nprivate:\n  int n;\n  std::vector<int> parent;\n\
    \  std::vector<int> rank;\n  std::vector<T> potential;\n\npublic:\n  explicit\
    \ PotentializedUnionFindTree(int _n) : n(_n), parent(_n), rank(_n, 0), potential(_n,\
    \ e()) {\n    for (int i = 0; i < n; ++i) {\n      parent[i] = i;\n    }\n  }\n\
    \  \n  int merge(int a, int b, T d) {\n    assert(0 <= a && a < n);\n    assert(0\
    \ <= b && b < n);\n    int rootA = leader(a);\n    int rootB = leader(b);\n\n\
    \    if (rootA == rootB) return rootA;\n\n    T new_potential = invop(potential[a],\
    \ op(d, potential[b]));\n\n    if (rank[rootA] < rank[rootB]) {  \n      std::swap(rootA,\
    \ rootB);\n      new_potential = invop(e(), new_potential);\n    }\n\n    parent[rootB]\
    \ = rootA;\n    potential[rootB] = new_potential;\n\n    if (rank[rootA] == rank[rootB])\
    \ {\n      rank[rootA]++;\n    }\n\n    return rootA;\n  }\n\n  bool same(int\
    \ a, int b) {\n    assert(0 <= a && a < n);\n    assert(0 <= b && b < n);\n  \
    \  return leader(a) == leader(b);\n  }\n\n  int leader(int a) {\n    assert(0\
    \ <= a && a < n);\n    if (parent[a] != a) {\n      int root = leader(parent[a]);\n\
    \      potential[a] = op(potential[a], potential[parent[a]]);\n      parent[a]\
    \ = root;\n    }\n    return parent[a];\n  }\n\n  int size(int a) {\n    assert(0\
    \ <= a && a < n);\n    int root = leader(a);\n    int size = 0;\n    for (int\
    \ i = 0; i < n; ++i) {\n      if (leader(i) == root) {\n        ++size;\n    \
    \  }\n    }\n    return size;\n  }\n\n  T diff(int a, int b) {\n    assert(0 <=\
    \ a && a < n);\n    assert(0 <= b && b < n);\n    assert(same(a,b));\n    return\
    \ invop(potential[a], potential[b]);\n  }\n};\n\n#endif // HARUILIB_STRUCTURE_POTENTIALIZED_UNION_FIND_TREE_HPP"
  dependsOn: []
  isVerificationFile: false
  path: structure/potentialized-union-find-tree.hpp
  requiredBy: []
  timestamp: '2024-06-28 19:20:57+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/verify/structure/aoj-dsl1-b.test.cpp
documentation_of: structure/potentialized-union-find-tree.hpp
layout: document
title: "Potentialized Union Find Tree (\u30DD\u30C6\u30F3\u30B7\u30E3\u30EB\u3064\u304D\
  UnionFind\u6728)"
---


## コンストラクタ

```
PotentializedUnionFindTree<T, op, invop, e>()
```
T: 群(の載ってる集合), op: 二項演算, invop: 二項演算の逆元, e: 二項演算の単位元を返す関数。

# merge

```
int merge(int a, int b, T t)
```
aのポテンシャル - bのポテンシャルが`t`になるように併合する。

### 計算量
- ならし $ (O(\alpha(n))) $

# diff 

```
T diff(int a, int b)
```
aのポテンシャル - bのポテンシャルを計算する。


### 計算量
- ならし $ (O(\alpha(n))) $

