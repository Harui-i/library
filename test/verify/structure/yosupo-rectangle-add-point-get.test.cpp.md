---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: structure/rectangle_apply_point_get.hpp
    title: Rectangle Apply Point Get
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
    PROBLEM: https://judge.yosupo.jp/problem/rectangle_add_point_get
    links:
    - https://judge.yosupo.jp/problem/rectangle_add_point_get
  bundledCode: "#line 1 \"test/verify/structure/yosupo-rectangle-add-point-get.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/rectangle_add_point_get\"\n\
    #line 1 \"template/template.hpp\"\n#include <iostream>\n#include <cassert>\nusing\
    \ namespace std;\nusing ll = long long;\ntemplate<class T> inline bool chmax(T&\
    \ a, const T& b) {if (a<b) {a=b; return true;} return false;}\ntemplate<class\
    \ T> inline bool chmin(T& a, const T& b) {if (b<a) {a=b; return true;} return\
    \ false;}\nconst int INTINF = 1000001000;\nconst int INTMAX = 2147483647;\nconst\
    \ ll LLMAX = 9223372036854775807;\nconst ll LLINF = 1000000000000000000;\n#line\
    \ 1 \"structure/rectangle_apply_point_get.hpp\"\n\n\n\n#line 5 \"structure/rectangle_apply_point_get.hpp\"\
    \n#include <vector>\n\ntemplate <class F, F (*composition)(F, F), F (*id)(), class\
    \ T = int>\nstruct rectangle_apply_point_get {\n  rectangle_apply_point_get(T\
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
    \ ys;\n};\n\n\n#line 4 \"test/verify/structure/yosupo-rectangle-add-point-get.test.cpp\"\
    \n\n#include <algorithm>\n#line 7 \"test/verify/structure/yosupo-rectangle-add-point-get.test.cpp\"\
    \n\nll composition(ll f, ll g) {\n  return f + g;\n}\n\nll id() {\n  return 0;\n\
    }\n\nstruct Rect {\n  int l, d, r, u;\n  ll w;\n};\n\nstruct Query {\n  int type;\n\
    \  Rect rect;\n  int x, y;\n};\n\nint main() {\n  ios::sync_with_stdio(0); cin.tie(0);\
    \ cout.tie(0);\n\n  int N, Q; cin >> N >> Q;\n  vector<Rect> rects(N);\n  for\
    \ (int i=0; i<N; i++) {\n    cin >> rects[i].l >> rects[i].d >> rects[i].r >>\
    \ rects[i].u >> rects[i].w;\n  }\n\n  vector<Query> qs(Q);\n  vector<int> xs,\
    \ ys;\n  for (int q=0; q<Q; q++) {\n    cin >> qs[q].type;\n    if (qs[q].type\
    \ == 0) {\n      cin >> qs[q].rect.l >> qs[q].rect.d >> qs[q].rect.r >> qs[q].rect.u\
    \ >> qs[q].rect.w;\n    }\n    else {\n      cin >> qs[q].x >> qs[q].y;\n    \
    \  xs.push_back(qs[q].x);\n      ys.push_back(qs[q].y);\n    }\n  }\n\n  if (xs.empty())\
    \ return 0;\n\n  sort(xs.begin(), xs.end());\n  xs.erase(unique(xs.begin(), xs.end()),\
    \ xs.end());\n  sort(ys.begin(), ys.end());\n  ys.erase(unique(ys.begin(), ys.end()),\
    \ ys.end());\n\n  auto get_x = [&](int x) {\n    return lower_bound(xs.begin(),\
    \ xs.end(), x) - xs.begin();\n  };\n  auto get_y = [&](int y) {\n    return lower_bound(ys.begin(),\
    \ ys.end(), y) - ys.begin();\n  };\n  auto apply = [&](rectangle_apply_point_get<ll,\
    \ composition, id>& g, const Rect& rect) {\n    int l = get_x(rect.l);\n    int\
    \ r = get_x(rect.r);\n    int d = get_y(rect.d);\n    int u = get_y(rect.u);\n\
    \    g.apply(l, r, d, u, rect.w);\n  };\n\n  rectangle_apply_point_get<ll, composition,\
    \ id> g(0, (int)xs.size(), 0, (int)ys.size());\n  for (auto& rect : rects) apply(g,\
    \ rect);\n\n  for (auto& q : qs) {\n    if (q.type == 0) {\n      apply(g, q.rect);\n\
    \    }\n    else {\n      cout << g.get(get_x(q.x), get_y(q.y)) << \"\\n\";\n\
    \    }\n  }\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/rectangle_add_point_get\"\
    \n#include \"template/template.hpp\"\n#include \"structure/rectangle_apply_point_get.hpp\"\
    \n\n#include <algorithm>\n#include <vector>\n\nll composition(ll f, ll g) {\n\
    \  return f + g;\n}\n\nll id() {\n  return 0;\n}\n\nstruct Rect {\n  int l, d,\
    \ r, u;\n  ll w;\n};\n\nstruct Query {\n  int type;\n  Rect rect;\n  int x, y;\n\
    };\n\nint main() {\n  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);\n\n  int\
    \ N, Q; cin >> N >> Q;\n  vector<Rect> rects(N);\n  for (int i=0; i<N; i++) {\n\
    \    cin >> rects[i].l >> rects[i].d >> rects[i].r >> rects[i].u >> rects[i].w;\n\
    \  }\n\n  vector<Query> qs(Q);\n  vector<int> xs, ys;\n  for (int q=0; q<Q; q++)\
    \ {\n    cin >> qs[q].type;\n    if (qs[q].type == 0) {\n      cin >> qs[q].rect.l\
    \ >> qs[q].rect.d >> qs[q].rect.r >> qs[q].rect.u >> qs[q].rect.w;\n    }\n  \
    \  else {\n      cin >> qs[q].x >> qs[q].y;\n      xs.push_back(qs[q].x);\n  \
    \    ys.push_back(qs[q].y);\n    }\n  }\n\n  if (xs.empty()) return 0;\n\n  sort(xs.begin(),\
    \ xs.end());\n  xs.erase(unique(xs.begin(), xs.end()), xs.end());\n  sort(ys.begin(),\
    \ ys.end());\n  ys.erase(unique(ys.begin(), ys.end()), ys.end());\n\n  auto get_x\
    \ = [&](int x) {\n    return lower_bound(xs.begin(), xs.end(), x) - xs.begin();\n\
    \  };\n  auto get_y = [&](int y) {\n    return lower_bound(ys.begin(), ys.end(),\
    \ y) - ys.begin();\n  };\n  auto apply = [&](rectangle_apply_point_get<ll, composition,\
    \ id>& g, const Rect& rect) {\n    int l = get_x(rect.l);\n    int r = get_x(rect.r);\n\
    \    int d = get_y(rect.d);\n    int u = get_y(rect.u);\n    g.apply(l, r, d,\
    \ u, rect.w);\n  };\n\n  rectangle_apply_point_get<ll, composition, id> g(0, (int)xs.size(),\
    \ 0, (int)ys.size());\n  for (auto& rect : rects) apply(g, rect);\n\n  for (auto&\
    \ q : qs) {\n    if (q.type == 0) {\n      apply(g, q.rect);\n    }\n    else\
    \ {\n      cout << g.get(get_x(q.x), get_y(q.y)) << \"\\n\";\n    }\n  }\n\n \
    \ return 0;\n}\n"
  dependsOn:
  - template/template.hpp
  - structure/rectangle_apply_point_get.hpp
  isVerificationFile: true
  path: test/verify/structure/yosupo-rectangle-add-point-get.test.cpp
  requiredBy: []
  timestamp: '2026-06-27 23:23:51+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/verify/structure/yosupo-rectangle-add-point-get.test.cpp
layout: document
redirect_from:
- /verify/test/verify/structure/yosupo-rectangle-add-point-get.test.cpp
- /verify/test/verify/structure/yosupo-rectangle-add-point-get.test.cpp.html
title: test/verify/structure/yosupo-rectangle-add-point-get.test.cpp
---
