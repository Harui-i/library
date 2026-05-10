---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: structure/fenwick_tree.hpp
    title: structure/fenwick_tree.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/verify/structure/yosupo-rectangle-sum.test.cpp
    title: test/verify/structure/yosupo-rectangle-sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"structure/offline_2dsum.hpp\"\n\n\n\n#include <algorithm>\n\
    #include <cassert>\n#include <vector>\n#line 1 \"structure/fenwick_tree.hpp\"\n\
    \n\n\n#line 6 \"structure/fenwick_tree.hpp\"\n\ntemplate <class T> struct fenwick_tree\
    \ {\n  fenwick_tree(): _n(0) {}\n  explicit fenwick_tree(int n): _n(n), data(n)\
    \ {}\n\n  // point add\n  void add(int p, T x) {\n    assert(0 <= p && p < _n);\n\
    \    p++;\n    while (p <= _n) {\n      data[p-1] += T(x);\n      p += p & -p;\n\
    \    }\n  } \n\n  T sum(int l, int r) {\n    assert(0 <= l && l <= r && r <= _n);\n\
    \    return sum(r) - sum(l);\n  }\n\nprivate:\n  int _n;\n  std::vector<T> data;\n\
    \  T sum(int r) {\n    T ret(0);\n    while (r > 0) {\n      ret += data[r-1];\n\
    \      r -= r & -r;\n    }\n\n    return ret;\n  }\n};\n\n\n#line 8 \"structure/offline_2dsum.hpp\"\
    \n\ntemplate <class T, class W> struct offline_2dsum {\n  struct Point {\n   \
    \ T x, y;\n    W w;\n  };\n  struct Query {\n    T l, r, d, u;\n  };\n\n  void\
    \ add_point(T x, T y, W w) {\n    points.push_back({x, y, w});\n  }\n\n  void\
    \ add_query(T l, T r, T d, T u) {\n    assert(l <= r && d <= u);\n    queries.push_back({l,\
    \ r, d, u});\n  }\n\n  std::vector<W> solve() {\n    int n = points.size();\n\
    \    int q = queries.size();\n    std::vector<W> res(q, 0);\n\n    std::vector<T>\
    \ ys;\n    ys.reserve(n);\n    for (auto& p : points) ys.push_back(p.y);\n   \
    \ std::sort(ys.begin(), ys.end());\n    ys.erase(std::unique(ys.begin(), ys.end()),\
    \ ys.end());\n\n    auto get_y = [&](T y) {\n      return std::lower_bound(ys.begin(),\
    \ ys.end(), y) - ys.begin();\n    };\n\n    struct Event {\n      T x;\n     \
    \ int d, u;\n      int id;\n      int type; // -1 for l, 1 for r\n      bool operator<(const\
    \ Event& other) const {\n        if (x != other.x) return x < other.x;\n     \
    \   return type < other.type;\n      }\n    };\n\n    std::vector<Event> events;\n\
    \    events.reserve(2 * q);\n    for (int i = 0; i < q; i++) {\n      assert(queries[i].l\
    \ <= queries[i].r && queries[i].d <= queries[i].u);\n      int d = get_y(queries[i].d);\n\
    \      int u = get_y(queries[i].u);\n      events.push_back({queries[i].l, d,\
    \ u, i, -1});\n      events.push_back({queries[i].r, d, u, i, 1});\n    }\n\n\
    \    std::sort(events.begin(), events.end());\n    std::sort(points.begin(), points.end(),\
    \ [](const Point& a, const Point& b) {\n      return a.x < b.x;\n    });\n\n \
    \   fenwick_tree<W> ft(ys.size());\n    int pi = 0;\n    for (auto& e : events)\
    \ {\n      while (pi < n && points[pi].x < e.x) {\n        ft.add(get_y(points[pi].y),\
    \ points[pi].w);\n        pi++;\n      }\n      res[e.id] += (W)e.type * ft.sum(e.d,\
    \ e.u);\n    }\n\n    return res;\n  }\n\nprivate:\n  std::vector<Point> points;\n\
    \  std::vector<Query> queries;\n};\n\n\n"
  code: "#ifndef HARUILIB_STRUCTURE_OFFLINE_2DSUM_HPP\n#define HARUILIB_STRUCTURE_OFFLINE_2DSUM_HPP\n\
    \n#include <algorithm>\n#include <cassert>\n#include <vector>\n#include \"structure/fenwick_tree.hpp\"\
    \n\ntemplate <class T, class W> struct offline_2dsum {\n  struct Point {\n   \
    \ T x, y;\n    W w;\n  };\n  struct Query {\n    T l, r, d, u;\n  };\n\n  void\
    \ add_point(T x, T y, W w) {\n    points.push_back({x, y, w});\n  }\n\n  void\
    \ add_query(T l, T r, T d, T u) {\n    assert(l <= r && d <= u);\n    queries.push_back({l,\
    \ r, d, u});\n  }\n\n  std::vector<W> solve() {\n    int n = points.size();\n\
    \    int q = queries.size();\n    std::vector<W> res(q, 0);\n\n    std::vector<T>\
    \ ys;\n    ys.reserve(n);\n    for (auto& p : points) ys.push_back(p.y);\n   \
    \ std::sort(ys.begin(), ys.end());\n    ys.erase(std::unique(ys.begin(), ys.end()),\
    \ ys.end());\n\n    auto get_y = [&](T y) {\n      return std::lower_bound(ys.begin(),\
    \ ys.end(), y) - ys.begin();\n    };\n\n    struct Event {\n      T x;\n     \
    \ int d, u;\n      int id;\n      int type; // -1 for l, 1 for r\n      bool operator<(const\
    \ Event& other) const {\n        if (x != other.x) return x < other.x;\n     \
    \   return type < other.type;\n      }\n    };\n\n    std::vector<Event> events;\n\
    \    events.reserve(2 * q);\n    for (int i = 0; i < q; i++) {\n      assert(queries[i].l\
    \ <= queries[i].r && queries[i].d <= queries[i].u);\n      int d = get_y(queries[i].d);\n\
    \      int u = get_y(queries[i].u);\n      events.push_back({queries[i].l, d,\
    \ u, i, -1});\n      events.push_back({queries[i].r, d, u, i, 1});\n    }\n\n\
    \    std::sort(events.begin(), events.end());\n    std::sort(points.begin(), points.end(),\
    \ [](const Point& a, const Point& b) {\n      return a.x < b.x;\n    });\n\n \
    \   fenwick_tree<W> ft(ys.size());\n    int pi = 0;\n    for (auto& e : events)\
    \ {\n      while (pi < n && points[pi].x < e.x) {\n        ft.add(get_y(points[pi].y),\
    \ points[pi].w);\n        pi++;\n      }\n      res[e.id] += (W)e.type * ft.sum(e.d,\
    \ e.u);\n    }\n\n    return res;\n  }\n\nprivate:\n  std::vector<Point> points;\n\
    \  std::vector<Query> queries;\n};\n\n#endif // HARUILIB_STRUCTURE_OFFLINE_2DSUM_HPP\n"
  dependsOn:
  - structure/fenwick_tree.hpp
  isVerificationFile: false
  path: structure/offline_2dsum.hpp
  requiredBy: []
  timestamp: '2026-05-10 19:38:55+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/verify/structure/yosupo-rectangle-sum.test.cpp
documentation_of: structure/offline_2dsum.hpp
layout: document
title: Offline 2D Sum (Rectangle Sum)
---

2次元平面上の点に重みを加え、長方形領域内の重みの総和を求めるクエリをオフラインで処理します。

## コンストラクタ

```
offline_2dsum<T, W>()
```
T: 座標の型, W: 重みの型

## add_point

```
void add_point(T x, T y, W w)
```
点 $(x, y)$ に重み $w$ を追加する。

### 計算量
- $O(1)$

## add_query

```
void add_query(T l, T r, T d, T u)
```
領域 $[l, r) \times [d, u)$ の重みの総和を求めるクエリを追加する。
つまり、$l \le x < r, d \le y < u$ を満たす点の重みの総和を求める。

### 計算量
- $O(1)$

## solve

```
std::vector<W> solve()
```
追加されたすべてのクエリに対する解答を計算し、追加された順に返す。

### 計算量
点の個数を $N$、クエリの個数を $Q$ とすると
- $O(N \log N + Q \log Q + (N + Q) \log N)$