#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include "template/template.hpp"
#include "math/modint.hpp"

#include "convolution/multiple-zeta-moebius-transform.hpp"

using mint = modint998244353;

// mapで倍数のゼータ変換とメビウス変換やるやつのテスト
void test() {
  random_device seed_gen;
  mt19937 rng(seed_gen()); 


  auto map_transform =  [&rng] (int N) {
    map<ll, mint> a_mp;
    vector<mint> a_vec(N+1);

    for (ll i=1; i*i <= N; i++) {
      if (N%i == 0) {
        int r1 = rng();
        int r2 = rng();
        a_mp[i] = r1;
        a_vec[i] = r1;

        a_mp[N/i] = r2;
        a_vec[N/i] = r2;
      }
    }

    map<ll, mint> a_mp2 = multiple::zeta_transform(a_mp);
    vector<mint> a_vec2 = multiple::zeta_transform_naive(a_vec);

    for (pair<ll, mint> plmi : a_mp2) {
      assert(a_vec2[plmi.first] == plmi.second);
    }

    map<ll,mint> a_mp3 = multiple::moebius_transform(a_mp2);
    vector<mint> a_vec3 = multiple::moebius_transform_naive(a_vec2);
    
    assert(a_mp == a_mp3 && "multiple transform for map");
    assert(a_vec == a_vec3 && "multiple transform for vector");

    for (pair<ll, mint> plmi : a_mp3) {
      assert(a_vec3[plmi.first] == plmi.second);
    }

  };

  for (int i=0; i<1000; i++) {
    map_transform(rng()%10000 + 1);
  }
  return;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  test();
  int A, B; cin >> A >> B;
  cout << A+B << endl;
}