---
title: 約数についてのゼータ変換/メビウス変換
documentation_of: //convolution/divisor-zeta-moebius-transform.hpp
---

## 概要

計算量は $ O(N \log \log N) $ にできるけど、よくわからないので妥協。

### 約数についてのゼータ変換

```
vector<T> zeta_transform_naive<T, op>(const vector<T>& A)
```

可換な二項演算(大抵の場合、数の和) $\oplus$ があるとき、
長さ$N$の数列$A$が与えられたときに、 $ B_{i} = \bigoplus_{j \mid i} A_j$ なる数列 $B$ を求める。

`op`は、例えば`T=int`で二項演算が和なら
```
int op(int a, int b){
  return a + b;
}
```

などとして定義された関数を渡す。

- `f`: 添字 $1,\ldots,N$ の値を格納した配列。`f[0]` は変換対象外で、そのまま保持される。
- `op`: 値を結合する二項演算。ゼータ変換の定義どおりに集約できる可換演算を渡す。
- 戻り値: 添字 $i$ に対し、`op` で $i$ の約数の値を集約した配列。
### 計算量

- $O(N \log N) $

### 約数についてのメビウス変換

可換な二項演算(大抵の場合、数の和) $\oplus$ に逆元があるとき、
長さ$N$の数列$B$が与えられたときに、$B_i = \bigoplus_{j \mid i} A_j $ なる数列 $A$ を求める。

```
vector<T> moebius_transform_naive<T, invop>(const vector<T>& B)
``` 

invopは、例えば`T=int`で、二項演算が和なら
```
int invop(int a, int b) {
  return a - b;
}
```

などとして定義された関数を渡す。

- `f`: 添字 $1,\ldots,N$ の変換済み配列。`f[0]` はそのまま保持される。
- `invop`: ゼータ変換で使った演算を取り消す逆演算。
- 戻り値: 約数ゼータ変換を逆変換した配列。

### 計算量

- $O(N \log N) $



## mapでやるやつ

```
map<I,T> zeta_transform<I,T,op>(const map<I,T>& mp)
```

```
map<I,T> moebius_transform<I,T,invop>(const map<I, T>& mp)
```

- `mp`: 正の整数をキーとする map（キー 0 は使えない）。キーにある値だけを変換対象にし、存在しない約数の値は補いません。値として型 `T` を使う。
- `op` / `invop`: それぞれゼータ変換の結合演算と、その逆変換演算。
- 戻り値: 入力と同じキー集合で変換した map。

どちらもゼータ変換/メビウス変換を行うが、`vector`で変換する場合と違い、`map`のkeyだけを添え字として扱う。

`vector`で変換するときは $ 1 \leq i \leq N $ なすべての $i$ について求めたが、mapを使うと$N$の約数に付いてだけ求める！とかもできるようになる。

ちなみに、メビウス関数を使うと、

$ g(n) = \bigoplus_{d \mid n} f(d)  \Leftrightarrow f(n) = \bigoplus_{d \mid n} \mu (\fran n d) g(d) $ という関係があるので、それを使って求めることもできる。その場合、蟻本P267にあるように、

```C++
map<ll, ll> moebius(ll n) {
  std::map<ll, ll> res;
  std::vector<ll> primes;

  for (ll i=2; i*i <=n; i++) {
    if (n%i == 0) {
      primes.push_back(i);
      while (n%i == 0) n /= i;
    }
  }
  if (n != 1) primes.push_back(n);

  int m = primes.size();

  for (int s = 0; s < (1 << M); s++ ) {
    ll mu = 1, d = 1;
    for (int j=0; j<m; j++) {
      if ( i >> j & 1) {
        mu *= -1;
        d *= primes[j];
      }
    }

    res[d] = mu;
  }

  return res;
}

```

とするといいんじゃないか。書いていて思ったけど、結局メビウス関数を陽に扱わないやつのほうがシンプルでわかりやすいし、約数の個数の2乗の計算量がかかるといっても、どちらの方法もそもそも約数の計算に $\sqrt N $ かかるわけで、蟻本のようにやってもmapでやっても速度に大差は無い気がする。


### 計算量

`map`のサイズを $N$ として

- $O(N^2 \log N) $

配列版の補助空間は $O(N)$。map 版は $K$ をキー数として $O(K^2\log K)$ 時間、返り値用に $O(K)$ 空間。


## 何が嬉しいのか

一言で : 添字lcmで畳み込みができる

約数についてメビウス変換んしたあと各点積とってゼータ変換取ったらlcm畳み込みになる。TODO: 書く
