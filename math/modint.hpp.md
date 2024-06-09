---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: formal-power-series/formal-power-series.hpp
    title: "Formal Power Series (\u5F62\u5F0F\u7684\u3079\u304D\u7D1A\u6570)"
  - icon: ':heavy_check_mark:'
    path: formal-power-series/sparse-fps.hpp
    title: sparse-fps
  - icon: ':warning:'
    path: test/verify/atcoder-tdpc-s.cpp
    title: test/verify/atcoder-tdpc-s.cpp
  - icon: ':warning:'
    path: test/verify/yosupo-inv-of-formal-power-series-fast1-test.cpp
    title: test/verify/yosupo-inv-of-formal-power-series-fast1-test.cpp
  - icon: ':warning:'
    path: test/verify/yosupo-inv-of-formal-power-series-naive-test.cpp
    title: test/verify/yosupo-inv-of-formal-power-series-naive-test.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/verify/yosupo-deque-operate-all-composite.test.cpp
    title: test/verify/yosupo-deque-operate-all-composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/verify/yosupo-exp-of-formal-power-series.test.cpp
    title: test/verify/yosupo-exp-of-formal-power-series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/verify/yosupo-inv-of-formal-power-series-fast2.test.cpp
    title: test/verify/yosupo-inv-of-formal-power-series-fast2.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/verify/yosupo-inv-of-formal-power-series-sparse.test.cpp
    title: test/verify/yosupo-inv-of-formal-power-series-sparse.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/verify/yosupo-log-of-formal-power-series.test.cpp
    title: test/verify/yosupo-log-of-formal-power-series.test.cpp
  - icon: ':x:'
    path: test/verify/yosupo-matrix-product.test.cpp
    title: test/verify/yosupo-matrix-product.test.cpp
  - icon: ':x:'
    path: test/verify/yosupo-pow-of-matrix.test.cpp
    title: test/verify/yosupo-pow-of-matrix.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/verify/yosupo-queue-operate-all-composite.test.cpp
    title: test/verify/yosupo-queue-operate-all-composite.test.cpp
  - icon: ':x:'
    path: test/verify/yuki-372-itsautomatic.test.cpp
    title: test/verify/yuki-372-itsautomatic.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/modint.hpp\"\ntemplate<int MOD>\nstruct static_modint\
    \ {\n    int value;\n\n    constexpr static_modint() : value(0) {}\n\n    constexpr\
    \ static_modint(long long v) {\n        value = int(((v % MOD) + MOD) % MOD);\n\
    \    }\n\n    constexpr static_modint& operator+=(const static_modint& other)\
    \ {\n        if ((value += other.value) >= MOD) value -= MOD;\n        return\
    \ *this;\n    }\n\n    constexpr static_modint& operator-=(const static_modint&\
    \ other) {\n        if ((value -= other.value) < 0) value += MOD;\n        return\
    \ *this;\n    }\n\n    constexpr static_modint& operator*=(const static_modint&\
    \ other) {\n        value = int((long long)value * other.value % MOD);\n     \
    \   return *this;\n    }\n\n    constexpr static_modint operator+(const static_modint&\
    \ other) const {\n        return static_modint(*this) += other;\n    }\n\n   \
    \ constexpr static_modint operator-(const static_modint& other) const {\n    \
    \    return static_modint(*this) -= other;\n    }\n\n    constexpr static_modint\
    \ operator*(const static_modint& other) const {\n        return static_modint(*this)\
    \ *= other;\n    }\n\n    constexpr static_modint pow(long long exp) const {\n\
    \        static_modint base = *this, res = 1;\n        while (exp > 0) {\n   \
    \         if (exp & 1) res *= base;\n            base *= base;\n            exp\
    \ >>= 1;\n        }\n        return res;\n    }\n\n    constexpr static_modint\
    \ inv() const {\n        return pow(MOD - 2);\n    }\n\n    constexpr static_modint&\
    \ operator/=(const static_modint& other) {\n        return *this *= other.inv();\n\
    \    }\n\n    constexpr static_modint operator/(const static_modint& other) const\
    \ {\n        return static_modint(*this) /= other;\n    }\n\n    constexpr bool\
    \ operator!=(const static_modint& other) const {\n        return val() != other.val();\n\
    \    }\n\n    constexpr bool operator==(const static_modint& other) const {\n\
    \        return val() == other.val();\n    }\n\n    int val() const {\n      return\
    \ this->value;\n    }\n\n    friend std::ostream& operator<<(std::ostream& os,\
    \ const static_modint& mi) {\n        return os << mi.value;\n    }\n\n    friend\
    \ std::istream& operator>>(std::istream& is, static_modint& mi) {\n        long\
    \ long x;\n        is >> x;\n        mi = static_modint(x);\n        return is;\n\
    \    }\n};\n\ntemplate <int mod>\nusing modint = static_modint<mod>;\nusing modint998244353\
    \  = modint<998244353>;\nusing modint1000000007 = modint<1000000007>;\n"
  code: "#pragma once\ntemplate<int MOD>\nstruct static_modint {\n    int value;\n\
    \n    constexpr static_modint() : value(0) {}\n\n    constexpr static_modint(long\
    \ long v) {\n        value = int(((v % MOD) + MOD) % MOD);\n    }\n\n    constexpr\
    \ static_modint& operator+=(const static_modint& other) {\n        if ((value\
    \ += other.value) >= MOD) value -= MOD;\n        return *this;\n    }\n\n    constexpr\
    \ static_modint& operator-=(const static_modint& other) {\n        if ((value\
    \ -= other.value) < 0) value += MOD;\n        return *this;\n    }\n\n    constexpr\
    \ static_modint& operator*=(const static_modint& other) {\n        value = int((long\
    \ long)value * other.value % MOD);\n        return *this;\n    }\n\n    constexpr\
    \ static_modint operator+(const static_modint& other) const {\n        return\
    \ static_modint(*this) += other;\n    }\n\n    constexpr static_modint operator-(const\
    \ static_modint& other) const {\n        return static_modint(*this) -= other;\n\
    \    }\n\n    constexpr static_modint operator*(const static_modint& other) const\
    \ {\n        return static_modint(*this) *= other;\n    }\n\n    constexpr static_modint\
    \ pow(long long exp) const {\n        static_modint base = *this, res = 1;\n \
    \       while (exp > 0) {\n            if (exp & 1) res *= base;\n           \
    \ base *= base;\n            exp >>= 1;\n        }\n        return res;\n    }\n\
    \n    constexpr static_modint inv() const {\n        return pow(MOD - 2);\n  \
    \  }\n\n    constexpr static_modint& operator/=(const static_modint& other) {\n\
    \        return *this *= other.inv();\n    }\n\n    constexpr static_modint operator/(const\
    \ static_modint& other) const {\n        return static_modint(*this) /= other;\n\
    \    }\n\n    constexpr bool operator!=(const static_modint& other) const {\n\
    \        return val() != other.val();\n    }\n\n    constexpr bool operator==(const\
    \ static_modint& other) const {\n        return val() == other.val();\n    }\n\
    \n    int val() const {\n      return this->value;\n    }\n\n    friend std::ostream&\
    \ operator<<(std::ostream& os, const static_modint& mi) {\n        return os <<\
    \ mi.value;\n    }\n\n    friend std::istream& operator>>(std::istream& is, static_modint&\
    \ mi) {\n        long long x;\n        is >> x;\n        mi = static_modint(x);\n\
    \        return is;\n    }\n};\n\ntemplate <int mod>\nusing modint = static_modint<mod>;\n\
    using modint998244353  = modint<998244353>;\nusing modint1000000007 = modint<1000000007>;"
  dependsOn: []
  isVerificationFile: false
  path: math/modint.hpp
  requiredBy:
  - test/verify/atcoder-tdpc-s.cpp
  - test/verify/yosupo-inv-of-formal-power-series-naive-test.cpp
  - test/verify/yosupo-inv-of-formal-power-series-fast1-test.cpp
  - formal-power-series/sparse-fps.hpp
  - formal-power-series/formal-power-series.hpp
  timestamp: '2024-06-09 18:28:49+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/verify/yosupo-deque-operate-all-composite.test.cpp
  - test/verify/yosupo-exp-of-formal-power-series.test.cpp
  - test/verify/yosupo-matrix-product.test.cpp
  - test/verify/yosupo-inv-of-formal-power-series-fast2.test.cpp
  - test/verify/yuki-372-itsautomatic.test.cpp
  - test/verify/yosupo-queue-operate-all-composite.test.cpp
  - test/verify/yosupo-inv-of-formal-power-series-sparse.test.cpp
  - test/verify/yosupo-pow-of-matrix.test.cpp
  - test/verify/yosupo-log-of-formal-power-series.test.cpp
documentation_of: math/modint.hpp
layout: document
title: modint
---

なんかうまくやってくれます。生成AIが書いてくれました。