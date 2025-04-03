---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: structure/potentialized-union-find-tree.hpp
    title: "Potentialized Union Find Tree (\u30DD\u30C6\u30F3\u30B7\u30E3\u30EB\u3064\
      \u304DUnionFind\u6728)"
  - icon: ':heavy_check_mark:'
    path: template/template.hpp
    title: template/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_1_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_1_B
  bundledCode: "#line 1 \"test/verify/structure/aoj-dsl1-b.test.cpp\"\n#define PROBLEM\
    \ \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_1_B\"\n\n#line\
    \ 1 \"template/template.hpp\"\n#include <iostream>\n#include <cassert>\nusing\
    \ namespace std;\nusing ll = long long;\ntemplate<class T> inline bool chmax(T&\
    \ a, const T& b) {if (a<b) {a=b; return true;} return false;}\ntemplate<class\
    \ T> inline bool chmin(T& a, const T& b) {if (b<a) {a=b; return true;} return\
    \ false;}\nconst int INTINF = 1000001000;\nconst int INTMAX = 2147483647;\nconst\
    \ ll LLMAX = 9223372036854775807;\nconst ll LLINF = 1000000000000000000;\n#line\
    \ 1 \"structure/potentialized-union-find-tree.hpp\"\n\n\n\n#include <vector>\n\
    \ntemplate <typename T, T(*op)(T, T), T(*invop)(T, T), T(*e)()>\nstruct PotentializedUnionFindTree\
    \ {\nprivate:\n  int n;\n  std::vector<int> parent;\n  std::vector<int> rank;\n\
    \  std::vector<T> potential;\n\npublic:\n  explicit PotentializedUnionFindTree(int\
    \ _n) : n(_n), parent(_n), rank(_n, 0), potential(_n, e()) {\n    for (int i =\
    \ 0; i < n; ++i) {\n      parent[i] = i;\n    }\n  }\n  \n  int merge(int a, int\
    \ b, T d) {\n    assert(0 <= a && a < n);\n    assert(0 <= b && b < n);\n    int\
    \ rootA = leader(a);\n    int rootB = leader(b);\n\n    if (rootA == rootB) return\
    \ rootA;\n\n    T new_potential = invop(potential[a], op(d, potential[b]));\n\n\
    \    if (rank[rootA] < rank[rootB]) {  \n      std::swap(rootA, rootB);\n    \
    \  new_potential = invop(e(), new_potential);\n    }\n\n    parent[rootB] = rootA;\n\
    \    potential[rootB] = new_potential;\n\n    if (rank[rootA] == rank[rootB])\
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
    \ invop(potential[a], potential[b]);\n  }\n};\n\n\n#line 5 \"test/verify/structure/aoj-dsl1-b.test.cpp\"\
    \n\nll op(ll a, ll b) {\n  return a + b;\n}\n\nll invop(ll a, ll b) {\n  return\
    \ a - b;\n}\n\nll e() {\n  return 0LL;\n}\n\nint main() {\n  ios::sync_with_stdio(0);\
    \ cin.tie(0); cout.tie(0);\n  int n, q; cin >> n >> q;\n\n  PotentializedUnionFindTree<ll,op,invop,e>\
    \ puf(n);\n  for(int i=0; i<q; i++) {\n    int t; cin >> t;\n    int x, y; cin\
    \ >> x >> y;\n    if (t == 0) {\n      ll z; cin >> z;\n      puf.merge(x,y,-z);\n\
    \    }\n    else if (t == 1) {\n      if (puf.same(x,y)) {\n        ll diff =\
    \ puf.diff(y,x);\n        cout << diff << endl; \n      }\n      else cout <<\
    \ \"?\" <<  endl;\n    }\n  }\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_1_B\"\
    \n\n#include \"template/template.hpp\"\n#include \"structure/potentialized-union-find-tree.hpp\"\
    \n\nll op(ll a, ll b) {\n  return a + b;\n}\n\nll invop(ll a, ll b) {\n  return\
    \ a - b;\n}\n\nll e() {\n  return 0LL;\n}\n\nint main() {\n  ios::sync_with_stdio(0);\
    \ cin.tie(0); cout.tie(0);\n  int n, q; cin >> n >> q;\n\n  PotentializedUnionFindTree<ll,op,invop,e>\
    \ puf(n);\n  for(int i=0; i<q; i++) {\n    int t; cin >> t;\n    int x, y; cin\
    \ >> x >> y;\n    if (t == 0) {\n      ll z; cin >> z;\n      puf.merge(x,y,-z);\n\
    \    }\n    else if (t == 1) {\n      if (puf.same(x,y)) {\n        ll diff =\
    \ puf.diff(y,x);\n        cout << diff << endl; \n      }\n      else cout <<\
    \ \"?\" <<  endl;\n    }\n  }\n  return 0;\n}\n"
  dependsOn:
  - template/template.hpp
  - structure/potentialized-union-find-tree.hpp
  isVerificationFile: true
  path: test/verify/structure/aoj-dsl1-b.test.cpp
  requiredBy: []
  timestamp: '2024-08-21 21:41:37+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/verify/structure/aoj-dsl1-b.test.cpp
layout: document
redirect_from:
- /verify/test/verify/structure/aoj-dsl1-b.test.cpp
- /verify/test/verify/structure/aoj-dsl1-b.test.cpp.html
title: test/verify/structure/aoj-dsl1-b.test.cpp
---
