---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: math/modint.hpp
    title: modint
  - icon: ':heavy_check_mark:'
    path: structure/slide-window-aggregation.hpp
    title: Foldable Deque(Slide Window Aggregation)
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
    PROBLEM: https://judge.yosupo.jp/problem/queue_operate_all_composite
    links:
    - https://judge.yosupo.jp/problem/queue_operate_all_composite
  bundledCode: "#line 1 \"test/verify/yosupo-queue-operate-all-composite.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/queue_operate_all_composite\"\
    \n\n#line 1 \"template/template.hpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\ntypedef long long ll;\ntypedef unsigned int uint;\ntemplate<class T> inline\
    \ bool chmax(T& a, const T& b) {if (a<b) {a=b; return true;} return false;}\n\
    template<class T> inline bool chmin(T& a, const T& b) {if (b<a) {a=b; return true;}\
    \ return false;}\nconst int INTINF = 1000001000;\nconst int INTMAX = 2147483647;\n\
    const ll LLMAX = 9223372036854775807;\nconst ll LLINF = 1000000000000000000;\n\
    #line 1 \"math/modint.hpp\"\n\n\n\ntemplate<int MOD>\nstruct static_modint {\n\
    \    int value;\n\n    constexpr static_modint() : value(0) {}\n\n    constexpr\
    \ static_modint(long long v) {\n        value = int(((v % MOD) + MOD) % MOD);\n\
    \    }\n\n    constexpr static_modint& operator+=(const static_modint& other)\
    \ {\n        if ((value += other.value) >= MOD) value -= MOD;\n        return\
    \ *this;\n    }\n\n    constexpr static_modint& operator-=(const static_modint&\
    \ other) {\n        if ((value -= other.value) < 0) value += MOD;\n        return\
    \ *this;\n    }\n\n    constexpr static_modint& operator*=(const static_modint&\
    \ other) {\n        value = int((long long)value * other.value % MOD);\n     \
    \   return *this;\n    }\n\n    constexpr static_modint operator+(const static_modint&\
    \ other) const {\n        return static_modint(*this) += other;\n    }\n\n   \
    \ constexpr static_modint operator-(const static_modint& other) const {\n    \
    \    return static_modint(*this) -= other;\n    }\n\n    constexpr static_modint\
    \ operator*(const static_modint& other) const {\n        return static_modint(*this)\
    \ *= other;\n    }\n\n    constexpr static_modint pow(long long exp) const {\n\
    \        static_modint base = *this, res = 1;\n        while (exp > 0) {\n   \
    \         if (exp & 1) res *= base;\n            base *= base;\n            exp\
    \ >>= 1;\n        }\n        return res;\n    }\n\n    constexpr static_modint\
    \ inv() const {\n        return pow(MOD - 2);\n    }\n\n    constexpr static_modint&\
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
    \ 1 \"structure/slide-window-aggregation.hpp\"\ntemplate <class S, S (*op)(S,\
    \ S), S (*e)()>\nstruct FoldableDeque {\n  struct Node {\n    S val;\n    S prod;\n\
    \  };\n\n  vector<Node> front, back;\n\n  FoldableDeque() : front(), back() {}\n\
    \  size_t size() const { return front.size() + back.size(); }\n  bool empty()\
    \ const { return front.size() + back.size() == 0; }\n\n\n  // nyaan\u3055\u3093\
    \u306E\u3092\u30D1\u30AF\u3063\u3066\u304A\u308A\n  void rebalance() {\n    int\
    \ n = front.size() + back.size();\n    int s0 = n / 2 + (front.empty() ? n % 2\
    \ : 0);\n    // front\u306Bs0\u500B\n    // back\u306BN - s0\u500B\u5165\u308C\
    \u308B\n    vector<Node> a{front};\n    reverse(begin(a), end(a));\n    copy(begin(back),\
    \ end(back), back_inserter(a));\n    front.clear(), back.clear();\n    for (int\
    \ i = s0 - 1; i >= 0; i--) push_front(a[i].val);\n    for (int i = s0; i < n;\
    \ i++) push_back(a[i].val);\n    return;\n  }\n\n  S all_prod() const {\n    if\
    \ (front.empty() && back.empty() ) return e();\n\n    if (front.empty()) {\n \
    \     return back.back().prod;\n    }\n    else if (back.empty()) {\n      return\
    \ front.back().prod;\n    }\n\n    else return op(front.back().prod, back.back().prod)\
    \ ;\n  }\n\n  void push_back(const S& x) {\n    if (back.empty()) {\n      back.push_back({x,\
    \ x});\n    }\n    else {\n      // \u9806\u5E8F\u602A\u3057\u3044\u304B\u3082\
    \n      back.push_back({x, op(back.back().prod, x) });\n    }\n  }\n\n  void push_front(const\
    \ S& x) {\n    if (front.empty()) {\n      front.push_back({x, x});\n    }\n \
    \   else {\n      // \u9806\u5E8F\u602A\u3057\u3044\u304B\u3082\n      front.push_back({x,\
    \ op(x, front.back().prod) });\n    }  \n  }\n\n  void pop_back() {\n    assert(size()\
    \ > 0);\n    if (back.empty()) rebalance();\n    back.pop_back();\n  }\n\n  void\
    \ pop_front() {\n    assert(size() > 0);\n    if (front.empty()) rebalance();\n\
    \    front.pop_back();\n  }\n};\n#line 6 \"test/verify/yosupo-queue-operate-all-composite.test.cpp\"\
    \n\nusing mint = modint998244353;\nusing mpp = pair<mint,mint>;\n\nmpp op(mpp\
    \ lf, mpp rf) {\n  return {rf.first * lf.first, rf.first * lf.second + rf.second};\n\
    }\n\nmpp e() {\n  return {1, 0};\n}\n\nint main() {\n  ios::sync_with_stdio(0);\
    \ cin.tie(0); cout.tie(0);\n  FoldableDeque<mpp,op,e> fdq;\n\n  int Q; cin >>\
    \ Q;\n  for(int i=0; i<Q; i++) {\n    int op; cin >> op;\n    if (op == 0) {\n\
    \      int a,b; cin >> a >> b;\n      fdq.push_back({mint(a), mint(b)});\n   \
    \ }\n\n    else if (op == 1) {\n      fdq.pop_front();\n    }\n    else if (op\
    \ == 2) {\n      int x; cin >> x;\n      mpp all_prod = fdq.all_prod();\n    \
    \  cout << mint(x) * all_prod.first + all_prod.second << endl;;\n    }\n  }\n\
    \  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/queue_operate_all_composite\"\
    \n\n#include \"../../template/template.hpp\"\n#include \"../../math/modint.hpp\"\
    \n#include \"../../structure/slide-window-aggregation.hpp\"\n\nusing mint = modint998244353;\n\
    using mpp = pair<mint,mint>;\n\nmpp op(mpp lf, mpp rf) {\n  return {rf.first *\
    \ lf.first, rf.first * lf.second + rf.second};\n}\n\nmpp e() {\n  return {1, 0};\n\
    }\n\nint main() {\n  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);\n  FoldableDeque<mpp,op,e>\
    \ fdq;\n\n  int Q; cin >> Q;\n  for(int i=0; i<Q; i++) {\n    int op; cin >> op;\n\
    \    if (op == 0) {\n      int a,b; cin >> a >> b;\n      fdq.push_back({mint(a),\
    \ mint(b)});\n    }\n\n    else if (op == 1) {\n      fdq.pop_front();\n    }\n\
    \    else if (op == 2) {\n      int x; cin >> x;\n      mpp all_prod = fdq.all_prod();\n\
    \      cout << mint(x) * all_prod.first + all_prod.second << endl;;\n    }\n \
    \ }\n  return 0;\n}"
  dependsOn:
  - template/template.hpp
  - math/modint.hpp
  - structure/slide-window-aggregation.hpp
  isVerificationFile: true
  path: test/verify/yosupo-queue-operate-all-composite.test.cpp
  requiredBy: []
  timestamp: '2024-06-14 19:04:40+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/verify/yosupo-queue-operate-all-composite.test.cpp
layout: document
redirect_from:
- /verify/test/verify/yosupo-queue-operate-all-composite.test.cpp
- /verify/test/verify/yosupo-queue-operate-all-composite.test.cpp.html
title: test/verify/yosupo-queue-operate-all-composite.test.cpp
---
