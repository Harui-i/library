---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/count_by_remainder.hpp\"\n\n\n\ntemplate <typename\
    \ T= long long>\n// l\u4EE5\u4E0Ar\u672A\u6E80\u3067\u3001M\u3067\u5272\u3063\u305F\
    \u4F59\u308A\u304Cb\u3067\u3042\u308B\u6574\u6570\u306E\u500B\u6570\u3092\u6C42\
    \u3081\u308B\nT count_by_remainder(T l, T r, T b, T M) {\n  assert(l <= r && 0\
    \ <= b && b < M);\n  r--;\n  T k_min = (l - b + M - 1) / M;\n  if (l - b + M -\
    \ 1 < 0 && (l - b + M - 1) % M != 0) k_min--;\n\n  T k_max = (r - b) / M;\n  if\
    \ (r - b < 0 && (r - b) % M != 0) k_max--;\n\n  T ans = k_max - k_min + 1;\n \
    \ //T mini = k_min * M + b;\n  //T maxi = k_max * M + b;\n\n  return ans;\n}\n\
    \n\n\n"
  code: "#ifndef HARUILIB_MATH_COUNT_BY_REMAINDER_HPP\n#define HARUILIB_MATH_COUNT_BY_REMAINDER_HPP\n\
    \ntemplate <typename T= long long>\n// l\u4EE5\u4E0Ar\u672A\u6E80\u3067\u3001\
    M\u3067\u5272\u3063\u305F\u4F59\u308A\u304Cb\u3067\u3042\u308B\u6574\u6570\u306E\
    \u500B\u6570\u3092\u6C42\u3081\u308B\nT count_by_remainder(T l, T r, T b, T M)\
    \ {\n  assert(l <= r && 0 <= b && b < M);\n  r--;\n  T k_min = (l - b + M - 1)\
    \ / M;\n  if (l - b + M - 1 < 0 && (l - b + M - 1) % M != 0) k_min--;\n\n  T k_max\
    \ = (r - b) / M;\n  if (r - b < 0 && (r - b) % M != 0) k_max--;\n\n  T ans = k_max\
    \ - k_min + 1;\n  //T mini = k_min * M + b;\n  //T maxi = k_max * M + b;\n\n \
    \ return ans;\n}\n\n\n#endif // HARUILIB_MATH_COUNT_BY_REMAINDER_HPP"
  dependsOn: []
  isVerificationFile: false
  path: math/count_by_remainder.hpp
  requiredBy: []
  timestamp: '2024-06-16 15:19:23+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/count_by_remainder.hpp
layout: document
title: count by remainder
---

$L$ 以上 $R$未満であって、$M$で割った余りが$b$である整数の個数を求める。
こんなんソラで書くのは頭バグらせますからね。

## count_by_remainder

```
T count_by_remainder(T l, T r, T b, T M)
```

### 計算量

- $O(1)$

###　実装例

verify先がAtCしかみつからなかったので。

```C++
#include "math/count_by_remainder.hpp"

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  ll A,M,L,R; cin >> A >> M >> L >> R;
  A %= M;
  if (A < 0) A += M;  

  cout << count_by_remainder(L,R+1,A,M) << endl;
  return 0;
}
```


問題:  [https://atcoder.jp/contests/abc334/submissions/54631702] ( https://atcoder.jp/contests/abc334/submissions/54631702 )
