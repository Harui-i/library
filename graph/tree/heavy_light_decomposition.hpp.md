---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/graph_template.hpp
    title: graph/graph_template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/verify/yosupo-vertex-add-path-sum.test.cpp
    title: test/verify/yosupo-vertex-add-path-sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/verify/yosupo-vertex-add-subtree-sum.test.cpp
    title: test/verify/yosupo-vertex-add-subtree-sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/verify/yosupo-vertex-set-path-composite.test.cpp
    title: test/verify/yosupo-vertex-set-path-composite.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://ngtkana.hatenablog.com/entry/2024/06/24/200138
  bundledCode: "#line 1 \"graph/tree/heavy_light_decomposition.hpp\"\n\n\n\n#include\
    \ <vector>\n#include <algorithm>\n#include <cassert>\n#include <utility>\n\n#line\
    \ 1 \"graph/graph_template.hpp\"\n\n\n\n#line 5 \"graph/graph_template.hpp\"\n\
    \ntemplate <typename T>\nstruct Edge {\n  int from; int to;\n  T cost;\n\n  Edge(int\
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
    \    (*this)[_from].push_back(Edge(_from, _to, T(1)));\n  }\n\n};\n\n\n#line 10\
    \ \"graph/tree/heavy_light_decomposition.hpp\"\n\n// cf : https://ngtkana.hatenablog.com/entry/2024/06/24/200138\n\
    struct Interval {\n  // top_id : interval \u306E\u3082\u3063\u3068\u3082\u6839\
    \u306B\u8FD1\u3044\u9802\u70B9\u306Eid\n  // bottom_id : interval \u306E\u3082\
    \u3063\u3068\u3082\u8449\u306B\u8FD1\u3044\u9802\u70B9\u306Eid\n  // last : LCA\u3092\
    \u542B\u3080 interval \u3067\u3042\u308B\u304B\u3069\u3046\u304B\n  // reverse\
    \ : from \u2192 to \u3068 top \u2192 bottom\u304C\u9006\u5411\u304D\u304B\u3069\
    \u3046\u304B\n  int top_id, bottom_id;\n  bool last;\n  bool reverse;\n\n  Interval(int\
    \ _top_id, int _bottom_id, bool _last, bool _reverse) : top_id(_top_id), bottom_id(_bottom_id),\
    \ last(_last), reverse(_reverse) {\n\n  }\n};\n\nusing Path = std::vector<Interval>;\n\
    \nstruct HLD {\n\n  //vector<vector<int>>children;\n  std::vector<int>parent;\n\
    \  std::vector<int> id;\n  std::vector<int> id2;\n  std::vector<int> head;\n \
    \ std::vector<int>depth;\n  Graph<int>graph;\n\n  HLD (int N) : parent(std::vector<int>(N,\
    \ -1)), id(std::vector<int>(N)), id2(std::vector<int>(N)), head(std::vector<int>(N)),\
    \ depth(std::vector<int>(N)), graph(N) {}\n\n  void build(int root=0) {\n    dfs_sz(root);\n\
    \    int k = 0; dfs_hld(root, k);\n  }\n\n  int dfs_sz(int v) {\n    int ret =\
    \ 1, mx_sz = 0;\n    for (Edge<int>& nxt : graph[v]) {\n      if (nxt.to == parent[v])\
    \ continue;\n\n      parent[nxt.to] = v;\n      depth[nxt.to] = depth[v] + 1;\n\
    \      int sz = dfs_sz(nxt.to);\n      ret += sz;\n      if (mx_sz < sz) {\n \
    \       mx_sz = sz;\n        std::swap(graph[v][0], nxt);\n      }\n    }\n\n\
    \    return ret;\n  }\n\n  void dfs_hld(int v, int& k) {\n    id[v] = k; k++;\n\
    \    for (Edge e : graph[v]) {\n      if (e.to == parent[v]) continue;\n\n   \
    \   head[e.to] = (e == graph[v][0] ? head[v] : e.to);\n      dfs_hld(e.to, k);\n\
    \    }\n    id2[v] = k;\n  }\n\n  int lca(int u, int v) {\n    while (true) {\n\
    \      if (id[u] > id[v]) std::swap(u, v);\n      if (head[u] == head[v]) return\
    \ u;\n\n      v = parent[head[v]];\n    }\n  }\n\n  Path get_path(int u, int v)\
    \ {\n    Path upath, vpath;\n\n    while (head[u] != head[v]) {\n\n      // \u3061\
    \u306A\u307F\u306Bu,v\u306Edepth\u306E\u5927\u5C0F\u95A2\u4FC2\u306F\u5909\u308F\
    \u308A\u7D9A\u3051\u308B\u3053\u3068\u3082\u3042\u308B\u3002\n      // 10 \u2192\
    \ 12\u306A\u3069\u3002\n\n      // v's head is deeper\n      if (depth[head[v]]\
    \ >= depth[head[u]]) {\n        assert(depth[head[v]] >= depth[head[u]]);\n  \
    \      /*\n          /   : heavy edge\n         .... : light edge\n\n        \
    \    head[u]\n               /\n              /...\n             u  ...\n    \
    \        /   head[v]\n           /       \\\n          /         \\\n        \
    \ /           v\n        */\n\n        // u\u2192v \u306A\u306E\u3067reverse=false\n\
    \        vpath.emplace_back(id[head[v]], id[v], false, false);\n        v = parent[head[v]];\n\
    \      }\n\n      // u's head is deeper\n      else if (depth[head[v]] < depth[head[u]])\
    \ {\n        /*\n          /   : heavy edge\n         .... : light edge\n\n  \
    \          head[v]\n               /\n              /...\n             v  ...\n\
    \            /   head[u]\n           /       \\\n          /         \\\n    \
    \     /           u\n        */\n\n        //\n        upath.emplace_back(id[head[u]],\
    \ id[u], false, true);\n        u = parent[head[u]];\n      }\n    }\n\n    //\
    \ v is deeper\n    /*\n       u\n      /\n     /  \u2190\u2193\n    /\n   v\n\n\
    \    */\n    if (depth[v] > depth[u]) {\n      upath.emplace_back(id[u], id[v],\
    \ true, false);\n    }\n\n    // u is deeper\n    /*\n       v\n      /\n    \
    \ /  \u2192\u2191\n    /\n   u\n\n    */\n    else {\n      upath.emplace_back(id[v],\
    \ id[u], true, true);\n    }\n    Path retpath = upath;\n    std::reverse(vpath.begin(),\
    \ vpath.end());\n    for (Interval path : vpath) retpath.push_back(path);\n\n\
    \    return retpath;\n  }\n\n  std::pair<int,int> subtree_query(int r) {\n   \
    \ assert(r < int(id.size()));\n    return std::make_pair(id[r], id2[r]);\n  }\n\
    \n};\n\n\n"
  code: "#ifndef HARUILIB_GRAPH_TREE_HEAVY_LIGHT_DECOMPOSITION_HPP\n#define HARUILIB_GRAPH_TREE_HEAVY_LIGHT_DECOMPOSITION_HPP\n\
    \n#include <vector>\n#include <algorithm>\n#include <cassert>\n#include <utility>\n\
    \n#include \"graph/graph_template.hpp\"\n\n// cf : https://ngtkana.hatenablog.com/entry/2024/06/24/200138\n\
    struct Interval {\n  // top_id : interval \u306E\u3082\u3063\u3068\u3082\u6839\
    \u306B\u8FD1\u3044\u9802\u70B9\u306Eid\n  // bottom_id : interval \u306E\u3082\
    \u3063\u3068\u3082\u8449\u306B\u8FD1\u3044\u9802\u70B9\u306Eid\n  // last : LCA\u3092\
    \u542B\u3080 interval \u3067\u3042\u308B\u304B\u3069\u3046\u304B\n  // reverse\
    \ : from \u2192 to \u3068 top \u2192 bottom\u304C\u9006\u5411\u304D\u304B\u3069\
    \u3046\u304B\n  int top_id, bottom_id;\n  bool last;\n  bool reverse;\n\n  Interval(int\
    \ _top_id, int _bottom_id, bool _last, bool _reverse) : top_id(_top_id), bottom_id(_bottom_id),\
    \ last(_last), reverse(_reverse) {\n\n  }\n};\n\nusing Path = std::vector<Interval>;\n\
    \nstruct HLD {\n\n  //vector<vector<int>>children;\n  std::vector<int>parent;\n\
    \  std::vector<int> id;\n  std::vector<int> id2;\n  std::vector<int> head;\n \
    \ std::vector<int>depth;\n  Graph<int>graph;\n\n  HLD (int N) : parent(std::vector<int>(N,\
    \ -1)), id(std::vector<int>(N)), id2(std::vector<int>(N)), head(std::vector<int>(N)),\
    \ depth(std::vector<int>(N)), graph(N) {}\n\n  void build(int root=0) {\n    dfs_sz(root);\n\
    \    int k = 0; dfs_hld(root, k);\n  }\n\n  int dfs_sz(int v) {\n    int ret =\
    \ 1, mx_sz = 0;\n    for (Edge<int>& nxt : graph[v]) {\n      if (nxt.to == parent[v])\
    \ continue;\n\n      parent[nxt.to] = v;\n      depth[nxt.to] = depth[v] + 1;\n\
    \      int sz = dfs_sz(nxt.to);\n      ret += sz;\n      if (mx_sz < sz) {\n \
    \       mx_sz = sz;\n        std::swap(graph[v][0], nxt);\n      }\n    }\n\n\
    \    return ret;\n  }\n\n  void dfs_hld(int v, int& k) {\n    id[v] = k; k++;\n\
    \    for (Edge e : graph[v]) {\n      if (e.to == parent[v]) continue;\n\n   \
    \   head[e.to] = (e == graph[v][0] ? head[v] : e.to);\n      dfs_hld(e.to, k);\n\
    \    }\n    id2[v] = k;\n  }\n\n  int lca(int u, int v) {\n    while (true) {\n\
    \      if (id[u] > id[v]) std::swap(u, v);\n      if (head[u] == head[v]) return\
    \ u;\n\n      v = parent[head[v]];\n    }\n  }\n\n  Path get_path(int u, int v)\
    \ {\n    Path upath, vpath;\n\n    while (head[u] != head[v]) {\n\n      // \u3061\
    \u306A\u307F\u306Bu,v\u306Edepth\u306E\u5927\u5C0F\u95A2\u4FC2\u306F\u5909\u308F\
    \u308A\u7D9A\u3051\u308B\u3053\u3068\u3082\u3042\u308B\u3002\n      // 10 \u2192\
    \ 12\u306A\u3069\u3002\n\n      // v's head is deeper\n      if (depth[head[v]]\
    \ >= depth[head[u]]) {\n        assert(depth[head[v]] >= depth[head[u]]);\n  \
    \      /*\n          /   : heavy edge\n         .... : light edge\n\n        \
    \    head[u]\n               /\n              /...\n             u  ...\n    \
    \        /   head[v]\n           /       \\\n          /         \\\n        \
    \ /           v\n        */\n\n        // u\u2192v \u306A\u306E\u3067reverse=false\n\
    \        vpath.emplace_back(id[head[v]], id[v], false, false);\n        v = parent[head[v]];\n\
    \      }\n\n      // u's head is deeper\n      else if (depth[head[v]] < depth[head[u]])\
    \ {\n        /*\n          /   : heavy edge\n         .... : light edge\n\n  \
    \          head[v]\n               /\n              /...\n             v  ...\n\
    \            /   head[u]\n           /       \\\n          /         \\\n    \
    \     /           u\n        */\n\n        //\n        upath.emplace_back(id[head[u]],\
    \ id[u], false, true);\n        u = parent[head[u]];\n      }\n    }\n\n    //\
    \ v is deeper\n    /*\n       u\n      /\n     /  \u2190\u2193\n    /\n   v\n\n\
    \    */\n    if (depth[v] > depth[u]) {\n      upath.emplace_back(id[u], id[v],\
    \ true, false);\n    }\n\n    // u is deeper\n    /*\n       v\n      /\n    \
    \ /  \u2192\u2191\n    /\n   u\n\n    */\n    else {\n      upath.emplace_back(id[v],\
    \ id[u], true, true);\n    }\n    Path retpath = upath;\n    std::reverse(vpath.begin(),\
    \ vpath.end());\n    for (Interval path : vpath) retpath.push_back(path);\n\n\
    \    return retpath;\n  }\n\n  std::pair<int,int> subtree_query(int r) {\n   \
    \ assert(r < int(id.size()));\n    return std::make_pair(id[r], id2[r]);\n  }\n\
    \n};\n\n#endif // HARUILIB_GRAPH_TREE_HEAVY_LIGHT_DECOMPOSITION_HPP\n"
  dependsOn:
  - graph/graph_template.hpp
  isVerificationFile: false
  path: graph/tree/heavy_light_decomposition.hpp
  requiredBy: []
  timestamp: '2024-08-15 16:38:21+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/verify/yosupo-vertex-add-subtree-sum.test.cpp
  - test/verify/yosupo-vertex-add-path-sum.test.cpp
  - test/verify/yosupo-vertex-set-path-composite.test.cpp
