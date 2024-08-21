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
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://judge.yosupo.jp/problem/aplusb
  bundledCode: "#line 1 \"test/unittest/unittest-template.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/aplusb\"\n\n#line 1 \"template/template.hpp\"\n\
    #include <iostream>\n#include <cassert>\nusing namespace std;\nusing ll = long\
    \ long;\ntemplate<class T> inline bool chmax(T& a, const T& b) {if (a<b) {a=b;\
    \ return true;} return false;}\ntemplate<class T> inline bool chmin(T& a, const\
    \ T& b) {if (b<a) {a=b; return true;} return false;}\nconst int INTINF = 1000001000;\n\
    const int INTMAX = 2147483647;\nconst ll LLMAX = 9223372036854775807;\nconst ll\
    \ LLINF = 1000000000000000000;\n#line 4 \"test/unittest/unittest-template.cpp\"\
    \n\nvoid test() {\n  random_device seed_gen;\n  mt19937 rng(seed_gen()); \n\n\
    \  while (rng() % 2 == 1) {\n    continue;\n  }\n\n  return;\n}\n\nint main()\
    \ {\n  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);\n  test();\n  int A,\
    \ B; cin >> A >> B;\n  cout << A+B << endl;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n\n#include \"\
    template/template.hpp\"\n\nvoid test() {\n  random_device seed_gen;\n  mt19937\
    \ rng(seed_gen()); \n\n  while (rng() % 2 == 1) {\n    continue;\n  }\n\n  return;\n\
    }\n\nint main() {\n  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);\n  test();\n\
    \  int A, B; cin >> A >> B;\n  cout << A+B << endl;\n}"
  dependsOn:
  - template/template.hpp
  isVerificationFile: false
  path: test/unittest/unittest-template.cpp
  requiredBy: []
  timestamp: '2024-08-21 21:41:37+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: test/unittest/unittest-template.cpp
layout: document
redirect_from:
- /library/test/unittest/unittest-template.cpp
- /library/test/unittest/unittest-template.cpp.html
title: test/unittest/unittest-template.cpp
---
