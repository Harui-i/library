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
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A
  bundledCode: "#line 1 \"unabstracted_libs/segment-tree/aoj-dsl-2-a(RMQ).test.cpp\"\
    \n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A\"\
    \n\n#line 1 \"template/template.hpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\ntypedef long long ll;\ntypedef unsigned int uint;\ntemplate<class T> inline\
    \ bool chmax(T& a, const T& b) {if (a<b) {a=b; return true;} return false;}\n\
    template<class T> inline bool chmin(T& a, const T& b) {if (b<a) {a=b; return true;}\
    \ return false;}\nconst int INTINF = 1000001000;\nconst int INTMAX = 2147483647;\n\
    const ll LLMAX = 9223372036854775807;\nconst ll LLINF = 1000000000000000000;\n\
    #line 4 \"unabstracted_libs/segment-tree/aoj-dsl-2-a(RMQ).test.cpp\"\n\nvector<int>\
    \ dat;\nint sz;\n\n// k\u756A\u76EE(0-indexed)\u306E\u5024\u3092a\u306B\u5909\u66F4\
    \nvoid update (int k, int a) {\n k += sz; \n dat[k] = a;\n while (k > 0) {\n \
    \  k /= 2;\n   dat[k] = min(dat[k*2], dat[k*2+1]);\n }\n}\n\n// [l, r)\u306E\u6700\
    \u5C0F\u5024\u3092\u6C42\u3081\u308B(l, r\u306F0-indexed)\nint query (int l, int\
    \ r) {\n  l += sz; r += sz;\n  int L = INTMAX, R = INTMAX;\n  while (l < r) {\n\
    \    if (l%2 == 1) {\n       L = min(L, dat[l]);\n       l++;\n    }\n\n    if\
    \ (r%2 == 1) {\n      r--;\n      R = min(dat[r], R);\n    }\n\n    l /= 2; r\
    \ /= 2;\n  }\n  return min(L, R);\n}\n\n\nint main() {\n  ios::sync_with_stdio(0);\
    \ cin.tie(0); cout.tie(0);\n  int n, q; cin >> n >> q;\n\n  sz = 1; while (sz\
    \ < n) sz *= 2;\n\n  dat.resize(sz * 2, INTMAX);  \n\n  while (q--) {\n    int\
    \ com, x, y; cin >> com >> x >> y;\n    if (com == 0) {\n      update(x, y);\n\
    \    } else {\n      cout << query(x, y+1) << endl;\n    }\n  } \n  return 0;\n\
    }\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A\"\
    \n\n#include \"../../template/template.hpp\"\n\nvector<int> dat;\nint sz;\n\n\
    // k\u756A\u76EE(0-indexed)\u306E\u5024\u3092a\u306B\u5909\u66F4\nvoid update\
    \ (int k, int a) {\n k += sz; \n dat[k] = a;\n while (k > 0) {\n   k /= 2;\n \
    \  dat[k] = min(dat[k*2], dat[k*2+1]);\n }\n}\n\n// [l, r)\u306E\u6700\u5C0F\u5024\
    \u3092\u6C42\u3081\u308B(l, r\u306F0-indexed)\nint query (int l, int r) {\n  l\
    \ += sz; r += sz;\n  int L = INTMAX, R = INTMAX;\n  while (l < r) {\n    if (l%2\
    \ == 1) {\n       L = min(L, dat[l]);\n       l++;\n    }\n\n    if (r%2 == 1)\
    \ {\n      r--;\n      R = min(dat[r], R);\n    }\n\n    l /= 2; r /= 2;\n  }\n\
    \  return min(L, R);\n}\n\n\nint main() {\n  ios::sync_with_stdio(0); cin.tie(0);\
    \ cout.tie(0);\n  int n, q; cin >> n >> q;\n\n  sz = 1; while (sz < n) sz *= 2;\n\
    \n  dat.resize(sz * 2, INTMAX);  \n\n  while (q--) {\n    int com, x, y; cin >>\
    \ com >> x >> y;\n    if (com == 0) {\n      update(x, y);\n    } else {\n   \
    \   cout << query(x, y+1) << endl;\n    }\n  } \n  return 0;\n}"
  dependsOn:
  - template/template.hpp
  isVerificationFile: true
  path: unabstracted_libs/segment-tree/aoj-dsl-2-a(RMQ).test.cpp
  requiredBy: []
  timestamp: '2024-05-15 22:41:41+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: unabstracted_libs/segment-tree/aoj-dsl-2-a(RMQ).test.cpp
layout: document
redirect_from:
- /verify/unabstracted_libs/segment-tree/aoj-dsl-2-a(RMQ).test.cpp
- /verify/unabstracted_libs/segment-tree/aoj-dsl-2-a(RMQ).test.cpp.html
title: unabstracted_libs/segment-tree/aoj-dsl-2-a(RMQ).test.cpp
---
