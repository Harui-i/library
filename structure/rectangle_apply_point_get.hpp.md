---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/verify/structure/yosupo-rectangle-add-point-get.test.cpp
    title: test/verify/structure/yosupo-rectangle-add-point-get.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"structure/rectangle_apply_point_get.hpp\"\n\n\n\n#include\
    \ <cassert>\n#include <vector>\n\ntemplate <class F, F (*composition)(F, F), F\
    \ (*id)(), class T = int>\nstruct rectangle_apply_point_get {\n  rectangle_apply_point_get(T\
    \ xl, T xr, T yl, T yr)\n      : xl(xl), xr(xr), yl(yl), yr(yr), root(-1) {\n\
    \    assert(xl < xr);\n    assert(yl < yr);\n    root = new_x_node();\n  }\n\n\
    \  void apply(T l, T r, T d, T u, F f) {\n    assert(xl <= l && l <= r && r <=\
    \ xr);\n    assert(yl <= d && d <= u && u <= yr);\n    apply_x(root, xl, xr, l,\
    \ r, d, u, f);\n  }\n\n  F get(T x, T y) const {\n    assert(xl <= x && x < xr);\n\
    \    assert(yl <= y && y < yr);\n    return get_x(root, xl, xr, x, y);\n  }\n\n\
    private:\n  struct XNode {\n    int left, right, y_root;\n  };\n\n  struct YNode\
    \ {\n    int left, right;\n    F val;\n  };\n\n  int new_x_node() {\n    xs.push_back({-1,\
    \ -1, -1});\n    return (int)xs.size() - 1;\n  }\n\n  int new_y_node() {\n   \
    \ ys.push_back({-1, -1, id()});\n    return (int)ys.size() - 1;\n  }\n\n  void\
    \ apply_x(int k, T nl, T nr, T ql, T qr, T qd, T qu, F f) {\n    if (qr <= nl\
    \ || nr <= ql) return;\n    if (ql <= nl && nr <= qr) {\n      xs[k].y_root =\
    \ apply_y(xs[k].y_root, yl, yr, qd, qu, f);\n      return;\n    }\n\n    T mid\
    \ = nl + (nr - nl) / 2;\n    if (ql < mid) {\n      if (xs[k].left == -1) {\n\
    \        int child = new_x_node();\n        xs[k].left = child;\n      }\n   \
    \   apply_x(xs[k].left, nl, mid, ql, qr, qd, qu, f);\n    }\n    if (mid < qr)\
    \ {\n      if (xs[k].right == -1) {\n        int child = new_x_node();\n     \
    \   xs[k].right = child;\n      }\n      apply_x(xs[k].right, mid, nr, ql, qr,\
    \ qd, qu, f);\n    }\n  }\n\n  int apply_y(int k, T nl, T nr, T ql, T qr, F f)\
    \ {\n    if (qr <= nl || nr <= ql) return k;\n    if (k == -1) k = new_y_node();\n\
    \    if (ql <= nl && nr <= qr) {\n      ys[k].val = composition(f, ys[k].val);\n\
    \      return k;\n    }\n\n    T mid = nl + (nr - nl) / 2;\n    if (ql < mid)\
    \ ys[k].left = apply_y(ys[k].left, nl, mid, ql, qr, f);\n    if (mid < qr) ys[k].right\
    \ = apply_y(ys[k].right, mid, nr, ql, qr, f);\n    return k;\n  }\n\n  F get_x(int\
    \ k, T nl, T nr, T x, T y) const {\n    if (k == -1) return id();\n\n    F res\
    \ = get_y(xs[k].y_root, yl, yr, y);\n    if (nr - nl == 1) return res;\n\n   \
    \ T mid = nl + (nr - nl) / 2;\n    if (x < mid) return composition(get_x(xs[k].left,\
    \ nl, mid, x, y), res);\n    return composition(get_x(xs[k].right, mid, nr, x,\
    \ y), res);\n  }\n\n  F get_y(int k, T nl, T nr, T y) const {\n    if (k == -1)\
    \ return id();\n\n    F res = ys[k].val;\n    if (nr - nl == 1) return res;\n\n\
    \    T mid = nl + (nr - nl) / 2;\n    if (y < mid) return composition(get_y(ys[k].left,\
    \ nl, mid, y), res);\n    return composition(get_y(ys[k].right, mid, nr, y), res);\n\
    \  }\n\n  T xl, xr, yl, yr;\n  int root;\n  std::vector<XNode> xs;\n  std::vector<YNode>\
    \ ys;\n};\n\n\n"
  code: "#ifndef HARUILIB_STRUCTURE_RECTANGLE_APPLY_POINT_GET_HPP\n#define HARUILIB_STRUCTURE_RECTANGLE_APPLY_POINT_GET_HPP\n\
    \n#include <cassert>\n#include <vector>\n\ntemplate <class F, F (*composition)(F,\
    \ F), F (*id)(), class T = int>\nstruct rectangle_apply_point_get {\n  rectangle_apply_point_get(T\
    \ xl, T xr, T yl, T yr)\n      : xl(xl), xr(xr), yl(yl), yr(yr), root(-1) {\n\
    \    assert(xl < xr);\n    assert(yl < yr);\n    root = new_x_node();\n  }\n\n\
    \  void apply(T l, T r, T d, T u, F f) {\n    assert(xl <= l && l <= r && r <=\
    \ xr);\n    assert(yl <= d && d <= u && u <= yr);\n    apply_x(root, xl, xr, l,\
    \ r, d, u, f);\n  }\n\n  F get(T x, T y) const {\n    assert(xl <= x && x < xr);\n\
    \    assert(yl <= y && y < yr);\n    return get_x(root, xl, xr, x, y);\n  }\n\n\
    private:\n  struct XNode {\n    int left, right, y_root;\n  };\n\n  struct YNode\
    \ {\n    int left, right;\n    F val;\n  };\n\n  int new_x_node() {\n    xs.push_back({-1,\
    \ -1, -1});\n    return (int)xs.size() - 1;\n  }\n\n  int new_y_node() {\n   \
    \ ys.push_back({-1, -1, id()});\n    return (int)ys.size() - 1;\n  }\n\n  void\
    \ apply_x(int k, T nl, T nr, T ql, T qr, T qd, T qu, F f) {\n    if (qr <= nl\
    \ || nr <= ql) return;\n    if (ql <= nl && nr <= qr) {\n      xs[k].y_root =\
    \ apply_y(xs[k].y_root, yl, yr, qd, qu, f);\n      return;\n    }\n\n    T mid\
    \ = nl + (nr - nl) / 2;\n    if (ql < mid) {\n      if (xs[k].left == -1) {\n\
    \        int child = new_x_node();\n        xs[k].left = child;\n      }\n   \
    \   apply_x(xs[k].left, nl, mid, ql, qr, qd, qu, f);\n    }\n    if (mid < qr)\
    \ {\n      if (xs[k].right == -1) {\n        int child = new_x_node();\n     \
    \   xs[k].right = child;\n      }\n      apply_x(xs[k].right, mid, nr, ql, qr,\
    \ qd, qu, f);\n    }\n  }\n\n  int apply_y(int k, T nl, T nr, T ql, T qr, F f)\
    \ {\n    if (qr <= nl || nr <= ql) return k;\n    if (k == -1) k = new_y_node();\n\
    \    if (ql <= nl && nr <= qr) {\n      ys[k].val = composition(f, ys[k].val);\n\
    \      return k;\n    }\n\n    T mid = nl + (nr - nl) / 2;\n    if (ql < mid)\
    \ ys[k].left = apply_y(ys[k].left, nl, mid, ql, qr, f);\n    if (mid < qr) ys[k].right\
    \ = apply_y(ys[k].right, mid, nr, ql, qr, f);\n    return k;\n  }\n\n  F get_x(int\
    \ k, T nl, T nr, T x, T y) const {\n    if (k == -1) return id();\n\n    F res\
    \ = get_y(xs[k].y_root, yl, yr, y);\n    if (nr - nl == 1) return res;\n\n   \
    \ T mid = nl + (nr - nl) / 2;\n    if (x < mid) return composition(get_x(xs[k].left,\
    \ nl, mid, x, y), res);\n    return composition(get_x(xs[k].right, mid, nr, x,\
    \ y), res);\n  }\n\n  F get_y(int k, T nl, T nr, T y) const {\n    if (k == -1)\
    \ return id();\n\n    F res = ys[k].val;\n    if (nr - nl == 1) return res;\n\n\
    \    T mid = nl + (nr - nl) / 2;\n    if (y < mid) return composition(get_y(ys[k].left,\
    \ nl, mid, y), res);\n    return composition(get_y(ys[k].right, mid, nr, y), res);\n\
    \  }\n\n  T xl, xr, yl, yr;\n  int root;\n  std::vector<XNode> xs;\n  std::vector<YNode>\
    \ ys;\n};\n\n#endif // HARUILIB_STRUCTURE_RECTANGLE_APPLY_POINT_GET_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: structure/rectangle_apply_point_get.hpp
  requiredBy: []
  timestamp: '2026-06-27 23:23:51+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/verify/structure/yosupo-rectangle-add-point-get.test.cpp
