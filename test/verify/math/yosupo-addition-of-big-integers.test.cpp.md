---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/decimal_big_integer.hpp
    title: decimal_big_integer
  - icon: ':heavy_check_mark:'
    path: template/template.hpp
    title: template/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/addition_of_big_integers
    links:
    - https://judge.yosupo.jp/problem/addition_of_big_integers
  bundledCode: "#line 1 \"test/verify/math/yosupo-addition-of-big-integers.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/addition_of_big_integers\"\
    \n\n#line 1 \"template/template.hpp\"\n#include <iostream>\n#include <cassert>\n\
    using namespace std;\nusing ll = long long;\ntemplate<class T> inline bool chmax(T&\
    \ a, const T& b) {if (a<b) {a=b; return true;} return false;}\ntemplate<class\
    \ T> inline bool chmin(T& a, const T& b) {if (b<a) {a=b; return true;} return\
    \ false;}\nconst int INTINF = 1000001000;\nconst int INTMAX = 2147483647;\nconst\
    \ ll LLMAX = 9223372036854775807;\nconst ll LLINF = 1000000000000000000;\n#line\
    \ 1 \"math/decimal_big_integer.hpp\"\n\n\n\n#include <algorithm>\n#line 6 \"math/decimal_big_integer.hpp\"\
    \n#include <cctype>\n#include <cstdint>\n#include <iomanip>\n#line 10 \"math/decimal_big_integer.hpp\"\
    \n#include <string>\n#include <tuple>\n#include <utility>\n#include <vector>\n\
    \nnamespace decimal_big_integer_internal {\n\ntemplate<int MOD, int G>\nstruct\
    \ NTT {\n  static int mod_pow(int a, int e) {\n    long long r = 1, x = a;\n \
    \   while(e > 0) {\n      if(e & 1) r = r * x % MOD;\n      x = x * x % MOD;\n\
    \      e >>= 1;\n    }\n    return (int)r;\n  }\n\n  static void ntt(std::vector<int>&\
    \ a, bool inverse) {\n    int n = (int)a.size();\n    for(int i=1, j=0; i<n; i++)\
    \ {\n      int bit = n >> 1;\n      for(; j & bit; bit >>= 1) j ^= bit;\n    \
    \  j ^= bit;\n      if(i < j) std::swap(a[i], a[j]);\n    }\n\n    for(int len=2;\
    \ len<=n; len<<=1) {\n      int wlen = mod_pow(G, (MOD - 1) / len);\n      if(inverse)\
    \ wlen = mod_pow(wlen, MOD - 2);\n      for(int i=0; i<n; i+=len) {\n        long\
    \ long w = 1;\n        for(int j=0; j<len/2; j++) {\n          int u = a[i + j];\n\
    \          int v = (int)(w * a[i + j + len / 2] % MOD);\n          int x = u +\
    \ v; if(x >= MOD) x -= MOD;\n          int y = u - v; if(y < 0) y += MOD;\n  \
    \        a[i + j] = x;\n          a[i + j + len / 2] = y;\n          w = w * wlen\
    \ % MOD;\n        }\n      }\n    }\n\n    if(inverse) {\n      int inv_n = mod_pow(n,\
    \ MOD - 2);\n      for(int& x: a) x = (int)((long long)x * inv_n % MOD);\n   \
    \ }\n  }\n\n  static std::vector<int> convolution(const std::vector<int>& a, const\
    \ std::vector<int>& b) {\n    if(a.empty() || b.empty()) return {};\n    int need\
    \ = (int)a.size() + (int)b.size() - 1;\n    int n = 1;\n    while(n < need) n\
    \ <<= 1;\n    std::vector<int> fa(a.begin(), a.end()), fb(b.begin(), b.end());\n\
    \    fa.resize(n);\n    fb.resize(n);\n    ntt(fa, false);\n    ntt(fb, false);\n\
    \    for(int i=0; i<n; i++) fa[i] = (int)((long long)fa[i] * fb[i] % MOD);\n \
    \   ntt(fa, true);\n    fa.resize(need);\n    return fa;\n  }\n};\n\ninline long\
    \ long crt3(int x1, int x2, int x3) {\n  static constexpr long long m1 = 998244353LL;\n\
    \  static constexpr long long m2 = 1004535809LL;\n  static constexpr long long\
    \ m3 = 469762049LL;\n  static const long long inv_m1_mod_m2 = NTT<1004535809,\
    \ 3>::mod_pow((int)(m1 % m2), (int)m2 - 2);\n  static const long long inv_m1m2_mod_m3\
    \ =\n      NTT<469762049, 3>::mod_pow((int)((__int128)m1 * m2 % m3), (int)m3 -\
    \ 2);\n\n  long long t2 = (x2 - x1) % m2;\n  if(t2 < 0) t2 += m2;\n  t2 = t2 *\
    \ inv_m1_mod_m2 % m2;\n\n  long long cur_m3 = (x1 % m3 + (__int128)(m1 % m3) *\
    \ (t2 % m3)) % m3;\n  long long t3 = (x3 - cur_m3) % m3;\n  if(t3 < 0) t3 += m3;\n\
    \  t3 = t3 * inv_m1m2_mod_m3 % m3;\n\n  __int128 res = x1 + (__int128)m1 * t2\
    \ + (__int128)m1 * m2 * t3;\n  return (long long)res;\n}\n\n} // namespace decimal_big_integer_internal\n\
    \nstruct DecimalBigInteger {\n  using i128 = __int128;\n  static constexpr long\
    \ long base = 1000000000000000000LL;\n  static constexpr int base_digits = 18;\n\
    \  std::vector<long long> a;\n  int sign = 1;\n\n  DecimalBigInteger() = default;\n\
    \  DecimalBigInteger(long long v) { *this = v; }\n  DecimalBigInteger(const std::string&\
    \ s) { read(s); }\n\n  DecimalBigInteger& operator=(long long v) {\n    sign =\
    \ v < 0 ? -1 : 1;\n    unsigned long long x = v < 0 ? (unsigned long long)(-(v\
    \ + 1)) + 1 : (unsigned long long)v;\n    a.clear();\n    while(x > 0) {\n   \
    \   a.push_back((long long)(x % base));\n      x /= base;\n    }\n    trim();\n\
    \    return *this;\n  }\n\n  bool is_zero() const { return a.empty(); }\n\n  DecimalBigInteger&\
    \ trim() {\n    while(!a.empty() && a.back() == 0) a.pop_back();\n    if(a.empty())\
    \ sign = 1;\n    return *this;\n  }\n\n  DecimalBigInteger abs() const {\n   \
    \ DecimalBigInteger res = *this;\n    res.sign = 1;\n    return res;\n  }\n\n\
    \  void read(const std::string& s) {\n    sign = 1;\n    a.clear();\n    int pos\
    \ = 0;\n    while(pos < (int)s.size() && std::isspace((unsigned char)s[pos]))\
    \ pos++;\n    if(pos < (int)s.size() && (s[pos] == '-' || s[pos] == '+')) {\n\
    \      if(s[pos] == '-') sign = -1;\n      pos++;\n    }\n    int end = pos;\n\
    \    while(end < (int)s.size() && std::isdigit((unsigned char)s[end])) end++;\n\
    \    for(int i=end; i>pos; i-=base_digits) {\n      int l = std::max(pos, i -\
    \ base_digits);\n      long long x = 0;\n      for(int j=l; j<i; j++) x = x *\
    \ 10 + (s[j] - '0');\n      a.push_back(x);\n    }\n    trim();\n  }\n\n  std::string\
    \ to_string() const {\n    if(a.empty()) return \"0\";\n    std::string s = sign\
    \ < 0 ? \"-\" : \"\";\n    s += std::to_string(a.back());\n    for(int i=(int)a.size()-2;\
    \ i>=0; i--) {\n      std::string t = std::to_string(a[i]);\n      s += std::string(base_digits\
    \ - (int)t.size(), '0') + t;\n    }\n    return s;\n  }\n\n  static int abs_compare(const\
    \ DecimalBigInteger& x, const DecimalBigInteger& y) {\n    if(x.a.size() != y.a.size())\
    \ return x.a.size() < y.a.size() ? -1 : 1;\n    for(int i=(int)x.a.size()-1; i>=0;\
    \ i--) {\n      if(x.a[i] != y.a[i]) return x.a[i] < y.a[i] ? -1 : 1;\n    }\n\
    \    return 0;\n  }\n\n  friend bool operator<(const DecimalBigInteger& x, const\
    \ DecimalBigInteger& y) {\n    if(x.sign != y.sign) return x.sign < y.sign;\n\
    \    int cmp = abs_compare(x, y);\n    return x.sign == 1 ? cmp < 0 : cmp > 0;\n\
    \  }\n  friend bool operator==(const DecimalBigInteger& x, const DecimalBigInteger&\
    \ y) {\n    return x.sign == y.sign && x.a == y.a;\n  }\n  friend bool operator!=(const\
    \ DecimalBigInteger& x, const DecimalBigInteger& y) { return !(x == y); }\n  friend\
    \ bool operator>(const DecimalBigInteger& x, const DecimalBigInteger& y) { return\
    \ y < x; }\n  friend bool operator<=(const DecimalBigInteger& x, const DecimalBigInteger&\
    \ y) { return !(y < x); }\n  friend bool operator>=(const DecimalBigInteger& x,\
    \ const DecimalBigInteger& y) { return !(x < y); }\n\n  DecimalBigInteger operator-()\
    \ const {\n    DecimalBigInteger res = *this;\n    if(!res.is_zero()) res.sign\
    \ = -res.sign;\n    return res;\n  }\n\n  friend DecimalBigInteger operator+(DecimalBigInteger\
    \ x, const DecimalBigInteger& y) {\n    if(x.sign == y.sign) {\n      int carry\
    \ = 0;\n      for(size_t i=0; i<std::max(x.a.size(), y.a.size()) || carry; i++)\
    \ {\n        if(i == x.a.size()) x.a.push_back(0);\n        long long cur = (long\
    \ long)x.a[i] + carry + (i < y.a.size() ? y.a[i] : 0);\n        carry = cur >=\
    \ base;\n        if(carry) cur -= base;\n        x.a[i] = cur;\n      }\n    \
    \  return x;\n    }\n    return x - (-y);\n  }\n\n  friend DecimalBigInteger operator-(DecimalBigInteger\
    \ x, const DecimalBigInteger& y) {\n    if(y.is_zero()) return x;\n    if(x.sign\
    \ == y.sign) {\n      if(abs_compare(x, y) >= 0) {\n        int carry = 0;\n \
    \       for(size_t i=0; i<y.a.size() || carry; i++) {\n          long long cur\
    \ = (long long)x.a[i] - carry - (i < y.a.size() ? y.a[i] : 0);\n          carry\
    \ = cur < 0;\n          if(carry) cur += base;\n          x.a[i] = cur;\n    \
    \    }\n        return x.trim();\n      }\n      return -(y - x);\n    }\n   \
    \ return x + (-y);\n  }\n\n  static std::vector<int> to_base1000000(const std::vector<long\
    \ long>& v) {\n    std::vector<int> res;\n    res.reserve(v.size() * 3);\n   \
    \ for(long long x: v) {\n      for(int i=0; i<3; i++) {\n        res.push_back((int)(x\
    \ % 1000000));\n        x /= 1000000;\n      }\n    }\n    while(!res.empty()\
    \ && res.back() == 0) res.pop_back();\n    return res;\n  }\n\n  static std::vector<long\
    \ long> multiply_digits(const std::vector<long long>& x, const std::vector<long\
    \ long>& y) {\n    if(x.empty() || y.empty()) return {};\n    if(std::min(x.size(),\
    \ y.size()) <= 32) {\n      std::vector<i128> tmp(x.size() + y.size());\n    \
    \  for(size_t i=0; i<x.size(); i++) for(size_t j=0; j<y.size(); j++) {\n     \
    \   tmp[i + j] += (i128)x[i] * y[j];\n      }\n      std::vector<long long> res(tmp.size());\n\
    \      i128 carry = 0;\n      for(size_t i=0; i<tmp.size(); i++) {\n        i128\
    \ cur = tmp[i] + carry;\n        res[i] = (long long)(cur % base);\n        carry\
    \ = cur / base;\n      }\n      while(carry > 0) {\n        res.push_back((long\
    \ long)(carry % base));\n        carry /= base;\n      }\n      while(!res.empty()\
    \ && res.back() == 0) res.pop_back();\n      return res;\n    }\n\n    using N1\
    \ = decimal_big_integer_internal::NTT<998244353, 3>;\n    using N2 = decimal_big_integer_internal::NTT<1004535809,\
    \ 3>;\n    using N3 = decimal_big_integer_internal::NTT<469762049, 3>;\n    std::vector<int>\
    \ sx = to_base1000000(x), sy = to_base1000000(y);\n    std::vector<int> c1 = N1::convolution(sx,\
    \ sy);\n    std::vector<int> c2 = N2::convolution(sx, sy);\n    std::vector<int>\
    \ c3 = N3::convolution(sx, sy);\n\n    std::vector<int> chunks(c1.size());\n \
    \   long long carry = 0;\n    for(size_t i=0; i<c1.size(); i++) {\n      long\
    \ long cur = decimal_big_integer_internal::crt3(c1[i], c2[i], c3[i]) + carry;\n\
    \      chunks[i] = (int)(cur % 1000000);\n      carry = cur / 1000000;\n    }\n\
    \    while(carry > 0) {\n      chunks.push_back((int)(carry % 1000000));\n   \
    \   carry /= 1000000;\n    }\n\n    std::vector<long long> res;\n    res.reserve((chunks.size()\
    \ + 2) / 3);\n    for(size_t i=0; i<chunks.size(); i+=3) {\n      long long cur\
    \ = 0;\n      long long p = 1;\n      for(size_t j=0; j<3 && i+j<chunks.size();\
    \ j++) {\n        cur += (long long)chunks[i + j] * p;\n        p *= 1000000;\n\
    \      }\n      res.push_back(cur);\n    }\n    while(!res.empty() && res.back()\
    \ == 0) res.pop_back();\n    return res;\n  }\n\n  friend DecimalBigInteger operator*(const\
    \ DecimalBigInteger& x, const DecimalBigInteger& y) {\n    DecimalBigInteger res;\n\
    \    res.sign = x.sign * y.sign;\n    res.a = multiply_digits(x.a, y.a);\n   \
    \ return res.trim();\n  }\n\n  DecimalBigInteger& operator+=(const DecimalBigInteger&\
    \ v) { return *this = *this + v; }\n  DecimalBigInteger& operator-=(const DecimalBigInteger&\
    \ v) { return *this = *this - v; }\n  DecimalBigInteger& operator*=(const DecimalBigInteger&\
    \ v) { return *this = *this * v; }\n\n  void mul_int(long long m) {\n    if(m\
    \ == 0 || is_zero()) {\n      a.clear();\n      sign = 1;\n      return;\n   \
    \ }\n    i128 carry = 0;\n    for(size_t i=0; i<a.size() || carry; i++) {\n  \
    \    if(i == a.size()) a.push_back(0);\n      i128 cur = carry + (i128)a[i] *\
    \ m;\n      a[i] = (long long)(cur % base);\n      carry = cur / base;\n    }\n\
    \    trim();\n  }\n\n  long long div_int(long long v) {\n    assert(v > 0);\n\
    \    i128 rem = 0;\n    for(int i=(int)a.size()-1; i>=0; i--) {\n      i128 cur\
    \ = a[i] + rem * base;\n      a[i] = (long long)(cur / v);\n      rem = cur %\
    \ v;\n    }\n    trim();\n    return (long long)rem;\n  }\n\n  static DecimalBigInteger\
    \ digits_slice(const DecimalBigInteger& x, int l, int r) {\n    DecimalBigInteger\
    \ res;\n    l = std::max(l, 0);\n    r = std::min(r, (int)x.a.size());\n    if(l\
    \ < r) res.a.assign(x.a.begin() + l, x.a.begin() + r);\n    return res.trim();\n\
    \  }\n\n  static DecimalBigInteger shift_left_digits(const DecimalBigInteger&\
    \ x, int k) {\n    if(x.is_zero()) return x;\n    DecimalBigInteger res;\n   \
    \ res.a.assign(k, 0);\n    res.a.insert(res.a.end(), x.a.begin(), x.a.end());\n\
    \    return res;\n  }\n\n  static DecimalBigInteger low_digits(const DecimalBigInteger&\
    \ x, int k) {\n    return digits_slice(x, 0, k);\n  }\n\n  static DecimalBigInteger\
    \ high_digits(const DecimalBigInteger& x, int k) {\n    return digits_slice(x,\
    \ k, (int)x.a.size());\n  }\n\n  static DecimalBigInteger one_shift_digits_minus_one(int\
    \ k) {\n    DecimalBigInteger res;\n    res.a.assign(k, base - 1);\n    return\
    \ res.trim();\n  }\n\n  static std::pair<DecimalBigInteger, DecimalBigInteger>\
    \ divmod_abs_knuth(DecimalBigInteger u, DecimalBigInteger v) {\n    assert(!v.is_zero());\n\
    \    if(abs_compare(u, v) < 0) return {DecimalBigInteger(0), u};\n    if(v.a.size()\
    \ == 1) {\n      DecimalBigInteger q = u;\n      long long r = q.div_int(v.a[0]);\n\
    \      return {q, DecimalBigInteger(r)};\n    }\n\n    long long norm = base /\
    \ (v.a.back() + 1);\n    u.mul_int(norm);\n    v.mul_int(norm);\n    u.a.push_back(0);\n\
    \n    int n = (int)v.a.size();\n    int m = (int)u.a.size() - n - 1;\n    DecimalBigInteger\
    \ q;\n    q.a.assign(m + 1, 0);\n\n    for(int j=m; j>=0; j--) {\n      i128 numerator\
    \ = (i128)u.a[j + n] * base + u.a[j + n - 1];\n      long long qhat = (long long)(numerator\
    \ / v.a[n - 1]);\n      i128 rhat = numerator % v.a[n - 1];\n      if(qhat >=\
    \ base) {\n        qhat = base - 1;\n        rhat += v.a[n - 1];\n      }\n\n\
    \      while(n >= 2 && (i128)qhat * v.a[n - 2] > rhat * base + u.a[j + n - 2])\
    \ {\n        qhat--;\n        rhat += v.a[n - 1];\n        if(rhat >= base) break;\n\
    \      }\n\n      i128 carry = 0;\n      long long borrow = 0;\n      for(int\
    \ i=0; i<n; i++) {\n        i128 prod = (i128)qhat * v.a[i] + carry;\n       \
    \ carry = prod / base;\n        i128 cur = (i128)u.a[j + i] - (prod % base) -\
    \ borrow;\n        borrow = 0;\n        if(cur < 0) {\n          cur += base;\n\
    \          borrow = 1;\n        }\n        u.a[j + i] = (long long)cur;\n    \
    \  }\n\n      i128 cur = (i128)u.a[j + n] - carry - borrow;\n      bool negative\
    \ = cur < 0;\n      if(negative) cur += base;\n      u.a[j + n] = (long long)cur;\n\
    \n      if(negative) {\n        qhat--;\n        long long c = 0;\n        for(int\
    \ i=0; i<n; i++) {\n          i128 sum = (i128)u.a[j + i] + v.a[i] + c;\n    \
    \      if(sum >= base) {\n            sum -= base;\n            c = 1;\n     \
    \     } else {\n            c = 0;\n          }\n          u.a[j + i] = (long\
    \ long)sum;\n        }\n        u.a[j + n] += c;\n        if(u.a[j + n] >= base)\
    \ u.a[j + n] -= base;\n      }\n      q.a[j] = qhat;\n    }\n\n    q.trim();\n\
    \    u.div_int(norm);\n    u.trim();\n    return {q, u};\n  }\n\n  static std::pair<DecimalBigInteger,\
    \ DecimalBigInteger> div_3n_2n(\n      const DecimalBigInteger& a1,\n      const\
    \ DecimalBigInteger& a2,\n      const DecimalBigInteger& a3,\n      const DecimalBigInteger&\
    \ b1,\n      const DecimalBigInteger& b2,\n      int n) {\n    DecimalBigInteger\
    \ q, r;\n    int cmp = abs_compare(a1, b1);\n    if(cmp >= 0) {\n      q = one_shift_digits_minus_one(n);\n\
    \      r = shift_left_digits(a1 - b1, n) + a2 + b1;\n    } else {\n      DecimalBigInteger\
    \ top = shift_left_digits(a1, n) + a2;\n      std::tie(q, r) = div_2n_1n(top,\
    \ b1);\n    }\n\n    DecimalBigInteger b = shift_left_digits(b1, n) + b2;\n  \
    \  DecimalBigInteger r_full = shift_left_digits(r, n) + a3;\n    r_full -= q *\
    \ b2;\n    while(r_full.sign < 0) {\n      q -= DecimalBigInteger(1);\n      r_full\
    \ += b;\n    }\n    while(abs_compare(r_full, b) >= 0) {\n      q += DecimalBigInteger(1);\n\
    \      r_full -= b;\n    }\n    return {q.trim(), r_full.trim()};\n  }\n\n  static\
    \ std::pair<DecimalBigInteger, DecimalBigInteger> div_2n_1n(const DecimalBigInteger&\
    \ u, const DecimalBigInteger& v) {\n    int n = (int)v.a.size();\n    assert(n\
    \ > 0);\n    if(abs_compare(u, v) < 0) return {DecimalBigInteger(0), u};\n   \
    \ if(n <= 64) return divmod_abs_knuth(u, v);\n    if(n & 1) {\n      auto [q,\
    \ r] = div_2n_1n(shift_left_digits(u, 1), shift_left_digits(v, 1));\n      r =\
    \ high_digits(r, 1);\n      return {q.trim(), r.trim()};\n    }\n\n    int half\
    \ = n / 2;\n    DecimalBigInteger b1 = high_digits(v, half);\n    DecimalBigInteger\
    \ b2 = low_digits(v, half);\n\n    DecimalBigInteger a1 = digits_slice(u, 3 *\
    \ half, 4 * half);\n    DecimalBigInteger a2 = digits_slice(u, 2 * half, 3 * half);\n\
    \    DecimalBigInteger a3 = digits_slice(u, half, 2 * half);\n    DecimalBigInteger\
    \ a4 = digits_slice(u, 0, half);\n\n    auto [q1, r1] = div_3n_2n(a1, a2, a3,\
    \ b1, b2, half);\n    DecimalBigInteger r1_high = high_digits(r1, half);\n   \
    \ DecimalBigInteger r1_low = low_digits(r1, half);\n    auto [q2, r2] = div_3n_2n(r1_high,\
    \ r1_low, a4, b1, b2, half);\n    DecimalBigInteger q = shift_left_digits(q1,\
    \ half) + q2;\n    return {q.trim(), r2.trim()};\n  }\n\n  static std::pair<DecimalBigInteger,\
    \ DecimalBigInteger> divmod_abs_bz(DecimalBigInteger u, DecimalBigInteger v) {\n\
    \    int n = (int)v.a.size();\n    if(n <= 128 || (n & 1)) return divmod_abs_knuth(std::move(u),\
    \ std::move(v));\n\n    DecimalBigInteger q, r;\n    int blocks = ((int)u.a.size()\
    \ + n - 1) / n;\n    for(int block=blocks-1; block>=0; block--) {\n      DecimalBigInteger\
    \ cur = digits_slice(u, block * n, std::min((block + 1) * n, (int)u.a.size()));\n\
    \      r = shift_left_digits(r, n) + cur;\n      auto [q_block, next_r] = div_2n_1n(r,\
    \ v);\n      q += shift_left_digits(q_block, block * n);\n      r = next_r;\n\
    \    }\n    q.trim();\n    r.trim();\n    return {q, r};\n  }\n\n  static std::pair<DecimalBigInteger,\
    \ DecimalBigInteger> divmod_abs(DecimalBigInteger u, DecimalBigInteger v) {\n\
    \    assert(!v.is_zero());\n    if(abs_compare(u, v) < 0) return {DecimalBigInteger(0),\
    \ u};\n    long long norm = base / (v.a.back() + 1);\n    u.mul_int(norm);\n \
    \   v.mul_int(norm);\n    int extra_base_shifts = 0;\n    if(v.a.size() > 128\
    \ && (v.a.size() & 1)) {\n      u = shift_left_digits(u, 1);\n      v = shift_left_digits(v,\
    \ 1);\n      extra_base_shifts = 1;\n    }\n    auto [q, r] = divmod_abs_bz(std::move(u),\
    \ std::move(v));\n    if(extra_base_shifts > 0) r = high_digits(r, extra_base_shifts);\n\
    \    r.div_int(norm);\n    q.trim();\n    r.trim();\n    return {q, r};\n  }\n\
    \n  friend std::pair<DecimalBigInteger, DecimalBigInteger> divmod(const DecimalBigInteger&\
    \ x, const DecimalBigInteger& y) {\n    assert(!y.is_zero());\n    auto [q, r]\
    \ = divmod_abs(x.abs(), y.abs());\n    q.sign = x.sign * y.sign;\n    r.sign =\
    \ x.sign;\n    q.trim();\n    r.trim();\n    return {q, r};\n  }\n\n  friend DecimalBigInteger\
    \ operator/(const DecimalBigInteger& x, const DecimalBigInteger& y) {\n    return\
    \ divmod(x, y).first;\n  }\n  friend DecimalBigInteger operator%(const DecimalBigInteger&\
    \ x, const DecimalBigInteger& y) {\n    return divmod(x, y).second;\n  }\n  DecimalBigInteger&\
    \ operator/=(const DecimalBigInteger& v) { return *this = *this / v; }\n  DecimalBigInteger&\
    \ operator%=(const DecimalBigInteger& v) { return *this = *this % v; }\n\n  friend\
    \ std::istream& operator>>(std::istream& is, DecimalBigInteger& v) {\n    std::string\
    \ s;\n    is >> s;\n    v.read(s);\n    return is;\n  }\n  friend std::ostream&\
    \ operator<<(std::ostream& os, const DecimalBigInteger& v) {\n    return os <<\
    \ v.to_string();\n  }\n};\n\n\n#line 5 \"test/verify/math/yosupo-addition-of-big-integers.test.cpp\"\
    \n\nint main() {\n  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);\n\n  int\
    \ T; cin >> T;\n  while(T--) {\n    DecimalBigInteger a, b;\n    cin >> a >> b;\n\
    \    cout << a + b << '\\n';\n  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/addition_of_big_integers\"\
    \n\n#include \"template/template.hpp\"\n#include \"math/decimal_big_integer.hpp\"\
    \n\nint main() {\n  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);\n\n  int\
    \ T; cin >> T;\n  while(T--) {\n    DecimalBigInteger a, b;\n    cin >> a >> b;\n\
    \    cout << a + b << '\\n';\n  }\n}\n"
  dependsOn:
  - template/template.hpp
  - math/decimal_big_integer.hpp
  isVerificationFile: true
  path: test/verify/math/yosupo-addition-of-big-integers.test.cpp
  requiredBy: []
  timestamp: '2026-06-28 00:46:41+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/verify/math/yosupo-addition-of-big-integers.test.cpp
layout: document
redirect_from:
- /verify/test/verify/math/yosupo-addition-of-big-integers.test.cpp
- /verify/test/verify/math/yosupo-addition-of-big-integers.test.cpp.html
title: test/verify/math/yosupo-addition-of-big-integers.test.cpp
---
