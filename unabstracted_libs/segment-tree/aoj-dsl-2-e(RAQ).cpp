// https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_E
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

vector<int> dat;
int sz;

// k番目(0-indexed)の値を取得
int get(int k) {
  k += sz;
  int ret = 0;
  while (k > 0) {
    ret += dat[k];
    k /= 2;
  }
  return ret;
}

// [l, r)にxを加算する(l, rは0-indexed)
void add(int l, int r, int x) {
  l += sz; r += sz;
  while (l < r) {
    if (l % 2 == 1) {
      dat[l] += x;
      l++;
    }

    if (r % 2 == 1) {
      r--;
      dat[r] += x;
    }

    l /= 2; r /= 2;
  }
}


int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n, q; cin >> n >> q;

  sz = 1; while (sz < n) sz *= 2;

  dat.resize(sz * 2, 0);

  while (q--) {
    int com; cin >> com;
    if (com == 0) {
      int s, t, x; cin >> s >> t >> x;
      add(s-1, t, x);
    }
    else {
      int t; cin >> t;
      cout << get(t-1) << endl;
    }
  }
  return 0;
}