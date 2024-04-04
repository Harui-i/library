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

int sz;
vector<int> dat, lazy;


int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n, q; cin >> n >> q;
  while (q--) {
    int com; cin >> com;
    if (com == 0) {
      int s, t, x; cin >> s >> t >> x;
    }
    else {
      int s, t; cin >> s >> t;
    }
  }
  return 0;
}