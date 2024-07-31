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
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_D
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_D
  bundledCode: "#line 1 \"unabstracted_libs/segment-tree/aoj-dsl-2-d(RUQ).test.cpp\"\
    \n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_D\"\
    \n\n#line 1 \"template/template.hpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\nusing ll = long long;\ntemplate<class T> inline bool chmax(T& a, const\
    \ T& b) {if (a<b) {a=b; return true;} return false;}\ntemplate<class T> inline\
    \ bool chmin(T& a, const T& b) {if (b<a) {a=b; return true;} return false;}\n\
    const int INTINF = 1000001000;\nconst int INTMAX = 2147483647;\nconst ll LLMAX\
    \ = 9223372036854775807;\nconst ll LLINF = 1000000000000000000;\n#line 4 \"unabstracted_libs/segment-tree/aoj-dsl-2-d(RUQ).test.cpp\"\
    \n\nvector<pair<int,int>>dat;\nint sz;\n\n// k\u756A\u76EE(0-indexed)\u306E\u5024\
    \u3092\u53D6\u5F97\nint get(int k) {\n  k += sz;\n  int ret = INTMAX;\n  int current_time\
    \ = 0;\n  while (k > 0) {\n    if (dat[k].second > current_time) {\n      ret\
    \ = dat[k].first;\n      current_time = dat[k].second;\n    }\n    k /= 2;\n \
    \ }\n  return ret;\n}\n\n// [l, r)\u3092x\u306B\u5909\u66F4\u3059\u308B(l, r\u306F\
    0-indexed)\nvoid update(int l, int r, int x, int time) {\n  l += sz; r += sz;\n\
    \  while (l < r) {\n    if (l % 2 == 1) {\n      dat[l] = make_pair(x, time);\n\
    \      l++;\n    }\n\n    if (r % 2 == 1) {\n      r--;\n      dat[r] = make_pair(x,\
    \ time);\n    }\n\n    l /= 2; r /= 2;\n  }\n  assert(l == r); \n\n}\n\n\nint\
    \ main() {\n  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);\n  int n, q; cin\
    \ >> n >> q;\n\n  sz = 1; while (sz < n) sz *= 2;\n\n  dat.resize(sz * 2, make_pair(INTMAX,\
    \ 0));\n\n  int time = 1;\n\n  while (q--) {\n    int com; cin >> com;\n    if\
    \ (com == 0) {\n      int s, t, x; cin >> s >> t >> x;\n      update(s, t+1, x,\
    \ ++time);\n    }\n    else {\n      int t; cin >> t;\n      cout << get(t) <<\
    \ endl;\n    }\n  }\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_D\"\
    \n\n#include \"../../template/template.hpp\"\n\nvector<pair<int,int>>dat;\nint\
    \ sz;\n\n// k\u756A\u76EE(0-indexed)\u306E\u5024\u3092\u53D6\u5F97\nint get(int\
    \ k) {\n  k += sz;\n  int ret = INTMAX;\n  int current_time = 0;\n  while (k >\
    \ 0) {\n    if (dat[k].second > current_time) {\n      ret = dat[k].first;\n \
    \     current_time = dat[k].second;\n    }\n    k /= 2;\n  }\n  return ret;\n\
    }\n\n// [l, r)\u3092x\u306B\u5909\u66F4\u3059\u308B(l, r\u306F0-indexed)\nvoid\
    \ update(int l, int r, int x, int time) {\n  l += sz; r += sz;\n  while (l < r)\
    \ {\n    if (l % 2 == 1) {\n      dat[l] = make_pair(x, time);\n      l++;\n \
    \   }\n\n    if (r % 2 == 1) {\n      r--;\n      dat[r] = make_pair(x, time);\n\
    \    }\n\n    l /= 2; r /= 2;\n  }\n  assert(l == r); \n\n}\n\n\nint main() {\n\
    \  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);\n  int n, q; cin >> n >>\
    \ q;\n\n  sz = 1; while (sz < n) sz *= 2;\n\n  dat.resize(sz * 2, make_pair(INTMAX,\
    \ 0));\n\n  int time = 1;\n\n  while (q--) {\n    int com; cin >> com;\n    if\
    \ (com == 0) {\n      int s, t, x; cin >> s >> t >> x;\n      update(s, t+1, x,\
    \ ++time);\n    }\n    else {\n      int t; cin >> t;\n      cout << get(t) <<\
    \ endl;\n    }\n  }\n  return 0;\n}"
  dependsOn:
  - template/template.hpp
  isVerificationFile: true
  path: unabstracted_libs/segment-tree/aoj-dsl-2-d(RUQ).test.cpp
  requiredBy: []
  timestamp: '2024-06-29 08:51:47+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: unabstracted_libs/segment-tree/aoj-dsl-2-d(RUQ).test.cpp
layout: document
redirect_from:
- /verify/unabstracted_libs/segment-tree/aoj-dsl-2-d(RUQ).test.cpp
- /verify/unabstracted_libs/segment-tree/aoj-dsl-2-d(RUQ).test.cpp.html
title: unabstracted_libs/segment-tree/aoj-dsl-2-d(RUQ).test.cpp
---
