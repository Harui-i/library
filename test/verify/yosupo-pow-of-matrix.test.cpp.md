---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: math/matrix/square_matrix.hpp
    title: "SquareMatrix(\u6B63\u65B9\u884C\u5217)"
  - icon: ':question:'
    path: math/modint.hpp
    title: modint
  - icon: ':question:'
    path: template/template.hpp
    title: template/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/pow_of_matrix
    links:
    - https://judge.yosupo.jp/problem/pow_of_matrix
  bundledCode: "#line 1 \"test/verify/yosupo-pow-of-matrix.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/pow_of_matrix\"\n\n#line 1 \"template/template.hpp\"\
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
    \ \"math/matrix/square_matrix.hpp\"\n\ntemplate <class T> \nstruct SquareMatrix\
    \  {\nprivate:\n  int N;\n  vector<vector<T>> vec;\npublic:\n  SquareMatrix(int\
    \ _N) : N(_N), vec(vector<vector<T>>(_N, vector<T>(_N)))  {}\n\n  SquareMatrix&\
    \ operator*=(const SquareMatrix<T>& rhs)  {\n    assert(N == rhs.N);\n    SquareMatrix\
    \ ret(N);\n\n    for (int i=0; i<N; i++) for (int k=0; k<N; k++) for(int j=0;\
    \ j<rhs.N; j++) {\n      ret.vec[i][j] += vec[i][k] * rhs.vec[k][j];\n    } \n\
    \    vec = ret.vec;\n\n    return *this;\n  }\n\n  SquareMatrix& operator^=(unsigned\
    \ long long k) {\n    SquareMatrix B(N);\n    for(int i=0; i<N; i++) B[i][i] =\
    \ 1;\n\n    while (k > 0) {\n      if (k&1) {\n        B *= *this;\n      }\n\
    \      *this *= *this;\n      k >>= 1;\n    }\n    *this = B;\n    return *this;\
    \    \n  }\n  \n  vector<T>& operator[](int i) {\n    assert(i < N);\n    return\
    \ vec[i];\n  }\n\n  friend SquareMatrix<T> operator*(SquareMatrix<T> a, const\
    \ SquareMatrix<T>& b) { return a *= b; }\n  friend SquareMatrix<T> operator^(SquareMatrix<T>\
    \ a, const SquareMatrix<T>& b) { return a^=b; }\n};\n#line 6 \"test/verify/yosupo-pow-of-matrix.test.cpp\"\
    \n\nusing mint = modint998244353;\n\n\nint main() {\n  ios::sync_with_stdio(0);\
    \ cin.tie(0); cout.tie(0);\n  int N; cin >> N;\n  ll K; cin >> K;\n\n  SquareMatrix<mint>A(N);\n\
    \n  for(int i=0; i<N; i++) for(int j=0; j<N; j++) cin >> A[i][j];\n\n  A ^= K;\n\
    \  for(int i=0; i<N; i++) {\n    for(int j=0; j<N; j++) {\n      cout << A[i][j].val();\n\
    \      if (j == N-1) cout << endl;\n      else cout << \" \";\n    }\n  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/pow_of_matrix\"\n\n#include\
    \ \"template/template.hpp\"\n#include \"math/modint.hpp\"\n#include \"math/matrix/square_matrix.hpp\"\
    \n\nusing mint = modint998244353;\n\n\nint main() {\n  ios::sync_with_stdio(0);\
    \ cin.tie(0); cout.tie(0);\n  int N; cin >> N;\n  ll K; cin >> K;\n\n  SquareMatrix<mint>A(N);\n\
    \n  for(int i=0; i<N; i++) for(int j=0; j<N; j++) cin >> A[i][j];\n\n  A ^= K;\n\
    \  for(int i=0; i<N; i++) {\n    for(int j=0; j<N; j++) {\n      cout << A[i][j].val();\n\
    \      if (j == N-1) cout << endl;\n      else cout << \" \";\n    }\n  }\n}\n"
  dependsOn:
  - template/template.hpp
  - math/modint.hpp
  - math/matrix/square_matrix.hpp
  isVerificationFile: true
  path: test/verify/yosupo-pow-of-matrix.test.cpp
  requiredBy: []
  timestamp: '2024-06-10 01:49:10+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/verify/yosupo-pow-of-matrix.test.cpp
layout: document
redirect_from:
- /verify/test/verify/yosupo-pow-of-matrix.test.cpp
- /verify/test/verify/yosupo-pow-of-matrix.test.cpp.html
title: test/verify/yosupo-pow-of-matrix.test.cpp
---
