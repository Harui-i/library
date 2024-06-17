---
title : 上位集合の高速ゼータ変換
documentation_of: //convolution/superset-zeta-moebius-transform.hpp
---

## 概要

サイズ$N$の集合 $S$について、$f(S)$が($2^N$の`vector`で)与えられたときに、
$$ g(S) = \Sum_{S \subseteq T} f(S) $$ を求めたり(Zeta)、その逆変換を求めたり(Möbius)する。


### 計算量
ゼータもメビウスも

- $O(N 2^N ) $

