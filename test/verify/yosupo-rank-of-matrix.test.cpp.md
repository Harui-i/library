---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: math/matrix/matrix.hpp
    title: "Matrix(\u884C\u5217)"
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
    PROBLEM: https://judge.yosupo.jp/problem/matrix_rank
    links:
    - https://judge.yosupo.jp/problem/matrix_rank
  bundledCode: "#line 1 \"test/verify/yosupo-rank-of-matrix.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/matrix_rank\"\n\n#line 1 \"template/template.hpp\"\
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
    \ \n  vector<vector<T>>vec;\npublic:\n  const int N, M;\n\n  Matrix(int _N, int\
    \ _M) : N(_N), M(_M), vec(vector<vector<T>>(_N, vector<T>(_M))) {\n    assert(_N\
    \ >= 0 && _M >= 0); // 0*0\u306E\u884C\u5217\u3092\u8FD4\u3057\u305F\u3044\u3068\
    \u304D\u3082\u3042\u308B(\u9006\u884C\u5217\u306A\u304B\u3063\u305F\u3068\u304D\
    \u3068\u304B)\n  }\n\n  Matrix operator*(const Matrix& rhs) const  {\n    assert(M\
    \ == rhs.N);\n    Matrix ret(N,rhs.M);\n    for (int i=0; i<N; i++) for (int k=0;\
    \ k<M; k++) for(int j=0; j<rhs.M; j++) {\n      ret.vec[i][j] += vec[i][k] * rhs.vec[k][j];\n\
    \    } \n\n    return ret;\n  }\n\n  Matrix operator^(unsigned long long k) const\
    \ {\n    assert(N == M);\n    Matrix ret(N, N);\n    for(int i=0; i<N; i++) ret[i][i]\
    \ = T(1);\n\n    Matrix base = *this;\n\n    while (k > 0) {\n      if (k & 1)\
    \ {\n        ret *= base;\n      }\n\n      base *= base;\n      k >>= 1; \n \
    \   }\n\n    return ret;\n  }\n\n  vector<T>& operator[](int i) {\n    assert(i\
    \ < N);\n    return vec[i];\n  }\n\n  Matrix<T>& operator*=(const Matrix<T>& b)\
    \ { return (*this) = (*this) * b; }\n  Matrix<T>& operator^=(const unsigned long\
    \ long k) { return (*this) = (*this) ^ k; }\n\n  int rank() {\n    return sweep(M);\n\
    \  }\n\n  // \u9006\u884C\u5217\u3092\u8FD4\u3059\u3002\u306A\u3051\u308C\u3070\
    0*0\u884C\u5217\u3092\u8FD4\u3059(\u3053\u308C\u306FGifted infants\u306E\u30DE\
    \u30CD\u3060\u304C\u30010*0\u3092\u8FD4\u3059\u5B09\u3057\u3055\u306F\u3044\u307E\
    \u3044\u3061\u308F\u304B\u3063\u3066\u3044\u306A\u3044\u3002\u5909\u3048\u308B\
    \u304B\u3082\u3002)\n  Matrix<T> inverse() const {\n    assert(N == M);\n    Matrix\
    \ A(N, 2*N);\n    for(int i=0; i<N; i++) for(int j=0; j<N; j++) A[i][j] = vec[i][j];\n\
    \    for(int i=0; i<N; i++) A[i][N+i] = T(1);\n    int rank = A.sweep(N);\n  \
    \  if (rank < N) return Matrix(0,0);\n\n    Matrix<T> ret(N, N);\n    for(int\
    \ i=0; i<N; i++) for(int j=0; j<N; j++) ret[i][j] = A[i][N+j];\n\n    return ret;\n\
    \  }  \n\nprivate:\n// 0<= j < var\u306Aj\u5217\u76EE\u306B\u3064\u3044\u3066\u6383\
    \u304D\u51FA\u3057\u3066\u3001rank\u3092\u8FD4\u3059\n\nint sweep(int var) {\n\
    \  assert(var <= M);\n  int rank = 0;\n\n  for(int col=0; col<var; col++) {\n\
    \    int pivot = -1;\n    for(int row=rank; row<N; row++) {\n      // \u3053\u308C\
    \u304Cdouble\u3068\u304B\u306A\u3089\u3001\n      // if ( && chmax(mx, asb(A[row][col]))\
    \ ) \u307F\u305F\u3044\u306A\u6761\u4EF6\u3092\u4ED8\u3051\u3066\u3001\u3067\u304D\
    \u308B\u3060\u3051\u7D76\u5BFE\u5024\u306E\u5927\u304D\u3044pivot\u3092\u9078\u3076\
    \u3088\u3046\u306B\u3059\u308B\n      if (vec[row][col] != T(0)) {\n        pivot\
    \ = row;\n        break; //double \u306A\u3089\u9055\u3046\n      }\n    }\n\n\
    \    if (pivot == -1) continue;\n    swap(vec[pivot], vec[rank]);\n\n    T inv\
    \ = T(1) / vec[rank][col];\n    // pivot\u306E\u884C\u306E\u5148\u982D\u304C1\u306B\
    \u306A\u308B\u3088\u3046\u306B\u884C\u3092\u5B9A\u6570\u500D\u3057\u3066\u63C3\
    \u3048\u308B\n    for(int col2=0; col2<M; col2++) {\n      vec[rank][col2] *=\
    \ inv;\n    }\n\n    for(int row=0; row<N; row++) {\n      // double\u306A\u3089\
    \u3001 && A[row:[col] > EPS\u306E\u3068\u304D\u306E\u307F\u3053\u306E\u64CD\u4F5C\
    \u3092\u3059\u308B\n      if (row != rank) {\n        T fac = vec[row][col];\n\
    \        for(int col2=0; col2<M; col2++) {\n          vec[row][col2] -= vec[rank][col2]\
    \ * fac;\n        }\n      }\n    }\n    rank++;\n  }\n\n  return rank;\n}\n\n\
    \n};\n#line 6 \"test/verify/yosupo-rank-of-matrix.test.cpp\"\n\nusing mint = modint998244353;\n\
    \n\nint main() {\n  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);\n  int N,\
    \ M; cin >> N >> M;\n  if(N == 0 || M == 0) {\n    cout << 0 << endl;\n    return\
    \ 0;\n  }\n\n  Matrix<mint>A(N,M);\n\n  for(int i=0; i<N; i++) for(int j=0; j<M;\
    \ j++) cin >> A[i][j];\n  cout << A.rank() << endl;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/matrix_rank\"\n\n#include\
    \ \"template/template.hpp\"\n#include \"math/modint.hpp\"\n#include \"math/matrix/matrix.hpp\"\
    \n\nusing mint = modint998244353;\n\n\nint main() {\n  ios::sync_with_stdio(0);\
    \ cin.tie(0); cout.tie(0);\n  int N, M; cin >> N >> M;\n  if(N == 0 || M == 0)\
    \ {\n    cout << 0 << endl;\n    return 0;\n  }\n\n  Matrix<mint>A(N,M);\n\n \
    \ for(int i=0; i<N; i++) for(int j=0; j<M; j++) cin >> A[i][j];\n  cout << A.rank()\
    \ << endl;\n}\n"
  dependsOn:
  - template/template.hpp
  - math/modint.hpp
  - math/matrix/matrix.hpp
  isVerificationFile: true
  path: test/verify/yosupo-rank-of-matrix.test.cpp
  requiredBy: []
  timestamp: '2024-06-10 19:28:22+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/verify/yosupo-rank-of-matrix.test.cpp
layout: document
redirect_from:
- /verify/test/verify/yosupo-rank-of-matrix.test.cpp
- /verify/test/verify/yosupo-rank-of-matrix.test.cpp.html
title: test/verify/yosupo-rank-of-matrix.test.cpp
---
