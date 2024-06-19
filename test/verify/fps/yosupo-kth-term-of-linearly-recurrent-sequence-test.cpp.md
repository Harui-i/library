---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: formal-power-series/fiduccia.hpp
    title: formal-power-series/fiduccia.hpp
  - icon: ':heavy_check_mark:'
    path: formal-power-series/formal-power-series.hpp
    title: "Formal Power Series (\u5F62\u5F0F\u7684\u3079\u304D\u7D1A\u6570)"
  - icon: ':heavy_check_mark:'
    path: formal-power-series/fps998.hpp
    title: formal-power-series/fps998.hpp
  - icon: ':heavy_check_mark:'
    path: math/modint.hpp
    title: modint
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
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://judge.yosupo.jp/problem/kth_term_of_linearly_recurrent_sequence
  bundledCode: "#line 1 \"test/verify/fps/yosupo-kth-term-of-linearly-recurrent-sequence-test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/kth_term_of_linearly_recurrent_sequence\"\
    \n\n#line 1 \"template/template.hpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\ntypedef long long ll;\ntypedef unsigned int uint;\ntemplate<class T> inline\
    \ bool chmax(T& a, const T& b) {if (a<b) {a=b; return true;} return false;}\n\
    template<class T> inline bool chmin(T& a, const T& b) {if (b<a) {a=b; return true;}\
    \ return false;}\nconst int INTINF = 1000001000;\nconst int INTMAX = 2147483647;\n\
    const ll LLMAX = 9223372036854775807;\nconst ll LLINF = 1000000000000000000;\n\
    #line 1 \"math/modint.hpp\"\n\n\n\ntemplate<int MOD>\nstruct static_modint {\n\
    \    int value;\n\n    constexpr static_modint() : value(0) {}\n\n    constexpr\
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
    \  = modint<998244353>;\nusing modint1000000007 = modint<1000000007>;\n\n\n#line\
    \ 1 \"formal-power-series/formal-power-series.hpp\"\n\n\n\n#line 6 \"formal-power-series/formal-power-series.hpp\"\
    \n\nusing namespace std;\n\n\n\ntemplate <typename mint>\nstruct FPS {\n  vector<mint>\
    \ _vec;\n\n  constexpr int lg2(int N) const {\n    int ret = 0;\n    if ( N >\
    \ 0) ret = 31 - __builtin_clz(N);\n    if ((1LL << ret) < N) ret++;\n    return\
    \ ret;\n  }\n\n  // \u30CA\u30A4\u30FC\u30D6\u306A\u30CB\u30E5\u30FC\u30C8\u30F3\
    \u6CD5\u3067\u306E\u9006\u5143\u8A08\u7B97\n  FPS inv_naive(int deg) const {\n\
    \    assert(_vec[0] != mint(0)); // \u3055\u3042\u3089\u3056\u308C\u3070\u3001\
    \u9006\u5143\u306E\u3066\u3072\u304E\u3044\u304D\u306B\u3053\u305D\u3042\u3089\
    \u3056\u308C\u3002\n    if (deg == -1) deg = this->size();\n    FPS g(1);\n  \
    \  g._vec[0] = mint(_vec[0]).inv();\n    // g_{n+1} = 2 * g_n - f * (g_n)^2\n\
    \    for (int d=1; d < deg; d <<= 1) {\n      FPS g_twice = g * mint(2);\n   \
    \   FPS fgg = (*this).pre(d*2) * g * g;\n     \n      g = g_twice - fgg;\n   \
    \   g.resize(d*2);\n    }\n\n    return g.pre(deg);\n  }\n\n  //*/\n\n  FPS log(int\
    \ deg=-1) const {\n    assert(_vec[0] == mint(1));\n\n    if (deg == -1) deg =\
    \ size();\n    FPS df = this->diff();\n    FPS iv = this->inv(deg);\n    FPS ret\
    \ = (df * iv).pre(deg-1).integral();\n\n    return ret;\n  }\n\n  FPS exp(int\
    \ deg=-1) const {\n    assert(_vec[0] == mint(0));\n\n    if (deg == -1) deg =\
    \ size();\n    FPS g(1);\n    g[0] = 1;\n    for (int d=1; d<deg; d <<= 1) {\n\
    \      // g_2d = g_d * (f(x) + 1 - log(g_d))\n      FPS fpl1 = (*this + mint(1)).pre(2*d);\n\
    \      FPS logg = g.log(2*d);\n      FPS right = (fpl1 - logg);\n\n      g = (g\
    \ * right).pre(2*d);\n    }\n\n    return g.pre(deg);\n  }\n\n  FPS integral()\
    \ const {\n    const int N = size();\n    FPS ret(N+1);\n\n    for(int i=0; i<N;\
    \ i++) ret[i+1] = _vec[i] * mint(i+1).inv();\n\n    return ret;\n  }\n\n  FPS\
    \ diff() const {\n    const int N = size();\n    FPS ret(max(0, N-1));\n    for(int\
    \ i=1; i<N; i++) ret[i-1] = mint(i) * _vec[i];\n\n    return ret;\n  }\n\n  FPS(vector<mint>\
    \ vec) : _vec(vec) {\n  }\n\n  FPS(initializer_list<mint> ilist) : _vec(ilist)\
    \ {\n  }\n\n  // \u9805\u306E\u6570\u306B\u63C3\u3048\u305F\u307B\u3046\u304C\u3088\
    \u3055\u305D\u3046\n  FPS(int sz) : _vec(vector<mint>(sz)) {\n  }\n\n  int size()\
    \ const {\n    return _vec.size();\n  }\n\n  FPS& operator+=(const FPS& rhs) {\n\
    \    if (rhs.size() > this->size()) _vec.resize(rhs.size());\n    for (int i =\
    \ 0; i < (int)rhs.size(); ++i) _vec[i] += rhs._vec[i];\n    return *this;\n  }\n\
    \n  FPS& operator-=(const FPS& rhs) {\n    if (rhs.size() > this->size()) this->_vec.resize(rhs.size());\n\
    \    for (int i = 0; i < (int)rhs.size(); ++i) _vec[i] -= rhs._vec[i];\n    return\
    \ *this;\n  }\n\n  FPS& operator*=(const FPS& rhs) {\n    _vec = multiply(_vec,\
    \ rhs._vec);\n    return *this;\n  }\n\n  // Nyaan\u5148\u751F\u306E\u30E9\u30A4\
    \u30D6\u30E9\u30EA\u3092\u5927\u5199\u7D4C....\n  FPS& operator/=(const FPS& rhs)\
    \ {\n    if (size() < rhs.size()) {\n      return *this =  FPS(0);\n    }\n  \
    \  int sz = size() - rhs.size() + 1;\n//\n//    FPS left = (*this).rev().pre(sz);\n\
    //    FPS right = rhs.rev();\n//    right = right.inv(sz);\n//    FPS mp = left*right;\n\
    //    mp = mp.pre(sz);\n//    mp = mp.rev();\n//    return *this = mp;\n//   \
    \ return *this = (left * right).pre(sz).rev();\n    return *this =  ((*this).rev().pre(sz)\
    \ * rhs.rev().inv(sz)).pre(sz).rev();\n  }\n\n  FPS& operator%=(const FPS &rhs)\
    \ {\n    *this -= *this / rhs * rhs;\n    shrink(); \n    return *this;\n  }\n\
    \n  FPS& operator+=(const mint& rhs) {\n    _vec[0] += rhs;\n    return *this;\n\
    \  }\n\n  FPS& operator-=(const mint& rhs) {\n    _vec[0] -= rhs;\n    return\
    \ *this;\n  }\n\n  FPS& operator*=(const mint& rhs) {\n    for(int i=0; i<size();\
    \ i++) _vec[i] *= rhs;\n    return *this;\n  }\n\n  FPS& operator/=(const mint&\
    \ rhs) {\n    for(int i=0; i<size(); i++) _vec[i] *= rhs.inv();\n    return *this;\n\
    \  }\n\n  FPS operator>>(int sz) const {\n    if ((int)this->size() <= sz) return\
    \ {};\n    FPS ret(*this);\n    ret._vec.erase(ret._vec.begin(), ret._vec.begin()\
    \ + sz);\n    return ret;\n  }\n\n  FPS operator<<(int sz) const {\n    FPS ret(*this);\n\
    \    ret._vec.insert(ret._vec.begin(), sz, mint(0));\n\n    return ret;\n  }\n\
    \n  friend FPS operator+(FPS a, const FPS& b) { return a += b; }\n  friend FPS\
    \ operator-(FPS a, const FPS& b) { return a -= b; }\n  friend FPS operator*(FPS\
    \ a, const FPS& b) { return a *= b; }\n  friend FPS operator/(FPS a, const FPS&\
    \ b) { return a /= b; }\n  friend FPS operator%(FPS a, const FPS& b) {return a\
    \ %= b; }\n\n  friend FPS operator+(FPS a, const mint& b) {return a += b; }\n\
    \  friend FPS operator-(FPS a, const mint& b) {return a -= b; }\n  friend FPS\
    \ operator*(FPS a, const mint& b) {return a *= b; }\n  friend FPS operator/(FPS\
    \ a, const mint& b) {return a /= b; }\n  \n  // sz\u6B21\u672A\u6E80\u306E\u9805\
    \u3092\u53D6\u3063\u3066\u304F\u308B\n  FPS pre(int sz) const {\n    FPS ret =\
    \ *this; \n    ret._vec.resize(sz);\n\n    return ret;\n  }\n\n  FPS rev() const\
    \ {\n    FPS ret = *this;\n    reverse(ret._vec.begin(), ret._vec.end());\n  \
    \  \n    return ret;\n  }\n\n  const mint& operator[](size_t i) const {\n    return\
    \ _vec[i];\n  }\n\n  mint& operator[](size_t i) {\n    return _vec[i];\n  }\n\n\
    \  void resize(int sz)  {\n    this->_vec.resize(sz);\n  }\n\n  void shrink()\
    \ {\n    while (size() > 0 && _vec.back() == mint(0)) _vec.pop_back();\n  }\n\n\
    \  friend ostream& operator<<(ostream& os, const FPS& fps) {\n    for (int i =\
    \ 0; i < fps.size(); ++i) {\n      if (i > 0) os << \" \";\n      os << fps._vec[i].val();\n\
    \    }\n    return os;\n  }\n\n  // \u4EEE\u60F3\u95A2\u6570\u3063\u3066\u3084\
    \u3064\u3002mod 998244353\u306A\u306E\u304B\u3001\u4ED6\u306ENTT-friendly\u306A\
    mod\u3067\u8003\u3048\u308B\u306E\u304B\u3001\u305D\u308C\u3068\u3082Garner\u3067\
    \u5FA9\u5143\u3059\u308B\u306E\u304B\u3001\u305D\u308C\u3068\u3082\u7573\u307F\
    \u8FBC\u307F\u3092$O(N^2)$\u3067\u59A5\u5354\u3059\u308B\u306E\u304B\u306A\u3069\
    \u306B\u3088\u3063\u3066\u7570\u306A\u308B\n  virtual FPS inv(int deg=-1) const;\n\
    \  virtual void CooleyTukeyNTT998244353(vector<mint>&a, bool is_reverse) const;\n\
    //  virtual FPS exp(int deg=-1) const;\n  virtual vector<mint> multiply(const\
    \ vector<mint>& a, const vector<mint>& b);\n  };\n\n\n#line 1 \"formal-power-series/fps998.hpp\"\
    \n\n\n\n\n#line 6 \"formal-power-series/fps998.hpp\"\n\nusing mint = modint998244353;\n\
    //ZETAS = {1,998244352,911660635,372528824,929031873,452798380,922799308,781712469,476477967,166035806,258648936,584193783,63912897,350007156,666702199,968855178,629671588,24514907,996173970,363395222,565042129,733596141,267099868,15311432};\n\
    // constexpr \u95A2\u6570\u5185\u3067 ZETAS \u914D\u5217\u3092\u8A2D\u5B9A\u3059\
    \u308B\u305F\u3081\u306E\u88DC\u52A9\u95A2\u6570\nconstexpr std::array<mint, 24>\
    \ setup_zetas() {\n  std::array<mint, 24> zetas;\n  zetas[23] = mint(3).pow(119);\n\
    \  for (int i = 22; i >= 0; --i) {\n    zetas[i] = (zetas[i + 1] * zetas[i + 1]);\n\
    \  }\n  return zetas;\n}\n\n// \u30B3\u30F3\u30D1\u30A4\u30EB\u6642\u306B ZETAS\
    \ \u914D\u5217\u3092\u521D\u671F\u5316\nconstexpr array<mint, 24> ZETAS = setup_zetas();\n\
    \n\n\n// \u53C2\u8003: https://www.creativ.xyz/fast-fourier-transform/\ntemplate\
    \ <typename mint>\nvoid FPS<mint>::CooleyTukeyNTT998244353(vector<mint>& a, bool\
    \ is_reverse) const {\n  int N = a.size();\n  int lgN = lg2(N);\n  //for (int\
    \ i = 0; 1 << i < N; i++) lgN++;\n  assert(N == 1 << lgN);\n\n  for (int i = 0;\
    \ i < N; i++) {\n    int j = 0;\n    for (int k = 0; k < lgN; k++) j |= (i >>\
    \ k & 1) << (lgN - 1 - k);\n    if (i < j) swap(a[i], a[j]);\n  }\n\n  int lgb\
    \ = -1;\n  for (int b = 1; b < N; b *= 2) {\n    lgb++;\n    mint mpzeta = ZETAS[lgb\
    \ + 1];\n    if (is_reverse) mpzeta = mpzeta.inv();\n    mint zeta = 1;\n\n  \
    \  for (int j = 0; j < b; j++) {\n      for (int k = 0; k < N; k += b * 2) {\n\
    \        mint s = a[j + k];\n        mint t = (a[j + k + b] * zeta);\n       \
    \ a[j + k] = (s + t);\n        a[j + k + b] = (s - t);\n      }\n      zeta *=\
    \ mpzeta;\n    }\n  }\n  if (is_reverse) {\n    mint size_inv = mint(N).inv();\n\
    \    for (int i = 0; i < N; i++) {\n      a[i] *= size_inv;\n    }\n  }\n}\n\n\
    template <typename mint>\nvector<mint> FPS<mint>::multiply(const vector<mint>&\
    \ a, const vector<mint>& b) {\n  if (a.size() == 0 || b.size() == 0) return vector<mint>();\n\
    \n  vector<mint> fa(a.begin(), a.end()), fb(b.begin(), b.end());\n  int n = 1\
    \ << lg2(a.size() + b.size());\n  //while (n < (int)(a.size() + b.size())) n <<=\
    \ 1;\n\n  fa.resize(n);\n  fb.resize(n);\n\n  vector<mint>fc(n);\n  if (min(a.size(),\
    \ b.size()) <= 40) {\n    for (int i = 0; i < (int)a.size(); i++) for (int j =\
    \ 0; j < (int)b.size(); j++) fc[i + j] += fa[i] * fb[j];\n  }\n  else {\n    CooleyTukeyNTT998244353(fa,\
    \ false);\n    CooleyTukeyNTT998244353(fb, false);\n    for (int i = 0; i < n;\
    \ ++i) fc[i] = fa[i] * fb[i];\n    CooleyTukeyNTT998244353(fc, true);\n  }\n \
    \ fc.resize(a.size() + b.size() - 1);\n  return fc;\n}\n\n\n// FFT\u306E\u56DE\
    \u6570\u3092\u7BC0\u7D04\u3057\u305FNewton\u6CD5\u3067\u306E\u9006\u5143\u8A08\
    \u7B97\n/* \ntemplate <typename mint>\nFPS<mint> FPS<mint>::inv_fast1(int deg\
    \ = -1) const {\n  assert(_vec[0] != mint(0));\n  if (deg == -1) deg = size();\n\
    \  FPS g(1);\n  g._vec[0] = mint(_vec[0]).inv();\n\n  for (int d = 1; d < deg;\
    \ d <<= 1) {\n    FPS g_squared = g;\n    FPS g_twice = g * mint(2);\n\n    g_squared.resize(d\
    \ * 4);\n    CooleyTukeyNTT998244353(g_squared._vec, false);\n    for (int i =\
    \ 0; i < g_squared.size(); i++) g_squared._vec[i] *= g_squared._vec[i];\n\n  \
    \  FPS fgg = (*this).FPS::pre(d * 2);\n    fgg.resize(d * 4);\n    CooleyTukeyNTT998244353(fgg._vec,\
    \ false);\n\n    for (int i = 0; i < fgg.size(); i++) {\n      fgg._vec[i] *=\
    \ g_squared._vec[i];\n    }\n    CooleyTukeyNTT998244353(fgg._vec, true);\n  \
    \  fgg.resize(d * 4 - 2);\n\n    g = (g_twice - fgg);\n    g.resize(d * 2);\n\
    \  }\n\n  return g.pre(deg);\n} \n*/\n\n// \u5DE1\u56DE\u7573\u307F\u8FBC\u307F\
    \u3092\u5229\u7528\u3057\u3066FFT\u306E\u56DE\u6570\u3092\u7BC0\u7D04\u3057\u305F\
    Newton\u6CD5\u306B\u3088\u308B\u9006\u5143\u8A08\u7B97\n// https://paper.dropbox.com/doc/fps--CQCZhUV1oN9UT3BCLrowhxgzAg-EoHXQDZxfduAB8wD1PMBW\n\
    // \u5143\u306E\u8A18\u4E8B\u3068\u306Fg_2d\u3068\u304B\u306E\u547D\u540D\u304C\
    \u9055\u3046\u3002f_2d\u306A\u3069\u306E\u4E0B\u4ED8\u304D\u306E\u6570\u5B57\u306F\
    \u3001\u3053\u306E\u30B3\u30FC\u30C9\u3067\u306F\u5F62\u5F0F\u7684\u3079\u304D\
    \u7D1A\u6570\u306E\u30B5\u30A4\u30BA\u3092\u8868\u3059\u3002\n// \u30CB\u30E5\u30FC\
    \u30C8\u30F3\u6CD51\u56DE\u3042\u305F\u308A\u306EFFT\u306E\u8A08\u7B97\u91CF\u304C\
    \u30015 * F(2d)\u306B\u306A\u308B\u3002\n// \u2193\u30B3\u30E1\u30F3\u30C8\u30A2\
    \u30A6\u30C8\u306EToggle\u5207\u308A\u66FF\u3048\u7528\n//*\n\ntemplate <typename\
    \ mint>\nFPS<mint> FPS<mint>::inv(int deg) const {\n  assert(_vec[0] != mint(0));\n\
    \  if (deg == -1) deg = size();\n  FPS g(1);\n  g._vec[0] = mint(_vec[0]).inv();\n\
    \n  for (int d = 1; d < deg; d <<= 1) {\n    // g_2n = g_n - (f_n g_n - 1) g_n\n\
    \    // e_n := f_n g_n - 1\n\n    FPS f_2d = (*this).pre(2 * d);\n    FPS g_d\
    \ = g.pre(2 * d);\n    FPS g_origin = g.pre(2 * d); // \u5F8C\u3005\u4F7F\u3044\
    \u305F\u3044\u306E\u3067\u4FDD\u5B58\u3057\u3066\u304A\u304F\n\n    CooleyTukeyNTT998244353(f_2d._vec,\
    \ false);\n    CooleyTukeyNTT998244353(g_d._vec, false);\n    assert(2 * d ==\
    \ (int)g_d.size() && f_2d.size() == g_d.size());\n    FPS h_2d(2 * d);\n    for\
    \ (int i = 0; i < 2 * d; i++) h_2d[i] = f_2d[i] * g_d[i];\n    CooleyTukeyNTT998244353(h_2d._vec,\
    \ true);\n\n    // \u3053\u3046\u3059\u308B\u3053\u3068\u3067\u3001h_2d\u306F\
    \ f_2d * g_d\u306E 2d\u6B21\u672A\u6E80\u306E\u9805\u306B\u4E00\u81F4\u3059\u308B\
    \u3002\n    // h_2d\u306Ff_2d\u3068g_d\u306E\u30B5\u30A4\u30BA2d\u306E\u5DE1\u56DE\
    \u7573\u307F\u8FBC\u307F\u3067\u3042\u308B\u304B\u3089\u3001 h_2d\u306E\u9805\u306F\
    \u4E0B\u56F3\u306E\u3088\u3046\u306B\u306A\u3063\u3066\u3044\u308B\u3002\n   \
    \ // \u3053\u3053\u3067\u3001h_2d\u306E\u3046\u3061\u307B\u3057\u3044\u90E8\u5206\
    \u306F\u5DE6\u4E0A\u3068\u3001\u53F3\u4E0A\u306E\u90E8\u5206\u306E\u307F\u3002\
    (f_2d*g_d\u306E2d\u6B21\u672A\u6E80\u304C\u307B\u3057\u3044\u306E\u3067)\n   \
    \ // \u5DE6\u4E0A\u306E\u90E8\u5206\u306F\u3001g_d\u306E\u6027\u8CEA\u304B\u3089\
    \u3001 1, 0, 0, ... \u3068\u306A\u3063\u3066\u3044\u308B\u3053\u3068\u304C\u308F\
    \u304B\u308B\u3002\n    // \u53F3\u4E0B\u306E\u90E8\u5206\u306F deg(f_2d) < 2d,\
    \ deg(g_d) < d \u2192 deg(f_2d*g_d) < 3d \u3068\u306A\u3063\u3066\u30010\u3068\
    \u306A\u3063\u3066\u3044\u308B\u3053\u3068\u304C\u308F\u304B\u308B\u3002\n   \
    \ // \u3088\u3063\u3066\u3001h_2d\u306E[d,2d)\u306E\u90E8\u5206\u306Ff_2d*g_d\u306E\
    [d,2d)\u306B\u4E00\u81F4\u3059\u308B\u306E\u3067\u4F55\u3082\u51E6\u7406\u3059\
    \u308B\u5FC5\u8981\u304C\u306A\u304F\u3001\n    // h_2d\u306E[0,d)\u306E\u90E8\
    \u5206\u306F\u4F59\u8A08\u306A\u8DB3\u3057\u7B97\u304C\u5165\u3063\u3066\u3057\
    \u307E\u3063\u3066\u3044\u308B\u304C\u30011,0,0,...\u306B\u5909\u3048\u3066\u3057\
    \u307E\u3048\u3070\u3088\u3044\u3002\n    //    [0, d)\u306E\u9805           \
    \ [d, 2d)\u306E\u9805\n    //    f_2d*g_d\u306E[0,d)       f_2d*g_d\u306E[d, 2d)\n\
    \    //    f_2d*g_d\u306E[2d, 3d)    f_2d*g_d\u306E[3d, 4d)\n\n    h_2d[0] = mint(0);\
    \ // h_2d\u3092 (f_2d * g_d - 1)\u306B\u5909\u3048\u3061\u3083\u3046\u3002\n \
    \   for (int i = 1; i < d; i++) h_2d[i] = 0;\n\n    CooleyTukeyNTT998244353(h_2d._vec,\
    \ false);\n    for (int i = 0; i < 2 * d; i++) h_2d[i] = g_d[i] * h_2d[i];\n \
    \   CooleyTukeyNTT998244353(h_2d._vec, true);\n    for (int i = 0; i < d; i++)\
    \ h_2d[i] = mint(0);\n\n    // h_2d - 1 =: h'_2d\u3068\u304A\u304F\u3002\n   \
    \ // g_2d = g_d - h'_2d * g_d \u3067\u3042\u308A\u3001\u3055\u3063\u304D\u3068\
    \u540C\u3058\u3088\u3046\u306A\u56F3\u3092\u66F8\u304F\u3068, h_2d * g_d\u3092\
    \u5DE1\u56DE\u7573\u307F\u8FBC\u307F\u3057\u305F\u3082\u306E\u306F\u3001\u4E0B\
    \u56F3\u306E\u3088\u3046\u306B\u306A\u3063\u3066\u3044\u308B\u3002\n    // \u5DE6\
    \u4E0A\u306Fall-zero(\u5B9A\u6570\u9805\u30820\u306B\u3057\u305F\u306E\u3067)\u3001\
    \u53F3\u4E0B\u3082\u6B21\u6570\u306E\u95A2\u4FC2\u304B\u3089\u5168\u90E80\u306A\
    \u306E\u3067\u3001h_2d * g_d\u306F\u3001\u5DE1\u56DE\u7573\u307F\u8FBC\u307F\u3092\
    \u3057\u305F\u3082\u306E\u306E[0,d)\u306E\u9805\u30920\u306B\u3059\u308B\u3053\
    \u3068\u3067\u5F97\u3089\u308C\u308B\u3002 \n    //    [0, d)\u306E\u9805    \
    \        [d, 2d)\u306E\u9805\n    //    h'_2d*g_d\u306E[0,d)       h'_2d*g_d\u306E\
    [d, 2d)\n    //    h'_2d*g_d\u306E[2d, 3d)    h'_2d*g_d\u306E[3d, 4d)\n\n    g\
    \ = g_origin - h_2d;\n    g.resize(d * 2);\n\n  }\n\n  return g.pre(deg);\n}\n\
    \n\n#line 7 \"test/verify/fps/yosupo-kth-term-of-linearly-recurrent-sequence-test.cpp\"\
    \n\n#line 3 \"formal-power-series/fiduccia.hpp\"\n\n// BAGUTTERU!!! gomen!!!!\n\
    // given linear recurrence sequence a_{n+K}= c_1 a_{n+K-1} + c_2 a_{n+k-2} + \\\
    dots + c_{K-1} a_{n+1} + c_K a_n\n// a_0, a_1, \\dots, a_{K-1} are given\n// calculate\
    \ a_N (N-th term of linear recurrence sequence) time complexity is O(K log K log\
    \ N) (when NNT is used), O(K^2 log N) (when naive convolution is used).\ntemplate\
    \ <typename mint> \nmint Fiduccia(const vector<mint>& a, const vector<mint>& c,\
    \ unsigned long long  N) {\n  if (N < a.size()) return a[N];\n  assert(a.size()\
    \ == c.size());\n  int K = c.size();\n\n  FPS<mint> varphi(K+1); \n  varphi[K]\
    \ = mint(1);\n  for(int i=0; i<K; i++) varphi[i] = mint(-1) * c[K-i-1];\n\n  //\
    \ calculate x^N mod varphi, using square and multiply technique.\n  // Note that\
    \ there is two way to implement the methodlogy. LSB-first algorithm(famous one\
    \ ) and MSB-first alogirthm.\n int msb=0;\n  for (int i=0; 1ULL<< i <=N; i++)\
    \ {\n    if (N & (1ULL << i)) msb = i;\n  }\n  FPS<mint> remainder(1); remainder[0]\
    \ = mint(1);\n  for (int i=msb; i>=0; i--) {\n    if (N & (1ULL << i)) {\n   \
    \   remainder = remainder << 1; // it is equal to remainder *= x.\n      if (remainder.size()\
    \ >= varphi.size()) remainder %= varphi;\n    }\n    if (i != 0) {\n      remainder\
    \ *= remainder; // NTT\u306A\u3089\u3001NTT\u914D\u5217\u3092\u4F7F\u3044\u56DE\
    \u3059\u3053\u3068\u3067\u5B9A\u6570\u500D\u304C\u826F\u304F\u306A\u308B\u306D\
    \n      if (remainder.size() >= varphi.size()) remainder %= varphi;\n    }\n \
    \ }\n\n  // remainder = x^N mod varphi \n  mint ret = 0;\n  assert(remainder.size()\
    \ <= K);\n  for(int i=0; i<remainder.size(); i++) {\n    ret += remainder[i] *\
    \ a[i];\n  }\n\n  return ret;\n}\n#line 9 \"test/verify/fps/yosupo-kth-term-of-linearly-recurrent-sequence-test.cpp\"\
    \n\nusing mint = modint998244353;\n\n\nint main() {\n  ios::sync_with_stdio(0);\
    \ cin.tie(0); cout.tie(0);\n  int d; cin >> d;\n  ll K; cin >> K;\n  vector<mint>a(d);\
    \ for(int i=0; i<d; i++) cin >> a[i];\n  vector<mint>c(d); for(int i=0; i<d; i++)\
    \ cin >> c[i];\n\n  reverse(c.begin(), c.end()); \n  mint ans = Fiduccia(a,c,K);\n\
    \n  cout << ans.val() << \"\\n\";\n\n\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/kth_term_of_linearly_recurrent_sequence\"\
    \n\n#include \"template/template.hpp\"\n#include \"math/modint.hpp\"\n#include\
    \ \"formal-power-series/formal-power-series.hpp\"\n#include \"formal-power-series/fps998.hpp\"\
    \n\n#include \"formal-power-series/fiduccia.hpp\"\n\nusing mint = modint998244353;\n\
    \n\nint main() {\n  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);\n  int d;\
    \ cin >> d;\n  ll K; cin >> K;\n  vector<mint>a(d); for(int i=0; i<d; i++) cin\
    \ >> a[i];\n  vector<mint>c(d); for(int i=0; i<d; i++) cin >> c[i];\n\n  reverse(c.begin(),\
    \ c.end()); \n  mint ans = Fiduccia(a,c,K);\n\n  cout << ans.val() << \"\\n\"\
    ;\n\n\n}\n"
  dependsOn:
  - template/template.hpp
  - math/modint.hpp
  - formal-power-series/formal-power-series.hpp
  - math/modint.hpp
  - formal-power-series/fps998.hpp
  - formal-power-series/fiduccia.hpp
  isVerificationFile: false
  path: test/verify/fps/yosupo-kth-term-of-linearly-recurrent-sequence-test.cpp
  requiredBy: []
  timestamp: '2024-06-19 18:05:48+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: test/verify/fps/yosupo-kth-term-of-linearly-recurrent-sequence-test.cpp
layout: document
redirect_from:
- /library/test/verify/fps/yosupo-kth-term-of-linearly-recurrent-sequence-test.cpp
- /library/test/verify/fps/yosupo-kth-term-of-linearly-recurrent-sequence-test.cpp.html
title: test/verify/fps/yosupo-kth-term-of-linearly-recurrent-sequence-test.cpp
---