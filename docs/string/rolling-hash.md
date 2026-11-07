---
title: ローリングハッシュ(Rolling Hash)
documentation_of: //string/rolling-hash.hpp
---

RollingHashを扱う。

文字列Sのハッシュは、$ \Sum_{i=0, 1, \dots |S|} b^i S[i] $とする。

# Hash

文字列のハッシュを表現する。
文字列の長さ、基数、ハッシュの値を持つ。

## コンストラクタ

```
Hash(mint _hash, mint _base, int _len)
```

ハッシュした値が`_hash`で、基数が`_base`であり、その文字列は`_len`の長さであるとしてハッシュを初期化する。

```
operator+(const Hash& rhs) const
```

rhsを文字列として右から結合したあとのHashを返す。
基数が同じであることを要求する。

# RollingHash

文字列のHashを扱う。先頭からのハッシュを管理しておくことで、部分文字列のハッシュ計算なども対応する。

## コンストラクタ

```
RollingHash(const string& S, mint _base): (_base)
```

文字列 `S` の prefix hash を構築する。`_base` はハッシュの基数で、同じ `Hash` 同士の演算では一致している必要がある。構築時間・空間はいずれも $O(|S|)$。

## get

```
Hash get(int l, int r) const
```

$S$の$[l,r)$部分のハッシュを計算する。
制約は $0 \le l \le r \le |S|$。計算量は $O(1)$（固定幅整数演算のモデル）。

## 引数・戻り値

- `Hash(string s, mint base)`: `s` のハッシュを作る。時間 $O(|s|)$、追加領域 $O(1)$。
- `Hash(mint hash, mint base, int len)`: ハッシュ値・基数・長さを指定して作る。
- `Hash + Hash` / `Hash + char`: 文字列として右側へ連結したハッシュを返す。基数が一致すること。
- `get(l, r)`: 部分文字列を表す `Hash` を返す。

使用する法は `modint2611` の $2^{61}-1$。ハッシュ値の衝突可能性があるため、文字列の一致判定を厳密に保証する用途には使えない。

