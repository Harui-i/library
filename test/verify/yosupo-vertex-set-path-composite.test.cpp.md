---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: graph/graph_template.hpp
    title: graph/graph_template.hpp
  - icon: ':heavy_check_mark:'
    path: graph/tree/heavy_light_decomposition.hpp
    title: "Heavy-Light Decomposition(HL\u5206\u89E3, HLD)"
  - icon: ':question:'
    path: math/external_gcd.hpp
    title: math/external_gcd.hpp
  - icon: ':heavy_check_mark:'
    path: math/linear_function.hpp
    title: math/linear_function.hpp
  - icon: ':question:'
    path: math/modint.hpp
    title: modint
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
    PROBLEM: https://judge.yosupo.jp/problem/vertex_set_path_composite
    links:
    - https://judge.yosupo.jp/problem/vertex_set_path_composite
  bundledCode: "#line 1 \"test/verify/yosupo-vertex-set-path-composite.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/vertex_set_path_composite\"\n\
    #line 1 \"template/template.hpp\"\n#include <iostream>\n#include <cassert>\nusing\
    \ namespace std;\nusing ll = long long;\ntemplate<class T> inline bool chmax(T&\
    \ a, const T& b) {if (a<b) {a=b; return true;} return false;}\ntemplate<class\
    \ T> inline bool chmin(T& a, const T& b) {if (b<a) {a=b; return true;} return\
    \ false;}\nconst int INTINF = 1000001000;\nconst int INTMAX = 2147483647;\nconst\
    \ ll LLMAX = 9223372036854775807;\nconst ll LLINF = 1000000000000000000;\n#line\
    \ 3 \"test/verify/yosupo-vertex-set-path-composite.test.cpp\"\n#include <vector>\n\
    \n#ifdef _MSC_VER\n#include <intrin.h>\n#endif\n\nnamespace atcoder {\n\nnamespace\
    \ internal {\n\n// @param n `0 <= n`\n// @return minimum non-negative `x` s.t.\
    \ `n <= 2**x`\nint ceil_pow2(int n) {\n    int x = 0;\n    while ((1U << x) <\
    \ (unsigned int)(n)) x++;\n    return x;\n}\n\n// @param n `1 <= n`\n// @return\
    \ minimum non-negative `x` s.t. `(n & (1 << x)) != 0`\nconstexpr int bsf_constexpr(unsigned\
    \ int n) {\n    int x = 0;\n    while (!(n & (1 << x))) x++;\n    return x;\n\
    }\n\n// @param n `1 <= n`\n// @return minimum non-negative `x` s.t. `(n & (1 <<\
    \ x)) != 0`\nint bsf(unsigned int n) {\n#ifdef _MSC_VER\n    unsigned long index;\n\
    \    _BitScanForward(&index, n);\n    return index;\n#else\n    return __builtin_ctz(n);\n\
    #endif\n}\n\n}  // namespace internal\n\n}  // namespace atcoder\n\nnamespace\
    \ atcoder {\n\ntemplate <class S, S (*op)(S, S), S (*e)()> struct segtree {\n\
    \  public:\n    segtree() : segtree(0) {}\n    explicit segtree(int n) : segtree(std::vector<S>(n,\
    \ e())) {}\n    explicit segtree(const std::vector<S>& v) : _n(int(v.size()))\
    \ {\n        log = internal::ceil_pow2(_n);\n        size = 1 << log;\n      \
    \  d = std::vector<S>(2 * size, e());\n        for (int i = 0; i < _n; i++) d[size\
    \ + i] = v[i];\n        for (int i = size - 1; i >= 1; i--) {\n            update(i);\n\
    \        }\n    }\n\n    void set(int p, S x) {\n        assert(0 <= p && p <\
    \ _n);\n        p += size;\n        d[p] = x;\n        for (int i = 1; i <= log;\
    \ i++) update(p >> i);\n    }\n\n    S get(int p) const {\n        assert(0 <=\
    \ p && p < _n);\n        return d[p + size];\n    }\n\n    S prod(int l, int r)\
    \ const {\n        assert(0 <= l && l <= r && r <= _n);\n        S sml = e(),\
    \ smr = e();\n        l += size;\n        r += size;\n\n        while (l < r)\
    \ {\n            if (l & 1) sml = op(sml, d[l++]);\n            if (r & 1) smr\
    \ = op(d[--r], smr);\n            l >>= 1;\n            r >>= 1;\n        }\n\
    \        return op(sml, smr);\n    }\n\n    S all_prod() const { return d[1];\
    \ }\n\n    template <bool (*f)(S)> int max_right(int l) const {\n        return\
    \ max_right(l, [](S x) { return f(x); });\n    }\n    template <class F> int max_right(int\
    \ l, F f) const {\n        assert(0 <= l && l <= _n);\n        assert(f(e()));\n\
    \        if (l == _n) return _n;\n        l += size;\n        S sm = e();\n  \
    \      do {\n            while (l % 2 == 0) l >>= 1;\n            if (!f(op(sm,\
    \ d[l]))) {\n                while (l < size) {\n                    l = (2 *\
    \ l);\n                    if (f(op(sm, d[l]))) {\n                        sm\
    \ = op(sm, d[l]);\n                        l++;\n                    }\n     \
    \           }\n                return l - size;\n            }\n            sm\
    \ = op(sm, d[l]);\n            l++;\n        } while ((l & -l) != l);\n      \
    \  return _n;\n    }\n\n    template <bool (*f)(S)> int min_left(int r) const\
    \ {\n        return min_left(r, [](S x) { return f(x); });\n    }\n    template\
    \ <class F> int min_left(int r, F f) const {\n        assert(0 <= r && r <= _n);\n\
    \        assert(f(e()));\n        if (r == 0) return 0;\n        r += size;\n\
    \        S sm = e();\n        do {\n            r--;\n            while (r > 1\
    \ && (r % 2)) r >>= 1;\n            if (!f(op(d[r], sm))) {\n                while\
    \ (r < size) {\n                    r = (2 * r + 1);\n                    if (f(op(d[r],\
    \ sm))) {\n                        sm = op(d[r], sm);\n                      \
    \  r--;\n                    }\n                }\n                return r +\
    \ 1 - size;\n            }\n            sm = op(d[r], sm);\n        } while ((r\
    \ & -r) != r);\n        return 0;\n    }\n\n  private:\n    int _n, size, log;\n\
    \    std::vector<S> d;\n\n    void update(int k) { d[k] = op(d[2 * k], d[2 * k\
    \ + 1]); }\n};\n\n}  // namespace atcoder\n\n#line 1 \"math/linear_function.hpp\"\
    \n\n\n\ntemplate <typename T>\nstruct LinearFunction {\n  T a, b;\n\n  LinearFunction()\
    \ : a{0}, b(0) {}\n  LinearFunction(T _a, T _b) : a(_a), b(_b) {}\n\n  static\
    \ LinearFunction Add_Identity() {\n    return LinearFunction(T(0), T(0));\n  }\n\
    \n  static LinearFunction Mul_Identity(){\n    return LinearFunction(T(1), T(0));\n\
    \  }\n\n  // f(g())\n  LinearFunction composite(LinearFunction& g) const {\n \
    \   return LinearFunction(a * g.a, a * g.b + b);\n  }\n\n  LinearFunction operator+(const\
    \ LinearFunction& rhs) const {\n    return LinearFunction(a + rhs.a, b + rhs.b);\n\
    \  }\n\n  // rhs(f())\n  LinearFunction operator*(const LinearFunction& rhs) const\
    \ {\n    LinearFunction f = *this;\n    return rhs.composite(f);\n  }\n\n  T operator()(T\
    \ x) const {\n    return a * x + b;\n  }\n\n};\n\n\n\n#line 1 \"math/modint.hpp\"\
    \n\n\n\n#line 1 \"math/external_gcd.hpp\"\n\n\n\n#include <tuple>\n\n// g,x,y\n\
    template<typename T>\nconstexpr std::tuple<T, T, T> extendedGCD(T a, T b) {\n\
    \    T x0 = 1, y0 = 0, x1 = 0, y1 = 1;\n    while (b != 0) {\n        T q = a\
    \ / b;\n        T r = a % b;\n        a = b;\n        b = r;\n        \n     \
    \   T xTemp = x0 - q * x1;\n        x0 = x1;\n        x1 = xTemp;\n        \n\
    \        T yTemp = y0 - q * y1;\n        y0 = y1;\n        y1 = yTemp;\n    }\n\
    \    return {a, x0, y0};\n}\n\n#line 5 \"math/modint.hpp\"\n\ntemplate<int MOD>\n\
    struct static_modint {\n    int value;\n\n    constexpr explicit static_modint()\
    \ : value(0) {}\n\n    constexpr static_modint(long long v) {\n        value =\
    \ int(((v % MOD) + MOD) % MOD);\n    }\n\n    constexpr static_modint& operator+=(const\
    \ static_modint& other) {\n        if ((value += other.value) >= MOD) value -=\
    \ MOD;\n        return *this;\n    }\n\n    constexpr static_modint& operator-=(const\
    \ static_modint& other) {\n        if ((value -= other.value) < 0) value += MOD;\n\
    \        return *this;\n    }\n\n    constexpr static_modint& operator*=(const\
    \ static_modint& other) {\n        value = int((long long)value * other.value\
    \ % MOD);\n        return *this;\n    }\n\n    constexpr static_modint operator+(const\
    \ static_modint& other) const {\n        return static_modint(*this) += other;\n\
    \    }\n\n    constexpr static_modint operator-(const static_modint& other) const\
    \ {\n        return static_modint(*this) -= other;\n    }\n\n    constexpr static_modint\
    \ operator*(const static_modint& other) const {\n        return static_modint(*this)\
    \ *= other;\n    }\n\n    constexpr static_modint pow(long long exp) const {\n\
    \        static_modint base = *this, res = static_modint(1);\n        while (exp\
    \ > 0) {\n            if (exp & 1) res *= base;\n            base *= base;\n \
    \           exp >>= 1;\n        }\n        return res;\n    }\n\n    constexpr\
    \ static_modint inv() const {\n        //return pow(MOD - 2);\n        int g,x,y;\n\
    \        tie(g,x,y) = extendedGCD(value, MOD);\n        assert(g==1);\n      \
    \  if (x < 0) {\n            x += MOD;\n        }\n        //cerr << g << \" \"\
    \ << x << \" \" << y << \" \" << value << endl;\n        //assert((((long)x*value)%MOD\
    \ + MOD)%MOD == 1);\n        return x;\n    }\n\n    constexpr static_modint&\
    \ operator/=(const static_modint& other) {\n        return *this *= other.inv();\n\
    \    }\n\n    constexpr static_modint operator/(const static_modint& other) const\
    \ {\n        return static_modint(*this) /= other;\n    }\n\n    constexpr bool\
    \ operator!=(const static_modint& other) const {\n        return val() != other.val();\n\
    \    }\n\n    constexpr bool operator==(const static_modint& other) const {\n\
    \        return val() == other.val();\n    }\n\n    int val() const {\n      return\
    \ this->value;\n    }\n\n    friend std::ostream& operator<<(std::ostream& os,\
    \ const static_modint& mi) {\n        return os << mi.value;\n    }\n\n    friend\
    \ std::istream& operator>>(std::istream& is, static_modint& mi) {\n        long\
    \ long x;\n        is >> x;\n        mi = static_modint(x);\n        return is;\n\
    \    }\n};\n\ntemplate <int mod>\nusing modint = static_modint<mod>;\nusing modint998244353\
    \  = modint<998244353>;\nusing modint1000000007 = modint<1000000007>;\n\n\n#line\
    \ 1 \"graph/tree/heavy_light_decomposition.hpp\"\n\n\n\n#line 5 \"graph/tree/heavy_light_decomposition.hpp\"\
    \n#include <algorithm>\n#line 7 \"graph/tree/heavy_light_decomposition.hpp\"\n\
    #include <utility>\n\n#line 1 \"graph/graph_template.hpp\"\n\n\n\n#line 5 \"graph/graph_template.hpp\"\
    \n\ntemplate <typename T>\nstruct Edge {\n  int from; int to;\n  T cost;\n\n \
    \ // default constructor\n  Edge () : from(-1), to(-1), cost(T(0)) {}\n\n  Edge(int\
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
    \n};\n\n\n#line 156 \"test/verify/yosupo-vertex-set-path-composite.test.cpp\"\n\
    \nusing mint = modint998244353;\nusing LF = LinearFunction<mint>;\n\nLF op(LF\
    \ l, LF r) {\n  return l * r;\n}\n\nLF revop(LF l, LF r) {\n  return r * l;\n\
    }\n\nLF e() {\n  return LF::Mul_Identity();\n}\n\nint main() {\n  ios::sync_with_stdio(0);\
    \ cin.tie(0); cout.tie(0);\n  int N, Q; cin >> N >> Q; \n  vector<LF>a(N);\n \
    \ for(int i=0; i<N; i++) {\n    int coef_a, coef_b;\n    cin >> coef_a >> coef_b;\n\
    \    a[i] = LF(coef_a, coef_b);\n  }\n\n  HLD hld(N);\n  for(int i=0; i<N-1; i++)\
    \ {\n    int u, v; cin >> u >> v;\n    hld.graph.add_edge(u,v);\n    hld.graph.add_edge(v,u);\n\
    \  } \n  hld.build();\n\n  atcoder::segtree<LF,op,e> seg(N);\n  atcoder::segtree<LF,revop,e>\
    \ revseg(N);\n\n  for(int i=0; i<N; i++) {\n    seg.set(hld.id[i], a[i]);\n  \
    \  revseg.set(hld.id[i], a[i]);\n  }\n\n  for (int q=0; q<Q; q++) {\n    int op;\
    \ cin >> op;\n    if (op == 0) {\n      int p, c, d; cin >> p >> c >> d;\n   \
    \   seg.set(hld.id[p], LF(c,d));\n      revseg.set(hld.id[p], LF(c,d));\n    }\n\
    \    else if (op == 1) {\n      int u, v; cin >> u >> v;\n      mint x; cin >>\
    \ x;\n\n      LF ret = LF::Mul_Identity();\n      Path path = hld.get_path(u,v);\n\
    \      for (Interval interval : path) {\n        if (interval.reverse == true)\
    \ {\n          ret = ret * revseg.prod(interval.top_id, interval.bottom_id + 1);\n\
    \        }\n        else {\n          ret = ret * seg.prod(interval.top_id, interval.bottom_id\
    \ + 1);\n        }\n      }\n\n      mint ans = ret(x);\n      cout << ans.val()\
    \ << endl;\n    }\n  }\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_set_path_composite\"\
    \n#include \"template/template.hpp\"\n#include <vector>\n\n#ifdef _MSC_VER\n#include\
    \ <intrin.h>\n#endif\n\nnamespace atcoder {\n\nnamespace internal {\n\n// @param\
    \ n `0 <= n`\n// @return minimum non-negative `x` s.t. `n <= 2**x`\nint ceil_pow2(int\
    \ n) {\n    int x = 0;\n    while ((1U << x) < (unsigned int)(n)) x++;\n    return\
    \ x;\n}\n\n// @param n `1 <= n`\n// @return minimum non-negative `x` s.t. `(n\
    \ & (1 << x)) != 0`\nconstexpr int bsf_constexpr(unsigned int n) {\n    int x\
    \ = 0;\n    while (!(n & (1 << x))) x++;\n    return x;\n}\n\n// @param n `1 <=\
    \ n`\n// @return minimum non-negative `x` s.t. `(n & (1 << x)) != 0`\nint bsf(unsigned\
    \ int n) {\n#ifdef _MSC_VER\n    unsigned long index;\n    _BitScanForward(&index,\
    \ n);\n    return index;\n#else\n    return __builtin_ctz(n);\n#endif\n}\n\n}\
    \  // namespace internal\n\n}  // namespace atcoder\n\nnamespace atcoder {\n\n\
    template <class S, S (*op)(S, S), S (*e)()> struct segtree {\n  public:\n    segtree()\
    \ : segtree(0) {}\n    explicit segtree(int n) : segtree(std::vector<S>(n, e()))\
    \ {}\n    explicit segtree(const std::vector<S>& v) : _n(int(v.size())) {\n  \
    \      log = internal::ceil_pow2(_n);\n        size = 1 << log;\n        d = std::vector<S>(2\
    \ * size, e());\n        for (int i = 0; i < _n; i++) d[size + i] = v[i];\n  \
    \      for (int i = size - 1; i >= 1; i--) {\n            update(i);\n       \
    \ }\n    }\n\n    void set(int p, S x) {\n        assert(0 <= p && p < _n);\n\
    \        p += size;\n        d[p] = x;\n        for (int i = 1; i <= log; i++)\
    \ update(p >> i);\n    }\n\n    S get(int p) const {\n        assert(0 <= p &&\
    \ p < _n);\n        return d[p + size];\n    }\n\n    S prod(int l, int r) const\
    \ {\n        assert(0 <= l && l <= r && r <= _n);\n        S sml = e(), smr =\
    \ e();\n        l += size;\n        r += size;\n\n        while (l < r) {\n  \
    \          if (l & 1) sml = op(sml, d[l++]);\n            if (r & 1) smr = op(d[--r],\
    \ smr);\n            l >>= 1;\n            r >>= 1;\n        }\n        return\
    \ op(sml, smr);\n    }\n\n    S all_prod() const { return d[1]; }\n\n    template\
    \ <bool (*f)(S)> int max_right(int l) const {\n        return max_right(l, [](S\
    \ x) { return f(x); });\n    }\n    template <class F> int max_right(int l, F\
    \ f) const {\n        assert(0 <= l && l <= _n);\n        assert(f(e()));\n  \
    \      if (l == _n) return _n;\n        l += size;\n        S sm = e();\n    \
    \    do {\n            while (l % 2 == 0) l >>= 1;\n            if (!f(op(sm,\
    \ d[l]))) {\n                while (l < size) {\n                    l = (2 *\
    \ l);\n                    if (f(op(sm, d[l]))) {\n                        sm\
    \ = op(sm, d[l]);\n                        l++;\n                    }\n     \
    \           }\n                return l - size;\n            }\n            sm\
    \ = op(sm, d[l]);\n            l++;\n        } while ((l & -l) != l);\n      \
    \  return _n;\n    }\n\n    template <bool (*f)(S)> int min_left(int r) const\
    \ {\n        return min_left(r, [](S x) { return f(x); });\n    }\n    template\
    \ <class F> int min_left(int r, F f) const {\n        assert(0 <= r && r <= _n);\n\
    \        assert(f(e()));\n        if (r == 0) return 0;\n        r += size;\n\
    \        S sm = e();\n        do {\n            r--;\n            while (r > 1\
    \ && (r % 2)) r >>= 1;\n            if (!f(op(d[r], sm))) {\n                while\
    \ (r < size) {\n                    r = (2 * r + 1);\n                    if (f(op(d[r],\
    \ sm))) {\n                        sm = op(d[r], sm);\n                      \
    \  r--;\n                    }\n                }\n                return r +\
    \ 1 - size;\n            }\n            sm = op(d[r], sm);\n        } while ((r\
    \ & -r) != r);\n        return 0;\n    }\n\n  private:\n    int _n, size, log;\n\
    \    std::vector<S> d;\n\n    void update(int k) { d[k] = op(d[2 * k], d[2 * k\
    \ + 1]); }\n};\n\n}  // namespace atcoder\n\n#include \"math/linear_function.hpp\"\
    \n#include \"math/modint.hpp\"\n#include \"graph/tree/heavy_light_decomposition.hpp\"\
    \n\nusing mint = modint998244353;\nusing LF = LinearFunction<mint>;\n\nLF op(LF\
    \ l, LF r) {\n  return l * r;\n}\n\nLF revop(LF l, LF r) {\n  return r * l;\n\
    }\n\nLF e() {\n  return LF::Mul_Identity();\n}\n\nint main() {\n  ios::sync_with_stdio(0);\
    \ cin.tie(0); cout.tie(0);\n  int N, Q; cin >> N >> Q; \n  vector<LF>a(N);\n \
    \ for(int i=0; i<N; i++) {\n    int coef_a, coef_b;\n    cin >> coef_a >> coef_b;\n\
    \    a[i] = LF(coef_a, coef_b);\n  }\n\n  HLD hld(N);\n  for(int i=0; i<N-1; i++)\
    \ {\n    int u, v; cin >> u >> v;\n    hld.graph.add_edge(u,v);\n    hld.graph.add_edge(v,u);\n\
    \  } \n  hld.build();\n\n  atcoder::segtree<LF,op,e> seg(N);\n  atcoder::segtree<LF,revop,e>\
    \ revseg(N);\n\n  for(int i=0; i<N; i++) {\n    seg.set(hld.id[i], a[i]);\n  \
    \  revseg.set(hld.id[i], a[i]);\n  }\n\n  for (int q=0; q<Q; q++) {\n    int op;\
    \ cin >> op;\n    if (op == 0) {\n      int p, c, d; cin >> p >> c >> d;\n   \
    \   seg.set(hld.id[p], LF(c,d));\n      revseg.set(hld.id[p], LF(c,d));\n    }\n\
    \    else if (op == 1) {\n      int u, v; cin >> u >> v;\n      mint x; cin >>\
    \ x;\n\n      LF ret = LF::Mul_Identity();\n      Path path = hld.get_path(u,v);\n\
    \      for (Interval interval : path) {\n        if (interval.reverse == true)\
    \ {\n          ret = ret * revseg.prod(interval.top_id, interval.bottom_id + 1);\n\
    \        }\n        else {\n          ret = ret * seg.prod(interval.top_id, interval.bottom_id\
    \ + 1);\n        }\n      }\n\n      mint ans = ret(x);\n      cout << ans.val()\
    \ << endl;\n    }\n  }\n\n  return 0;\n}\n"
  dependsOn:
  - template/template.hpp
  - math/linear_function.hpp
  - math/modint.hpp
  - math/external_gcd.hpp
  - graph/tree/heavy_light_decomposition.hpp
  - graph/graph_template.hpp
  isVerificationFile: true
  path: test/verify/yosupo-vertex-set-path-composite.test.cpp
  requiredBy: []
  timestamp: '2024-09-07 20:55:28+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/verify/yosupo-vertex-set-path-composite.test.cpp
layout: document
redirect_from:
- /verify/test/verify/yosupo-vertex-set-path-composite.test.cpp
- /verify/test/verify/yosupo-vertex-set-path-composite.test.cpp.html
title: test/verify/yosupo-vertex-set-path-composite.test.cpp
---
