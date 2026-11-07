---
title: modint
documentation_of: //math/modint.hpp
---

なんかうまくやってくれます。生成AIが書いてくれました。

## mod_sqrt

```
long long mod_sqrt(long long a, long long p)
```

$x^2 \equiv a \pmod p$ となる $x$ を1つ返す。存在しない場合は `-1` を返す。

`p` は素数であることを仮定している。

### 引数

- `a`: 平方根を求める値。負値も受け取り、法 `p` で正規化される。
- `p`: 素数。`p > 1`。

戻り値は代表元 $0 \le x < p$ のいずれか。

### 計算量

- `p % 4 == 3` の場合は $O(\log p)$。
- それ以外は Tonelli–Shanks 法に加えて平方非剰余の線形探索を行う。探索回数を $z$ とすると $O(z \log p + (\log p)^2)$。

## static_modint::sqrt

```
long long sqrt_val()
static_modint sqrt()
```

`sqrt_val()` は固定された mod で平方根を求め、存在しない場合は `-1` を返す。

`sqrt()` は平方根が存在することを仮定して `static_modint` で返す。

クラスの法 `MOD` が素数であることを前提とする。`sqrt()` は平方根が存在しない場合に `assert` で停止する。

### 計算量

- `sqrt_val()` / `sqrt()`: `mod_sqrt` と同じ。
