#define PROBLEM "https://judge.yosupo.jp/problem/deque_operate_all_composite"

#include "../../template/template.hpp"
#include "../../math/modint.hpp"
#include "../../structure/slide-window-aggregation.hpp"

using mint = modint998244353;
using mpp = pair<mint,mint>;

mpp op(mpp lf, mpp rf) {
  return {rf.first * lf.first, rf.first * lf.second + rf.second};
}

mpp e() {
  return {mint(1), mint(0)};
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  FoldableDeque<mpp,op,e> fdq;

  int Q; cin >> Q;

  for(int i=0; i<Q; i++) {
    int op; cin >> op;
    if (op == 0) {
      int a,b; cin >> a >> b;
      fdq.push_front({mint(a), mint(b)});
    }

    else if (op == 1) {
      int a, b; cin >> a >> b;
      fdq.push_back({mint(a), mint(b)});
    }
    else if (op == 2) {
      fdq.pop_front();
    }
    else if (op == 3) {
      fdq.pop_back();
    }
    else if (op == 4) {
      int x; cin >> x;
      mpp all_prod = fdq.all_prod();
      cout << mint(x) * all_prod.first + all_prod.second << endl;;
    }
  }
  return 0;
}