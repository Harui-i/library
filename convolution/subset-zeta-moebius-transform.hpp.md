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
  bundledCode: "#line 1 \"convolution/subset-zeta-moebius-transform.hpp\"\n\n\n\n\
    #include <vector>\n\ntemplate <class T, T (*op)(T, T) >\nstd::vector<T> subset_zeta_transform(const\
    \ std::vector<T>& f) {\n\n  int n = 0; while ((1 << n) < (int)f.size()) n++;\n\
    \  assert((int)f.size() == (1 << n)); // f.size() should be power of 2.\n\n\n\
    \  std::vector<T> F = f;\n  for (int k = 0; k < n; k++) {\n    for (int s = 0;\
    \ s < 1 << n; s++) {\n      if ((s >> k) & 1) F[s] = op(F[s], F[s ^ (1 << k)]);\n\
    \    }\n  }\n  return F;\n}\n\n\ntemplate <class T, T (*invop)(T, T) >\nstd::vector<T>\
    \ subset_moebius_transform(const std::vector<T>& f) {\n  int n = 0; while ((1\
    \ << n) < (int)f.size()) n++;\n  assert((int)f.size() == (1 << n)); // f.size()\
    \ should be power of 2.\n\n  std::vector<T> F = f;\n  for (int k = 0; k < n; k++)\
    \ {\n    for (int s = 0; s < 1 << n; s++) {\n      if ((s >> k) & 1) F[s] = invop(F[s],\
    \ F[s ^ (1 << k)]);\n    }\n  }\n  return F;\n}\n\n\n"
  code: "#ifndef HARUILIB_CONVOLUTION_SUBSET_ZETA_MOEBIUS_TRANSFORM_HPP\n#define HARUILIB_CONVOLUTION_SUBSET_ZETA_MOEBIUS_TRANSFORM_HPP\n\
    \n#include <vector>\n\ntemplate <class T, T (*op)(T, T) >\nstd::vector<T> subset_zeta_transform(const\
    \ std::vector<T>& f) {\n\n  int n = 0; while ((1 << n) < (int)f.size()) n++;\n\
    \  assert((int)f.size() == (1 << n)); // f.size() should be power of 2.\n\n\n\
    \  std::vector<T> F = f;\n  for (int k = 0; k < n; k++) {\n    for (int s = 0;\
    \ s < 1 << n; s++) {\n      if ((s >> k) & 1) F[s] = op(F[s], F[s ^ (1 << k)]);\n\
    \    }\n  }\n  return F;\n}\n\n\ntemplate <class T, T (*invop)(T, T) >\nstd::vector<T>\
    \ subset_moebius_transform(const std::vector<T>& f) {\n  int n = 0; while ((1\
    \ << n) < (int)f.size()) n++;\n  assert((int)f.size() == (1 << n)); // f.size()\
    \ should be power of 2.\n\n  std::vector<T> F = f;\n  for (int k = 0; k < n; k++)\
    \ {\n    for (int s = 0; s < 1 << n; s++) {\n      if ((s >> k) & 1) F[s] = invop(F[s],\
    \ F[s ^ (1 << k)]);\n    }\n  }\n  return F;\n}\n\n#endif // HARUILIB_CONVOLUTION_SUBSET_ZETA_MOEBIUS_TRANSFORM_HPP"
  dependsOn: []
  isVerificationFile: false
  path: convolution/subset-zeta-moebius-transform.hpp
  requiredBy: []
  timestamp: '2024-06-20 23:28:06+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: convolution/subset-zeta-moebius-transform.hpp
layout: document
redirect_from:
- /library/convolution/subset-zeta-moebius-transform.hpp
- /library/convolution/subset-zeta-moebius-transform.hpp.html
title: convolution/subset-zeta-moebius-transform.hpp
---
