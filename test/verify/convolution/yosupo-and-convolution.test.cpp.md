---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: convolution/superset-zeta-moebius-transform.hpp
    title: "\u4E0A\u4F4D\u96C6\u5408\u306E\u9AD8\u901F\u30BC\u30FC\u30BF\u5909\u63DB"
  - icon: ':heavy_check_mark:'
    path: math/external_gcd.hpp
    title: math/external_gcd.hpp
  - icon: ':heavy_check_mark:'
    path: math/modint.hpp
    title: modint
  - icon: ':heavy_check_mark:'
    path: template/template.hpp
    title: template/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/bitwise_and_convolution
    links:
    - https://judge.yosupo.jp/problem/bitwise_and_convolution
  bundledCode: "#line 1 \"test/verify/convolution/yosupo-and-convolution.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/bitwise_and_convolution\"\n\
    \n#line 1 \"template/template.hpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\ntypedef long long ll;\ntypedef unsigned int uint;\ntemplate<class T> inline\
    \ bool chmax(T& a, const T& b) {if (a<b) {a=b; return true;} return false;}\n\
    template<class T> inline bool chmin(T& a, const T& b) {if (b<a) {a=b; return true;}\
    \ return false;}\nconst int INTINF = 1000001000;\nconst int INTMAX = 2147483647;\n\
    const ll LLMAX = 9223372036854775807;\nconst ll LLINF = 1000000000000000000;\n\
    #line 1 \"math/modint.hpp\"\n\n\n\n#line 1 \"math/external_gcd.hpp\"\n\n\n\n#line\
    \ 5 \"math/external_gcd.hpp\"\n\n// g,x,y\ntemplate<typename T>\nconstexpr std::tuple<T,\
    \ T, T> extendedGCD(T a, T b) {\n    T x0 = 1, y0 = 0, x1 = 0, y1 = 1;\n    while\
    \ (b != 0) {\n        T q = a / b;\n        T r = a % b;\n        a = b;\n   \
    \     b = r;\n        \n        T xTemp = x0 - q * x1;\n        x0 = x1;\n   \
    \     x1 = xTemp;\n        \n        T yTemp = y0 - q * y1;\n        y0 = y1;\n\
    \        y1 = yTemp;\n    }\n    return {a, x0, y0};\n}\n\n#line 5 \"math/modint.hpp\"\
    \n\ntemplate<int MOD>\nstruct static_modint {\n    int value;\n\n    constexpr\
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
    \n    constexpr static_modint inv() const {\n        //return pow(MOD - 2);\n\
    \        int g,x,y;\n        tie(g,x,y) = extendedGCD(value, MOD);\n        assert(g==1);\n\
    \        if (x < 0) {\n            x += MOD;\n        }\n        //cerr << g <<\
    \ \" \" << x << \" \" << y << \" \" << value << endl;\n        //assert((((long)x*value)%MOD\
    \ + MOD)%MOD == 1);\n        return x;\n    }\n\n    constexpr static_modint&\
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
    \  = modint<998244353>;\nusing modint1000000007 = modint<1000000007>;\n\n\n#line\
    \ 1 \"convolution/superset-zeta-moebius-transform.hpp\"\n\n\n\n#line 5 \"convolution/superset-zeta-moebius-transform.hpp\"\
    \n\ntemplate <class T, T (*op)(T, T) >\nstd::vector<T> superset_zeta_transform(const\
    \ std::vector<T>& f) {\n\n  int n = 0; while ((1 << n) < (int)f.size()) n++;\n\
    \  assert((int)f.size() == (1 << n)); // f.size() should be power of 2.\n\n\n\
    \  std::vector<T> F = f;\n  for (int k = 0; k < n; k++) {\n    for (int s = 0;\
    \ s < 1 << n; s++) {\n      if (!((s >> k) & 1)) F[s] = op(F[s], F[s ^ (1 << k)]);\n\
    \    }\n  }\n  return F;\n}\n\n\ntemplate <class T, T (*invop)(T, T) >\nstd::vector<T>\
    \ superset_moebius_transform(const std::vector<T>& f) {\n  int n = 0; while ((1\
    \ << n) < (int)f.size()) n++;\n  assert((int)f.size() == (1 << n)); // f.size()\
    \ should be power of 2.\n\n  std::vector<T> F = f;\n  for (int k = 0; k < n; k++)\
    \ {\n    for (int s = 0; s < 1 << n; s++) {\n      if (!((s >> k) & 1)) F[s] =\
    \ invop(F[s], F[s ^ (1 << k)]);\n    }\n  }\n  return F;\n}\n\n\n#line 6 \"test/verify/convolution/yosupo-and-convolution.test.cpp\"\
    \n\nusing mint = modint998244353;\n\nmint op(mint a, mint b) {\n  return a + b;\n\
    }\n\nmint invop(mint a, mint b) {\n  return a - b;\n}\n\nint main() {\n  ios::sync_with_stdio(0);\
    \ cin.tie(0); cout.tie(0);\n  int N; cin >> N;\n  vector<mint> A(1 << N); for\
    \ (int i = 0; i < 1 << N; i++) cin >> A[i];\n  vector<mint> B(1 << N); for (int\
    \ i = 0; i < 1 << N; i++) cin >> B[i];\n\n  // A\u3092\u4E0A\u4F4D\u96C6\u5408\
    \u306B\u3064\u3044\u3066\u306E\u30BC\u30FC\u30BF\u5909\u63DB\u3059\u308B\n  vector<mint>\
    \ AZ = superset_zeta_transform<mint,op>(A);\n  // B\u3092\u4E0A\u4F4D\u96C6\u5408\
    \u306B\u3064\u3044\u3066\u30BC\u30FC\u30BF\u5909\u63DB\u3059\u308B\n  vector<mint>\
    \ BZ = superset_zeta_transform<mint,op>(B);\n\n  vector<mint>C(1 << N); for (int\
    \ i = 0; i < 1 << N; i++) C[i] = AZ[i] * BZ[i];\n  // C\u3092\u4E0A\u4F4D\u96C6\
    \u5408\u306B\u3064\u3044\u3066\u306E\u30E1\u30D3\u30A6\u30B9\u5909\u63DB\u3059\
    \u308B\u3002\n  vector<mint>CZ = superset_moebius_transform<mint,invop>(C);\n\
    \  for (int i = 0; i < 1 << N; i++) cout << CZ[i].val() << \" \\n\"[i == (1 <<\
    \ N) - 1];\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/bitwise_and_convolution\"\
    \n\n#include \"template/template.hpp\"\n#include \"math/modint.hpp\"\n#include\
    \ \"convolution/superset-zeta-moebius-transform.hpp\"\n\nusing mint = modint998244353;\n\
    \nmint op(mint a, mint b) {\n  return a + b;\n}\n\nmint invop(mint a, mint b)\
    \ {\n  return a - b;\n}\n\nint main() {\n  ios::sync_with_stdio(0); cin.tie(0);\
    \ cout.tie(0);\n  int N; cin >> N;\n  vector<mint> A(1 << N); for (int i = 0;\
    \ i < 1 << N; i++) cin >> A[i];\n  vector<mint> B(1 << N); for (int i = 0; i <\
    \ 1 << N; i++) cin >> B[i];\n\n  // A\u3092\u4E0A\u4F4D\u96C6\u5408\u306B\u3064\
    \u3044\u3066\u306E\u30BC\u30FC\u30BF\u5909\u63DB\u3059\u308B\n  vector<mint> AZ\
    \ = superset_zeta_transform<mint,op>(A);\n  // B\u3092\u4E0A\u4F4D\u96C6\u5408\
    \u306B\u3064\u3044\u3066\u30BC\u30FC\u30BF\u5909\u63DB\u3059\u308B\n  vector<mint>\
    \ BZ = superset_zeta_transform<mint,op>(B);\n\n  vector<mint>C(1 << N); for (int\
    \ i = 0; i < 1 << N; i++) C[i] = AZ[i] * BZ[i];\n  // C\u3092\u4E0A\u4F4D\u96C6\
    \u5408\u306B\u3064\u3044\u3066\u306E\u30E1\u30D3\u30A6\u30B9\u5909\u63DB\u3059\
    \u308B\u3002\n  vector<mint>CZ = superset_moebius_transform<mint,invop>(C);\n\
    \  for (int i = 0; i < 1 << N; i++) cout << CZ[i].val() << \" \\n\"[i == (1 <<\
    \ N) - 1];\n}"
  dependsOn:
  - template/template.hpp
  - math/modint.hpp
  - math/external_gcd.hpp
  - convolution/superset-zeta-moebius-transform.hpp
  isVerificationFile: true
  path: test/verify/convolution/yosupo-and-convolution.test.cpp
  requiredBy: []
  timestamp: '2024-06-20 21:09:39+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/verify/convolution/yosupo-and-convolution.test.cpp
layout: document
redirect_from:
- /verify/test/verify/convolution/yosupo-and-convolution.test.cpp
- /verify/test/verify/convolution/yosupo-and-convolution.test.cpp.html
title: test/verify/convolution/yosupo-and-convolution.test.cpp
---
