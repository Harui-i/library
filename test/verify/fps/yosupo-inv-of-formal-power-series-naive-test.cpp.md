---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: formal-power-series/formal-power-series.hpp
    title: "Formal Power Series (\u5F62\u5F0F\u7684\u3079\u304D\u7D1A\u6570)"
  - icon: ':heavy_check_mark:'
    path: formal-power-series/fps-sparse.hpp
    title: "fps-sparse(\u758E\u306A\u5834\u5408\u306E\u9AD8\u901F\u5316)"
  - icon: ':heavy_check_mark:'
    path: math/external_gcd.hpp
    title: math/external_gcd.hpp
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
    - https://judge.yosupo.jp/problem/inv_of_formal_power_series
  bundledCode: "#line 1 \"test/verify/fps/yosupo-inv-of-formal-power-series-naive-test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/inv_of_formal_power_series\"\
    \n\n#line 1 \"template/template.hpp\"\n#include <iostream>\n#include <cassert>\n\
    using namespace std;\nusing ll = long long;\ntemplate<class T> inline bool chmax(T&\
    \ a, const T& b) {if (a<b) {a=b; return true;} return false;}\ntemplate<class\
    \ T> inline bool chmin(T& a, const T& b) {if (b<a) {a=b; return true;} return\
    \ false;}\nconst int INTINF = 1000001000;\nconst int INTMAX = 2147483647;\nconst\
    \ ll LLMAX = 9223372036854775807;\nconst ll LLINF = 1000000000000000000;\n#line\
    \ 1 \"math/modint.hpp\"\n\n\n\n#line 1 \"math/external_gcd.hpp\"\n\n\n\n#include\
    \ <tuple>\n\n// g,x,y\ntemplate<typename T>\nconstexpr std::tuple<T, T, T> extendedGCD(T\
    \ a, T b) {\n    T x0 = 1, y0 = 0, x1 = 0, y1 = 1;\n    while (b != 0) {\n   \
    \     T q = a / b;\n        T r = a % b;\n        a = b;\n        b = r;\n   \
    \     \n        T xTemp = x0 - q * x1;\n        x0 = x1;\n        x1 = xTemp;\n\
    \        \n        T yTemp = y0 - q * y1;\n        y0 = y1;\n        y1 = yTemp;\n\
    \    }\n    return {a, x0, y0};\n}\n\n#line 5 \"math/modint.hpp\"\n#include <type_traits>\n\
    #line 7 \"math/modint.hpp\"\n\ntemplate<int MOD, typename T = int>\nstruct static_modint\
    \ {\n    T value;\n\n    constexpr explicit static_modint() : value(0) {}\n\n\
    \    constexpr static_modint(long long v) {\n        if constexpr (std::is_same<T,\
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
    \ -= other;\n    }\n\n    constexpr static_modint operator*(const static_modint&\
    \ other) const {\n        return static_modint(*this) *= other;\n    }\n\n   \
    \ constexpr static_modint pow(long long exp) const {\n        static_modint base\
    \ = *this, res = static_modint(1);\n        while (exp > 0) {\n            if\
    \ (exp & 1) res *= base;\n            base *= base;\n            exp >>= 1;\n\
    \        }\n        return res;\n    }\n\n    constexpr static_modint inv() const\
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
    \n\n#line 1 \"formal-power-series/formal-power-series.hpp\"\n\n\n\n#include <algorithm>\n\
    #line 6 \"formal-power-series/formal-power-series.hpp\"\n#include <vector>\n\n\
    #line 9 \"formal-power-series/formal-power-series.hpp\"\n\ntemplate <typename\
    \ mint>\nstruct FPS {\n  std::vector<mint> _vec;\n\n  constexpr int lg2(int N)\
    \ const {\n    int ret = 0;\n    if (N > 0) ret = 31 - __builtin_clz(N);\n   \
    \ if ((1LL << ret) < N) ret++;\n    return ret;\n  }\n\n  // \u30CA\u30A4\u30FC\
    \u30D6\u306A\u30CB\u30E5\u30FC\u30C8\u30F3\u6CD5\u3067\u306E\u9006\u5143\u8A08\
    \u7B97\n  FPS inv_naive(int deg) const {\n    assert(_vec[0] != mint(0));  //\
    \ \u3055\u3042\u3089\u3056\u308C\u3070\u3001\u9006\u5143\u306E\u3066\u3072\u304E\
    \u3044\u304D\u306B\u3053\u305D\u3042\u3089\u3056\u308C\u3002\n    if (deg == -1)\
    \ deg = this->size();\n    FPS g(1);\n    g._vec[0] = mint(_vec[0]).inv();\n \
    \   // g_{n+1} = 2 * g_n - f * (g_n)^2\n    for (int d = 1; d < deg; d <<= 1)\
    \ {\n      FPS g_twice = g * mint(2);\n      FPS fgg = (*this).pre(d * 2) * g\
    \ * g;\n\n      g = g_twice - fgg;\n      g.resize(d * 2);\n    }\n\n    return\
    \ g.pre(deg);\n  }\n\n  //*/\n\n  FPS log(int deg = -1) const {\n    assert(_vec[0]\
    \ == mint(1));\n\n    if (deg == -1) deg = size();\n    FPS df = this->diff();\n\
    \    FPS iv = this->inv(deg);\n    FPS ret = (df * iv).pre(deg - 1).integral();\n\
    \n    return ret;\n  }\n\n  FPS exp(int deg = -1) const {\n    assert(_vec[0]\
    \ == mint(0));\n\n    if (deg == -1) deg = size();\n    FPS h = {1};  // h: exp(f)\n\
    \n    // h_2d = h * (f + 1 - Integrate(h' * h.inv() ) )\n\n    for (int d = 1;\
    \ d < deg; d <<= 1) {\n      // h_2d = h_d * (f + 1 - log(h_d))\n      // = h_d\
    \ * (f + 1  - Integral(h' * h.inv() ))\n      // \u3092\u5229\u7528\u3057\u3066\
    \u3001h.inv\u3092\u6F38\u5316\u5F0F\u3067\u66F4\u65B0\u3057\u3066\u3044\u3051\u3070\
    \u5B9A\u6570\u500D\u6539\u5584\u3067\u304D\u308B\u304B\u3068\u601D\u3063\u305F\
    \u304C\u3001\u306A\u3093\u304B\u30D0\u30B0\u3063\u3066\u308B\u3002\n\n      FPS\
    \ fpl1 = ((*this).pre(2 * d) + mint(1));\n      FPS logh = h.log(2 * d);\n   \
    \   FPS right = (fpl1 - logh);\n\n      h = (h * right).pre(2 * d);\n    }\n\n\
    \    return h.pre(deg);\n  }\n\n  // f^k \u3092\u8FD4\u3059\n  FPS pow(long long\
    \ k, int deg = -1) const {\n    mint lowest_coeff;\n    if (deg == -1) deg = size();\n\
    \    int lowest_deg = -1;\n\n    if (k == 0) {\n      FPS ret = {mint(1)};\n \
    \     ret.resize(deg);\n      return ret;\n    }\n\n    for (int i = 0; i < size();\
    \ i++) {\n      if (i * k > deg) {\n        return FPS(deg);\n      }\n      if\
    \ (_vec[i] != mint(0)) {\n        lowest_deg = i;\n        lowest_coeff = _vec[i];\n\
    \n        int deg3 = deg - k * lowest_deg;\n\n        FPS f2 = (*this / lowest_coeff)\
    \ >> lowest_deg;\n        FPS ret = (lowest_coeff.pow(k) * (f2.log(deg3) * mint(k)).exp(deg3)\
    \ << (lowest_deg * k)).pre(deg);\n        ret.resize(deg);\n\n        return ret;\n\
    \      }\n    }\n    assert(false);\n  }\n\n  FPS integral() const {\n    const\
    \ int N = size();\n    FPS ret(N + 1);\n\n    for (int i = 0; i < N; i++) ret[i\
    \ + 1] = _vec[i] * mint(i + 1).inv();\n\n    return ret;\n  }\n\n  FPS diff()\
    \ const {\n    const int N = size();\n    FPS ret(std::max(0, N - 1));\n    for\
    \ (int i = 1; i < N; i++) ret[i - 1] = mint(i) * _vec[i];\n\n    return ret;\n\
    \  }\n\n  FPS to_egf() const {\n    const int N = size();\n    FPS ret(N);\n \
    \   mint fact = mint(1);\n    for (int i = 0; i < N; i++) {\n      ret[i] = _vec[i]\
    \ * fact.inv();\n      fact *= mint(i + 1);\n    }\n\n    return ret;\n  }\n\n\
    \  FPS to_ogf() const {\n    const int N = size();\n    FPS ret(N);\n    mint\
    \ fact = mint(1);\n    for (int i = 0; i < N; i++) {\n      ret[i] = _vec[i] *\
    \ fact;\n      fact *= mint(i + 1);\n    }\n    return ret;\n  }\n\n  FPS(std::vector<mint>\
    \ vec) : _vec(vec) {}\n\n  FPS(std::initializer_list<mint> ilist) : _vec(ilist)\
    \ {}\n\n  // \u9805\u306E\u6570\u306B\u63C3\u3048\u305F\u307B\u3046\u304C\u3088\
    \u3055\u305D\u3046\n  FPS(int sz) : _vec(std::vector<mint>(sz)) {}\n\n  int size()\
    \ const { return _vec.size(); }\n\n  FPS& operator+=(const FPS& rhs) {\n    if\
    \ (rhs.size() > this->size()) _vec.resize(rhs.size());\n    for (int i = 0; i\
    \ < (int)rhs.size(); ++i) _vec[i] += rhs._vec[i];\n    return *this;\n  }\n\n\
    \  FPS& operator-=(const FPS& rhs) {\n    if (rhs.size() > this->size()) this->_vec.resize(rhs.size());\n\
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
    \n  friend FPS operator-(FPS a, const mint& b) { return a -= b; }\n  friend FPS\
    \ operator-(const mint& b, FPS a) { return a -= b; }\n\n  friend FPS operator*(FPS\
    \ a, const mint& b) { return a *= b; }\n  friend FPS operator*(const mint& b,\
    \ FPS a) { return a *= b; }\n\n  friend FPS operator/(FPS a, const mint& b) {\
    \ return a /= b; }\n  friend FPS operator/(const mint& b, FPS a) { return a /=\
    \ b; }\n\n  FPS mul(FPS g, int deg = -1) const { return ((*this) * g).pre(deg);\
    \ }\n\n  // sz\u6B21\u672A\u6E80\u306E\u9805\u3092\u53D6\u3063\u3066\u304F\u308B\
    \n  FPS pre(int sz) const {\n    FPS ret = *this;\n    ret._vec.resize(sz);\n\n\
    \    return ret;\n  }\n\n  FPS rev() const {\n    FPS ret = *this;\n    std::reverse(ret._vec.begin(),\
    \ ret._vec.end());\n\n    return ret;\n  }\n\n  const mint& operator[](size_t\
    \ i) const { return _vec[i]; }\n\n  mint& operator[](size_t i) { return _vec[i];\
    \ }\n\n  void resize(int sz) { this->_vec.resize(sz); }\n\n  // \u5168\u3066\u306E\
    \u4E0D\u8981\u306A\u672B\u5C3E\u306E0\u3092\u524A\u9664\u3059\u308B\n  void shrink()\
    \ {\n    while (size() > 0 && _vec.back() == mint(0)) _vec.pop_back();\n  }\n\n\
    \  friend std::ostream& operator<<(std::ostream& os, const FPS& fps) {\n    for\
    \ (int i = 0; i < fps.size(); ++i) {\n      if (i > 0) os << \" \";\n      os\
    \ << fps._vec[i].val();\n    }\n    return os;\n  }\n\n  // \u4EEE\u60F3\u95A2\
    \u6570\u3063\u3066\u3084\u3064\u3002mod\n  // 998244353\u306A\u306E\u304B\u3001\
    \u4ED6\u306ENTT-friendly\u306Amod\u3067\u8003\u3048\u308B\u306E\u304B\u3001\u305D\
    \u308C\u3068\u3082Garner\u3067\u5FA9\u5143\u3059\u308B\u306E\u304B\u3001\u305D\
    \u308C\u3068\u3082\u7573\u307F\u8FBC\u307F\u3092$O(N^2)$\u3067\u59A5\u5354\u3059\
    \u308B\u306E\u304B\u306A\u3069\u306B\u3088\u3063\u3066\u7570\u306A\u308B\n  virtual\
    \ FPS inv(int deg = -1) const;\n  virtual FPS mul_sparse(const FPS& g, int deg\
    \ = -1) const;  // fps-sparse.hpp\u3067\u5B9F\u88C5\u3057\u305F\u308A\n  virtual\
    \ FPS inv_sparse(int deg) const;                     // fps-sparse.hpp\u3067\u5B9F\
    \u88C5\u3057\u305F\u308A\n  virtual FPS exp_sparse(int deg) const;           \
    \          // fps-sparse.hpp\u3067\u5B9F\u88C5\u3057\u305F\u308A\n  virtual FPS\
    \ log_sparse(int deg) const;                     // fps-sparse.hpp\u3067\u5B9F\
    \u88C5\u3057\u305F\u308A\n  virtual FPS pow_sparse(long long k, int deg) const;\
    \        // fps-sparse.hpp\u3067\u5B9F\u88C5\u3057\u305F\u308A\n\n  virtual void\
    \ next_inv(FPS& g_d) const;\n  virtual void CooleyTukeyNTT998244353(std::vector<mint>&\
    \ a, bool is_reverse) const;\n  //  virtual FPS exp(int deg=-1) const;\n  virtual\
    \ std::vector<mint> multiply(const std::vector<mint>& a, const std::vector<mint>&\
    \ b);\n};\n\n#line 1 \"formal-power-series/fps-sparse.hpp\"\n\n\n\n#line 6 \"\
    formal-power-series/fps-sparse.hpp\"\n\n// forward decl to avoid circular include:\
    \ formal-power-series.hpp includes this file\ntemplate <typename mint>\nstruct\
    \ FPS;\n\n// FPS\u306E\u975E\u30BC\u30ED\u306A\u9805\u3092\u96C6\u3081\u305Fvector<pair<int,mint>>\u3092\
    \u8FD4\u3059\ntemplate <typename mint>\nstd::vector<std::pair<int, mint>> get_nonzeros(const\
    \ FPS<mint>& f) {\n  std::vector<std::pair<int, mint>> ret;\n  for (int i = 0;\
    \ i < f.size(); i++) {\n    if (f[i] != mint(0)) ret.emplace_back(i, f[i]);\n\
    \  }\n  return ret;\n}\n\n// \u2193--- inverse of sparse fps ---\u2193\n// calculate\
    \ inverse of f(sparse)\n// deg : -1 + ( maximum degree of g )\ntemplate <typename\
    \ mint>\nFPS<mint> inv_sparse(const std::vector<std::pair<int, mint>>& f, int\
    \ deg) {\n  assert(deg >= 0);\n  for (int i = 0; i < (int)f.size() - 1; i++) assert(f[i].first\
    \ < f[i + 1].first);\n  assert(f[0].first == 0 && f[0].second != mint(0));\n\n\
    \  mint f0inv = f[0].second.inv();\n  std::vector<mint> g(deg);\n  g[0] = f0inv;\n\
    \  for (int i = 0; i < deg - 1; i++) {\n    for (std::pair<int, mint> pim : f)\
    \ {\n      if (i + 1 - pim.first >= 0)\n        g[i + 1] -= pim.second * g[i +\
    \ 1 - pim.first];\n      else\n        continue;\n    }\n    g[i + 1] *= f0inv;\n\
    \  }\n\n  return g;\n}\n\ntemplate <typename mint>\nFPS<mint> inv_sparse(const\
    \ FPS<mint>& f, int deg) {\n  return inv_sparse(get_nonzeros(f), deg);\n}\n\n\
    template <typename mint>\nFPS<mint> FPS<mint>::inv_sparse(int deg) const {\n \
    \ return ::inv_sparse(*this, deg);\n}\n\n// \u2191--- inverse of sparse fps ----\u2191\
    \n\n// exp(f)\u306Edeg\u6B21\u672A\u6E80\u306E\u90E8\u5206\u3092\u6C42\u3081\u308B\
    \u3002\n// F := exp(f) = F_0 + F_1 x + F_2 x^2 + ... \u3068\u3059\u308B\u3002\n\
    // F' = F * f' \u306A\u306E\u3067\n// F_1 + 2F_2 x + 3F_3 x^3 + ... = f' F.\n\
    // 0\u4EE5\u4E0A\u306E\u6574\u6570i\u306B\u3064\u3044\u3066\u3001i\u6B21\u306E\
    \u9805\u306B\u6CE8\u76EE\u3059\u308B\u3068\u3001\n// (i+1) * F_{i+1} = [x^i] (f'\
    \ * F)\n// \u3068\u308F\u304B\u308B\u3002F\u306F0,1,...,i\u6B21\u307E\u3067\u308F\
    \u304B\u3063\u3066\u308C\u3070F_{i+1}\u3082\u308F\u304B\u308B\u3068\u3044\u3046\
    \u3053\u3068\u306B\u306A\u308B\u3002f'\u306F\u30B9\u30D1\u30FC\u30B9\u3060\u304B\
    \u3089F_{i+1}\u306F\u305F\u304B\u3060\u304BK\u56DE\u306E\u8A08\u7B97\u3067\u6C42\
    \u3081\u3089\u308C\u308B.\n\ntemplate <typename mint>\nFPS<mint> exp_sparse(const\
    \ FPS<mint>& f, int deg) {\n  FPS<mint> F(deg);\n  F[0] = mint(1);\n\n  std::vector<std::pair<int,\
    \ mint>> nonzero_fdiff = get_nonzeros(f.diff());\n\n  for (int i = 0; i + 1 <\
    \ deg; i++) {\n    // F[i+1]\u3092\u6C42\u3081\u308B\n    // (i+1) * F_{i+1} =\
    \ [x^i] (f' * F)\n\n    for (std::pair<int, mint> pim : nonzero_fdiff) {\n   \
    \   int a = pim.first;\n      // F\u306Ei-a\u6B21\u306E\u9805\u3092\u8DB3\u3057\
    \u3066\u3044\u304F\n      if (i - a < 0) continue;\n      assert(i - a >= 0);\n\
    \      assert(i + 1 > i - a);\n      F[i + 1] += pim.second * F[i - a];\n    }\n\
    \    F[i + 1] /= mint(i + 1);\n  }\n  return F;\n}\n\ntemplate <typename mint>\n\
    FPS<mint> FPS<mint>::exp_sparse(int deg) const {\n  return ::exp_sparse(*this,\
    \ deg);\n}\n\ntemplate <typename mint>\nFPS<mint> log_sparse(const FPS<mint>&\
    \ f, int deg) {\n  FPS<mint> f_inv = inv_sparse(f, deg);\n  return multiply_sparse(f_inv,\
    \ f.diff(), deg).integral().pre(deg);\n}\n\ntemplate <typename mint>\nFPS<mint>\
    \ FPS<mint>::log_sparse(int deg) const {\n  return ::log_sparse(*this, deg);\n\
    }\n\n// g := f ^ k\n// g' = k * f^{k-1} * f'\n// fg' = k * f^k * f'\n// fg' =\
    \ k * g * f'\n\ntemplate <typename mint>\nFPS<mint> pow_sparse(const FPS<mint>&\
    \ f, long long k, int deg) {\n  if (k == 0) {\n    FPS ret = {mint(1)};\n    ret.resize(deg);\n\
    \    return ret;\n  }\n\n  if (f[0] == mint(0)) {\n    int mindeg = 0;\n    while\
    \ (mindeg < deg && f[mindeg] == mint(0)) mindeg++;\n\n    // (x^{mindeg})^k =\
    \ x^{mindeg * k}\n    // mindeg * k >= deg \u21D4 k >= floor(deg / mindeg) \u3067\
    \u3042\u308B\u3002\n    // \u2192: \u81EA\u660E (k >= deg / mindeg >= floor(deg\
    \ / mindeg) \u306A\u306E\u3067)\n\n    // \u2190\u306B\u3064\u3044\u3066:  h1:\
    \ k >= floor(deg / mindeg) \u3092\u4EEE\u5B9A\u3057\u3066 Goal: k >= deg\u3092\
    \u793A\u3059\u3002\n    // deg = mindeg * q + r (0 <= r < mindeg)\u3068\u8868\u3059\
    \u3002\u3053\u308C\u3092\u4F7F\u3046\u3068\n    // h1: k >= q.\n    // Goal: k\
    \ >= mindeg * q + r.\n\n    // mindeg * k > LLINF\n    // mindeg > LLINF / k\n\
    \    constexpr long long INF = 4450000000011100000;\n    if (mindeg > INF / k\
    \ || mindeg * k >= deg) {\n      FPS<mint> ret(deg);\n      assert(ret[0] == mint(0));\n\
    \      return ret;\n    }\n    return pow_sparse(f >> mindeg, k, deg - mindeg\
    \ * k) << k * mindeg;\n  }\n\n  FPS<mint> g(deg);\n  assert(f[0] != mint(0));\n\
    \  g[0] = f[0].pow(k);\n\n  std::vector<std::pair<int, mint>> nonzero_f = get_nonzeros(f);\n\
    \n  for (int i = 0; i + 1 < deg; i++) {\n    // g[0], g[1], ..., g[i]\u304C\u5224\
    \u3063\u3066\u3044\u308B\u72B6\u614B\u3067,x^i\u306B\u6CE8\u76EE\u3057\u3066g[i+1]\u3092\
    \u6C42\u3081\u306B\u3044\u304F\u3002\n\n    // fg' = (f[0] + f[1]x + f[2]x^2 +\
    \ ... + f[i]x^i)(g[1] + 2g[2]x + 3g[3]x^2 + ... + ig[i]x^{i-1} + (i+1)g[i+1]x^i)\n\
    \    // (\u5DE6) kgf' = k(g[0] + g[1]x + g[2]x^2 + ... + g[i]x^i) * (f[1] + 2*f[2]x\
    \ 3*f[3]x^2 + ... + i*f[i]x^{i-1} +\n    // (i+1)*f[i+1]x^i) (\u53F3)\n\n    //\
    \ \u5DE6\u306Ex^i\u306E\u4FC2\u6570\u306F f[0](i+1)g[i+1] + f[1]ig[i] + f[2](i-1)g[i-1]\
    \ + ... + f[i]g[1]\n    // \u53F3\u306Ex^i\u306E\u4FC2\u6570\u306F k * ( g[0]*(i+1)f[i+1]\
    \ +  g[1]if[i] + ... + g[i]*1f[1])\n\n    // f[0](i+1)g[i+1] = k * (g[0]*(i+1)f[i+1]\
    \ + g[1]if[i] + ... + g[i]*1f[1]) - f[1]ig[i] - f[2](i-1)g[i-1] - ... -\n    //\
    \ f[i]g[1]\n\n    mint sum(0);\n    for (std::pair<int, mint> pim : nonzero_f)\
    \ {\n      // f[pim.first]: pim.second\n      // \u5DE6\u3067\u306F 0 <= pim.first\
    \ <= i\n      // \u53F3\u3067\u306F 1 <= pim.first <= i+1\u306E\u90E8\u5206\u3092\
    \u898B\u308B\n\n      if (0 <= pim.first && pim.first <= i) sum -= pim.second\
    \ * mint(i + 1 - pim.first) * g[i + 1 - pim.first];\n      if (1 <= pim.first\
    \ && pim.first <= i + 1) sum += mint(k) * g[i + 1 - pim.first] * mint(pim.first)\
    \ * pim.second;\n    }\n\n    // for (int j=0; j<=i; j++) sum += mint(k) * g[j]\
    \ * mint(i+1-j) * f[i+1-j];\n    // for (int j=1; j<=i; j++) sum -= f[j] * mint(i+1-j)\
    \ * g[i+1-j];\n\n    g[i + 1] = sum / f[0] / mint(i + 1);\n  }\n\n  return g;\n\
    }\n\ntemplate <typename mint>\nFPS<mint> FPS<mint>::pow_sparse(long long k, int\
    \ deg) const {\n  return ::pow_sparse(*this, k, deg);\n}\n\n// tabun baggute masu.\n\
    template <typename mint>\nFPS<mint> multiply_sparse(const FPS<mint>& f, const\
    \ std::vector<std::pair<int, mint>>& g, int deg = -1) {\n  if (deg == -1) deg\
    \ = f.size() - 1 + g.back().first + 1;\n\n  FPS<mint> ret(deg);\n  for (std::pair<int,\
    \ mint> pim : g) {\n    assert(pim.second != 0);\n    if (pim.second == 0) continue;\n\
    \n    for (int i = 0; i < f.size(); i++) {\n      if (i + pim.first >= ret.size())\
    \ continue;\n      if (f[i] != mint(0) && pim.second != mint(0)) ret[i + pim.first]\
    \ += pim.second * f[i];\n    }\n  }\n\n  return ret;\n}\n\ntemplate <typename\
    \ mint>\nFPS<mint> multiply_sparse(const FPS<mint>& f, const FPS<mint>& g, int\
    \ deg = -1) {\n  std::vector<std::pair<int, mint>> vpmi;\n\n  for (int i = 0;\
    \ i < g.size(); i++)\n    if (g[i] != mint(0)) vpmi.emplace_back(i, g[i]);\n\n\
    \  return multiply_sparse(f, vpmi, deg);\n}\n\ntemplate <typename mint>\nFPS<mint>\
    \ FPS<mint>::mul_sparse(const FPS<mint>& g, int deg) const {\n  return multiply_sparse(*this,\
    \ g, deg);\n}\n\n\n#line 304 \"formal-power-series/formal-power-series.hpp\"\n\
    \n\n#line 6 \"test/verify/fps/yosupo-inv-of-formal-power-series-naive-test.cpp\"\
    \n\nusing mint = modint998244353;\n\n\nint main() {\n  ios::sync_with_stdio(0);\
    \ cin.tie(0); cout.tie(0);\n  int N; cin >> N;\n  vector<modint998244353>a(N);\n\
    \  for(int i=0; i<N; i++) cin >> a[i];\n\n  FPS a_fps(a);\n  cout << a_fps.inv_naive(N)\
    \ << endl;\n\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/inv_of_formal_power_series\"\
    \n\n#include \"template/template.hpp\"\n#include \"math/modint.hpp\"\n#include\
    \ \"formal-power-series/formal-power-series.hpp\"\n\nusing mint = modint998244353;\n\
    \n\nint main() {\n  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);\n  int N;\
    \ cin >> N;\n  vector<modint998244353>a(N);\n  for(int i=0; i<N; i++) cin >> a[i];\n\
    \n  FPS a_fps(a);\n  cout << a_fps.inv_naive(N) << endl;\n\n}\n"
  dependsOn:
  - template/template.hpp
  - math/modint.hpp
  - math/external_gcd.hpp
  - formal-power-series/formal-power-series.hpp
  - math/modint.hpp
  - formal-power-series/fps-sparse.hpp
  isVerificationFile: false
  path: test/verify/fps/yosupo-inv-of-formal-power-series-naive-test.cpp
  requiredBy: []
  timestamp: '2025-11-05 12:09:20+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: test/verify/fps/yosupo-inv-of-formal-power-series-naive-test.cpp
layout: document
redirect_from:
- /library/test/verify/fps/yosupo-inv-of-formal-power-series-naive-test.cpp
- /library/test/verify/fps/yosupo-inv-of-formal-power-series-naive-test.cpp.html
title: test/verify/fps/yosupo-inv-of-formal-power-series-naive-test.cpp
---
