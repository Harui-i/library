---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/modint2611.hpp
    title: math/modint2611.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/verify/aoj-alds-1-14-b.test.cpp
    title: test/verify/aoj-alds-1-14-b.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"string/rolling-hash.hpp\"\n\n\n\n#include <iostream>\n#include\
    \ <vector>\n\n#line 1 \"math/modint2611.hpp\"\n\n\n\n#include <random>\n#include\
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
    \  }\n\n};\n\n\n#line 8 \"string/rolling-hash.hpp\"\n\nstruct Hash {\n  using\
    \ mint = modint2611;\n  mint hash;\n  mint base;\n  int len;\n\n  constexpr Hash(mint\
    \ _hash, mint _base, int _len): hash(_hash), base(_base), len(_len) {\n  }\n\n\
    \  // \u6587\u5B57\u5217\u3068\u3057\u3066\u306E\u7D50\u5408\u3092\u3057\u305F\
    \u3042\u3068\u306EHash\u3092\u8FD4\u3059\n  constexpr Hash& operator+=(const Hash&\
    \ rhs) {\n    assert(base == rhs.base);\n    hash += base.pow(len) * rhs.hash;\n\
    \    len += rhs.len;\n    return *this;\n  }\n\n  constexpr Hash operator+(const\
    \ Hash& rhs) const {\n    return Hash(*this) += rhs; \n  }\n\n  constexpr bool\
    \ operator==(const Hash& rhs) const {\n    return len == rhs.len && hash == rhs.hash;\n\
    \  }\n\n  friend std::ostream& operator<<(std::ostream& os, const Hash& hash)\
    \ {\n    os << \"Hash{len: \";\n    os << hash.len;\n    os << \", hash: \";\n\
    \    os << hash.hash.val();\n    os << \", base: \";\n    os << hash.base.val();\n\
    \    os << \"}\";\n    return os;\n  }\n};\n\nstruct RollingHash {\n  using mint\
    \ = modint2611;\n  std::vector<mint> hashes;\n  mint base;\n  constexpr RollingHash\
    \ (const std::string& S, mint _base) : base(_base) {\n    int N = int(S.size());\n\
    \    hashes.resize(N+1);\n    mint powb = base;\n    for (int i=0; i<N; i++) {\n\
    \      hashes[i+1] = hashes[i] + powb * mint(S[i]);\n      powb *= base;\n   \
    \ }\n  }\n\n  constexpr Hash get(int l, int r) const {\n    assert(0 <= l && l\
    \ <= r && r < int(hashes.size()));\n    mint hash_val = (hashes[r] - hashes[l])*(base.pow(l).inv());\n\
    \    return Hash(hash_val, base, r-l);\n  }\n\n};\n\n\n\n"
  code: "#ifndef HARUILIB_LIBRARY_STRING_ROLLING_HASH_HPP\n#define HARUILIB_LIBRARY_STRING_ROLLING_HASH_HPP\n\
    \n#include <iostream>\n#include <vector>\n\n#include \"math/modint2611.hpp\"\n\
    \nstruct Hash {\n  using mint = modint2611;\n  mint hash;\n  mint base;\n  int\
    \ len;\n\n  constexpr Hash(mint _hash, mint _base, int _len): hash(_hash), base(_base),\
    \ len(_len) {\n  }\n\n  // \u6587\u5B57\u5217\u3068\u3057\u3066\u306E\u7D50\u5408\
    \u3092\u3057\u305F\u3042\u3068\u306EHash\u3092\u8FD4\u3059\n  constexpr Hash&\
    \ operator+=(const Hash& rhs) {\n    assert(base == rhs.base);\n    hash += base.pow(len)\
    \ * rhs.hash;\n    len += rhs.len;\n    return *this;\n  }\n\n  constexpr Hash\
    \ operator+(const Hash& rhs) const {\n    return Hash(*this) += rhs; \n  }\n\n\
    \  constexpr bool operator==(const Hash& rhs) const {\n    return len == rhs.len\
    \ && hash == rhs.hash;\n  }\n\n  friend std::ostream& operator<<(std::ostream&\
    \ os, const Hash& hash) {\n    os << \"Hash{len: \";\n    os << hash.len;\n  \
    \  os << \", hash: \";\n    os << hash.hash.val();\n    os << \", base: \";\n\
    \    os << hash.base.val();\n    os << \"}\";\n    return os;\n  }\n};\n\nstruct\
    \ RollingHash {\n  using mint = modint2611;\n  std::vector<mint> hashes;\n  mint\
    \ base;\n  constexpr RollingHash (const std::string& S, mint _base) : base(_base)\
    \ {\n    int N = int(S.size());\n    hashes.resize(N+1);\n    mint powb = base;\n\
    \    for (int i=0; i<N; i++) {\n      hashes[i+1] = hashes[i] + powb * mint(S[i]);\n\
    \      powb *= base;\n    }\n  }\n\n  constexpr Hash get(int l, int r) const {\n\
    \    assert(0 <= l && l <= r && r < int(hashes.size()));\n    mint hash_val =\
    \ (hashes[r] - hashes[l])*(base.pow(l).inv());\n    return Hash(hash_val, base,\
    \ r-l);\n  }\n\n};\n\n\n#endif // HARUILIB_LIBRARY_STRING_ROLLING_HASH_HPP\n"
  dependsOn:
  - math/modint2611.hpp
  isVerificationFile: false
  path: string/rolling-hash.hpp
  requiredBy: []
  timestamp: '2025-04-03 16:44:01+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/verify/aoj-alds-1-14-b.test.cpp
documentation_of: string/rolling-hash.hpp
layout: document
title: "\u30ED\u30FC\u30EA\u30F3\u30B0\u30CF\u30C3\u30B7\u30E5(Rolling Hash)"
---

RollingHashを扱う。

文字列Sのハッシュは、$ \Sum_{i=0, 1, \dots |S|} b^i S[i] $とする。

# Hash

文字列のハッシュを表現する。
文字列の長さ、基数、ハッシュの値を持つ。

## コンストラクタ

```
Hash(mint _hash, mint _base, int _len)
```

ハッシュした値が`_hash`で、基数が`_base`であり、その文字列は`_len`の長さであるとしてハッシュを初期化する。

```
operator+(const Hash& rhs) const
```

rhsを文字列として右から結合したあとのHashを返す。
基数が同じであることを要求する。

# RollingHash

文字列のHashを扱う。先頭からのハッシュを管理しておくことで、部分文字列のハッシュ計算なども対応する。

## コンストラクタ

```
RollingHash(const string& S, mint _base): (_base)
```

## get

```
Hash get(int l, int r) const
```

$S$の$[l,r)$部分のハッシュを計算する。
$mod$は定数なので計算量は$O(1)$

