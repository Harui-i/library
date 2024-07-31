---
titel : Heavy-Light Decomposition(HL分解, HLD)
documentation_of: //graph/tree/heavy_light_decomposition.hpp
---

木に関する部分木クエリ、パスクエリを処理するためのデータ構造。

## コンストラクタ

```
HLD (int N)
```

`N` :　頂点の数。

(`HLD hld(20);`などして構築したあと、`hld.graph.add_edge(0,1);` などして木の情報を与える。)

## build

```
void build(int root=0)
```
`root`を根とした木のHeavy-Light Decompositionを実行する。


## lca

```cpp
int lca(int u, int v)
```

`u`と`v`の最小共通祖先(LCA)を求める。

## get_path

```cpp
Path get_path(int u, int v)
```

頂点`u`から頂点`v`までのパスを返す。パスはHeavy-Edgeで繋がれた区間(`Interval`)の`vector`として表される。

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

