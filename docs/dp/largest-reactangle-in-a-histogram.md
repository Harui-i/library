---
title: ヒストグラム内の最大長方形
documentation_of: //dp/largest-rectangle-in-a-histogram.hpp
---

## 概要

ヒストグラム内の最大長方形を求める。お気持ちはコメントに書いてあるのでそれを参照してくれ。

番長とか先輩とかいうワードは、[スライド最大（最小）値・ヒストグラム内最大長方形問題を俯瞰する](https://qiita.com/kuuso1/items/318d42cd089a49eeb332)
という記事によるもの。

## largest_reactangle_in_a_histogram
```
ll largest_reactangle_in_a_histogram<vector<T>& vec>
```

`vec` を幅 1 の棒の高さとして、ヒストグラム内に作れる最大長方形の面積を `long long` で返す。高さは非負とする。空配列なら 0 を返す。引数の配列は変更しない。

### 引数

- `vec`: 各棒の高さを並べた配列。要素数を $N$ とする。

### 計算量
$O(N)$

補助空間は $O(N)$。
