#ifndef HARUILIB_FORMAL_POWER_SERIES_SPARSE_FPS_HPP
#define HARUILIB_FORMAL_POWER_SERIES_SPARSE_FPS_HPP

#include <vector>
using namespace std;

#include "formal-power-series.hpp"

// calculate inverse of f(sparse)
// deg : -1 + ( maximum degree of g )
template <typename mint>
FPS<mint> inv_sparse(const vector<pair<int,mint>>& f, int deg) {
  assert(deg >= 0);
  for(int i=0; i<(int)f.size()-1; i++) assert(f[i].first < f[i+1].first); 
  assert(f[0].first == 0 && f[0].second != mint(0));

  mint f0inv = f[0].second.inv();
  vector<mint> g(deg); g[0] = f0inv;
  for(int i=0; i<deg-1; i++) {
    for (pair<int,mint> pim : f) {
      if (i+1 - pim.first >= 0) g[i+1] -= pim.second * g[i+1 - pim.first];
      else continue;
    }
    g[i+1] *= f0inv;
  }

  return g;
}

template <typename mint>
FPS<mint> inv_sparse(const FPS<mint>& f, int deg) {
  vector<pair<int,mint>> vpim;
  for(int i=0; i<f.size(); i++) if (f[i] != mint(0)) vpim.emplace_back(i, f[i]);

  return inv_sparse(vpim, deg);
}


/* tabun baggute masu. TODO
template<typename mint>
FPS multiply_sparse(const FPS& f, const vector<pair<int,mint>>& g, int deg) {

  

  FPS ret(deg);
  for (pair<int,mint> pim : g) {
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
FPS multiply_sparse(const FPS& f, const FPS& g) {
  vector<pair<mint,int>> vpmi;

  for(int i=0; i<g.size(); i++) if (g[i] != mint(0)) vpmi.emplace_back(i, g[i]);

  return multiply_sparse(f, vpmi);
}
*/

#endif // HARUILIB_FORMAL_POWER_SERIES_SPARSE_FPS_HPP