---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/external_gcd.hpp
    title: math/external_gcd.hpp
  - icon: ':heavy_check_mark:'
    path: math/linear_function.hpp
    title: math/linear_function.hpp
  - icon: ':heavy_check_mark:'
    path: math/modint.hpp
    title: modint
  - icon: ':heavy_check_mark:'
    path: structure/slide-window-aggregation.hpp
    title: Foldable Deque(Slide Window Aggregation)
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
    PROBLEM: https://judge.yosupo.jp/problem/queue_operate_all_composite
    links:
    - https://judge.yosupo.jp/problem/queue_operate_all_composite
  bundledCode: "#line 1 \"test/verify/yosupo-queue-operate-all-composite.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/queue_operate_all_composite\"\
    \n\n#line 1 \"template/template.hpp\"\n#include <iostream>\n#include <cassert>\n\
    using namespace std;\nusing ll = long long;\ntemplate<class T> inline bool chmax(T&\
    \ a, const T& b) {if (a<b) {a=b; return true;} return false;}\ntemplate<class\
    \ T> inline bool chmin(T& a, const T& b) {if (b<a) {a=b; return true;} return\
    \ false;}\nconst int INTINF = 1000001000;\nconst int INTMAX = 2147483647;\nconst\
    \ ll LLMAX = 9223372036854775807;\nconst ll LLINF = 1000000000000000000;\n#line\
    \ 1 \"math/modint.hpp\"\n\n\n\n#line 1 \"math/external_gcd.hpp\"\n\n\n\n#include\
    \ <tuple>\n\n// g,x,y\ntemplate<typename T>\nconstexpr std::tuple<T, T, T> extendedGCD(T\
    \ a, T b) {\n    T x0 = 1, y0 = 0, x1 = 0, y1 = 1;\n    while (b != 0) {\n   \
    \     T q = a / b;\n        T r = a % b;\n        a = b;\n        b = r;\n   \
    \     \n        T xTemp = x0 - q * x1;\n        x0 = x1;\n        x1 = xTemp;\n\
    \        \n        T yTemp = y0 - q * y1;\n        y0 = y1;\n        y1 = yTemp;\n\
    \    }\n    return {a, x0, y0};\n}\n\n#line 5 \"math/modint.hpp\"\n#include <type_traits>\n\
    #line 7 \"math/modint.hpp\"\n\ntemplate<int MOD, typename T = int>\nstruct static_modint\
    \ {\n    T value;\n\n    constexpr explicit static_modint() : value(0) {}\n\n\
    \    constexpr static_modint(long long v) {\n        if constexpr (std::is_same<T,\
    \ double>::value) {\n            value = static_cast<T>(v);\n        }\n     \
    \   else {\n            value = int(((v % MOD) + MOD) % MOD);\n        }\n   \
    \ }\n\n    constexpr static_modint& operator+=(const static_modint& other) {\n\
    \        if constexpr (std::is_same<T, double>::value) {\n            value +=\
    \ other.value;\n        }\n        else {\n            if ((value += other.value)\
    \ >= MOD) value -= MOD;\n        }\n        return *this;\n    }\n\n    constexpr\
    \ static_modint& operator-=(const static_modint& other) {\n        if constexpr\
    \ (std::is_same<T, double>::value) {\n            value -= other.value;\n    \
    \    }\n        else {\n            if ((value -= other.value) < 0) value += MOD;\n\
    \        }\n        return *this;\n    }\n\n    constexpr static_modint& operator*=(const\
    \ static_modint& other) {\n        if constexpr (std::is_same<T, double>::value)\
    \ {\n            value *= other.value;\n        }\n        else {\n          \
    \  value = int((long long)value * other.value % MOD);\n        }\n        return\
    \ *this;\n    }\n\n    constexpr static_modint operator+(const static_modint&\
    \ other) const {\n        return static_modint(*this) += other;\n    }\n\n   \
    \ constexpr static_modint operator-(const static_modint& other) const {\n    \
    \    return static_modint(*this) -= other;\n    }\n\n    constexpr static_modint\
    \ operator*(const static_modint& other) const {\n        return static_modint(*this)\
    \ *= other;\n    }\n\n    constexpr static_modint pow(long long exp) const {\n\
    \        static_modint base = *this, res = static_modint(1);\n        while (exp\
    \ > 0) {\n            if (exp & 1) res *= base;\n            base *= base;\n \
    \           exp >>= 1;\n        }\n        return res;\n    }\n\n    constexpr\
    \ static_modint inv() const {\n        if constexpr (std::is_same<T, double>::value)\
    \ {\n            return static_modint(1) / static_modint(value);\n        }\n\
    \        else {\n            int g, x, y;\n            std::tie(g, x, y) = extendedGCD(value,\
    \ MOD);\n            assert(g == 1);\n            if (x < 0) x += MOD;\n     \
    \       return x;\n        }\n    }\n\n    constexpr static_modint& operator/=(const\
    \ static_modint& other) {\n        return *this *= other.inv();\n    }\n\n   \
    \ constexpr static_modint operator/(const static_modint& other) const {\n    \
    \    return static_modint(*this) /= other;\n    }\n\n    constexpr bool operator!=(const\
    \ static_modint& other) const {\n        return val() != other.val();\n    }\n\
    \n    constexpr bool operator==(const static_modint& other) const {\n        return\
    \ val() == other.val();\n    }\n\n    T val() const {\n        if constexpr (std::is_same<T,\
    \ double>::value) {\n            return static_cast<double>(value);\n        }\n\
    \        else return this->value;\n    }\n\n    friend std::ostream& operator<<(std::ostream&\
    \ os, const static_modint& mi) {\n        return os << mi.value;\n    }\n\n  \
    \  friend std::istream& operator>>(std::istream& is, static_modint& mi) {\n  \
    \      long long x;\n        is >> x;\n        mi = static_modint(x);\n      \
    \  return is;\n    }\n};\n\ntemplate <int mod>\nusing modint = static_modint<mod>;\n\
    using modint998244353 = modint<998244353>;\nusing modint1000000007 = modint<1000000007>;\n\
    \n\n#line 1 \"structure/slide-window-aggregation.hpp\"\n\n\n\n#include <vector>\n\
    #include <algorithm>\n\ntemplate <class S, S (*op)(S, S), S (*e)()>\nstruct FoldableDeque\
    \ {\n  struct Node {\n    S val;\n    S prod;\n  };\n\n  std::vector<Node> front,\
    \ back;\n\n  FoldableDeque() : front(), back() {}\n  size_t size() const { return\
    \ front.size() + back.size(); }\n  bool empty() const { return front.size() +\
    \ back.size() == 0; }\n\n\n  // nyaan\u3055\u3093\u306E\u3092\u30D1\u30AF\u3063\
    \u3066\u304A\u308A\n  void rebalance() {\n    int n = front.size() + back.size();\n\
    \    int s0 = n / 2 + (front.empty() ? n % 2 : 0);\n    // front\u306Bs0\u500B\
    \n    // back\u306BN - s0\u500B\u5165\u308C\u308B\n    vector<Node> a{front};\n\
    \    std::reverse(begin(a), end(a));\n    std::copy(begin(back), end(back), back_inserter(a));\n\
    \    front.clear(), back.clear();\n    for (int i = s0 - 1; i >= 0; i--) push_front(a[i].val);\n\
    \    for (int i = s0; i < n; i++) push_back(a[i].val);\n    return;\n  }\n\n \
    \ S all_prod() const {\n    if (front.empty() && back.empty() ) return e();\n\n\
    \    if (front.empty()) {\n      return back.back().prod;\n    }\n    else if\
    \ (back.empty()) {\n      return front.back().prod;\n    }\n\n    else return\
    \ op(front.back().prod, back.back().prod) ;\n  }\n\n  void push_back(const S&\
    \ x) {\n    if (back.empty()) {\n      back.push_back({x, x});\n    }\n    else\
    \ {\n      // \u9806\u5E8F\u602A\u3057\u3044\u304B\u3082\n      back.push_back({x,\
    \ op(back.back().prod, x) });\n    }\n  }\n\n  void push_front(const S& x) {\n\
    \    if (front.empty()) {\n      front.push_back({x, x});\n    }\n    else {\n\
    \      // \u9806\u5E8F\u602A\u3057\u3044\u304B\u3082\n      front.push_back({x,\
    \ op(x, front.back().prod) });\n    }  \n  }\n\n  void pop_back() {\n    assert(size()\
    \ > 0);\n    if (back.empty()) rebalance();\n    back.pop_back();\n  }\n\n  void\
    \ pop_front() {\n    assert(size() > 0);\n    if (front.empty()) rebalance();\n\
    \    front.pop_back();\n  }\n};\n\n#line 1 \"math/linear_function.hpp\"\n\n\n\n\
    template <typename T>\nstruct LinearFunction {\n  T a, b;\n\n  LinearFunction()\
    \ : a{0}, b(0) {}\n  LinearFunction(T _a, T _b) : a(_a), b(_b) {}\n\n  static\
    \ LinearFunction Add_Identity() {\n    return LinearFunction(T(0), T(0));\n  }\n\
    \n  static LinearFunction Mul_Identity(){\n    return LinearFunction(T(1), T(0));\n\
    \  }\n\n  // f(g())\n  LinearFunction composite(LinearFunction& g) const {\n \
    \   return LinearFunction(a * g.a, a * g.b + b);\n  }\n\n  LinearFunction operator+(const\
    \ LinearFunction& rhs) const {\n    return LinearFunction(a + rhs.a, b + rhs.b);\n\
    \  }\n\n  // rhs(f())\n  LinearFunction operator*(const LinearFunction& rhs) const\
    \ {\n    LinearFunction f = *this;\n    return rhs.composite(f);\n  }\n\n  T operator()(T\
    \ x) const {\n    return a * x + b;\n  }\n\n};\n\n\n\n#line 7 \"test/verify/yosupo-queue-operate-all-composite.test.cpp\"\
    \n\nusing mint = modint998244353;\nusing LF = LinearFunction<mint>;\n\n// f_r(f_l)\n\
    LF op(LF lf, LF rf) {\n  return rf.composite(lf);\n}\n\nLF e() {\n  return LF::Mul_Identity();\n\
    }\n\n\nint main() {\n  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);\n  FoldableDeque<LF,op,e>\
    \ fdq;\n\n  int Q; cin >> Q;\n  for(int i=0; i<Q; i++) {\n    int op; cin >> op;\n\
    \    if (op == 0) {\n      int a,b; cin >> a >> b;\n      fdq.push_back({mint(a),\
    \ mint(b)});\n    }\n\n    else if (op == 1) {\n      fdq.pop_front();\n    }\n\
    \    else if (op == 2) {\n      int x; cin >> x;\n      LF all_prod = fdq.all_prod();\n\
    \      cout << all_prod(x).val() << endl;\n    }\n  }\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/queue_operate_all_composite\"\
    \n\n#include \"template/template.hpp\"\n#include \"math/modint.hpp\"\n#include\
    \ \"structure/slide-window-aggregation.hpp\"\n#include \"math/linear_function.hpp\"\
    \n\nusing mint = modint998244353;\nusing LF = LinearFunction<mint>;\n\n// f_r(f_l)\n\
    LF op(LF lf, LF rf) {\n  return rf.composite(lf);\n}\n\nLF e() {\n  return LF::Mul_Identity();\n\
    }\n\n\nint main() {\n  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);\n  FoldableDeque<LF,op,e>\
    \ fdq;\n\n  int Q; cin >> Q;\n  for(int i=0; i<Q; i++) {\n    int op; cin >> op;\n\
    \    if (op == 0) {\n      int a,b; cin >> a >> b;\n      fdq.push_back({mint(a),\
    \ mint(b)});\n    }\n\n    else if (op == 1) {\n      fdq.pop_front();\n    }\n\
    \    else if (op == 2) {\n      int x; cin >> x;\n      LF all_prod = fdq.all_prod();\n\
    \      cout << all_prod(x).val() << endl;\n    }\n  }\n  return 0;\n}"
  dependsOn:
  - template/template.hpp
  - math/modint.hpp
  - math/external_gcd.hpp
  - structure/slide-window-aggregation.hpp
  - math/linear_function.hpp
  isVerificationFile: true
  path: test/verify/yosupo-queue-operate-all-composite.test.cpp
  requiredBy: []
  timestamp: '2025-04-04 21:14:56+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/verify/yosupo-queue-operate-all-composite.test.cpp
layout: document
redirect_from:
- /verify/test/verify/yosupo-queue-operate-all-composite.test.cpp
- /verify/test/verify/yosupo-queue-operate-all-composite.test.cpp.html
title: test/verify/yosupo-queue-operate-all-composite.test.cpp
---
