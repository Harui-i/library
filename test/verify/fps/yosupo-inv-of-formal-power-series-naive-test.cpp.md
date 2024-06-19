---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://judge.yosupo.jp/problem/inv_of_formal_power_series
  bundledCode: "Traceback (most recent call last):\n  File \"/home/runner/.local/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/home/runner/.local/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/home/runner/.local/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/home/runner/.local/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../../template/template.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/inv_of_formal_power_series\"\
    \n\n#include \"../../template/template.hpp\"\n#include \"../../math/modint.hpp\"\
    \n#include \"../../formal-power-series/formal-power-series.hpp\"\n\nusing mint\
    \ = modint998244353;\n\n\nint main() {\n  ios::sync_with_stdio(0); cin.tie(0);\
    \ cout.tie(0);\n  int N; cin >> N;\n  vector<modint998244353>a(N);\n  for(int\
    \ i=0; i<N; i++) cin >> a[i];\n\n  FPS a_fps(a);\n  cout << a_fps.inv_naive(N)\
    \ << endl;\n\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: test/verify/fps/yosupo-inv-of-formal-power-series-naive-test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: test/verify/fps/yosupo-inv-of-formal-power-series-naive-test.cpp
layout: document
redirect_from:
- /library/test/verify/fps/yosupo-inv-of-formal-power-series-naive-test.cpp
- /library/test/verify/fps/yosupo-inv-of-formal-power-series-naive-test.cpp.html
title: test/verify/fps/yosupo-inv-of-formal-power-series-naive-test.cpp
---
