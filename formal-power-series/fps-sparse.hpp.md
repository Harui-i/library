---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: formal-power-series/fiduccia.hpp
    title: "Fiduccia\u306E\u30A2\u30EB\u30B4\u30EA\u30BA\u30E0 (\u304D\u305F\u307E\
      \u3055\u6CD5?)"
  - icon: ':heavy_check_mark:'
    path: formal-power-series/formal-power-series.hpp
    title: "Formal Power Series (\u5F62\u5F0F\u7684\u3079\u304D\u7D1A\u6570)"
  - icon: ':heavy_check_mark:'
    path: formal-power-series/fps-998.hpp
    title: "mod 998244353\u3067\u306EFPS(Formal Power Series, \u5F62\u5F0F\u7684\u3079\
      \u304D\u7D1A\u6570)"
  - icon: ':warning:'
    path: formal-power-series/fps-naive.hpp
    title: formal-power-series/fps-naive.hpp
  - icon: ':warning:'
    path: test/verify/fps/yosupo-inv-of-formal-power-series-naive-test.cpp
    title: test/verify/fps/yosupo-inv-of-formal-power-series-naive-test.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/verify/convolution/yosupo-normal-convolution.test.cpp
    title: test/verify/convolution/yosupo-normal-convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/verify/fps/yosupo-division-of-polynomials.test.cpp
    title: test/verify/fps/yosupo-division-of-polynomials.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/verify/fps/yosupo-exp-of-formal-power-series-sparse.test.cpp
    title: test/verify/fps/yosupo-exp-of-formal-power-series-sparse.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/verify/fps/yosupo-exp-of-formal-power-series-sparse.test.cpp
    title: test/verify/fps/yosupo-exp-of-formal-power-series-sparse.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/verify/fps/yosupo-exp-of-formal-power-series.test.cpp
    title: test/verify/fps/yosupo-exp-of-formal-power-series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/verify/fps/yosupo-inv-of-formal-power-series-fast2.test.cpp
    title: test/verify/fps/yosupo-inv-of-formal-power-series-fast2.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/verify/fps/yosupo-inv-of-formal-power-series-sparse.test.cpp
    title: test/verify/fps/yosupo-inv-of-formal-power-series-sparse.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/verify/fps/yosupo-inv-of-formal-power-series-sparse.test.cpp
    title: test/verify/fps/yosupo-inv-of-formal-power-series-sparse.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/verify/fps/yosupo-kth-term-of-linearly-recurrent-sequence.test.cpp
    title: test/verify/fps/yosupo-kth-term-of-linearly-recurrent-sequence.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/verify/fps/yosupo-log-of-formal-power-series-sparse.test.cpp
    title: test/verify/fps/yosupo-log-of-formal-power-series-sparse.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/verify/fps/yosupo-log-of-formal-power-series-sparse.test.cpp
    title: test/verify/fps/yosupo-log-of-formal-power-series-sparse.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/verify/fps/yosupo-log-of-formal-power-series.test.cpp
    title: test/verify/fps/yosupo-log-of-formal-power-series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/verify/fps/yosupo-pow-of-formal-power-series-sparse.test.cpp
    title: test/verify/fps/yosupo-pow-of-formal-power-series-sparse.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/verify/fps/yosupo-pow-of-formal-power-series-sparse.test.cpp
    title: test/verify/fps/yosupo-pow-of-formal-power-series-sparse.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/verify/fps/yosupo-pow-of-formal-power-series.test.cpp
    title: test/verify/fps/yosupo-pow-of-formal-power-series.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"formal-power-series/fps-sparse.hpp\"\n\n\n\n#include <cassert>\n\
    #include <vector>\n\n// forward decl to avoid circular include: formal-power-series.hpp\
    \ includes this file\ntemplate <typename mint>\nstruct FPS;\n\n// FPS\u306E\u975E\
    \u30BC\u30ED\u306A\u9805\u3092\u96C6\u3081\u305Fvector<pair<int,mint>>\u3092\u8FD4\
    \u3059\ntemplate <typename mint>\nstd::vector<std::pair<int, mint>> get_nonzeros(const\
    \ FPS<mint>& f) {\n  std::vector<std::pair<int, mint>> ret;\n  for (int i = 0;\
    \ i < f.size(); i++) {\n    if (f[i] != mint(0)) ret.emplace_back(i, f[i]);\n\
    \  }\n  return ret;\n}\n\n// \u2193--- inverse of sparse fps ---\u2193\n// calculate\
    \ inverse of f(sparse)\n// deg : -1 + ( maximum degree of g )\ntemplate <typename\
    \ mint>\nFPS<mint> inv_sparse(const std::vector<std::pair<int, mint>>& f, int\
    \ deg) {\n  assert(deg >= 0);\n  for (int i = 0; i < (int)f.size() - 1; i++) assert(f[i].first\
    \ < f[i + 1].first);\n  assert(f[0].first == 0 && f[0].second != mint(0));\n\n\
    \  mint f0inv = f[0].second.inv();\n  std::vector<mint> g(deg);\n  g[0] = f0inv;\n\
    \  for (int i = 0; i < deg - 1; i++) {\n    for (std::pair<int, mint> pim : f)\
    \ {\n      if (i + 1 - pim.first >= 0)\n        g[i + 1] -= pim.second * g[i +\
    \ 1 - pim.first];\n      else\n        continue;\n    }\n    g[i + 1] *= f0inv;\n\
    \  }\n\n  return g;\n}\n\ntemplate <typename mint>\nFPS<mint> inv_sparse(const\
    \ FPS<mint>& f, int deg) {\n  return inv_sparse(get_nonzeros(f), deg);\n}\n\n\
    template <typename mint>\nFPS<mint> FPS<mint>::inv_sparse(int deg) const {\n \
    \ return ::inv_sparse(*this, deg);\n}\n\n// \u2191--- inverse of sparse fps ----\u2191\
    \n\n// exp(f)\u306Edeg\u6B21\u672A\u6E80\u306E\u90E8\u5206\u3092\u6C42\u3081\u308B\
    \u3002\n// F := exp(f) = F_0 + F_1 x + F_2 x^2 + ... \u3068\u3059\u308B\u3002\n\
    // F' = F * f' \u306A\u306E\u3067\n// F_1 + 2F_2 x + 3F_3 x^3 + ... = f' F.\n\
    // 0\u4EE5\u4E0A\u306E\u6574\u6570i\u306B\u3064\u3044\u3066\u3001i\u6B21\u306E\
    \u9805\u306B\u6CE8\u76EE\u3059\u308B\u3068\u3001\n// (i+1) * F_{i+1} = [x^i] (f'\
    \ * F)\n// \u3068\u308F\u304B\u308B\u3002F\u306F0,1,...,i\u6B21\u307E\u3067\u308F\
    \u304B\u3063\u3066\u308C\u3070F_{i+1}\u3082\u308F\u304B\u308B\u3068\u3044\u3046\
    \u3053\u3068\u306B\u306A\u308B\u3002f'\u306F\u30B9\u30D1\u30FC\u30B9\u3060\u304B\
    \u3089F_{i+1}\u306F\u305F\u304B\u3060\u304BK\u56DE\u306E\u8A08\u7B97\u3067\u6C42\
    \u3081\u3089\u308C\u308B.\n\ntemplate <typename mint>\nFPS<mint> exp_sparse(const\
    \ FPS<mint>& f, int deg) {\n  FPS<mint> F(deg);\n  F[0] = mint(1);\n\n  std::vector<std::pair<int,\
    \ mint>> nonzero_fdiff = get_nonzeros(f.diff());\n\n  for (int i = 0; i + 1 <\
    \ deg; i++) {\n    // F[i+1]\u3092\u6C42\u3081\u308B\n    // (i+1) * F_{i+1} =\
    \ [x^i] (f' * F)\n\n    for (std::pair<int, mint> pim : nonzero_fdiff) {\n   \
    \   int a = pim.first;\n      // F\u306Ei-a\u6B21\u306E\u9805\u3092\u8DB3\u3057\
    \u3066\u3044\u304F\n      if (i - a < 0) continue;\n      assert(i - a >= 0);\n\
    \      assert(i + 1 > i - a);\n      F[i + 1] += pim.second * F[i - a];\n    }\n\
    \    F[i + 1] /= mint(i + 1);\n  }\n  return F;\n}\n\ntemplate <typename mint>\n\
    FPS<mint> FPS<mint>::exp_sparse(int deg) const {\n  return ::exp_sparse(*this,\
    \ deg);\n}\n\ntemplate <typename mint>\nFPS<mint> log_sparse(const FPS<mint>&\
    \ f, int deg) {\n  FPS<mint> f_inv = inv_sparse(f, deg);\n  return multiply_sparse(f_inv,\
    \ f.diff(), deg).integral().pre(deg);\n}\n\ntemplate <typename mint>\nFPS<mint>\
    \ FPS<mint>::log_sparse(int deg) const {\n  return ::log_sparse(*this, deg);\n\
    }\n\n// g := f ^ k\n// g' = k * f^{k-1} * f'\n// fg' = k * f^k * f'\n// fg' =\
    \ k * g * f'\n\ntemplate <typename mint>\nFPS<mint> pow_sparse(const FPS<mint>&\
    \ f, long long k, int deg) {\n  if (k == 0) {\n    FPS ret = {mint(1)};\n    ret.resize(deg);\n\
    \    return ret;\n  }\n\n  if (f[0] == mint(0)) {\n    int mindeg = 0;\n    while\
    \ (mindeg < deg && f[mindeg] == mint(0)) mindeg++;\n\n    // (x^{mindeg})^k =\
    \ x^{mindeg * k}\n    // mindeg * k >= deg \u21D4 k >= floor(deg / mindeg) \u3067\
    \u3042\u308B\u3002\n    // \u2192: \u81EA\u660E (k >= deg / mindeg >= floor(deg\
    \ / mindeg) \u306A\u306E\u3067)\n\n    // \u2190\u306B\u3064\u3044\u3066:  h1:\
    \ k >= floor(deg / mindeg) \u3092\u4EEE\u5B9A\u3057\u3066 Goal: k >= deg\u3092\
    \u793A\u3059\u3002\n    // deg = mindeg * q + r (0 <= r < mindeg)\u3068\u8868\u3059\
    \u3002\u3053\u308C\u3092\u4F7F\u3046\u3068\n    // h1: k >= q.\n    // Goal: k\
    \ >= mindeg * q + r.\n\n    // mindeg * k > LLINF\n    // mindeg > LLINF / k\n\
    \    constexpr long long INF = 4450000000011100000;\n    if (mindeg > INF / k\
    \ || mindeg * k >= deg) {\n      FPS<mint> ret(deg);\n      assert(ret[0] == mint(0));\n\
    \      return ret;\n    }\n    return pow_sparse(f >> mindeg, k, deg - mindeg\
    \ * k) << k * mindeg;\n  }\n\n  FPS<mint> g(deg);\n  assert(f[0] != mint(0));\n\
    \  g[0] = f[0].pow(k);\n\n  std::vector<std::pair<int, mint>> nonzero_f = get_nonzeros(f);\n\
    \n  for (int i = 0; i + 1 < deg; i++) {\n    // g[0], g[1], ..., g[i]\u304C\u5224\
    \u3063\u3066\u3044\u308B\u72B6\u614B\u3067,x^i\u306B\u6CE8\u76EE\u3057\u3066g[i+1]\u3092\
    \u6C42\u3081\u306B\u3044\u304F\u3002\n\n    // fg' = (f[0] + f[1]x + f[2]x^2 +\
    \ ... + f[i]x^i)(g[1] + 2g[2]x + 3g[3]x^2 + ... + ig[i]x^{i-1} + (i+1)g[i+1]x^i)\n\
    \    // (\u5DE6) kgf' = k(g[0] + g[1]x + g[2]x^2 + ... + g[i]x^i) * (f[1] + 2*f[2]x\
    \ 3*f[3]x^2 + ... + i*f[i]x^{i-1} +\n    // (i+1)*f[i+1]x^i) (\u53F3)\n\n    //\
    \ \u5DE6\u306Ex^i\u306E\u4FC2\u6570\u306F f[0](i+1)g[i+1] + f[1]ig[i] + f[2](i-1)g[i-1]\
    \ + ... + f[i]g[1]\n    // \u53F3\u306Ex^i\u306E\u4FC2\u6570\u306F k * ( g[0]*(i+1)f[i+1]\
    \ +  g[1]if[i] + ... + g[i]*1f[1])\n\n    // f[0](i+1)g[i+1] = k * (g[0]*(i+1)f[i+1]\
    \ + g[1]if[i] + ... + g[i]*1f[1]) - f[1]ig[i] - f[2](i-1)g[i-1] - ... -\n    //\
    \ f[i]g[1]\n\n    mint sum(0);\n    for (std::pair<int, mint> pim : nonzero_f)\
    \ {\n      // f[pim.first]: pim.second\n      // \u5DE6\u3067\u306F 0 <= pim.first\
    \ <= i\n      // \u53F3\u3067\u306F 1 <= pim.first <= i+1\u306E\u90E8\u5206\u3092\
    \u898B\u308B\n\n      if (0 <= pim.first && pim.first <= i) sum -= pim.second\
    \ * mint(i + 1 - pim.first) * g[i + 1 - pim.first];\n      if (1 <= pim.first\
    \ && pim.first <= i + 1) sum += mint(k) * g[i + 1 - pim.first] * mint(pim.first)\
    \ * pim.second;\n    }\n\n    // for (int j=0; j<=i; j++) sum += mint(k) * g[j]\
    \ * mint(i+1-j) * f[i+1-j];\n    // for (int j=1; j<=i; j++) sum -= f[j] * mint(i+1-j)\
    \ * g[i+1-j];\n\n    g[i + 1] = sum / f[0] / mint(i + 1);\n  }\n\n  return g;\n\
    }\n\ntemplate <typename mint>\nFPS<mint> FPS<mint>::pow_sparse(long long k, int\
    \ deg) const {\n  return ::pow_sparse(*this, k, deg);\n}\n\n// tabun baggute masu.\n\
    template <typename mint>\nFPS<mint> multiply_sparse(const FPS<mint>& f, const\
    \ std::vector<std::pair<int, mint>>& g, int deg = -1) {\n  if (deg == -1) deg\
    \ = f.size() - 1 + g.back().first + 1;\n\n  FPS<mint> ret(deg);\n  for (std::pair<int,\
    \ mint> pim : g) {\n    assert(pim.second != 0);\n    if (pim.second == 0) continue;\n\
    \n    for (int i = 0; i < f.size(); i++) {\n      if (i + pim.first >= ret.size())\
    \ continue;\n      if (f[i] != mint(0) && pim.second != mint(0)) ret[i + pim.first]\
    \ += pim.second * f[i];\n    }\n  }\n\n  return ret;\n}\n\ntemplate <typename\
    \ mint>\nFPS<mint> multiply_sparse(const FPS<mint>& f, const FPS<mint>& g, int\
    \ deg = -1) {\n  std::vector<std::pair<int, mint>> vpmi;\n\n  for (int i = 0;\
    \ i < g.size(); i++)\n    if (g[i] != mint(0)) vpmi.emplace_back(i, g[i]);\n\n\
    \  return multiply_sparse(f, vpmi, deg);\n}\n\ntemplate <typename mint>\nFPS<mint>\
    \ FPS<mint>::mul_sparse(const FPS<mint>& g, int deg) const {\n  return multiply_sparse(*this,\
    \ g, deg);\n}\n\n\n"
  code: "#ifndef HARUILIB_FORMAL_POWER_SERIES_SPARSE_FPS_HPP\n#define HARUILIB_FORMAL_POWER_SERIES_SPARSE_FPS_HPP\n\
    \n#include <cassert>\n#include <vector>\n\n// forward decl to avoid circular include:\
    \ formal-power-series.hpp includes this file\ntemplate <typename mint>\nstruct\
    \ FPS;\n\n// FPS\u306E\u975E\u30BC\u30ED\u306A\u9805\u3092\u96C6\u3081\u305Fvector<pair<int,mint>>\u3092\
    \u8FD4\u3059\ntemplate <typename mint>\nstd::vector<std::pair<int, mint>> get_nonzeros(const\
    \ FPS<mint>& f) {\n  std::vector<std::pair<int, mint>> ret;\n  for (int i = 0;\
    \ i < f.size(); i++) {\n    if (f[i] != mint(0)) ret.emplace_back(i, f[i]);\n\
    \  }\n  return ret;\n}\n\n// \u2193--- inverse of sparse fps ---\u2193\n// calculate\
    \ inverse of f(sparse)\n// deg : -1 + ( maximum degree of g )\ntemplate <typename\
    \ mint>\nFPS<mint> inv_sparse(const std::vector<std::pair<int, mint>>& f, int\
    \ deg) {\n  assert(deg >= 0);\n  for (int i = 0; i < (int)f.size() - 1; i++) assert(f[i].first\
    \ < f[i + 1].first);\n  assert(f[0].first == 0 && f[0].second != mint(0));\n\n\
    \  mint f0inv = f[0].second.inv();\n  std::vector<mint> g(deg);\n  g[0] = f0inv;\n\
    \  for (int i = 0; i < deg - 1; i++) {\n    for (std::pair<int, mint> pim : f)\
    \ {\n      if (i + 1 - pim.first >= 0)\n        g[i + 1] -= pim.second * g[i +\
    \ 1 - pim.first];\n      else\n        continue;\n    }\n    g[i + 1] *= f0inv;\n\
    \  }\n\n  return g;\n}\n\ntemplate <typename mint>\nFPS<mint> inv_sparse(const\
    \ FPS<mint>& f, int deg) {\n  return inv_sparse(get_nonzeros(f), deg);\n}\n\n\
    template <typename mint>\nFPS<mint> FPS<mint>::inv_sparse(int deg) const {\n \
    \ return ::inv_sparse(*this, deg);\n}\n\n// \u2191--- inverse of sparse fps ----\u2191\
    \n\n// exp(f)\u306Edeg\u6B21\u672A\u6E80\u306E\u90E8\u5206\u3092\u6C42\u3081\u308B\
    \u3002\n// F := exp(f) = F_0 + F_1 x + F_2 x^2 + ... \u3068\u3059\u308B\u3002\n\
    // F' = F * f' \u306A\u306E\u3067\n// F_1 + 2F_2 x + 3F_3 x^3 + ... = f' F.\n\
    // 0\u4EE5\u4E0A\u306E\u6574\u6570i\u306B\u3064\u3044\u3066\u3001i\u6B21\u306E\
    \u9805\u306B\u6CE8\u76EE\u3059\u308B\u3068\u3001\n// (i+1) * F_{i+1} = [x^i] (f'\
    \ * F)\n// \u3068\u308F\u304B\u308B\u3002F\u306F0,1,...,i\u6B21\u307E\u3067\u308F\
    \u304B\u3063\u3066\u308C\u3070F_{i+1}\u3082\u308F\u304B\u308B\u3068\u3044\u3046\
    \u3053\u3068\u306B\u306A\u308B\u3002f'\u306F\u30B9\u30D1\u30FC\u30B9\u3060\u304B\
    \u3089F_{i+1}\u306F\u305F\u304B\u3060\u304BK\u56DE\u306E\u8A08\u7B97\u3067\u6C42\
    \u3081\u3089\u308C\u308B.\n\ntemplate <typename mint>\nFPS<mint> exp_sparse(const\
    \ FPS<mint>& f, int deg) {\n  FPS<mint> F(deg);\n  F[0] = mint(1);\n\n  std::vector<std::pair<int,\
    \ mint>> nonzero_fdiff = get_nonzeros(f.diff());\n\n  for (int i = 0; i + 1 <\
    \ deg; i++) {\n    // F[i+1]\u3092\u6C42\u3081\u308B\n    // (i+1) * F_{i+1} =\
    \ [x^i] (f' * F)\n\n    for (std::pair<int, mint> pim : nonzero_fdiff) {\n   \
    \   int a = pim.first;\n      // F\u306Ei-a\u6B21\u306E\u9805\u3092\u8DB3\u3057\
    \u3066\u3044\u304F\n      if (i - a < 0) continue;\n      assert(i - a >= 0);\n\
    \      assert(i + 1 > i - a);\n      F[i + 1] += pim.second * F[i - a];\n    }\n\
    \    F[i + 1] /= mint(i + 1);\n  }\n  return F;\n}\n\ntemplate <typename mint>\n\
    FPS<mint> FPS<mint>::exp_sparse(int deg) const {\n  return ::exp_sparse(*this,\
    \ deg);\n}\n\ntemplate <typename mint>\nFPS<mint> log_sparse(const FPS<mint>&\
    \ f, int deg) {\n  FPS<mint> f_inv = inv_sparse(f, deg);\n  return multiply_sparse(f_inv,\
    \ f.diff(), deg).integral().pre(deg);\n}\n\ntemplate <typename mint>\nFPS<mint>\
    \ FPS<mint>::log_sparse(int deg) const {\n  return ::log_sparse(*this, deg);\n\
    }\n\n// g := f ^ k\n// g' = k * f^{k-1} * f'\n// fg' = k * f^k * f'\n// fg' =\
    \ k * g * f'\n\ntemplate <typename mint>\nFPS<mint> pow_sparse(const FPS<mint>&\
    \ f, long long k, int deg) {\n  if (k == 0) {\n    FPS ret = {mint(1)};\n    ret.resize(deg);\n\
    \    return ret;\n  }\n\n  if (f[0] == mint(0)) {\n    int mindeg = 0;\n    while\
    \ (mindeg < deg && f[mindeg] == mint(0)) mindeg++;\n\n    // (x^{mindeg})^k =\
    \ x^{mindeg * k}\n    // mindeg * k >= deg \u21D4 k >= floor(deg / mindeg) \u3067\
    \u3042\u308B\u3002\n    // \u2192: \u81EA\u660E (k >= deg / mindeg >= floor(deg\
    \ / mindeg) \u306A\u306E\u3067)\n\n    // \u2190\u306B\u3064\u3044\u3066:  h1:\
    \ k >= floor(deg / mindeg) \u3092\u4EEE\u5B9A\u3057\u3066 Goal: k >= deg\u3092\
    \u793A\u3059\u3002\n    // deg = mindeg * q + r (0 <= r < mindeg)\u3068\u8868\u3059\
    \u3002\u3053\u308C\u3092\u4F7F\u3046\u3068\n    // h1: k >= q.\n    // Goal: k\
    \ >= mindeg * q + r.\n\n    // mindeg * k > LLINF\n    // mindeg > LLINF / k\n\
    \    constexpr long long INF = 4450000000011100000;\n    if (mindeg > INF / k\
    \ || mindeg * k >= deg) {\n      FPS<mint> ret(deg);\n      assert(ret[0] == mint(0));\n\
    \      return ret;\n    }\n    return pow_sparse(f >> mindeg, k, deg - mindeg\
    \ * k) << k * mindeg;\n  }\n\n  FPS<mint> g(deg);\n  assert(f[0] != mint(0));\n\
    \  g[0] = f[0].pow(k);\n\n  std::vector<std::pair<int, mint>> nonzero_f = get_nonzeros(f);\n\
    \n  for (int i = 0; i + 1 < deg; i++) {\n    // g[0], g[1], ..., g[i]\u304C\u5224\
    \u3063\u3066\u3044\u308B\u72B6\u614B\u3067,x^i\u306B\u6CE8\u76EE\u3057\u3066g[i+1]\u3092\
    \u6C42\u3081\u306B\u3044\u304F\u3002\n\n    // fg' = (f[0] + f[1]x + f[2]x^2 +\
    \ ... + f[i]x^i)(g[1] + 2g[2]x + 3g[3]x^2 + ... + ig[i]x^{i-1} + (i+1)g[i+1]x^i)\n\
    \    // (\u5DE6) kgf' = k(g[0] + g[1]x + g[2]x^2 + ... + g[i]x^i) * (f[1] + 2*f[2]x\
    \ 3*f[3]x^2 + ... + i*f[i]x^{i-1} +\n    // (i+1)*f[i+1]x^i) (\u53F3)\n\n    //\
    \ \u5DE6\u306Ex^i\u306E\u4FC2\u6570\u306F f[0](i+1)g[i+1] + f[1]ig[i] + f[2](i-1)g[i-1]\
    \ + ... + f[i]g[1]\n    // \u53F3\u306Ex^i\u306E\u4FC2\u6570\u306F k * ( g[0]*(i+1)f[i+1]\
    \ +  g[1]if[i] + ... + g[i]*1f[1])\n\n    // f[0](i+1)g[i+1] = k * (g[0]*(i+1)f[i+1]\
    \ + g[1]if[i] + ... + g[i]*1f[1]) - f[1]ig[i] - f[2](i-1)g[i-1] - ... -\n    //\
    \ f[i]g[1]\n\n    mint sum(0);\n    for (std::pair<int, mint> pim : nonzero_f)\
    \ {\n      // f[pim.first]: pim.second\n      // \u5DE6\u3067\u306F 0 <= pim.first\
    \ <= i\n      // \u53F3\u3067\u306F 1 <= pim.first <= i+1\u306E\u90E8\u5206\u3092\
    \u898B\u308B\n\n      if (0 <= pim.first && pim.first <= i) sum -= pim.second\
    \ * mint(i + 1 - pim.first) * g[i + 1 - pim.first];\n      if (1 <= pim.first\
    \ && pim.first <= i + 1) sum += mint(k) * g[i + 1 - pim.first] * mint(pim.first)\
    \ * pim.second;\n    }\n\n    // for (int j=0; j<=i; j++) sum += mint(k) * g[j]\
    \ * mint(i+1-j) * f[i+1-j];\n    // for (int j=1; j<=i; j++) sum -= f[j] * mint(i+1-j)\
    \ * g[i+1-j];\n\n    g[i + 1] = sum / f[0] / mint(i + 1);\n  }\n\n  return g;\n\
    }\n\ntemplate <typename mint>\nFPS<mint> FPS<mint>::pow_sparse(long long k, int\
    \ deg) const {\n  return ::pow_sparse(*this, k, deg);\n}\n\n// tabun baggute masu.\n\
    template <typename mint>\nFPS<mint> multiply_sparse(const FPS<mint>& f, const\
    \ std::vector<std::pair<int, mint>>& g, int deg = -1) {\n  if (deg == -1) deg\
    \ = f.size() - 1 + g.back().first + 1;\n\n  FPS<mint> ret(deg);\n  for (std::pair<int,\
    \ mint> pim : g) {\n    assert(pim.second != 0);\n    if (pim.second == 0) continue;\n\
    \n    for (int i = 0; i < f.size(); i++) {\n      if (i + pim.first >= ret.size())\
    \ continue;\n      if (f[i] != mint(0) && pim.second != mint(0)) ret[i + pim.first]\
    \ += pim.second * f[i];\n    }\n  }\n\n  return ret;\n}\n\ntemplate <typename\
    \ mint>\nFPS<mint> multiply_sparse(const FPS<mint>& f, const FPS<mint>& g, int\
    \ deg = -1) {\n  std::vector<std::pair<int, mint>> vpmi;\n\n  for (int i = 0;\
    \ i < g.size(); i++)\n    if (g[i] != mint(0)) vpmi.emplace_back(i, g[i]);\n\n\
    \  return multiply_sparse(f, vpmi, deg);\n}\n\ntemplate <typename mint>\nFPS<mint>\
    \ FPS<mint>::mul_sparse(const FPS<mint>& g, int deg) const {\n  return multiply_sparse(*this,\
    \ g, deg);\n}\n\n#endif  // HARUILIB_FORMAL_POWER_SERIES_SPARSE_FPS_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: formal-power-series/fps-sparse.hpp
  requiredBy:
  - formal-power-series/fiduccia.hpp
  - formal-power-series/formal-power-series.hpp
  - formal-power-series/fps-998.hpp
  - formal-power-series/fps-naive.hpp
  - test/verify/fps/yosupo-inv-of-formal-power-series-naive-test.cpp
  timestamp: '2025-11-05 12:09:20+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/verify/fps/yosupo-division-of-polynomials.test.cpp
  - test/verify/fps/yosupo-kth-term-of-linearly-recurrent-sequence.test.cpp
  - test/verify/fps/yosupo-inv-of-formal-power-series-sparse.test.cpp
  - test/verify/fps/yosupo-inv-of-formal-power-series-sparse.test.cpp
  - test/verify/fps/yosupo-exp-of-formal-power-series.test.cpp
  - test/verify/fps/yosupo-log-of-formal-power-series-sparse.test.cpp
  - test/verify/fps/yosupo-log-of-formal-power-series-sparse.test.cpp
  - test/verify/fps/yosupo-exp-of-formal-power-series-sparse.test.cpp
  - test/verify/fps/yosupo-exp-of-formal-power-series-sparse.test.cpp
  - test/verify/fps/yosupo-pow-of-formal-power-series-sparse.test.cpp
  - test/verify/fps/yosupo-pow-of-formal-power-series-sparse.test.cpp
  - test/verify/fps/yosupo-log-of-formal-power-series.test.cpp
  - test/verify/fps/yosupo-inv-of-formal-power-series-fast2.test.cpp
  - test/verify/fps/yosupo-pow-of-formal-power-series.test.cpp
  - test/verify/convolution/yosupo-normal-convolution.test.cpp
