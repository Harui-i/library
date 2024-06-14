---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: formal-power-series/formal-power-series.hpp
    title: "Formal Power Series (\u5F62\u5F0F\u7684\u3079\u304D\u7D1A\u6570)"
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
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://judge.yosupo.jp/problem/inv_of_formal_power_series
  bundledCode: "#line 1 \"test/verify/yosupo-inv-of-formal-power-series-naive-test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/inv_of_formal_power_series\"\
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
    \ vector<mint>& a, const vector<mint>& b);\n  };\n\n\n#line 6 \"test/verify/yosupo-inv-of-formal-power-series-naive-test.cpp\"\
    \n\nusing mint = modint998244353;\n\n\nint main() {\n  ios::sync_with_stdio(0);\
    \ cin.tie(0); cout.tie(0);\n  int N; cin >> N;\n  vector<modint998244353>a(N);\n\
    \  for(int i=0; i<N; i++) cin >> a[i];\n\n  FPS a_fps(a);\n  cout << a_fps.inv_naive(N)\
    \ << endl;\n\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/inv_of_formal_power_series\"\
    \n\n#include \"../../template/template.hpp\"\n#include \"../../math/modint.hpp\"\
    \n#include \"../../formal-power-series/formal-power-series.hpp\"\n\nusing mint\
    \ = modint998244353;\n\n\nint main() {\n  ios::sync_with_stdio(0); cin.tie(0);\
    \ cout.tie(0);\n  int N; cin >> N;\n  vector<modint998244353>a(N);\n  for(int\
    \ i=0; i<N; i++) cin >> a[i];\n\n  FPS a_fps(a);\n  cout << a_fps.inv_naive(N)\
    \ << endl;\n\n}\n"
  dependsOn:
  - template/template.hpp
  - math/modint.hpp
  - formal-power-series/formal-power-series.hpp
  - math/modint.hpp
  isVerificationFile: false
  path: test/verify/yosupo-inv-of-formal-power-series-naive-test.cpp
  requiredBy: []
  timestamp: '2024-06-14 19:20:17+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: test/verify/yosupo-inv-of-formal-power-series-naive-test.cpp
layout: document
redirect_from:
- /library/test/verify/yosupo-inv-of-formal-power-series-naive-test.cpp
- /library/test/verify/yosupo-inv-of-formal-power-series-naive-test.cpp.html
title: test/verify/yosupo-inv-of-formal-power-series-naive-test.cpp
---
