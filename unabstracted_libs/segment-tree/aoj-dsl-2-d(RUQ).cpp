// https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_D
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned int uint;
template<class T> inline bool chmax(T& a, const T& b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, const T& b) { if (b < a) { a = b; return true; } return false; }
const int INTINF = 1000001000;
const int INTMAX = 2147483647;
const ll LLMAX = 9223372036854775807;
const ll LLINF = 1000000000000000000;

vector<pair<int,int>>dat;
int sz;

// k番目(0-indexed)の値を取得
int get(int k) {
  k += sz;
  int ret = INTMAX;
  int current_time = 0;
  while (k > 0) {
    if (dat[k].second > current_time) {
      ret = dat[k].first;
      current_time = dat[k].second;
    }
    k /= 2;
  }
  return ret;
}

// [l, r)をxに変更する(l, rは0-indexed)
void update(int l, int r, int x, int time) {
  l += sz; r += sz;
  while (l < r) {
    if (l % 2 == 1) {
      dat[l] = make_pair(x, time);
      l++;
    }

    if (r % 2 == 1) {
      r--;
      dat[r] = make_pair(x, time);
    }

    l /= 2; r /= 2;
  }
  assert(l == r); 

}


int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n, q; cin >> n >> q;

  sz = 1; while (sz < n) sz *= 2;

  dat.resize(sz * 2, make_pair(INTMAX, 0));

  int time = 1;

  while (q--) {
    int com; cin >> com;
    if (com == 0) {
      int s, t, x; cin >> s >> t >> x;
      update(s, t+1, x, ++time);
    }
    else {
      int t; cin >> t;
      cout << get(t) << endl;
    }
  }
  return 0;
}