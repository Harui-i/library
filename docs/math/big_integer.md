---
title: big_integer
documentation_of: //math/big_integer.hpp
---

符号付き多倍長整数です。

内部は `2^32` 進数で保持し、乗算は NTT + CRT、除算は Knuth の基数除算を使っています。

## 使い方

```cpp
BigInteger a, b;
cin >> a >> b;

BigInteger c = a + b;
BigInteger d = a - b;
BigInteger e = a * b;
BigInteger q = a / b;
BigInteger r = a % b;
auto [q2, r2] = divmod(a, b);
```

`/` は 0 方向への丸めです。`%` は `a == (a / b) * b + (a % b)` を満たし、余りの符号は被除数と同じです。

## 計算量

`n`, `m` をそれぞれオペランドの $2^{32}$ 進ブロック数とします。

- 加減算: `O(n)`
- 乗算: `O(n log n)`
- 除算: `O(nm)`（Knuth の基数除算。`n`, `m` は被除数・除数のブロック数）

`divmod(a, b)` は `{a / b, a % b}` を返す。`b` は 0 以外でなければならない。整数値・10進文字列から構築でき、ストリーム入出力にも対応する。
