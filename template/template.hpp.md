---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/verify/aoj-0560.test.cpp
    title: test/verify/aoj-0560.test.cpp
  - icon: ':heavy_check_mark:'
    path: unabstracted_libs/segment-tree/aoj-dsl-2-a(RMQ).test.cpp
    title: unabstracted_libs/segment-tree/aoj-dsl-2-a(RMQ).test.cpp
  - icon: ':heavy_check_mark:'
    path: unabstracted_libs/segment-tree/aoj-dsl-2-b(RSQ).test.cpp
    title: unabstracted_libs/segment-tree/aoj-dsl-2-b(RSQ).test.cpp
  - icon: ':heavy_check_mark:'
    path: unabstracted_libs/segment-tree/aoj-dsl-2-d(RUQ).test.cpp
    title: unabstracted_libs/segment-tree/aoj-dsl-2-d(RUQ).test.cpp
  - icon: ':heavy_check_mark:'
    path: unabstracted_libs/segment-tree/aoj-dsl-2-e(RAQ).test.cpp
    title: unabstracted_libs/segment-tree/aoj-dsl-2-e(RAQ).test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: '#line 1 "template/template.hpp"

    #include <bits/stdc++.h>

    using namespace std;

    typedef long long ll;

    typedef unsigned int uint;

    template<class T> inline bool chmax(T& a, const T& b) {if (a<b) {a=b; return true;}
    return false;}

    template<class T> inline bool chmin(T& a, const T& b) {if (b<a) {a=b; return true;}
    return false;}

    const int INTINF = 1000001000;

    const int INTMAX = 2147483647;

    const ll LLMAX = 9223372036854775807;

    const ll LLINF = 1000000000000000000;

    '
  code: '#include <bits/stdc++.h>

    using namespace std;

    typedef long long ll;

    typedef unsigned int uint;

    template<class T> inline bool chmax(T& a, const T& b) {if (a<b) {a=b; return true;}
    return false;}

    template<class T> inline bool chmin(T& a, const T& b) {if (b<a) {a=b; return true;}
    return false;}

    const int INTINF = 1000001000;

    const int INTMAX = 2147483647;

    const ll LLMAX = 9223372036854775807;

    const ll LLINF = 1000000000000000000;

    '
  dependsOn: []
  isVerificationFile: false
  path: template/template.hpp
  requiredBy: []
  timestamp: '2024-05-14 18:24:32+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - unabstracted_libs/segment-tree/aoj-dsl-2-b(RSQ).test.cpp
  - unabstracted_libs/segment-tree/aoj-dsl-2-a(RMQ).test.cpp
  - unabstracted_libs/segment-tree/aoj-dsl-2-e(RAQ).test.cpp
  - unabstracted_libs/segment-tree/aoj-dsl-2-d(RUQ).test.cpp
  - test/verify/aoj-0560.test.cpp
documentation_of: template/template.hpp
layout: document
redirect_from:
- /library/template/template.hpp
- /library/template/template.hpp.html
title: template/template.hpp
---