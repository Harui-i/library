---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/verify/yosupo-and-convolution.test.cpp
    title: test/verify/yosupo-and-convolution.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"convolution/superset-zeta-moebius-transform.hpp\"\n\n\n\n\
    #include <vector>\n\ntemplate <typename T>\nstd::vector<T> superset_zeta_transform(const\
    \ std::vector<T>& f) {\n\n  int n = 0; while ((1 << n) < (int)f.size()) n++;\n\
    \  assert((int)f.size() == (1 << n)); // f.size() should be power of 2.\n\n\n\
    \  std::vector<T> F = f;\n  for (int k = 0; k < n; k++) {\n    for (int s = 0;\
    \ s < 1 << n; s++) {\n      if (!((s >> k) & 1)) F[s] += F[s ^ (1 << k)];\n  \
    \  }\n  }\n  return F;\n}\n\n\ntemplate <typename T>\nstd::vector<T> superset_moebius_transform(const\
    \ std::vector<T>& f) {\n  int n = 0; while ((1 << n) < (int)f.size()) n++;\n \
    \ assert((int)f.size() == (1 << n)); // f.size() should be power of 2.\n\n  std::vector<T>\
    \ F = f;\n  for (int k = 0; k < n; k++) {\n    for (int s = 0; s < 1 << n; s++)\
    \ {\n      if (!((s >> k) & 1)) F[s] -= F[s ^ (1 << k)];\n    }\n  }\n  return\
    \ F;\n}\n\n\n"
  code: "#ifndef HARUILIB_CONVOLUTION_SUPERSET_ZETA_MOEBIUS_TRANSFORM_HPP\n#define\
    \ HARUILIB_CONVOLUTION_SUPERSET_ZETA_MOEBIUS_TRANSFORM_HPP\n\n#include <vector>\n\
    \ntemplate <typename T>\nstd::vector<T> superset_zeta_transform(const std::vector<T>&\
    \ f) {\n\n  int n = 0; while ((1 << n) < (int)f.size()) n++;\n  assert((int)f.size()\
    \ == (1 << n)); // f.size() should be power of 2.\n\n\n  std::vector<T> F = f;\n\
    \  for (int k = 0; k < n; k++) {\n    for (int s = 0; s < 1 << n; s++) {\n   \
    \   if (!((s >> k) & 1)) F[s] += F[s ^ (1 << k)];\n    }\n  }\n  return F;\n}\n\
    \n\ntemplate <typename T>\nstd::vector<T> superset_moebius_transform(const std::vector<T>&\
    \ f) {\n  int n = 0; while ((1 << n) < (int)f.size()) n++;\n  assert((int)f.size()\
    \ == (1 << n)); // f.size() should be power of 2.\n\n  std::vector<T> F = f;\n\
    \  for (int k = 0; k < n; k++) {\n    for (int s = 0; s < 1 << n; s++) {\n   \
    \   if (!((s >> k) & 1)) F[s] -= F[s ^ (1 << k)];\n    }\n  }\n  return F;\n}\n\
    \n#endif // HARUILIB_CONVOLUTION_SUPERSET_ZETA_MOEBIUS_TRANSFORM_HPP"
  dependsOn: []
  isVerificationFile: false
  path: convolution/superset-zeta-moebius-transform.hpp
  requiredBy: []
  timestamp: '2024-06-18 00:02:31+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/verify/yosupo-and-convolution.test.cpp
documentation_of: convolution/superset-zeta-moebius-transform.hpp
layout: document
title: "\u4E0A\u4F4D\u96C6\u5408\u306E\u9AD8\u901F\u30BC\u30FC\u30BF\u5909\u63DB"
---

## 概要

サイズ$N$の集合 $S$について、$f(S)$が($2^N$の`vector`で)与えられたときに、
$ g(S) = \Sigma_{S \subseteq T} f(S) $ を求めたり(Zeta)、その逆変換を求めたり(Möbius)する。

添字AND畳み込みは、上位集合についてゼータ変換したあとに各点積を取ってメビウス変換すると求められたりする。

Scrapboxを見るといっぱい資料がある。

### 計算量
ゼータもメビウスも

- $O(N 2^N ) $

