---
data:
  _extendedDependsOn:
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
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_E
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_E
  bundledCode: "#line 1 \"unabstracted_libs/segment-tree/aoj-dsl-2-e(RAQ).test.cpp\"\
    \n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_E\"\
    \n\n#line 1 \"template/template.hpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\nusing ll = long long;\ntemplate<class T> inline bool chmax(T& a, const\
    \ T& b) {if (a<b) {a=b; return true;} return false;}\ntemplate<class T> inline\
    \ bool chmin(T& a, const T& b) {if (b<a) {a=b; return true;} return false;}\n\
    const int INTINF = 1000001000;\nconst int INTMAX = 2147483647;\nconst ll LLMAX\
    \ = 9223372036854775807;\nconst ll LLINF = 1000000000000000000;\n#line 4 \"unabstracted_libs/segment-tree/aoj-dsl-2-e(RAQ).test.cpp\"\
    \n\nvector<int> dat;\nint sz;\n\n// k\u756A\u76EE(0-indexed)\u306E\u5024\u3092\
    \u53D6\u5F97\nint get(int k) {\n  k += sz;\n  int ret = 0;\n  while (k > 0) {\n\
    \    ret += dat[k];\n    k /= 2;\n  }\n  return ret;\n}\n\n// [l, r)\u306Bx\u3092\
    \u52A0\u7B97\u3059\u308B(l, r\u306F0-indexed)\nvoid add(int l, int r, int x) {\n\
    \  l += sz; r += sz;\n  while (l < r) {\n    if (l % 2 == 1) {\n      dat[l] +=\
    \ x;\n      l++;\n    }\n\n    if (r % 2 == 1) {\n      r--;\n      dat[r] +=\
    \ x;\n    }\n\n    l /= 2; r /= 2;\n  }\n}\n\n\nint main() {\n  ios::sync_with_stdio(0);\
    \ cin.tie(0); cout.tie(0);\n  int n, q; cin >> n >> q;\n\n  sz = 1; while (sz\
    \ < n) sz *= 2;\n\n  dat.resize(sz * 2, 0);\n\n  while (q--) {\n    int com; cin\
    \ >> com;\n    if (com == 0) {\n      int s, t, x; cin >> s >> t >> x;\n     \
    \ add(s-1, t, x);\n    }\n    else {\n      int t; cin >> t;\n      cout << get(t-1)\
    \ << endl;\n    }\n  }\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_E\"\
    \n\n#include \"../../template/template.hpp\"\n\nvector<int> dat;\nint sz;\n\n\
    // k\u756A\u76EE(0-indexed)\u306E\u5024\u3092\u53D6\u5F97\nint get(int k) {\n\
    \  k += sz;\n  int ret = 0;\n  while (k > 0) {\n    ret += dat[k];\n    k /= 2;\n\
    \  }\n  return ret;\n}\n\n// [l, r)\u306Bx\u3092\u52A0\u7B97\u3059\u308B(l, r\u306F\
    0-indexed)\nvoid add(int l, int r, int x) {\n  l += sz; r += sz;\n  while (l <\
    \ r) {\n    if (l % 2 == 1) {\n      dat[l] += x;\n      l++;\n    }\n\n    if\
    \ (r % 2 == 1) {\n      r--;\n      dat[r] += x;\n    }\n\n    l /= 2; r /= 2;\n\
    \  }\n}\n\n\nint main() {\n  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);\n\
    \  int n, q; cin >> n >> q;\n\n  sz = 1; while (sz < n) sz *= 2;\n\n  dat.resize(sz\
    \ * 2, 0);\n\n  while (q--) {\n    int com; cin >> com;\n    if (com == 0) {\n\
    \      int s, t, x; cin >> s >> t >> x;\n      add(s-1, t, x);\n    }\n    else\
    \ {\n      int t; cin >> t;\n      cout << get(t-1) << endl;\n    }\n  }\n  return\
    \ 0;\n}"
  dependsOn:
  - template/template.hpp
  isVerificationFile: true
  path: unabstracted_libs/segment-tree/aoj-dsl-2-e(RAQ).test.cpp
  requiredBy: []
  timestamp: '2024-06-29 08:51:47+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: unabstracted_libs/segment-tree/aoj-dsl-2-e(RAQ).test.cpp
layout: document
redirect_from:
- /verify/unabstracted_libs/segment-tree/aoj-dsl-2-e(RAQ).test.cpp
- /verify/unabstracted_libs/segment-tree/aoj-dsl-2-e(RAQ).test.cpp.html
title: unabstracted_libs/segment-tree/aoj-dsl-2-e(RAQ).test.cpp
---
