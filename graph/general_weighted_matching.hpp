#ifndef HARUILIB_GRAPH_GENERAL_WEIGHTED_MATCHING_HPP
#define HARUILIB_GRAPH_GENERAL_WEIGHTED_MATCHING_HPP

#include <algorithm>
#include <array>
#include <functional>
#include <limits>
#include <numeric>
#include <utility>
#include <vector>

namespace mylib {

struct GeneralWeightedMatching {
  int n;
  std::vector<std::vector<long long>> w;

  explicit GeneralWeightedMatching(int n_) : n(n_), w(n_, std::vector<long long>(n_, 0)) {}

  void add_edge(int u, int v, long long cost) {
    if (u == v) return;
    if (w[u][v] < cost) w[u][v] = w[v][u] = cost;
  }

  std::pair<long long, std::vector<int>> solve() const {
    if (n == 0) return {0, {}};
    int N = n;
    int S = N + 1;

    std::vector<std::vector<long long>> g(N + 1, std::vector<long long>(N + 1, 0));
    for (int i = 1; i <= N; i++) {
      for (int j = 1; j <= N; j++) {
        g[i][j] = w[i - 1][j - 1];
      }
    }

    std::vector<int> match(N + 1, 0), slackx(N + 1), prev(N + 1), st(N + 1), pa(N + 1);
    std::vector<long long> lab(N + 1), slack(N + 1);
    std::vector<std::vector<int>> flower_from(N + 1, std::vector<int>(N + 1, 0));
    std::vector<std::vector<int>> flower(N + 1);
    std::vector<std::array<int, 2>> q(2 * N + 5);
    std::vector<int> Sstate(N + 1), vis(N + 1);
    int qh = 0, qt = 0;

    auto dist = [&](int u, int v) {
      return lab[u] + lab[v] - g[u][v] * 2;
    };

    auto update_slack = [&](int u, int x) {
      if (!slack[x] || dist(u, x) < dist(slackx[x], x)) {
        slack[x] = dist(u, x);
        slackx[x] = u;
      }
    };

    auto set_slack = [&](int x) {
      slack[x] = 0;
      for (int u = 1; u <= N; u++) {
        if (Sstate[st[u]] == 0 && st[u] != x && g[u][x] > 0) update_slack(u, x);
      }
    };

    auto q_push = [&](int x) {
      if (x <= N) q[qt++] = {x, 0};
      else for (int v : flower[x]) q[qt++] = {v, x};
    };

    std::function<void(int, int)> set_st = [&](int x, int b) {
      st[x] = b;
      if (x > N) {
        for (int v : flower[x]) set_st(v, b);
      }
    };

    auto get_pr = [&](int b, int xr) {
      int pr = std::find(flower[b].begin(), flower[b].end(), xr) - flower[b].begin();
      if (pr % 2 == 1) {
        std::reverse(flower[b].begin() + 1, flower[b].end());
        return (int)flower[b].size() - pr;
      }
      return pr;
    };

    std::function<void(int, int, int)> set_match = [&](int u, int v, int from) {
      match[u] = v;
      if (u <= N) return;
      int xr = flower_from[u][g[st[u]][st[v]] == 0 ? v : from];
      int pr = get_pr(u, xr);
      for (int i = 0; i < pr; i++) {
        set_match(flower[u][i], flower[u][i ^ 1], from);
      }
      set_match(xr, v, from);
      std::rotate(flower[u].begin(), flower[u].begin() + pr, flower[u].end());
    };

    std::function<void(int)> augment = [&](int u) {
      while (u) {
        int v = st[pa[u]];
        int wv = st[match[v]];
        set_match(u, v, 0);
        u = wv;
      }
    };

    std::function<int(int, int)> lca = [&](int u, int v) {
      std::fill(vis.begin(), vis.end(), 0);
      while (u || v) {
        if (u) {
          if (vis[u] == 1) return u;
          vis[u] = 1;
          if (match[u]) u = st[pa[match[u]]];
          else u = 0;
        }
        std::swap(u, v);
      }
      return 0;
    };

    auto add_blossom = [&](int u, int l, int v) {
      int b = N + 1;
      while (b <= S && st[b]) b++;
      if (b > S) return;
      lab[b] = 0;
      Sstate[b] = -1;
      match[b] = match[l];
      flower[b].clear();
      flower[b].push_back(l);
      for (int x = u, y; x != l; x = st[pa[y]]) {
        flower[b].push_back(x);
        y = st[match[x]];
        flower[b].push_back(y);
        q_push(y);
      }
      std::reverse(flower[b].begin() + 1, flower[b].end());
      for (int x = v, y; x != l; x = st[pa[y]]) {
        flower[b].push_back(x);
        y = st[match[x]];
        flower[b].push_back(y);
        q_push(y);
      }
      set_st(b, b);

      for (int x = 1; x <= S; x++) {
        g[b][x] = g[x][b] = 0;
      }
      for (int x = 1; x <= N; x++) flower_from[b][x] = 0;

      for (int x : flower[b]) {
        for (int y = 1; y <= S; y++) {
          if (g[b][y] < g[x][y]) {
            g[b][y] = g[x][y];
            g[y][b] = g[y][x];
          }
        }
      }

      for (int x : flower[b]) {
        for (int y = 1; y <= S; y++) {
          if (g[x][y] == g[b][y] && flower_from[b][y] == 0) flower_from[b][y] = x;
        }
      }

      set_slack(b);
    };

    auto expand_blossom = [&](int b) {
      for (int x : flower[b]) set_st(x, x);
      int xr = flower_from[b][g[b][pa[b]] == 0 ? pa[b] : match[b]];
      int pr = get_pr(b, xr);
      for (int i = 0; i < pr; i += 2) {
        int xs = flower[b][i], xns = flower[b][i + 1];
        pa[xs] = g[xns][xs] == 0 ? xns : pa[b];
        Sstate[xs] = 1;
        Sstate[xns] = 0;
        slack[xs] = 0;
        set_slack(xns);
        q_push(xns);
      }
      Sstate[xr] = 1;
      pa[xr] = pa[b];
      for (int i = pr + 1; i < (int)flower[b].size(); i++) {
        int x = flower[b][i];
        Sstate[x] = -1;
        set_slack(x);
      }
      st[b] = 0;
    };

    auto on_found_edge = [&](int u, int v) {
      int su = st[u], sv = st[v];
      if (Sstate[sv] == -1) {
        pa[sv] = u;
        Sstate[sv] = 1;
        int nu = st[match[sv]];
        slack[sv] = slack[nu] = 0;
        Sstate[nu] = 0;
        q_push(nu);
      } else if (Sstate[sv] == 0) {
        int l = lca(su, sv);
        if (l == 0) {
          augment(su);
          augment(sv);
          return true;
        } else {
          add_blossom(su, l, sv);
        }
      }
      return false;
    };

    auto matching = [&]() {
      std::fill(Sstate.begin(), Sstate.end(), -1);
      std::fill(slack.begin(), slack.end(), 0);
      qh = qt = 0;

      for (int x = 1; x <= S; x++) {
        if (st[x] == x && !match[x]) {
          pa[x] = 0;
          Sstate[x] = 0;
          q_push(x);
        }
      }
      if (qt == 0) return false;

      while (true) {
        while (qh < qt) {
          int u = q[qh++][0];
          if (Sstate[st[u]] == 1) continue;
          for (int v = 1; v <= N; v++) {
            if (g[u][v] > 0 && st[u] != st[v] && Sstate[st[v]] != 1 && dist(u, v) == 0) {
              if (on_found_edge(u, v)) return true;
            }
          }
        }

        long long d = std::numeric_limits<long long>::max();
        for (int b = N + 1; b <= S; b++) {
          if (st[b] == b && Sstate[st[b]] == 1) d = std::min(d, lab[b] / 2);
        }
        for (int x = 1; x <= S; x++) {
          if (st[x] == x && slack[x] > 0) {
            if (Sstate[x] == -1) d = std::min(d, slack[x]);
            else if (Sstate[x] == 0) d = std::min(d, slack[x] / 2);
          }
        }
        if (d == std::numeric_limits<long long>::max()) return false;

        for (int x = 1; x <= N; x++) {
          if (Sstate[st[x]] == 0) {
            if (lab[x] <= d) return false;
            lab[x] -= d;
          } else if (Sstate[st[x]] == 1) {
            lab[x] += d;
          }
        }
        for (int b = N + 1; b <= S; b++) {
          if (st[b] == b) {
            if (Sstate[st[b]] == 0) lab[b] += d * 2;
            else if (Sstate[st[b]] == 1) lab[b] -= d * 2;
          }
        }

        qh = qt = 0;
        for (int x = 1; x <= S; x++) {
          if (st[x] == x && slack[x] > 0 && st[slackx[x]] != x && dist(slackx[x], x) == 0) {
            if (on_found_edge(slackx[x], x)) return true;
          }
        }
        for (int b = N + 1; b <= S; b++) {
          if (st[b] == b && Sstate[b] == 1 && lab[b] == 0) expand_blossom(b);
        }
      }
    };

    for (int i = 1; i <= S; i++) {
      st[i] = i;
      flower[i].clear();
    }

    long long mx = 0;
    for (int i = 1; i <= N; i++) {
      for (int j = 1; j <= N; j++) mx = std::max(mx, g[i][j]);
    }
    for (int i = 1; i <= N; i++) lab[i] = mx;

    int nmatch = 0;
    while (matching()) nmatch++;

    std::vector<int> mate(n, -1);
    long long total = 0;
    for (int i = 1; i <= N; i++) {
      if (match[i] && match[i] <= N) {
        mate[i - 1] = match[i] - 1;
      }
    }
    for (int i = 0; i < n; i++) if (mate[i] > i) total += w[i][mate[i]];
    return {total, mate};
  }
};

} // namespace mylib

#endif