documentation_of: structure/rectangle_apply_point_get.hpp
layout: document
title: Rectangle Apply Point Get
---

長方形領域に作用素を掛け、一点に掛かっている作用素を取得するデータ構造です。

座標範囲を先に指定し、その範囲内の長方形作用と一点取得をオンラインに処理できます。

作用素 `F` はモノイドとして扱います。

```
F composition(F f, F g)
F id()
```

`composition(f, g)` は ACL の `lazy_segtree` と同じく、作用 `g` の後に作用 `f` を適用する合成、`id()` は単位元です。

## コンストラクタ

```
rectangle_apply_point_get<F, composition, id, T = int>(T xl, T xr, T yl, T yr)
```

座標範囲 $[xl, xr) \times [yl, yr)$ を指定する。
`T` は座標の型です。

## apply

```
void apply(T l, T r, T d, T u, F f)
```

領域 $[l, r) \times [d, u)$ に作用 `f` を掛ける。

### 計算量
座標範囲の幅を $X = xr - xl, Y = yr - yl$ として
- $O(\log X \log Y)$

新しく作られる内部ノード数も $O(\log X \log Y)$。

## get

```
F get(T x, T y)
```

点 `(x, y)` に掛かっている作用素の合成を返す。

### 計算量
座標範囲の幅を $X = xr - xl, Y = yr - yl$ として
- $O(\log X \log Y)$

内部ノードは作らない。
