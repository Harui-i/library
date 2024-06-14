---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/mod_pow.hpp\"\n\n\n\ntemplate <typename T>\nT mod_pow(T\
    \ x, ll a, const T &p) {\n  assert(a >= 0);\n  T ret = 1;\n  while(a > 0) {\n\
    \    if (a % 2 == 1) {\n      ret = ret * x;\n      ret %= p;\n    }\n\n    x\
    \ = x * x;\n    x %= p;\n    a /= 2;\n  }\n  return ret;\n}\n\n\n"
  code: "#ifndef HARUILIB_MATH_MOD_POW_HPP\n#define HARUILIB_MATH_MOD_POW_HPP\n\n\
    template <typename T>\nT mod_pow(T x, ll a, const T &p) {\n  assert(a >= 0);\n\
    \  T ret = 1;\n  while(a > 0) {\n    if (a % 2 == 1) {\n      ret = ret * x;\n\
    \      ret %= p;\n    }\n\n    x = x * x;\n    x %= p;\n    a /= 2;\n  }\n  return\
    \ ret;\n}\n\n#endif // HARUI MOD_POW_HPP"
  dependsOn: []
  isVerificationFile: false
  path: math/mod_pow.hpp
  requiredBy: []
  timestamp: '2024-06-14 19:04:40+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/mod_pow.hpp
layout: document
redirect_from:
- /library/math/mod_pow.hpp
- /library/math/mod_pow.hpp.html
title: math/mod_pow.hpp
---
