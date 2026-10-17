---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: dp/automaton/automaton.hpp
    title: "\u6C7A\u5B9A\u6027\u6709\u9650\u30AA\u30FC\u30C8\u30DE\u30C8\u30F3(DFA,\
      \ Deterministic Finite Automaton)"
  - icon: ':question:'
    path: dp/automaton/remainder.hpp
    title: "\u3042\u307E\u308A\u3092\u7BA1\u7406\u3059\u308B\u30AA\u30FC\u30C8\u30DE\
      \u30C8\u30F3(remainder.hpp)"
  - icon: ':question:'
    path: math/external_gcd.hpp
    title: math/external_gcd.hpp
  - icon: ':question:'
    path: math/modint.hpp
    title: modint
  - icon: ':question:'
    path: template/template.hpp
    title: template/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://yukicoder.me/problems/no/372
    links:
    - https://yukicoder.me/problems/no/372
  bundledCode: "#line 1 \"test/verify/yuki-372-itsautomatic.test.cpp\"\n#define PROBLEM\
    \ \"https://yukicoder.me/problems/no/372\"\n\n#line 1 \"template/template.hpp\"\
    \n\n\n// https://harui-i.github.io/library/template/template.hpp.html\n\n#include\
    \ <iostream>\n#include <cassert>\nusing namespace std;\nusing ll = long long;\n\
    template<class T> inline bool chmax(T& a, const T& b) {if (a<b) {a=b; return true;}\
    \ return false;}\ntemplate<class T> inline bool chmin(T& a, const T& b) {if (b<a)\
    \ {a=b; return true;} return false;}\nconst int INTINF = 1000001000;\nconst int\
    \ INTMAX = 2147483647;\nconst ll LLMAX = 9223372036854775807;\nconst ll LLINF\
    \ = 1000000000000000000;\n\n\n#line 1 \"math/modint.hpp\"\n\n\n// https://harui-i.github.io/library/math/modint.hpp.html\n\
    \n#line 1 \"math/external_gcd.hpp\"\n\n\n// https://harui-i.github.io/library/math/external_gcd.hpp.html\n\
    \n#include <tuple>\n\n// g,x,y\ntemplate<typename T>\nconstexpr std::tuple<T,\
    \ T, T> extendedGCD(T a, T b) {\n    T x0 = 1, y0 = 0, x1 = 0, y1 = 1;\n    while\
    \ (b != 0) {\n        T q = a / b;\n        T r = a % b;\n        a = b;\n   \
    \     b = r;\n        \n        T xTemp = x0 - q * x1;\n        x0 = x1;\n   \
    \     x1 = xTemp;\n        \n        T yTemp = y0 - q * y1;\n        y0 = y1;\n\
    \        y1 = yTemp;\n    }\n    return {a, x0, y0};\n}\n\n#line 6 \"math/modint.hpp\"\
    \n#include <type_traits>\n#line 8 \"math/modint.hpp\"\n\nlong long mod_pow_ll(long\
    \ long x, long long n, long long mod) {\n    long long ret = 1;\n    while (n\
    \ > 0) {\n        if (n & 1) ret = (__int128)ret * x % mod;\n        x = (__int128)x\
    \ * x % mod;\n        n >>= 1;\n    }\n    return ret;\n}\n\n// x^2 = a (mod p)\
    \ \u3068\u306A\u308B x \u3092\u8FD4\u3059\u3002\u5B58\u5728\u3057\u306A\u3044\u5834\
    \u5408\u306F -1\u3002\n// p \u306F\u7D20\u6570\u3067\u3042\u308B\u3053\u3068\u3092\
    \u4EEE\u5B9A\u3059\u308B\u3002\nlong long mod_sqrt(long long a, long long p) {\n\
    \    a %= p;\n    if (a < 0) a += p;\n    if (a == 0) return 0;\n    if (p ==\
    \ 2) return a;\n    if (mod_pow_ll(a, (p - 1) / 2, p) != 1) return -1;\n    if\
    \ (p % 4 == 3) return mod_pow_ll(a, (p + 1) / 4, p);\n\n    long long q = p -\
    \ 1;\n    int s = 0;\n    while ((q & 1) == 0) {\n        q >>= 1;\n        s++;\n\
    \    }\n\n    long long z = 2;\n    while (mod_pow_ll(z, (p - 1) / 2, p) != p\
    \ - 1) z++;\n\n    long long c = mod_pow_ll(z, q, p);\n    long long x = mod_pow_ll(a,\
    \ (q + 1) / 2, p);\n    long long t = mod_pow_ll(a, q, p);\n    int m = s;\n\n\
    \    while (t != 1) {\n        int i = 1;\n        long long tt = (__int128)t\
    \ * t % p;\n        while (tt != 1) {\n            tt = (__int128)tt * tt % p;\n\
    \            i++;\n        }\n        long long b = c;\n        for (int j = 0;\
    \ j < m - i - 1; j++) b = (__int128)b * b % p;\n        x = (__int128)x * b %\
    \ p;\n        c = (__int128)b * b % p;\n        t = (__int128)t * c % p;\n   \
    \     m = i;\n    }\n\n    return x;\n}\n\ntemplate<int MOD, typename T = int>\n\
    struct static_modint {\n    T value;\n\n    constexpr explicit static_modint()\
    \ : value(0) {}\n\n    static constexpr int mod() { return MOD; }\n\n    constexpr\
    \ static_modint(long long v) {\n        if constexpr (std::is_same<T, double>::value)\
    \ {\n            value = double(v);\n        }\n        else {\n            value\
    \ = int(((v % MOD) + MOD) % MOD);\n        }\n    }\n\n    constexpr static_modint&\
    \ operator+=(const static_modint& other) {\n        if constexpr (std::is_same<T,\
    \ double>::value) {\n            value += other.value;\n        }\n        else\
    \ {\n            if ((value += other.value) >= MOD) value -= MOD;\n        }\n\
    \        return *this;\n    }\n\n    constexpr static_modint& operator-=(const\
    \ static_modint& other) {\n        if constexpr (std::is_same<T, double>::value)\
    \ {\n            value -= other.value;\n        }\n        else {\n          \
    \  if ((value -= other.value) < 0) value += MOD;\n        }\n        return *this;\n\
    \    }\n\n    constexpr static_modint& operator*=(const static_modint& other)\
    \ {\n        if constexpr (std::is_same<T, double>::value) {\n            value\
    \ *= other.value;\n        }\n        else {\n            value = int((long long)value\
    \ * other.value % MOD);\n        }\n        return *this;\n    }\n\n    constexpr\
    \ static_modint operator+(const static_modint& other) const {\n        return\
    \ static_modint(*this) += other;\n    }\n\n    constexpr static_modint operator-(const\
    \ static_modint& other) const {\n        return static_modint(*this) -= other;\n\
    \    }\n\n    constexpr static_modint operator-() const {\n        return static_modint(0)\
    \ - *this;\n    }\n\n    constexpr static_modint operator*(const static_modint&\
    \ other) const {\n        return static_modint(*this) *= other;\n    }\n\n   \
    \ constexpr static_modint pow(long long exp) const {\n        static_modint base\
    \ = *this, res = static_modint(1);\n        while (exp > 0) {\n            if\
    \ (exp & 1) res *= base;\n            base *= base;\n            exp >>= 1;\n\
    \        }\n        return res;\n    }\n\n    long long sqrt_val() const {\n \
    \       return mod_sqrt(value, MOD);\n    }\n\n    static_modint sqrt() const\
    \ {\n        long long ret = sqrt_val();\n        assert(ret != -1);\n       \
    \ return static_modint(ret);\n    }\n\n    constexpr static_modint inv() const\
    \ {\n        if constexpr (std::is_same<T, double>::value) {\n            static_modint\
    \ ret;\n            ret.value = double(1.0) / value;\n            return ret;\n\
    \        }\n        else {\n            int g, x, y;\n            std::tie(g,\
    \ x, y) = extendedGCD(value, MOD);\n            assert(g == 1);\n            if\
    \ (x < 0) x += MOD;\n            return x;\n        }\n    }\n\n    constexpr\
    \ static_modint& operator/=(const static_modint& other) {\n        return *this\
    \ *= other.inv();\n    }\n\n    constexpr static_modint operator/(const static_modint&\
    \ other) const {\n        return static_modint(*this) /= other;\n    }\n\n   \
    \ constexpr bool operator!=(const static_modint& other) const {\n        return\
    \ val() != other.val();\n    }\n\n    constexpr bool operator==(const static_modint&\
    \ other) const {\n        return val() == other.val();\n    }\n\n    T val() const\
    \ {\n        if constexpr (std::is_same<T, double>::value) {\n            return\
    \ double(value);\n        }\n        else return this->value;\n    }\n\n    friend\
    \ std::ostream& operator<<(std::ostream& os, const static_modint& mi) {\n    \
    \    return os << mi.value;\n    }\n\n    friend std::istream& operator>>(std::istream&\
    \ is, static_modint& mi) {\n        long long x;\n        is >> x;\n        mi\
    \ = static_modint(x);\n        return is;\n    }\n};\n\ntemplate <int mod>\nusing\
    \ modint = static_modint<mod>;\nusing doublemodint = static_modint<59, double>;\n\
    using modint998244353 = modint<998244353>;\nusing modint1000000007 = modint<1000000007>;\n\
    \n\n#line 1 \"dp/automaton/remainder.hpp\"\n\n\n// https://harui-i.github.io/library/dp/automaton/remainder.hpp.html\n\
    \n#line 1 \"dp/automaton/automaton.hpp\"\n\n\n// https://harui-i.github.io/library/dp/automaton/automaton.hpp.html\n\
    \n#include <functional>\n#include <memory>\n#include <string>\n#include <unordered_map>\n\
    #include <utility>\n#include <vector>\n\ntemplate <typename Alphabet = int>\n\
    struct Dfa {\n  using alphabet_type = Alphabet;\n  using state_type = int;\n\n\
    \  virtual int state_count() const = 0;\n  virtual int initial_state() const =\
    \ 0;\n  virtual int next_state(int state, Alphabet c) const = 0;\n  virtual bool\
    \ accept(int state) const = 0;\n  virtual ~Dfa() = default;\n};\n\ntemplate <typename\
    \ Alphabet = int>\nusing DfaPtr = std::shared_ptr<Dfa<Alphabet>>;\n\ntemplate\
    \ <typename Alphabet = int>\nclass ProductPolicyDfa : public Dfa<Alphabet> {\n\
    \  std::vector<DfaPtr<Alphabet>> dfas;\n  std::vector<int> base;\n  int states;\n\
    \  std::function<bool(const std::vector<bool>&)> policy;\n\npublic:\n  ProductPolicyDfa(std::vector<DfaPtr<Alphabet>>\
    \ dfas,\n                   std::function<bool(const std::vector<bool>&)> policy)\n\
    \      : dfas(std::move(dfas)), states(1), policy(std::move(policy)) {\n    base.resize(this->dfas.size());\n\
    \    for(int i = 0; i < (int)this->dfas.size(); i++) {\n      base[i] = states;\n\
    \      states *= this->dfas[i]->state_count();\n    }\n  }\n\n  int encode(const\
    \ std::vector<int>& component_states) const {\n    int state = 0;\n    for(int\
    \ i = 0; i < (int)dfas.size(); i++) {\n      state += component_states[i] * base[i];\n\
    \    }\n    return state;\n  }\n\n  std::vector<int> decode(int state) const {\n\
    \    std::vector<int> component_states(dfas.size());\n    for(int i = 0; i < (int)dfas.size();\
    \ i++) {\n      component_states[i] = (state / base[i]) % dfas[i]->state_count();\n\
    \    }\n    return component_states;\n  }\n\n  int state_count() const override\
    \ {\n    return states;\n  }\n\n  int initial_state() const override {\n    std::vector<int>\
    \ component_states(dfas.size());\n    for(int i = 0; i < (int)dfas.size(); i++)\
    \ {\n      component_states[i] = dfas[i]->initial_state();\n    }\n    return\
    \ encode(component_states);\n  }\n\n  int next_state(int state, Alphabet c) const\
    \ override {\n    std::vector<int> component_states = decode(state);\n    for(int\
    \ i = 0; i < (int)dfas.size(); i++) {\n      component_states[i] = dfas[i]->next_state(component_states[i],\
    \ c);\n    }\n    return encode(component_states);\n  }\n\n  bool accept(int state)\
    \ const override {\n    std::vector<int> component_states = decode(state);\n \
    \   std::vector<bool> accepted(dfas.size());\n    for(int i = 0; i < (int)dfas.size();\
    \ i++) {\n      accepted[i] = dfas[i]->accept(component_states[i]);\n    }\n \
    \   return policy(accepted);\n  }\n};\n\ntemplate <typename Alphabet = int>\n\
    class AndDfa : public Dfa<Alphabet> {\n  DfaPtr<Alphabet> lhs;\n  DfaPtr<Alphabet>\
    \ rhs;\n  int rhs_states;\n\npublic:\n  AndDfa(DfaPtr<Alphabet> lhs, DfaPtr<Alphabet>\
    \ rhs)\n      : lhs(std::move(lhs)), rhs(std::move(rhs)), rhs_states(this->rhs->state_count())\
    \ {}\n\n  int encode(int lhs_state, int rhs_state) const {\n    return lhs_state\
    \ * rhs_states + rhs_state;\n  }\n\n  std::pair<int, int> decode(int state) const\
    \ {\n    return {state / rhs_states, state % rhs_states};\n  }\n\n  int state_count()\
    \ const override {\n    return lhs->state_count() * rhs->state_count();\n  }\n\
    \n  int initial_state() const override {\n    return encode(lhs->initial_state(),\
    \ rhs->initial_state());\n  }\n\n  int next_state(int state, Alphabet c) const\
    \ override {\n    auto [a, b] = decode(state);\n    return encode(lhs->next_state(a,\
    \ c), rhs->next_state(b, c));\n  }\n\n  bool accept(int state) const override\
    \ {\n    auto [a, b] = decode(state);\n    return lhs->accept(a) && rhs->accept(b);\n\
    \  }\n};\n\ntemplate <typename T, typename Alphabet = int>\nT count_fixed_length(const\
    \ Dfa<Alphabet>& dfa, const std::vector<Alphabet>& alphabet, int length) {\n \
    \ std::unordered_map<int, T> dp, next_dp;\n  dp[dfa.initial_state()] = T(1);\n\
    \n  for(int i = 0; i < length; i++) {\n    next_dp.clear();\n    for(const auto&\
    \ [state, value] : dp) {\n      for(const Alphabet& c : alphabet) {\n        next_dp[dfa.next_state(state,\
    \ c)] += value;\n      }\n    }\n    dp.swap(next_dp);\n  }\n\n  T answer = T(0);\n\
    \  for(const auto& [state, value] : dp) {\n    if(dfa.accept(state)) answer +=\
    \ value;\n  }\n  return answer;\n}\n\nclass DecimalLessEqualDfa : public Dfa<int>\
    \ {\n  std::vector<int> digits;\n\npublic:\n  explicit DecimalLessEqualDfa(const\
    \ std::string& n) {\n    digits.reserve(n.size());\n    for(char c : n) digits.push_back(c\
    \ - '0');\n  }\n\n  int encode(int pos, int rel) const {\n    return pos * 3 +\
    \ rel;\n  }\n\n  std::pair<int, int> decode(int state) const {\n    return {state\
    \ / 3, state % 3};\n  }\n\n  int state_count() const override {\n    return ((int)digits.size()\
    \ + 1) * 3;\n  }\n\n  int initial_state() const override {\n    return encode(0,\
    \ 0);\n  }\n\n  int next_state(int state, int digit) const override {\n    auto\
    \ [pos, rel] = decode(state);\n    if(pos == (int)digits.size()) return encode(pos,\
    \ 2);\n\n    if(rel == 0) {\n      if(digit < digits[pos]) rel = 1;\n      if(digit\
    \ > digits[pos]) rel = 2;\n    }\n    return encode(pos + 1, rel);\n  }\n\n  bool\
    \ accept(int state) const override {\n    auto [pos, rel] = decode(state);\n \
    \   return pos == (int)digits.size() && rel != 2;\n  }\n};\n\ntemplate <typename\
    \ Alphabet = int>\nclass LeadingZeroSkipDfa : public Dfa<Alphabet> {\n  DfaPtr<Alphabet>\
    \ inner;\n  Alphabet zero;\n  int inner_states;\n\npublic:\n  LeadingZeroSkipDfa(DfaPtr<Alphabet>\
    \ inner, Alphabet zero = Alphabet())\n      : inner(std::move(inner)), zero(zero),\
    \ inner_states(this->inner->state_count()) {}\n\n  int encode(bool started, int\
    \ inner_state) const {\n    return (started ? inner_states : 0) + inner_state;\n\
    \  }\n\n  std::pair<bool, int> decode(int state) const {\n    if(state < inner_states)\
    \ return {false, state};\n    return {true, state - inner_states};\n  }\n\n  int\
    \ state_count() const override {\n    return inner_states * 2;\n  }\n\n  int initial_state()\
    \ const override {\n    return encode(false, inner->initial_state());\n  }\n\n\
    \  int next_state(int state, Alphabet c) const override {\n    auto [started,\
    \ inner_state] = decode(state);\n    if(!started && c == zero) return encode(false,\
    \ inner_state);\n    return encode(true, inner->next_state(inner_state, c));\n\
    \  }\n\n  bool accept(int state) const override {\n    auto [started, inner_state]\
    \ = decode(state);\n    if(started) return inner->accept(inner_state);\n\n   \
    \ int zero_state = inner->next_state(inner->initial_state(), zero);\n    return\
    \ inner->accept(zero_state);\n  }\n};\n\n\n#line 6 \"dp/automaton/remainder.hpp\"\
    \n\nclass DecimalRemainderDfa : public Dfa<int> {\n  int mod;\n\npublic:\n  explicit\
    \ DecimalRemainderDfa(int mod) : mod(mod) {}\n\n  int state_count() const override\
    \ {\n    return mod;\n  }\n\n  int initial_state() const override {\n    return\
    \ 0;\n  }\n\n  int next_state(int state, int digit) const override {\n    return\
    \ ((long long)state * 10 + digit) % mod;\n  }\n\n  bool accept(int state) const\
    \ override {\n    return state == 0;\n  }\n};\n\nusing RemainderAutomaton = DecimalRemainderDfa;\n\
    \n\n#line 7 \"test/verify/yuki-372-itsautomatic.test.cpp\"\n\nusing mint = modint1000000007;\n\
    \nint main() {\n  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);\n\n  string\
    \ S; cin >> S;\n  vector<char> svec(S.begin(), S.end());\n\n  int M; cin >> M;\n\
    \n  vector<char> alphabet = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'\
    \ };\n\n  DecimalRemainderDfa ra(M);\n\n  mint ans = 0;\n  vector<mint>dp1(M),\
    \ dp2(M);\n\n\n  for (int i = 0; i < (int) S.size(); i++) {\n    if (S[i] == '0')\
    \ ans += 1;\n    else {\n      dp2[(S[i] - '0') % M] += 1; // only one word substring,\
    \ 'S[i]' .\n    }\n    for (int j = 0; j < M; j++) {\n\n      dp2[j] += dp1[j];\
    \ // the case when S[i] is not choosed\n\n      dp2[(j * 10 + S[i] - '0') % M]\
    \ += dp1[j]; // the case when S[i] is choosen and added into past substrings\n\
    \n    }\n\n    swap(dp1, dp2);\n    dp2.assign(M, 0);\n  }\n  for(int i=0; i<M;\
    \ i++) {\n    if (ra.accept(i)) ans += dp1[i];\n  }\n  cout << ans.val() << endl;\n\
    \n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/372\"\n\n#include \"template/template.hpp\"\
    \n#include \"math/modint.hpp\"\n#include \"dp/automaton/remainder.hpp\"\n#include\
    \ <vector>\n\nusing mint = modint1000000007;\n\nint main() {\n  ios::sync_with_stdio(0);\
    \ cin.tie(0); cout.tie(0);\n\n  string S; cin >> S;\n  vector<char> svec(S.begin(),\
    \ S.end());\n\n  int M; cin >> M;\n\n  vector<char> alphabet = { '0', '1', '2',\
    \ '3', '4', '5', '6', '7', '8', '9' };\n\n  DecimalRemainderDfa ra(M);\n\n  mint\
    \ ans = 0;\n  vector<mint>dp1(M), dp2(M);\n\n\n  for (int i = 0; i < (int) S.size();\
    \ i++) {\n    if (S[i] == '0') ans += 1;\n    else {\n      dp2[(S[i] - '0') %\
    \ M] += 1; // only one word substring, 'S[i]' .\n    }\n    for (int j = 0; j\
    \ < M; j++) {\n\n      dp2[j] += dp1[j]; // the case when S[i] is not choosed\n\
    \n      dp2[(j * 10 + S[i] - '0') % M] += dp1[j]; // the case when S[i] is choosen\
    \ and added into past substrings\n\n    }\n\n    swap(dp1, dp2);\n    dp2.assign(M,\
    \ 0);\n  }\n  for(int i=0; i<M; i++) {\n    if (ra.accept(i)) ans += dp1[i];\n\
    \  }\n  cout << ans.val() << endl;\n\n\n  return 0;\n}\n"
  dependsOn:
  - template/template.hpp
  - math/modint.hpp
  - math/external_gcd.hpp
  - dp/automaton/remainder.hpp
  - dp/automaton/automaton.hpp
  isVerificationFile: true
  path: test/verify/yuki-372-itsautomatic.test.cpp
  requiredBy: []
  timestamp: '2026-10-17 23:49:45+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/verify/yuki-372-itsautomatic.test.cpp
layout: document
redirect_from:
- /verify/test/verify/yuki-372-itsautomatic.test.cpp
- /verify/test/verify/yuki-372-itsautomatic.test.cpp.html
title: test/verify/yuki-372-itsautomatic.test.cpp
---
