---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: test/verify/atcoder-tdpc-s.cpp
    title: test/verify/atcoder-tdpc-s.cpp
  - icon: ':warning:'
    path: test/verify/yosupo-inv-of-formal-power-series-fast1-test.cpp
    title: test/verify/yosupo-inv-of-formal-power-series-fast1-test.cpp
  - icon: ':warning:'
    path: test/verify/yosupo-inv-of-formal-power-series-naive-test.cpp
    title: test/verify/yosupo-inv-of-formal-power-series-naive-test.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/verify/aoj-0560.test.cpp
    title: test/verify/aoj-0560.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/verify/aoj-dpl3-c.test.cpp
    title: test/verify/aoj-dpl3-c.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/verify/yosupo-deque-operate-all-composite.test.cpp
    title: test/verify/yosupo-deque-operate-all-composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/verify/yosupo-exp-of-formal-power-series.test.cpp
    title: test/verify/yosupo-exp-of-formal-power-series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/verify/yosupo-inv-of-formal-power-series-fast2.test.cpp
    title: test/verify/yosupo-inv-of-formal-power-series-fast2.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/verify/yosupo-inv-of-formal-power-series-sparse.test.cpp
    title: test/verify/yosupo-inv-of-formal-power-series-sparse.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/verify/yosupo-log-of-formal-power-series.test.cpp
    title: test/verify/yosupo-log-of-formal-power-series.test.cpp
  - icon: ':x:'
    path: test/verify/yosupo-matrix-product.test.cpp
    title: test/verify/yosupo-matrix-product.test.cpp
  - icon: ':x:'
    path: test/verify/yosupo-pow-of-matrix.test.cpp
    title: test/verify/yosupo-pow-of-matrix.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/verify/yosupo-queue-operate-all-composite.test.cpp
    title: test/verify/yosupo-queue-operate-all-composite.test.cpp
  - icon: ':x:'
    path: test/verify/yuki-372-itsautomatic.test.cpp
    title: test/verify/yuki-372-itsautomatic.test.cpp
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
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
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
  requiredBy:
  - test/verify/atcoder-tdpc-s.cpp
  - test/verify/yosupo-inv-of-formal-power-series-naive-test.cpp
  - test/verify/yosupo-inv-of-formal-power-series-fast1-test.cpp
  timestamp: '2024-05-14 18:24:32+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/verify/yosupo-deque-operate-all-composite.test.cpp
  - test/verify/yosupo-exp-of-formal-power-series.test.cpp
  - test/verify/yosupo-matrix-product.test.cpp
  - test/verify/yosupo-inv-of-formal-power-series-fast2.test.cpp
  - test/verify/aoj-0560.test.cpp
  - test/verify/yuki-372-itsautomatic.test.cpp
  - test/verify/yosupo-queue-operate-all-composite.test.cpp
  - test/verify/yosupo-inv-of-formal-power-series-sparse.test.cpp
  - test/verify/yosupo-pow-of-matrix.test.cpp
  - test/verify/yosupo-log-of-formal-power-series.test.cpp
  - test/verify/aoj-dpl3-c.test.cpp
  - unabstracted_libs/segment-tree/aoj-dsl-2-d(RUQ).test.cpp
  - unabstracted_libs/segment-tree/aoj-dsl-2-a(RMQ).test.cpp
  - unabstracted_libs/segment-tree/aoj-dsl-2-e(RAQ).test.cpp
  - unabstracted_libs/segment-tree/aoj-dsl-2-b(RSQ).test.cpp
documentation_of: template/template.hpp
layout: document
redirect_from:
- /library/template/template.hpp
- /library/template/template.hpp.html
title: template/template.hpp
---
