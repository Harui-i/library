---
title : Heavy-Light Decomposition(HL分解, HLD)
documentation_of: //graph/tree/heavy_light_decomposition.hpp
---

木に関する部分木クエリ、パスクエリを処理するためのデータ構造。

## 使い方

```
haruilib::HLD hld(N);

for (int i=0; i<N-1; i++) {
  int u, v; cin >> u >> v;
  hld.graph.add_edge(u,v);
  hld.graph.add_edge(v,u);
}

hld.build();
```

みたいに構築したあと、
```
int a,b; cin >> a >> b;
haruilib::Path path = hld.get_path(a,b);

ll sum = 0;
for(haruilib::Interval intv: path) {
  sum += seg.prod(intv.top_id, intv.bottom_id + 1);
}
```
のように、id上でセグ木などの列に対するアルゴリズムを使っていく流れが基本だと思われる。

他にも、

- 辺属性なら子側の頂点に持たせるほうがいい
- 辺属性を考えるときはLCAの頂点に注意する

みたいな色々考えておくことがある。

## コンストラクタ

```
HLD (int N)
```

`N` :　頂点の数。

(`HLD hld(20);`などして構築したあと、`hld.graph.add_edge(0,1);` などして木の情報を与える。)

頂点数は正とし、`graph` には連結な木を無向辺として登録する。コンストラクタは $O(N)$ 時間・空間。

## build

```
void build(int root=0)
```
`root`を根とした木のHeavy-Light Decompositionを実行する。

- 引数: `root` は根の頂点番号（既定値 `0`）。
- 制約: 木を `graph` に設定してから呼び、各頂点について一度だけ呼ぶ。
- 計算量: 時間・追加空間ともに $O(N)$。


## lca

```cpp
int lca(int u, int v)
```

`u`と`v`の最小共通祖先(LCA)を求める。

- 引数: `u`, `v` は頂点番号。
- 戻り値: 最小共通祖先の頂点番号。
- 制約: `build()` の後に呼ぶ。
- 計算量: $O(\log N)$。

## get_path

```cpp
Path get_path(int u, int v)
```

頂点`u`から頂点`v`までのパスを返す。パスはHeavy-Edgeで繋がれた区間(`Interval`)の`vector`として表される。

- 引数: `u`, `v` は頂点番号。
- 制約: `build()` の後に呼ぶ。
- 計算量: $O(\log N)$ 時間・空間（返す区間数も $O(\log N)$）。

ここで、 `using Path = std::vector<Interval>`として定義されていて、`Interval`は

```cpp
struct Interval {
  // top_id : interval のもっとも根に近い頂点のid
  // bottom_id : interval のもっとも葉に近い頂点のid
  // last : LCAを含む interval であるかどうか
  // reverse : from → to と top → bottomが逆向きかどうか
  int top_id, bottom_id;
  bool last;
  bool reverse;

  Interval(int _top_id, int _bottom_id, bool _last, bool _reverse) : top_id(_top_id), bottom_id(_bottom_id), last(_last), reverse(_reverse) {

  }
};
``` 
として定義されている。

## subtree_query

```
std::pair<int,int> subtree_query(int r)
```
   
頂点rの部分木(rも含む)の頂点列を表すid上の区間 $[id[r], id2[r])$ を返す。

- 引数: `r` は頂点番号。
- 制約: `build()` の後に呼ぶ。

### 計算量

- $O(1)$


