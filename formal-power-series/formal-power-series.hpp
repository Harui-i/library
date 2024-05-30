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
  FPS inv_fast1(int deg=-1) const {
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
  
  // 巡回畳み込みを利用してFFTの回数を節約したNewton法による逆元計算
  // https://paper.dropbox.com/doc/fps--CQCZhUV1oN9UT3BCLrowhxgzAg-EoHXQDZxfduAB8wD1PMBW
  // 元の記事とはg_2dとかの命名が違う。f_2dなどの下付きの数字は、このコードでは形式的べき級数のサイズを表す。
  // ニュートン法1回あたりのFFTの計算量が、5 * F(2d)になる。
  // ↓コメントアウトのToggle切り替え用
  //*
  FPS inv_fast2(int deg=-1) const {
    assert(_vec[0] != mint(0));
    if (deg == -1) deg = size();
    FPS g(1);
    g._vec[0] = mint(_vec[0]).inv();

    for(int d=1; d<deg; d <<= 1) {
      // g_2n = g_n - (f_n g_n - 1) g_n
      // e_n := f_n g_n - 1

      FPS f_2d = (*this).pre(2*d);
      FPS g_d = g.pre(2*d);
      FPS g_origin = g.pre(2*d); // 後々使いたいので保存しておく

      CooleyTukeyNTT998244353(f_2d._vec, false);
      CooleyTukeyNTT998244353(g_d._vec, false);
      assert(2*d == (int)g_d.size() && f_2d.size() == g_d.size());
      FPS h_2d(2*d);
      for(int i=0; i<2*d; i++) h_2d[i] = f_2d[i] * g_d[i];
      CooleyTukeyNTT998244353(h_2d._vec, true);

      // こうすることで、h_2dは f_2d * g_dの 2d次未満の項に一致する。
      // h_2dはf_2dとg_dのサイズ2dの巡回畳み込みであるから、 h_2dの項は下図のようになっている。
      // ここで、h_2dのうちほしい部分は左上と、右上の部分のみ。(f_2d*g_dの2d次未満がほしいので)
      // 左上の部分は、g_dの性質から、 1, 0, 0, ... となっていることがわかる。
      // 右下の部分は deg(f_2d) < 2d, deg(g_d) < d → deg(f_2d*g_d) < 3d となって、0となっていることがわかる。
      // よって、h_2dの[d,2d)の部分はf_2d*g_dの[d,2d)に一致するので何も処理する必要がなく、
      // h_2dの[0,d)の部分は余計な足し算が入ってしまっているが、1,0,0,...に変えてしまえばよい。
      //    [0, d)の項            [d, 2d)の項
      //    f_2d*g_dの[0,d)       f_2d*g_dの[d, 2d)
      //    f_2d*g_dの[2d, 3d)    f_2d*g_dの[3d, 4d)

      h_2d[0]  = mint(0); // h_2dを (f_2d * g_d - 1)に変えちゃう。
      for(int i=1; i<d; i++) h_2d[i] = 0; 

      CooleyTukeyNTT998244353(h_2d._vec, false);
      for(int i=0; i<2*d; i++) h_2d[i] = g_d[i] * h_2d[i];
      CooleyTukeyNTT998244353(h_2d._vec, true);
      for(int i=0; i<d; i++) h_2d[i] = mint(0);
    
      // h_2d - 1 =: h'_2dとおく。
      // g_2d = g_d - h'_2d * g_d であり、さっきと同じような図を書くと, h_2d * g_dを巡回畳み込みしたものは、下図のようになっている。
      // 左上はall-zero(定数項も0にしたので)、右下も次数の関係から全部0なので、h_2d * g_dは、巡回畳み込みをしたものの[0,d)の項を0にすることで得られる。 
      //    [0, d)の項            [d, 2d)の項
      //    h'_2d*g_dの[0,d)       h'_2d*g_dの[d, 2d)
      //    h'_2d*g_dの[2d, 3d)    h'_2d*g_dの[3d, 4d)

      g = g_origin - h_2d;
      g.resize(d*2);

    }

    return g.pre(deg);

  }
  //*/

  FPS log(int deg=-1) {
    assert(_vec[0] == mint(1));

    if (deg == -1) deg = size();
    FPS df = this->diff();
    FPS iv = this->inv_fast2(deg);
    FPS ret = (df * iv).pre(deg-1).integral();

    return ret;
  }

  FPS integral() const {
    const int N = size();
    FPS ret(N+1);

    for(int i=0; i<N; i++) ret[i+1] = _vec[i] * mint(i+1).inv();

    return ret;
  }

  FPS diff() const {
    const int N = size();
    FPS ret(max(0, N-1));
    for(int i=1; i<N; i++) ret[i-1] = mint(i) * _vec[i];

    return ret;
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

  const mint& operator[](size_t i) const {
    return _vec[i];
  }

  mint& operator[](size_t i) {
    return _vec[i];
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
