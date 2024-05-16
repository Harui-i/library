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
title: "Cumulative Sum 2D (\u4E8C\u6B21\u5143\u7D2F\u7A4D\u548C)"
---

## コンストラクタ

```
CumulativeSum2D< T >(int H, int W)
```
1. サイズ$H$ * $W$ の二次元グリッドを作成する。

### 計算量
- $O(1)$

## add
```
void add(int i, int j, T x)
```

座標 $(i,j)$に$x$を加算する。

### 制約
- $0 \leq i \lt H, 0 \leq j \lt W $ 
(だけどassertしてません。したほうがいいね)

### 計算量
- O(1)

## build
```
void build()
```
二次元累積和を計算する。
### 計算量
- $O(1)$

## query
```
T query(int si, int sj, int gi, int gj)
```

直積(?) $[si, gi) \times [sj, gj)の区間和を求める (0-indexed)。

### 制約
- $0 \leq si \lt H $
- $0 \leq sj \lt W $
- $0 \leq gi \leq H $
- $0 \leq gj \leq W $  
- `build()`が呼ばれた後に呼ばれる必要がある

(だけどassertしてません。したほうがいいね)


### 計算量
- $O(1)$
