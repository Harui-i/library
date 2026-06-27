---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/diameter.hpp
    title: "Tree Diameter(\u6728\u306E\u76F4\u5F84)"
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
    PROBLEM: https://judge.yosupo.jp/problem/tree_diameter
    links:
    - https://judge.yosupo.jp/problem/tree_diameter
  bundledCode: "#line 1 \"test/verify/yosupo-tree-diameter.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/tree_diameter\"\n\n#line 1 \"template/template.hpp\"\
    \n#include <iostream>\n#include <cassert>\nusing namespace std;\nusing ll = long\
    \ long;\ntemplate<class T> inline bool chmax(T& a, const T& b) {if (a<b) {a=b;\
    \ return true;} return false;}\ntemplate<class T> inline bool chmin(T& a, const\
    \ T& b) {if (b<a) {a=b; return true;} return false;}\nconst int INTINF = 1000001000;\n\
    const int INTMAX = 2147483647;\nconst ll LLMAX = 9223372036854775807;\nconst ll\
    \ LLINF = 1000000000000000000;\n#line 1 \"graph/graph_template.hpp\"\n\n\n\n#include\
    \ <vector>\n\ntemplate <typename T>\nstruct Edge {\n  int from; int to;\n  T cost;\n\
    \n  // default constructor\n  Edge () : from(-1), to(-1), cost(T(0)) {}\n\n  Edge(int\
    \ _from, int _to, T _cost) : from(_from), to(_to), cost(_cost) {}\n\n  // unweighted\n\
    \  Edge(int _from, int _to) : from(_from), to(_to), cost(T(1)) {}\n\n  bool operator==(const\
    \ Edge& rhs) const {\n    return from == rhs.from && to == rhs.to && cost == rhs.cost;\n\
    \  }\n\n  bool operator<(const Edge& rhs) const {\n    return cost < rhs.cost;\n\
    \  }\n  \n  bool operator>(const Edge& rhs) const {\n    return cost > rhs.cost;\n\
    \  }\n\n};\n\n\ntemplate <typename T>\nstruct Graph : std::vector<std::vector<Edge<T>>>\
    \ {\n\n  using std::vector<std::vector<Edge<T>>>::vector; // inherit constructors\n\
    \n  void add_edge(int i, Edge<T> e) {\n    (*this)[i].push_back(e);\n  }\n\n \
    \ void add_edge(Edge<T> e) {\n    (*this)[e.from].push_back(e);\n  }\n\n  // weighted\n\
    \  void add_edge(int _from, int _to, T _cost) {\n    (*this)[_from].push_back(Edge(_from,\
    \ _to, _cost));\n  }\n\n  // unweighted\n  void add_edge(int _from, int _to) {\n\
    \    (*this)[_from].push_back(Edge(_from, _to, T(1)));\n  }\n\n};\n\n\n#line 1\
    \ \"graph/diameter.hpp\"\n\n\n\n\n#include <algorithm>\n#line 7 \"graph/diameter.hpp\"\
    \n#include <queue>\n#line 9 \"graph/diameter.hpp\"\n\nnamespace mylib {\n\n  using\
    \ std::vector;\n  using std::pair;\n  using std::queue;\n\n  template <typename\
    \ T>\n  pair<vector<int>, T> diameter_path(const Graph<T>& graph) {\n    int N\
    \ = (int)graph.size();\n\n    // first sweep\n    pair<T, int> farest1 = make_pair(T(0),\
    \ 0);\n    {\n      vector<T> dist(N, T(-1));\n      dist[0] = T(0);\n\n     \
    \ queue<int> que;\n      que.push(0);\n      while (!que.empty()) {\n        int\
    \ front = que.front(); que.pop();\n\n        for (Edge e: graph[front]) {\n  \
    \        if (dist[e.to] == T(-1)) {\n            dist[e.to] = dist[front] + e.cost;\n\
    \            que.push(e.to);\n            if (farest1.first == -1 || farest1.first\
    \ < dist[e.to]) {\n              farest1 = make_pair(dist[e.to], e.to);\n    \
    \        }\n          }\n        }\n      }\n    }\n\n\n    pair<T, int> farest2\
    \ = make_pair(T(0), farest1.second);\n    // second sweep\n    vector<int> prev(N,\
    \ -1);\n    {\n      int start = farest1.second;\n      vector<T> dist(N, T(-1));\n\
    \      dist[start] = T(0);\n\n      queue<int> que;\n      que.push(start);\n\n\
    \      while (!que.empty()) {\n        int front = que.front(); que.pop();\n\n\
    \        for (Edge e: graph[front]) {\n          if (dist[e.to] == T(-1)) {\n\
    \            dist[e.to] = dist[front] + e.cost;\n            prev[e.to] = front;\n\
    \            que.push(e.to);\n          }\n\n          if (farest2.second == -1\
    \ || farest2.first < dist[e.to]) {\n            farest2 = make_pair(dist[e.to],\
    \ e.to);\n          }\n        }\n      }\n    }\n\n    vector<int> diameter_path;\n\
    \    {\n      int now = farest2.second;\n      while (now != -1) {\n        diameter_path.push_back(now);\n\
    \        now = prev[now];\n      }\n\n      reverse(diameter_path.begin(), diameter_path.end());\n\
    \    }\n\n    return make_pair(diameter_path, farest2.first);\n  }\n\n} // namespace\
    \ mylib\n\n\n#line 6 \"test/verify/yosupo-tree-diameter.test.cpp\"\n\nint main()\
    \ {\n  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);\n\n  int N; cin >> N;\n\
    \  Graph<ll>graph(N);\n  for(int i=0; i<N-1; i++) {\n    ll a, b, c; cin >> a\
    \ >> b >> c;\n    graph.add_edge(a,b,c);\n    graph.add_edge(b,a,c);\n  }\n\n\
    \  pair<vector<int>, ll> pr = mylib::diameter_path<ll>(graph);\n\n  cout << pr.second\
    \ << \" \" << pr.first.size() << \"\\n\";\n  for(int i=0; i<(int)pr.first.size();\
    \ i++) {\n    cout << pr.first[i];\n    if (i < N-1) cout << \" \";\n    else\
    \ cout << \"\\n\";\n  }\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/tree_diameter\"\n\n#include\
    \ \"template/template.hpp\"\n#include \"graph/graph_template.hpp\"\n#include \"\
    graph/diameter.hpp\"\n\nint main() {\n  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);\n\
    \n  int N; cin >> N;\n  Graph<ll>graph(N);\n  for(int i=0; i<N-1; i++) {\n   \
    \ ll a, b, c; cin >> a >> b >> c;\n    graph.add_edge(a,b,c);\n    graph.add_edge(b,a,c);\n\
    \  }\n\n  pair<vector<int>, ll> pr = mylib::diameter_path<ll>(graph);\n\n  cout\
    \ << pr.second << \" \" << pr.first.size() << \"\\n\";\n  for(int i=0; i<(int)pr.first.size();\
    \ i++) {\n    cout << pr.first[i];\n    if (i < N-1) cout << \" \";\n    else\
    \ cout << \"\\n\";\n  }\n\n  return 0;\n}\n"
  dependsOn:
  - template/template.hpp
  - graph/graph_template.hpp
  - graph/diameter.hpp
  isVerificationFile: true
  path: test/verify/yosupo-tree-diameter.test.cpp
  requiredBy: []
  timestamp: '2025-03-23 00:55:59+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/verify/yosupo-tree-diameter.test.cpp
layout: document
redirect_from:
- /verify/test/verify/yosupo-tree-diameter.test.cpp
- /verify/test/verify/yosupo-tree-diameter.test.cpp.html
title: test/verify/yosupo-tree-diameter.test.cpp
---
