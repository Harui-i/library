---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: math/external_gcd.hpp
    title: math/external_gcd.hpp
  - icon: ':question:'
    path: math/modint.hpp
    title: modint
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
    PROBLEM: https://judge.yosupo.jp/problem/sqrt_mod
    links:
    - https://judge.yosupo.jp/problem/sqrt_mod
  bundledCode: "#line 1 \"test/verify/math/yosupo-sqrt-mod.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/sqrt_mod\"\n\n#line 1 \"template/template.hpp\"\
    \n#include <iostream>\n#include <cassert>\nusing namespace std;\nusing ll = long\
    \ long;\ntemplate<class T> inline bool chmax(T& a, const T& b) {if (a<b) {a=b;\
    \ return true;} return false;}\ntemplate<class T> inline bool chmin(T& a, const\
    \ T& b) {if (b<a) {a=b; return true;} return false;}\nconst int INTINF = 1000001000;\n\
    const int INTMAX = 2147483647;\nconst ll LLMAX = 9223372036854775807;\nconst ll\
    \ LLINF = 1000000000000000000;\n#line 1 \"math/modint.hpp\"\n\n\n\n#line 1 \"\
    math/external_gcd.hpp\"\n\n\n\n#include <tuple>\n\n// g,x,y\ntemplate<typename\
    \ T>\nconstexpr std::tuple<T, T, T> extendedGCD(T a, T b) {\n    T x0 = 1, y0\
    \ = 0, x1 = 0, y1 = 1;\n    while (b != 0) {\n        T q = a / b;\n        T\
    \ r = a % b;\n        a = b;\n        b = r;\n        \n        T xTemp = x0 -\
    \ q * x1;\n        x0 = x1;\n        x1 = xTemp;\n        \n        T yTemp =\
    \ y0 - q * y1;\n        y0 = y1;\n        y1 = yTemp;\n    }\n    return {a, x0,\
    \ y0};\n}\n\n#line 5 \"math/modint.hpp\"\n#include <type_traits>\n#line 7 \"math/modint.hpp\"\
    \n\nlong long mod_pow_ll(long long x, long long n, long long mod) {\n    long\
    \ long ret = 1;\n    while (n > 0) {\n        if (n & 1) ret = (__int128)ret *\
    \ x % mod;\n        x = (__int128)x * x % mod;\n        n >>= 1;\n    }\n    return\
    \ ret;\n}\n\n// x^2 = a (mod p) \u3068\u306A\u308B x \u3092\u8FD4\u3059\u3002\u5B58\
    \u5728\u3057\u306A\u3044\u5834\u5408\u306F -1\u3002\n// p \u306F\u7D20\u6570\u3067\
    \u3042\u308B\u3053\u3068\u3092\u4EEE\u5B9A\u3059\u308B\u3002\nlong long mod_sqrt(long\
    \ long a, long long p) {\n    a %= p;\n    if (a < 0) a += p;\n    if (a == 0)\
    \ return 0;\n    if (p == 2) return a;\n    if (mod_pow_ll(a, (p - 1) / 2, p)\
    \ != 1) return -1;\n    if (p % 4 == 3) return mod_pow_ll(a, (p + 1) / 4, p);\n\
    \n    long long q = p - 1;\n    int s = 0;\n    while ((q & 1) == 0) {\n     \
    \   q >>= 1;\n        s++;\n    }\n\n    long long z = 2;\n    while (mod_pow_ll(z,\
    \ (p - 1) / 2, p) != p - 1) z++;\n\n    long long c = mod_pow_ll(z, q, p);\n \
    \   long long x = mod_pow_ll(a, (q + 1) / 2, p);\n    long long t = mod_pow_ll(a,\
    \ q, p);\n    int m = s;\n\n    while (t != 1) {\n        int i = 1;\n       \
    \ long long tt = (__int128)t * t % p;\n        while (tt != 1) {\n           \
    \ tt = (__int128)tt * tt % p;\n            i++;\n        }\n        long long\
    \ b = c;\n        for (int j = 0; j < m - i - 1; j++) b = (__int128)b * b % p;\n\
    \        x = (__int128)x * b % p;\n        c = (__int128)b * b % p;\n        t\
    \ = (__int128)t * c % p;\n        m = i;\n    }\n\n    return x;\n}\n\ntemplate<int\
    \ MOD, typename T = int>\nstruct static_modint {\n    T value;\n\n    constexpr\
    \ explicit static_modint() : value(0) {}\n\n    static constexpr int mod() { return\
    \ MOD; }\n\n    constexpr static_modint(long long v) {\n        if constexpr (std::is_same<T,\
    \ double>::value) {\n            value = double(v);\n        }\n        else {\n\
    \            value = int(((v % MOD) + MOD) % MOD);\n        }\n    }\n\n    constexpr\
    \ static_modint& operator+=(const static_modint& other) {\n        if constexpr\
    \ (std::is_same<T, double>::value) {\n            value += other.value;\n    \
    \    }\n        else {\n            if ((value += other.value) >= MOD) value -=\
    \ MOD;\n        }\n        return *this;\n    }\n\n    constexpr static_modint&\
    \ operator-=(const static_modint& other) {\n        if constexpr (std::is_same<T,\
    \ double>::value) {\n            value -= other.value;\n        }\n        else\
    \ {\n            if ((value -= other.value) < 0) value += MOD;\n        }\n  \
    \      return *this;\n    }\n\n    constexpr static_modint& operator*=(const static_modint&\
    \ other) {\n        if constexpr (std::is_same<T, double>::value) {\n        \
    \    value *= other.value;\n        }\n        else {\n            value = int((long\
    \ long)value * other.value % MOD);\n        }\n        return *this;\n    }\n\n\
    \    constexpr static_modint operator+(const static_modint& other) const {\n \
    \       return static_modint(*this) += other;\n    }\n\n    constexpr static_modint\
    \ operator-(const static_modint& other) const {\n        return static_modint(*this)\
    \ -= other;\n    }\n\n    constexpr static_modint operator-() const {\n      \
    \  return static_modint(0) - *this;\n    }\n\n    constexpr static_modint operator*(const\
    \ static_modint& other) const {\n        return static_modint(*this) *= other;\n\
    \    }\n\n    constexpr static_modint pow(long long exp) const {\n        static_modint\
    \ base = *this, res = static_modint(1);\n        while (exp > 0) {\n         \
    \   if (exp & 1) res *= base;\n            base *= base;\n            exp >>=\
    \ 1;\n        }\n        return res;\n    }\n\n    long long sqrt_val() const\
    \ {\n        return mod_sqrt(value, MOD);\n    }\n\n    static_modint sqrt() const\
    \ {\n        long long ret = sqrt_val();\n        assert(ret != -1);\n       \
    \ return static_modint(ret);\n    }\n\n    constexpr static_modint inv() const\
    \ {\n        if constexpr (std::is_same<T, double>::value) {\n            static_modint\
    \ ret;\n            ret.value = double(1.0) / value;\n            return ret;\n\
    \        }\n        else {\n            int g, x, y;\n            std::tie(g,\
    \ x, y) = extendedGCD(value, MOD);\n            assert(g == 1);\n            if\
    \ (x < 0) x += MOD;\n            return x;\n        }\n    }\n\n    constexpr\
    \ static_modint& operator/=(const static_modint& other) {\n        return *this\
    \ *= other.inv();\n    }\n\n    constexpr static_modint operator/(const static_modint&\
    \ other) const {\n        return static_modint(*this) /= other;\n    }\n\n   \
    \ constexpr bool operator!=(const static_modint& other) const {\n        return\
    \ val() != other.val();\n    }\n\n    constexpr bool operator==(const static_modint&\
    \ other) const {\n        return val() == other.val();\n    }\n\n    T val() const\
    \ {\n        if constexpr (std::is_same<T, double>::value) {\n            return\
    \ double(value);\n        }\n        else return this->value;\n    }\n\n    friend\
    \ std::ostream& operator<<(std::ostream& os, const static_modint& mi) {\n    \
    \    return os << mi.value;\n    }\n\n    friend std::istream& operator>>(std::istream&\
    \ is, static_modint& mi) {\n        long long x;\n        is >> x;\n        mi\
    \ = static_modint(x);\n        return is;\n    }\n};\n\ntemplate <int mod>\nusing\
    \ modint = static_modint<mod>;\nusing doublemodint = static_modint<59, double>;\n\
    using modint998244353 = modint<998244353>;\nusing modint1000000007 = modint<1000000007>;\n\
    \n\n#line 5 \"test/verify/math/yosupo-sqrt-mod.test.cpp\"\n\nint main() {\n  ios::sync_with_stdio(0);\
    \ cin.tie(0); cout.tie(0);\n\n  int T; cin >> T;\n  while (T--) {\n    long long\
    \ y, p; cin >> y >> p;\n    cout << mod_sqrt(y, p) << '\\n';\n  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/sqrt_mod\"\n\n#include\
    \ \"template/template.hpp\"\n#include \"math/modint.hpp\"\n\nint main() {\n  ios::sync_with_stdio(0);\
    \ cin.tie(0); cout.tie(0);\n\n  int T; cin >> T;\n  while (T--) {\n    long long\
    \ y, p; cin >> y >> p;\n    cout << mod_sqrt(y, p) << '\\n';\n  }\n}\n"
  dependsOn:
  - template/template.hpp
  - math/modint.hpp
  - math/external_gcd.hpp
  isVerificationFile: true
  path: test/verify/math/yosupo-sqrt-mod.test.cpp
  requiredBy: []
  timestamp: '2026-06-28 07:56:01+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/verify/math/yosupo-sqrt-mod.test.cpp
layout: document
redirect_from:
- /verify/test/verify/math/yosupo-sqrt-mod.test.cpp
- /verify/test/verify/math/yosupo-sqrt-mod.test.cpp.html
title: test/verify/math/yosupo-sqrt-mod.test.cpp
---
