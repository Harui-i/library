#ifndef HARUILIB_FORMAL_POWER_SERIES_SPARSE_FPS_HPP
#define HARUILIB_FORMAL_POWER_SERIES_SPARSE_FPS_HPP

#include <vector>

#include "formal-power-series/formal-power-series.hpp"


// FPSの非ゼロな項を集めたvector<pair<int,mint>>を返す
template <typename mint>
std::vector<std::pair<int,mint>> get_nonzeros(const FPS<mint>& f) {
  std::vector<std::pair<int,mint>> ret;
  for (int i=0; i<f.size(); i++) {
    if (f[i] != mint(0)) ret.emplace_back(i, f[i]);
  }
  return ret;
}

// ↓--- inverse of sparse fps ---↓
// calculate inverse of f(sparse)
// deg : -1 + ( maximum degree of g )
template <typename mint>
FPS<mint> inv_sparse(const std::vector<std::pair<int,mint>>& f, int deg) {
  assert(deg >= 0);
  for(int i=0; i<(int)f.size()-1; i++) assert(f[i].first < f[i+1].first); 
  assert(f[0].first == 0 && f[0].second != mint(0));

  mint f0inv = f[0].second.inv();
  std::vector<mint> g(deg); g[0] = f0inv;
  for(int i=0; i<deg-1; i++) {
    for (std::pair<int,mint> pim : f) {
      if (i+1 - pim.first >= 0) g[i+1] -= pim.second * g[i+1 - pim.first];
      else continue;
    }
    g[i+1] *= f0inv;
  }

  return g;
}

template <typename mint>
FPS<mint> inv_sparse(const FPS<mint>& f, int deg) {
  return inv_sparse(get_nonzeros(f), deg);
}

// ↑--- inverse of sparse fps ----↑

// exp(f)のdeg次未満の部分を求める。
// F := exp(f) = F_0 + F_1 x + F_2 x^2 + ... とする。
// F' = F * f' なので
// F_1 + 2F_2 x + 3F_3 x^3 + ... = f' F.
// 0以上の整数iについて、i次の項に注目すると、
// (i+1) * F_{i+1} = [x^i] (f' * F)
// とわかる。Fは0,1,...,i次までわかってればF_{i+1}もわかるということになる。f'はスパースだからF_{i+1}はたかだかK回の計算で求められる.

template <typename mint>
FPS<mint> exp_sparse(const FPS<mint>& f, int deg) {
  FPS<mint> F(deg);
  F[0] = mint(1);

  std::vector<std::pair<int,mint>> nonzero_fdiff = get_nonzeros(f.diff());

  for (int i=0; i+1<deg; i++) {
    // F[i+1]を求める
    // (i+1) * F_{i+1} = [x^i] (f' * F)

    for (std::pair<int,mint> pim: nonzero_fdiff) {
      int a = pim.first;
      // Fのi-a次の項を足していく
      if (i-a < 0) continue;
      assert(i-a >= 0);
      assert(i+1 > i-a);
      F[i+1] += pim.second * F[i-a];
    }
    F[i+1] /= mint(i+1);
  }
  return F;
}


template <typename mint>
FPS<mint> log_sparse(const FPS<mint>& f, int deg) {
  FPS<mint> f_inv = inv_sparse(f, deg);
  return multiply_sparse(f_inv, f.diff(), deg).integral().pre(deg);
}

//tabun baggute masu. 
template<typename mint>
FPS<mint> multiply_sparse(const FPS<mint>& f, const std::vector<std::pair<int,mint>>& g, int deg = -1) {
  if (deg == -1) deg = f.size() - 1 + g.back().first + 1;

  FPS<mint> ret(deg);
  for (std::pair<int,mint> pim : g) {
    assert(pim.second != 0);
    if (pim.second == 0) continue;

    for(int i=0; i<f.size(); i++) {
      if (i+pim.first >= ret.size()) continue;
      if (f[i] != mint(0) && pim.second != mint(0)) ret[i+pim.first] += pim.second * f[i];
    }
  }

  return ret;
}

template <typename mint>
FPS<mint> multiply_sparse(const FPS<mint>& f, const FPS<mint>& g, int deg = -1) {
  std::vector<std::pair<int,mint>> vpmi;

  for(int i=0; i<g.size(); i++) if (g[i] != mint(0)) vpmi.emplace_back(i, g[i]);

  return multiply_sparse(f, vpmi, deg);
}

#endif // HARUILIB_FORMAL_POWER_SERIES_SPARSE_FPS_HPP
