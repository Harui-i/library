//#de   fi  n e PRO  LE  M "https://atcoder.jp/contests/dp/tasks/dp_s"

#include "../../template/template.hpp"
#include "../../math/modint.hpp"
#include "../../dp/automaton/automaton.hpp"

using mint = modint100000007;

struct dpState {
  int cmp_state; // -1: less than K, 0: equal to K, 1: greater than K
  int digsum_remainder; // digit sum % D

  dpState(int _cmp_state, int _digsum_remainder) : cmp_state(_cmp_state), digsum_remainder(_digsum_remainder) {}

  bool operator<(const dpState& other) const {
    return make_pair(cmp_state, digsum_remainder) < make_pair(other.cmp_state, other.digsum_remainder);
  }
};

// K以下の、桁和がDの倍数の数のみを受理するオートマトン
class Automaton : public Dfa<char, dpState> { 
  const vector<char> K_vec;
  const int D; 
  
public:
  using State = dpState;

  Automaton (const vector<char> _K_vec, int _d) : K_vec(_K_vec), D(_d) {}

  State init() const override {
    return State(0, 0);
  }

  State next(State s, char c, int i) const {
    State ret = s;
    if (s.cmp_state == 0) {
      if (c > K_vec[i]) ret.cmp_state = 1;
      if (c < K_vec[i]) ret.cmp_state = -1;
    }

    ret.digsum_remainder += c - '0';
    ret.digsum_remainder %= D;

    return ret;
  }

  bool accept(State s) const override {
    return s.cmp_state != 1 && s.digsum_remainder % D == 0;
  }

  bool unsuccessful(State s) const override {
    return s.cmp_state == 1;
  }

  bool successful([[maybe_unused]] State s) const override {
    return false;
  }

};

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  string K_str; cin >> K_str;
  vector<char> K_vec(K_str.begin(), K_str.end());

  int D; cin >> D; 
  
  Automaton atm(K_vec, D);

  vector<char> alphabet = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

  int Ksize = K_vec.size();
  map<dpState, mint> dp1, dp2; 
  mint ans = 0;

  dp1[atm.init()] = 1;

  for(int i=0; i<Ksize; i++) {
    for (char c : alphabet) {
      for (pair<dpState, mint> st_cnt : dp1) {
        dpState state = st_cnt.first;
        mint cnt = st_cnt.second;        

        dpState newState = atm.next(state, c, i);
        if (atm.unsuccessful(newState)) continue;

        dp2[newState] += cnt;
      }
    }

    swap(dp1,dp2);
    dp2.clear();
  }


  for (pair<dpState, mint> st_cnt: dp1) {
    if (atm.accept(st_cnt.first)) {
      ans += st_cnt.second;
    }
  }
  ans -= 1;// 0をカウントしてしまっているが、ゼロは正整数ではないので答えから1引く
  cout << ans.val() << endl; 
  return 0;
}