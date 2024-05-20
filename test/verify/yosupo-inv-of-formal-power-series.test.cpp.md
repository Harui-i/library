---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: formal-power-series/formal-power-series.hpp
    title: "Formal Power Series (\u5F62\u5F0F\u7684\u3079\u304D\u7D1A\u6570)"
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
    PROBLEM: https://judge.yosupo.jp/problem/inv_of_formal_power_series
    links:
    - https://judge.yosupo.jp/problem/inv_of_formal_power_series
  bundledCode: "#line 1 \"test/verify/yosupo-inv-of-formal-power-series.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/inv_of_formal_power_series\"\
    \n\n#line 1 \"template/template.hpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\ntypedef long long ll;\ntypedef unsigned int uint;\ntemplate<class T> inline\
    \ bool chmax(T& a, const T& b) {if (a<b) {a=b; return true;} return false;}\n\
    template<class T> inline bool chmin(T& a, const T& b) {if (b<a) {a=b; return true;}\
    \ return false;}\nconst int INTINF = 1000001000;\nconst int INTMAX = 2147483647;\n\
    const ll LLMAX = 9223372036854775807;\nconst ll LLINF = 1000000000000000000;\n\
    #line 2 \"math/modint.hpp\"\n\ntemplate<int MOD>\nstruct static_modint {\n   \
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
    using modint998244353 = modint<998244353>;\nusing modint100000007 = modint<100000007>;\n\
    #line 2 \"formal-power-series/formal-power-series.hpp\"\n\n#line 5 \"formal-power-series/formal-power-series.hpp\"\
    \n\nusing namespace std;\nusing mint = modint998244353;\n\n//ZETAS = {1,998244352,911660635,372528824,929031873,452798380,922799308,781712469,476477967,166035806,258648936,584193783,63912897,350007156,666702199,968855178,629671588,24514907,996173970,363395222,565042129,733596141,267099868,15311432};\n\
    // constexpr \u95A2\u6570\u5185\u3067 ZETAS \u914D\u5217\u3092\u8A2D\u5B9A\u3059\
    \u308B\u305F\u3081\u306E\u88DC\u52A9\u95A2\u6570\nconstexpr std::array<mint, 24>\
    \ setup_zetas() {\n  std::array<mint, 24> zetas;\n  zetas[23] = mint(3).pow(119);\n\
    \  for (int i = 22; i >= 0; --i) {\n    zetas[i] = (zetas[i + 1] * zetas[i + 1]);\n\
    \  }\n  return zetas;\n}\n\n// \u30B3\u30F3\u30D1\u30A4\u30EB\u6642\u306B ZETAS\
    \ \u914D\u5217\u3092\u521D\u671F\u5316\nconstexpr array<mint, 24> ZETAS = setup_zetas();\n\
    struct FPS {\n  vector<mint> _vec;\n\n  constexpr int lg2(int N) const {\n   \
    \ int ret = 0;\n    if ( N > 0) ret = 31 - __builtin_clz(N);\n    if ((1LL <<\
    \ ret) < N) ret++;\n    return ret;\n  }\n\n  // \u53C2\u8003: https://www.creativ.xyz/fast-fourier-transform/\n\
    \  void CooleyTukeyNTT998244353(vector<mint>& a, bool is_reverse) const {\n  \
    \  int N = a.size();\n    int lgN = lg2(N);\n    //for (int i = 0; 1 << i < N;\
    \ i++) lgN++;\n    assert(N == 1 << lgN);\n\n    for (int i = 0; i < N; i++) {\n\
    \      int j = 0;\n      for (int k = 0; k < lgN; k++) j |= (i >> k & 1) << (lgN\
    \ - 1 - k);\n      if (i < j) swap(a[i], a[j]);\n    }\n\n    int lgb = -1;\n\
    \    for (int b = 1; b < N; b *= 2) {\n      lgb++;\n      mint mpzeta = ZETAS[lgb\
    \ + 1];\n      if (is_reverse) mpzeta = mpzeta.inv();\n      mint zeta = 1;\n\n\
    \      for (int j = 0; j < b; j++) {\n        for (int k = 0; k < N; k += b *\
    \ 2) {\n          mint s = a[j + k];\n          mint t = (a[j + k + b] * zeta);\n\
    \          a[j + k] = (s + t);\n          a[j + k + b] = (s - t);\n        }\n\
    \        zeta *= mpzeta;\n      }\n    }\n    if (is_reverse) {\n      mint size_inv\
    \ = mint(N).inv();\n      for (int i = 0; i < N; i++) {\n        a[i] *= size_inv;\n\
    \      }\n    }\n  }\n\n\n  vector<mint> multiply(vector<mint> const& a, vector<mint>\
    \ const& b) {\n    vector<mint> fa(a.begin(), a.end()), fb(b.begin(), b.end());\n\
    \    int n = 1 << lg2(a.size() + b.size());\n    //while (n < (int)(a.size() +\
    \ b.size())) n <<= 1;\n\n    fa.resize(n);\n    fb.resize(n);\n\n    vector<mint>fc(n);\n\
    \    if (min(a.size(), b.size()) <= 40) {\n      for (int i = 0; i < (int)a.size();\
    \ i++) for (int j = 0; j < (int)b.size(); j++) fc[i + j] += fa[i] * fb[j];\n \
    \   }\n    else {\n      CooleyTukeyNTT998244353(fa, false);\n      CooleyTukeyNTT998244353(fb,\
    \ false);\n      for (int i = 0; i < n; ++i) fc[i] = fa[i] * fb[i];\n      CooleyTukeyNTT998244353(fc,\
    \ true);\n    }\n    fc.resize(a.size() + b.size() - 1);\n    return fc;\n  }\n\
    \n  // \u30CA\u30A4\u30FC\u30D6\u306A\u30CB\u30E5\u30FC\u30C8\u30F3\u6CD5\u3067\
    \u306E\u9006\u5143\u8A08\u7B97\n  FPS inv_naive(int deg) const {\n    assert(_vec[0]\
    \ != mint(0)); // \u3055\u3042\u3089\u3056\u308C\u3070\u3001\u9006\u5143\u306E\
    \u3066\u3072\u304E\u3044\u304D\u306B\u3053\u305D\u3042\u3089\u3056\u308C\u3002\
    \n    if (deg == -1) deg = this->size();\n    FPS g(1);\n    g._vec[0] = mint(_vec[0]).inv();\n\
    \    // g_{n+1} = 2 * g_n - f * (g_n)^2\n    for (int d=1; d < deg; d <<= 1) {\n\
    \      FPS g_twice = g * mint(2);\n      FPS fgg = (*this).pre(d*2) * g * g;\n\
    \      \n      g = g_twice - fgg;\n      g.resize(d*2);\n    }\n\n    return g.pre(deg);\n\
    \  }\n\n  // FFT\u306E\u56DE\u6570\u3092\u7BC0\u7D04\u3057\u305FNewton\u6CD5\u3067\
    \u306E\u9006\u5143\u8A08\u7B97\n  FPS inv_fast1(int deg) const {\n    assert(_vec[0]\
    \ != mint(0));\n    if (deg == -1) deg = size();\n    FPS g(1);\n    g._vec[0]\
    \ = mint(_vec[0]).inv();\n\n    for(int d=1; d<deg; d <<= 1) {\n      FPS g_squared\
    \ = g;\n      FPS g_twice = g * mint(2);\n\n      g_squared.resize(d*4);\n   \
    \   CooleyTukeyNTT998244353(g_squared._vec, false);\n      for(int i=0; i<g_squared.size();\
    \ i++) g_squared._vec[i] *= g_squared._vec[i];\n\n      FPS fgg = (*this).pre(d*2);\n\
    \      fgg.resize(d*4);\n      CooleyTukeyNTT998244353(fgg._vec, false);\n\n \
    \     for(int i=0; i<fgg.size(); i++) {\n        fgg._vec[i] *= g_squared._vec[i];\n\
    \      }\n      CooleyTukeyNTT998244353(fgg._vec, true);\n      fgg.resize(d*4\
    \ - 2);\n\n      g = (g_twice - fgg); \n      g.resize(d*2);\n    }\n\n    return\
    \ g.pre(deg);\n  }\n\n  FPS(vector<mint> vec) {\n    _vec = vec;\n  }\n\n  FPS(initializer_list<mint>\
    \ ilist) {\n    _vec = ilist;\n  }\n\n  // \u9805\u306E\u6570\u306B\u63C3\u3048\
    \u305F\u307B\u3046\u304C\u3088\u3055\u305D\u3046\n  FPS(int sz) {\n    _vec.resize(sz);\n\
    \  }\n\n  int size() const {\n    return _vec.size();\n  }\n\n  FPS& operator+=(const\
    \ FPS& rhs) {\n    if (rhs.size() > this->size()) _vec.resize(rhs.size());\n \
    \   for (int i = 0; i < (int)rhs.size(); ++i) _vec[i] += rhs._vec[i];\n    return\
    \ *this;\n  }\n\n  FPS& operator-=(const FPS& rhs) {\n    if (rhs.size() > this->size())\
    \ this->_vec.resize(rhs.size());\n    for (int i = 0; i < (int)rhs.size(); ++i)\
    \ _vec[i] -= rhs._vec[i];\n    return *this;\n  }\n\n  FPS& operator*=(const FPS&\
    \ rhs) {\n    _vec = multiply(_vec, rhs._vec);\n    return *this;\n  }\n\n  FPS&\
    \ operator*=(const mint& rhs) {\n    for(int i=0; i<size(); i++) _vec[i] *= rhs;\n\
    \    return *this;\n  }\n\n  FPS& operator/=(const mint& rhs) {\n    for(int i=0;\
    \ i<size(); i++) _vec[i] *= rhs.inv();\n    return *this;\n  }\n\n  FPS operator>>(int\
    \ sz) const {\n    if ((int)this->size() <= sz) return {};\n    FPS ret(*this);\n\
    \    ret._vec.erase(ret._vec.begin(), ret._vec.begin() + sz);\n    return ret;\n\
    \  }\n\n  FPS operator<<(int sz) const {\n    FPS ret(*this);\n    ret._vec.insert(ret._vec.begin(),\
    \ sz, mint(0));\n\n    return ret;\n  }\n\n  friend FPS operator+(FPS a, const\
    \ FPS& b) { return a += b; }\n  friend FPS operator-(FPS a, const FPS& b) { return\
    \ a -= b; }\n  friend FPS operator*(FPS a, const FPS& b) { return a *= b; }\n\n\
    \  friend FPS operator*(FPS a, const mint& b) {return a *= b; }\n  friend FPS\
    \ operator/(FPS a, const mint& b) {return a /= b; }\n\n  FPS pre(int sz) const\
    \ {\n    FPS ret = *this; \n    ret._vec.resize(sz);\n\n    return ret;\n  }\n\
    \n  void resize(int sz)  {\n    this->_vec.resize(sz);\n  }\n\n  friend ostream&\
    \ operator<<(ostream& os, const FPS& fps) {\n    for (int i = 0; i < fps.size();\
    \ ++i) {\n      if (i > 0) os << \" \";\n      os << fps._vec[i];\n    }\n   \
    \ return os;\n  }\n};\n#line 6 \"test/verify/yosupo-inv-of-formal-power-series.test.cpp\"\
    \n\nusing mint = modint998244353;\n\n\nint main() {\n  ios::sync_with_stdio(0);\
    \ cin.tie(0); cout.tie(0);\n  int N; cin >> N;\n  vector<modint998244353>a(N);\n\
    \  for(int i=0; i<N; i++) cin >> a[i];\n\n  FPS a_fps(a);\n  cout << a_fps.inv_fast1(N)\
    \ << endl;\n\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/inv_of_formal_power_series\"\
    \n\n#include \"../../template/template.hpp\"\n#include \"../../math/modint.hpp\"\
    \n#include \"../../formal-power-series/formal-power-series.hpp\"\n\nusing mint\
    \ = modint998244353;\n\n\nint main() {\n  ios::sync_with_stdio(0); cin.tie(0);\
    \ cout.tie(0);\n  int N; cin >> N;\n  vector<modint998244353>a(N);\n  for(int\
    \ i=0; i<N; i++) cin >> a[i];\n\n  FPS a_fps(a);\n  cout << a_fps.inv_fast1(N)\
    \ << endl;\n\n}\n"
  dependsOn:
  - template/template.hpp
  - math/modint.hpp
  - formal-power-series/formal-power-series.hpp
  isVerificationFile: true
  path: test/verify/yosupo-inv-of-formal-power-series.test.cpp
  requiredBy: []
  timestamp: '2024-05-21 00:13:35+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/verify/yosupo-inv-of-formal-power-series.test.cpp
layout: document
redirect_from:
- /verify/test/verify/yosupo-inv-of-formal-power-series.test.cpp
- /verify/test/verify/yosupo-inv-of-formal-power-series.test.cpp.html
title: test/verify/yosupo-inv-of-formal-power-series.test.cpp
---
