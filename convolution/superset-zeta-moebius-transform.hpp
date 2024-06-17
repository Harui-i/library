#ifndef HARUILIB_CONVOLUTION_SUPERSET_ZETA_MOEBIUS_TRANSFORM_HPP
#define HARUILIB_CONVOLUTION_SUPERSET_ZETA_MOEBIUS_TRANSFORM_HPP

#include <vector>

template <typename T>
std::vector<T> superset_zeta_transform(const std::vector<T>& f) {

  int n = 0; while ((1 << n) < (int)f.size()) n++;
  assert((int)f.size() == (1 << n)); // f.size() should be power of 2.


  std::vector<T> F = f;
  for (int k = 0; k < n; k++) {
    for (int s = 0; s < 1 << n; s++) {
      if (!((s >> k) & 1)) F[s] += F[s ^ (1 << k)];
    }
  }
  return F;
}


template <typename T>
std::vector<T> superset_moebius_transform(const std::vector<T>& f) {
  int n = 0; while ((1 << n) < (int)f.size()) n++;
  assert((int)f.size() == (1 << n)); // f.size() should be power of 2.

  std::vector<T> F = f;
  for (int k = 0; k < n; k++) {
    for (int s = 0; s < 1 << n; s++) {
      if (!((s >> k) & 1)) F[s] -= F[s ^ (1 << k)];
    }
  }
  return F;
}

#endif // HARUILIB_CONVOLUTION_SUPERSET_ZETA_MOEBIUS_TRANSFORM_HPP