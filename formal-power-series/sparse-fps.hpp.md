---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: formal-power-series/formal-power-series.hpp
    title: "Formal Power Series (\u5F62\u5F0F\u7684\u3079\u304D\u7D1A\u6570)"
  - icon: ':heavy_check_mark:'
    path: math/external_gcd.hpp
    title: math/external_gcd.hpp
  - icon: ':heavy_check_mark:'
    path: math/modint.hpp
    title: modint
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/verify/fps/yosupo-inv-of-formal-power-series-sparse.test.cpp
    title: test/verify/fps/yosupo-inv-of-formal-power-series-sparse.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"formal-power-series/sparse-fps.hpp\"\n\n\n\n#include <vector>\n\
    using namespace std;\n\n#line 1 \"formal-power-series/formal-power-series.hpp\"\
    \n\n\n\n#line 1 \"math/modint.hpp\"\n\n\n\n#line 1 \"math/external_gcd.hpp\"\n\
    \n\n\n#include <tuple>\n\n// g,x,y\ntemplate<typename T>\nconstexpr std::tuple<T,\
    \ T, T> extendedGCD(T a, T b) {\n    T x0 = 1, y0 = 0, x1 = 0, y1 = 1;\n    while\
    \ (b != 0) {\n        T q = a / b;\n        T r = a % b;\n        a = b;\n   \
    \     b = r;\n        \n        T xTemp = x0 - q * x1;\n        x0 = x1;\n   \
    \     x1 = xTemp;\n        \n        T yTemp = y0 - q * y1;\n        y0 = y1;\n\
    \        y1 = yTemp;\n    }\n    return {a, x0, y0};\n}\n\n#line 5 \"math/modint.hpp\"\
    \n#include <type_traits>\n#include <cassert>\n\ntemplate<int MOD, typename T =\
    \ int>\nstruct static_modint {\n    T value;\n\n    constexpr explicit static_modint()\
    \ : value(0) {}\n\n    constexpr static_modint(long long v) {\n        if constexpr\
    \ (std::is_same<T, double>::value) {\n            value = static_cast<T>(v);\n\
    \        }\n        else {\n            value = int(((v % MOD) + MOD) % MOD);\n\
    \        }\n    }\n\n    constexpr static_modint& operator+=(const static_modint&\
    \ other) {\n        if constexpr (std::is_same<T, double>::value) {\n        \
    \    value += other.value;\n        }\n        else {\n            if ((value\
    \ += other.value) >= MOD) value -= MOD;\n        }\n        return *this;\n  \
    \  }\n\n    constexpr static_modint& operator-=(const static_modint& other) {\n\
    \        if constexpr (std::is_same<T, double>::value) {\n            value -=\
    \ other.value;\n        }\n        else {\n            if ((value -= other.value)\
    \ < 0) value += MOD;\n        }\n        return *this;\n    }\n\n    constexpr\
    \ static_modint& operator*=(const static_modint& other) {\n        if constexpr\
    \ (std::is_same<T, double>::value) {\n            value *= other.value;\n    \
    \    }\n        else {\n            value = int((long long)value * other.value\
    \ % MOD);\n        }\n        return *this;\n    }\n\n    constexpr static_modint\
    \ operator+(const static_modint& other) const {\n        return static_modint(*this)\
    \ += other;\n    }\n\n    constexpr static_modint operator-(const static_modint&\
    \ other) const {\n        return static_modint(*this) -= other;\n    }\n\n   \
    \ constexpr static_modint operator*(const static_modint& other) const {\n    \
    \    return static_modint(*this) *= other;\n    }\n\n    constexpr static_modint\
    \ pow(long long exp) const {\n        static_modint base = *this, res = static_modint(1);\n\
    \        while (exp > 0) {\n            if (exp & 1) res *= base;\n          \
    \  base *= base;\n            exp >>= 1;\n        }\n        return res;\n   \
    \ }\n\n    constexpr auto inv() const {\n        if constexpr (std::is_same<T,\
    \ double>::value) {\n            return double(1.0) / static_cast<double>(value);\n\
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
    \ static_cast<double>(value);\n        }\n        else return this->value;\n \
    \   }\n\n    friend std::ostream& operator<<(std::ostream& os, const static_modint&\
    \ mi) {\n        return os << mi.value;\n    }\n\n    friend std::istream& operator>>(std::istream&\
    \ is, static_modint& mi) {\n        long long x;\n        is >> x;\n        mi\
    \ = static_modint(x);\n        return is;\n    }\n};\n\ntemplate <int mod>\nusing\
    \ modint = static_modint<mod>;\nusing modint998244353 = modint<998244353>;\nusing\
    \ modint1000000007 = modint<1000000007>;\n\n\n#line 6 \"formal-power-series/formal-power-series.hpp\"\
    \n#include <algorithm>\n\n\ntemplate <typename mint>\nstruct FPS {\n  std::vector<mint>\
    \ _vec;\n\n  constexpr int lg2(int N) const {\n    int ret = 0;\n    if (N > 0)\
    \ ret = 31 - __builtin_clz(N);\n    if ((1LL << ret) < N) ret++;\n    return ret;\n\
    \  }\n\n  // \u30CA\u30A4\u30FC\u30D6\u306A\u30CB\u30E5\u30FC\u30C8\u30F3\u6CD5\
    \u3067\u306E\u9006\u5143\u8A08\u7B97\n  FPS inv_naive(int deg) const {\n    assert(_vec[0]\
    \ != mint(0)); // \u3055\u3042\u3089\u3056\u308C\u3070\u3001\u9006\u5143\u306E\
    \u3066\u3072\u304E\u3044\u304D\u306B\u3053\u305D\u3042\u3089\u3056\u308C\u3002\
    \n    if (deg == -1) deg = this->size();\n    FPS g(1);\n    g._vec[0] = mint(_vec[0]).inv();\n\
    \    // g_{n+1} = 2 * g_n - f * (g_n)^2\n    for (int d = 1; d < deg; d <<= 1)\
    \ {\n      FPS g_twice = g * mint(2);\n      FPS fgg = (*this).pre(d * 2) * g\
    \ * g;\n\n      g = g_twice - fgg;\n      g.resize(d * 2);\n    }\n\n    return\
    \ g.pre(deg);\n  }\n\n  //*/\n\n  FPS log(int deg = -1) const {\n    assert(_vec[0]\
    \ == mint(1));\n\n    if (deg == -1) deg = size();\n    FPS df = this->diff();\n\
    \    FPS iv = this->inv(deg);\n    FPS ret = (df * iv).pre(deg - 1).integral();\n\
    \n    return ret;\n  }\n\n  FPS exp(int deg = -1) const {\n    assert(_vec[0]\
    \ == mint(0));\n\n    if (deg == -1) deg = size();\n    FPS h = {1}; // h: exp(f)\n\
    \n    // h_2d = h * (f + 1 - Integrate(h' * h.inv() ) )\n\n    for (int d = 1;\
    \ d < deg; d <<= 1) {\n      // h_2d = h_d * (f + 1 - log(h_d))\n      // = h_d\
    \ * (f + 1  - Integral(h' * h.inv() ))\n      // \u3092\u5229\u7528\u3057\u3066\
    \u3001h.inv\u3092\u6F38\u5316\u5F0F\u3067\u66F4\u65B0\u3057\u3066\u3044\u3051\u3070\
    \u5B9A\u6570\u500D\u6539\u5584\u3067\u304D\u308B\u304B\u3068\u601D\u3063\u305F\
    \u304C\u3001\u306A\u3093\u304B\u30D0\u30B0\u3063\u3066\u308B\u3002\n\n      FPS\
    \ fpl1 = ((*this).pre(2*d) + mint(1));\n      FPS logh = h.log(2*d);\n      FPS\
    \ right = (fpl1 - logh);\n\n      h = (h * right).pre(2 * d);\n    }\n\n    return\
    \ h.pre(deg);\n  }\n\n  // f^k \u3092\u8FD4\u3059\n  FPS pow(long long k, int\
    \ deg = -1) const {\n    mint lowest_coeff;\n    if (deg == -1) deg = size();\n\
    \    int lowest_deg = -1;\n\n    if (k == 0) {\n      FPS ret = { mint(1) };\n\
    \      ret.resize(deg);\n      return ret;\n    }\n\n    for (int i = 0; i < size();\
    \ i++) {\n      if (i * k > deg) {\n        return FPS(deg);\n      }\n      if\
    \ (_vec[i] != mint(0)) {\n        lowest_deg = i;\n        lowest_coeff = _vec[i];\n\
    \        \n        int deg3 = deg - k*lowest_deg;\n\n        FPS f2 = (*this /\
    \ lowest_coeff) >> lowest_deg;\n        FPS ret = (lowest_coeff.pow(k) * (f2.log(deg3)\
    \ * mint(k)).exp(deg3) << (lowest_deg * k)).pre(deg);\n        ret.resize(deg);\n\
    \n        return ret;\n      }\n    }\n    assert(false);\n  }\n\n  FPS integral()\
    \ const {\n    const int N = size();\n    FPS ret(N + 1);\n\n    for (int i =\
    \ 0; i < N; i++) ret[i + 1] = _vec[i] * mint(i + 1).inv();\n\n    return ret;\n\
    \  }\n\n  FPS diff() const {\n    const int N = size();\n    FPS ret(max(0, N\
    \ - 1));\n    for (int i = 1; i < N; i++) ret[i - 1] = mint(i) * _vec[i];\n\n\
    \    return ret;\n  }\n\n  FPS(std::vector<mint> vec) : _vec(vec) {\n  }\n\n \
    \ FPS(initializer_list<mint> ilist) : _vec(ilist) {\n  }\n\n  // \u9805\u306E\u6570\
    \u306B\u63C3\u3048\u305F\u307B\u3046\u304C\u3088\u3055\u305D\u3046\n  FPS(int\
    \ sz) : _vec(std::vector<mint>(sz)) {\n  }\n\n  int size() const {\n    return\
    \ _vec.size();\n  }\n\n  FPS& operator+=(const FPS& rhs) {\n    if (rhs.size()\
    \ > this->size()) _vec.resize(rhs.size());\n    for (int i = 0; i < (int)rhs.size();\
    \ ++i) _vec[i] += rhs._vec[i];\n    return *this;\n  }\n\n  FPS& operator-=(const\
    \ FPS& rhs) {\n    if (rhs.size() > this->size()) this->_vec.resize(rhs.size());\n\
    \    for (int i = 0; i < (int)rhs.size(); ++i) _vec[i] -= rhs._vec[i];\n    return\
    \ *this;\n  }\n\n  FPS& operator*=(const FPS& rhs) {\n    _vec = multiply(_vec,\
    \ rhs._vec);\n    return *this;\n  }\n\n  // Nyaan\u5148\u751F\u306E\u30E9\u30A4\
    \u30D6\u30E9\u30EA\u3092\u5927\u5199\u7D4C....\n  FPS& operator/=(const FPS& rhs)\
    \ {\n    if (size() < rhs.size()) {\n      return *this = FPS(0);\n    }\n   \
    \ int sz = size() - rhs.size() + 1;\n    //\n    //    FPS left = (*this).rev().pre(sz);\n\
    \    //    FPS right = rhs.rev();\n    //    right = right.inv(sz);\n    //  \
    \  FPS mp = left*right;\n    //    mp = mp.pre(sz);\n    //    mp = mp.rev();\n\
    \    //    return *this = mp;\n    //    return *this = (left * right).pre(sz).rev();\n\
    \    return *this = ((*this).rev().pre(sz) * rhs.rev().inv(sz)).pre(sz).rev();\n\
    \  }\n\n  FPS& operator%=(const FPS& rhs) {\n    *this -= *this / rhs * rhs;\n\
    \    shrink();\n    return *this;\n  }\n\n  FPS& operator+=(const mint& rhs) {\n\
    \    _vec[0] += rhs;\n    return *this;\n  }\n\n  FPS& operator-=(const mint&\
    \ rhs) {\n    _vec[0] -= rhs;\n    return *this;\n  }\n\n  FPS& operator*=(const\
    \ mint& rhs) {\n    for (int i = 0; i < size(); i++) _vec[i] *= rhs;\n    return\
    \ *this;\n  }\n\n  // \u591A\u9805\u5F0F\u5168\u4F53\u3092\u5B9A\u6570\u9664\u7B97\
    \u3059\u308B\n  FPS& operator/=(const mint& rhs) {\n    for (int i = 0; i < size();\
    \ i++) _vec[i] *= rhs.inv();\n    return *this;\n  }\n\n  // f /= x^sz\n  FPS\
    \ operator>>(int sz) const {\n    if ((int)this->size() <= sz) return {};\n  \
    \  FPS ret(*this);\n    ret._vec.erase(ret._vec.begin(), ret._vec.begin() + sz);\n\
    \    return ret;\n  }\n\n  // f *= x^sz\n  FPS operator<<(int sz) const {\n  \
    \  FPS ret(*this);\n    ret._vec.insert(ret._vec.begin(), sz, mint(0));\n\n  \
    \  return ret;\n  }\n\n  friend FPS operator+(FPS a, const FPS& b) { return a\
    \ += b; }\n  friend FPS operator-(FPS a, const FPS& b) { return a -= b; }\n  friend\
    \ FPS operator*(FPS a, const FPS& b) { return a *= b; }\n  friend FPS operator/(FPS\
    \ a, const FPS& b) { return a /= b; }\n  friend FPS operator%(FPS a, const FPS&\
    \ b) { return a %= b; }\n\n  friend FPS operator+(FPS a, const mint& b) { return\
    \ a += b; }\n  friend FPS operator+(const mint& b, FPS a) { return a += b; }\n\
    \  \n  friend FPS operator-(FPS a, const mint& b) { return a -= b; }\n  friend\
    \ FPS operator-(const mint& b, FPS a) { return a -= b; }\n\n  friend FPS operator*(FPS\
    \ a, const mint& b) { return a *= b; }\n  friend FPS operator*(const mint& b,\
    \ FPS a) { return a *= b; }\n\n  friend FPS operator/(FPS a, const mint& b) {\
    \ return a /= b; }\n  friend FPS operator/(const mint& b, FPS a) { return a /=\
    \ b; }\n\n  // sz\u6B21\u672A\u6E80\u306E\u9805\u3092\u53D6\u3063\u3066\u304F\u308B\
    \n  FPS pre(int sz) const {\n    FPS ret = *this;\n    ret._vec.resize(sz);\n\n\
    \    return ret;\n  }\n\n  FPS rev() const {\n    FPS ret = *this;\n    std::reverse(ret._vec.begin(),\
    \ ret._vec.end());\n\n    return ret;\n  }\n\n  const mint& operator[](size_t\
    \ i) const {\n    return _vec[i];\n  }\n\n  mint& operator[](size_t i) {\n   \
    \ return _vec[i];\n  }\n\n  void resize(int sz) {\n    this->_vec.resize(sz);\n\
    \  }\n\n  void shrink() {\n    while (size() > 0 && _vec.back() == mint(0)) _vec.pop_back();\n\
    \  }\n\n  friend ostream& operator<<(ostream& os, const FPS& fps) {\n    for (int\
    \ i = 0; i < fps.size(); ++i) {\n      if (i > 0) os << \" \";\n      os << fps._vec[i].val();\n\
    \    }\n    return os;\n  }\n\n  // \u4EEE\u60F3\u95A2\u6570\u3063\u3066\u3084\
    \u3064\u3002mod 998244353\u306A\u306E\u304B\u3001\u4ED6\u306ENTT-friendly\u306A\
    mod\u3067\u8003\u3048\u308B\u306E\u304B\u3001\u305D\u308C\u3068\u3082Garner\u3067\
    \u5FA9\u5143\u3059\u308B\u306E\u304B\u3001\u305D\u308C\u3068\u3082\u7573\u307F\
    \u8FBC\u307F\u3092$O(N^2)$\u3067\u59A5\u5354\u3059\u308B\u306E\u304B\u306A\u3069\
    \u306B\u3088\u3063\u3066\u7570\u306A\u308B\n  virtual FPS inv(int deg = -1) const;\n\
    \  virtual void next_inv(FPS& g_d) const; \n  virtual void CooleyTukeyNTT998244353(std::vector<mint>&\
    \ a, bool is_reverse) const;\n  //  virtual FPS exp(int deg=-1) const;\n  virtual\
    \ std::vector<mint> multiply(const std::vector<mint>& a, const std::vector<mint>&\
    \ b);\n};\n\n\n#line 8 \"formal-power-series/sparse-fps.hpp\"\n\n// calculate\
    \ inverse of f(sparse)\n// deg : -1 + ( maximum degree of g )\ntemplate <typename\
    \ mint>\nFPS<mint> inv_sparse(const vector<pair<int,mint>>& f, int deg) {\n  assert(deg\
    \ >= 0);\n  for(int i=0; i<(int)f.size()-1; i++) assert(f[i].first < f[i+1].first);\
    \ \n  assert(f[0].first == 0 && f[0].second != mint(0));\n\n  mint f0inv = f[0].second.inv();\n\
    \  vector<mint> g(deg); g[0] = f0inv;\n  for(int i=0; i<deg-1; i++) {\n    for\
    \ (pair<int,mint> pim : f) {\n      if (i+1 - pim.first >= 0) g[i+1] -= pim.second\
    \ * g[i+1 - pim.first];\n      else continue;\n    }\n    g[i+1] *= f0inv;\n \
    \ }\n\n  return g;\n}\n\ntemplate <typename mint>\nFPS<mint> inv_sparse(const\
    \ FPS<mint>& f, int deg) {\n  vector<pair<int,mint>> vpim;\n  for(int i=0; i<f.size();\
    \ i++) if (f[i] != mint(0)) vpim.emplace_back(i, f[i]);\n\n  return inv_sparse(vpim,\
    \ deg);\n}\n\n\n//tabun baggute masu. TODO\ntemplate<typename mint>\nFPS<mint>\
    \ multiply_sparse(const FPS<mint>& f, const vector<pair<int,mint>>& g, int deg\
    \ = -1) {\n  if (deg == -1) deg = f.size() - 1 + g.back().first + 1;\n\n  FPS<mint>\
    \ ret(deg);\n  for (pair<int,mint> pim : g) {\n    assert(pim.second != 0);\n\
    \    if (pim.second == 0) continue;\n\n    for(int i=0; i<f.size(); i++) {\n \
    \     if (i+pim.first >= ret.size()) continue;\n      if (f[i] != mint(0) && pim.second\
    \ != mint(0)) ret[i+pim.first] += pim.second * f[i];\n    }\n  }\n\n  return ret;\n\
    }\n\ntemplate <typename mint>\nFPS<mint> multiply_sparse(const FPS<mint>& f, const\
    \ FPS<mint>& g, int deg = -1) {\n  vector<pair<int,mint>> vpmi;\n\n  for(int i=0;\
    \ i<g.size(); i++) if (g[i] != mint(0)) vpmi.emplace_back(i, g[i]);\n\n  return\
    \ multiply_sparse(f, vpmi, deg);\n}\n\n\n"
  code: "#ifndef HARUILIB_FORMAL_POWER_SERIES_SPARSE_FPS_HPP\n#define HARUILIB_FORMAL_POWER_SERIES_SPARSE_FPS_HPP\n\
    \n#include <vector>\nusing namespace std;\n\n#include \"formal-power-series/formal-power-series.hpp\"\
    \n\n// calculate inverse of f(sparse)\n// deg : -1 + ( maximum degree of g )\n\
    template <typename mint>\nFPS<mint> inv_sparse(const vector<pair<int,mint>>& f,\
    \ int deg) {\n  assert(deg >= 0);\n  for(int i=0; i<(int)f.size()-1; i++) assert(f[i].first\
    \ < f[i+1].first); \n  assert(f[0].first == 0 && f[0].second != mint(0));\n\n\
    \  mint f0inv = f[0].second.inv();\n  vector<mint> g(deg); g[0] = f0inv;\n  for(int\
    \ i=0; i<deg-1; i++) {\n    for (pair<int,mint> pim : f) {\n      if (i+1 - pim.first\
    \ >= 0) g[i+1] -= pim.second * g[i+1 - pim.first];\n      else continue;\n   \
    \ }\n    g[i+1] *= f0inv;\n  }\n\n  return g;\n}\n\ntemplate <typename mint>\n\
    FPS<mint> inv_sparse(const FPS<mint>& f, int deg) {\n  vector<pair<int,mint>>\
    \ vpim;\n  for(int i=0; i<f.size(); i++) if (f[i] != mint(0)) vpim.emplace_back(i,\
    \ f[i]);\n\n  return inv_sparse(vpim, deg);\n}\n\n\n//tabun baggute masu. TODO\n\
    template<typename mint>\nFPS<mint> multiply_sparse(const FPS<mint>& f, const vector<pair<int,mint>>&\
    \ g, int deg = -1) {\n  if (deg == -1) deg = f.size() - 1 + g.back().first + 1;\n\
    \n  FPS<mint> ret(deg);\n  for (pair<int,mint> pim : g) {\n    assert(pim.second\
    \ != 0);\n    if (pim.second == 0) continue;\n\n    for(int i=0; i<f.size(); i++)\
    \ {\n      if (i+pim.first >= ret.size()) continue;\n      if (f[i] != mint(0)\
    \ && pim.second != mint(0)) ret[i+pim.first] += pim.second * f[i];\n    }\n  }\n\
    \n  return ret;\n}\n\ntemplate <typename mint>\nFPS<mint> multiply_sparse(const\
    \ FPS<mint>& f, const FPS<mint>& g, int deg = -1) {\n  vector<pair<int,mint>>\
    \ vpmi;\n\n  for(int i=0; i<g.size(); i++) if (g[i] != mint(0)) vpmi.emplace_back(i,\
    \ g[i]);\n\n  return multiply_sparse(f, vpmi, deg);\n}\n\n#endif // HARUILIB_FORMAL_POWER_SERIES_SPARSE_FPS_HPP"
  dependsOn:
  - formal-power-series/formal-power-series.hpp
  - math/modint.hpp
  - math/external_gcd.hpp
  isVerificationFile: false
  path: formal-power-series/sparse-fps.hpp
  requiredBy: []
  timestamp: '2025-02-28 14:43:36+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/verify/fps/yosupo-inv-of-formal-power-series-sparse.test.cpp
documentation_of: formal-power-series/sparse-fps.hpp
layout: document
title: sparse-fps
---

スパース(非0な項が多い)な形式的べき級数で効率的に計算する。

## inv_sparse
スパースな形式的べき級数の逆元を効率的(?)に計算する。
定数項は0でないことを要求する。

```
FPS inv_sparse(const vector<pair<int,mint>>& f, int deg) 
```

```
FPS inv_sparse(const FPS& f, int deg) 
```

### 計算量
非0な項の数を $K$、先頭の$N$項を求めるとして
- $O(NK)$

### 原理
そんなに難しくないけど、忘れてしまったときのために一応書いておく。

$g := f^{-1}$ として、$g$の$i$項目まで計算できているとする。

ここで、畳み込みの定義と逆元の定義から、
$g[i+1]f[0] + g[i] f[1] + \dots + g[1] f[i] + g[0] f[i+1] = 0$。変形して

$g[i+1] =  - \frac{g[1] f[1] + \dots + g[1] f[i] + g[0] f[i+1] }{f[0]} $　ここで、$f$はスパースだから、非ゼロな項は$K$個以下。よって$g[i+1]$を$O(K)$で求められる。これを$O(N)$回繰り返すから、全体で$O(NK)$で求められる。