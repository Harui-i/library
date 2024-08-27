---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: formal-power-series/formal-power-series.hpp
    title: "Formal Power Series (\u5F62\u5F0F\u7684\u3079\u304D\u7D1A\u6570)"
  - icon: ':question:'
    path: math/external_gcd.hpp
    title: math/external_gcd.hpp
  - icon: ':question:'
    path: math/modint.hpp
    title: modint
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/verify/fps/yosupo-kth-term-of-linearly-recurrent-sequence.test.cpp
    title: test/verify/fps/yosupo-kth-term-of-linearly-recurrent-sequence.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"formal-power-series/fiduccia.hpp\"\n#include <vector>\n\
    #line 1 \"formal-power-series/formal-power-series.hpp\"\n\n\n\n#line 1 \"math/modint.hpp\"\
    \n\n\n\n#line 1 \"math/external_gcd.hpp\"\n\n\n\n#include <tuple>\n\n// g,x,y\n\
    template<typename T>\nconstexpr std::tuple<T, T, T> extendedGCD(T a, T b) {\n\
    \    T x0 = 1, y0 = 0, x1 = 0, y1 = 1;\n    while (b != 0) {\n        T q = a\
    \ / b;\n        T r = a % b;\n        a = b;\n        b = r;\n        \n     \
    \   T xTemp = x0 - q * x1;\n        x0 = x1;\n        x1 = xTemp;\n        \n\
    \        T yTemp = y0 - q * y1;\n        y0 = y1;\n        y1 = yTemp;\n    }\n\
    \    return {a, x0, y0};\n}\n\n#line 5 \"math/modint.hpp\"\n\ntemplate<int MOD>\n\
    struct static_modint {\n    int value;\n\n    constexpr static_modint() : value(0)\
    \ {}\n\n    constexpr static_modint(long long v) {\n        value = int(((v %\
    \ MOD) + MOD) % MOD);\n    }\n\n    constexpr static_modint& operator+=(const\
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
    using modint1000000007 = modint<1000000007>;\n\n\n#line 6 \"formal-power-series/formal-power-series.hpp\"\
    \n\n\ntemplate <typename mint>\nstruct FPS {\n  std::vector<mint> _vec;\n\n  constexpr\
    \ int lg2(int N) const {\n    int ret = 0;\n    if (N > 0) ret = 31 - __builtin_clz(N);\n\
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
    #line 3 \"formal-power-series/fiduccia.hpp\"\n\n// AtCoder\u3067\u306Fverify\u3067\
    \u304D\u305F\u304C\u3001LC\u3067\u306F\u3067\u304D\u305A\n// given linear recurrence\
    \ sequence a_{n+K}= c_1 a_{n+K-1} + c_2 a_{n+k-2} + \\dots + c_{K-1} a_{n+1} +\
    \ c_K a_n\n// a_0, a_1, \\dots, a_{K-1} are given\n// calculate a_N (N-th term\
    \ of linear recurrence sequence) time complexity is O(K log K log N) (when NNT\
    \ is used), O(K^2 log N) (when naive convolution is used).\ntemplate <typename\
    \ mint> \nmint Fiduccia(const vector<mint>& a, const vector<mint>& c, unsigned\
    \ long long  N) {\n  if (N < a.size()) return a[N];\n  assert(a.size() == c.size());\n\
    \  int K = c.size();\n\n  FPS<mint> varphi(K+1); \n  varphi[K] = mint(1);\n  for(int\
    \ i=0; i<K; i++) varphi[i] = mint(-1) * c[K-i-1];\n\n  // calculate x^N mod varphi,\
    \ using square and multiply technique.\n  // Note that there is two way to implement\
    \ the methodlogy. LSB-first algorithm(famous one ) and MSB-first alogirthm.\n\
    \ int msb=0;\n  for (int i=0; 1ULL<< i <=N; i++) {\n    if (N & (1ULL << i)) msb\
    \ = i;\n  }\n  FPS<mint> remainder(1); remainder[0] = mint(1);\n  for (int i=msb;\
    \ i>=0; i--) {\n    if (N & (1ULL << i)) {\n      remainder = remainder << 1;\
    \ // it is equal to remainder *= x.\n      if (remainder.size() >= varphi.size())\
    \ remainder %= varphi;\n    }\n    if (i != 0) {\n      remainder *= remainder;\
    \ // NTT\u306A\u3089\u3001NTT\u914D\u5217\u3092\u4F7F\u3044\u56DE\u3059\u3053\u3068\
    \u3067\u5B9A\u6570\u500D\u304C\u826F\u304F\u306A\u308B\u306D\n      if (remainder.size()\
    \ >= varphi.size()) remainder %= varphi;\n    }\n  }\n\n  // remainder = x^N mod\
    \ varphi \n  mint ret = 0;\n  assert(remainder.size() <= K);\n  for(int i=0; i<remainder.size();\
    \ i++) {\n    ret += remainder[i] * a[i];\n  }\n\n  return ret;\n}\n"
  code: "#include <vector>\n#include \"formal-power-series/formal-power-series.hpp\"\
    \n\n// AtCoder\u3067\u306Fverify\u3067\u304D\u305F\u304C\u3001LC\u3067\u306F\u3067\
    \u304D\u305A\n// given linear recurrence sequence a_{n+K}= c_1 a_{n+K-1} + c_2\
    \ a_{n+k-2} + \\dots + c_{K-1} a_{n+1} + c_K a_n\n// a_0, a_1, \\dots, a_{K-1}\
    \ are given\n// calculate a_N (N-th term of linear recurrence sequence) time complexity\
    \ is O(K log K log N) (when NNT is used), O(K^2 log N) (when naive convolution\
    \ is used).\ntemplate <typename mint> \nmint Fiduccia(const vector<mint>& a, const\
    \ vector<mint>& c, unsigned long long  N) {\n  if (N < a.size()) return a[N];\n\
    \  assert(a.size() == c.size());\n  int K = c.size();\n\n  FPS<mint> varphi(K+1);\
    \ \n  varphi[K] = mint(1);\n  for(int i=0; i<K; i++) varphi[i] = mint(-1) * c[K-i-1];\n\
    \n  // calculate x^N mod varphi, using square and multiply technique.\n  // Note\
    \ that there is two way to implement the methodlogy. LSB-first algorithm(famous\
    \ one ) and MSB-first alogirthm.\n int msb=0;\n  for (int i=0; 1ULL<< i <=N; i++)\
    \ {\n    if (N & (1ULL << i)) msb = i;\n  }\n  FPS<mint> remainder(1); remainder[0]\
    \ = mint(1);\n  for (int i=msb; i>=0; i--) {\n    if (N & (1ULL << i)) {\n   \
    \   remainder = remainder << 1; // it is equal to remainder *= x.\n      if (remainder.size()\
    \ >= varphi.size()) remainder %= varphi;\n    }\n    if (i != 0) {\n      remainder\
    \ *= remainder; // NTT\u306A\u3089\u3001NTT\u914D\u5217\u3092\u4F7F\u3044\u56DE\
    \u3059\u3053\u3068\u3067\u5B9A\u6570\u500D\u304C\u826F\u304F\u306A\u308B\u306D\
    \n      if (remainder.size() >= varphi.size()) remainder %= varphi;\n    }\n \
    \ }\n\n  // remainder = x^N mod varphi \n  mint ret = 0;\n  assert(remainder.size()\
    \ <= K);\n  for(int i=0; i<remainder.size(); i++) {\n    ret += remainder[i] *\
    \ a[i];\n  }\n\n  return ret;\n}\n"
  dependsOn:
  - formal-power-series/formal-power-series.hpp
  - math/modint.hpp
  - math/external_gcd.hpp
  isVerificationFile: false
  path: formal-power-series/fiduccia.hpp
  requiredBy: []
  timestamp: '2024-07-08 21:43:05+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/verify/fps/yosupo-kth-term-of-linearly-recurrent-sequence.test.cpp
documentation_of: formal-power-series/fiduccia.hpp
layout: document
title: "Fiduccia\u306E\u30A2\u30EB\u30B4\u30EA\u30BA\u30E0 (\u304D\u305F\u307E\u3055\
  \u6CD5?)"
---

~~ なんかLibrary Checkerは通らないが、Typical DP Contest Tのフィボナッチは(NaiveなFPSを使うことで)通った。~~ → 普通にLibrary Checkerも通りました。遅いけど。

提出: [https://atcoder.jp/contests/tdpc/submissions/55372657]

Fiducciaの論文はarchive.orgにあったきがする。ACMのだったはず。

参考にしたもの: [https://qiita.com/ryuhe1/items/da5acbcce4ac1911f47a] のFiducciaのアルゴリズム ~ 二種類の繰り返し二乗法あたりまで。

## Fidducia

```
mint Fidducia(const vector<mint>& a, const vector<mint>& c, unsigned long long N)
```

$a_{n+K}= c_1 a_{n+K-1} + c_2 a_{n+k-2} + \dots + c_{K-1} a_{n+1} + c_K a_n $
という線型漸化式が与えられて、初項

$ a_0, a_1, \dots, a_{K-1} $ がわかっているときに、$a_N$を求める。


### 計算量

畳み込みがFFTなどで高速化されるなら
- $ O(K log K log N) $

ナイーブな畳み込みを使うなら

- $ O(K^2 log N) $



↓↓↓自分でまとめたときの解説みたいなやつ

## 扱うこと

$K+1$項間の線型漸化式を持つ数列の$N$項目は行列累乗で求めたら$O(K^3 \log N)$かかるが、このスライドの手法でやると、もうちょっと速くなる。


## 線形漸化式を持つ数列の遷移を表す行列

$$a_{n+K}= c_1 a_{n+K-1} + c_2 a_{n+k-2} + \dots + c_{K-1} a_{n+1} + c_K a_n$$
という$K+1$項間線形漸化式があるとする。

すると、いわゆる行列累乗の要領で

$$
\begin{bmatrix}
a_{n+1} \\
a_{n} \\
\vdots \\
a_{n-K+3} \\
a_{n-K+2}
\end {bmatrix}

= 
\begin{bmatrix}
c_1   & c_2 & c_3 & c_4 & \dots & c_K \\
1 & 0 & 0 & 0 & \dots & 0 \\
0 & 1 & 0 & 0 & \dots & 0 \\
\vdots & \vdots & \vdots & \vdots & \vdots & \vdots & \\
0 & \dots & 0 & 0  & 1 & 0
\end{bmatrix}

\begin {bmatrix}
a_{n} \\ 
a_{n-1} \\
\vdots \\
a_{n-K+2} \\
a_{n-K+1}
\end {bmatrix}
$$

であるとわかる。

---

すると、先ほどの式を繰り返し適用すると、以下のような関係式が成り立つから、

$$
\begin{bmatrix}
a_N \\
a_{N-1} \\
\vdots \\
a_{N-K+2} \\
a_{N-K+1}
\end{bmatrix}

= 
\begin{bmatrix}
c_1   & c_2 & c_3 & c_4 & \dots & c_K \\
1 & 0 & 0 & 0 & \dots & 0 \\
0 & 1 & 0 & 0 & \dots & 0 \\
\vdots & \vdots & \vdots & \vdots & \vdots & \vdots & \\
0 & \dots & 0 & 0  & 1 & 0
\end{bmatrix}^{N-K}

\begin {bmatrix}
a_K \\
a_{K-1} \\
a_{K_2} \\
\vdots \\
a_1  
\end {bmatrix}
$$
となる。
数列の$N$項目は行列をだいたい$N$回掛けることで求められる。行列の積は1回あたり$O(K^3)$かかるので、$A^{N-1}$を求めるのに繰り返し二乗法を使うと、$a_N$は全体で$O(K^3 \log N)$ の計算量で求められる。


---

## もっと速くできます！！！！

さっきの式:
$$
\begin{bmatrix}
a_N \\
a_{N-1} \\
\vdots \\
a_{N-K+2} \\
a_{N-K+1}
\end{bmatrix}

= 
\begin{bmatrix}
c_1   & c_2 & c_3 & c_4 & \dots & c_K \\
1 & 0 & 0 & 0 & \dots & 0 \\
0 & 1 & 0 & 0 & \dots & 0 \\
\vdots & \vdots & \vdots & \vdots & \vdots & \vdots & \\
0 & \dots & 0 & 0  & 1 & 0
\end{bmatrix}^{N-K}

\begin {bmatrix}
a_K \\
a_{K-1} \\
a_{K_2} \\
\vdots \\
a_1  
\end {bmatrix}
$$


---

これをちょっと変えて、
$$
\begin{bmatrix}
a_{N+K-1} \\
a_{N+K-2} \\
\vdots \\
a_{N+1} \\
a_{N}
\end{bmatrix}

= 
\begin{bmatrix}
c_1   & c_2 & c_3 & c_4 & \dots & c_K \\
1 & 0 & 0 & 0 & \dots & 0 \\
0 & 1 & 0 & 0 & \dots & 0 \\
\vdots & \vdots & \vdots & \vdots & \vdots & \vdots & \\
0 & \dots & 0 & 0  & 1 & 0
\end{bmatrix}^{N}

\begin {bmatrix}
a_{K-1} \\
a_{K-2} \\
\vdots \\
a_1 \\ 
a_0  
\end {bmatrix}
$$

のようにしてみる。

---

### ケーリーハミルトンの定理

緑の線形代数の教科書(線形代数講義と演習 改訂版 小林正典, 寺尾宏明 ) P98 定理17.1を見ると、

>定理17.1 (ケイリーハミルトンの定理)
>$n$次正方行列$A$の固有多項式$\varphi_A(x)$に$A$を代入したものは零行列に等しい

と書いてあります。つまり、$\varphi_A(A) = 0$。ここで $x^N$を $\varphi_A(x)$ で割ったあまりを$r(x)$　と定義する。つまり、 
$x^N = q(x) \varphi_A(x) + r(x)$。ただし$\deg(r(x)) < \deg(\varphi_A(x))$ 

すると、$A^N = r(A^N)$となる。 $r(x) = r_0 + r_1 x + \dots + r_{K-1} x^{K-1}$　とおくと、$A^N = r(A^N) = r_0 E + r_1 A + \dots + r_{K-1} A^{K-1}$とわかる。

---

### 驚きの事実
求めたい$a_N$は、$A^{N}$の一番下の行と、$[a_{K-1}  a_{K-2}   \dots a_0 ]$の内積。
だから、 $E, A^1, A^2, \dots A^{K-1}$の一番下の行のみわかればよい。

ここで、驚きの事実(証明はあとで書く)として、$A^i$ ( $0 \leq i < K$) の一番下の行は、$K-i$列目だけ$1$で、他は$0$となっている。

なので、
$$r_i A^i \begin{bmatrix} a_{K-1} \\ a_{K-2} \\ \vdots \\ a_1 \\ a_0 \end{bmatrix} =
\begin{bmatrix}
 * & * &  * & * & *  \\
 * & * &  * & * & *  \\
\vdots & \vdots & \vdots & \vdots & \vdots & \\
 * & * &  * & * & *  \\
 0 & \dots & r_i  & \dots & 0
 \end{bmatrix}$$
のようになる。($i$があるのは$K-i$列目)



---

よって、
$$ 
r_0 E + r_1 A + \dots + r_{K-1} A^{K-1} = 
\begin{bmatrix}
 * & * &  * & * & *  \\
 * & * &  * & * & *  \\
\vdots & \vdots & \vdots & \vdots & \vdots & \\
 * & * &  * & * & *  \\
 r_{K-1} & r_{K-2} & \dots  & r_{1} & r_0
 \end{bmatrix}
$$
となることがわかるから、$a_N = r_{K-1} a_{K-1} + r_{K-2} a_{K-2} + \dots r_1 a_1 + r_0 a_0$である。

これまでのことをまとめると、
1. 線型漸化式の遷移を表す行列の固有多項式$\varphi_A(x)$を求める。
2. $x^N$を$\varphi_A(x)$で割った余りを求めて、それを$r_0 + r_1 x + \dots + r_{K-1} x^{K-1}$ とする。
3. $a_N = r_{K-1} a_{K-1} + \dots + r_0 a_0$である。

という3ステップで$a_N$が計算できることがわかった。

---

## ステップ1: $\varphi_A(x)$を求める

実は、固有多項式は線型漸化式によって決められるので、入力で線型漸化式を受け取ってから、掃き出し法をして ... みたいな計算は必要なく、($c_1, c_2, \dots c_K$を使った式で)事前に求められる。。(あたりまえかも)

$$

\varphi_A(x) = |xE - A | =  
\begin{vmatrix}
x - c_1  & -c_2 & -c_3 & -c_4 & \dots & -c_K \\
-1 & x & 0 & 0 & \dots & 0 \\
0 & -1 & x & 0 & \dots & 0 \\
\vdots & \vdots & \vdots & \vdots & \vdots & \vdots & \\
0 & \dots & 0 & 0  & -1 & x
\end{vmatrix}
$$

(結論を先に書くと、$=-x^K + c_1 x^{K-1} + \dots + c_{K-1} x^1 + c_{K}$ )

---

## ステップ2: $x^N$を $\varphi_A(x)$で割った余りを求める

多項式除算なので ~~ナイーブにやると$O(K^2)$でできる。行列積よりも速い!~~ →嘘っぽい。

mod $\varphi_A(x)$ 上で$x^N$を計算すればよい。


---

## ステップ3 $a_N = r_K a_K + r_{K-1} a{K-1} + \dots + r_0 a_0$を計算する

はい。やるだけ。

---

## 参考文献
https://blog.miz-ar.info/2019/02/typical-dp-contest-t/ : 
https://qiita.com/ryuhe1/items/da5acbcce4ac1911f47a : Bostan-MoriのMoriさんです