---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: convolution/multiple-zeta-moebius-transform.hpp
    title: "\u500D\u6570\u306B\u3064\u3044\u3066\u306E\u30BC\u30FC\u30BF\u5909\u63DB\
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
    PROBLEM: https://judge.yosupo.jp/problem/aplusb
    links:
    - https://judge.yosupo.jp/problem/aplusb
  bundledCode: "#line 1 \"test/unittest/unittest-multiple-moebius-transform.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n\n#line 1 \"template/template.hpp\"\
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
    \ 5 \"test/unittest/unittest-multiple-moebius-transform.test.cpp\"\n\n#line 1\
    \ \"convolution/multiple-zeta-moebius-transform.hpp\"\n\n\n\n#line 5 \"convolution/multiple-zeta-moebius-transform.hpp\"\
    \n\nnamespace multiple {\n\n  // \u500D\u6570\u306B\u3064\u3044\u3066\u306E\u30BC\
    \u30FC\u30BF\u5909\u63DB\u3002 g_n = \\Sigma_{n|m} f_m \u306A\u308B g \u3092\u6C42\
    \u3081\u308B\u3002\n  // n|m\u3068\u3044\u3046\u306E\u306F\u3001m%n==0\u3068\u3044\
    \u3046\u610F\u5473\u3002\n  // O(N log N) (\u8ABF\u548C\u7D1A\u6570)\n  // \u3046\
    \u307E\u304F\u3084\u308B\u3068O(Nlog(log(N)))\u306B\u3067\u304D\u308B\u3053\u3068\
    \u304C\u3088\u304F\u77E5\u3089\u308C\u3066\u3044\u308B\u304C\u3001\u96E3\u3057\
    \u3044\u3057log\u306F\u5B9A\u6570\u306A\u306E\u3067\u59A5\u5354\u3059\u308B\u3002\
    \n  template <typename T>\n  std::vector<T> zeta_transform_naive(const std::vector<T>&\
    \ f) {\n    int N = f.size() - 1;\n    std::vector<T> g = f;\n    for (int i =\
    \ 1; i <= N; i++) {\n      for (int j = 2 * i; j <= N; j += i) {\n        g[i]\
    \ += f[j];\n      }\n    }\n\n    return g;\n  }\n\n  // \u500D\u6570\u306B\u3064\
    \u3044\u3066\u306E\u30E1\u30D3\u30A6\u30B9\u5909\u63DB\n  // f_n = \\Sigma_{n|m}\
    \ g_m \u306A\u308B g \u3092\u6C42\u3081\u308B\u3002\n  // O(N log N) (\u8ABF\u548C\
    \u7D1A\u6570)\n  template <typename T>\n  std::vector<T> moebius_transform_naive(const\
    \ std::vector<T>& f) {\n    int N = f.size() - 1;\n    std::vector<T> g = f;\n\
    \    for (int i = N; i >= 1; i--) {\n      for (int j = 2 * i; j <= N; j += i)\
    \ {\n        g[i] -= g[j];\n      }\n    }\n    return g;\n  }\n\n\n  template\
    \ <typename I, typename T>\n  std::map<I, T> zeta_transform(const std::map<I,\
    \ T>& mp) {\n    std::map<I, T> ret = mp;\n    for (std::pair<I, T> pit : ret)\
    \ {\n      for (auto p2itr = ret.rbegin(); (*p2itr).first != pit.first; p2itr++)\
    \ {\n        if ((*p2itr).first % pit.first == 0) {\n          ret[pit.first]\
    \ += (*p2itr).second;\n        }\n      }\n    }\n\n    return ret;\n  }\n\n\n\
    \  template <typename I, typename T>\n  std::map<I, T> moebius_transform(const\
    \ std::map<I, T>& mp) {\n    std::map<I, T> ret = mp;\n    for (auto p1itr = ret.rbegin();\
    \ p1itr != ret.rend(); p1itr++) {\n      for (auto p2itr = ret.rbegin(); p2itr\
    \ != p1itr; p2itr++) {\n        if ((*p2itr).first % (*p1itr).first == 0) (*p1itr).second\
    \ -= (*p2itr).second;\n      }\n    }\n\n    return ret;\n  }\n\n} // namespace\
    \ multiple\n\n\n#line 7 \"test/unittest/unittest-multiple-moebius-transform.test.cpp\"\
    \n\nusing mint = modint998244353;\n\n// map\u3067\u500D\u6570\u306E\u30BC\u30FC\
    \u30BF\u5909\u63DB\u3068\u30E1\u30D3\u30A6\u30B9\u5909\u63DB\u3084\u308B\u3084\
    \u3064\u306E\u30C6\u30B9\u30C8\nvoid test() {\n  random_device seed_gen;\n  mt19937\
    \ rng(seed_gen()); \n\n\n  auto map_transform =  [&rng] (int N) {\n    map<ll,\
    \ mint> a_mp;\n    vector<mint> a_vec(N+1);\n\n    for (ll i=1; i*i <= N; i++)\
    \ {\n      if (N%i == 0) {\n        int r1 = rng();\n        int r2 = rng();\n\
    \        a_mp[i] = r1;\n        a_vec[i] = r1;\n\n        a_mp[N/i] = r2;\n  \
    \      a_vec[N/i] = r2;\n      }\n    }\n\n    map<ll, mint> a_mp2 = multiple::zeta_transform(a_mp);\n\
    \    vector<mint> a_vec2 = multiple::zeta_transform_naive(a_vec);\n\n    for (pair<ll,\
    \ mint> plmi : a_mp2) {\n      assert(a_vec2[plmi.first] == plmi.second);\n  \
    \  }\n\n    map<ll,mint> a_mp3 = multiple::moebius_transform(a_mp2);\n    vector<mint>\
    \ a_vec3 = multiple::moebius_transform_naive(a_vec2);\n    \n    assert(a_mp ==\
    \ a_mp3 && \"multiple transform for map\");\n    assert(a_vec == a_vec3 && \"\
    multiple transform for vector\");\n\n    for (pair<ll, mint> plmi : a_mp3) {\n\
    \      assert(a_vec3[plmi.first] == plmi.second);\n    }\n\n  };\n\n  for (int\
    \ i=0; i<1000; i++) {\n    map_transform(rng()%10000 + 1);\n  }\n  return;\n}\n\
    \nint main() {\n  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);\n  test();\n\
    \  int A, B; cin >> A >> B;\n  cout << A+B << endl;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n\n#include \"\
    template/template.hpp\"\n#include \"math/modint.hpp\"\n\n#include \"convolution/multiple-zeta-moebius-transform.hpp\"\
    \n\nusing mint = modint998244353;\n\n// map\u3067\u500D\u6570\u306E\u30BC\u30FC\
    \u30BF\u5909\u63DB\u3068\u30E1\u30D3\u30A6\u30B9\u5909\u63DB\u3084\u308B\u3084\
    \u3064\u306E\u30C6\u30B9\u30C8\nvoid test() {\n  random_device seed_gen;\n  mt19937\
    \ rng(seed_gen()); \n\n\n  auto map_transform =  [&rng] (int N) {\n    map<ll,\
    \ mint> a_mp;\n    vector<mint> a_vec(N+1);\n\n    for (ll i=1; i*i <= N; i++)\
    \ {\n      if (N%i == 0) {\n        int r1 = rng();\n        int r2 = rng();\n\
    \        a_mp[i] = r1;\n        a_vec[i] = r1;\n\n        a_mp[N/i] = r2;\n  \
    \      a_vec[N/i] = r2;\n      }\n    }\n\n    map<ll, mint> a_mp2 = multiple::zeta_transform(a_mp);\n\
    \    vector<mint> a_vec2 = multiple::zeta_transform_naive(a_vec);\n\n    for (pair<ll,\
    \ mint> plmi : a_mp2) {\n      assert(a_vec2[plmi.first] == plmi.second);\n  \
    \  }\n\n    map<ll,mint> a_mp3 = multiple::moebius_transform(a_mp2);\n    vector<mint>\
    \ a_vec3 = multiple::moebius_transform_naive(a_vec2);\n    \n    assert(a_mp ==\
    \ a_mp3 && \"multiple transform for map\");\n    assert(a_vec == a_vec3 && \"\
    multiple transform for vector\");\n\n    for (pair<ll, mint> plmi : a_mp3) {\n\
    \      assert(a_vec3[plmi.first] == plmi.second);\n    }\n\n  };\n\n  for (int\
    \ i=0; i<1000; i++) {\n    map_transform(rng()%10000 + 1);\n  }\n  return;\n}\n\
    \nint main() {\n  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);\n  test();\n\
    \  int A, B; cin >> A >> B;\n  cout << A+B << endl;\n}"
  dependsOn:
  - template/template.hpp
  - math/modint.hpp
  - convolution/multiple-zeta-moebius-transform.hpp
  isVerificationFile: true
  path: test/unittest/unittest-multiple-moebius-transform.test.cpp
  requiredBy: []
  timestamp: '2024-06-19 19:19:30+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/unittest/unittest-multiple-moebius-transform.test.cpp
layout: document
redirect_from:
- /verify/test/unittest/unittest-multiple-moebius-transform.test.cpp
- /verify/test/unittest/unittest-multiple-moebius-transform.test.cpp.html
title: test/unittest/unittest-multiple-moebius-transform.test.cpp
---
