---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/external_gcd.hpp
    title: math/external_gcd.hpp
  - icon: ':heavy_check_mark:'
    path: math/matrix/matrix.hpp
    title: "Matrix(\u884C\u5217)"
  - icon: ':heavy_check_mark:'
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
    PROBLEM: https://judge.yosupo.jp/problem/inverse_matrix
    links:
    - https://judge.yosupo.jp/problem/inverse_matrix
  bundledCode: "#line 1 \"test/verify/math/matrix/yosupo-inverse-of-matrix.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/inverse_matrix\"\n\n#line\
    \ 1 \"template/template.hpp\"\n#include <iostream>\n#include <cassert>\nusing\
    \ namespace std;\nusing ll = long long;\ntemplate<class T> inline bool chmax(T&\
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
    using modint1000000007 = modint<1000000007>;\n\n\n#line 1 \"math/matrix/matrix.hpp\"\
    \n\n\n\n#include <vector>\n\ntemplate <class T>\nstruct Matrix{\nprivate: \n \
    \ std::vector<std::vector<T>>vec;\n  int N, M;\npublic:\n\n  Matrix(int _N, int\
    \ _M) : vec(std::vector<std::vector<T>>(_N, std::vector<T>(_M))), N(_N), M(_M)\
    \  {\n    assert(_N >= 0 && _M >= 0); // 0*0\u306E\u884C\u5217\u3092\u8FD4\u3057\
    \u305F\u3044\u3068\u304D\u3082\u3042\u308B(\u9006\u884C\u5217\u306A\u304B\u3063\
    \u305F\u3068\u304D\u3068\u304B)\n  }\n\n  Matrix<T> operator*(const Matrix<T>&\
    \ rhs) const  {\n    assert(M == rhs.N);\n    Matrix ret(N,rhs.M);\n    for (int\
    \ i=0; i<N; i++) for (int k=0; k<M; k++) for(int j=0; j<rhs.M; j++) {\n      ret.vec[i][j]\
    \ += vec[i][k] * rhs.vec[k][j];\n    } \n\n    return ret;\n  }\n\n  Matrix<T>\
    \ operator^(unsigned long long k) const {\n    assert(N == M);\n    Matrix<T>\
    \ ret(N, N);\n    for(int i=0; i<N; i++) ret[i][i] = T(1);\n\n    Matrix<T> base\
    \ = *this;\n\n    while (k > 0) {\n      if (k & 1) {\n        ret *= base;\n\
    \      }\n\n      base *= base;\n      k >>= 1; \n    }\n\n    return ret;\n \
    \ }\n\n  vector<T>& operator[](int i) {\n    assert(i < N);\n    return vec[i];\n\
    \  }\n\n  Matrix<T>& operator*=(const Matrix<T>& b) { return (*this) = (*this)\
    \ * b; }\n  Matrix<T>& operator^=(const unsigned long long k) { return (*this)\
    \ = (*this) ^ k; }\n\n  // \u3055\u3059\u304C\u306Brank\u3092\u77E5\u308B\u306E\
    \u306B\u526F\u4F5C\u7528\u304C\u3042\u308B\u306E\u306F\u30E4\u30D0\u3044\u306E\
    \u3067\n  int rank() const {\n    Matrix A = *this;\n    return A.sweep(M);\n\
    \  }\n\n  // \u30B5\u30A4\u30BA\u3092\u8FD4\u3059\u3002N,M\u3092const\u306B\u3057\
    \u305F\u3044\u3051\u3069const\u306B\u3059\u308B\u3068*=\u3084^=\u304C\u9762\u5012\
    \u306B\u306A\u308B\u305F\u3081\u3001N,M\u3092\u975Econst\u306Eprivate\u306B\u3059\
    \u308B\u3053\u3068\u3067\u306A\u3093\u3068\u304B\u3059\u308B\u3002\n  pair<int,int>\
    \ size() const {\n    return make_pair(N, M);\n  }\n\n  // \u9006\u884C\u5217\u3092\
    \u8FD4\u3059\u3002\u306A\u3051\u308C\u30700*0\u884C\u5217\u3092\u8FD4\u3059(\u3053\
    \u308C\u306FGifted infants\u306E\u30DE\u30CD\u3060\u304C\u30010*0\u3092\u8FD4\u3059\
    \u5B09\u3057\u3055\u306F\u3044\u307E\u3044\u3061\u308F\u304B\u3063\u3066\u3044\
    \u306A\u3044\u3002\u5909\u3048\u308B\u304B\u3082\u3002)\n  Matrix<T> inverse()\
    \ const {\n    assert(N == M);\n    Matrix A(N, 2*N);\n    for(int i=0; i<N; i++)\
    \ for(int j=0; j<N; j++) A[i][j] = vec[i][j];\n    for(int i=0; i<N; i++) A[i][N+i]\
    \ = T(1);\n    int rank = A.sweep(N);\n    if (rank < N) return Matrix(0,0);\n\
    \n    Matrix<T> ret(N, N);\n    for(int i=0; i<N; i++) for(int j=0; j<N; j++)\
    \ ret[i][j] = A[i][N+j];\n\n    return ret;\n  }  \n\n  // Solve Ax = b for H*W\
    \ matrix A, longitudinal vector b, x.\n  // x using {W-rank(A) + 1} vectors, x\
    \ = x_0 + c_1 * x_1 + .... + c_{W-rank(A)} * x_{W-rank(A)} (c is an arbitrary\
    \ constant), so x_0, x_1, ... , x_{W-rank(A)} is returned. \n  // if there is\
    \ no solution, return an empty vector sequence.\n  // ref : https://nyaannyaan.github.io/library/matrix/linear-equation.hpp\n\
    \  std::vector<std::vector<T>> linear_equation() {\n    int rk = sweep(M-1);\n\
    \    int H = N;\n    int W = M-1;\n\n    for(int i=rk; i<N; i++) {\n      if (vec[i][W]\
    \ != T(0)) return std::vector<std::vector<T>>(); \n    }\n\n    std::vector<std::vector<T>>\
    \ ret(1, std::vector<T>(W));\n    std::vector<int> pivot(W, -1);\n    for (int\
    \ i=0, j=0; i<rk; i++) {\n      while (vec[i][j] == T(0)) {\n        j++;\n  \
    \      assert(j < W);\n      }\n\n      ret[0][j] = vec[i][W];\n      pivot[j]\
    \ = i;\n    }\n\n    for(int j=0; j<W; j++) {\n      if (pivot[j] == -1) {\n \
    \       std::vector<T> x(W);\n        x[j] = 1;\n        for(int k=0; k<j; k++)\
    \ {\n          if (pivot[k] != -1) x[k] -= vec[pivot[k]][j];\n        }\n\n  \
    \      ret.push_back(x);\n      }\n    }\n\n    return ret;\n  }\n\nprivate:\n\
    // 0<= j < var\u306Aj\u5217\u76EE\u306B\u3064\u3044\u3066\u6383\u304D\u51FA\u3057\
    \u3066\u3001rank\u3092\u8FD4\u3059\n\nint sweep(int var) {\n  assert(var <= M);\n\
    \  int rank = 0;\n\n  for(int col=0; col<var; col++) {\n    int pivot = -1;\n\
    \    for(int row=rank; row<N; row++) {\n      // \u3053\u308C\u304Cdouble\u3068\
    \u304B\u306A\u3089\u3001\n      // if ( && chmax(mx, asb(A[row][col])) ) \u307F\
    \u305F\u3044\u306A\u6761\u4EF6\u3092\u4ED8\u3051\u3066\u3001\u3067\u304D\u308B\
    \u3060\u3051\u7D76\u5BFE\u5024\u306E\u5927\u304D\u3044pivot\u3092\u9078\u3076\u3088\
    \u3046\u306B\u3059\u308B\n      if (vec[row][col] != T(0)) {\n        pivot =\
    \ row;\n        break; //double \u306A\u3089\u9055\u3046\n      }\n    }\n\n \
    \   if (pivot == -1) continue;\n    swap(vec[pivot], vec[rank]); // \u884Cswap\u306B\
    \u3088\u3063\u3066pivot\u304C0,1,2,...,rank-1\u884C\u76EE\u306B\u3042\u308B\u3088\
    \u3046\u306B\u3059\u308B\n\n    T inv = T(1) / vec[rank][col];\n    // pivot\u306E\
    \u884C\u306E\u5148\u982D\u304C1\u306B\u306A\u308B\u3088\u3046\u306B\u884C\u3092\
    \u5B9A\u6570\u500D\u3057\u3066\u63C3\u3048\u308B\n    for(int col2=0; col2<M;\
    \ col2++) {\n      vec[rank][col2] *= inv;\n    }\n\n    for(int row=0; row<N;\
    \ row++) {\n      // double\u306A\u3089\u3001 && A[row:[col] > EPS\u306E\u3068\
    \u304D\u306E\u307F\u3053\u306E\u64CD\u4F5C\u3092\u3059\u308B\n      if (row !=\
    \ rank) {\n        T fac = vec[row][col];\n        for(int col2=0; col2<M; col2++)\
    \ {\n          vec[row][col2] -= vec[rank][col2] * fac;\n        }\n      }\n\
    \    }\n    rank++;\n  }\n\n  return rank;\n}\n\n\n};\n\n\n#line 6 \"test/verify/math/matrix/yosupo-inverse-of-matrix.test.cpp\"\
    \n\nusing mint = modint998244353;\n\n\nint main() {\n  ios::sync_with_stdio(0);\
    \ cin.tie(0); cout.tie(0);\n  int N; cin >> N;\n\n  Matrix<mint>A(N,N);\n\n  for(int\
    \ i=0; i<N; i++) for(int j=0; j<N; j++) cin >> A[i][j];\n  Matrix<mint> inv =\
    \ A.inverse();\n  if (inv.size().first == 0) {\n    cout << -1 << endl;\n  }\n\
    \  else {\n    for(int i=0; i<N; i++) {\n      for(int j=0; j<N; j++) {\n    \
    \    cout << inv[i][j].val();\n        if (j != N-1) cout << \" \";\n        else\
    \ cout << endl;\n      }\n    }\n  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/inverse_matrix\"\n\n#include\
    \ \"template/template.hpp\"\n#include \"math/modint.hpp\"\n#include \"math/matrix/matrix.hpp\"\
    \n\nusing mint = modint998244353;\n\n\nint main() {\n  ios::sync_with_stdio(0);\
    \ cin.tie(0); cout.tie(0);\n  int N; cin >> N;\n\n  Matrix<mint>A(N,N);\n\n  for(int\
    \ i=0; i<N; i++) for(int j=0; j<N; j++) cin >> A[i][j];\n  Matrix<mint> inv =\
    \ A.inverse();\n  if (inv.size().first == 0) {\n    cout << -1 << endl;\n  }\n\
    \  else {\n    for(int i=0; i<N; i++) {\n      for(int j=0; j<N; j++) {\n    \
    \    cout << inv[i][j].val();\n        if (j != N-1) cout << \" \";\n        else\
    \ cout << endl;\n      }\n    }\n  }\n}\n"
  dependsOn:
  - template/template.hpp
  - math/modint.hpp
  - math/external_gcd.hpp
  - math/matrix/matrix.hpp
  isVerificationFile: true
  path: test/verify/math/matrix/yosupo-inverse-of-matrix.test.cpp
  requiredBy: []
  timestamp: '2024-08-21 21:41:37+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/verify/math/matrix/yosupo-inverse-of-matrix.test.cpp
layout: document
redirect_from:
- /verify/test/verify/math/matrix/yosupo-inverse-of-matrix.test.cpp
- /verify/test/verify/math/matrix/yosupo-inverse-of-matrix.test.cpp.html
title: test/verify/math/matrix/yosupo-inverse-of-matrix.test.cpp
---