documentation_of: formal-power-series/fps-sparse.hpp
layout: document
title: "fps-sparse(\u758E\u306A\u5834\u5408\u306E\u9AD8\u901F\u5316)"
---

スパース(非0な項が多い)な形式的べき級数で効率的に計算する。

## inv_sparse
スパースな形式的べき級数の逆元を効率的(?)に計算する。
定数項は0でないことを要求する。

↓非ゼロな項のpairを与えるときに使う
```cpp
FPS inv_sparse(const vector<pair<int,mint>>& f, int deg)
```

↓普通にFPSを与えるとき
```cpp
FPS inv_sparse(const FPS& f, int deg)
// または
f.inv_sparse(deg)
```

### 計算量
非0な項の数を $K$、先頭の$N$項を求めるとして
- $O(NK)$

### 原理
そんなに難しくないけど、忘れてしまったときのために一応書いておく。

$g := f^{-1}$ として、$g$の$i$項目まで計算できているとする。

ここで、畳み込みの定義と逆元の定義から、
$g[i+1]f[0] + g[i] f[1] + \dots + g[1] f[i] + g[0] f[i+1] = 0$。変形して

$g[i+1] =  - \frac{g[i] f[1] + g[i-1] f[2] + \dots + g[1] f[i] + g[0] f[i+1] }{f[0]} $　ここで、$f$はスパースだから、非ゼロな項は$K$個以下。よって$g[i+1]$を$O(K)$で求められる。これを$O(N)$回繰り返すから、全体で$O(NK)$で求められる。


