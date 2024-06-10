---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/matrix/matrix.hpp
    title: "Matrix(\u884C\u5217)"
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
    PROBLEM: https://judge.yosupo.jp/problem/matrix_product
    links:
    - https://judge.yosupo.jp/problem/matrix_product
  bundledCode: "#line 1 \"test/verify/yosupo-matrix-product.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/matrix_product\"\n\n#line 1 \"template/template.hpp\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\ntypedef long long ll;\ntypedef\
    \ unsigned int uint;\ntemplate<class T> inline bool chmax(T& a, const T& b) {if\
    \ (a<b) {a=b; return true;} return false;}\ntemplate<class T> inline bool chmin(T&\
    \ a, const T& b) {if (b<a) {a=b; return true;} return false;}\nconst int INTINF\
    \ = 1000001000;\nconst int INTMAX = 2147483647;\nconst ll LLMAX = 9223372036854775807;\n\
    const ll LLINF = 1000000000000000000;\n#line 2 \"math/modint.hpp\"\ntemplate<int\
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
    \  = modint<998244353>;\nusing modint1000000007 = modint<1000000007>;\n#line 2\
    \ \"math/matrix/matrix.hpp\"\n\ntemplate <class T>\nstruct Matrix{\nprotected:\
    \ \n  vector<vector<T>>vec;\n  int N, M;\npublic:\n\n  Matrix(int _N, int _M)\
    \ : N(_N), M(_M), vec(vector<vector<T>>(_N, vector<T>(_M))) {\n    assert(_N >\
    \ 0 && _M > 0);\n  }\n\n  Matrix operator*(const Matrix& rhs) const  {\n    assert(M\
    \ == rhs.N);\n    Matrix ret(N,rhs.M);\n    for (int i=0; i<N; i++) for (int k=0;\
    \ k<M; k++) for(int j=0; j<rhs.M; j++) {\n      ret.vec[i][j] += vec[i][k] * rhs.vec[k][j];\n\
    \    } \n\n    return ret;\n  }\n\n  Matrix operator^(unsigned long long k) const\
    \ {\n    assert(N == M);\n    Matrix ret(N, N);\n    for(int i=0; i<N; i++) ret[i][i]\
    \ = T(1);\n\n    Matrix base = *this;\n\n    while (k > 0) {\n      if (k & 1)\
    \ {\n        ret *= base;\n      }\n\n      base *= base;\n      k >>= 1; \n \
    \   }\n\n    return ret;\n  }\n\n  vector<T>& operator[](int i) {\n    assert(i\
    \ < N);\n    return vec[i];\n  }\n\n  Matrix<T>& operator*=(const Matrix<T>& b)\
    \ { return (*this) = (*this) * b; }\n  Matrix<T>& operator^=(const unsigned long\
    \ long k) { return (*this) = (*this) ^ k; }\n};\n#line 6 \"test/verify/yosupo-matrix-product.test.cpp\"\
    \n\nusing mint = modint998244353;\n\n\nint main() {\n  ios::sync_with_stdio(0);\
    \ cin.tie(0); cout.tie(0);\n  int N, M, K; cin >> N >> M >> K;\n\n  Matrix<mint>\
    \ A(N, M);\n  Matrix<mint> B(M, K);\n\n  for(int i=0; i<N; i++) for(int j=0; j<M;\
    \ j++) cin >> A[i][j];\n\n  for(int i=0; i<M; i++) for(int j=0; j<K; j++) cin\
    \ >> B[i][j];\n\n  Matrix<mint> C = A * B; \n  for(int i=0; i<N; i++) {\n    for(int\
    \ j=0; j<K; j++) {\n      cout << C[i][j].val();\n      if (j == K-1) cout <<\
    \ endl;\n      else cout << \" \";\n    }\n  }\n\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/matrix_product\"\n\n#include\
    \ \"template/template.hpp\"\n#include \"math/modint.hpp\"\n#include \"math/matrix/matrix.hpp\"\
    \n\nusing mint = modint998244353;\n\n\nint main() {\n  ios::sync_with_stdio(0);\
    \ cin.tie(0); cout.tie(0);\n  int N, M, K; cin >> N >> M >> K;\n\n  Matrix<mint>\
    \ A(N, M);\n  Matrix<mint> B(M, K);\n\n  for(int i=0; i<N; i++) for(int j=0; j<M;\
    \ j++) cin >> A[i][j];\n\n  for(int i=0; i<M; i++) for(int j=0; j<K; j++) cin\
    \ >> B[i][j];\n\n  Matrix<mint> C = A * B; \n  for(int i=0; i<N; i++) {\n    for(int\
    \ j=0; j<K; j++) {\n      cout << C[i][j].val();\n      if (j == K-1) cout <<\
    \ endl;\n      else cout << \" \";\n    }\n  }\n\n}\n"
  dependsOn:
  - template/template.hpp
  - math/modint.hpp
  - math/matrix/matrix.hpp
  isVerificationFile: true
  path: test/verify/yosupo-matrix-product.test.cpp
  requiredBy: []
  timestamp: '2024-06-10 16:47:33+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/verify/yosupo-matrix-product.test.cpp
layout: document
redirect_from:
- /verify/test/verify/yosupo-matrix-product.test.cpp
- /verify/test/verify/yosupo-matrix-product.test.cpp.html
title: test/verify/yosupo-matrix-product.test.cpp
---
