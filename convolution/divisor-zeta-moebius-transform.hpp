#ifndef HARUILIB_CONVOLUTION_DIVISOR_ZETA_MOEBIUS_TRANSFORM_HPP
#define HARUILIB_CONVOLUTION_DIVISOR_ZETA_MOEBIUS_TRANSFORM_HPP

#include <vector>

namespace divisor {
  // 約数についてのゼータ変換。 g_n = \Sigma_{m|n} f_m なる g を求める。
  template <typename T>
  std::vector<T> zeta_transform_naive(const std::vector<T>& f) {
    int N = f.size() - 1;
    std::vector<T> g = f;

    for(int i=1; i<=N; i++) {
      for(int j=2*i; j<=N; j+=i) {
        g[j] += f[i];
      }
    }

    return g;
  }

  // 約数についてのメビウス変換。 f_n = \Sigma_{m|n} g_m なる g を求める。
  template <typename T>
  std::vector<T> moebius_transform_naive(const std::vector<T>& f) {
    int N = f.size() - 1;
    std::vector<T> g = f;

    for (int i=1; i<=N; i++) {
      for (int j=i*2; j<= N; j+=i) {
        g[j] -= g[i];
      }
    }

    return g;
  }
}


#endif // HARUILIB_CONVOLUTION_DIVISOR_ZETA_MOEBIUS_TRANSFORM_HPP