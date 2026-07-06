---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/general_weighted_matching.hpp
    title: General Weighted Matching
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
    PROBLEM: https://judge.yosupo.jp/problem/general_weighted_matching
    links:
    - https://judge.yosupo.jp/problem/general_weighted_matching
  bundledCode: "#line 1 \"test/verify/yosupo-general-weighted-matching.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/general_weighted_matching\"\n\
    \n#line 1 \"template/template.hpp\"\n#include <iostream>\n#include <cassert>\n\
    using namespace std;\nusing ll = long long;\ntemplate<class T> inline bool chmax(T&\
    \ a, const T& b) {if (a<b) {a=b; return true;} return false;}\ntemplate<class\
    \ T> inline bool chmin(T& a, const T& b) {if (b<a) {a=b; return true;} return\
    \ false;}\nconst int INTINF = 1000001000;\nconst int INTMAX = 2147483647;\nconst\
    \ ll LLMAX = 9223372036854775807;\nconst ll LLINF = 1000000000000000000;\n#line\
    \ 1 \"graph/general_weighted_matching.hpp\"\n\n\n\n#include <algorithm>\n#include\
    \ <functional>\n#include <limits>\n#include <queue>\n#include <utility>\n#include\
    \ <vector>\n\nnamespace mylib {\n\nstruct GeneralWeightedMatching {\n  int n;\n\
    \  std::vector<std::vector<long long>> w;\n\n  explicit GeneralWeightedMatching(int\
    \ n_) : n(n_), w(n_, std::vector<long long>(n_, 0)) {}\n\n  void add_edge(int\
    \ u, int v, long long cost) {\n    if (u == v) return;\n    if (w[u][v] < cost)\
    \ w[u][v] = w[v][u] = cost;\n  }\n\n  std::pair<long long, std::vector<int>> solve()\
    \ const {\n    if (n == 0) return {0, {}};\n\n    struct Edge {\n      int u,\
    \ v;\n      long long w;\n      Edge(int u_ = 0, int v_ = 0, long long w_ = 0)\
    \ : u(u_), v(v_), w(w_) {}\n    };\n\n    const int N = n;\n    const int max_nodes\
    \ = 2 * N;\n    int nodes = N;\n\n    std::vector<std::vector<Edge>> g(max_nodes\
    \ + 1, std::vector<Edge>(max_nodes + 1));\n    for (int i = 1; i <= max_nodes;\
    \ i++) {\n      for (int j = 1; j <= max_nodes; j++) {\n        g[i][j] = Edge(i,\
    \ j, 0);\n      }\n    }\n    for (int i = 1; i <= N; i++) {\n      for (int j\
    \ = 1; j <= N; j++) {\n        g[i][j].w = w[i - 1][j - 1];\n      }\n    }\n\n\
    \    std::vector<int> match(max_nodes + 1), slack(max_nodes + 1), st(max_nodes\
    \ + 1), parent(max_nodes + 1);\n    std::vector<int> state(max_nodes + 1), vis(max_nodes\
    \ + 1);\n    std::vector<long long> label(max_nodes + 1);\n    std::vector<std::vector<int>>\
    \ blossom_from(max_nodes + 1, std::vector<int>(N + 1));\n    std::vector<std::vector<int>>\
    \ blossom(max_nodes + 1);\n    std::queue<int> q;\n    int vis_timer = 0;\n\n\
    \    auto delta = [&](const Edge &e) {\n      return label[e.u] + label[e.v] -\
    \ e.w * 2;\n    };\n\n    auto update_slack = [&](int u, int x) {\n      if (!slack[x]\
    \ || delta(g[u][x]) < delta(g[slack[x]][x])) {\n        slack[x] = u;\n      }\n\
    \    };\n\n    auto set_slack = [&](int x) {\n      slack[x] = 0;\n      for (int\
    \ u = 1; u <= N; u++) {\n        if (g[u][x].w > 0 && st[u] != x && state[st[u]]\
    \ == 0) update_slack(u, x);\n      }\n    };\n\n    std::function<void(int)> q_push\
    \ = [&](int x) {\n      if (x <= N) {\n        q.push(x);\n      } else {\n  \
    \      for (int v : blossom[x]) q_push(v);\n      }\n    };\n\n    std::function<void(int,\
    \ int)> set_st = [&](int x, int b) {\n      st[x] = b;\n      if (x > N) {\n \
    \       for (int v : blossom[x]) set_st(v, b);\n      }\n    };\n\n    auto get_pr\
    \ = [&](int b, int xr) {\n      int pr = std::find(blossom[b].begin(), blossom[b].end(),\
    \ xr) - blossom[b].begin();\n      if (pr % 2 == 1) {\n        std::reverse(blossom[b].begin()\
    \ + 1, blossom[b].end());\n        return (int)blossom[b].size() - pr;\n     \
    \ }\n      return pr;\n    };\n\n    std::function<void(int, int)> set_match =\
    \ [&](int u, int v) {\n      match[u] = g[u][v].v;\n      if (u <= N) return;\n\
    \      int xr = blossom_from[u][g[u][v].u];\n      int pr = get_pr(u, xr);\n \
    \     for (int i = 0; i < pr; i++) {\n        set_match(blossom[u][i], blossom[u][i\
    \ ^ 1]);\n      }\n      set_match(xr, v);\n      std::rotate(blossom[u].begin(),\
    \ blossom[u].begin() + pr, blossom[u].end());\n    };\n\n    auto augment = [&](int\
    \ u, int v) {\n      while (true) {\n        int next = st[match[u]];\n      \
    \  set_match(u, v);\n        if (!next) return;\n        set_match(next, st[parent[next]]);\n\
    \        u = st[parent[next]];\n        v = next;\n      }\n    };\n\n    auto\
    \ lca = [&](int u, int v) {\n      ++vis_timer;\n      for (; u || v; std::swap(u,\
    \ v)) {\n        if (!u) continue;\n        if (vis[u] == vis_timer) return u;\n\
    \        vis[u] = vis_timer;\n        u = st[match[u]];\n        if (u) u = st[parent[u]];\n\
    \      }\n      return 0;\n    };\n\n    auto add_blossom = [&](int u, int l,\
    \ int v) {\n      int b = N + 1;\n      while (b <= nodes && st[b]) b++;\n   \
    \   if (b > nodes) nodes++;\n\n      label[b] = 0;\n      state[b] = 0;\n    \
    \  match[b] = match[l];\n      blossom[b].clear();\n      blossom[b].push_back(l);\n\
    \      for (int x = u, y; x != l; x = st[parent[y]]) {\n        blossom[b].push_back(x);\n\
    \        y = st[match[x]];\n        blossom[b].push_back(y);\n        q_push(y);\n\
    \      }\n      std::reverse(blossom[b].begin() + 1, blossom[b].end());\n    \
    \  for (int x = v, y; x != l; x = st[parent[y]]) {\n        blossom[b].push_back(x);\n\
    \        y = st[match[x]];\n        blossom[b].push_back(y);\n        q_push(y);\n\
    \      }\n      set_st(b, b);\n\n      for (int x = 1; x <= nodes; x++) {\n  \
    \      g[b][x] = Edge(b, x, 0);\n        g[x][b] = Edge(x, b, 0);\n      }\n \
    \     for (int x = 1; x <= N; x++) blossom_from[b][x] = 0;\n\n      for (int x\
    \ : blossom[b]) {\n        for (int y = 1; y <= nodes; y++) {\n          if (g[b][y].w\
    \ == 0 || delta(g[x][y]) < delta(g[b][y])) {\n            g[b][y] = g[x][y];\n\
    \            g[y][b] = g[y][x];\n          }\n        }\n        for (int y =\
    \ 1; y <= N; y++) {\n          if (blossom_from[x][y]) blossom_from[b][y] = x;\n\
    \        }\n      }\n      set_slack(b);\n    };\n\n    auto expand_blossom =\
    \ [&](int b) {\n      for (int x : blossom[b]) set_st(x, x);\n      int xr = blossom_from[b][g[b][parent[b]].u];\n\
    \      int pr = get_pr(b, xr);\n      for (int i = 0; i < pr; i += 2) {\n    \
    \    int xs = blossom[b][i], xns = blossom[b][i + 1];\n        parent[xs] = g[xns][xs].u;\n\
    \        state[xs] = 1;\n        state[xns] = 0;\n        slack[xs] = 0;\n   \
    \     set_slack(xns);\n        q_push(xns);\n      }\n      state[xr] = 1;\n \
    \     parent[xr] = parent[b];\n      for (int i = pr + 1; i < (int)blossom[b].size();\
    \ i++) {\n        int x = blossom[b][i];\n        state[x] = -1;\n        set_slack(x);\n\
    \      }\n      st[b] = 0;\n    };\n\n    auto on_found_edge = [&](const Edge\
    \ &e) {\n      int u = st[e.u], v = st[e.v];\n      if (state[v] == -1) {\n  \
    \      parent[v] = e.u;\n        state[v] = 1;\n        int next = st[match[v]];\n\
    \        slack[v] = slack[next] = 0;\n        state[next] = 0;\n        q_push(next);\n\
    \      } else if (state[v] == 0) {\n        int l = lca(u, v);\n        if (!l)\
    \ {\n          augment(u, v);\n          augment(v, u);\n          return true;\n\
    \        }\n        add_blossom(u, l, v);\n      }\n      return false;\n    };\n\
    \n    auto matching = [&]() {\n      std::fill(state.begin(), state.end(), -1);\n\
    \      std::fill(slack.begin(), slack.end(), 0);\n      q = std::queue<int>();\n\
    \      for (int x = 1; x <= nodes; x++) {\n        if (st[x] == x && !match[x])\
    \ {\n          parent[x] = 0;\n          state[x] = 0;\n          q_push(x);\n\
    \        }\n      }\n      if (q.empty()) return false;\n\n      while (true)\
    \ {\n        while (!q.empty()) {\n          int u = q.front();\n          q.pop();\n\
    \          if (state[st[u]] == 1) continue;\n          for (int v = 1; v <= N;\
    \ v++) {\n            if (g[u][v].w > 0 && st[u] != st[v]) {\n              if\
    \ (delta(g[u][v]) == 0) {\n                if (on_found_edge(g[u][v])) return\
    \ true;\n              } else {\n                update_slack(u, st[v]);\n   \
    \           }\n            }\n          }\n        }\n\n        long long d =\
    \ std::numeric_limits<long long>::max();\n        for (int u = 1; u <= N; u++)\
    \ {\n          if (state[st[u]] == 0) d = std::min(d, label[u]);\n        }\n\
    \        for (int b = N + 1; b <= nodes; b++) {\n          if (st[b] == b && state[b]\
    \ == 1) d = std::min(d, label[b] / 2);\n        }\n        for (int x = 1; x <=\
    \ nodes; x++) {\n          if (st[x] == x && slack[x]) {\n            if (state[x]\
    \ == -1) d = std::min(d, delta(g[slack[x]][x]));\n            else if (state[x]\
    \ == 0) d = std::min(d, delta(g[slack[x]][x]) / 2);\n          }\n        }\n\
    \        if (d == std::numeric_limits<long long>::max()) return false;\n\n   \
    \     for (int u = 1; u <= N; u++) {\n          if (state[st[u]] == 0) {\n   \
    \         if (label[u] == d) return false;\n            label[u] -= d;\n     \
    \     } else if (state[st[u]] == 1) {\n            label[u] += d;\n          }\n\
    \        }\n        for (int b = N + 1; b <= nodes; b++) {\n          if (st[b]\
    \ == b) {\n            if (state[b] == 0) label[b] += d * 2;\n            else\
    \ if (state[b] == 1) label[b] -= d * 2;\n          }\n        }\n\n        q =\
    \ std::queue<int>();\n        for (int x = 1; x <= nodes; x++) {\n          if\
    \ (st[x] == x && slack[x] && st[slack[x]] != x && delta(g[slack[x]][x]) == 0)\
    \ {\n            if (on_found_edge(g[slack[x]][x])) return true;\n          }\n\
    \        }\n        for (int b = N + 1; b <= nodes; b++) {\n          if (st[b]\
    \ == b && state[b] == 1 && label[b] == 0) expand_blossom(b);\n        }\n    \
    \  }\n    };\n\n    long long max_weight = 0;\n    for (int u = 1; u <= N; u++)\
    \ {\n      st[u] = u;\n      blossom[u].clear();\n      for (int v = 1; v <= N;\
    \ v++) {\n        blossom_from[u][v] = (u == v ? u : 0);\n        max_weight =\
    \ std::max(max_weight, g[u][v].w);\n      }\n    }\n    for (int u = 1; u <= N;\
    \ u++) label[u] = max_weight;\n\n    while (matching()) {}\n\n    std::vector<int>\
    \ mate(n, -1);\n    long long total = 0;\n    for (int i = 1; i <= N; i++) {\n\
    \      if (match[i] && match[i] <= N) mate[i - 1] = match[i] - 1;\n    }\n   \
    \ for (int i = 0; i < n; i++) {\n      if (mate[i] > i) total += w[i][mate[i]];\n\
    \    }\n    return {total, mate};\n  }\n};\n\n} // namespace mylib\n\n\n#line\
    \ 5 \"test/verify/yosupo-general-weighted-matching.test.cpp\"\n\nint main() {\n\
    \  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);\n\n  int N, M; cin >> N >>\
    \ M;\n  mylib::GeneralWeightedMatching wm(N);\n  for (int i = 0; i < M; i++) {\n\
    \    int u, v;\n    long long w;\n    cin >> u >> v >> w;\n    wm.add_edge(u,\
    \ v, w);\n  }\n\n  auto ans = wm.solve();\n  vector<pair<int, int>> edges;\n \
    \ for (int i = 0; i < N; i++) {\n    if (ans.second[i] != -1 && i < ans.second[i])\
    \ edges.emplace_back(i, ans.second[i]);\n  }\n\n  cout << edges.size() << \" \"\
    \ << ans.first << \"\\n\";\n  for (auto [u, v] : edges) {\n    cout << u << \"\
    \ \" << v << \"\\n\";\n  }\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/general_weighted_matching\"\
    \n\n#include \"template/template.hpp\"\n#include \"graph/general_weighted_matching.hpp\"\
    \n\nint main() {\n  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);\n\n  int\
    \ N, M; cin >> N >> M;\n  mylib::GeneralWeightedMatching wm(N);\n  for (int i\
    \ = 0; i < M; i++) {\n    int u, v;\n    long long w;\n    cin >> u >> v >> w;\n\
    \    wm.add_edge(u, v, w);\n  }\n\n  auto ans = wm.solve();\n  vector<pair<int,\
    \ int>> edges;\n  for (int i = 0; i < N; i++) {\n    if (ans.second[i] != -1 &&\
    \ i < ans.second[i]) edges.emplace_back(i, ans.second[i]);\n  }\n\n  cout << edges.size()\
    \ << \" \" << ans.first << \"\\n\";\n  for (auto [u, v] : edges) {\n    cout <<\
    \ u << \" \" << v << \"\\n\";\n  }\n  return 0;\n}\n"
  dependsOn:
  - template/template.hpp
  - graph/general_weighted_matching.hpp
  isVerificationFile: true
  path: test/verify/yosupo-general-weighted-matching.test.cpp
  requiredBy: []
  timestamp: '2026-05-10 20:38:40+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/verify/yosupo-general-weighted-matching.test.cpp
layout: document
redirect_from:
- /verify/test/verify/yosupo-general-weighted-matching.test.cpp
- /verify/test/verify/yosupo-general-weighted-matching.test.cpp.html
title: test/verify/yosupo-general-weighted-matching.test.cpp
---
