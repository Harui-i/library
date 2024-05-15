---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: mod pow
    links: []
  bundledCode: "#line 1 \"math/mod_pow.hpp\"\n/**\n * @brief mod pow\n *  \n * \n\
    */\n\ntemplate <typename T>\nT mod_pow(T x, int a, const T &p) {\n  assert(a >=\
    \ 0);\n  T ret = 1;\n  while(a > 0) {\n    if (a % 2 == 1) {\n      ret = ret\
    \ * x;\n      ret %= p;\n    }\n\n    x = x * x;\n    x %= p;\n  }\n  return ret;\n\
    }\n"
  code: "/**\n * @brief mod pow\n *  \n * \n*/\n\ntemplate <typename T>\nT mod_pow(T\
    \ x, int a, const T &p) {\n  assert(a >= 0);\n  T ret = 1;\n  while(a > 0) {\n\
    \    if (a % 2 == 1) {\n      ret = ret * x;\n      ret %= p;\n    }\n\n    x\
    \ = x * x;\n    x %= p;\n  }\n  return ret;\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/mod_pow.hpp
  requiredBy: []
  timestamp: '2024-05-14 18:24:32+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/mod_pow.hpp
layout: document
redirect_from:
- /library/math/mod_pow.hpp
- /library/math/mod_pow.hpp.html
title: mod pow
---