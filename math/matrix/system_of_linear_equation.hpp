#ifndef HARUILIB_MATH_MATRIX_SYSTEM_OF_LINEAR_EQUATION_HPP
#define HARUILIB_MATH_MATRIX_SYSTEM_OF_LINEAR_EQUATION_HPP

#include <vector>
#include "math/matrix/matrix.hpp"

template <typename T>
std::vector<std::vector<T>> linear_equation(const std::vector<std::vector<T>>& a, const std::vector<std::vector<T>>& b) {
  assert(a.size() == b.size());
  int N = a.size();
  int M = a[0].size();

  Matrix <T> A(N, M);
  for(int i=0; i<N; i++) {
    for(int j=0; j<M; j++) A[i][j] = a[i][j];
    A[i][M] = b[i];
  }


}

#endif // HARUILIB_MATH_MATRIX_SYSTEM_OF_LINEAR_EQUATION_HPP