---
title : sparse-fps
documentation_of: //formal-power-series/sparse-fps.hpp
---

スパース(非0な項が多い)な形式的べき級数で効率的に計算する。

## inv_sparse
スパースな形式的べき級数の逆元を効率的(?)に計算する。
定数項は0でないことを要求する。

↓非ゼロな項のpairを与えるときに使う

```
FPS inv_sparse(const vector<pair<int,mint>>& f, int deg) 
```

↓普通にFPSを与えるとき

```
FPS inv_sparse(const FPS& f, int deg) 
```

### 計算量
非0な項の数を $K$、先頭の$N$項を求めるとして
- $O(NK)$

### 原理
そんなに難しくないけど、忘れてしまったときのために一応書いておく。

$g := f^{-1}$ として、$g$の$i$項目まで計算できているとする。

ここで、畳み込みの定義と逆元の定義から、
$g[i+1]f[0] + g[i] f[1] + \dots + g[1] f[i] + g[0] f[i+1] = 0$。変形して

$g[i+1] =  - \frac{g[1] f[1] + \dots + g[1] f[i] + g[0] f[i+1] }{f[0]} $　ここで、$f$はスパースだから、非ゼロな項は$K$個以下。よって$g[i+1]$を$O(K)$で求められる。これを$O(N)$回繰り返すから、全体で$O(NK)$で求められる。


## exp_sparse


```
FPS<mint> exp_sparse(const FPS<mint>& f, int deg) 
```


### 計算量

- $O(NK)$


### 原理

$f = f[0] + f[1] x + f[2] x^2 + \dots$
$F := \exp(f) = F[0] + F[1] x^1 + \dots$ 
としておく。

$F' = F * f'$なので
$F[1] + 2F[2] x + 3F[3] x^3 + \dots = f'(F[0] + F[1] x + F[2] x^2 + \dots)$
$F[0], F[1], \dots , F[i]$はわかっているとする。
両辺の$i$次の項に注目すると、左辺は$(i+1)F[i+1]$、右辺は $f' * F$の$i$次の部分。これらは今までにわかっている数値から$O(K)$回の計算で計算できるので、
それを$N-1$次まで計算することで、$O(NK)$で計算できる


