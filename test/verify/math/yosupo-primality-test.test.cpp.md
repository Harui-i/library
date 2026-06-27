---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/primality_test.hpp
    title: primality_test
  - icon: ':question:'
    path: template/template.hpp
    title: template/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/primality_test
    links:
    - https://judge.yosupo.jp/problem/primality_test
  bundledCode: "#line 1 \"test/verify/math/yosupo-primality-test.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/primality_test\"\n\n#line 1 \"template/template.hpp\"\
    \n#include <iostream>\n#include <cassert>\nusing namespace std;\nusing ll = long\
    \ long;\ntemplate<class T> inline bool chmax(T& a, const T& b) {if (a<b) {a=b;\
    \ return true;} return false;}\ntemplate<class T> inline bool chmin(T& a, const\
    \ T& b) {if (b<a) {a=b; return true;} return false;}\nconst int INTINF = 1000001000;\n\
    const int INTMAX = 2147483647;\nconst ll LLMAX = 9223372036854775807;\nconst ll\
    \ LLINF = 1000000000000000000;\n#line 1 \"math/primality_test.hpp\"\n\n\n\n#include\
    \ <cstdint>\n\nnamespace primality_test_internal {\n\nusing u64 = unsigned long\
    \ long;\nusing u128 = unsigned __int128;\n\ninline u64 mod_pow_u64(u64 a, u64\
    \ e, u64 mod) {\n  u64 ret = 1;\n  while(e > 0) {\n    if(e & 1) ret = (u128)ret\
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
    \ a, d, s)) return false;\n  }\n  return true;\n}\n\n\n#line 5 \"test/verify/math/yosupo-primality-test.test.cpp\"\
    \n\nint main() {\n  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);\n\n  int\
    \ Q; cin >> Q;\n  while(Q--) {\n    unsigned long long n; cin >> n;\n    cout\
    \ << (is_prime(n) ? \"Yes\" : \"No\") << '\\n';\n  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/primality_test\"\n\n#include\
    \ \"template/template.hpp\"\n#include \"math/primality_test.hpp\"\n\nint main()\
    \ {\n  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);\n\n  int Q; cin >> Q;\n\
    \  while(Q--) {\n    unsigned long long n; cin >> n;\n    cout << (is_prime(n)\
    \ ? \"Yes\" : \"No\") << '\\n';\n  }\n}\n"
  dependsOn:
  - template/template.hpp
  - math/primality_test.hpp
  isVerificationFile: true
  path: test/verify/math/yosupo-primality-test.test.cpp
  requiredBy: []
  timestamp: '2026-05-11 00:18:16+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/verify/math/yosupo-primality-test.test.cpp
layout: document
redirect_from:
- /verify/test/verify/math/yosupo-primality-test.test.cpp
- /verify/test/verify/math/yosupo-primality-test.test.cpp.html
title: test/verify/math/yosupo-primality-test.test.cpp
---
