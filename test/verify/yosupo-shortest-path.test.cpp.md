---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/dijkstra.hpp
    title: graph/dijkstra.hpp
  - icon: ':heavy_check_mark:'
    path: graph/graph_template.hpp
    title: graph/graph_template.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/shortest_path
    links:
    - https://judge.yosupo.jp/problem/shortest_path
  bundledCode: "#line 1 \"test/verify/yosupo-shortest-path.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/shortest_path\" \n\n#line 1 \"template/template.hpp\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\ntypedef long long ll;\ntypedef\
    \ unsigned int uint;\ntemplate<class T> inline bool chmax(T& a, const T& b) {if\
    \ (a<b) {a=b; return true;} return false;}\ntemplate<class T> inline bool chmin(T&\
    \ a, const T& b) {if (b<a) {a=b; return true;} return false;}\nconst int INTINF\
    \ = 1000001000;\nconst int INTMAX = 2147483647;\nconst ll LLMAX = 9223372036854775807;\n\
    const ll LLINF = 1000000000000000000;\n#line 3 \"graph/graph_template.hpp\"\n\
    template <typename T>\nstruct Edge {\n  int from; int to;\n  T cost;\n\n  Edge(int\
    \ _from, int _to, T _cost) : from(_from), to(_to), cost(_cost) {}\n\n  // unweighted\n\
    \  Edge(int _from, int _to) : from(_from), to(_to), cost(T(1)) {}\n\n};\n\n\n\
    template <typename T>\nstruct Graph : vector<vector<Edge<T>>> {\n\n  using vector<vector<Edge<T>>>::vector;\
    \ // inherit constructors\n\n  void add_edge(int i, Edge<T> e) {\n    (*this)[i].push_back(e);\n\
    \  }\n\n  // weighted\n  void add_edge(int _from, int _to, T _cost) {\n    (*this)[_from].push_back(Edge(_from,\
    \ _to, _cost));\n  }\n\n  // unweighted\n  void add_edge(int _from, int _to) {\n\
    \    (*this)[_from].push_back(Edge(_from, _to, T(1)));\n  }\n\n};\n#line 2 \"\
    graph/dijkstra.hpp\"\n\n#line 4 \"graph/dijkstra.hpp\"\n\ntemplate <typename T>\n\
    std::vector<T> dijkstra(const Graph<T>& graph, int start) {\n  int N = (int)graph.size();\n\
    \  vector<T>dist(N, T(-1));\n  using P = pair<T, int>;\n\n  priority_queue<P,\
    \ vector<P>, greater<P>>que;\n\n  que.push(make_pair(T(0), start));\n  dist[start]\
    \ = T(0);\n\n  while (!que.empty()) {\n    P front = que.top(); que.pop();\n\n\
    \    if (dist[front.second] < front.first) continue;\n\n    for (Edge ed : graph[front.second])\
    \ {\n\n      if (dist[ed.to] == T(-1) || dist[ed.to] > front.first + ed.cost)\
    \ {\n        dist[ed.to] = front.first + ed.cost;\n        que.emplace(dist[ed.to],\
    \ ed.to);\n      }\n    }\n  }\n\n  return dist;\n}\n\ntemplate <typename T>\n\
    pair<vector<T>, vector<int>> dijkstra_path(const Graph<T>& graph, int start) {\n\
    \  int N = (int)graph.size();\n\n  using P = pair<T, int>;\n  vector<T>dist(N,\
    \ T(-1));\n  vector<int>prev(N, -1);\n\n  priority_queue<P, vector<P>, greater<P>>que;\n\
    \  que.push(make_pair(T(0), start));\n  dist[start] = T(0);\n\n  while (!que.empty())\
    \ {\n    P front = que.top(); que.pop();\n\n    if (dist[front.second] < front.first)\
    \ continue;\n\n    for (Edge ed : graph[front.second]) {\n      if (dist[ed.to]\
    \ == T(-1) || dist[ed.to] > front.first + ed.cost) {\n        dist[ed.to] = front.first\
    \ + ed.cost;\n        prev[ed.to] = front.second;\n        que.emplace(dist[ed.to],\
    \ ed.to);\n      }\n    }\n  }\n\n  return make_pair(dist, prev);\n}\n#line 6\
    \ \"test/verify/yosupo-shortest-path.test.cpp\"\n\nint main() {\n  ios::sync_with_stdio(0);\
    \ cin.tie(0); cout.tie(0);\n  int N, M, s, t; cin >> N >> M >> s >> t;\n\n  Graph<ll>\
    \ gr(N);\n  for(int i=0; i<M; i++) {\n    ll a, b, c;\n    cin >> a >> b >> c;\n\
    \    gr.add_edge(a,b,c);\n  }\n\n  vector<ll>dist; vector<int>prev;\n\n   auto\
    \ pr = dijkstra_path(gr, s);\n   dist = pr.first; prev = pr.second;\n\n  if (dist[t]\
    \ == -1) {\n    cout << -1 << \"\\n\";\n  }\n  else {\n    ll X = dist[t];\n \
    \   int Y;\n    vector<int> path;\n    {\n      int now = t;\n      while (now\
    \ != -1) {\n        path.push_back(now);\n        now = prev[now];\n      }\n\
    \      Y = path.size();\n    }\n\n    reverse(path.begin(), path.end());\n   \
    \ cout << X << \" \" << Y - 1 << \"\\n\";\n    for(int i=0; i<Y-1; i++) {\n  \
    \    cout << path[i] << \" \" << path[i+1] << \"\\n\";\n    }\n  }\n\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/shortest_path\" \n\n#include\
    \ \"template/template.hpp\"\n#include \"graph/graph_template.hpp\"\n#include \"\
    graph/dijkstra.hpp\"\n\nint main() {\n  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);\n\
    \  int N, M, s, t; cin >> N >> M >> s >> t;\n\n  Graph<ll> gr(N);\n  for(int i=0;\
    \ i<M; i++) {\n    ll a, b, c;\n    cin >> a >> b >> c;\n    gr.add_edge(a,b,c);\n\
    \  }\n\n  vector<ll>dist; vector<int>prev;\n\n   auto pr = dijkstra_path(gr, s);\n\
    \   dist = pr.first; prev = pr.second;\n\n  if (dist[t] == -1) {\n    cout <<\
    \ -1 << \"\\n\";\n  }\n  else {\n    ll X = dist[t];\n    int Y;\n    vector<int>\
    \ path;\n    {\n      int now = t;\n      while (now != -1) {\n        path.push_back(now);\n\
    \        now = prev[now];\n      }\n      Y = path.size();\n    }\n\n    reverse(path.begin(),\
    \ path.end());\n    cout << X << \" \" << Y - 1 << \"\\n\";\n    for(int i=0;\
    \ i<Y-1; i++) {\n      cout << path[i] << \" \" << path[i+1] << \"\\n\";\n   \
    \ }\n  }\n\n}\n"
  dependsOn:
  - template/template.hpp
  - graph/graph_template.hpp
  - graph/dijkstra.hpp
  isVerificationFile: true
  path: test/verify/yosupo-shortest-path.test.cpp
  requiredBy: []
  timestamp: '2024-06-14 18:26:48+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/verify/yosupo-shortest-path.test.cpp
layout: document
redirect_from:
- /verify/test/verify/yosupo-shortest-path.test.cpp
- /verify/test/verify/yosupo-shortest-path.test.cpp.html
title: test/verify/yosupo-shortest-path.test.cpp
---
