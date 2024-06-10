#pragma once

template <class T>
struct Matrix{
protected: 
  vector<vector<T>>vec;
  int N, M;
public:

  Matrix(int _N, int _M) : N(_N), M(_M), vec(vector<vector<T>>(_N, vector<T>(_M))) {
    assert(_N > 0 && _M > 0);
  }

  Matrix operator*(const Matrix& rhs) const  {
    assert(M == rhs.N);
    Matrix ret(N,rhs.M);
    for (int i=0; i<N; i++) for (int k=0; k<M; k++) for(int j=0; j<rhs.M; j++) {
      ret.vec[i][j] += vec[i][k] * rhs.vec[k][j];
    } 

    return ret;
  }

  Matrix operator^(unsigned long long k) const {
    assert(N == M);
    Matrix ret(N, N);
    for(int i=0; i<N; i++) ret[i][i] = T(1);

    Matrix base = *this;

    while (k > 0) {
      if (k & 1) {
        ret *= base;
      }

      base *= base;
      k >>= 1; 
    }

    return ret;
  }

  vector<T>& operator[](int i) {
    assert(i < N);
    return vec[i];
  }

  Matrix<T>& operator*=(const Matrix<T>& b) { return (*this) = (*this) * b; }
  Matrix<T>& operator^=(const unsigned long long k) { return (*this) = (*this) ^ k; }
};