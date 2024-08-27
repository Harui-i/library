---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: formal-power-series/fiduccia.hpp
    title: formal-power-series/fiduccia.hpp
  - icon: ':heavy_check_mark:'
    path: formal-power-series/formal-power-series.hpp
    title: "Formal Power Series (\u5F62\u5F0F\u7684\u3079\u304D\u7D1A\u6570)"
  - icon: ':heavy_check_mark:'
    path: formal-power-series/fps998.hpp
    title: formal-power-series/fps998.hpp
  - icon: ':warning:'
    path: formal-power-series/naive-fps.hpp
    title: formal-power-series/naive-fps.hpp
  - icon: ':heavy_check_mark:'
    path: formal-power-series/sparse-fps.hpp
    title: sparse-fps
  - icon: ':question:'
    path: math/modint.hpp
    title: modint
  - icon: ':warning:'
    path: test/verify/fps/yosupo-inv-of-formal-power-series-naive-test.cpp
    title: test/verify/fps/yosupo-inv-of-formal-power-series-naive-test.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/unittest/unittest-multiple-divisor-moebius-transform.test.cpp
    title: test/unittest/unittest-multiple-divisor-moebius-transform.test.cpp
  - icon: ':x:'
    path: test/verify/atcoder-tdpc-s.test.cpp
    title: test/verify/atcoder-tdpc-s.test.cpp
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
    path: test/verify/convolution/yosupo-normal-convolution.test.cpp
    title: test/verify/convolution/yosupo-normal-convolution.test.cpp
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
    path: test/verify/fps/yosupo-kth-term-of-linearly-recurrent-sequence.test.cpp
    title: test/verify/fps/yosupo-kth-term-of-linearly-recurrent-sequence.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/verify/fps/yosupo-log-of-formal-power-series.test.cpp
    title: test/verify/fps/yosupo-log-of-formal-power-series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/verify/fps/yosupo-pow-of-formal-power-series.test.cpp
    title: test/verify/fps/yosupo-pow-of-formal-power-series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/verify/math/matrix/yosupo-inverse-of-matrix.test.cpp
    title: test/verify/math/matrix/yosupo-inverse-of-matrix.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/verify/math/matrix/yosupo-linear-equation.test.cpp
    title: test/verify/math/matrix/yosupo-linear-equation.test.cpp
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
    path: test/verify/yosupo-vertex-set-path-composite.test.cpp
    title: test/verify/yosupo-vertex-set-path-composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/verify/yuki-372-itsautomatic.test.cpp
    title: test/verify/yuki-372-itsautomatic.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/external_gcd.hpp\"\n\n\n\n#include <tuple>\n\n// g,x,y\n\
    template<typename T>\nconstexpr std::tuple<T, T, T> extendedGCD(T a, T b) {\n\
    \    T x0 = 1, y0 = 0, x1 = 0, y1 = 1;\n    while (b != 0) {\n        T q = a\
    \ / b;\n        T r = a % b;\n        a = b;\n        b = r;\n        \n     \
    \   T xTemp = x0 - q * x1;\n        x0 = x1;\n        x1 = xTemp;\n        \n\
    \        T yTemp = y0 - q * y1;\n        y0 = y1;\n        y1 = yTemp;\n    }\n\
    \    return {a, x0, y0};\n}\n\n"
  code: "#ifndef HARUILIB_MATH_EXTERNAL_GCD_HPP\n#define HARUILIB_MATH_EXTERNAL_GCD_HPP\n\
    \n#include <tuple>\n\n// g,x,y\ntemplate<typename T>\nconstexpr std::tuple<T,\
    \ T, T> extendedGCD(T a, T b) {\n    T x0 = 1, y0 = 0, x1 = 0, y1 = 1;\n    while\
    \ (b != 0) {\n        T q = a / b;\n        T r = a % b;\n        a = b;\n   \
    \     b = r;\n        \n        T xTemp = x0 - q * x1;\n        x0 = x1;\n   \
    \     x1 = xTemp;\n        \n        T yTemp = y0 - q * y1;\n        y0 = y1;\n\
    \        y1 = yTemp;\n    }\n    return {a, x0, y0};\n}\n#endif // HARUILIB_MATH_EXTERNAL_GCD_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: math/external_gcd.hpp
  requiredBy:
  - formal-power-series/sparse-fps.hpp
  - formal-power-series/fps998.hpp
  - formal-power-series/formal-power-series.hpp
  - formal-power-series/fiduccia.hpp
  - formal-power-series/naive-fps.hpp
  - test/verify/fps/yosupo-inv-of-formal-power-series-naive-test.cpp
  - math/modint.hpp
  timestamp: '2024-06-20 15:39:33+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/verify/convolution/yosupo-normal-convolution.test.cpp
  - test/verify/convolution/yosupo-gcd-convolution.test.cpp
  - test/verify/convolution/yosupo-and-convolution.test.cpp
  - test/verify/convolution/yosupo-lcm-convolution.test.cpp
  - test/verify/yuki-372-itsautomatic.test.cpp
  - test/verify/math/matrix/yosupo-inverse-of-matrix.test.cpp
  - test/verify/math/matrix/yosupo-matrix-product.test.cpp
  - test/verify/math/matrix/yosupo-pow-of-matrix.test.cpp
  - test/verify/math/matrix/yosupo-rank-of-matrix.test.cpp
  - test/verify/math/matrix/yosupo-linear-equation.test.cpp
  - test/verify/yosupo-deque-operate-all-composite.test.cpp
  - test/verify/yosupo-queue-operate-all-composite.test.cpp
  - test/verify/atcoder-tdpc-s.test.cpp
  - test/verify/yosupo-vertex-set-path-composite.test.cpp
  - test/verify/fps/yosupo-log-of-formal-power-series.test.cpp
  - test/verify/fps/yosupo-inv-of-formal-power-series-sparse.test.cpp
  - test/verify/fps/yosupo-exp-of-formal-power-series.test.cpp
  - test/verify/fps/yosupo-inv-of-formal-power-series-fast2.test.cpp
  - test/verify/fps/yosupo-kth-term-of-linearly-recurrent-sequence.test.cpp
  - test/verify/fps/yosupo-division-of-polynomials.test.cpp
  - test/verify/fps/yosupo-pow-of-formal-power-series.test.cpp
  - test/unittest/unittest-multiple-divisor-moebius-transform.test.cpp
documentation_of: math/external_gcd.hpp
layout: document
redirect_from:
- /library/math/external_gcd.hpp
- /library/math/external_gcd.hpp.html
title: math/external_gcd.hpp
---