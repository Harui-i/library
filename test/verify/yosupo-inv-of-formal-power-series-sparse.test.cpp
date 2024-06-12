#define PROBLEM "https://judge.yosupo.jp/problem/inv_of_formal_power_series_sparse"

#include "template/template.hpp"
#include "math/modint.hpp"
#include "formal-power-series/formal-power-series.hpp"
#include "formal-power-series/fps998.hpp"
#include "formal-power-series/sparse-fps.hpp"

using mint = modint998244353;


int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int N, K; cin >> N >> K;
  vector<pair<int,mint>> ia(K);
  for(int i=0; i<K; i++) cin >> ia[i].first >> ia[i].second;

  FPS<mint> inv = inv_sparse(ia, N);
  for(int i=0; i<N; i++) cout << inv[i] << " ";
  cout << endl;
}
