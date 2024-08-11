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
    links:
    - https://ngtkana.hatenablog.com/entry/2023/12/04/194327
  bundledCode: "#line 1 \"dp/cumulative-sum-2d.hpp\"\n\n\n\n#include <cassert>\n#include\
    \ <vector>\n\ntemplate<class T>\nstruct CumulativeSum2D {\n  bool has_built =\
    \ false;\n  int H, W;\n  std::vector<std::vector<T>> data;\n\n  CumulativeSum2D(int\
    \ _H, int _W)  : H(_H), W(_W), data(std::vector<std::vector<T>>(H+1, std::vector<T>(W+1)))\
    \ {\n  }\n\n  void add (int i, int j, T x) {\n    assert(0 <= i && i < H && 0\
    \ <= j && j < W && !has_built);\n    data[i+1][j+1] += x;\n  }\n\n  // https://ngtkana.hatenablog.com/entry/2023/12/04/194327\n\
    \  // 1B\n  void build() {\n    assert(!has_built);\n    for (int i=1; i<=H; i++)\
    \ {\n      for (int j=1; j<=W; j++) {\n        data[i][j] += data[i-1][j];\n \
    \     }\n    }\n\n    for (int i=1; i<=H; i++) {\n      for (int j=1; j<=W; j++)\
    \ {\n        data[i][j] += data[i][j-1];\n      }\n    }\n\n\n    has_built =\
    \ true;\n  }\n\n  // [si, gi) * [sj, gj)\n  T query(int si, int sj, int gi, int\
    \ gj) {\n    assert(has_built);\n    assert(0 <= si && si < H && 0 <= sj && sj\
    \ < W);\n    assert(0 <= gi && gi <= H && 0 <= gj && gj <= W);\n    assert(si\
    \ <= gi && sj <= gj);\n    return data[gi][gj] - data[si][gj] - data[gi][sj] +\
    \ data[si][sj];\n  }\n};\n\n"
  code: "#ifndef HARUILIB_DP_CUMULATIVE_SUM_2D_HPP\n#define HARUILIB_DP_CUMULATIVE_SUM_2D_HPP\n\
    \n#include <cassert>\n#include <vector>\n\ntemplate<class T>\nstruct CumulativeSum2D\
    \ {\n  bool has_built = false;\n  int H, W;\n  std::vector<std::vector<T>> data;\n\
    \n  CumulativeSum2D(int _H, int _W)  : H(_H), W(_W), data(std::vector<std::vector<T>>(H+1,\
    \ std::vector<T>(W+1))) {\n  }\n\n  void add (int i, int j, T x) {\n    assert(0\
    \ <= i && i < H && 0 <= j && j < W && !has_built);\n    data[i+1][j+1] += x;\n\
    \  }\n\n  // https://ngtkana.hatenablog.com/entry/2023/12/04/194327\n  // 1B\n\
    \  void build() {\n    assert(!has_built);\n    for (int i=1; i<=H; i++) {\n \
    \     for (int j=1; j<=W; j++) {\n        data[i][j] += data[i-1][j];\n      }\n\
    \    }\n\n    for (int i=1; i<=H; i++) {\n      for (int j=1; j<=W; j++) {\n \
    \       data[i][j] += data[i][j-1];\n      }\n    }\n\n\n    has_built = true;\n\
    \  }\n\n  // [si, gi) * [sj, gj)\n  T query(int si, int sj, int gi, int gj) {\n\
    \    assert(has_built);\n    assert(0 <= si && si < H && 0 <= sj && sj < W);\n\
    \    assert(0 <= gi && gi <= H && 0 <= gj && gj <= W);\n    assert(si <= gi &&\
    \ sj <= gj);\n    return data[gi][gj] - data[si][gj] - data[gi][sj] + data[si][sj];\n\
    \  }\n};\n#endif //HARUILIB_DP_CUMULATIVE_SUM_2D_HPP"
  dependsOn: []
  isVerificationFile: false
  path: dp/cumulative-sum-2d.hpp
  requiredBy: []
  timestamp: '2024-08-11 15:34:25+09:00'
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
