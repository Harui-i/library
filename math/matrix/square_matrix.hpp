#pragma once

template <class T> 
struct SquareMatrix  {
private:
  int N;
  vector<vector<T>> vec;
public:
  SquareMatrix(int _N) : N(_N), vec(vector<vector<T>>(_N, vector<T>(_N)))  {}

  SquareMatrix& operator*=(const SquareMatrix<T>& rhs)  {
    assert(N == rhs.N);
    SquareMatrix ret(N);

    for (int i=0; i<N; i++) for (int k=0; k<N; k++) for(int j=0; j<rhs.N; j++) {
      ret.vec[i][j] += vec[i][k] * rhs.vec[k][j];
    } 
    vec = ret.vec;

    return *this;
  }

  SquareMatrix& operator^=(unsigned long long k) {
    SquareMatrix B(N);
    for(int i=0; i<N; i++) B[i][i] = 1;

    while (k > 0) {
      if (k&1) {
        B *= *this;
      }
      *this *= *this;
      k >>= 1;
    }
    *this = B;
    return *this;    
  }
  
  vector<T>& operator[](int i) {
    assert(i < N);
    return vec[i];
  }

  friend SquareMatrix<T> operator*(SquareMatrix<T> a, const SquareMatrix<T>& b) { return a *= b; }
  friend SquareMatrix<T> operator^(SquareMatrix<T> a, const SquareMatrix<T>& b) { return a^=b; }
};