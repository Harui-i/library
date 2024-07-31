#ifndef HARUILIB_GRAPH_TREE_HEAVY_LIGHT_DECOMPOSITION_HPP
#define HARUILIB_GRAPH_TREE_HEAVY_LIGHT_DECOMPOSITION_HPP

#include <vector>
#include <algorithm>
#include <cassert>
#include <utility>

#include "graph/graph_template.hpp"

// cf : https://ngtkana.hatenablog.com/entry/2024/06/24/200138
struct Interval {
  // i : interval のもっとも根に近い頂点のid
  // j : interval のもっとも葉に近い頂点のid
  // last : LCAを含む interval であるかどうか
  // reverse : from → to と i → jが逆向きかどうか
  int top_id, bottom_id;
  bool last;
  bool reverse;

  Interval(int _top_id, int _bottom_id, bool _last, bool _reverse) : top_id(_top_id), bottom_id(_j), last(_last), reverse(_reverse) {

  }
};

using Path = std::vector<Interval>;

struct HLD {

  //vector<vector<int>>children;
  std::vector<int>parent;
  std::vector<int> id;
  std::vector<int> id2;
  std::vector<int> head;
  std::vector<int>depth;
  Graph<int>graph;

  HLD (int N) : parent(std::vector<int>(N, -1)), id(std::vector<int>(N)), id2(std::vector<int>(N)), head(std::vector<int>(N)), depth(std::vector<int>(N)), graph(N) {}

  void build(int root=0) {
    dfs_sz(root);
    int k = 0; dfs_hld(root, k);
  }

  int dfs_sz(int v) {
    int ret = 1, mx_sz = 0;
    for (Edge<int>& nxt : graph[v]) {
      if (nxt.to == parent[v]) continue;

      parent[nxt.to] = v;
      depth[nxt.to] = depth[v] + 1;
      int sz = dfs_sz(nxt.to);
      ret += sz;
      if (mx_sz < sz) {
        mx_sz = sz;
        std::swap(graph[v][0], nxt);
      }
    }

    return ret;
  }

  void dfs_hld(int v, int& k) {
    id[v] = k; k++;
    for (Edge e : graph[v]) {
      if (e.to == parent[v]) continue;

      head[e.to] = (e == graph[v][0] ? head[v] : e.to);
      dfs_hld(e.to, k);
    }
    id2[v] = k;
  }

  int lca(int u, int v) {
    while (true) {
      if (id[u] > id[v]) std::swap(u, v);
      if (head[u] == head[v]) return u;

      v = parent[head[v]];
    }
  }

  Path get_path(int u, int v) {
    Path upath, vpath;

    while (head[u] != head[v]) {

      // ちなみにu,vのdepthの大小関係は変わり続けることもある。
      // 10 → 12など。

      // v's head is deeper
      if (depth[head[v]] >= depth[head[u]]) {
        assert(depth[head[v]] >= depth[head[u]]);
        /*
          /   : heavy edge
         .... : light edge

            head[u]
               /
              /...
             u  ...
            /   head[v]
           /       \
          /         \
         /           v
        */

        // u→v なのでreverse=false
        vpath.emplace_back(id[head[v]], id[v], false, false);
        v = parent[head[v]];
      }

      // u's head is deeper
      else if (depth[head[v]] < depth[head[u]]) {
        /*
          /   : heavy edge
         .... : light edge

            head[v]
               /
              /...
             v  ...
            /   head[u]
           /       \
          /         \
         /           u
        */

        //
        upath.emplace_back(id[head[u]], id[u], false, true);
        u = parent[head[u]];
      }
    }

    // v is deeper
    /*
       u
      /
     /  ←↓
    /
   v

    */
    if (depth[v] > depth[u]) {
      upath.emplace_back(id[u], id[v], true, false);
    }

    // u is deeper
    /*
       v
      /
     /  →↑
    /
   u

    */
    else {
      upath.emplace_back(id[v], id[u], true, true);
    }
    Path retpath = upath;
    std::reverse(vpath.begin(), vpath.end());
    for (Interval path : vpath) retpath.push_back(path);

    return retpath;
  }

  std::pair<int,int> subtree_query(int r) {
    assert(r < int(id.size()));
    return std::make_pair(id[r], id2[r]);
  }

};

#endif // HARUILIB_GRAPH_TREE_HEAVY_LIGHT_DECOMPOSITION_HPP
