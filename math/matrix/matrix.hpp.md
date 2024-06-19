---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/verify/math/matrix/yosupo-inverse-of-matrix.test.cpp
    title: test/verify/math/matrix/yosupo-inverse-of-matrix.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/verify/math/matrix/yosupo-matrix-product.test.cpp
    title: test/verify/math/matrix/yosupo-matrix-product.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/verify/math/matrix/yosupo-pow-of-matrix.test.cpp
    title: test/verify/math/matrix/yosupo-pow-of-matrix.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/verify/math/matrix/yosupo-rank-of-matrix.test.cpp
    title: test/verify/math/matrix/yosupo-rank-of-matrix.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/matrix/matrix.hpp\"\n\n\n\ntemplate <class T>\nstruct\
    \ Matrix{\nprivate: \n  vector<vector<T>>vec;\n  int N, M;\npublic:\n\n  Matrix(int\
    \ _N, int _M) : N(_N), M(_M), vec(vector<vector<T>>(_N, vector<T>(_M))) {\n  \
    \  assert(_N >= 0 && _M >= 0); // 0*0\u306E\u884C\u5217\u3092\u8FD4\u3057\u305F\
    \u3044\u3068\u304D\u3082\u3042\u308B(\u9006\u884C\u5217\u306A\u304B\u3063\u305F\
    \u3068\u304D\u3068\u304B)\n  }\n\n  Matrix<T> operator*(const Matrix<T>& rhs)\
    \ const  {\n    assert(M == rhs.N);\n    Matrix ret(N,rhs.M);\n    for (int i=0;\
    \ i<N; i++) for (int k=0; k<M; k++) for(int j=0; j<rhs.M; j++) {\n      ret.vec[i][j]\
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
    \ ret[i][j] = A[i][N+j];\n\n    return ret;\n  }  \n\nprivate:\n// 0<= j < var\u306A\
    j\u5217\u76EE\u306B\u3064\u3044\u3066\u6383\u304D\u51FA\u3057\u3066\u3001rank\u3092\
    \u8FD4\u3059\n\nint sweep(int var) {\n  assert(var <= M);\n  int rank = 0;\n\n\
    \  for(int col=0; col<var; col++) {\n    int pivot = -1;\n    for(int row=rank;\
    \ row<N; row++) {\n      // \u3053\u308C\u304Cdouble\u3068\u304B\u306A\u3089\u3001\
    \n      // if ( && chmax(mx, asb(A[row][col])) ) \u307F\u305F\u3044\u306A\u6761\
    \u4EF6\u3092\u4ED8\u3051\u3066\u3001\u3067\u304D\u308B\u3060\u3051\u7D76\u5BFE\
    \u5024\u306E\u5927\u304D\u3044pivot\u3092\u9078\u3076\u3088\u3046\u306B\u3059\u308B\
    \n      if (vec[row][col] != T(0)) {\n        pivot = row;\n        break; //double\
    \ \u306A\u3089\u9055\u3046\n      }\n    }\n\n    if (pivot == -1) continue;\n\
    \    swap(vec[pivot], vec[rank]);\n\n    T inv = T(1) / vec[rank][col];\n    //\
    \ pivot\u306E\u884C\u306E\u5148\u982D\u304C1\u306B\u306A\u308B\u3088\u3046\u306B\
    \u884C\u3092\u5B9A\u6570\u500D\u3057\u3066\u63C3\u3048\u308B\n    for(int col2=0;\
    \ col2<M; col2++) {\n      vec[rank][col2] *= inv;\n    }\n\n    for(int row=0;\
    \ row<N; row++) {\n      // double\u306A\u3089\u3001 && A[row:[col] > EPS\u306E\
    \u3068\u304D\u306E\u307F\u3053\u306E\u64CD\u4F5C\u3092\u3059\u308B\n      if (row\
    \ != rank) {\n        T fac = vec[row][col];\n        for(int col2=0; col2<M;\
    \ col2++) {\n          vec[row][col2] -= vec[rank][col2] * fac;\n        }\n \
    \     }\n    }\n    rank++;\n  }\n\n  return rank;\n}\n\n\n};\n\n\n"
  code: "#ifndef HARUILIB_MATH_MATRIX_MATRIX_HPP\n#define HARUILIB_MATH_MATRIX_MATRIX_HPP\n\
    \ntemplate <class T>\nstruct Matrix{\nprivate: \n  vector<vector<T>>vec;\n  int\
    \ N, M;\npublic:\n\n  Matrix(int _N, int _M) : N(_N), M(_M), vec(vector<vector<T>>(_N,\
    \ vector<T>(_M))) {\n    assert(_N >= 0 && _M >= 0); // 0*0\u306E\u884C\u5217\u3092\
    \u8FD4\u3057\u305F\u3044\u3068\u304D\u3082\u3042\u308B(\u9006\u884C\u5217\u306A\
    \u304B\u3063\u305F\u3068\u304D\u3068\u304B)\n  }\n\n  Matrix<T> operator*(const\
    \ Matrix<T>& rhs) const  {\n    assert(M == rhs.N);\n    Matrix ret(N,rhs.M);\n\
    \    for (int i=0; i<N; i++) for (int k=0; k<M; k++) for(int j=0; j<rhs.M; j++)\
    \ {\n      ret.vec[i][j] += vec[i][k] * rhs.vec[k][j];\n    } \n\n    return ret;\n\
    \  }\n\n  Matrix<T> operator^(unsigned long long k) const {\n    assert(N == M);\n\
    \    Matrix<T> ret(N, N);\n    for(int i=0; i<N; i++) ret[i][i] = T(1);\n\n  \
    \  Matrix<T> base = *this;\n\n    while (k > 0) {\n      if (k & 1) {\n      \
    \  ret *= base;\n      }\n\n      base *= base;\n      k >>= 1; \n    }\n\n  \
    \  return ret;\n  }\n\n  vector<T>& operator[](int i) {\n    assert(i < N);\n\
    \    return vec[i];\n  }\n\n  Matrix<T>& operator*=(const Matrix<T>& b) { return\
    \ (*this) = (*this) * b; }\n  Matrix<T>& operator^=(const unsigned long long k)\
    \ { return (*this) = (*this) ^ k; }\n\n  // \u3055\u3059\u304C\u306Brank\u3092\
    \u77E5\u308B\u306E\u306B\u526F\u4F5C\u7528\u304C\u3042\u308B\u306E\u306F\u30E4\
    \u30D0\u3044\u306E\u3067\n  int rank() const {\n    Matrix A = *this;\n    return\
    \ A.sweep(M);\n  }\n\n  // \u30B5\u30A4\u30BA\u3092\u8FD4\u3059\u3002N,M\u3092\
    const\u306B\u3057\u305F\u3044\u3051\u3069const\u306B\u3059\u308B\u3068*=\u3084\
    ^=\u304C\u9762\u5012\u306B\u306A\u308B\u305F\u3081\u3001N,M\u3092\u975Econst\u306E\
    private\u306B\u3059\u308B\u3053\u3068\u3067\u306A\u3093\u3068\u304B\u3059\u308B\
    \u3002\n  pair<int,int> size() const {\n    return make_pair(N, M);\n  }\n\n \
    \ // \u9006\u884C\u5217\u3092\u8FD4\u3059\u3002\u306A\u3051\u308C\u30700*0\u884C\
    \u5217\u3092\u8FD4\u3059(\u3053\u308C\u306FGifted infants\u306E\u30DE\u30CD\u3060\
    \u304C\u30010*0\u3092\u8FD4\u3059\u5B09\u3057\u3055\u306F\u3044\u307E\u3044\u3061\
    \u308F\u304B\u3063\u3066\u3044\u306A\u3044\u3002\u5909\u3048\u308B\u304B\u3082\
    \u3002)\n  Matrix<T> inverse() const {\n    assert(N == M);\n    Matrix A(N, 2*N);\n\
    \    for(int i=0; i<N; i++) for(int j=0; j<N; j++) A[i][j] = vec[i][j];\n    for(int\
    \ i=0; i<N; i++) A[i][N+i] = T(1);\n    int rank = A.sweep(N);\n    if (rank <\
    \ N) return Matrix(0,0);\n\n    Matrix<T> ret(N, N);\n    for(int i=0; i<N; i++)\
    \ for(int j=0; j<N; j++) ret[i][j] = A[i][N+j];\n\n    return ret;\n  }  \n\n\
    private:\n// 0<= j < var\u306Aj\u5217\u76EE\u306B\u3064\u3044\u3066\u6383\u304D\
    \u51FA\u3057\u3066\u3001rank\u3092\u8FD4\u3059\n\nint sweep(int var) {\n  assert(var\
    \ <= M);\n  int rank = 0;\n\n  for(int col=0; col<var; col++) {\n    int pivot\
    \ = -1;\n    for(int row=rank; row<N; row++) {\n      // \u3053\u308C\u304Cdouble\u3068\
    \u304B\u306A\u3089\u3001\n      // if ( && chmax(mx, asb(A[row][col])) ) \u307F\
    \u305F\u3044\u306A\u6761\u4EF6\u3092\u4ED8\u3051\u3066\u3001\u3067\u304D\u308B\
    \u3060\u3051\u7D76\u5BFE\u5024\u306E\u5927\u304D\u3044pivot\u3092\u9078\u3076\u3088\
    \u3046\u306B\u3059\u308B\n      if (vec[row][col] != T(0)) {\n        pivot =\
    \ row;\n        break; //double \u306A\u3089\u9055\u3046\n      }\n    }\n\n \
    \   if (pivot == -1) continue;\n    swap(vec[pivot], vec[rank]);\n\n    T inv\
    \ = T(1) / vec[rank][col];\n    // pivot\u306E\u884C\u306E\u5148\u982D\u304C1\u306B\
    \u306A\u308B\u3088\u3046\u306B\u884C\u3092\u5B9A\u6570\u500D\u3057\u3066\u63C3\
    \u3048\u308B\n    for(int col2=0; col2<M; col2++) {\n      vec[rank][col2] *=\
    \ inv;\n    }\n\n    for(int row=0; row<N; row++) {\n      // double\u306A\u3089\
    \u3001 && A[row:[col] > EPS\u306E\u3068\u304D\u306E\u307F\u3053\u306E\u64CD\u4F5C\
    \u3092\u3059\u308B\n      if (row != rank) {\n        T fac = vec[row][col];\n\
    \        for(int col2=0; col2<M; col2++) {\n          vec[row][col2] -= vec[rank][col2]\
    \ * fac;\n        }\n      }\n    }\n    rank++;\n  }\n\n  return rank;\n}\n\n\
    \n};\n\n#endif // HARUILIB_MATH_MATRIX_MATRIX_HPP"
  dependsOn: []
  isVerificationFile: false
  path: math/matrix/matrix.hpp
  requiredBy: []
  timestamp: '2024-06-14 19:04:40+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/verify/math/matrix/yosupo-matrix-product.test.cpp
  - test/verify/math/matrix/yosupo-inverse-of-matrix.test.cpp
  - test/verify/math/matrix/yosupo-pow-of-matrix.test.cpp
  - test/verify/math/matrix/yosupo-rank-of-matrix.test.cpp
documentation_of: math/matrix/matrix.hpp
layout: document
title: "Matrix(\u884C\u5217)"
---

行列色々を実装。
`-O2`などのコンパイルオプションを付けない場合、かなり遅くなるので、バカデカ行列の積を計算するときは注意!


TODO
- rankとか逆行列とか、様々な掃き出し法による計算
- 定数倍、行列の和や差など

## rank
行列の階数(rank)をGauss-Jordanの掃き出し法を使って求める。
`double`などの実数(を近似したもの)だと`EPS`の扱いとかで工夫が必要なため、たぶんうまくいかない。

### 計算量
行の数を$N$,列の数を$M$として、
- $O(NM^2)$

## inverse
正方行列の逆行列をGauss-Jordanの掃き出し法を使って求める。
`double`などの実数(を近似したもの)だと`EPS`の扱いとかで工夫が必要なため、たぶんうまくいかない。

### 計算量
行の数を$N$として
- $O(N^3)$

## determinant
いるか？未実装

## 線形連立方程式を解くやつ
ほしい。未実装