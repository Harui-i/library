#pragma once

#include <vector>

namespace std {
  template <typename T>
  struct Edge {
    int from; int to;
    T cost;

    Edge(int _from, int _to, T _cost) : from(_from), to(_to), cost(_cost) {}

    // unweighted
    Edge(int _from, int _to) : from(_from), to(_to), cost(T(1)) {}

  };




  template <typename T>
  struct Graph : vector<vector<Edge<T>>> {

    using vector<vector<Edge<T>>>::vector; // inherit constructors

    void add_edge(int i, Edge<T> e) {
      (*this)[i].push_back(e);
    }

    // weighted
    void add_edge(int _from, int _to, T _cost) {
      (*this)[_from].push_back(Edge(_from, _to, _cost));
    }

    // unweighted
    void add_edge(int _from, int _to) {
      (*this)[_from].push_back(Edge(_from, _to, T(1)));
    }

  };
}
