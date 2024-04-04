// https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned int uint;
template<class T> inline bool chmax(T& a, const T& b) {if (a<b) {a=b; return true;} return false;}
template<class T> inline bool chmin(T& a, const T& b) {if (b<a) {a=b; return true;} return false;}
const int INTINF = 1000001000;
const int INTMAX = 2147483647;
const ll LLMAX = 9223372036854775807;
const ll LLINF = 1000000000000000000;

vector<int> dat;
int sz;

// k番目(0-indexed)の値をaに変更
void update (int k, int a) {
 k += sz; 
 dat[k] = a;
 while (k > 0) {
   k /= 2;
   dat[k] = min(dat[k*2], dat[k*2+1]);
 }
}

// [l, r)の最小値を求める(l, rは0-indexed)
int query (int l, int r) {
  l += sz; r += sz;
  int L = INTMAX, R = INTMAX;
  while (l < r) {
    if (l%2 == 1) {
       L = min(L, dat[l]);
       l++;
    }

    if (r%2 == 1) {
      r--;
      R = min(dat[r], R);
    }

    l /= 2; r /= 2;
  }
  return min(L, R);
}


int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n, q; cin >> n >> q;

  sz = 1; while (sz < n) sz *= 2;

  dat.resize(sz * 2, INTMAX);  

  while (q--) {
    int com, x, y; cin >> com >> x >> y;
    if (com == 0) {
      update(x, y);
    } else {
      cout << query(x, y+1) << endl;
    }
  } 
  return 0;
}