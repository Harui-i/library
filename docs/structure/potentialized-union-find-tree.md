---
title: Potentialized Union Find Tree (ポテンシャルつきUnionFind木)
documentation_of: //structure/potentialized-union-find-tree.hpp
---


## コンストラクタ

```
PotentializedUnionFindTree<T, op, invop, e>()
```
T: 群(の載ってる集合), op: 二項演算, invop: 二項演算の逆元, e: 二項演算の単位元を返す関数。
実際のコンストラクタは `PotentializedUnionFindTree(int n)` で、`n` は要素数。

# merge

```
int merge(int a, int b, T t)
```
aのポテンシャル - bのポテンシャルが`t`になるように併合する。

引数 `a`, `b` は要素番号、`t` は課すポテンシャル差。返り値は併合後の代表元。既に同じ集合なら状態を変更せず、代表元を返す。

### 計算量
- ならし $ (O(\alpha(n))) $

## same / leader / size

- `same(a, b)`: 2 要素が同じ集合か返す。$O(\alpha(n))$。
- `leader(a)`: 要素 `a` の代表元を返す。$O(\alpha(n))$。
- `size(a)`: `a` を含む集合の要素数を返す。この実装は全要素を走査するため $O(n\alpha(n))$。

各引数は $0 \le a,b < n$ を満たすこと。

# diff 

```
T diff(int a, int b)
```
aのポテンシャル - bのポテンシャルを計算する。
`a`, `b` が同じ集合に属している必要がある。異なる集合の場合は `assert` に失敗する。


### 計算量
- ならし $ (O(\alpha(n))) $

