#pragma once

#include "graph/graph_template.hpp"

namespace std {
  template <typename T>
  vector<T> dijkstra(const Graph<T>& graph, int start) {
    int N = (int)graph.size();
    vector<T>dist(N, T(-1));
    using P = pair<T, int>;

    priority_queue<P, vector<P>, greater<P>>que;

    que.push(make_pair(T(0), start));
    dist[start] = T(0);

    while (!que.empty()) {
      P front = que.top(); que.pop();

      if (dist[front.second] < front.first) continue;

      for (Edge ed : graph[front.second]) {

        if (dist[ed.to] == T(-1) || dist[ed.to] > front.first + ed.cost) {
          dist[ed.to] = front.first + ed.cost;
          que.emplace(dist[ed.to], ed.to);
        }
      }
    }

    return dist;
  }
  
  template <typename T>
  pair<vector<T>, vector<int>> dijkstra_path(const Graph<T>& graph, int start) {
    int N = (int)graph.size();

    using P = pair<T, int>;
    vector<T>dist(N, T(-1));
    vector<int>prev(N, -1);

    priority_queue<P, vector<P>, greater<P>>que;
    que.push(make_pair(T(0), start));
    dist[start] = T(0);

    while (!que.empty()) {
      P front = que.top(); que.pop();

      if (dist[front.second] < front.first) continue;

      for (Edge ed: graph[front.second]) {
        if (dist[ed.to] == T(-1) || dist[ed.to] > front.first + ed.cost) {
          dist[ed.to] = front.first + ed.cost;
          prev[ed.to] = front.second;
          que.emplace(dist[ed.to], ed.to);
        }
      }
    }

    return make_pair(dist, prev);  
  }
}
