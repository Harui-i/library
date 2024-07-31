---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/graph_template.hpp
    title: graph/graph_template.hpp
  - icon: ':heavy_check_mark:'
    path: graph/tree/heavy_light_decomposition.hpp
    title: graph/tree/heavy_light_decomposition.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/vertex_add_path_sum
    links:
    - https://en.wikipedia.org/wiki/Fenwick_tree
    - https://judge.yosupo.jp/problem/vertex_add_path_sum
  bundledCode: "#line 1 \"test/verify/yosupo-vertex-add-path-sum.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/vertex_add_path_sum\"\n#line 1 \"\
    template/template.hpp\"\n#include <bits/stdc++.h>\nusing namespace std;\nusing\
    \ ll = long long;\ntemplate<class T> inline bool chmax(T& a, const T& b) {if (a<b)\
    \ {a=b; return true;} return false;}\ntemplate<class T> inline bool chmin(T& a,\
    \ const T& b) {if (b<a) {a=b; return true;} return false;}\nconst int INTINF =\
    \ 1000001000;\nconst int INTMAX = 2147483647;\nconst ll LLMAX = 9223372036854775807;\n\
    const ll LLINF = 1000000000000000000;\n#line 3 \"test/verify/yosupo-vertex-add-path-sum.test.cpp\"\
    \n\n#include <type_traits>\n\nnamespace atcoder {\n\nnamespace internal {\n\n\
    #ifndef _MSC_VER\ntemplate <class T>\nusing is_signed_int128 =\n    typename std::conditional<std::is_same<T,\
    \ __int128_t>::value ||\n                                  std::is_same<T, __int128>::value,\n\
    \                              std::true_type,\n                             \
    \ std::false_type>::type;\n\ntemplate <class T>\nusing is_unsigned_int128 =\n\
    \    typename std::conditional<std::is_same<T, __uint128_t>::value ||\n      \
    \                            std::is_same<T, unsigned __int128>::value,\n    \
    \                          std::true_type,\n                              std::false_type>::type;\n\
    \ntemplate <class T>\nusing make_unsigned_int128 =\n    typename std::conditional<std::is_same<T,\
    \ __int128_t>::value,\n                              __uint128_t,\n          \
    \                    unsigned __int128>;\n\ntemplate <class T>\nusing is_integral\
    \ = typename std::conditional<std::is_integral<T>::value ||\n                \
    \                                  is_signed_int128<T>::value ||\n           \
    \                                       is_unsigned_int128<T>::value,\n      \
    \                                        std::true_type,\n                   \
    \                           std::false_type>::type;\n\ntemplate <class T>\nusing\
    \ is_signed_int = typename std::conditional<(is_integral<T>::value &&\n      \
    \                                           std::is_signed<T>::value) ||\n   \
    \                                                 is_signed_int128<T>::value,\n\
    \                                                std::true_type,\n           \
    \                                     std::false_type>::type;\n\ntemplate <class\
    \ T>\nusing is_unsigned_int =\n    typename std::conditional<(is_integral<T>::value\
    \ &&\n                               std::is_unsigned<T>::value) ||\n        \
    \                          is_unsigned_int128<T>::value,\n                   \
    \           std::true_type,\n                              std::false_type>::type;\n\
    \ntemplate <class T>\nusing to_unsigned = typename std::conditional<\n    is_signed_int128<T>::value,\n\
    \    make_unsigned_int128<T>,\n    typename std::conditional<std::is_signed<T>::value,\n\
    \                              std::make_unsigned<T>,\n                      \
    \        std::common_type<T>>::type>::type;\n\n#else\n\ntemplate <class T> using\
    \ is_integral = typename std::is_integral<T>;\n\ntemplate <class T>\nusing is_signed_int\
    \ =\n    typename std::conditional<is_integral<T>::value && std::is_signed<T>::value,\n\
    \                              std::true_type,\n                             \
    \ std::false_type>::type;\n\ntemplate <class T>\nusing is_unsigned_int =\n   \
    \ typename std::conditional<is_integral<T>::value &&\n                       \
    \           std::is_unsigned<T>::value,\n                              std::true_type,\n\
    \                              std::false_type>::type;\n\ntemplate <class T>\n\
    using to_unsigned = typename std::conditional<is_signed_int<T>::value,\n     \
    \                                         std::make_unsigned<T>,\n           \
    \                                   std::common_type<T>>::type;\n\n#endif\n\n\
    template <class T>\nusing is_signed_int_t = std::enable_if_t<is_signed_int<T>::value>;\n\
    \ntemplate <class T>\nusing is_unsigned_int_t = std::enable_if_t<is_unsigned_int<T>::value>;\n\
    \ntemplate <class T> using to_unsigned_t = typename to_unsigned<T>::type;\n\n\
    }  // namespace internal\n\n}  // namespace atcoder\n\nnamespace atcoder {\n\n\
    // Reference: https://en.wikipedia.org/wiki/Fenwick_tree\ntemplate <class T> struct\
    \ fenwick_tree {\n    using U = internal::to_unsigned_t<T>;\n\n  public:\n   \
    \ fenwick_tree() : _n(0) {}\n    explicit fenwick_tree(int n) : _n(n), data(n)\
    \ {}\n\n    void add(int p, T x) {\n        assert(0 <= p && p < _n);\n      \
    \  p++;\n        while (p <= _n) {\n            data[p - 1] += U(x);\n       \
    \     p += p & -p;\n        }\n    }\n\n    T sum(int l, int r) {\n        assert(0\
    \ <= l && l <= r && r <= _n);\n        return sum(r) - sum(l);\n    }\n\n  private:\n\
    \    int _n;\n    std::vector<U> data;\n\n    U sum(int r) {\n        U s = 0;\n\
    \        while (r > 0) {\n            s += data[r - 1];\n            r -= r &\
    \ -r;\n        }\n        return s;\n    }\n};\n\n}  // namespace atcoder\n\n\
    #line 1 \"graph/tree/heavy_light_decomposition.hpp\"\n\n\n\n#line 8 \"graph/tree/heavy_light_decomposition.hpp\"\
    \n\n#line 1 \"graph/graph_template.hpp\"\n\n\n\n#line 5 \"graph/graph_template.hpp\"\
    \n\ntemplate <typename T>\nstruct Edge {\n  int from; int to;\n  T cost;\n\n \
    \ Edge(int _from, int _to, T _cost) : from(_from), to(_to), cost(_cost) {}\n\n\
    \  // unweighted\n  Edge(int _from, int _to) : from(_from), to(_to), cost(T(1))\
    \ {}\n\n  bool operator==(const Edge& rhs) {\n    return from == rhs.from && to\
    \ == rhs.to && cost == rhs.cost;\n  }\n\n};\n\n\ntemplate <typename T>\nstruct\
    \ Graph : std::vector<std::vector<Edge<T>>> {\n\n  using std::vector<std::vector<Edge<T>>>::vector;\
    \ // inherit constructors\n\n  void add_edge(int i, Edge<T> e) {\n    (*this)[i].push_back(e);\n\
    \  }\n\n  // weighted\n  void add_edge(int _from, int _to, T _cost) {\n    (*this)[_from].push_back(Edge(_from,\
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
    \n};\n\n\n#line 138 \"test/verify/yosupo-vertex-add-path-sum.test.cpp\"\n\nint\
    \ main() {\n  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);\n  int N, Q; cin\
    \ >> N >> Q;\n  vector<int>a(N); \n  for(int i=0; i<N; i++) cin >> a[i];\n\n \
    \ HLD hld(N);\n  for (int i=0; i<N-1; i++) {\n    int u, v; cin >> u >> v;\n \
    \   hld.graph.add_edge(u,v);\n    hld.graph.add_edge(v,u);\n  }\n\n  hld.build();\n\
    \  atcoder::fenwick_tree<ll> fw(N);\n  for (int i=0; i<N; i++) {\n    fw.add(hld.id[i],\
    \ a[i]);\n  }\n\n  for (int q=0; q<Q; q++) {\n    int op; cin >> op;\n    if (op\
    \ == 0) {\n      int p, x; cin >> p >> x;\n      fw.add(hld.id[p], x);\n    }\n\
    \    else if (op == 1) {\n      int u, v; cin >> u >> v;\n      ll ret = 0;\n\n\
    \      for (Interval interval : hld.get_path(u, v)) {\n        ret += fw.sum(interval.top_id,\
    \ interval.bottom_id + 1);\n      }\n\n      cout << ret << endl;\n    }\n  }\n\
    \n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_add_path_sum\"\n\
    #include \"template/template.hpp\"\n\n#include <type_traits>\n\nnamespace atcoder\
    \ {\n\nnamespace internal {\n\n#ifndef _MSC_VER\ntemplate <class T>\nusing is_signed_int128\
    \ =\n    typename std::conditional<std::is_same<T, __int128_t>::value ||\n   \
    \                               std::is_same<T, __int128>::value,\n          \
    \                    std::true_type,\n                              std::false_type>::type;\n\
    \ntemplate <class T>\nusing is_unsigned_int128 =\n    typename std::conditional<std::is_same<T,\
    \ __uint128_t>::value ||\n                                  std::is_same<T, unsigned\
    \ __int128>::value,\n                              std::true_type,\n         \
    \                     std::false_type>::type;\n\ntemplate <class T>\nusing make_unsigned_int128\
    \ =\n    typename std::conditional<std::is_same<T, __int128_t>::value,\n     \
    \                         __uint128_t,\n                              unsigned\
    \ __int128>;\n\ntemplate <class T>\nusing is_integral = typename std::conditional<std::is_integral<T>::value\
    \ ||\n                                                  is_signed_int128<T>::value\
    \ ||\n                                                  is_unsigned_int128<T>::value,\n\
    \                                              std::true_type,\n             \
    \                                 std::false_type>::type;\n\ntemplate <class T>\n\
    using is_signed_int = typename std::conditional<(is_integral<T>::value &&\n  \
    \                                               std::is_signed<T>::value) ||\n\
    \                                                    is_signed_int128<T>::value,\n\
    \                                                std::true_type,\n           \
    \                                     std::false_type>::type;\n\ntemplate <class\
    \ T>\nusing is_unsigned_int =\n    typename std::conditional<(is_integral<T>::value\
    \ &&\n                               std::is_unsigned<T>::value) ||\n        \
    \                          is_unsigned_int128<T>::value,\n                   \
    \           std::true_type,\n                              std::false_type>::type;\n\
    \ntemplate <class T>\nusing to_unsigned = typename std::conditional<\n    is_signed_int128<T>::value,\n\
    \    make_unsigned_int128<T>,\n    typename std::conditional<std::is_signed<T>::value,\n\
    \                              std::make_unsigned<T>,\n                      \
    \        std::common_type<T>>::type>::type;\n\n#else\n\ntemplate <class T> using\
    \ is_integral = typename std::is_integral<T>;\n\ntemplate <class T>\nusing is_signed_int\
    \ =\n    typename std::conditional<is_integral<T>::value && std::is_signed<T>::value,\n\
    \                              std::true_type,\n                             \
    \ std::false_type>::type;\n\ntemplate <class T>\nusing is_unsigned_int =\n   \
    \ typename std::conditional<is_integral<T>::value &&\n                       \
    \           std::is_unsigned<T>::value,\n                              std::true_type,\n\
    \                              std::false_type>::type;\n\ntemplate <class T>\n\
    using to_unsigned = typename std::conditional<is_signed_int<T>::value,\n     \
    \                                         std::make_unsigned<T>,\n           \
    \                                   std::common_type<T>>::type;\n\n#endif\n\n\
    template <class T>\nusing is_signed_int_t = std::enable_if_t<is_signed_int<T>::value>;\n\
    \ntemplate <class T>\nusing is_unsigned_int_t = std::enable_if_t<is_unsigned_int<T>::value>;\n\
    \ntemplate <class T> using to_unsigned_t = typename to_unsigned<T>::type;\n\n\
    }  // namespace internal\n\n}  // namespace atcoder\n\nnamespace atcoder {\n\n\
    // Reference: https://en.wikipedia.org/wiki/Fenwick_tree\ntemplate <class T> struct\
    \ fenwick_tree {\n    using U = internal::to_unsigned_t<T>;\n\n  public:\n   \
    \ fenwick_tree() : _n(0) {}\n    explicit fenwick_tree(int n) : _n(n), data(n)\
    \ {}\n\n    void add(int p, T x) {\n        assert(0 <= p && p < _n);\n      \
    \  p++;\n        while (p <= _n) {\n            data[p - 1] += U(x);\n       \
    \     p += p & -p;\n        }\n    }\n\n    T sum(int l, int r) {\n        assert(0\
    \ <= l && l <= r && r <= _n);\n        return sum(r) - sum(l);\n    }\n\n  private:\n\
    \    int _n;\n    std::vector<U> data;\n\n    U sum(int r) {\n        U s = 0;\n\
    \        while (r > 0) {\n            s += data[r - 1];\n            r -= r &\
    \ -r;\n        }\n        return s;\n    }\n};\n\n}  // namespace atcoder\n\n\
    #include \"graph/tree/heavy_light_decomposition.hpp\"\n\nint main() {\n  ios::sync_with_stdio(0);\
    \ cin.tie(0); cout.tie(0);\n  int N, Q; cin >> N >> Q;\n  vector<int>a(N); \n\
    \  for(int i=0; i<N; i++) cin >> a[i];\n\n  HLD hld(N);\n  for (int i=0; i<N-1;\
    \ i++) {\n    int u, v; cin >> u >> v;\n    hld.graph.add_edge(u,v);\n    hld.graph.add_edge(v,u);\n\
    \  }\n\n  hld.build();\n  atcoder::fenwick_tree<ll> fw(N);\n  for (int i=0; i<N;\
    \ i++) {\n    fw.add(hld.id[i], a[i]);\n  }\n\n  for (int q=0; q<Q; q++) {\n \
    \   int op; cin >> op;\n    if (op == 0) {\n      int p, x; cin >> p >> x;\n \
    \     fw.add(hld.id[p], x);\n    }\n    else if (op == 1) {\n      int u, v; cin\
    \ >> u >> v;\n      ll ret = 0;\n\n      for (Interval interval : hld.get_path(u,\
    \ v)) {\n        ret += fw.sum(interval.top_id, interval.bottom_id + 1);\n   \
    \   }\n\n      cout << ret << endl;\n    }\n  }\n\n  return 0;\n}\n"
  dependsOn:
  - template/template.hpp
  - graph/tree/heavy_light_decomposition.hpp
  - graph/graph_template.hpp
  isVerificationFile: true
  path: test/verify/yosupo-vertex-add-path-sum.test.cpp
  requiredBy: []
  timestamp: '2024-07-31 20:07:18+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/verify/yosupo-vertex-add-path-sum.test.cpp
layout: document
redirect_from:
- /verify/test/verify/yosupo-vertex-add-path-sum.test.cpp
- /verify/test/verify/yosupo-vertex-add-path-sum.test.cpp.html
title: test/verify/yosupo-vertex-add-path-sum.test.cpp
---
