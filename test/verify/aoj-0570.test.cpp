#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0570"

#include "template/template.hpp"
#include "math/modint.hpp"
#include "dp/automaton/automaton.hpp"
#include "dp/automaton/remainder.hpp"
#include <memory>
#include <string>
#include <vector>

using mint = modint<10000>;

class ZigZagDfa : public Dfa<int> {
  static constexpr int START = 30;
  static constexpr int NG = 31;

  int encode(int last_digit, int direction) const {
    return last_digit * 3 + direction;
  }

public:
  int state_count() const override {
    return 32;
  }

  int initial_state() const override {
    return START;
  }

  int next_state(int state, int digit) const override {
    if(state == NG) return NG;
    if(state == START) return encode(digit, 0);

    int last_digit = state / 3;
    int direction = state % 3;
    if(digit == last_digit) return NG;

    int next_direction = (last_digit < digit ? 1 : 2);
    if(direction != 0 && direction == next_direction) return NG;
    return encode(digit, next_direction);
  }

  bool accept(int state) const override {
    return state != START && state != NG;
  }
};

string decrement(string s) {
  int i = (int)s.size() - 1;
  while(i >= 0 && s[i] == '0') {
    s[i] = '9';
    i--;
  }
  if(i >= 0) s[i]--;

  int pos = 0;
  while(pos + 1 < (int)s.size() && s[pos] == '0') pos++;
  return s.substr(pos);
}

mint count_less_equal(const string& n, int m) {
  vector<int> alphabet = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

  DfaPtr<int> less_equal = make_shared<DecimalLessEqualDfa>(n);
  DfaPtr<int> multiple_of_m = make_shared<LeadingZeroSkipDfa<int>>(
      make_shared<DecimalRemainderDfa>(m));
  DfaPtr<int> zig_zag = make_shared<LeadingZeroSkipDfa<int>>(
      make_shared<ZigZagDfa>());

  DfaPtr<int> condition = make_shared<AndDfa<int>>(multiple_of_m, zig_zag);
  DfaPtr<int> whole = make_shared<AndDfa<int>>(less_equal, condition);

  return count_fixed_length<mint>(*whole, alphabet, n.size());
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string A, B;
  int M;
  cin >> A >> B >> M;

  cout << count_less_equal(B, M) - count_less_equal(decrement(A), M) << '\n';
}
