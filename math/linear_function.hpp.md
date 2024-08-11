---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/verify/yosupo-deque-operate-all-composite.test.cpp
    title: test/verify/yosupo-deque-operate-all-composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/verify/yosupo-queue-operate-all-composite.test.cpp
    title: test/verify/yosupo-queue-operate-all-composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/verify/yosupo-vertex-set-path-composite.test.cpp
    title: test/verify/yosupo-vertex-set-path-composite.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/linear_function.hpp\"\n\n\n\ntemplate <typename T>\n\
    struct LinearFunction {\n  T a, b;\n\n  LinearFunction() : a{0}, b(0) {}\n  LinearFunction(T\
    \ _a, T _b) : a(_a), b(_b) {}\n\n  static LinearFunction Add_Identity() {\n  \
    \  return LinearFunction(T(0), T(0));\n  }\n\n  static LinearFunction Mul_Identity(){\n\
    \    return LinearFunction(T(1), T(0));\n  }\n\n  // f(g())\n  LinearFunction\
    \ composite(LinearFunction& g) const {\n    return LinearFunction(a * g.a, a *\
    \ g.b + b);\n  }\n\n  LinearFunction operator+(const LinearFunction& rhs) const\
    \ {\n    return LinearFunction(a + rhs.a, b + rhs.b);\n  }\n\n  // rhs(f())\n\
    \  LinearFunction operator*(const LinearFunction& rhs) const {\n    LinearFunction\
    \ f = *this;\n    return rhs.composite(f);\n  }\n\n  T operator()(T x) const {\n\
    \    return a * x + b;\n  }\n\n};\n\n\n\n"
  code: "#ifndef HARUILIB_LINEAR_FUNCTION_HPP\n#define HARUILIB_LINEAR_FUNCTION_HPP\n\
    \ntemplate <typename T>\nstruct LinearFunction {\n  T a, b;\n\n  LinearFunction()\
    \ : a{0}, b(0) {}\n  LinearFunction(T _a, T _b) : a(_a), b(_b) {}\n\n  static\
    \ LinearFunction Add_Identity() {\n    return LinearFunction(T(0), T(0));\n  }\n\
    \n  static LinearFunction Mul_Identity(){\n    return LinearFunction(T(1), T(0));\n\
    \  }\n\n  // f(g())\n  LinearFunction composite(LinearFunction& g) const {\n \
    \   return LinearFunction(a * g.a, a * g.b + b);\n  }\n\n  LinearFunction operator+(const\
    \ LinearFunction& rhs) const {\n    return LinearFunction(a + rhs.a, b + rhs.b);\n\
    \  }\n\n  // rhs(f())\n  LinearFunction operator*(const LinearFunction& rhs) const\
    \ {\n    LinearFunction f = *this;\n    return rhs.composite(f);\n  }\n\n  T operator()(T\
    \ x) const {\n    return a * x + b;\n  }\n\n};\n\n\n#endif // HARUILIB_LINEAR_FUNCTION_HPP"
  dependsOn: []
  isVerificationFile: false
  path: math/linear_function.hpp
  requiredBy: []
  timestamp: '2024-07-30 23:24:22+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/verify/yosupo-deque-operate-all-composite.test.cpp
  - test/verify/yosupo-queue-operate-all-composite.test.cpp
  - test/verify/yosupo-vertex-set-path-composite.test.cpp
documentation_of: math/linear_function.hpp
layout: document
redirect_from:
- /library/math/linear_function.hpp
- /library/math/linear_function.hpp.html
title: math/linear_function.hpp
---
