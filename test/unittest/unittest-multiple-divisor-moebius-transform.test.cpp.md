---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: convolution/divisor-zeta-moebius-transform.hpp
    title: "\u7D04\u6570\u306B\u3064\u3044\u3066\u306E\u30BC\u30FC\u30BF\u5909\u63DB\
      /\u30E1\u30D3\u30A6\u30B9\u5909\u63DB"
  - icon: ':heavy_check_mark:'
    path: convolution/multiple-zeta-moebius-transform.hpp
    title: "\u500D\u6570\u306B\u3064\u3044\u3066\u306E\u30BC\u30FC\u30BF\u5909\u63DB\
      /\u30E1\u30D3\u30A6\u30B9\u5909\u63DB"
  - icon: ':heavy_check_mark:'
    path: math/external_gcd.hpp
    title: math/external_gcd.hpp
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
  bundledCode: "#line 1 \"test/unittest/unittest-multiple-divisor-moebius-transform.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n\n#line 1 \"template/template.hpp\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\nusing ll = long long;\ntemplate<class\
    \ T> inline bool chmax(T& a, const T& b) {if (a<b) {a=b; return true;} return\
    \ false;}\ntemplate<class T> inline bool chmin(T& a, const T& b) {if (b<a) {a=b;\
    \ return true;} return false;}\nconst int INTINF = 1000001000;\nconst int INTMAX\
    \ = 2147483647;\nconst ll LLMAX = 9223372036854775807;\nconst ll LLINF = 1000000000000000000;\n\
    #line 1 \"math/modint.hpp\"\n\n\n\n#line 1 \"math/external_gcd.hpp\"\n\n\n\n#line\
    \ 5 \"math/external_gcd.hpp\"\n\n// g,x,y\ntemplate<typename T>\nconstexpr std::tuple<T,\
    \ T, T> extendedGCD(T a, T b) {\n    T x0 = 1, y0 = 0, x1 = 0, y1 = 1;\n    while\
    \ (b != 0) {\n        T q = a / b;\n        T r = a % b;\n        a = b;\n   \
    \     b = r;\n        \n        T xTemp = x0 - q * x1;\n        x0 = x1;\n   \
    \     x1 = xTemp;\n        \n        T yTemp = y0 - q * y1;\n        y0 = y1;\n\
    \        y1 = yTemp;\n    }\n    return {a, x0, y0};\n}\n\n#line 5 \"math/modint.hpp\"\
    \n\ntemplate<int MOD>\nstruct static_modint {\n    int value;\n\n    constexpr\
    \ static_modint() : value(0) {}\n\n    constexpr static_modint(long long v) {\n\
    \        value = int(((v % MOD) + MOD) % MOD);\n    }\n\n    constexpr static_modint&\
    \ operator+=(const static_modint& other) {\n        if ((value += other.value)\
    \ >= MOD) value -= MOD;\n        return *this;\n    }\n\n    constexpr static_modint&\
    \ operator-=(const static_modint& other) {\n        if ((value -= other.value)\
    \ < 0) value += MOD;\n        return *this;\n    }\n\n    constexpr static_modint&\
    \ operator*=(const static_modint& other) {\n        value = int((long long)value\
    \ * other.value % MOD);\n        return *this;\n    }\n\n    constexpr static_modint\
    \ operator+(const static_modint& other) const {\n        return static_modint(*this)\
    \ += other;\n    }\n\n    constexpr static_modint operator-(const static_modint&\
    \ other) const {\n        return static_modint(*this) -= other;\n    }\n\n   \
    \ constexpr static_modint operator*(const static_modint& other) const {\n    \
    \    return static_modint(*this) *= other;\n    }\n\n    constexpr static_modint\
    \ pow(long long exp) const {\n        static_modint base = *this, res = 1;\n \
    \       while (exp > 0) {\n            if (exp & 1) res *= base;\n           \
    \ base *= base;\n            exp >>= 1;\n        }\n        return res;\n    }\n\
    \n    constexpr static_modint inv() const {\n        //return pow(MOD - 2);\n\
    \        int g,x,y;\n        tie(g,x,y) = extendedGCD(value, MOD);\n        assert(g==1);\n\
    \        if (x < 0) {\n            x += MOD;\n        }\n        //cerr << g <<\
    \ \" \" << x << \" \" << y << \" \" << value << endl;\n        //assert((((long)x*value)%MOD\
    \ + MOD)%MOD == 1);\n        return x;\n    }\n\n    constexpr static_modint&\
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
    \ 5 \"test/unittest/unittest-multiple-divisor-moebius-transform.test.cpp\"\n\n\
    #line 1 \"convolution/multiple-zeta-moebius-transform.hpp\"\n\n\n\n#line 5 \"\
    convolution/multiple-zeta-moebius-transform.hpp\"\n\nnamespace multiple {\n\n\
    \  // \u500D\u6570\u306B\u3064\u3044\u3066\u306E\u30BC\u30FC\u30BF\u5909\u63DB\
    \u3002 g_n = \\Sigma_{n|m} f_m \u306A\u308B g \u3092\u6C42\u3081\u308B\u3002\n\
    \  // n|m\u3068\u3044\u3046\u306E\u306F\u3001m%n==0\u3068\u3044\u3046\u610F\u5473\
    \u3002\n  // O(N log N) (\u8ABF\u548C\u7D1A\u6570)\n  // \u3046\u307E\u304F\u3084\
    \u308B\u3068O(Nlog(log(N)))\u306B\u3067\u304D\u308B\u3053\u3068\u304C\u3088\u304F\
    \u77E5\u3089\u308C\u3066\u3044\u308B\u304C\u3001\u96E3\u3057\u3044\u3057log\u306F\
    \u5B9A\u6570\u306A\u306E\u3067\u59A5\u5354\u3059\u308B\u3002\n  template <typename\
    \ T, T (*op)(T, T)>\n  std::vector<T> zeta_transform_naive(const std::vector<T>&\
    \ f) {\n    int N = f.size() - 1;\n    std::vector<T> g = f;\n    for (int i =\
    \ 1; i <= N; i++) {\n      for (int j = 2 * i; j <= N; j += i) {\n        g[i]\
    \ = op(g[i], f[j]);\n      }\n    }\n\n    return g;\n  }\n\n  // \u500D\u6570\
    \u306B\u3064\u3044\u3066\u306E\u30E1\u30D3\u30A6\u30B9\u5909\u63DB\n  // f_n =\
    \ \\Sigma_{n|m} g_m \u306A\u308B g \u3092\u6C42\u3081\u308B\u3002\n  // O(N log\
    \ N) (\u8ABF\u548C\u7D1A\u6570)\n  template <typename T, T(*invop)(T, T)>\n  std::vector<T>\
    \ moebius_transform_naive(const std::vector<T>& f) {\n    int N = f.size() - 1;\n\
    \    std::vector<T> g = f;\n    for (int i = N; i >= 1; i--) {\n      for (int\
    \ j = 2 * i; j <= N; j += i) {\n        g[i] = invop(g[i], g[j]);\n      }\n \
    \   }\n    return g;\n  }\n\n\n  template <typename I, typename T, T(*op)(T, T)>\n\
    \  std::map<I, T> zeta_transform(const std::map<I, T>& mp) {\n    std::map<I,\
    \ T> ret = mp;\n    for (std::pair<I, T> pit : ret) {\n      for (auto p2itr =\
    \ ret.rbegin(); (*p2itr).first != pit.first; p2itr++) {\n        if ((*p2itr).first\
    \ % pit.first == 0) {\n          ret[pit.first] = op(ret[pit.first], (*p2itr).second);\n\
    \        }\n      }\n    }\n\n    return ret;\n  }\n\n\n  template <typename I,\
    \ typename T, T (*invop)(T, T)>\n  std::map<I, T> moebius_transform(const std::map<I,\
    \ T>& mp) {\n    std::map<I, T> ret = mp;\n    for (auto p1itr = ret.rbegin();\
    \ p1itr != ret.rend(); p1itr++) {\n      for (auto p2itr = ret.rbegin(); p2itr\
    \ != p1itr; p2itr++) {\n        if ((*p2itr).first % (*p1itr).first == 0) {\n\
    \          (*p1itr).second = invop((*p1itr).second, (*p2itr).second);\n      \
    \  }\n      }\n    }\n\n    return ret;\n  }\n\n} // namespace multiple\n\n\n\
    #line 1 \"convolution/divisor-zeta-moebius-transform.hpp\"\n\n\n\n#line 5 \"convolution/divisor-zeta-moebius-transform.hpp\"\
    \n\nnamespace divisor {\n  // \u7D04\u6570\u306B\u3064\u3044\u3066\u306E\u30BC\
    \u30FC\u30BF\u5909\u63DB\u3002 g_n = \\Sigma_{m|n} f_m \u306A\u308B g \u3092\u6C42\
    \u3081\u308B\u3002\n  template <typename T, T(*op)(T, T) >\n  std::vector<T> zeta_transform_naive(const\
    \ std::vector<T>& f) {\n    int N = f.size() - 1;\n    std::vector<T> g = f;\n\
    \n    for (int i = 1; i <= N; i++) {\n      for (int j = 2 * i; j <= N; j += i)\
    \ {\n        g[j] = op(g[j], f[i]);\n      }\n    }\n\n    return g;\n  }\n\n\
    \  // \u7D04\u6570\u306B\u3064\u3044\u3066\u306E\u30E1\u30D3\u30A6\u30B9\u5909\
    \u63DB\u3002 f_n = \\Sigma_{m|n} g_m \u306A\u308B g \u3092\u6C42\u3081\u308B\u3002\
    \n  template <typename T, T(*invop)(T, T)>\n  std::vector<T> moebius_transform_naive(const\
    \ std::vector<T>& f) {\n    int N = f.size() - 1;\n    std::vector<T> g = f;\n\
    \n    for (int i = 1; i <= N; i++) {\n      for (int j = i * 2; j <= N; j += i)\
    \ {\n        g[j] = invop(g[j], g[i]);\n      }\n    }\n\n    return g;\n  }\n\
    \n  template <typename I, typename T, T(*op)(T, T)>\n  std::map<I, T> zeta_transform(const\
    \ std::map<I, T>& mp) {\n    std::map<I, T> ret = mp;\n    for (auto p2itr = mp.rbegin();\
    \ p2itr != mp.rend(); p2itr++) {\n      for (auto p1itr = next(p2itr); p1itr !=\
    \ mp.rend(); p1itr++) {\n        if ((*p2itr).first % (*p1itr).first == 0) {\n\
    \          ret[(*p2itr).first] = op(ret[(*p2itr).first], ret[(*p1itr).first]);\n\
    \        }\n      }\n    }\n\n    return ret;\n  }\n\n\n  template <typename I,\
    \ typename T, T(*op)(T, T)>\n  std::map<I, T> moebius_transform(const std::map<I,\
    \ T>& mp) {\n    std::map<I, T> ret = mp;\n\n    for (auto p1itr = ret.begin();\
    \ p1itr != ret.end(); p1itr++) {\n      for (auto p2itr = next(p1itr); p2itr !=\
    \ ret.end(); p2itr++) {\n        if ((*p2itr).first % (*p1itr).first == 0) {\n\
    \          ret[(*p2itr).first] = invop(ret[(*p2itr).first], ret[(*p1itr).first]);\n\
    \        }\n      }\n    }\n\n    return ret;\n  }\n} // namespace divisor\n\n\
    \n#line 8 \"test/unittest/unittest-multiple-divisor-moebius-transform.test.cpp\"\
    \n\nusing mint = modint998244353;\n\nmint op(mint a, mint b) {\n  return a + b;\n\
    }\n\nmint invop(mint a, mint b) {\n  return a - b;\n}\n\n// map\u3067\u500D\u6570\
    \u306E\u30BC\u30FC\u30BF\u5909\u63DB\u3068\u30E1\u30D3\u30A6\u30B9\u5909\u63DB\
    \u3084\u308B\u3084\u3064\u306E\u30C6\u30B9\u30C8\nvoid test() {\n  random_device\
    \ seed_gen;\n  mt19937 rng(seed_gen());\n\n\n  auto map_transform = [&rng](int\
    \ N) {\n    map<ll, mint> multiple_map;\n    map<ll, mint> divisor_map;\n\n  \
    \  vector<mint> multiple_vec(N + 1);\n    vector<mint> divisor_vec(N + 1);\n\n\
    \    for (ll i = 1; i * i <= N; i++) {\n      if (N % i == 0) {\n        int r1\
    \ = rng();\n        int r2 = rng();\n        multiple_map[i] = r1;\n        multiple_vec[i]\
    \ = r1;\n\n        multiple_map[N / i] = r2;\n        multiple_vec[N / i] = r2;\n\
    \      }\n    }\n\n    divisor_map = multiple_map;\n    divisor_vec = multiple_vec;\n\
    \n    // multiple\n    {\n      map<ll, mint> multiple_map2 = multiple::zeta_transform<ll,mint,op>(multiple_map);\n\
    \      vector<mint> multiple_vec2 = multiple::zeta_transform_naive<mint,op>(multiple_vec);\n\
    \n      for (pair<ll, mint> plmi : multiple_map2) {\n        assert(multiple_vec2[plmi.first]\
    \ == plmi.second);\n      }\n\n      map<ll, mint> multiple_map3 = multiple::moebius_transform<ll,mint,invop>(multiple_map2);\n\
    \      vector<mint> multiple_vec3 = multiple::moebius_transform_naive<mint,invop>(multiple_vec2);\n\
    \n      assert(multiple_map == multiple_map3 && \"multiple transform for map\"\
    );\n      assert(multiple_vec == multiple_vec3 && \"multiple transform for vector\"\
    );\n\n      for (pair<ll, mint> plmi : multiple_map3) {\n        assert(multiple_vec3[plmi.first]\
    \ == plmi.second);\n      }\n    }\n\n    // divisor\n    {\n      map<ll, mint>\
    \ divisor_map2 = divisor::zeta_transform<ll,mint,op>(divisor_map);\n      vector<mint>\
    \ divisor_vec2 = divisor::zeta_transform_naive<mint,op>(divisor_vec);\n\n    \
    \  for (pair<ll, mint> plmi : divisor_map2) {\n        assert(divisor_vec2[plmi.first]\
    \ == plmi.second && \"divisor zeta transform\");\n      }\n\n      map<ll, mint>\
    \ divisor_map3 = divisor::moebius_transform<ll,mint,invop>(divisor_map2);\n  \
    \    vector<mint> divisor_vec3 = divisor::moebius_transform_naive<mint,invop>(divisor_vec2);\n\
    \n      assert(divisor_map == divisor_map3 && \"multiple transform for map\");\n\
    \      assert(divisor_vec == divisor_vec3 && \"multiple transform for vector\"\
    );\n\n      for (pair<ll, mint> plmi : divisor_map3) {\n        assert(divisor_vec3[plmi.first]\
    \ == plmi.second && \"divisor moebius transform\");\n      }\n    }\n\n    };\n\
    \n  for (int i = 0; i < 1000; i++) {\n    map_transform(rng() % 10000 + 1);\n\
    \  }\n  return;\n}\n\nint main() {\n  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);\n\
    \  test();\n  int A, B; cin >> A >> B;\n  cout << A + B << endl;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n\n#include \"\
    template/template.hpp\"\n#include \"math/modint.hpp\"\n\n#include \"convolution/multiple-zeta-moebius-transform.hpp\"\
    \n#include \"convolution/divisor-zeta-moebius-transform.hpp\"\n\nusing mint =\
    \ modint998244353;\n\nmint op(mint a, mint b) {\n  return a + b;\n}\n\nmint invop(mint\
    \ a, mint b) {\n  return a - b;\n}\n\n// map\u3067\u500D\u6570\u306E\u30BC\u30FC\
    \u30BF\u5909\u63DB\u3068\u30E1\u30D3\u30A6\u30B9\u5909\u63DB\u3084\u308B\u3084\
    \u3064\u306E\u30C6\u30B9\u30C8\nvoid test() {\n  random_device seed_gen;\n  mt19937\
    \ rng(seed_gen());\n\n\n  auto map_transform = [&rng](int N) {\n    map<ll, mint>\
    \ multiple_map;\n    map<ll, mint> divisor_map;\n\n    vector<mint> multiple_vec(N\
    \ + 1);\n    vector<mint> divisor_vec(N + 1);\n\n    for (ll i = 1; i * i <= N;\
    \ i++) {\n      if (N % i == 0) {\n        int r1 = rng();\n        int r2 = rng();\n\
    \        multiple_map[i] = r1;\n        multiple_vec[i] = r1;\n\n        multiple_map[N\
    \ / i] = r2;\n        multiple_vec[N / i] = r2;\n      }\n    }\n\n    divisor_map\
    \ = multiple_map;\n    divisor_vec = multiple_vec;\n\n    // multiple\n    {\n\
    \      map<ll, mint> multiple_map2 = multiple::zeta_transform<ll,mint,op>(multiple_map);\n\
    \      vector<mint> multiple_vec2 = multiple::zeta_transform_naive<mint,op>(multiple_vec);\n\
    \n      for (pair<ll, mint> plmi : multiple_map2) {\n        assert(multiple_vec2[plmi.first]\
    \ == plmi.second);\n      }\n\n      map<ll, mint> multiple_map3 = multiple::moebius_transform<ll,mint,invop>(multiple_map2);\n\
    \      vector<mint> multiple_vec3 = multiple::moebius_transform_naive<mint,invop>(multiple_vec2);\n\
    \n      assert(multiple_map == multiple_map3 && \"multiple transform for map\"\
    );\n      assert(multiple_vec == multiple_vec3 && \"multiple transform for vector\"\
    );\n\n      for (pair<ll, mint> plmi : multiple_map3) {\n        assert(multiple_vec3[plmi.first]\
    \ == plmi.second);\n      }\n    }\n\n    // divisor\n    {\n      map<ll, mint>\
    \ divisor_map2 = divisor::zeta_transform<ll,mint,op>(divisor_map);\n      vector<mint>\
    \ divisor_vec2 = divisor::zeta_transform_naive<mint,op>(divisor_vec);\n\n    \
    \  for (pair<ll, mint> plmi : divisor_map2) {\n        assert(divisor_vec2[plmi.first]\
    \ == plmi.second && \"divisor zeta transform\");\n      }\n\n      map<ll, mint>\
    \ divisor_map3 = divisor::moebius_transform<ll,mint,invop>(divisor_map2);\n  \
    \    vector<mint> divisor_vec3 = divisor::moebius_transform_naive<mint,invop>(divisor_vec2);\n\
    \n      assert(divisor_map == divisor_map3 && \"multiple transform for map\");\n\
    \      assert(divisor_vec == divisor_vec3 && \"multiple transform for vector\"\
    );\n\n      for (pair<ll, mint> plmi : divisor_map3) {\n        assert(divisor_vec3[plmi.first]\
    \ == plmi.second && \"divisor moebius transform\");\n      }\n    }\n\n    };\n\
    \n  for (int i = 0; i < 1000; i++) {\n    map_transform(rng() % 10000 + 1);\n\
    \  }\n  return;\n}\n\nint main() {\n  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);\n\
    \  test();\n  int A, B; cin >> A >> B;\n  cout << A + B << endl;\n}"
  dependsOn:
  - template/template.hpp
  - math/modint.hpp
  - math/external_gcd.hpp
  - convolution/multiple-zeta-moebius-transform.hpp
  - convolution/divisor-zeta-moebius-transform.hpp
  isVerificationFile: true
  path: test/unittest/unittest-multiple-divisor-moebius-transform.test.cpp
  requiredBy: []
  timestamp: '2024-06-29 08:51:47+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/unittest/unittest-multiple-divisor-moebius-transform.test.cpp
layout: document
redirect_from:
- /verify/test/unittest/unittest-multiple-divisor-moebius-transform.test.cpp
- /verify/test/unittest/unittest-multiple-divisor-moebius-transform.test.cpp.html
title: test/unittest/unittest-multiple-divisor-moebius-transform.test.cpp
---
