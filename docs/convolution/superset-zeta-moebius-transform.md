---
title : 上位集合の高速ゼータ変換
documentation_of: //convolution/superset-zeta-moebius-transform.hpp
---

## 概要

サイズ$N$の集合 $S$について、$f(S)$が($2^N$の`vector`で)与えられたときに、
$ g(S) = \Sigma_{S \subseteq T} f(S) $ を求めたり(Zeta)、その逆変換を求めたり(Möbius)する。

添字AND畳み込みは、上位集合についてゼータ変換したあとに各点積を取ってメビウス変換すると求められたりする。

Scrapboxを見るといっぱい資料がある。

### 計算量
ゼータもメビウスも

- $O(N 2^N ) $

