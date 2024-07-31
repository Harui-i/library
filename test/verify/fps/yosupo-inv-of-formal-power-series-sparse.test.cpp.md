---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: formal-power-series/formal-power-series.hpp
    title: "Formal Power Series (\u5F62\u5F0F\u7684\u3079\u304D\u7D1A\u6570)"
  - icon: ':heavy_check_mark:'
    path: formal-power-series/fps998.hpp
    title: formal-power-series/fps998.hpp
  - icon: ':heavy_check_mark:'
    path: formal-power-series/sparse-fps.hpp
    title: sparse-fps
  - icon: ':question:'
    path: math/external_gcd.hpp
    title: math/external_gcd.hpp
  - icon: ':question:'
    path: math/modint.hpp
    title: modint
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
    PROBLEM: https://judge.yosupo.jp/problem/inv_of_formal_power_series_sparse
    links:
    - https://judge.yosupo.jp/problem/inv_of_formal_power_series_sparse
  bundledCode: "#line 1 \"test/verify/fps/yosupo-inv-of-formal-power-series-sparse.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/inv_of_formal_power_series_sparse\"\
    \n\n#line 1 \"template/template.hpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\nusing ll = long long;\ntemplate<class T> inline bool chmax(T& a, const\
    \ T& b) {if (a<b) {a=b; return true;} return false;}\ntemplate<class T> inline\
    \ bool chmin(T& a, const T& b) {if (b<a) {a=b; return true;} return false;}\n\
    const int INTINF = 1000001000;\nconst int INTMAX = 2147483647;\nconst ll LLMAX\
    \ = 9223372036854775807;\nconst ll LLINF = 1000000000000000000;\n#line 1 \"math/modint.hpp\"\
    \n\n\n\n#line 1 \"math/external_gcd.hpp\"\n\n\n\n#line 5 \"math/external_gcd.hpp\"\
    \n\n// g,x,y\ntemplate<typename T>\nconstexpr std::tuple<T, T, T> extendedGCD(T\
    \ a, T b) {\n    T x0 = 1, y0 = 0, x1 = 0, y1 = 1;\n    while (b != 0) {\n   \
    \     T q = a / b;\n        T r = a % b;\n        a = b;\n        b = r;\n   \
    \     \n        T xTemp = x0 - q * x1;\n        x0 = x1;\n        x1 = xTemp;\n\
    \        \n        T yTemp = y0 - q * y1;\n        y0 = y1;\n        y1 = yTemp;\n\
    \    }\n    return {a, x0, y0};\n}\n\n#line 5 \"math/modint.hpp\"\n\ntemplate<int\
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
    \ inv() const {\n        //return pow(MOD - 2);\n        int g,x,y;\n        tie(g,x,y)\
    \ = extendedGCD(value, MOD);\n        assert(g==1);\n        if (x < 0) {\n  \
    \          x += MOD;\n        }\n        //cerr << g << \" \" << x << \" \" <<\
    \ y << \" \" << value << endl;\n        //assert((((long)x*value)%MOD + MOD)%MOD\
    \ == 1);\n        return x;\n    }\n\n    constexpr static_modint& operator/=(const\
    \ static_modint& other) {\n        return *this *= other.inv();\n    }\n\n   \
    \ constexpr static_modint operator/(const static_modint& other) const {\n    \
    \    return static_modint(*this) /= other;\n    }\n\n    constexpr bool operator!=(const\
    \ static_modint& other) const {\n        return val() != other.val();\n    }\n\
    \n    constexpr bool operator==(const static_modint& other) const {\n        return\
    \ val() == other.val();\n    }\n\n    int val() const {\n      return this->value;\n\
    \    }\n\n    friend std::ostream& operator<<(std::ostream& os, const static_modint&\
    \ mi) {\n        return os << mi.value;\n    }\n\n    friend std::istream& operator>>(std::istream&\
    \ is, static_modint& mi) {\n        long long x;\n        is >> x;\n        mi\
    \ = static_modint(x);\n        return is;\n    }\n};\n\ntemplate <int mod>\nusing\
    \ modint = static_modint<mod>;\nusing modint998244353  = modint<998244353>;\n\
    using modint1000000007 = modint<1000000007>;\n\n\n#line 1 \"formal-power-series/formal-power-series.hpp\"\
    \n\n\n\n#line 6 \"formal-power-series/formal-power-series.hpp\"\n\n\ntemplate\
    \ <typename mint>\nstruct FPS {\n  std::vector<mint> _vec;\n\n  constexpr int\
    \ lg2(int N) const {\n    int ret = 0;\n    if (N > 0) ret = 31 - __builtin_clz(N);\n\
    \    if ((1LL << ret) < N) ret++;\n    return ret;\n  }\n\n  // \u30CA\u30A4\u30FC\
    \u30D6\u306A\u30CB\u30E5\u30FC\u30C8\u30F3\u6CD5\u3067\u306E\u9006\u5143\u8A08\
    \u7B97\n  FPS inv_naive(int deg) const {\n    assert(_vec[0] != mint(0)); // \u3055\
    \u3042\u3089\u3056\u308C\u3070\u3001\u9006\u5143\u306E\u3066\u3072\u304E\u3044\
    \u304D\u306B\u3053\u305D\u3042\u3089\u3056\u308C\u3002\n    if (deg == -1) deg\
    \ = this->size();\n    FPS g(1);\n    g._vec[0] = mint(_vec[0]).inv();\n    //\
    \ g_{n+1} = 2 * g_n - f * (g_n)^2\n    for (int d = 1; d < deg; d <<= 1) {\n \
    \     FPS g_twice = g * mint(2);\n      FPS fgg = (*this).pre(d * 2) * g * g;\n\
    \n      g = g_twice - fgg;\n      g.resize(d * 2);\n    }\n\n    return g.pre(deg);\n\
    \  }\n\n  //*/\n\n  FPS log(int deg = -1) const {\n    assert(_vec[0] == mint(1));\n\
    \n    if (deg == -1) deg = size();\n    FPS df = this->diff();\n    FPS iv = this->inv(deg);\n\
    \    FPS ret = (df * iv).pre(deg - 1).integral();\n\n    return ret;\n  }\n\n\
    \  FPS exp(int deg = -1) const {\n    assert(_vec[0] == mint(0));\n\n    if (deg\
    \ == -1) deg = size();\n    FPS h = {1}; // h: exp(f)\n\n    // h_2d = h * (f\
    \ + 1 - Integrate(h' * h.inv() ) )\n\n    for (int d = 1; d < deg; d <<= 1) {\n\
    \      // h_2d = h_d * (f + 1 - log(h_d))\n      // = h_d * (f + 1  - Integral(h'\
    \ * h.inv() ))\n      // \u3092\u5229\u7528\u3057\u3066\u3001h.inv\u3092\u6F38\
    \u5316\u5F0F\u3067\u66F4\u65B0\u3057\u3066\u3044\u3051\u3070\u5B9A\u6570\u500D\
    \u6539\u5584\u3067\u304D\u308B\u304B\u3068\u601D\u3063\u305F\u304C\u3001\u306A\
    \u3093\u304B\u30D0\u30B0\u3063\u3066\u308B\u3002\n\n      FPS fpl1 = ((*this).pre(2*d)\
    \ + mint(1));\n      FPS logh = h.log(2*d);\n      FPS right = (fpl1 - logh);\n\
    \n      h = (h * right).pre(2 * d);\n    }\n\n    return h.pre(deg);\n  }\n\n\
    \  // f^k \u3092\u8FD4\u3059\n  FPS pow(long long k, int deg = -1) const {\n \
    \   mint lowest_coeff;\n    if (deg == -1) deg = size();\n    int lowest_deg =\
    \ -1;\n\n    if (k == 0) {\n      FPS ret = { mint(1) };\n      ret.resize(deg);\n\
    \      return ret;\n    }\n\n    for (int i = 0; i < size(); i++) {\n      if\
    \ (i * k > deg) {\n        return FPS(deg);\n      }\n      if (_vec[i] != mint(0))\
    \ {\n        lowest_deg = i;\n        lowest_coeff = _vec[i];\n        \n    \
    \    int deg3 = deg - k*lowest_deg;\n\n        FPS f2 = (*this / lowest_coeff)\
    \ >> lowest_deg;\n        FPS ret = (lowest_coeff.pow(k) * (f2.log(deg3) * mint(k)).exp(deg3)\
    \ << (lowest_deg * k)).pre(deg);\n        ret.resize(deg);\n\n        return ret;\n\
    \      }\n    }\n    assert(false);\n  }\n\n  FPS integral() const {\n    const\
    \ int N = size();\n    FPS ret(N + 1);\n\n    for (int i = 0; i < N; i++) ret[i\
    \ + 1] = _vec[i] * mint(i + 1).inv();\n\n    return ret;\n  }\n\n  FPS diff()\
    \ const {\n    const int N = size();\n    FPS ret(max(0, N - 1));\n    for (int\
    \ i = 1; i < N; i++) ret[i - 1] = mint(i) * _vec[i];\n\n    return ret;\n  }\n\
    \n  FPS(std::vector<mint> vec) : _vec(vec) {\n  }\n\n  FPS(initializer_list<mint>\
    \ ilist) : _vec(ilist) {\n  }\n\n  // \u9805\u306E\u6570\u306B\u63C3\u3048\u305F\
    \u307B\u3046\u304C\u3088\u3055\u305D\u3046\n  FPS(int sz) : _vec(std::vector<mint>(sz))\
    \ {\n  }\n\n  int size() const {\n    return _vec.size();\n  }\n\n  FPS& operator+=(const\
    \ FPS& rhs) {\n    if (rhs.size() > this->size()) _vec.resize(rhs.size());\n \
    \   for (int i = 0; i < (int)rhs.size(); ++i) _vec[i] += rhs._vec[i];\n    return\
    \ *this;\n  }\n\n  FPS& operator-=(const FPS& rhs) {\n    if (rhs.size() > this->size())\
    \ this->_vec.resize(rhs.size());\n    for (int i = 0; i < (int)rhs.size(); ++i)\
    \ _vec[i] -= rhs._vec[i];\n    return *this;\n  }\n\n  FPS& operator*=(const FPS&\
    \ rhs) {\n    _vec = multiply(_vec, rhs._vec);\n    return *this;\n  }\n\n  //\
    \ Nyaan\u5148\u751F\u306E\u30E9\u30A4\u30D6\u30E9\u30EA\u3092\u5927\u5199\u7D4C\
    ....\n  FPS& operator/=(const FPS& rhs) {\n    if (size() < rhs.size()) {\n  \
    \    return *this = FPS(0);\n    }\n    int sz = size() - rhs.size() + 1;\n  \
    \  //\n    //    FPS left = (*this).rev().pre(sz);\n    //    FPS right = rhs.rev();\n\
    \    //    right = right.inv(sz);\n    //    FPS mp = left*right;\n    //    mp\
    \ = mp.pre(sz);\n    //    mp = mp.rev();\n    //    return *this = mp;\n    //\
    \    return *this = (left * right).pre(sz).rev();\n    return *this = ((*this).rev().pre(sz)\
    \ * rhs.rev().inv(sz)).pre(sz).rev();\n  }\n\n  FPS& operator%=(const FPS& rhs)\
    \ {\n    *this -= *this / rhs * rhs;\n    shrink();\n    return *this;\n  }\n\n\
    \  FPS& operator+=(const mint& rhs) {\n    _vec[0] += rhs;\n    return *this;\n\
    \  }\n\n  FPS& operator-=(const mint& rhs) {\n    _vec[0] -= rhs;\n    return\
    \ *this;\n  }\n\n  FPS& operator*=(const mint& rhs) {\n    for (int i = 0; i <\
    \ size(); i++) _vec[i] *= rhs;\n    return *this;\n  }\n\n  // \u591A\u9805\u5F0F\
    \u5168\u4F53\u3092\u5B9A\u6570\u9664\u7B97\u3059\u308B\n  FPS& operator/=(const\
    \ mint& rhs) {\n    for (int i = 0; i < size(); i++) _vec[i] *= rhs.inv();\n \
    \   return *this;\n  }\n\n  // f /= x^sz\n  FPS operator>>(int sz) const {\n \
    \   if ((int)this->size() <= sz) return {};\n    FPS ret(*this);\n    ret._vec.erase(ret._vec.begin(),\
    \ ret._vec.begin() + sz);\n    return ret;\n  }\n\n  // f *= x^sz\n  FPS operator<<(int\
    \ sz) const {\n    FPS ret(*this);\n    ret._vec.insert(ret._vec.begin(), sz,\
    \ mint(0));\n\n    return ret;\n  }\n\n  friend FPS operator+(FPS a, const FPS&\
    \ b) { return a += b; }\n  friend FPS operator-(FPS a, const FPS& b) { return\
    \ a -= b; }\n  friend FPS operator*(FPS a, const FPS& b) { return a *= b; }\n\
    \  friend FPS operator/(FPS a, const FPS& b) { return a /= b; }\n  friend FPS\
    \ operator%(FPS a, const FPS& b) { return a %= b; }\n\n  friend FPS operator+(FPS\
    \ a, const mint& b) { return a += b; }\n  friend FPS operator+(const mint& b,\
    \ FPS a) { return a += b; }\n  \n  friend FPS operator-(FPS a, const mint& b)\
    \ { return a -= b; }\n  friend FPS operator-(const mint& b, FPS a) { return a\
    \ -= b; }\n\n  friend FPS operator*(FPS a, const mint& b) { return a *= b; }\n\
    \  friend FPS operator*(const mint& b, FPS a) { return a *= b; }\n\n  friend FPS\
    \ operator/(FPS a, const mint& b) { return a /= b; }\n  friend FPS operator/(const\
    \ mint& b, FPS a) { return a /= b; }\n\n  // sz\u6B21\u672A\u6E80\u306E\u9805\u3092\
    \u53D6\u3063\u3066\u304F\u308B\n  FPS pre(int sz) const {\n    FPS ret = *this;\n\
    \    ret._vec.resize(sz);\n\n    return ret;\n  }\n\n  FPS rev() const {\n   \
    \ FPS ret = *this;\n    reverse(ret._vec.begin(), ret._vec.end());\n\n    return\
    \ ret;\n  }\n\n  const mint& operator[](size_t i) const {\n    return _vec[i];\n\
    \  }\n\n  mint& operator[](size_t i) {\n    return _vec[i];\n  }\n\n  void resize(int\
    \ sz) {\n    this->_vec.resize(sz);\n  }\n\n  void shrink() {\n    while (size()\
    \ > 0 && _vec.back() == mint(0)) _vec.pop_back();\n  }\n\n  friend ostream& operator<<(ostream&\
    \ os, const FPS& fps) {\n    for (int i = 0; i < fps.size(); ++i) {\n      if\
    \ (i > 0) os << \" \";\n      os << fps._vec[i].val();\n    }\n    return os;\n\
    \  }\n\n  // \u4EEE\u60F3\u95A2\u6570\u3063\u3066\u3084\u3064\u3002mod 998244353\u306A\
    \u306E\u304B\u3001\u4ED6\u306ENTT-friendly\u306Amod\u3067\u8003\u3048\u308B\u306E\
    \u304B\u3001\u305D\u308C\u3068\u3082Garner\u3067\u5FA9\u5143\u3059\u308B\u306E\
    \u304B\u3001\u305D\u308C\u3068\u3082\u7573\u307F\u8FBC\u307F\u3092$O(N^2)$\u3067\
    \u59A5\u5354\u3059\u308B\u306E\u304B\u306A\u3069\u306B\u3088\u3063\u3066\u7570\
    \u306A\u308B\n  virtual FPS inv(int deg = -1) const;\n  virtual void next_inv(FPS&\
    \ g_d) const; \n  virtual void CooleyTukeyNTT998244353(std::vector<mint>& a, bool\
    \ is_reverse) const;\n  //  virtual FPS exp(int deg=-1) const;\n  virtual std::vector<mint>\
    \ multiply(const std::vector<mint>& a, const std::vector<mint>& b);\n};\n\n\n\
    #line 1 \"formal-power-series/fps998.hpp\"\n\n\n\n\n#line 6 \"formal-power-series/fps998.hpp\"\
    \n\nusing mint = modint998244353;\n//ZETAS = {1,998244352,911660635,372528824,929031873,452798380,922799308,781712469,476477967,166035806,258648936,584193783,63912897,350007156,666702199,968855178,629671588,24514907,996173970,363395222,565042129,733596141,267099868,15311432};\n\
    // constexpr \u95A2\u6570\u5185\u3067 ZETAS \u914D\u5217\u3092\u8A2D\u5B9A\u3059\
    \u308B\u305F\u3081\u306E\u88DC\u52A9\u95A2\u6570\nconstexpr std::array<mint, 24>\
    \ setup_zetas() {\n  std::array<mint, 24> zetas;\n  zetas[23] = mint(3).pow(119);\n\
    \  for (int i = 22; i >= 0; --i) {\n    zetas[i] = (zetas[i + 1] * zetas[i + 1]);\n\
    \  }\n  return zetas;\n}\n\n// \u30B3\u30F3\u30D1\u30A4\u30EB\u6642\u306B ZETAS\
    \ \u914D\u5217\u3092\u521D\u671F\u5316\nconstexpr array<mint, 24> ZETAS = setup_zetas();\n\
    \n\n\n// \u53C2\u8003: https://www.creativ.xyz/fast-fourier-transform/\ntemplate\
    \ <typename mint>\nvoid FPS<mint>::CooleyTukeyNTT998244353(vector<mint>& a, bool\
    \ is_reverse) const {\n  int N = a.size();\n  int lgN = lg2(N);\n  //for (int\
    \ i = 0; 1 << i < N; i++) lgN++;\n  assert(N == 1 << lgN);\n  assert(lgN <= 23\
    \ && \"the length shoud be less than or equal to 2^23 \" );\n\n  // https://37zigen.com/transpose-fft/\n\
    \  // https://tayu0110.hatenablog.com/entry/2023/05/06/023244\n  // \u5468\u6CE2\
    \u6570\u9593\u5F15\u304D\n  if (is_reverse == false) {\n    int width = N;\n \
    \   int lgw = lgN;\n    int offset = width >> 1;\n    while (width > 1) {\n  \
    \    mint w = ZETAS[lgw]; // 1\u306Ewidth\u4E57\u6839\n      for (int top=0; top<N;\
    \ top += width) {\n        mint root = 1;\n        for (int i=top; i<top+offset;\
    \ i++) {\n          mint c0 = a[i];\n          mint c1 = a[i+offset];\n\n    \
    \      a[i] = c0 + c1;\n          a[i+offset] = (c0 - c1) * root;\n          root\
    \ *= w; \n        }\n      }\n\n      width >>= 1;\n      offset >>= 1;\n    \
    \  lgw--;\n    }\n    return;\n  }\n  \n  // https://37zigen.com/transpose-fft/\n\
    \  // \u6642\u9593\u9593\u5F15\u304D\n  if (is_reverse == true) {\n    int width\
    \ = 2;\n    int lgw = 1;\n    int offset = 1;\n    while (width <= N) {\n    \
    \  mint w = ZETAS[lgw].inv(); // 1\u306Ewidth\u4E57\u6839\u306Einv\n\n      for\
    \ (int top=0; top<N; top += width) {\n        mint root = 1;\n        for (int\
    \ i=top; i<top+offset; i++) {\n          mint c0 = a[i];\n          mint c1 =\
    \ a[i+offset];\n          a[i] = c0 + c1 * root;\n          a[i+offset] = c0 -\
    \ c1 * root;\n          root *= w;\n        }\n      }\n\n      width <<= 1;\n\
    \      offset <<= 1;\n      lgw++;\n    }\n\n    for(int i=0; i<N; i++) a[i] *=\
    \ mint(N).inv();\n    return;\n  }\n\n}\n\ntemplate <typename mint>\nvector<mint>\
    \ FPS<mint>::multiply(const vector<mint>& a, const vector<mint>& b) {\n  if (a.size()\
    \ == 0 || b.size() == 0) return vector<mint>();\n\n  vector<mint> fa(a.begin(),\
    \ a.end()), fb(b.begin(), b.end());\n  int n = 1 << lg2(a.size() + b.size());\n\
    \  //while (n < (int)(a.size() + b.size())) n <<= 1;\n\n  fa.resize(n);\n  fb.resize(n);\n\
    \n  vector<mint>fc(n);\n  if (min(a.size(), b.size()) <= 40) {\n    for (int i\
    \ = 0; i < (int)a.size(); i++) for (int j = 0; j < (int)b.size(); j++) fc[i +\
    \ j] += fa[i] * fb[j];\n  }\n  else {\n    CooleyTukeyNTT998244353(fa, false);\n\
    \    CooleyTukeyNTT998244353(fb, false);\n    for (int i = 0; i < n; ++i) fc[i]\
    \ = fa[i] * fb[i];\n    CooleyTukeyNTT998244353(fc, true);\n  }\n  fc.resize(a.size()\
    \ + b.size() - 1);\n  return fc;\n}\n\n\n// FFT\u306E\u56DE\u6570\u3092\u7BC0\u7D04\
    \u3057\u305FNewton\u6CD5\u3067\u306E\u9006\u5143\u8A08\u7B97\n/* \ntemplate <typename\
    \ mint>\nFPS<mint> FPS<mint>::inv_fast1(int deg = -1) const {\n  assert(_vec[0]\
    \ != mint(0));\n  if (deg == -1) deg = size();\n  FPS g(1);\n  g._vec[0] = mint(_vec[0]).inv();\n\
    \n  for (int d = 1; d < deg; d <<= 1) {\n    FPS g_squared = g;\n    FPS g_twice\
    \ = g * mint(2);\n\n    g_squared.resize(d * 4);\n    CooleyTukeyNTT998244353(g_squared._vec,\
    \ false);\n    for (int i = 0; i < g_squared.size(); i++) g_squared._vec[i] *=\
    \ g_squared._vec[i];\n\n    FPS fgg = (*this).FPS::pre(d * 2);\n    fgg.resize(d\
    \ * 4);\n    CooleyTukeyNTT998244353(fgg._vec, false);\n\n    for (int i = 0;\
    \ i < fgg.size(); i++) {\n      fgg._vec[i] *= g_squared._vec[i];\n    }\n   \
    \ CooleyTukeyNTT998244353(fgg._vec, true);\n    fgg.resize(d * 4 - 2);\n\n   \
    \ g = (g_twice - fgg);\n    g.resize(d * 2);\n  }\n\n  return g.pre(deg);\n} \n\
    */\n\n// \u5DE1\u56DE\u7573\u307F\u8FBC\u307F\u3092\u5229\u7528\u3057\u3066FFT\u306E\
    \u56DE\u6570\u3092\u7BC0\u7D04\u3057\u305FNewton\u6CD5\u306B\u3088\u308B\u9006\
    \u5143\u8A08\u7B97\n// https://paper.dropbox.com/doc/fps--CQCZhUV1oN9UT3BCLrowhxgzAg-EoHXQDZxfduAB8wD1PMBW\n\
    // \u5143\u306E\u8A18\u4E8B\u3068\u306Fg_2d\u3068\u304B\u306E\u547D\u540D\u304C\
    \u9055\u3046\u3002f_2d\u306A\u3069\u306E\u4E0B\u4ED8\u304D\u306E\u6570\u5B57\u306F\
    \u3001\u3053\u306E\u30B3\u30FC\u30C9\u3067\u306F\u5F62\u5F0F\u7684\u3079\u304D\
    \u7D1A\u6570\u306E\u30B5\u30A4\u30BA\u3092\u8868\u3059\u3002\n// \u30CB\u30E5\u30FC\
    \u30C8\u30F3\u6CD51\u56DE\u3042\u305F\u308A\u306EFFT\u306E\u8A08\u7B97\u91CF\u304C\
    \u30015 * F(2d)\u306B\u306A\u308B\u3002\n// \u2193\u30B3\u30E1\u30F3\u30C8\u30A2\
    \u30A6\u30C8\u306EToggle\u5207\u308A\u66FF\u3048\u7528\n//*\n\ntemplate <typename\
    \ mint>\nFPS<mint> FPS<mint>::inv(int deg) const {\n  assert(_vec[0] != mint(0));\n\
    \  if (deg == -1) deg = size();\n  FPS g(1);\n  g._vec[0] = mint(_vec[0]).inv();\n\
    \n  for (int d = 1; d < deg; d <<= 1) {\n    next_inv(g);\n  }\n\n  return g.pre(deg);\n\
    }\n\n// this\u306E\u9006\u5143\u306En\u9805\u76EE\u307E\u3067\u3092\u53D7\u3051\
    \u3068\u308A\u3001\u7CBE\u5EA6\u3092\u500D\u306B\u3059\u308B\ntemplate <typename\
    \ mint>\nvoid FPS<mint>::next_inv(FPS<mint>& g) const {\n    // g_2n = g_n - (f_n\
    \ g_n - 1) g_n\n    // e_n := f_n g_n - 1\n    int d = g.size();\n    FPS f_2d\
    \ = (*this).pre(2 * d);\n    FPS g_d = g.pre(2 * d);\n    FPS g_origin = g.pre(2\
    \ * d); // \u5F8C\u3005\u4F7F\u3044\u305F\u3044\u306E\u3067\u4FDD\u5B58\u3057\u3066\
    \u304A\u304F\n\n    CooleyTukeyNTT998244353(f_2d._vec, false);\n    CooleyTukeyNTT998244353(g_d._vec,\
    \ false);\n    assert(2 * d == (int)g_d.size() && f_2d.size() == g_d.size());\n\
    \    FPS h_2d(2 * d);\n    for (int i = 0; i < 2 * d; i++) h_2d[i] = f_2d[i] *\
    \ g_d[i];\n    CooleyTukeyNTT998244353(h_2d._vec, true);\n\n    // \u3053\u3046\
    \u3059\u308B\u3053\u3068\u3067\u3001h_2d\u306F f_2d * g_d\u306E 2d\u6B21\u672A\
    \u6E80\u306E\u9805\u306B\u4E00\u81F4\u3059\u308B\u3002\n    // h_2d\u306Ff_2d\u3068\
    g_d\u306E\u30B5\u30A4\u30BA2d\u306E\u5DE1\u56DE\u7573\u307F\u8FBC\u307F\u3067\u3042\
    \u308B\u304B\u3089\u3001 h_2d\u306E\u9805\u306F\u4E0B\u56F3\u306E\u3088\u3046\u306B\
    \u306A\u3063\u3066\u3044\u308B\u3002\n    // \u3053\u3053\u3067\u3001h_2d\u306E\
    \u3046\u3061\u307B\u3057\u3044\u90E8\u5206\u306F\u5DE6\u4E0A\u3068\u3001\u53F3\
    \u4E0A\u306E\u90E8\u5206\u306E\u307F\u3002(f_2d*g_d\u306E2d\u6B21\u672A\u6E80\u304C\
    \u307B\u3057\u3044\u306E\u3067)\n    // \u5DE6\u4E0A\u306E\u90E8\u5206\u306F\u3001\
    g_d\u306E\u6027\u8CEA\u304B\u3089\u3001 1, 0, 0, ... \u3068\u306A\u3063\u3066\u3044\
    \u308B\u3053\u3068\u304C\u308F\u304B\u308B\u3002\n    // \u53F3\u4E0B\u306E\u90E8\
    \u5206\u306F deg(f_2d) < 2d, deg(g_d) < d \u2192 deg(f_2d*g_d) < 3d \u3068\u306A\
    \u3063\u3066\u30010\u3068\u306A\u3063\u3066\u3044\u308B\u3053\u3068\u304C\u308F\
    \u304B\u308B\u3002\n    // \u3088\u3063\u3066\u3001h_2d\u306E[d,2d)\u306E\u90E8\
    \u5206\u306Ff_2d*g_d\u306E[d,2d)\u306B\u4E00\u81F4\u3059\u308B\u306E\u3067\u4F55\
    \u3082\u51E6\u7406\u3059\u308B\u5FC5\u8981\u304C\u306A\u304F\u3001\n    // h_2d\u306E\
    [0,d)\u306E\u90E8\u5206\u306F\u4F59\u8A08\u306A\u8DB3\u3057\u7B97\u304C\u5165\u3063\
    \u3066\u3057\u307E\u3063\u3066\u3044\u308B\u304C\u30011,0,0,...\u306B\u5909\u3048\
    \u3066\u3057\u307E\u3048\u3070\u3088\u3044\u3002\n    //    [0, d)\u306E\u9805\
    \            [d, 2d)\u306E\u9805\n    //    f_2d*g_d\u306E[0,d)       f_2d*g_d\u306E\
    [d, 2d)\n    //    f_2d*g_d\u306E[2d, 3d)    f_2d*g_d\u306E[3d, 4d)\n\n    h_2d[0]\
    \ = mint(0); // h_2d\u3092 (f_2d * g_d - 1)\u306B\u5909\u3048\u3061\u3083\u3046\
    \u3002\n    for (int i = 1; i < d; i++) h_2d[i] = 0;\n\n    CooleyTukeyNTT998244353(h_2d._vec,\
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
    \ = g_origin - h_2d;\n    g.resize(d * 2);\n}\n\n\n#line 1 \"formal-power-series/sparse-fps.hpp\"\
    \n\n\n\n#line 5 \"formal-power-series/sparse-fps.hpp\"\nusing namespace std;\n\
    \n#line 8 \"formal-power-series/sparse-fps.hpp\"\n\n// calculate inverse of f(sparse)\n\
    // deg : -1 + ( maximum degree of g )\ntemplate <typename mint>\nFPS<mint> inv_sparse(const\
    \ vector<pair<int,mint>>& f, int deg) {\n  assert(deg >= 0);\n  for(int i=0; i<(int)f.size()-1;\
    \ i++) assert(f[i].first < f[i+1].first); \n  assert(f[0].first == 0 && f[0].second\
    \ != mint(0));\n\n  mint f0inv = f[0].second.inv();\n  vector<mint> g(deg); g[0]\
    \ = f0inv;\n  for(int i=0; i<deg-1; i++) {\n    for (pair<int,mint> pim : f) {\n\
    \      if (i+1 - pim.first >= 0) g[i+1] -= pim.second * g[i+1 - pim.first];\n\
    \      else continue;\n    }\n    g[i+1] *= f0inv;\n  }\n\n  return g;\n}\n\n\
    template <typename mint>\nFPS<mint> inv_sparse(const FPS<mint>& f, int deg) {\n\
    \  vector<pair<int,mint>> vpim;\n  for(int i=0; i<f.size(); i++) if (f[i] != mint(0))\
    \ vpim.emplace_back(i, f[i]);\n\n  return inv_sparse(vpim, deg);\n}\n\n\n//tabun\
    \ baggute masu. TODO\ntemplate<typename mint>\nFPS<mint> multiply_sparse(const\
    \ FPS<mint>& f, const vector<pair<int,mint>>& g, int deg = -1) {\n  if (deg ==\
    \ -1) deg = f.size() - 1 + g.back().first + 1;\n\n  FPS<mint> ret(deg);\n  for\
    \ (pair<int,mint> pim : g) {\n    assert(pim.second != 0);\n    if (pim.second\
    \ == 0) continue;\n\n    for(int i=0; i<f.size(); i++) {\n      if (i+pim.first\
    \ >= ret.size()) continue;\n      if (f[i] != mint(0) && pim.second != mint(0))\
    \ ret[i+pim.first] += pim.second * f[i];\n    }\n  }\n\n  return ret;\n}\n\ntemplate\
    \ <typename mint>\nFPS<mint> multiply_sparse(const FPS<mint>& f, const FPS<mint>&\
    \ g, int deg = -1) {\n  vector<pair<int,mint>> vpmi;\n\n  for(int i=0; i<g.size();\
    \ i++) if (g[i] != mint(0)) vpmi.emplace_back(i, g[i]);\n\n  return multiply_sparse(f,\
    \ vpmi, deg);\n}\n\n\n#line 8 \"test/verify/fps/yosupo-inv-of-formal-power-series-sparse.test.cpp\"\
    \n\nusing mint = modint998244353;\n\n\nint main() {\n  ios::sync_with_stdio(0);\
    \ cin.tie(0); cout.tie(0);\n  int N, K; cin >> N >> K;\n  vector<pair<int,mint>>\
    \ ia(K);\n  for(int i=0; i<K; i++) cin >> ia[i].first >> ia[i].second;\n\n  FPS<mint>\
    \ inv = inv_sparse(ia, N);\n  for(int i=0; i<N; i++) cout << inv[i] << \" \";\n\
    \  cout << endl;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/inv_of_formal_power_series_sparse\"\
    \n\n#include \"template/template.hpp\"\n#include \"math/modint.hpp\"\n#include\
    \ \"formal-power-series/formal-power-series.hpp\"\n#include \"formal-power-series/fps998.hpp\"\
    \n#include \"formal-power-series/sparse-fps.hpp\"\n\nusing mint = modint998244353;\n\
    \n\nint main() {\n  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);\n  int N,\
    \ K; cin >> N >> K;\n  vector<pair<int,mint>> ia(K);\n  for(int i=0; i<K; i++)\
    \ cin >> ia[i].first >> ia[i].second;\n\n  FPS<mint> inv = inv_sparse(ia, N);\n\
    \  for(int i=0; i<N; i++) cout << inv[i] << \" \";\n  cout << endl;\n}\n"
  dependsOn:
  - template/template.hpp
  - math/modint.hpp
  - math/external_gcd.hpp
  - formal-power-series/formal-power-series.hpp
  - math/modint.hpp
  - formal-power-series/fps998.hpp
  - formal-power-series/sparse-fps.hpp
  isVerificationFile: true
  path: test/verify/fps/yosupo-inv-of-formal-power-series-sparse.test.cpp
  requiredBy: []
  timestamp: '2024-07-13 17:32:44+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/verify/fps/yosupo-inv-of-formal-power-series-sparse.test.cpp
layout: document
redirect_from:
- /verify/test/verify/fps/yosupo-inv-of-formal-power-series-sparse.test.cpp
- /verify/test/verify/fps/yosupo-inv-of-formal-power-series-sparse.test.cpp.html
title: test/verify/fps/yosupo-inv-of-formal-power-series-sparse.test.cpp
---
