---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/verify/aoj-0560.test.cpp
    title: test/verify/aoj-0560.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"dp/cumulative-sum-2d.hpp\"\n\ntemplate<class T>\nstruct\
    \ CumulativeSum2D {\n  vector<vector<T>> data;\n  CumulativeSum2D(int H, int W)\
    \  {\n    data.resize(H+1, vector<T>(W+1));\n  }\n\n  void add (int i, int j,\
    \ T x) {\n    assert(0 <= i && i < data.size() && 0 <= j && j < data[0].size()\
    \ );\n    data[i+1][j+1] += x;\n  }\n\n  void build() {\n    for(int i=0; i<data.size()-1;\
    \ i++) {\n      for(int j=0; j<data[0].size()-1; j++) {\n        data[i+1][j+1]\
    \ += data[i][j+1] + data[i+1][j] - data[i][j];\n      }\n    }\n  }\n\n  T query(int\
    \ si, int sj, int gi, int gj) {\n    return data[gi][gj] - data[si][gj] - data[gi][sj]\
    \ + data[si][sj];\n  }\n};\n"
  code: "\ntemplate<class T>\nstruct CumulativeSum2D {\n  vector<vector<T>> data;\n\
    \  CumulativeSum2D(int H, int W)  {\n    data.resize(H+1, vector<T>(W+1));\n \
    \ }\n\n  void add (int i, int j, T x) {\n    assert(0 <= i && i < data.size()\
    \ && 0 <= j && j < data[0].size() );\n    data[i+1][j+1] += x;\n  }\n\n  void\
    \ build() {\n    for(int i=0; i<data.size()-1; i++) {\n      for(int j=0; j<data[0].size()-1;\
    \ j++) {\n        data[i+1][j+1] += data[i][j+1] + data[i+1][j] - data[i][j];\n\
    \      }\n    }\n  }\n\n  T query(int si, int sj, int gi, int gj) {\n    return\
    \ data[gi][gj] - data[si][gj] - data[gi][sj] + data[si][sj];\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: dp/cumulative-sum-2d.hpp
  requiredBy: []
  timestamp: '2024-04-10 18:06:46+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/verify/aoj-0560.test.cpp
documentation_of: dp/cumulative-sum-2d.hpp
layout: document
redirect_from:
- /library/dp/cumulative-sum-2d.hpp
- /library/dp/cumulative-sum-2d.hpp.html
title: dp/cumulative-sum-2d.hpp
---
