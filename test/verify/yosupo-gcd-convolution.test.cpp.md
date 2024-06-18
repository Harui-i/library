---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: convolution/divisor-multiple-zeta-moebius-transform.hpp
    title: "\u500D\u6570/\u7D04\u6570\u95A2\u4FC2\u306B\u3064\u3044\u3066\u306E\u30BC\
      \u30FC\u30BF\u5909\u63DB/\u30E1\u30D3\u30A6\u30B9\u5909\u63DB"
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
    PROBLEM: https://judge.yosupo.jp/problem/gcd_convolution
    links:
    - https://judge.yosupo.jp/problem/gcd_convolution
  bundledCode: "#line 1 \"test/verify/yosupo-gcd-convolution.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/gcd_convolution\"\n\n#line 1 \"template/template.hpp\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\ntypedef long long ll;\ntypedef\
    \ unsigned int uint;\ntemplate<class T> inline bool chmax(T& a, const T& b) {if\
    \ (a<b) {a=b; return true;} return false;}\ntemplate<class T> inline bool chmin(T&\
    \ a, const T& b) {if (b<a) {a=b; return true;} return false;}\nconst int INTINF\
    \ = 1000001000;\nconst int INTMAX = 2147483647;\nconst ll LLMAX = 9223372036854775807;\n\
    const ll LLINF = 1000000000000000000;\n#line 1 \"math/modint.hpp\"\n\n\n\ntemplate<int\
    \ MOD>\nstruct static_modint {\n    int value;\n\n    constexpr static_modint()\
    \ : value(0) {}\n\n    constexpr static_modint(long long v) {\n        value =\
    \ int(((v % MOD) + MOD) % MOD);\n    }\n\n    constexpr static_modint& operator+=(const\
    \ static_modint& other) {\n        if ((value += other.value) >= MOD) value -=\
    \ MOD;\n        return *this;\n    }\n\n    constexpr static_modint& operator-=(const\
    \ static_modint& other) {\n        if ((value -= other.value) < 0) value += MOD;\n\
    \        return *this;\n    }\n\n    constexpr static_modint& operator*=(const\
    \ static_modint& other) {\n        value = int((long long)value * other.value\
    \ % MOD);\n        return *this;\n    }\n\n    constexpr static_modint operator+(const\
    \ static_modint& other) const {\n        return static_modint(*this) += other;\n\
    \    }\n\n    constexpr static_modint operator-(const static_modint& other) const\
    \ {\n        return static_modint(*this) -= other;\n    }\n\n    constexpr static_modint\
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
    \  = modint<998244353>;\nusing modint1000000007 = modint<1000000007>;\n\n\n#line\
    \ 1 \"convolution/divisor-multiple-zeta-moebius-transform.hpp\"\n\n\n\n#line 5\
    \ \"convolution/divisor-multiple-zeta-moebius-transform.hpp\"\n\nnamespace multiple\
    \ {\n\n  // \u500D\u6570\u306B\u3064\u3044\u3066\u306E\u30BC\u30FC\u30BF\u5909\
    \u63DB\u3002 g_n = \\Sigma_{n|m} f_m \u306A\u308B g \u3092\u6C42\u3081\u308B\u3002\
    \n  // n|m\u3068\u3044\u3046\u306E\u306F\u3001m%n==0\u3068\u3044\u3046\u610F\u5473\
    \u3002\n  // O(N log N) (\u8ABF\u548C\u7D1A\u6570)\n  // \u3046\u307E\u304F\u3084\
    \u308B\u3068O(Nlog(log(N)))\u306B\u3067\u304D\u308B\u3053\u3068\u304C\u3088\u304F\
    \u77E5\u3089\u308C\u3066\u3044\u308B\u304C\u3001\u96E3\u3057\u3044\u3057log\u306F\
    \u5B9A\u6570\u306A\u306E\u3067\u59A5\u5354\u3059\u308B\u3002\n  template <typename\
    \ T>\n  std::vector<T> zeta_transform_naive(const std::vector<T>& f) {\n    int\
    \ N = f.size()-1;\n    std::vector<T> g = f;\n    for (int i=1; i<=N; i++) {\n\
    \      for (int j=2*i; j<=N; j+=i) {\n        g[i] += f[j];\n      }\n    }\n\n\
    \    return g;\n  }\n\n  // \u500D\u6570\u306B\u3064\u3044\u3066\u306E\u30E1\u30D3\
    \u30A6\u30B9\u5909\u63DB\n  // f_n = \\Sigma_{n|m} g_m \u306A\u308B g \u3092\u6C42\
    \u3081\u308B\u3002\n  // O(N log N) (\u8ABF\u548C\u7D1A\u6570)\n  template <typename\
    \ T>\n  std::vector<T> moebius_transform_naive(const std::vector<T>& f) {\n  \
    \  int N = f.size()-1;\n    std::vector<T> g = f;\n    for (int i=N; i>=1; i--)\
    \ {\n      for (int j=2*i; j<=N; j+=i) {\n        g[i] -= g[j];\n      }\n   \
    \ }\n    return g;\n  }\n\n}\n\n\n\n#line 6 \"test/verify/yosupo-gcd-convolution.test.cpp\"\
    \n\nusing mint = modint998244353;\n\nint main() {\n  ios::sync_with_stdio(0);\
    \ cin.tie(0); cout.tie(0);\n  int N; cin >> N;\n  vector<mint>a(N+1); for(int\
    \ i=0; i<N; i++) cin >> a[i+1];\n  vector<mint>b(N+1); for(int i=0; i<N; i++)\
    \ cin >> b[i+1];  \n\n  vector<mint> za = multiple::zeta_transform_naive(a);\n\
    \  vector<mint> zb = multiple::zeta_transform_naive(b);\n\n  vector<mint> zc(N+1);\
    \ for(int i=0; i<N+1; i++) zc[i] = za[i] * zb[i];\n\n  vector<mint> c = multiple::moebius_transform_naive(zc);\n\
    \  for(int i=1; i<=N; i++) cout << c[i].val() << \" \\n\"[i==N];\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/gcd_convolution\"\n\n#include\
    \ \"template/template.hpp\"\n#include \"math/modint.hpp\"\n#include \"convolution/divisor-multiple-zeta-moebius-transform.hpp\"\
    \n\nusing mint = modint998244353;\n\nint main() {\n  ios::sync_with_stdio(0);\
    \ cin.tie(0); cout.tie(0);\n  int N; cin >> N;\n  vector<mint>a(N+1); for(int\
    \ i=0; i<N; i++) cin >> a[i+1];\n  vector<mint>b(N+1); for(int i=0; i<N; i++)\
    \ cin >> b[i+1];  \n\n  vector<mint> za = multiple::zeta_transform_naive(a);\n\
    \  vector<mint> zb = multiple::zeta_transform_naive(b);\n\n  vector<mint> zc(N+1);\
    \ for(int i=0; i<N+1; i++) zc[i] = za[i] * zb[i];\n\n  vector<mint> c = multiple::moebius_transform_naive(zc);\n\
    \  for(int i=1; i<=N; i++) cout << c[i].val() << \" \\n\"[i==N];\n}"
  dependsOn:
  - template/template.hpp
  - math/modint.hpp
  - convolution/divisor-multiple-zeta-moebius-transform.hpp
  isVerificationFile: true
  path: test/verify/yosupo-gcd-convolution.test.cpp
  requiredBy: []
  timestamp: '2024-06-18 18:48:26+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/verify/yosupo-gcd-convolution.test.cpp
layout: document
redirect_from:
- /verify/test/verify/yosupo-gcd-convolution.test.cpp
- /verify/test/verify/yosupo-gcd-convolution.test.cpp.html
title: test/verify/yosupo-gcd-convolution.test.cpp
---
