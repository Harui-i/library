---
title: 下位集合についての高速ゼータ変換/メビウス変換
documentation_of: //convolution/subset-zeta-moebius-transform.hpp
---

## 概要

可換な二項演算(大抵の場合、数の和) $\oplus$ があるとき、
サイズ$N$の集合 $S$について、$f(S)$が($2^N$の`vector`で)与えられたときに、
$ g(S) = \bigoplus_{T \subseteq S} f(T) $ を求めたり(Zeta)、その逆変換を求めたり(Möbius)する。

添字OR畳み込みは、下位集合についてゼータ変換したあとに各点積を取ってメビウス変換すると求められたりする。

## 関数

```cpp
vector<T> subset_zeta_transform(const vector<T>& f)
vector<T> subset_moebius_transform(const vector<T>& f)
```

- `f`: 添字を集合（ビットマスク）とする長さ $2^N$ の配列。長さは 2 の冪であること。
- `op` / `invop`: 変換で値を合成する二項演算。メビウス変換ではゼータ変換を逆に戻せる逆演算を指定する。
- 戻り値: それぞれ $g[S]=\bigoplus_{T\subseteq S}f[T]$ のゼータ変換、およびその逆変換。

`op` は可換モノイドの演算を想定する。`invop` はその演算を取り消す演算を指定する。

### 計算量
ゼータもメビウスも

- $O(N 2^N ) $

補助空間は返り値を含めて $O(2^N)$。
