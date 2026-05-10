---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/verify/math/yosupo-primality-test.test.cpp
    title: test/verify/math/yosupo-primality-test.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/primality_test.hpp\"\n\n\n\n#include <cstdint>\n\n\
    namespace primality_test_internal {\n\nusing u64 = unsigned long long;\nusing\
    \ u128 = unsigned __int128;\n\ninline u64 mod_pow_u64(u64 a, u64 e, u64 mod) {\n\
    \  u64 ret = 1;\n  while(e > 0) {\n    if(e & 1) ret = (u128)ret * a % mod;\n\
    \    a = (u128)a * a % mod;\n    e >>= 1;\n  }\n  return ret;\n}\n\ninline bool\
    \ miller_rabin(u64 n, u64 a, u64 d, int s) {\n  if(a % n == 0) return true;\n\
    \  u64 x = mod_pow_u64(a, d, n);\n  if(x == 1 || x == n - 1) return true;\n  for(int\
    \ i=1; i<s; i++) {\n    x = (u128)x * x % n;\n    if(x == n - 1) return true;\n\
    \  }\n  return false;\n}\n\n} // namespace primality_test_internal\n\ninline bool\
    \ is_prime(unsigned long long n) {\n  using namespace primality_test_internal;\n\
    \  if(n < 2) return false;\n  for(u64 p: {2ULL, 3ULL, 5ULL, 7ULL, 11ULL, 13ULL,\
    \ 17ULL, 19ULL, 23ULL, 29ULL, 31ULL, 37ULL}) {\n    if(n == p) return true;\n\
    \    if(n % p == 0) return false;\n  }\n\n  u64 d = n - 1;\n  int s = 0;\n  while((d\
    \ & 1) == 0) {\n    d >>= 1;\n    s++;\n  }\n\n  for(u64 a: {2ULL, 3ULL, 5ULL,\
    \ 7ULL, 11ULL, 13ULL, 17ULL, 19ULL, 23ULL, 29ULL, 31ULL, 37ULL}) {\n    if(!miller_rabin(n,\
    \ a, d, s)) return false;\n  }\n  return true;\n}\n\n\n"
  code: "#ifndef HARUILIB_MATH_PRIMALITY_TEST_HPP\n#define HARUILIB_MATH_PRIMALITY_TEST_HPP\n\
    \n#include <cstdint>\n\nnamespace primality_test_internal {\n\nusing u64 = unsigned\
    \ long long;\nusing u128 = unsigned __int128;\n\ninline u64 mod_pow_u64(u64 a,\
    \ u64 e, u64 mod) {\n  u64 ret = 1;\n  while(e > 0) {\n    if(e & 1) ret = (u128)ret\
    \ * a % mod;\n    a = (u128)a * a % mod;\n    e >>= 1;\n  }\n  return ret;\n}\n\
    \ninline bool miller_rabin(u64 n, u64 a, u64 d, int s) {\n  if(a % n == 0) return\
    \ true;\n  u64 x = mod_pow_u64(a, d, n);\n  if(x == 1 || x == n - 1) return true;\n\
    \  for(int i=1; i<s; i++) {\n    x = (u128)x * x % n;\n    if(x == n - 1) return\
    \ true;\n  }\n  return false;\n}\n\n} // namespace primality_test_internal\n\n\
    inline bool is_prime(unsigned long long n) {\n  using namespace primality_test_internal;\n\
    \  if(n < 2) return false;\n  for(u64 p: {2ULL, 3ULL, 5ULL, 7ULL, 11ULL, 13ULL,\
    \ 17ULL, 19ULL, 23ULL, 29ULL, 31ULL, 37ULL}) {\n    if(n == p) return true;\n\
    \    if(n % p == 0) return false;\n  }\n\n  u64 d = n - 1;\n  int s = 0;\n  while((d\
    \ & 1) == 0) {\n    d >>= 1;\n    s++;\n  }\n\n  for(u64 a: {2ULL, 3ULL, 5ULL,\
    \ 7ULL, 11ULL, 13ULL, 17ULL, 19ULL, 23ULL, 29ULL, 31ULL, 37ULL}) {\n    if(!miller_rabin(n,\
    \ a, d, s)) return false;\n  }\n  return true;\n}\n\n#endif // HARUILIB_MATH_PRIMALITY_TEST_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: math/primality_test.hpp
  requiredBy: []
  timestamp: '2026-05-11 00:18:16+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/verify/math/yosupo-primality-test.test.cpp
documentation_of: math/primality_test.hpp
layout: document
title: primality_test
---

64bit 整数に対する素数判定です。

決定的 Miller-Rabin を使っています。

## 使い方

```cpp
bool is_prime(unsigned long long n);
```

`n` が素数なら `true`、そうでなければ `false` を返します。

## 計算量

`O(log n)`
