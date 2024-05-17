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
  bundledCode: "#line 1 \"math/modint.hpp\"\ntemplate<int MOD>\nstruct static_modint\
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
    \ {\n        return static_modint(*this) /= other;\n    }\n\n    int val() const\
    \ {\n      return this.val;\n    }\n\n    friend std::ostream& operator<<(std::ostream&\
    \ os, const static_modint& mi) {\n        return os << mi.value;\n    }\n\n  \
    \  friend std::istream& operator>>(std::istream& is, static_modint& mi) {\n  \
    \      long long x;\n        is >> x;\n        mi = static_modint(x);\n      \
    \  return is;\n    }\n};\n\ntemplate <int mod>\nusing modint = static_modint<mod>;\n\
    using modint998244353 = modint<998244353>;\nusing modint100000007 = modint<100000007>;\n"
  code: "template<int MOD>\nstruct static_modint {\n    int value;\n\n    constexpr\
    \ static_modint() : value(0) {}\n\n    constexpr static_modint(long long v) {\n\
    \        value = int(((v % MOD) + MOD) % MOD);\n    }\n\n    constexpr static_modint&\
    \ operator+=(const static_modint& other) {\n        if ((value += other.value)\
    \ >= MOD) value -= MOD;\n        return *this;\n    }\n\n    constexpr static_modint&\
    \ operator-=(const static_modint& other) {\n        if ((value -= other.value)\
    \ < 0) value += MOD;\n        return *this;\n    }\n\n    constexpr static_modint&\
    \ operator*=(const static_modint& other) {\n        value = int((long long)value\
    \ * other.value % MOD);\n        return *this;\n    }\n\n    constexpr static_modint\
    \ operator+(const static_modint& other) const {\n        return static_modint(*this)\
    \ += other;\n    }\n\n    constexpr static_modint operator-(const static_modint&\
    \ other) const {\n        return static_modint(*this) -= other;\n    }\n\n   \
    \ constexpr static_modint operator*(const static_modint& other) const {\n    \
    \    return static_modint(*this) *= other;\n    }\n\n    constexpr static_modint\
    \ pow(long long exp) const {\n        static_modint base = *this, res = 1;\n \
    \       while (exp > 0) {\n            if (exp & 1) res *= base;\n           \
    \ base *= base;\n            exp >>= 1;\n        }\n        return res;\n    }\n\
    \n    constexpr static_modint inv() const {\n        return pow(MOD - 2);\n  \
    \  }\n\n    constexpr static_modint& operator/=(const static_modint& other) {\n\
    \        return *this *= other.inv();\n    }\n\n    constexpr static_modint operator/(const\
    \ static_modint& other) const {\n        return static_modint(*this) /= other;\n\
    \    }\n\n    int val() const {\n      return this.val;\n    }\n\n    friend std::ostream&\
    \ operator<<(std::ostream& os, const static_modint& mi) {\n        return os <<\
    \ mi.value;\n    }\n\n    friend std::istream& operator>>(std::istream& is, static_modint&\
    \ mi) {\n        long long x;\n        is >> x;\n        mi = static_modint(x);\n\
    \        return is;\n    }\n};\n\ntemplate <int mod>\nusing modint = static_modint<mod>;\n\
    using modint998244353 = modint<998244353>;\nusing modint100000007 = modint<100000007>;"
  dependsOn: []
  isVerificationFile: false
  path: math/modint.hpp
  requiredBy: []
  timestamp: '2024-05-17 18:23:08+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/modint.hpp
layout: document
title: modint
---

なんかうまくやってくれます。生成AIが書いてくれました。