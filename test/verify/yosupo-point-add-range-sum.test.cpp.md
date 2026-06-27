---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: structure/fenwick_tree.hpp
    title: structure/fenwick_tree.hpp
  - icon: ':question:'
    path: template/template.hpp
    title: template/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/point_add_range_sum
    links:
    - https://judge.yosupo.jp/problem/point_add_range_sum
  bundledCode: "#line 1 \"test/verify/yosupo-point-add-range-sum.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n#line 1 \"\
    template/template.hpp\"\n#include <iostream>\n#include <cassert>\nusing namespace\
    \ std;\nusing ll = long long;\ntemplate<class T> inline bool chmax(T& a, const\
    \ T& b) {if (a<b) {a=b; return true;} return false;}\ntemplate<class T> inline\
    \ bool chmin(T& a, const T& b) {if (b<a) {a=b; return true;} return false;}\n\
    const int INTINF = 1000001000;\nconst int INTMAX = 2147483647;\nconst ll LLMAX\
    \ = 9223372036854775807;\nconst ll LLINF = 1000000000000000000;\n#line 3 \"test/verify/yosupo-point-add-range-sum.test.cpp\"\
    \n\n#include <vector>\n#line 1 \"structure/fenwick_tree.hpp\"\n\n\n\n#line 6 \"\
    structure/fenwick_tree.hpp\"\n\ntemplate <class T> struct fenwick_tree {\n  fenwick_tree():\
    \ _n(0) {}\n  explicit fenwick_tree(int n): _n(n), data(n) {}\n\n  // point add\n\
    \  void add(int p, T x) {\n    assert(0 <= p && p < _n);\n    p++;\n    while\
    \ (p <= _n) {\n      data[p-1] += T(x);\n      p += p & -p;\n    }\n  } \n\n \
    \ T sum(int l, int r) {\n    assert(0 <= l && l <= r && r <= _n);\n    return\
    \ sum(r) - sum(l);\n  }\n\nprivate:\n  int _n;\n  std::vector<T> data;\n  T sum(int\
    \ r) {\n    T ret(0);\n    while (r > 0) {\n      ret += data[r-1];\n      r -=\
    \ r & -r;\n    }\n\n    return ret;\n  }\n};\n\n\n#line 6 \"test/verify/yosupo-point-add-range-sum.test.cpp\"\
    \n\nint main() {\n  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);\n  int N,\
    \ Q; cin >> N >> Q;\n\n  fenwick_tree<ll> fw(N);\n  for (int i=0; i<N; i++) {\n\
    \    int a; cin >> a;\n    fw.add(i, a);\n  }\n\n  for (int q=0; q<Q; q++) {\n\
    \    ll op, a, b; cin >> op >> a >> b;\n    if (op == 0) {\n      fw.add(a,b);\n\
    \    }\n    else {\n      cout << fw.sum(a,b) << endl;\n    }\n  }\n  return 0;\n\
    }\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\
    #include \"template/template.hpp\"\n\n#include <vector>\n#include \"structure/fenwick_tree.hpp\"\
    \n\nint main() {\n  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);\n  int N,\
    \ Q; cin >> N >> Q;\n\n  fenwick_tree<ll> fw(N);\n  for (int i=0; i<N; i++) {\n\
    \    int a; cin >> a;\n    fw.add(i, a);\n  }\n\n  for (int q=0; q<Q; q++) {\n\
    \    ll op, a, b; cin >> op >> a >> b;\n    if (op == 0) {\n      fw.add(a,b);\n\
    \    }\n    else {\n      cout << fw.sum(a,b) << endl;\n    }\n  }\n  return 0;\n\
    }\n"
  dependsOn:
  - template/template.hpp
  - structure/fenwick_tree.hpp
  isVerificationFile: true
  path: test/verify/yosupo-point-add-range-sum.test.cpp
  requiredBy: []
  timestamp: '2025-03-23 14:07:18+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/verify/yosupo-point-add-range-sum.test.cpp
layout: document
redirect_from:
- /verify/test/verify/yosupo-point-add-range-sum.test.cpp
- /verify/test/verify/yosupo-point-add-range-sum.test.cpp.html
title: test/verify/yosupo-point-add-range-sum.test.cpp
---
