#pragma once

#include "../math/modint.hpp"
#include <bits/stdc++.h>

using namespace std;
using mint = modint998244353;

//ZETAS = {1,998244352,911660635,372528824,929031873,452798380,922799308,781712469,476477967,166035806,258648936,584193783,63912897,350007156,666702199,968855178,629671588,24514907,996173970,363395222,565042129,733596141,267099868,15311432};
// constexpr 関数内で ZETAS 配列を設定するための補助関数
constexpr std::array<mint, 24> setup_zetas() {
  std::array<mint, 24> zetas;
  zetas[23] = mint(3).pow(119);
  for (int i = 22; i >= 0; --i) {
    zetas[i] = (zetas[i + 1] * zetas[i + 1]);
  }
  return zetas;
}

// コンパイル時に ZETAS 配列を初期化
constexpr array<mint, 24> ZETAS = setup_zetas();
struct FPS {
  vector<mint> _vec;

  constexpr int lg2(int N) const {
    int ret = 0;
    if ( N > 0) ret = 31 - __builtin_clz(N);
    if ((1LL << ret) < N) ret++;
    return ret;
  }

  // 参考: https://www.creativ.xyz/fast-fourier-transform/
  void CooleyTukeyNTT998244353(vector<mint>& a, bool is_reverse) const {
    int N = a.size();
    int lgN = lg2(N);
    //for (int i = 0; 1 << i < N; i++) lgN++;
    assert(N == 1 << lgN);

    for (int i = 0; i < N; i++) {
      int j = 0;
      for (int k = 0; k < lgN; k++) j |= (i >> k & 1) << (lgN - 1 - k);
      if (i < j) swap(a[i], a[j]);
    }

    int lgb = -1;
    for (int b = 1; b < N; b *= 2) {
      lgb++;
      mint mpzeta = ZETAS[lgb + 1];
      if (is_reverse) mpzeta = mpzeta.inv();
      mint zeta = 1;

      for (int j = 0; j < b; j++) {
        for (int k = 0; k < N; k += b * 2) {
          mint s = a[j + k];
          mint t = (a[j + k + b] * zeta);
          a[j + k] = (s + t);
          a[j + k + b] = (s - t);
        }
        zeta *= mpzeta;
      }
    }
    if (is_reverse) {
      mint size_inv = mint(N).inv();
      for (int i = 0; i < N; i++) {
        a[i] *= size_inv;
      }
    }
  }


  vector<mint> multiply(vector<mint> const& a, vector<mint> const& b) {
    vector<mint> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    int n = 1 << lg2(a.size() + b.size());
    //while (n < (int)(a.size() + b.size())) n <<= 1;

    fa.resize(n);
    fb.resize(n);

    vector<mint>fc(n);
    if (min(a.size(), b.size()) <= 40) {
      for (int i = 0; i < (int)a.size(); i++) for (int j = 0; j < (int)b.size(); j++) fc[i + j] += fa[i] * fb[j];
    }
    else {
      CooleyTukeyNTT998244353(fa, false);
      CooleyTukeyNTT998244353(fb, false);
      for (int i = 0; i < n; ++i) fc[i] = fa[i] * fb[i];
      CooleyTukeyNTT998244353(fc, true);
    }
    fc.resize(a.size() + b.size() - 1);
    return fc;
  }

  // ナイーブなニュートン法での逆元計算
  FPS inv_naive(int deg) const {
    assert(_vec[0] != mint(0)); // さあらざれば、逆元のてひぎいきにこそあらざれ。
    if (deg == -1) deg = this->size();
    FPS g(1);
    g._vec[0] = mint(_vec[0]).inv();
    // g_{n+1} = 2 * g_n - f * (g_n)^2
    for (int d=1; d < deg; d <<= 1) {
      FPS g_twice = g * mint(2);
      FPS fgg = (*this).pre(d*2) * g * g;
      
      g = g_twice - fgg;
      g.resize(d*2);
    }

    return g.pre(deg);
  }

  // FFTの回数を節約したNewton法での逆元計算
  FPS inv_fast1(int deg) const {
    assert(_vec[0] != mint(0));
    if (deg == -1) deg = size();
    FPS g(1);
    g._vec[0] = mint(_vec[0]).inv();

    for(int d=1; d<deg; d <<= 1) {
      FPS g_squared = g;
      FPS g_twice = g * mint(2);

      g_squared.resize(d*4);
      CooleyTukeyNTT998244353(g_squared._vec, false);
      for(int i=0; i<g_squared.size(); i++) g_squared._vec[i] *= g_squared._vec[i];

      FPS fgg = (*this).pre(d*2);
      fgg.resize(d*4);
      CooleyTukeyNTT998244353(fgg._vec, false);

      for(int i=0; i<fgg.size(); i++) {
        fgg._vec[i] *= g_squared._vec[i];
      }
      CooleyTukeyNTT998244353(fgg._vec, true);
      fgg.resize(d*4 - 2);

      g = (g_twice - fgg); 
      g.resize(d*2);
    }

    return g.pre(deg);
  }

  FPS(vector<mint> vec) {
    _vec = vec;
  }

  FPS(initializer_list<mint> ilist) {
    _vec = ilist;
  }

  // 項の数に揃えたほうがよさそう
  FPS(int sz) {
    _vec.resize(sz);
  }

  int size() const {
    return _vec.size();
  }

  FPS& operator+=(const FPS& rhs) {
    if (rhs.size() > this->size()) _vec.resize(rhs.size());
    for (int i = 0; i < (int)rhs.size(); ++i) _vec[i] += rhs._vec[i];
    return *this;
  }

  FPS& operator-=(const FPS& rhs) {
    if (rhs.size() > this->size()) this->_vec.resize(rhs.size());
    for (int i = 0; i < (int)rhs.size(); ++i) _vec[i] -= rhs._vec[i];
    return *this;
  }

  FPS& operator*=(const FPS& rhs) {
    _vec = multiply(_vec, rhs._vec);
    return *this;
  }

  FPS& operator*=(const mint& rhs) {
    for(int i=0; i<size(); i++) _vec[i] *= rhs;
    return *this;
  }

  FPS& operator/=(const mint& rhs) {
    for(int i=0; i<size(); i++) _vec[i] *= rhs.inv();
    return *this;
  }

  FPS operator>>(int sz) const {
    if ((int)this->size() <= sz) return {};
    FPS ret(*this);
    ret._vec.erase(ret._vec.begin(), ret._vec.begin() + sz);
    return ret;
  }

  FPS operator<<(int sz) const {
    FPS ret(*this);
    ret._vec.insert(ret._vec.begin(), sz, mint(0));

    return ret;
  }

  friend FPS operator+(FPS a, const FPS& b) { return a += b; }
  friend FPS operator-(FPS a, const FPS& b) { return a -= b; }
  friend FPS operator*(FPS a, const FPS& b) { return a *= b; }

  friend FPS operator*(FPS a, const mint& b) {return a *= b; }
  friend FPS operator/(FPS a, const mint& b) {return a /= b; }

  FPS pre(int sz) const {
    FPS ret = *this; 
    ret._vec.resize(sz);

    return ret;
  }

  void resize(int sz)  {
    this->_vec.resize(sz);
  }

  friend ostream& operator<<(ostream& os, const FPS& fps) {
    for (int i = 0; i < fps.size(); ++i) {
      if (i > 0) os << " ";
      os << fps._vec[i];
    }
    return os;
  }
};
