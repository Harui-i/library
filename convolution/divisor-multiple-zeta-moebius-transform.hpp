#ifndef HARUILIB_CONVOLUTION_DIVISOR_MULTIPLE_ZETA_MOEBIUS_TRANSFORM_HPP
#define HARUILIB_CONVOLUTION_DIVISOR_MULTIPLE_ZETA_MOEBIUS_TRANSFORM_HPP

#include <vector>

namespace multiple {

  // 倍数についてのゼータ変換。 g_n = \Sigma_{n|m} f_m なる g を求める。
  // n|mというのは、m%n==0という意味。
  // O(N log N) (調和級数)
  // うまくやるとO(Nlog(log(N)))にできることがよく知られているが、難しいしlogは定数なので妥協する。
  template <typename T>
  std::vector<T> zeta_transform_naive(const std::vector<T>& f) {
    int N = f.size()-1;
    std::vector<T> g = f;
    for (int i=1; i<=N; i++) {
      for (int j=2*i; j<=N; j+=i) {
        g[i] += f[j];
      }
    }

    return g;
  }

  // 倍数についてのメビウス変換
  // f_n = \Sigma_{n|m} g_m なる g を求める。
  // O(N log N) (調和級数)
  template <typename T>
  std::vector<T> moebius_transform_naive(const std::vector<T>& f) {
    int N = f.size()-1;
    std::vector<T> g = f;
    for (int i=N; i>=1; i--) {
      for (int j=2*i; j<=N; j+=i) {
        g[i] -= g[j];
      }
    }
    return g;
  }

}


#endif // HARUILIB_CONVOLUTION_DIVISOR_MULTIPLE_ZETA_MOEBIUS_TRANSFORM_HPP