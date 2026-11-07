---
title: 倍数についてのゼータ変換/メビウス変換
documentation_of: //convolution/multiple-zeta-moebius-transform.hpp
---

TODO: `map`で渡すタイプのゼータ/メビウス変換について書く

## 概要

計算量は $ O(N \log \log N) $ にできるけど、よくわからないので妥協。

### 倍数についてのゼータ変換

```
vector<T> zeta_transform_naive<T, op>(const vector<T>& A)
```

可換な二項演算(大抵の場合、数の和) $\oplus$ があるとき、
長さ$N$の数列$A$が与えられたときに、 $ B_i = \bigoplus_{i \mid j} A_j $ なる数列 $B$ を求める。

`op`は、例えば`T=int`で二項演算が和なら
```
int op(int a, int b){
  return a + b;
}
```

などとして定義された関数を渡す。

- `f`: 添字 $1,\ldots,N$ の値を格納した配列。`f[0]` は変換対象外で、そのまま保持される。
- `op`: 値を結合する二項演算。
- 戻り値: 添字 $i$ に対し、`op` で $i$ の倍数の値を集約した配列。

### 計算量

- $O(N \log N) $

### 倍数についてのメビウス変換

可換な二項演算(大抵の場合、数の和) $\oplus$ に逆元があるとき、
長さ$N$の数列$B$が与えられたときに、$B_i = \bigoplus_{i \mid j} A_j $ なる 数列$A$ を求める。

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
- 戻り値: 倍数ゼータ変換を逆変換した配列。

### 計算量

- $O(N \log N) $

## mapでやるやつ

```
map<I,T> zeta_transform<I,T,op>(const map<I,T>& mp)
```

```
map<I,T> moebius_transform<I,T,invop>(const map<I, T>& mp)
```

- `mp`: 正の整数をキーとする map。キーにある値だけを変換対象にする（キー 0 は使えない）。
- `op` / `invop`: それぞれゼータ変換の結合演算と、その逆変換演算。
- 戻り値: 入力と同じキー集合で変換した map。

どちらもゼータ変換/メビウス変換を行うが、`vector`で変換する場合と違い、`map`のkeyだけを添え字として扱う。


メビウス関数を使うと、

$ g(n) = \bigoplus_{n \mid i} f(i) \Leftrightarrow f(n) = \bigoplus_{ n \mid i} \mu (\frac i n) g(i) $ と表せるらしい。


### 計算量

`map`のサイズを$N$として

- $O(N^2 \log N) $

配列版の補助空間は $O(N)$。map 版は $K$ をキー数として $O(K^2\log K)$ 時間、返り値用に $O(K)$ 空間。


### 何が嬉しいのか

数列$A$と$B$が与えられたとして、倍数についてのゼータ変換をすることで
$ A^{\prime}$と $B^{\prime}$ を得る。 $ A^{\prime}_i B^{\prime}_i = \Sigma_{i \mid j , i \mid k} A_j B_k $ であり、

$ {i \mid j , i \mid k} $ とは $ i \mid gcd(j,k) $ と言い換えられるから、$A^{\prime} B^{\prime} $ を倍数についてメビウス変換することで、gcd畳み込みができる、みたいな感じ。(書いてて自信なくなってきたな。間違ってるかも)