documentation_of: graph/tree/heavy_light_decomposition.hpp
layout: document
titel: "Heavy-Light Decomposition(HL\u5206\u89E3, HLD)"
---

木に関する部分木クエリ、パスクエリを処理するためのデータ構造。

## コンストラクタ

```
HLD (int N)
```

`N` :　頂点の数。

(`HLD hld(20);`などして構築したあと、`hld.graph.add_edge(0,1);` などして木の情報を与える。)

## build

```
void build(int root=0)
```
`root`を根とした木のHeavy-Light Decompositionを実行する。


## lca

```cpp
int lca(int u, int v)
```

`u`と`v`の最小共通祖先(LCA)を求める。

## get_path

```cpp
Path get_path(int u, int v)
```

頂点`u`から頂点`v`までのパスを返す。パスはHeavy-Edgeで繋がれた区間(`Interval`)の`vector`として表される。

ここで、 `using Path = std::vector<Interval>`として定義されていて、`Interval`は

```cpp
struct Interval {
  // top_id : interval のもっとも根に近い頂点のid
  // bottom_id : interval のもっとも葉に近い頂点のid
  // last : LCAを含む interval であるかどうか
  // reverse : from → to と top → bottomが逆向きかどうか
  int top_id, bottom_id;
  bool last;
  bool reverse;

  Interval(int _top_id, int _bottom_id, bool _last, bool _reverse) : top_id(_top_id), bottom_id(_bottom_id), last(_last), reverse(_reverse) {

  }
};
``` 
として定義されている。

