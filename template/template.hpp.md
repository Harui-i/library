---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: test/unittest/unittest-template.cpp
    title: test/unittest/unittest-template.cpp
  - icon: ':warning:'
    path: test/verify/atcoder-tdpc-s.cpp
    title: test/verify/atcoder-tdpc-s.cpp
  - icon: ':warning:'
    path: test/verify/fps/yosupo-kth-term-of-linearly-recurrent-sequence-test.cpp
    title: test/verify/fps/yosupo-kth-term-of-linearly-recurrent-sequence-test.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/unittest/unittest-divisor-moebius-transform.test.cpp
    title: test/unittest/unittest-divisor-moebius-transform.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/verify/aoj-0560.test.cpp
    title: test/verify/aoj-0560.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/verify/aoj-dpl3-c.test.cpp
    title: test/verify/aoj-dpl3-c.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/verify/convolution/yosupo-and-convolution.test.cpp
    title: test/verify/convolution/yosupo-and-convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/verify/convolution/yosupo-gcd-convolution.test.cpp
    title: test/verify/convolution/yosupo-gcd-convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/verify/convolution/yosupo-lcm-convolution.test.cpp
    title: test/verify/convolution/yosupo-lcm-convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/verify/fps/yosupo-division-of-polynomials.test.cpp
    title: test/verify/fps/yosupo-division-of-polynomials.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/verify/fps/yosupo-exp-of-formal-power-series.test.cpp
    title: test/verify/fps/yosupo-exp-of-formal-power-series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/verify/fps/yosupo-inv-of-formal-power-series-fast2.test.cpp
    title: test/verify/fps/yosupo-inv-of-formal-power-series-fast2.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/verify/fps/yosupo-inv-of-formal-power-series-sparse.test.cpp
    title: test/verify/fps/yosupo-inv-of-formal-power-series-sparse.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/verify/fps/yosupo-log-of-formal-power-series.test.cpp
    title: test/verify/fps/yosupo-log-of-formal-power-series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/verify/math/matrix/yosupo-inverse-of-matrix.test.cpp
    title: test/verify/math/matrix/yosupo-inverse-of-matrix.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/verify/math/matrix/yosupo-matrix-product.test.cpp
    title: test/verify/math/matrix/yosupo-matrix-product.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/verify/math/matrix/yosupo-pow-of-matrix.test.cpp
    title: test/verify/math/matrix/yosupo-pow-of-matrix.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/verify/math/matrix/yosupo-rank-of-matrix.test.cpp
    title: test/verify/math/matrix/yosupo-rank-of-matrix.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/verify/yosupo-deque-operate-all-composite.test.cpp
    title: test/verify/yosupo-deque-operate-all-composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/verify/yosupo-queue-operate-all-composite.test.cpp
    title: test/verify/yosupo-queue-operate-all-composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/verify/yosupo-shortest-path.test.cpp
    title: test/verify/yosupo-shortest-path.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/verify/yosupo-tree-diameter.test.cpp
    title: test/verify/yosupo-tree-diameter.test.cpp
  - icon: ':heavy_check_mark:'
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
  requiredBy:
  - test/verify/atcoder-tdpc-s.cpp
  - test/verify/fps/yosupo-kth-term-of-linearly-recurrent-sequence-test.cpp
  - test/unittest/unittest-template.cpp
  timestamp: '2024-05-14 18:24:32+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/verify/yosupo-deque-operate-all-composite.test.cpp
  - test/verify/yosupo-shortest-path.test.cpp
  - test/verify/fps/yosupo-division-of-polynomials.test.cpp
  - test/verify/fps/yosupo-exp-of-formal-power-series.test.cpp
  - test/verify/fps/yosupo-inv-of-formal-power-series-fast2.test.cpp
  - test/verify/fps/yosupo-inv-of-formal-power-series-sparse.test.cpp
  - test/verify/fps/yosupo-log-of-formal-power-series.test.cpp
  - test/verify/math/matrix/yosupo-matrix-product.test.cpp
  - test/verify/math/matrix/yosupo-inverse-of-matrix.test.cpp
  - test/verify/math/matrix/yosupo-pow-of-matrix.test.cpp
  - test/verify/math/matrix/yosupo-rank-of-matrix.test.cpp
  - test/verify/aoj-0560.test.cpp
  - test/verify/yuki-372-itsautomatic.test.cpp
  - test/verify/yosupo-queue-operate-all-composite.test.cpp
  - test/verify/convolution/yosupo-and-convolution.test.cpp
  - test/verify/convolution/yosupo-gcd-convolution.test.cpp
  - test/verify/convolution/yosupo-lcm-convolution.test.cpp
  - test/verify/yosupo-tree-diameter.test.cpp
  - test/verify/aoj-dpl3-c.test.cpp
  - test/unittest/unittest-divisor-moebius-transform.test.cpp
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