## exp_sparse
```cpp
FPS<mint> exp_sparse(const FPS<mint>& f, int deg)
// または
f.exp_sparse(deg)
```

### 計算量
- $O(NK)$

### 原理
$f = f[0] + f[1] x + f[2] x^2 + \dots$
$F := \exp(f) = F[0] + F[1] x^1 + \dots$
としておく。

$F' = F * f'$なので
$F[1] + 2F[2] x + 3F[3] x^3 + \dots = f'(F[0] + F[1] x + F[2] x^2 + \dots)$
$F[0], F[1], \dots , F[i]$はわかっているとする。
両辺の$i$次の項に注目すると、左辺は$(i+1)F[i+1]$、右辺は $f' * F$の$i$次の部分。これらは今までにわかっている数値から$O(K)$回の計算で計算できるので、
それを$N-1$次まで計算することで、$O(NK)$で計算できる

## log_sparse
```cpp
FPS<mint> log_sparse(const FPS<mint>& f, int deg)
// または
f.log_sparse(deg)
```

### 計算量
- $O(NK)$

### 原理
$\log(f) = \int (f' / f) dx$ を利用する。$f$がスパースでも$f^{-1}$はスパースとは限らないので、愚直に$f^{-1}$を計算すると$O(N \log N)$かかる。
しかし、$f^{-1}$と$f'$の積は、$f'$がスパースなので、$O(NK)$で計算できる。

## pow_sparse
```cpp
FPS<mint> pow_sparse(const FPS<mint>& f, long long k, int deg)
// または
f.pow_sparse(k, deg)
```

### 計算量
- $O(NK)$

### 原理
$g = f^k$ とすると、$g' = k f^{k-1} f' = k g f^{-1} f'$ となる。
$g' f = k g f'$ の両辺の係数を比較することで、$g$ の各係数を $O(K)$ で求めることができる。

## multiply_sparse
```cpp
FPS<mint> multiply_sparse(const FPS<mint>& f, const FPS<mint>& g, int deg = -1)
// または
f.mul_sparse(g, deg)
```

### 計算量
$f$ の非ゼロ項数を $K_f$, $g$ の非ゼロ項数を $K_g$ として、
- $O(N K_g)$ または $O(M K_f)$ (N, Mは次数)