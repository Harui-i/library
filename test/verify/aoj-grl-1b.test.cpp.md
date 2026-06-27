---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/bellmanford.hpp
    title: "Bellmanford(\u30D9\u30EB\u30DE\u30F3\u30D5\u30A9\u30FC\u30C9\u6CD5)"
  - icon: ':heavy_check_mark:'
    path: graph/graph_template.hpp
    title: graph/graph_template.hpp
  - icon: ':question:'
    path: template/template.hpp
    title: template/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_B
  bundledCode: "#line 1 \"test/verify/aoj-grl-1b.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_B\"\
    \n#line 1 \"template/template.hpp\"\n#include <iostream>\n#include <cassert>\n\
    using namespace std;\nusing ll = long long;\ntemplate<class T> inline bool chmax(T&\
    \ a, const T& b) {if (a<b) {a=b; return true;} return false;}\ntemplate<class\
    \ T> inline bool chmin(T& a, const T& b) {if (b<a) {a=b; return true;} return\
    \ false;}\nconst int INTINF = 1000001000;\nconst int INTMAX = 2147483647;\nconst\
    \ ll LLMAX = 9223372036854775807;\nconst ll LLINF = 1000000000000000000;\n#line\
    \ 3 \"test/verify/aoj-grl-1b.test.cpp\"\n#include <vector>\n\n#line 1 \"graph/bellmanford.hpp\"\
    \n\n\n\n#line 5 \"graph/bellmanford.hpp\"\n#include <queue>\n#line 7 \"graph/bellmanford.hpp\"\
    \n#include <limits>\n\n#line 1 \"graph/graph_template.hpp\"\n\n\n\n#line 5 \"\
    graph/graph_template.hpp\"\n\ntemplate <typename T>\nstruct Edge {\n  int from;\
    \ int to;\n  T cost;\n\n  // default constructor\n  Edge () : from(-1), to(-1),\
    \ cost(T(0)) {}\n\n  Edge(int _from, int _to, T _cost) : from(_from), to(_to),\
    \ cost(_cost) {}\n\n  // unweighted\n  Edge(int _from, int _to) : from(_from),\
    \ to(_to), cost(T(1)) {}\n\n  bool operator==(const Edge& rhs) const {\n    return\
    \ from == rhs.from && to == rhs.to && cost == rhs.cost;\n  }\n\n  bool operator<(const\
    \ Edge& rhs) const {\n    return cost < rhs.cost;\n  }\n  \n  bool operator>(const\
    \ Edge& rhs) const {\n    return cost > rhs.cost;\n  }\n\n};\n\n\ntemplate <typename\
    \ T>\nstruct Graph : std::vector<std::vector<Edge<T>>> {\n\n  using std::vector<std::vector<Edge<T>>>::vector;\
    \ // inherit constructors\n\n  void add_edge(int i, Edge<T> e) {\n    (*this)[i].push_back(e);\n\
    \  }\n\n  void add_edge(Edge<T> e) {\n    (*this)[e.from].push_back(e);\n  }\n\
    \n  // weighted\n  void add_edge(int _from, int _to, T _cost) {\n    (*this)[_from].push_back(Edge(_from,\
    \ _to, _cost));\n  }\n\n  // unweighted\n  void add_edge(int _from, int _to) {\n\
    \    (*this)[_from].push_back(Edge(_from, _to, T(1)));\n  }\n\n};\n\n\n#line 10\
    \ \"graph/bellmanford.hpp\"\n\n// \u5B8C\u5168\u306B\u30D1\u30AF\u30EA\u307E\u3057\
    \u305F\n// https://ei1333.github.io/library/graph/shortest-path/bellman-ford.hpp\n\
    template <typename T> \nstd::vector<T> bellman_ford(const std::vector<Edge<T>>&\
    \ edges, int N, int start) {\n  assert(0 <= start && start < N);\n\n  const int\
    \ M = int(edges.size());\n  constexpr T PLINF = std::numeric_limits<T>::max();\n\
    \  constexpr T MNINF = std::numeric_limits<T>::min();\n\n  std::vector<T> dist(N,\
    \ PLINF);\n  dist[start] = T(0);\n\n  for (int i=0; i<N-1; i++) {\n    for (int\
    \ j=0; j<M; j++) {\n      Edge e = edges[j];\n      if (dist[e.from] >= PLINF)\
    \ continue;\n\n      if (dist[e.to] > dist[e.from] + e.cost) {\n        dist[e.to]\
    \ = dist[e.from] + e.cost;\n      }\n    }\n  }\n\n  std::vector<bool> negative(N,\
    \ false);\n\n  for (int i=0; i<N; i++) {\n    for (int j=0; j<M; j++) {\n    \
    \  Edge e = edges[j];\n\n      if (dist[e.from] >= PLINF) continue;\n      if\
    \ (dist[e.to] > dist[e.from] + e.cost) {\n        dist[e.to] = dist[e.from] +\
    \ e.cost;\n        negative[e.to] = true;\n      }\n\n      if (negative[e.from])\
    \ negative[e.to] = true;\n    }\n  }\n\n  for (int i=0; i<N; i++) if (negative[i])\
    \ dist[i] = MNINF;\n\n  return dist;\n}\n\n\n#line 6 \"test/verify/aoj-grl-1b.test.cpp\"\
    \n\nint main() {\n  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);\n  int V,E,r;\
    \ cin >> V >> E >> r;\n  vector<Edge<ll>>edges;\n  for (int i=0; i<E; i++) {\n\
    \    int s,t; ll d;\n    cin >> s >> t >> d;\n    edges.emplace_back(s,t,d);\n\
    \  }\n\n  vector<ll> ans = bellman_ford(edges,V,r);\n  for (int i=0; i<V; i++)\
    \ if (ans[i] < -LLINF) {\n    cout << \"NEGATIVE CYCLE\\n\";\n    return 0;\n\
    \  }\n\n  for (int i=0; i<V; i++) {\n    if (ans[i] >= LLINF) cout << \"INF\\\
    n\";\n    else cout << ans[i] << \"\\n\";\n  }\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_B\"\
    \n#include \"template/template.hpp\"\n#include <vector>\n\n#include \"graph/bellmanford.hpp\"\
    \n\nint main() {\n  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);\n  int V,E,r;\
    \ cin >> V >> E >> r;\n  vector<Edge<ll>>edges;\n  for (int i=0; i<E; i++) {\n\
    \    int s,t; ll d;\n    cin >> s >> t >> d;\n    edges.emplace_back(s,t,d);\n\
    \  }\n\n  vector<ll> ans = bellman_ford(edges,V,r);\n  for (int i=0; i<V; i++)\
    \ if (ans[i] < -LLINF) {\n    cout << \"NEGATIVE CYCLE\\n\";\n    return 0;\n\
    \  }\n\n  for (int i=0; i<V; i++) {\n    if (ans[i] >= LLINF) cout << \"INF\\\
    n\";\n    else cout << ans[i] << \"\\n\";\n  }\n  return 0;\n}\n"
  dependsOn:
  - template/template.hpp
  - graph/bellmanford.hpp
  - graph/graph_template.hpp
  isVerificationFile: true
  path: test/verify/aoj-grl-1b.test.cpp
  requiredBy: []
  timestamp: '2024-09-07 20:55:28+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/verify/aoj-grl-1b.test.cpp
layout: document
redirect_from:
- /verify/test/verify/aoj-grl-1b.test.cpp
- /verify/test/verify/aoj-grl-1b.test.cpp.html
title: test/verify/aoj-grl-1b.test.cpp
---
