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
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/4/ALDS1_4_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/4/ALDS1_4_B
  bundledCode: "#line 1 \"example.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/4/ALDS1_4_B\"\
    \n#line 1 \"template/template.hpp\"\n#include <iostream>\n#include <cassert>\n\
    using namespace std;\nusing ll = long long;\ntemplate<class T> inline bool chmax(T&\
    \ a, const T& b) {if (a<b) {a=b; return true;} return false;}\ntemplate<class\
    \ T> inline bool chmin(T& a, const T& b) {if (b<a) {a=b; return true;} return\
    \ false;}\nconst int INTINF = 1000001000;\nconst int INTMAX = 2147483647;\nconst\
    \ ll LLMAX = 9223372036854775807;\nconst ll LLINF = 1000000000000000000;\n#line\
    \ 3 \"example.test.cpp\"\n#include <vector>\n#include <algorithm>\n\nint main()\
    \ {\n  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);\n  int n; cin >> n;\n\
    \  vector<int> s(n);\n  for (int i = 0; i < n; i++) {\n    cin >> s[i];\n  }\n\
    \  int q; cin >> q;\n  int cnt = 0;\n  while (q--) {\n    int t_i; cin >> t_i;\n\
    \    cnt += binary_search(s.begin(), s.end(), t_i);\n  }\n  cout << cnt << endl;\n\
    \  return 0;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/4/ALDS1_4_B\"\
    \n#include \"template/template.hpp\"\n#include <vector>\n#include <algorithm>\n\
    \nint main() {\n  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);\n  int n;\
    \ cin >> n;\n  vector<int> s(n);\n  for (int i = 0; i < n; i++) {\n    cin >>\
    \ s[i];\n  }\n  int q; cin >> q;\n  int cnt = 0;\n  while (q--) {\n    int t_i;\
    \ cin >> t_i;\n    cnt += binary_search(s.begin(), s.end(), t_i);\n  }\n  cout\
    \ << cnt << endl;\n  return 0;\n}\n"
  dependsOn:
  - template/template.hpp
  isVerificationFile: true
  path: example.test.cpp
  requiredBy: []
  timestamp: '2025-03-23 00:41:45+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: example.test.cpp
layout: document
redirect_from:
- /verify/example.test.cpp
- /verify/example.test.cpp.html
title: example.test.cpp
---
