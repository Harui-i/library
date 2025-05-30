#define PROBLEM "https://judge.yosupo.jp/problem/vertex_set_path_composite"
#include "template/template.hpp"
#include <vector>

#ifdef _MSC_VER
#include <intrin.h>
#endif

namespace atcoder {

namespace internal {

// @param n `0 <= n`
// @return minimum non-negative `x` s.t. `n <= 2**x`
int ceil_pow2(int n) {
    int x = 0;
    while ((1U << x) < (unsigned int)(n)) x++;
    return x;
}

// @param n `1 <= n`
// @return minimum non-negative `x` s.t. `(n & (1 << x)) != 0`
constexpr int bsf_constexpr(unsigned int n) {
    int x = 0;
    while (!(n & (1 << x))) x++;
    return x;
}

// @param n `1 <= n`
// @return minimum non-negative `x` s.t. `(n & (1 << x)) != 0`
int bsf(unsigned int n) {
#ifdef _MSC_VER
    unsigned long index;
    _BitScanForward(&index, n);
    return index;
#else
    return __builtin_ctz(n);
#endif
}

}  // namespace internal

}  // namespace atcoder

namespace atcoder {

template <class S, S (*op)(S, S), S (*e)()> struct segtree {
  public:
    segtree() : segtree(0) {}
    explicit segtree(int n) : segtree(std::vector<S>(n, e())) {}
    explicit segtree(const std::vector<S>& v) : _n(int(v.size())) {
        log = internal::ceil_pow2(_n);
        size = 1 << log;
        d = std::vector<S>(2 * size, e());
        for (int i = 0; i < _n; i++) d[size + i] = v[i];
        for (int i = size - 1; i >= 1; i--) {
            update(i);
        }
    }

    void set(int p, S x) {
        assert(0 <= p && p < _n);
        p += size;
        d[p] = x;
        for (int i = 1; i <= log; i++) update(p >> i);
    }

    S get(int p) const {
        assert(0 <= p && p < _n);
        return d[p + size];
    }

    S prod(int l, int r) const {
        assert(0 <= l && l <= r && r <= _n);
        S sml = e(), smr = e();
        l += size;
        r += size;

        while (l < r) {
            if (l & 1) sml = op(sml, d[l++]);
            if (r & 1) smr = op(d[--r], smr);
            l >>= 1;
            r >>= 1;
        }
        return op(sml, smr);
    }

    S all_prod() const { return d[1]; }

    template <bool (*f)(S)> int max_right(int l) const {
        return max_right(l, [](S x) { return f(x); });
    }
    template <class F> int max_right(int l, F f) const {
        assert(0 <= l && l <= _n);
        assert(f(e()));
        if (l == _n) return _n;
        l += size;
        S sm = e();
        do {
            while (l % 2 == 0) l >>= 1;
            if (!f(op(sm, d[l]))) {
                while (l < size) {
                    l = (2 * l);
                    if (f(op(sm, d[l]))) {
                        sm = op(sm, d[l]);
                        l++;
                    }
                }
                return l - size;
            }
            sm = op(sm, d[l]);
            l++;
        } while ((l & -l) != l);
        return _n;
    }

    template <bool (*f)(S)> int min_left(int r) const {
        return min_left(r, [](S x) { return f(x); });
    }
    template <class F> int min_left(int r, F f) const {
        assert(0 <= r && r <= _n);
        assert(f(e()));
        if (r == 0) return 0;
        r += size;
        S sm = e();
        do {
            r--;
            while (r > 1 && (r % 2)) r >>= 1;
            if (!f(op(d[r], sm))) {
                while (r < size) {
                    r = (2 * r + 1);
                    if (f(op(d[r], sm))) {
                        sm = op(d[r], sm);
                        r--;
                    }
                }
                return r + 1 - size;
            }
            sm = op(d[r], sm);
        } while ((r & -r) != r);
        return 0;
    }

  private:
    int _n, size, log;
    std::vector<S> d;

    void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }
};

}  // namespace atcoder

#include "math/linear_function.hpp"
#include "math/modint.hpp"
#include "graph/tree/heavy_light_decomposition.hpp"

using mint = modint998244353;
using LF = LinearFunction<mint>;

LF op(LF l, LF r) {
  return l * r;
}

LF revop(LF l, LF r) {
  return r * l;
}

LF e() {
  return LF::Mul_Identity();
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int N, Q; cin >> N >> Q; 
  vector<LF>a(N);
  for(int i=0; i<N; i++) {
    int coef_a, coef_b;
    cin >> coef_a >> coef_b;
    a[i] = LF(coef_a, coef_b);
  }

  HaruiLib::HLD hld(N);
  for(int i=0; i<N-1; i++) {
    int u, v; cin >> u >> v;
    hld.graph.add_edge(u,v);
    hld.graph.add_edge(v,u);
  } 
  hld.build();

  atcoder::segtree<LF,op,e> seg(N);
  atcoder::segtree<LF,revop,e> revseg(N);

  for(int i=0; i<N; i++) {
    seg.set(hld.id[i], a[i]);
    revseg.set(hld.id[i], a[i]);
  }

  for (int q=0; q<Q; q++) {
    int op; cin >> op;
    if (op == 0) {
      int p, c, d; cin >> p >> c >> d;
      seg.set(hld.id[p], LF(c,d));
      revseg.set(hld.id[p], LF(c,d));
    }
    else if (op == 1) {
      int u, v; cin >> u >> v;
      mint x; cin >> x;

      LF ret = LF::Mul_Identity();
      HaruiLib::Path path = hld.get_path(u,v);
      for (HaruiLib::Interval interval : path) {
        if (interval.reverse == true) {
          ret = ret * revseg.prod(interval.top_id, interval.bottom_id + 1);
        }
        else {
          ret = ret * seg.prod(interval.top_id, interval.bottom_id + 1);
        }
      }

      mint ans = ret(x);
      cout << ans.val() << endl;
    }
  }

  return 0;
}
