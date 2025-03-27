---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: string/rolling-hash.hpp
    title: "\u30ED\u30FC\u30EA\u30F3\u30B0\u30CF\u30C3\u30B7\u30E5(Rolling Hash)"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/verify/aoj-alds-1-14-b.test.cpp
    title: test/verify/aoj-alds-1-14-b.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://qiita.com/keymoon/items/11fac5627672a6d6a9f6
  bundledCode: "#line 1 \"math/modint2611.hpp\"\n\n\n\n#include <random>\n#include\
    \ <chrono>\n/*\n\u6CD5\u304C2^61 - 1\u306Emodint\ncf: https://qiita.com/keymoon/items/11fac5627672a6d6a9f6\n\
    \ */\n\nstruct modint2611 {\n\n  constexpr static const uint64_t mod = (1ull <<\
    \ 61ull) - 1;\n  using uint128_t = __uint128_t;\n  uint64_t _val;\n\n  constexpr\
    \ explicit modint2611() : _val(0) {}\n\n  constexpr explicit modint2611(uint64_t\
    \ v) : _val(v) {\n    if (_val >= mod) _val -= mod;\n  }\n\n  constexpr modint2611&\
    \ operator+=(const modint2611& rhs) {\n    if ((_val += rhs._val) >= mod) _val\
    \ -= mod;\n    return *this;\n  }\n\n  constexpr modint2611& operator-=(const\
    \ modint2611& rhs) {\n    if (_val < rhs._val) {\n      _val += (mod - rhs._val);\n\
    \    }\n    else {\n      _val += -rhs._val;\n    }\n    return *this;\n  }\n\n\
    \  constexpr modint2611& operator*=(const modint2611& rhs) {\n    uint128_t c\
    \ = (uint128_t) _val * rhs._val;\n    // return (c>>61) + (c & mod);\n    uint64_t\
    \ d = (c>>61) + (c & mod);\n    if (d >= mod) d -= mod;\n\n    _val = d;\n   \
    \ return *this;\n  }\n  \n  constexpr modint2611 operator-() const { return modint2611(0)\
    \ - *this; }\n\n  constexpr modint2611 operator+(const modint2611& a) const {\n\
    \    return modint2611(*this) += a;\n  }\n\n  constexpr modint2611 operator-(const\
    \ modint2611& a) const {\n    return modint2611(*this) -= a;\n  }\n\n  constexpr\
    \ modint2611 operator*(const modint2611& a) const {\n    return modint2611(*this)\
    \ *= a;\n  }\n  \n  constexpr bool operator==(const modint2611& a) const { return\
    \ _val == a._val; }\n\n  constexpr bool operator!=(const modint2611& a) const\
    \ { return _val != a._val; }\n\n  constexpr uint64_t val() const {\n    return\
    \ _val;\n  }\n\n  constexpr modint2611 pow(uint64_t n) const {\n    modint2611\
    \ ret = modint2611(1);\n    modint2611 base = *this;\n    while (n) {\n      if\
    \ (n & 1) ret *= base;\n      base *= base;\n      n >>= 1;\n    }\n    return\
    \ ret;\n  }\n\n  constexpr modint2611 inv() const {\n    return (*this).pow(mod\
    \ - 2);\n  }\n\n  static inline modint2611 generate_base() {\n    mt19937_64 mt(chrono::steady_clock::now().time_since_epoch().count());\n\
    \    uniform_int_distribution< uint64_t > rand(1, mod - 1);\n\n    return modint2611(rand(mt));\n\
    \  }\n\n};\n\n\n"
  code: "#ifndef HARUILIB_MATH_MODINT2611_HPP\n#define HARUILIB_MATH_MODINT2611_HPP\n\
    \n#include <random>\n#include <chrono>\n/*\n\u6CD5\u304C2^61 - 1\u306Emodint\n\
    cf: https://qiita.com/keymoon/items/11fac5627672a6d6a9f6\n */\n\nstruct modint2611\
    \ {\n\n  constexpr static const uint64_t mod = (1ull << 61ull) - 1;\n  using uint128_t\
    \ = __uint128_t;\n  uint64_t _val;\n\n  constexpr explicit modint2611() : _val(0)\
    \ {}\n\n  constexpr explicit modint2611(uint64_t v) : _val(v) {\n    if (_val\
    \ >= mod) _val -= mod;\n  }\n\n  constexpr modint2611& operator+=(const modint2611&\
    \ rhs) {\n    if ((_val += rhs._val) >= mod) _val -= mod;\n    return *this;\n\
    \  }\n\n  constexpr modint2611& operator-=(const modint2611& rhs) {\n    if (_val\
    \ < rhs._val) {\n      _val += (mod - rhs._val);\n    }\n    else {\n      _val\
    \ += -rhs._val;\n    }\n    return *this;\n  }\n\n  constexpr modint2611& operator*=(const\
    \ modint2611& rhs) {\n    uint128_t c = (uint128_t) _val * rhs._val;\n    // return\
    \ (c>>61) + (c & mod);\n    uint64_t d = (c>>61) + (c & mod);\n    if (d >= mod)\
    \ d -= mod;\n\n    _val = d;\n    return *this;\n  }\n  \n  constexpr modint2611\
    \ operator-() const { return modint2611(0) - *this; }\n\n  constexpr modint2611\
    \ operator+(const modint2611& a) const {\n    return modint2611(*this) += a;\n\
    \  }\n\n  constexpr modint2611 operator-(const modint2611& a) const {\n    return\
    \ modint2611(*this) -= a;\n  }\n\n  constexpr modint2611 operator*(const modint2611&\
    \ a) const {\n    return modint2611(*this) *= a;\n  }\n  \n  constexpr bool operator==(const\
    \ modint2611& a) const { return _val == a._val; }\n\n  constexpr bool operator!=(const\
    \ modint2611& a) const { return _val != a._val; }\n\n  constexpr uint64_t val()\
    \ const {\n    return _val;\n  }\n\n  constexpr modint2611 pow(uint64_t n) const\
    \ {\n    modint2611 ret = modint2611(1);\n    modint2611 base = *this;\n    while\
    \ (n) {\n      if (n & 1) ret *= base;\n      base *= base;\n      n >>= 1;\n\
    \    }\n    return ret;\n  }\n\n  constexpr modint2611 inv() const {\n    return\
    \ (*this).pow(mod - 2);\n  }\n\n  static inline modint2611 generate_base() {\n\
    \    mt19937_64 mt(chrono::steady_clock::now().time_since_epoch().count());\n\
    \    uniform_int_distribution< uint64_t > rand(1, mod - 1);\n\n    return modint2611(rand(mt));\n\
    \  }\n\n};\n\n#endif // HARUILIB_MATH_MODINT2611_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: math/modint2611.hpp
  requiredBy:
  - string/rolling-hash.hpp
  timestamp: '2025-03-27 15:05:33+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/verify/aoj-alds-1-14-b.test.cpp
documentation_of: math/modint2611.hpp
layout: document
redirect_from:
- /library/math/modint2611.hpp
- /library/math/modint2611.hpp.html
title: math/modint2611.hpp
---
