---
title: Bostan-Mori法
documentation_of: //formal-power-series/bostan-mori.hpp
---

線形漸化式の第N項や、形式的べき級数の分数 P(x)/Q(x) の係数を高速に求めるアルゴリズム。

## 使い方

```
mint BostanMori(FPS<mint> P, FPS<mint> Q, unsigned long long N)
```

P(x) / Q(x) の x^N の係数を返す。Q[0] != 0 が必要。

- `P`, `Q`: 係数を昇べき順に保持した形式的べき級数。`Q` は空でなく、定数項が 0 でないこと。
- `N`: 取得する係数の次数（0-indexed）。
- 戻り値: $[x^N]P(x)/Q(x)$。

```
mint BostanMori(const vector<mint>& a, const vector<mint>& c, unsigned long long N)
```

a_0..a_{K-1} と
a_{n+K} = c_1 a_{n+K-1} + ... + c_K a_n
が与えられたときの a_N を返す。

- `a`: 初期値列。`a[i] = a_i`。
- `c`: 漸化式係数列。`c[i] = c_{i+1}`。`a` と同じ長さであること。
- `N`: 求める項の添字（0-indexed）。
- 戻り値: $a_N$。

内部で Q(x) = 1 - c_1 x - ... - c_K x^K とし、
P(x) = (A(x) Q(x)) mod x^K を作って Bostan-Mori に流している。

## 計算量
畳み込みが FFT/NTT で高速化されるなら
- $O(K \log K \log N)$

ナイーブな畳み込みなら
- $O(K^2 \log N)$

ここで $K=|a|=|c|$。直接 FPS を渡すオーバーロードの計算量は、初期多項式の次数にも依存し、畳み込みを1回 $M(n)$ と書けば $O(M(n)\log N)$ となる。

## 参考
- https://qiita.com/ryuhe1/items/da5acbcce4ac1911f47a
