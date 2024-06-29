---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/matrix/matrix.hpp
    title: "Matrix(\u884C\u5217)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/matrix/system_of_linear_equation.hpp\"\n\n\n\n#include\
    \ <vector>\n#line 1 \"math/matrix/matrix.hpp\"\n\n\n\n#line 5 \"math/matrix/matrix.hpp\"\
    \n\ntemplate <class T>\nstruct Matrix{\nprivate: \n  std::vector<std::vector<T>>vec;\n\
    \  int N, M;\npublic:\n\n  Matrix(int _N, int _M) : N(_N), M(_M), vec(std::vector<std::vector<T>>(_N,\
    \ std::vector<T>(_M))) {\n    assert(_N >= 0 && _M >= 0); // 0*0\u306E\u884C\u5217\
    \u3092\u8FD4\u3057\u305F\u3044\u3068\u304D\u3082\u3042\u308B(\u9006\u884C\u5217\
    \u306A\u304B\u3063\u305F\u3068\u304D\u3068\u304B)\n  }\n\n  Matrix<T> operator*(const\
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
    \  // Solve Ax = b for H*W matrix A, longitudinal vector b, x.\n  // x using {W-rank(A)\
    \ + 1} vectors, x = x_0 + c_1 * x_1 + .... + c_{W-rank(A)} * x_{W-rank(A)} (c\
    \ is an arbitrary constant), so x_0, x_1, ... , x_{W-rank(A)} is returned. \n\
    \  // if there is no solution, return an empty vector sequence.\n  // ref : https://nyaannyaan.github.io/library/matrix/linear-equation.hpp\n\
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
    \    }\n    rank++;\n  }\n\n  return rank;\n}\n\n\n};\n\n\n#line 6 \"math/matrix/system_of_linear_equation.hpp\"\
    \n\ntemplate <typename T>\nstd::vector<std::vector<T>> linear_equation(const std::vector<std::vector<T>>&\
    \ a, const std::vector<std::vector<T>>& b) {\n  assert(a.size() == b.size());\n\
    \  int N = a.size();\n  int M = a[0].size();\n\n  Matrix <T> A(N, M);\n  for(int\
    \ i=0; i<N; i++) {\n    for(int j=0; j<M; j++) A[i][j] = a[i][j];\n    A[i][M]\
    \ = b[i];\n  }\n\n\n}\n\n\n"
  code: "#ifndef HARUILIB_MATH_MATRIX_SYSTEM_OF_LINEAR_EQUATION_HPP\n#define HARUILIB_MATH_MATRIX_SYSTEM_OF_LINEAR_EQUATION_HPP\n\
    \n#include <vector>\n#include \"math/matrix/matrix.hpp\"\n\ntemplate <typename\
    \ T>\nstd::vector<std::vector<T>> linear_equation(const std::vector<std::vector<T>>&\
    \ a, const std::vector<std::vector<T>>& b) {\n  assert(a.size() == b.size());\n\
    \  int N = a.size();\n  int M = a[0].size();\n\n  Matrix <T> A(N, M);\n  for(int\
    \ i=0; i<N; i++) {\n    for(int j=0; j<M; j++) A[i][j] = a[i][j];\n    A[i][M]\
    \ = b[i];\n  }\n\n\n}\n\n#endif // HARUILIB_MATH_MATRIX_SYSTEM_OF_LINEAR_EQUATION_HPP"
  dependsOn:
  - math/matrix/matrix.hpp
  isVerificationFile: false
  path: math/matrix/system_of_linear_equation.hpp
  requiredBy: []
  timestamp: '2024-06-29 08:51:47+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/matrix/system_of_linear_equation.hpp
layout: document
redirect_from:
- /library/math/matrix/system_of_linear_equation.hpp
- /library/math/matrix/system_of_linear_equation.hpp.html
title: math/matrix/system_of_linear_equation.hpp
---
