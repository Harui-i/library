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

  Matrix& operator*=(const Matrix& rhs)  {
    assert(M == rhs.N);
    Matrix ret(N,rhs.M);
    for (int i=0; i<N; i++) for (int k=0; k<M; k++) for(int j=0; j<rhs.M; j++) {
      ret.vec[i][j] += vec[i][k] * rhs.vec[k][j];
    } 
    vec = ret;

    return *this;
  }

  vector<T>& operator[](int i) {
    assert(i < N);
    return vec[i];
  }

  friend Matrix<T> operator*(Matrix a, const Matrix<T>& b) { return a *= b; }

};