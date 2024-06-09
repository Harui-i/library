---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/verify/yosupo-pow-of-matrix.test.cpp
    title: test/verify/yosupo-pow-of-matrix.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/matrix/square_matrix.hpp\"\n\ntemplate <class T> \n\
    struct SquareMatrix  {\nprivate:\n  int N;\n  vector<vector<T>> vec;\npublic:\n\
    \  SquareMatrix(int _N) : N(_N), vec(vector<vector<T>>(_N, vector<T>(_N)))  {}\n\
    \n  SquareMatrix& operator*=(const SquareMatrix<T>& rhs)  {\n    assert(N == rhs.N);\n\
    \    SquareMatrix ret(N);\n\n    for (int i=0; i<N; i++) for (int k=0; k<N; k++)\
    \ for(int j=0; j<rhs.N; j++) {\n      ret.vec[i][j] += vec[i][k] * rhs.vec[k][j];\n\
    \    } \n    vec = ret.vec;\n\n    return *this;\n  }\n\n  SquareMatrix& operator^=(unsigned\
    \ long long k) {\n    SquareMatrix B(N);\n    for(int i=0; i<N; i++) B[i][i] =\
    \ 1;\n\n    while (k > 0) {\n      if (k&1) {\n        B *= *this;\n      }\n\
    \      *this *= *this;\n      k >>= 1;\n    }\n    *this = B;\n    return *this;\
    \    \n  }\n  \n  vector<T>& operator[](int i) {\n    assert(i < N);\n    return\
    \ vec[i];\n  }\n\n  friend Matrix<T> operator*(Matrix a, const Matrix<T>& b) {\
    \ return a *= b; }\n  friend Matrix<T> operator^(Matrix a, const Matrix<T>& b)\
    \ { return a^=b; }\n};\n"
  code: "#pragma once\n\ntemplate <class T> \nstruct SquareMatrix  {\nprivate:\n \
    \ int N;\n  vector<vector<T>> vec;\npublic:\n  SquareMatrix(int _N) : N(_N), vec(vector<vector<T>>(_N,\
    \ vector<T>(_N)))  {}\n\n  SquareMatrix& operator*=(const SquareMatrix<T>& rhs)\
    \  {\n    assert(N == rhs.N);\n    SquareMatrix ret(N);\n\n    for (int i=0; i<N;\
    \ i++) for (int k=0; k<N; k++) for(int j=0; j<rhs.N; j++) {\n      ret.vec[i][j]\
    \ += vec[i][k] * rhs.vec[k][j];\n    } \n    vec = ret.vec;\n\n    return *this;\n\
    \  }\n\n  SquareMatrix& operator^=(unsigned long long k) {\n    SquareMatrix B(N);\n\
    \    for(int i=0; i<N; i++) B[i][i] = 1;\n\n    while (k > 0) {\n      if (k&1)\
    \ {\n        B *= *this;\n      }\n      *this *= *this;\n      k >>= 1;\n   \
    \ }\n    *this = B;\n    return *this;    \n  }\n  \n  vector<T>& operator[](int\
    \ i) {\n    assert(i < N);\n    return vec[i];\n  }\n\n  friend Matrix<T> operator*(Matrix\
    \ a, const Matrix<T>& b) { return a *= b; }\n  friend Matrix<T> operator^(Matrix\
    \ a, const Matrix<T>& b) { return a^=b; }\n};"
  dependsOn: []
  isVerificationFile: false
  path: math/matrix/square_matrix.hpp
  requiredBy: []
  timestamp: '2024-06-09 18:28:49+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/verify/yosupo-pow-of-matrix.test.cpp
documentation_of: math/matrix/square_matrix.hpp
layout: document
redirect_from:
- /library/math/matrix/square_matrix.hpp
- /library/math/matrix/square_matrix.hpp.html
title: math/matrix/square_matrix.hpp
---
