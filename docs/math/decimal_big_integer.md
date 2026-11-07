---
title: decimal_big_integer
documentation_of: //math/decimal_big_integer.hpp
---

10 進文字列の入出力が重い問題向けの符号付き多倍長整数です。

内部は `10^18` 進数で保持し、乗算は `10^6` chunk に展開して NTT + CRT、除算は Burnikel-Ziegler 除算を使っています。小さい入力では Knuth の基数除算にフォールバックします。

## 使い方

```cpp
DecimalBigInteger a, b;
cin >> a >> b;

DecimalBigInteger c = a + b;
DecimalBigInteger d = a - b;
DecimalBigInteger e = a * b;
DecimalBigInteger q = a / b;
DecimalBigInteger r = a % b;
auto [q2, r2] = divmod(a, b);
```

`/` は 0 方向への丸めです。`%` は `a == (a / b) * b + (a % b)` を満たし、余りの符号は被除数と同じです。

`divmod(a, b)` は `{a / b, a % b}` を返します。`b` は 0 以外でなければなりません。整数値・10進文字列から構築でき、ストリーム入出力にも対応します。

## 計算量

`n`, `m` をそれぞれオペランドの $10^{18}$ 進ブロック数とします。

- 加減算: $O(\max(n,m))$
- 乗算: $O(k \log k)$。ここで $k$ は $10^6$ 進チャンク数（ブロック数の定数倍）。
- 除算: Knuth 除算へフォールバックする場合は $O(nm)$。大きな偶数長除数では Burnikel–Ziegler 除算を使う。
