---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: convolution/divisor-zeta-moebius-transform.hpp
    title: "\u7D04\u6570\u306B\u3064\u3044\u3066\u306E\u30BC\u30FC\u30BF\u5909\u63DB\
      /\u30E1\u30D3\u30A6\u30B9\u5909\u63DB"
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
    PROBLEM: https://judge.yosupo.jp/problem/lcm_convolution
    links:
    - https://judge.yosupo.jp/problem/lcm_convolution
  bundledCode: "#line 1 \"test/verify/convolution/yosupo-lcm-convolution.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/lcm_convolution\"\n\n#line\
    \ 1 \"template/template.hpp\"\n#include <bits/stdc++.h>\nusing namespace std;\n\
    typedef long long ll;\ntypedef unsigned int uint;\ntemplate<class T> inline bool\
    \ chmax(T& a, const T& b) {if (a<b) {a=b; return true;} return false;}\ntemplate<class\
    \ T> inline bool chmin(T& a, const T& b) {if (b<a) {a=b; return true;} return\
    \ false;}\nconst int INTINF = 1000001000;\nconst int INTMAX = 2147483647;\nconst\
    \ ll LLMAX = 9223372036854775807;\nconst ll LLINF = 1000000000000000000;\n#line\
    \ 1 \"math/modint.hpp\"\n\n\n\ntemplate<int MOD>\nstruct static_modint {\n   \
    \ int value;\n\n    constexpr static_modint() : value(0) {}\n\n    constexpr static_modint(long\
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
    using modint998244353  = modint<998244353>;\nusing modint1000000007 = modint<1000000007>;\n\
    \n\n#line 1 \"convolution/divisor-zeta-moebius-transform.hpp\"\n\n\n\n#line 5\
    \ \"convolution/divisor-zeta-moebius-transform.hpp\"\n\nnamespace divisor {\n\
    \  // \u7D04\u6570\u306B\u3064\u3044\u3066\u306E\u30BC\u30FC\u30BF\u5909\u63DB\
    \u3002 g_n = \\Sigma_{m|n} f_m \u306A\u308B g \u3092\u6C42\u3081\u308B\u3002\n\
    \  template <typename T>\n  std::vector<T> zeta_transform_naive(const std::vector<T>&\
    \ f) {\n    int N = f.size() - 1;\n    std::vector<T> g = f;\n\n    for(int i=1;\
    \ i<=N; i++) {\n      for(int j=2*i; j<=N; j+=i) {\n        g[j] += f[i];\n  \
    \    }\n    }\n\n    return g;\n  }\n\n  // \u7D04\u6570\u306B\u3064\u3044\u3066\
    \u306E\u30E1\u30D3\u30A6\u30B9\u5909\u63DB\u3002 f_n = \\Sigma_{m|n} g_m \u306A\
    \u308B g \u3092\u6C42\u3081\u308B\u3002\n  template <typename T>\n  std::vector<T>\
    \ moebius_transform_naive(const std::vector<T>& f) {\n    int N = f.size() - 1;\n\
    \    std::vector<T> g = f;\n\n    for (int i=1; i<=N; i++) {\n      for (int j=i*2;\
    \ j<= N; j+=i) {\n        g[j] -= g[i];\n      }\n    }\n\n    return g;\n  }\n\
    }\n\n\n\n#line 6 \"test/verify/convolution/yosupo-lcm-convolution.test.cpp\"\n\
    \nusing mint = modint998244353;\n\nint main() {\n  ios::sync_with_stdio(0); cin.tie(0);\
    \ cout.tie(0);\n  int N; cin >> N;\n  vector<mint>a(N+1); for(int i=0; i<N; i++)\
    \ cin >> a[i+1];\n  vector<mint>b(N+1); for(int i=0; i<N; i++) cin >> b[i+1];\
    \  \n\n  vector<mint> za = divisor::zeta_transform_naive(a);\n  vector<mint> zb\
    \ = divisor::zeta_transform_naive(b);\n\n  vector<mint> zc(N+1); for(int i=0;\
    \ i<N+1; i++) zc[i] = za[i] * zb[i];\n\n  vector<mint> c = divisor::moebius_transform_naive(zc);\n\
    \  for(int i=1; i<=N; i++) cout << c[i].val() << \" \\n\"[i==N];\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/lcm_convolution\"\n\n#include\
    \ \"template/template.hpp\"\n#include \"math/modint.hpp\"\n#include \"convolution/divisor-zeta-moebius-transform.hpp\"\
    \n\nusing mint = modint998244353;\n\nint main() {\n  ios::sync_with_stdio(0);\
    \ cin.tie(0); cout.tie(0);\n  int N; cin >> N;\n  vector<mint>a(N+1); for(int\
    \ i=0; i<N; i++) cin >> a[i+1];\n  vector<mint>b(N+1); for(int i=0; i<N; i++)\
    \ cin >> b[i+1];  \n\n  vector<mint> za = divisor::zeta_transform_naive(a);\n\
    \  vector<mint> zb = divisor::zeta_transform_naive(b);\n\n  vector<mint> zc(N+1);\
    \ for(int i=0; i<N+1; i++) zc[i] = za[i] * zb[i];\n\n  vector<mint> c = divisor::moebius_transform_naive(zc);\n\
    \  for(int i=1; i<=N; i++) cout << c[i].val() << \" \\n\"[i==N];\n}"
  dependsOn:
  - template/template.hpp
  - math/modint.hpp
  - convolution/divisor-zeta-moebius-transform.hpp
  isVerificationFile: true
  path: test/verify/convolution/yosupo-lcm-convolution.test.cpp
  requiredBy: []
  timestamp: '2024-06-19 18:06:38+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/verify/convolution/yosupo-lcm-convolution.test.cpp
layout: document
redirect_from:
- /verify/test/verify/convolution/yosupo-lcm-convolution.test.cpp
- /verify/test/verify/convolution/yosupo-lcm-convolution.test.cpp.html
title: test/verify/convolution/yosupo-lcm-convolution.test.cpp
---
