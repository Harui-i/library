---
title : fps-sparse(疎な場合の高速化)
documentation_of: //formal-power-series/fps-sparse.hpp
---

非ゼロ項が少ない（スパースな）形式的べき級数で効率的に計算する。ここで `deg` は次数ではなく、計算する係数の個数を表す。

`get_nonzeros(f)` は、非ゼロ係数を `(次数, 係数)` の昇順ペア列にして返す。入力の項数を $N$、非ゼロ項数を $K$ として時間 $O(N)$、空間 $O(K)$。

## inv_sparse
スパースな形式的べき級数の逆元を効率的(?)に計算する。
定数項は0でないことを要求する。

↓非ゼロな項のpairを与えるときに使う
```cpp
FPS<mint> inv_sparse(const vector<pair<int,mint>>& f, int deg)
```

`f` は次数の昇順で重複のない非ゼロ係数の列で、先頭は `(0, f_0)`、かつ `f_0 != 0`。`deg` は出力の項数（正の整数）。戻り値は $f^{-1}$ の先頭 `deg` 項。

↓普通にFPSを与えるとき
```cpp
FPS inv_sparse(const FPS& f, int deg)
// または
f.inv_sparse(deg)
```

### 計算量
非ゼロ項数を $K$、出力項数を $N$ として時間 $O(NK)$、空間 $O(N)$。

### 原理
そんなに難しくないけど、忘れてしまったときのために一応書いておく。

$g := f^{-1}$ として、$g$の$i$項目まで計算できているとする。

ここで、畳み込みの定義と逆元の定義から、
$g[i+1]f[0] + g[i] f[1] + \dots + g[1] f[i] + g[0] f[i+1] = 0$。変形して

$g[i+1] =  - \frac{g[i] f[1] + g[i-1] f[2] + \dots + g[1] f[i] + g[0] f[i+1] }{f[0]} $　ここで、$f$はスパースだから、非ゼロな項は$K$個以下。よって$g[i+1]$を$O(K)$で求められる。これを$O(N)$回繰り返すから、全体で$O(NK)$で求められる。


## exp_sparse
```cpp
FPS<mint> exp_sparse(const FPS<mint>& f, int deg)
// または
f.exp_sparse(deg)
```

`f[0] == 0` を満たす `f` の指数関数を先頭 `deg` 項返す。`deg > 0` とし、係数体で $1,\ldots,deg-1$ の逆元が存在すること。

### 計算量
入力 `f` の非ゼロ項数を $K$、出力項数を $N=deg$ として、時間 $O(NK)$、空間 $O(N)$。

### 原理
$f = f[0] + f[1] x + f[2] x^2 + \dots$
$F := \exp(f) = F[0] + F[1] x^1 + \dots$
としておく。

$F' = F * f'$なので
$F[1] + 2F[2] x + 3F[3] x^3 + \dots = f'(F[0] + F[1] x + F[2] x^2 + \dots)$
$F[0], F[1], \dots , F[i]$はわかっているとする。
両辺の$i$次の項に注目すると、左辺は$(i+1)F[i+1]$、右辺は $f' * F$の$i$次の部分。これらは今までにわかっている数値から$O(K)$回の計算で計算できるので、
それを$N-1$次まで計算することで、$O(NK)$で計算できる

## log_sparse
```cpp
FPS<mint> log_sparse(const FPS<mint>& f, int deg)
// または
f.log_sparse(deg)
```

`f[0] == 1` を満たす `f` の対数を先頭 `deg` 項返す（返り値の定数項は 0）。`deg > 0` は出力項数。

### 計算量
入力 `f` の非ゼロ項数を $K$、出力項数を $N=deg$ として、時間 $O(NK)$、空間 $O(N)$。

### 原理
$\log(f) = \int (f' / f) dx$ を利用する。$f$がスパースでも$f^{-1}$はスパースとは限らないので、愚直に$f^{-1}$を計算すると$O(N \log N)$かかる。
しかし、$f^{-1}$と$f'$の積は、$f'$がスパースなので、$O(NK)$で計算できる。

## pow_sparse
```cpp
FPS<mint> pow_sparse(const FPS<mint>& f, long long k, int deg)
// または
f.pow_sparse(k, deg)
```

非負整数 `k` に対して `f^k` の先頭 `deg` 項を返す。`deg > 0` は出力項数。`k == 0` の場合は定数項 1 の級数を返す。

### 計算量
入力 `f` の非ゼロ項数を $K$、出力項数を $N=deg$ として、時間 $O(NK)$、空間 $O(N)$。

### 原理
$g = f^k$ とすると、$g' = k f^{k-1} f' = k g f^{-1} f'$ となる。
$g' f = k g f'$ の両辺の係数を比較することで、$g$ の各係数を $O(K)$ で求めることができる。

## multiply_sparse
```cpp
FPS<mint> multiply_sparse(const FPS<mint>& f, const FPS<mint>& g, int deg = -1)
// または
f.mul_sparse(g, deg)
```

`deg` は返す係数の個数。既定値 `-1` は積の全項を求める。`g` の非ゼロ項数を $K_g$ とすると、時間計算量は $O(|f|K_g)$、空間計算量は $O(deg)$。`FPS` 同士のオーバーロードでは $g$ の非ゼロ項を列挙する $O(|g|)$ もかかる。
