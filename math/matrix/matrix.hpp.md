---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/verify/yosupo-matrix-product.test.cpp
    title: test/verify/yosupo-matrix-product.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/matrix/matrix.hpp\"\n\ntemplate <class T>\nstruct Matrix{\n\
    protected: \n  vector<vector<T>>vec;\n  int N, M;\npublic:\n\n  Matrix(int _N,\
    \ int _M) : N(_N), M(_M), vec(vector<vector<T>>(_N, vector<T>(_M))) {\n    assert(_N\
    \ > 0 && _M > 0);\n  }\n\n  Matrix& operator*=(const Matrix& rhs)  {\n    assert(M\
    \ == rhs.N);\n    Matrix ret(N,rhs.M);\n    for (int i=0; i<N; i++) for (int k=0;\
    \ k<M; k++) for(int j=0; j<rhs.M; j++) {\n      ret.vec[i][j] += vec[i][k] * rhs.vec[k][j];\n\
    \    } \n    vec = ret;\n\n    return *this;\n  }\n\n  vector<T>& operator[](int\
    \ i) {\n    assert(i < N);\n    return vec[i];\n  }\n\n  friend Matrix<T> operator*(Matrix\
    \ a, const Matrix<T>& b) { return a *= b; }\n\n};\n"
  code: "#pragma once\n\ntemplate <class T>\nstruct Matrix{\nprotected: \n  vector<vector<T>>vec;\n\
    \  int N, M;\npublic:\n\n  Matrix(int _N, int _M) : N(_N), M(_M), vec(vector<vector<T>>(_N,\
    \ vector<T>(_M))) {\n    assert(_N > 0 && _M > 0);\n  }\n\n  Matrix& operator*=(const\
    \ Matrix& rhs)  {\n    assert(M == rhs.N);\n    Matrix ret(N,rhs.M);\n    for\
    \ (int i=0; i<N; i++) for (int k=0; k<M; k++) for(int j=0; j<rhs.M; j++) {\n \
    \     ret.vec[i][j] += vec[i][k] * rhs.vec[k][j];\n    } \n    vec = ret;\n\n\
    \    return *this;\n  }\n\n  vector<T>& operator[](int i) {\n    assert(i < N);\n\
    \    return vec[i];\n  }\n\n  friend Matrix<T> operator*(Matrix a, const Matrix<T>&\
    \ b) { return a *= b; }\n\n};"
  dependsOn: []
  isVerificationFile: false
  path: math/matrix/matrix.hpp
  requiredBy: []
  timestamp: '2024-06-09 18:28:49+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/verify/yosupo-matrix-product.test.cpp
documentation_of: math/matrix/matrix.hpp
layout: document
title: "Matrix(\u884C\u5217)"
---

行列色々を実装

TODO
- rankとか逆行列とか、様々な掃き出し法による計算
- 定数倍、行列の和や差など
