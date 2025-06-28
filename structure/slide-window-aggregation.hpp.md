---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/verify/yosupo-deque-operate-all-composite.test.cpp
    title: test/verify/yosupo-deque-operate-all-composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/verify/yosupo-queue-operate-all-composite.test.cpp
    title: test/verify/yosupo-queue-operate-all-composite.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"structure/slide-window-aggregation.hpp\"\n\n\n\n#include\
    \ <vector>\n#include <algorithm>\n\ntemplate <class S, S (*op)(S, S), S (*e)()>\n\
    struct FoldableDeque {\n  struct Node {\n    S val;\n    S prod;\n  };\n\n  std::vector<Node>\
    \ front, back;\n\n  FoldableDeque() : front(), back() {}\n  size_t size() const\
    \ { return front.size() + back.size(); }\n  bool empty() const { return front.size()\
    \ + back.size() == 0; }\n\n\n  // nyaan\u3055\u3093\u306E\u3092\u30D1\u30AF\u3063\
    \u3066\u304A\u308A\n  void rebalance() {\n    int n = front.size() + back.size();\n\
    \    int s0 = n / 2 + (front.empty() ? n % 2 : 0);\n    // front\u306Bs0\u500B\
    \n    // back\u306BN - s0\u500B\u5165\u308C\u308B\n    vector<Node> a{front};\n\
    \    std::reverse(begin(a), end(a));\n    std::copy(begin(back), end(back), back_inserter(a));\n\
    \    front.clear(), back.clear();\n    for (int i = s0 - 1; i >= 0; i--) push_front(a[i].val);\n\
    \    for (int i = s0; i < n; i++) push_back(a[i].val);\n    return;\n  }\n\n \
    \ S all_prod() const {\n    if (front.empty() && back.empty() ) return e();\n\n\
    \    if (front.empty()) {\n      return back.back().prod;\n    }\n    else if\
    \ (back.empty()) {\n      return front.back().prod;\n    }\n\n    else return\
    \ op(front.back().prod, back.back().prod) ;\n  }\n\n  void push_back(const S&\
    \ x) {\n    if (back.empty()) {\n      back.push_back({x, x});\n    }\n    else\
    \ {\n      // \u9806\u5E8F\u602A\u3057\u3044\u304B\u3082\n      back.push_back({x,\
    \ op(back.back().prod, x) });\n    }\n  }\n\n  void push_front(const S& x) {\n\
    \    if (front.empty()) {\n      front.push_back({x, x});\n    }\n    else {\n\
    \      // \u9806\u5E8F\u602A\u3057\u3044\u304B\u3082\n      front.push_back({x,\
    \ op(x, front.back().prod) });\n    }  \n  }\n\n  void pop_back() {\n    assert(size()\
    \ > 0);\n    if (back.empty()) rebalance();\n    back.pop_back();\n  }\n\n  void\
    \ pop_front() {\n    assert(size() > 0);\n    if (front.empty()) rebalance();\n\
    \    front.pop_back();\n  }\n};\n\n"
  code: "#ifndef HARUILIB_LIBRARY_STRUCTURE_SLIDE_WINDOW_AGGREGATION_HPP\n#define\
    \ HARUILIB_LIBRARY_STRUCTURE_SLIDE_WINDOW_AGGREGATION_HPP\n\n#include <vector>\n\
    #include <algorithm>\n\ntemplate <class S, S (*op)(S, S), S (*e)()>\nstruct FoldableDeque\
    \ {\n  struct Node {\n    S val;\n    S prod;\n  };\n\n  std::vector<Node> front,\
    \ back;\n\n  FoldableDeque() : front(), back() {}\n  size_t size() const { return\
    \ front.size() + back.size(); }\n  bool empty() const { return front.size() +\
    \ back.size() == 0; }\n\n\n  // nyaan\u3055\u3093\u306E\u3092\u30D1\u30AF\u3063\
    \u3066\u304A\u308A\n  void rebalance() {\n    int n = front.size() + back.size();\n\
    \    int s0 = n / 2 + (front.empty() ? n % 2 : 0);\n    // front\u306Bs0\u500B\
    \n    // back\u306BN - s0\u500B\u5165\u308C\u308B\n    vector<Node> a{front};\n\
    \    std::reverse(begin(a), end(a));\n    std::copy(begin(back), end(back), back_inserter(a));\n\
    \    front.clear(), back.clear();\n    for (int i = s0 - 1; i >= 0; i--) push_front(a[i].val);\n\
    \    for (int i = s0; i < n; i++) push_back(a[i].val);\n    return;\n  }\n\n \
    \ S all_prod() const {\n    if (front.empty() && back.empty() ) return e();\n\n\
    \    if (front.empty()) {\n      return back.back().prod;\n    }\n    else if\
    \ (back.empty()) {\n      return front.back().prod;\n    }\n\n    else return\
    \ op(front.back().prod, back.back().prod) ;\n  }\n\n  void push_back(const S&\
    \ x) {\n    if (back.empty()) {\n      back.push_back({x, x});\n    }\n    else\
    \ {\n      // \u9806\u5E8F\u602A\u3057\u3044\u304B\u3082\n      back.push_back({x,\
    \ op(back.back().prod, x) });\n    }\n  }\n\n  void push_front(const S& x) {\n\
    \    if (front.empty()) {\n      front.push_back({x, x});\n    }\n    else {\n\
    \      // \u9806\u5E8F\u602A\u3057\u3044\u304B\u3082\n      front.push_back({x,\
    \ op(x, front.back().prod) });\n    }  \n  }\n\n  void pop_back() {\n    assert(size()\
    \ > 0);\n    if (back.empty()) rebalance();\n    back.pop_back();\n  }\n\n  void\
    \ pop_front() {\n    assert(size() > 0);\n    if (front.empty()) rebalance();\n\
    \    front.pop_back();\n  }\n};\n#endif // HARUILIB_LIBRARY_STRUCTURE_SLIDE_WINDOW_AGGREGATION_HPP"
  dependsOn: []
  isVerificationFile: false
  path: structure/slide-window-aggregation.hpp
  requiredBy: []
  timestamp: '2024-08-21 21:41:37+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/verify/yosupo-deque-operate-all-composite.test.cpp
  - test/verify/yosupo-queue-operate-all-composite.test.cpp
