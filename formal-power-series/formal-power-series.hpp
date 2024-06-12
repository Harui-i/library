#pragma once

#include "../math/modint.hpp"
#include <bits/stdc++.h>

using namespace std;



template <typename mint>
struct FPS {
  vector<mint> _vec;

  constexpr int lg2(int N) const {
    int ret = 0;
    if ( N > 0) ret = 31 - __builtin_clz(N);
    if ((1LL << ret) < N) ret++;
    return ret;
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

  //*/

  FPS log(int deg=-1) const {
    assert(_vec[0] == mint(1));

    if (deg == -1) deg = size();
    FPS df = this->diff();
    FPS iv = this->inv(deg);
    FPS ret = (df * iv).pre(deg-1).integral();

    return ret;
  }

  FPS exp(int deg=-1) const {
    assert(_vec[0] == mint(0));

    if (deg == -1) deg = size();
    FPS g(1);
    g[0] = 1;
    for (int d=1; d<deg; d <<= 1) {
      // g_2d = g_d * (f(x) + 1 - log(g_d))
      FPS fpl1 = (*this + mint(1)).pre(2*d);
      FPS logg = g.log(2*d);
      FPS right = (fpl1 - logg);

      g = (g * right).pre(2*d);
    }

    return g.pre(deg);
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

  FPS(vector<mint> vec) : _vec(vec) {
  }

  FPS(initializer_list<mint> ilist) : _vec(ilist) {
  }

  // 項の数に揃えたほうがよさそう
  FPS(int sz) : _vec(vector<mint>(sz)) {
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

  // Nyaan先生のライブラリを大写経....
  FPS& operator/=(const FPS& rhs) {
    if (size() < rhs.size()) {
      return *this =  FPS(0);
    }
    int sz = size() - rhs.size() + 1;
//
//    FPS left = (*this).rev().pre(sz);
//    FPS right = rhs.rev();
//    right = right.inv(sz);
//    FPS mp = left*right;
//    mp = mp.pre(sz);
//    mp = mp.rev();
//    return *this = mp;
//    return *this = (left * right).pre(sz).rev();
    return *this =  ((*this).rev().pre(sz) * rhs.rev().inv(sz)).pre(sz).rev();
  }

  FPS& operator%=(const FPS &rhs) {
    *this -= *this / rhs * rhs;
    shrink(); 
    return *this;
  }

  FPS& operator+=(const mint& rhs) {
    _vec[0] += rhs;
    return *this;
  }

  FPS& operator-=(const mint& rhs) {
    _vec[0] -= rhs;
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
  friend FPS operator/(FPS a, const FPS& b) { return a /= b; }
  friend FPS operator%(FPS a, const FPS& b) {return a %= b; }

  friend FPS operator+(FPS a, const mint& b) {return a += b; }
  friend FPS operator-(FPS a, const mint& b) {return a -= b; }
  friend FPS operator*(FPS a, const mint& b) {return a *= b; }
  friend FPS operator/(FPS a, const mint& b) {return a /= b; }
  
  // sz次未満の項を取ってくる
  FPS pre(int sz) const {
    FPS ret = *this; 
    ret._vec.resize(sz);

    return ret;
  }

  FPS rev() const {
    FPS ret = *this;
    reverse(ret._vec.begin(), ret._vec.end());
    
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

  void shrink() {
    while (size() > 0 && _vec.back() == mint(0)) _vec.pop_back();
  }

  friend ostream& operator<<(ostream& os, const FPS& fps) {
    for (int i = 0; i < fps.size(); ++i) {
      if (i > 0) os << " ";
      os << fps._vec[i].val();
    }
    return os;
  }

  // 仮想関数ってやつ。mod 998244353なのか、他のNTT-friendlyなmodで考えるのか、それともGarnerで復元するのか、それとも畳み込みを$O(N^2)$で妥協するのかなどによって異なる
  virtual FPS inv(int deg=-1) const;
  virtual void CooleyTukeyNTT998244353(vector<mint>&a, bool is_reverse) const;
//  virtual FPS exp(int deg=-1) const;
  virtual vector<mint> multiply(const vector<mint>& a, const vector<mint>& b);
  };
