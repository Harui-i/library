#define PROBLEM "https://judge.yosupo.jp/problem/log_of_formal_power_series_sparse"

#include "template/template.hpp"
#include "math/modint.hpp"
#include "formal-power-series/formal-power-series.hpp"
#include "formal-power-series/fps-998.hpp"
#include "formal-power-series/fps-sparse.hpp"

using mint = modint998244353;


int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int N, K; cin >> N >> K;

  FPS<mint> f(N);

  for (int i=0; i<K; i++) {
    int a, x; cin >> a >> x;
    f[a] = mint(x);
  }

  cout << log_sparse(f, N) << endl;
}
