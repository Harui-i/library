---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: structure/fenwick_tree.hpp
    title: structure/fenwick_tree.hpp
  - icon: ':heavy_check_mark:'
    path: structure/offline_2dsum.hpp
    title: Offline 2D Sum (Rectangle Sum)
  - icon: ':heavy_check_mark:'
    path: template/template.hpp
    title: template/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/rectangle_sum
    links:
    - https://judge.yosupo.jp/problem/rectangle_sum
  bundledCode: "#line 1 \"test/verify/structure/yosupo-rectangle-sum.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/rectangle_sum\"\n#line 1 \"\
    template/template.hpp\"\n#include <iostream>\n#include <cassert>\nusing namespace\
    \ std;\nusing ll = long long;\ntemplate<class T> inline bool chmax(T& a, const\
    \ T& b) {if (a<b) {a=b; return true;} return false;}\ntemplate<class T> inline\
    \ bool chmin(T& a, const T& b) {if (b<a) {a=b; return true;} return false;}\n\
    const int INTINF = 1000001000;\nconst int INTMAX = 2147483647;\nconst ll LLMAX\
    \ = 9223372036854775807;\nconst ll LLINF = 1000000000000000000;\n#line 1 \"structure/offline_2dsum.hpp\"\
    \n\n\n\n#include <vector>\n#include <algorithm>\n#line 1 \"structure/fenwick_tree.hpp\"\
    \n\n\n\n#line 6 \"structure/fenwick_tree.hpp\"\n\ntemplate <class T> struct fenwick_tree\
    \ {\n  fenwick_tree(): _n(0) {}\n  explicit fenwick_tree(int n): _n(n), data(n)\
    \ {}\n\n  // point add\n  void add(int p, T x) {\n    assert(0 <= p && p < _n);\n\
    \    p++;\n    while (p <= _n) {\n      data[p-1] += T(x);\n      p += p & -p;\n\
    \    }\n  } \n\n  T sum(int l, int r) {\n    assert(0 <= l && l <= r && r <= _n);\n\
    \    return sum(r) - sum(l);\n  }\n\nprivate:\n  int _n;\n  std::vector<T> data;\n\
    \  T sum(int r) {\n    T ret(0);\n    while (r > 0) {\n      ret += data[r-1];\n\
    \      r -= r & -r;\n    }\n\n    return ret;\n  }\n};\n\n\n#line 7 \"structure/offline_2dsum.hpp\"\
    \n\ntemplate <class T, class W> struct offline_2dsum {\n  struct Point {\n   \
    \ T x, y;\n    W w;\n  };\n  struct Query {\n    T l, r, d, u;\n  };\n\n  void\
    \ add_point(T x, T y, W w) {\n    points.push_back({x, y, w});\n  }\n\n  void\
    \ add_query(T l, T r, T d, T u) {\n    queries.push_back({l, r, d, u});\n  }\n\
    \n  std::vector<W> solve() {\n    int n = points.size();\n    int q = queries.size();\n\
    \    std::vector<W> res(q, 0);\n\n    std::vector<T> ys;\n    ys.reserve(n);\n\
    \    for (auto& p : points) ys.push_back(p.y);\n    std::sort(ys.begin(), ys.end());\n\
    \    ys.erase(std::unique(ys.begin(), ys.end()), ys.end());\n\n    auto get_y\
    \ = [&](T y) {\n      return std::lower_bound(ys.begin(), ys.end(), y) - ys.begin();\n\
    \    };\n\n    struct Event {\n      T x;\n      int d, u;\n      int id;\n  \
    \    int type; // -1 for l, 1 for r\n      bool operator<(const Event& other)\
    \ const {\n        if (x != other.x) return x < other.x;\n        return type\
    \ < other.type;\n      }\n    };\n\n    std::vector<Event> events;\n    events.reserve(2\
    \ * q);\n    for (int i = 0; i < q; i++) {\n      int d = get_y(queries[i].d);\n\
    \      int u = get_y(queries[i].u);\n      events.push_back({queries[i].l, d,\
    \ u, i, -1});\n      events.push_back({queries[i].r, d, u, i, 1});\n    }\n\n\
    \    std::sort(events.begin(), events.end());\n    std::sort(points.begin(), points.end(),\
    \ [](const Point& a, const Point& b) {\n      return a.x < b.x;\n    });\n\n \
    \   fenwick_tree<W> ft(ys.size());\n    int pi = 0;\n    for (auto& e : events)\
    \ {\n      while (pi < n && points[pi].x < e.x) {\n        ft.add(get_y(points[pi].y),\
    \ points[pi].w);\n        pi++;\n      }\n      res[e.id] += (W)e.type * ft.sum(e.d,\
    \ e.u);\n    }\n\n    return res;\n  }\n\nprivate:\n  std::vector<Point> points;\n\
    \  std::vector<Query> queries;\n};\n\n\n#line 4 \"test/verify/structure/yosupo-rectangle-sum.test.cpp\"\
    \n\n#line 6 \"test/verify/structure/yosupo-rectangle-sum.test.cpp\"\n\nint main()\
    \ {\n  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);\n  int N, Q; cin >> N\
    \ >> Q;\n  offline_2dsum<int, ll> g;\n  for (int i=0; i<N; i++) {\n    int x,\
    \ y; cin >> x >> y;\n    ll w; cin >> w;\n    g.add_point(x, y, w);\n  }\n\n \
    \ for (int q=0; q<Q; q++) {\n    int l, d, r, u;\n    cin >> l >> d >> r >> u;\n\
    \    g.add_query(l, r, d, u);\n  }\n\n  auto ans = g.solve();\n  for (auto x :\
    \ ans) cout << x << \"\\n\";\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/rectangle_sum\"\n#include\
    \ \"template/template.hpp\"\n#include \"structure/offline_2dsum.hpp\"\n\n#include\
    \ <vector>\n\nint main() {\n  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);\n\
    \  int N, Q; cin >> N >> Q;\n  offline_2dsum<int, ll> g;\n  for (int i=0; i<N;\
    \ i++) {\n    int x, y; cin >> x >> y;\n    ll w; cin >> w;\n    g.add_point(x,\
    \ y, w);\n  }\n\n  for (int q=0; q<Q; q++) {\n    int l, d, r, u;\n    cin >>\
    \ l >> d >> r >> u;\n    g.add_query(l, r, d, u);\n  }\n\n  auto ans = g.solve();\n\
    \  for (auto x : ans) cout << x << \"\\n\";\n\n  return 0;\n}\n"
  dependsOn:
  - template/template.hpp
  - structure/offline_2dsum.hpp
  - structure/fenwick_tree.hpp
  isVerificationFile: true
  path: test/verify/structure/yosupo-rectangle-sum.test.cpp
  requiredBy: []
  timestamp: '2026-01-24 17:34:48+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/verify/structure/yosupo-rectangle-sum.test.cpp
layout: document
redirect_from:
- /verify/test/verify/structure/yosupo-rectangle-sum.test.cpp
- /verify/test/verify/structure/yosupo-rectangle-sum.test.cpp.html
title: test/verify/structure/yosupo-rectangle-sum.test.cpp
---