documentation_of: structure/slide-window-aggregation.hpp
layout: document
title: Foldable Deque(Slide Window Aggregation)
---

単位元があって、結合的な演算(逆元は必要なし)(可換じゃなくてもいいよ(!!))について、両端キュー(Deque)っぽい操作と、Deque内の要素の総積が(ならしも入れて) $O(1)$ で計算できるデータ構造です。セグ木でいいかも。


名称についてはSlide Window Aggregation(SWAG)というのも結構覇権だけど、https://qiita.com/Shirotsume/items/4a2837b5895ef9a7aeb1 の記事がFoldable Dequeという名称を推していたのでそれを採用してる。

## 計算量解析について

あとはまかせた: 

https://noshi91.hatenablog.com/entry/2019/10/10/230032

## コンストラクタ
```
FoldableDeque<S, op, e>()
```
S: モノイド, op: 二項演算, e: 二項演算の単位元を返す関数。


## push_back
dequeっぽく扱える。
### 計算量
- $O(1)$

## push_front
dequeっぽく扱える。

### 計算量
- $O(1)$

## pop_front
dequeっぽく扱える。

### 計算量
- $O(1)$ (ならし)

## pop_back
dequeっぽく扱える。

### 計算量
- $O(1)$ (ならし)

## all_prod
```
S all_prod()
```

Deque内にある要素の(先頭側から末尾側の順に計算した)総積を返す。

### 計算量
- $O(1)$
これがスゴイポイントであるけど、セグ木でいいじゃんかも。