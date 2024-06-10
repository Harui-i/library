---
data:
  _extendedDependsOn:
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
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B
  bundledCode: "#line 1 \"unabstracted_libs/segment-tree/aoj-dsl-2-b(RSQ).test.cpp\"\
    \n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B\"\
    \n\n#line 1 \"template/template.hpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\ntypedef long long ll;\ntypedef unsigned int uint;\ntemplate<class T> inline\
    \ bool chmax(T& a, const T& b) {if (a<b) {a=b; return true;} return false;}\n\
    template<class T> inline bool chmin(T& a, const T& b) {if (b<a) {a=b; return true;}\
    \ return false;}\nconst int INTINF = 1000001000;\nconst int INTMAX = 2147483647;\n\
    const ll LLMAX = 9223372036854775807;\nconst ll LLINF = 1000000000000000000;\n\
    #line 4 \"unabstracted_libs/segment-tree/aoj-dsl-2-b(RSQ).test.cpp\"\n\nvector<ll>\
    \ dat;\nint sz;\n\n// k\u756A\u76EE(0-indexed)\u306E\u5024\u306Ba\u3092\u52A0\u7B97\
    \nvoid update(int k, int a) {\n  k += sz;\n  dat[k] += a;\n  while (k > 0) {\n\
    \    k /= 2;\n    dat[k] = dat[k * 2] + dat[k * 2 + 1];\n  }\n}\n\n// [l, r)\u306E\
    \u548C\u3092\u6C42\u3081\u308B(l, r\u306F0-indexed)\nll query(int l, int r) {\n\
    \n  l += sz; r += sz;\n  assert(0<=l && 0<= r && l <= r);\n  int L = 0, R = 0;\n\
    \  while (l < r) {\n    if (l % 2 == 1) {\n      L = L + dat[l];\n      l++;\n\
    \    }\n\n    if (r % 2 == 1) {\n      r--;\n      R = dat[r] + R;\n    }\n\n\
    \    l /= 2; r /= 2;\n  }\n  return L + R;\n}\n\n\nint main() {\n  ios::sync_with_stdio(0);\
    \ cin.tie(0); cout.tie(0);\n  int n, q; cin >> n >> q;\n\n  sz = 1; while (sz\
    \ < n) sz *= 2;\n\n  dat.resize(sz * 2, 0);\n\n  while (q--) {\n    int com, x,\
    \ y; cin >> com >> x >> y;\n    x--;\n    if (com == 0) {\n      update(x, y);\n\
    \    }\n    else {\n      cout << query(x, y) << endl;\n    }\n  }\n  return 0;\n\
    }\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B\"\
    \n\n#include \"../../template/template.hpp\"\n\nvector<ll> dat;\nint sz;\n\n//\
    \ k\u756A\u76EE(0-indexed)\u306E\u5024\u306Ba\u3092\u52A0\u7B97\nvoid update(int\
    \ k, int a) {\n  k += sz;\n  dat[k] += a;\n  while (k > 0) {\n    k /= 2;\n  \
    \  dat[k] = dat[k * 2] + dat[k * 2 + 1];\n  }\n}\n\n// [l, r)\u306E\u548C\u3092\
    \u6C42\u3081\u308B(l, r\u306F0-indexed)\nll query(int l, int r) {\n\n  l += sz;\
    \ r += sz;\n  assert(0<=l && 0<= r && l <= r);\n  int L = 0, R = 0;\n  while (l\
    \ < r) {\n    if (l % 2 == 1) {\n      L = L + dat[l];\n      l++;\n    }\n\n\
    \    if (r % 2 == 1) {\n      r--;\n      R = dat[r] + R;\n    }\n\n    l /= 2;\
    \ r /= 2;\n  }\n  return L + R;\n}\n\n\nint main() {\n  ios::sync_with_stdio(0);\
    \ cin.tie(0); cout.tie(0);\n  int n, q; cin >> n >> q;\n\n  sz = 1; while (sz\
    \ < n) sz *= 2;\n\n  dat.resize(sz * 2, 0);\n\n  while (q--) {\n    int com, x,\
    \ y; cin >> com >> x >> y;\n    x--;\n    if (com == 0) {\n      update(x, y);\n\
    \    }\n    else {\n      cout << query(x, y) << endl;\n    }\n  }\n  return 0;\n\
    }"
  dependsOn:
  - template/template.hpp
  isVerificationFile: true
  path: unabstracted_libs/segment-tree/aoj-dsl-2-b(RSQ).test.cpp
  requiredBy: []
  timestamp: '2024-05-15 22:41:41+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: unabstracted_libs/segment-tree/aoj-dsl-2-b(RSQ).test.cpp
layout: document
redirect_from:
- /verify/unabstracted_libs/segment-tree/aoj-dsl-2-b(RSQ).test.cpp
- /verify/unabstracted_libs/segment-tree/aoj-dsl-2-b(RSQ).test.cpp.html
title: unabstracted_libs/segment-tree/aoj-dsl-2-b(RSQ).test.cpp
---
