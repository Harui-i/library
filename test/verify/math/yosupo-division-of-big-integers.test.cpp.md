---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: math/big_integer.hpp
    title: big_integer
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
    PROBLEM: https://judge.yosupo.jp/problem/division_of_big_integers
    links:
    - https://judge.yosupo.jp/problem/division_of_big_integers
  bundledCode: "#line 1 \"test/verify/math/yosupo-division-of-big-integers.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/division_of_big_integers\"\
    \n\n#line 1 \"template/template.hpp\"\n#include <iostream>\n#include <cassert>\n\
    using namespace std;\nusing ll = long long;\ntemplate<class T> inline bool chmax(T&\
    \ a, const T& b) {if (a<b) {a=b; return true;} return false;}\ntemplate<class\
    \ T> inline bool chmin(T& a, const T& b) {if (b<a) {a=b; return true;} return\
    \ false;}\nconst int INTINF = 1000001000;\nconst int INTMAX = 2147483647;\nconst\
    \ ll LLMAX = 9223372036854775807;\nconst ll LLINF = 1000000000000000000;\n#line\
    \ 1 \"math/big_integer.hpp\"\n\n\n\n#include <algorithm>\n#line 6 \"math/big_integer.hpp\"\
    \n#include <cctype>\n#include <cstdint>\n#include <iomanip>\n#line 10 \"math/big_integer.hpp\"\
    \n#include <string>\n#include <unordered_map>\n#include <utility>\n#include <vector>\n\
    \nnamespace big_integer_internal {\n\nusing ll = long long;\n\ntemplate<int MOD,\
    \ int G>\nstruct NTT {\n  static int mod_pow(int a, int e) {\n    long long r\
    \ = 1, x = a;\n    while(e > 0) {\n      if(e & 1) r = r * x % MOD;\n      x =\
    \ x * x % MOD;\n      e >>= 1;\n    }\n    return (int)r;\n  }\n\n  static void\
    \ ntt(std::vector<int>& a, bool inverse) {\n    int n = (int)a.size();\n    for(int\
    \ i=1, j=0; i<n; i++) {\n      int bit = n >> 1;\n      for(; j & bit; bit >>=\
    \ 1) j ^= bit;\n      j ^= bit;\n      if(i < j) std::swap(a[i], a[j]);\n    }\n\
    \n    for(int len=2; len<=n; len<<=1) {\n      int wlen = mod_pow(G, (MOD - 1)\
    \ / len);\n      if(inverse) wlen = mod_pow(wlen, MOD - 2);\n      for(int i=0;\
    \ i<n; i+=len) {\n        long long w = 1;\n        for(int j=0; j<len/2; j++)\
    \ {\n          int u = a[i + j];\n          int v = (int)(w * a[i + j + len /\
    \ 2] % MOD);\n          int x = u + v; if(x >= MOD) x -= MOD;\n          int y\
    \ = u - v; if(y < 0) y += MOD;\n          a[i + j] = x;\n          a[i + j + len\
    \ / 2] = y;\n          w = w * wlen % MOD;\n        }\n      }\n    }\n\n    if(inverse)\
    \ {\n      int inv_n = mod_pow(n, MOD - 2);\n      for(int& x: a) x = (int)((long\
    \ long)x * inv_n % MOD);\n    }\n  }\n\n  static std::vector<int> convolution(const\
    \ std::vector<int>& a, const std::vector<int>& b) {\n    if(a.empty() || b.empty())\
    \ return {};\n    int need = (int)a.size() + (int)b.size() - 1;\n    int n = 1;\n\
    \    while(n < need) n <<= 1;\n    std::vector<int> fa(a.begin(), a.end()), fb(b.begin(),\
    \ b.end());\n    fa.resize(n);\n    fb.resize(n);\n    ntt(fa, false);\n    ntt(fb,\
    \ false);\n    for(int i=0; i<n; i++) fa[i] = (int)((long long)fa[i] * fb[i] %\
    \ MOD);\n    ntt(fa, true);\n    fa.resize(need);\n    return fa;\n  }\n};\n\n\
    inline long long crt3(int x1, int x2, int x3) {\n  static constexpr long long\
    \ m1 = 998244353LL;\n  static constexpr long long m2 = 1004535809LL;\n  static\
    \ constexpr long long m3 = 469762049LL;\n  static const long long inv_m1_mod_m2\
    \ = NTT<1004535809, 3>::mod_pow((int)(m1 % m2), (int)m2 - 2);\n  static const\
    \ long long inv_m1m2_mod_m3 =\n      NTT<469762049, 3>::mod_pow((int)((__int128)m1\
    \ * m2 % m3), (int)m3 - 2);\n\n  long long t2 = (x2 - x1) % m2;\n  if(t2 < 0)\
    \ t2 += m2;\n  t2 = t2 * inv_m1_mod_m2 % m2;\n\n  long long x1_m3 = x1 % m3;\n\
    \  long long cur_m3 = (x1_m3 + (__int128)(m1 % m3) * (t2 % m3)) % m3;\n  long\
    \ long t3 = (x3 - cur_m3) % m3;\n  if(t3 < 0) t3 += m3;\n  t3 = t3 * inv_m1m2_mod_m3\
    \ % m3;\n\n  return (long long)(x1 + (__int128)m1 * t2 + (__int128)m1 * m2 * t3);\n\
    }\n\n} // namespace big_integer_internal\n\nstruct BigInteger {\n  using u32 =\
    \ std::uint32_t;\n  using u64 = std::uint64_t;\n  using u128 = unsigned __int128;\n\
    \  static constexpr u64 base = (1ULL << 32);\n\n  std::vector<u32> a;\n  int sign\
    \ = 1;\n\n  BigInteger() = default;\n  BigInteger(long long v) { *this = v; }\n\
    \  BigInteger(const std::string& s) { read(s); }\n\n  BigInteger& operator=(long\
    \ long v) {\n    sign = v < 0 ? -1 : 1;\n    u64 x = v < 0 ? (u64)(-(v + 1)) +\
    \ 1 : (u64)v;\n    a.clear();\n    while(x > 0) {\n      a.push_back((u32)x);\n\
    \      x >>= 32;\n    }\n    trim();\n    return *this;\n  }\n\n  bool is_zero()\
    \ const { return a.empty(); }\n\n  BigInteger& trim() {\n    while(!a.empty()\
    \ && a.back() == 0) a.pop_back();\n    if(a.empty()) sign = 1;\n    return *this;\n\
    \  }\n\n  BigInteger abs() const {\n    BigInteger res = *this;\n    res.sign\
    \ = 1;\n    return res;\n  }\n\n  void read(const std::string& s) {\n    int sgn\
    \ = 1;\n    sign = 1;\n    a.clear();\n    int pos = 0;\n    while(pos < (int)s.size()\
    \ && std::isspace((unsigned char)s[pos])) pos++;\n    if(pos < (int)s.size() &&\
    \ (s[pos] == '-' || s[pos] == '+')) {\n      if(s[pos] == '-') sgn = -1;\n   \
    \   pos++;\n    }\n    int end = pos;\n    while(end < (int)s.size() && std::isdigit((unsigned\
    \ char)s[end])) end++;\n    std::vector<int> dec;\n    for(int i=end; i>pos; i-=3)\
    \ {\n      int l = std::max(pos, i - 3);\n      int x = 0;\n      for(int j=l;\
    \ j<i; j++) x = x * 10 + (s[j] - '0');\n      dec.push_back(x);\n    }\n    *this\
    \ = from_decimal_chunks(dec, 0, (int)dec.size());\n    sign = sgn;\n    trim();\n\
    \  }\n\n  std::string to_string() const {\n    if(a.empty()) return \"0\";\n \
    \   std::vector<int> parts = to_decimal_chunks(a, 0, (int)a.size());\n    std::string\
    \ s = sign < 0 ? \"-\" : \"\";\n    s += std::to_string(parts.back());\n    for(int\
    \ i=(int)parts.size()-2; i>=0; i--) {\n      std::string t = std::to_string(parts[i]);\n\
    \      s += std::string(3 - (int)t.size(), '0') + t;\n    }\n    return s;\n \
    \ }\n\n  static int abs_compare(const BigInteger& x, const BigInteger& y) {\n\
    \    if(x.a.size() != y.a.size()) return x.a.size() < y.a.size() ? -1 : 1;\n \
    \   for(int i=(int)x.a.size()-1; i>=0; i--) {\n      if(x.a[i] != y.a[i]) return\
    \ x.a[i] < y.a[i] ? -1 : 1;\n    }\n    return 0;\n  }\n\n  friend bool operator<(const\
    \ BigInteger& x, const BigInteger& y) {\n    if(x.sign != y.sign) return x.sign\
    \ < y.sign;\n    int cmp = abs_compare(x, y);\n    return x.sign == 1 ? cmp <\
    \ 0 : cmp > 0;\n  }\n  friend bool operator==(const BigInteger& x, const BigInteger&\
    \ y) {\n    return x.sign == y.sign && x.a == y.a;\n  }\n  friend bool operator!=(const\
    \ BigInteger& x, const BigInteger& y) { return !(x == y); }\n  friend bool operator>(const\
    \ BigInteger& x, const BigInteger& y) { return y < x; }\n  friend bool operator<=(const\
    \ BigInteger& x, const BigInteger& y) { return !(y < x); }\n  friend bool operator>=(const\
    \ BigInteger& x, const BigInteger& y) { return !(x < y); }\n\n  BigInteger operator-()\
    \ const {\n    BigInteger res = *this;\n    if(!res.is_zero()) res.sign = -res.sign;\n\
    \    return res;\n  }\n\n  friend BigInteger operator+(BigInteger x, const BigInteger&\
    \ y) {\n    if(x.sign == y.sign) {\n      u64 carry = 0;\n      for(size_t i=0;\
    \ i<std::max(x.a.size(), y.a.size()) || carry; i++) {\n        if(i == x.a.size())\
    \ x.a.push_back(0);\n        u64 cur = carry + x.a[i] + (i < y.a.size() ? y.a[i]\
    \ : 0ULL);\n        x.a[i] = (u32)cur;\n        carry = cur >> 32;\n      }\n\
    \      return x;\n    }\n    return x - (-y);\n  }\n\n  friend BigInteger operator-(BigInteger\
    \ x, const BigInteger& y) {\n    if(y.is_zero()) return x;\n    if(x.sign == y.sign)\
    \ {\n      if(abs_compare(x, y) >= 0) {\n        u64 borrow = 0;\n        for(size_t\
    \ i=0; i<y.a.size() || borrow; i++) {\n          u64 sub = borrow + (i < y.a.size()\
    \ ? y.a[i] : 0ULL);\n          u64 cur = x.a[i];\n          x.a[i] = (u32)(cur\
    \ - sub);\n          borrow = cur < sub;\n        }\n        return x.trim();\n\
    \      }\n      return -(y - x);\n    }\n    return x + (-y);\n  }\n\n  static\
    \ std::vector<u32> multiply_digits(const std::vector<u32>& x, const std::vector<u32>&\
    \ y) {\n    if(x.empty() || y.empty()) return {};\n    if(std::min(x.size(), y.size())\
    \ <= 60) {\n      std::vector<u128> tmp(x.size() + y.size());\n      for(size_t\
    \ i=0; i<x.size(); i++) for(size_t j=0; j<y.size(); j++) {\n        tmp[i + j]\
    \ += (u128)x[i] * y[j];\n      }\n      std::vector<u32> res(tmp.size());\n  \
    \    u128 carry = 0;\n      for(size_t i=0; i<tmp.size(); i++) {\n        u128\
    \ cur = tmp[i] + carry;\n        res[i] = (u32)cur;\n        carry = cur >> 32;\n\
    \      }\n      while(carry > 0) {\n        res.push_back((u32)carry);\n     \
    \   carry >>= 32;\n      }\n      while(!res.empty() && res.back() == 0) res.pop_back();\n\
    \      return res;\n    }\n\n    auto split = [](const std::vector<u32>& v) {\n\
    \      std::vector<int> res;\n      res.reserve(v.size() * 4);\n      for(u32\
    \ x: v) {\n        res.push_back((int)(x & 255));\n        res.push_back((int)((x\
    \ >> 8) & 255));\n        res.push_back((int)((x >> 16) & 255));\n        res.push_back((int)(x\
    \ >> 24));\n      }\n      while(!res.empty() && res.back() == 0) res.pop_back();\n\
    \      return res;\n    };\n\n    using N1 = big_integer_internal::NTT<998244353,\
    \ 3>;\n    using N2 = big_integer_internal::NTT<1004535809, 3>;\n    using N3\
    \ = big_integer_internal::NTT<469762049, 3>;\n    std::vector<int> sx = split(x),\
    \ sy = split(y);\n    std::vector<int> c1 = N1::convolution(sx, sy);\n    std::vector<int>\
    \ c2 = N2::convolution(sx, sy);\n    std::vector<int> c3 = N3::convolution(sx,\
    \ sy);\n    std::vector<int> chunks(c1.size());\n    long long carry = 0;\n  \
    \  for(size_t i=0; i<c1.size(); i++) {\n      long long cur = big_integer_internal::crt3(c1[i],\
    \ c2[i], c3[i]) + carry;\n      chunks[i] = (int)(cur & 255);\n      carry = cur\
    \ >> 8;\n    }\n    while(carry > 0) {\n      chunks.push_back((int)(carry & 255));\n\
    \      carry >>= 8;\n    }\n\n    std::vector<u32> res;\n    res.reserve((chunks.size()\
    \ + 3) / 4);\n    for(size_t i=0; i<chunks.size(); i+=4) {\n      u32 cur = (u32)chunks[i];\n\
    \      if(i + 1 < chunks.size()) cur |= (u32)chunks[i + 1] << 8;\n      if(i +\
    \ 2 < chunks.size()) cur |= (u32)chunks[i + 2] << 16;\n      if(i + 3 < chunks.size())\
    \ cur |= (u32)chunks[i + 3] << 24;\n      res.push_back(cur);\n    }\n    while(!res.empty()\
    \ && res.back() == 0) res.pop_back();\n    return res;\n  }\n\n  static std::vector<int>\
    \ decimal_add(std::vector<int> x, const std::vector<int>& y) {\n    int carry\
    \ = 0;\n    for(size_t i=0; i<std::max(x.size(), y.size()) || carry; i++) {\n\
    \      if(i == x.size()) x.push_back(0);\n      int cur = x[i] + carry + (i <\
    \ y.size() ? y[i] : 0);\n      if(cur >= 1000) {\n        cur -= 1000;\n     \
    \   carry = 1;\n      } else {\n        carry = 0;\n      }\n      x[i] = cur;\n\
    \    }\n    while(!x.empty() && x.back() == 0) x.pop_back();\n    return x;\n\
    \  }\n\n  static std::vector<int> decimal_mul(const std::vector<int>& x, const\
    \ std::vector<int>& y) {\n    if(x.empty() || y.empty()) return {};\n    if(std::min(x.size(),\
    \ y.size()) <= 80) {\n      std::vector<long long> tmp(x.size() + y.size());\n\
    \      for(size_t i=0; i<x.size(); i++) for(size_t j=0; j<y.size(); j++) {\n \
    \       tmp[i + j] += (long long)x[i] * y[j];\n      }\n      std::vector<int>\
    \ res(tmp.size());\n      long long carry = 0;\n      for(size_t i=0; i<tmp.size();\
    \ i++) {\n        long long cur = tmp[i] + carry;\n        res[i] = (int)(cur\
    \ % 1000);\n        carry = cur / 1000;\n      }\n      while(carry > 0) {\n \
    \       res.push_back((int)(carry % 1000));\n        carry /= 1000;\n      }\n\
    \      while(!res.empty() && res.back() == 0) res.pop_back();\n      return res;\n\
    \    }\n\n    using N1 = big_integer_internal::NTT<998244353, 3>;\n    using N2\
    \ = big_integer_internal::NTT<1004535809, 3>;\n    using N3 = big_integer_internal::NTT<469762049,\
    \ 3>;\n    std::vector<int> c1 = N1::convolution(x, y);\n    std::vector<int>\
    \ c2 = N2::convolution(x, y);\n    std::vector<int> c3 = N3::convolution(x, y);\n\
    \    std::vector<int> res(c1.size());\n    long long carry = 0;\n    for(size_t\
    \ i=0; i<c1.size(); i++) {\n      long long cur = big_integer_internal::crt3(c1[i],\
    \ c2[i], c3[i]) + carry;\n      res[i] = (int)(cur % 1000);\n      carry = cur\
    \ / 1000;\n    }\n    while(carry > 0) {\n      res.push_back((int)(carry % 1000));\n\
    \      carry /= 1000;\n    }\n    while(!res.empty() && res.back() == 0) res.pop_back();\n\
    \    return res;\n  }\n\n  static std::vector<int> decimal_from_u64(u64 x) {\n\
    \    std::vector<int> res;\n    while(x > 0) {\n      res.push_back((int)(x %\
    \ 1000));\n      x /= 1000;\n    }\n    return res;\n  }\n\n  static BigInteger\
    \ pow1000_chunks(int n) {\n    static std::unordered_map<int, BigInteger> cache;\n\
    \    auto it = cache.find(n);\n    if(it != cache.end()) return it->second;\n\
    \    BigInteger res;\n    if(n == 0) {\n      res = 1;\n    } else if(n == 1)\
    \ {\n      res = 1000;\n    } else {\n      int m = n >> 1;\n      res = pow1000_chunks(m)\
    \ * pow1000_chunks(n - m);\n    }\n    cache.emplace(n, res);\n    return res;\n\
    \  }\n\n  static BigInteger from_decimal_chunks(const std::vector<int>& dec, int\
    \ l, int r) {\n    if(l >= r) return BigInteger(0);\n    if(r - l == 1) return\
    \ BigInteger(dec[l]);\n    int m = (l + r) >> 1;\n    BigInteger low = from_decimal_chunks(dec,\
    \ l, m);\n    BigInteger high = from_decimal_chunks(dec, m, r);\n    return low\
    \ + high * pow1000_chunks(m - l);\n  }\n\n  static std::vector<int> pow2_decimal_chunks(int\
    \ n) {\n    static std::unordered_map<int, std::vector<int>> cache;\n    auto\
    \ it = cache.find(n);\n    if(it != cache.end()) return it->second;\n    std::vector<int>\
    \ res;\n    if(n == 0) {\n      res = {1};\n    } else if(n == 1) {\n      res\
    \ = decimal_from_u64(base);\n    } else {\n      int m = n >> 1;\n      res =\
    \ decimal_mul(pow2_decimal_chunks(m), pow2_decimal_chunks(n - m));\n    }\n  \
    \  cache.emplace(n, res);\n    return res;\n  }\n\n  static std::vector<int> to_decimal_chunks(const\
    \ std::vector<u32>& limbs, int l, int r) {\n    if(l >= r) return {};\n    if(r\
    \ - l == 1) return decimal_from_u64(limbs[l]);\n    int m = (l + r) >> 1;\n  \
    \  std::vector<int> low = to_decimal_chunks(limbs, l, m);\n    std::vector<int>\
    \ high = to_decimal_chunks(limbs, m, r);\n    return decimal_add(low, decimal_mul(high,\
    \ pow2_decimal_chunks(m - l)));\n  }\n\n  friend BigInteger operator*(const BigInteger&\
    \ x, const BigInteger& y) {\n    BigInteger res;\n    res.sign = x.sign * y.sign;\n\
    \    res.a = multiply_digits(x.a, y.a);\n    return res.trim();\n  }\n\n  BigInteger&\
    \ operator+=(const BigInteger& v) { return *this = *this + v; }\n  BigInteger&\
    \ operator-=(const BigInteger& v) { return *this = *this - v; }\n  BigInteger&\
    \ operator*=(const BigInteger& v) { return *this = *this * v; }\n\n  void add_uint(u32\
    \ v) {\n    u64 carry = v;\n    for(size_t i=0; carry; i++) {\n      if(i == a.size())\
    \ a.push_back(0);\n      u64 cur = (u64)a[i] + carry;\n      a[i] = (u32)cur;\n\
    \      carry = cur >> 32;\n    }\n  }\n\n  void mul_uint(u32 m) {\n    if(m ==\
    \ 0 || is_zero()) {\n      a.clear();\n      sign = 1;\n      return;\n    }\n\
    \    u64 carry = 0;\n    for(size_t i=0; i<a.size() || carry; i++) {\n      if(i\
    \ == a.size()) a.push_back(0);\n      u64 cur = carry + (u64)a[i] * m;\n     \
    \ a[i] = (u32)cur;\n      carry = cur >> 32;\n    }\n    trim();\n  }\n\n  u32\
    \ div_uint(u32 v) {\n    assert(v > 0);\n    u64 rem = 0;\n    for(int i=(int)a.size()-1;\
    \ i>=0; i--) {\n      u64 cur = (rem << 32) | a[i];\n      a[i] = (u32)(cur /\
    \ v);\n      rem = cur % v;\n    }\n    trim();\n    return (u32)rem;\n  }\n\n\
    \  void shl_bits(int s) {\n    if(s == 0 || is_zero()) return;\n    u32 carry\
    \ = 0;\n    for(size_t i=0; i<a.size(); i++) {\n      u32 next = s == 0 ? 0 :\
    \ (a[i] >> (32 - s));\n      a[i] = (a[i] << s) | carry;\n      carry = next;\n\
    \    }\n    if(carry) a.push_back(carry);\n  }\n\n  void shr_bits(int s) {\n \
    \   if(s == 0 || is_zero()) return;\n    u32 carry = 0;\n    for(int i=(int)a.size()-1;\
    \ i>=0; i--) {\n      u32 next = a[i] << (32 - s);\n      a[i] = (a[i] >> s) |\
    \ carry;\n      carry = next;\n    }\n    trim();\n  }\n\n  static std::pair<BigInteger,\
    \ BigInteger> divmod_abs(BigInteger u, BigInteger v) {\n    assert(!v.is_zero());\n\
    \    if(abs_compare(u, v) < 0) return {BigInteger(0), u};\n    if(v.a.size() ==\
    \ 1) {\n      BigInteger q = u;\n      u32 r = q.div_uint(v.a[0]);\n      return\
    \ {q, BigInteger(r)};\n    }\n\n    int shift = __builtin_clz(v.a.back());\n \
    \   u.shl_bits(shift);\n    v.shl_bits(shift);\n    u.a.push_back(0);\n\n    int\
    \ n = (int)v.a.size();\n    int m = (int)u.a.size() - n - 1;\n    BigInteger q;\n\
    \    q.a.assign(m + 1, 0);\n\n    for(int j=m; j>=0; j--) {\n      u128 numerator\
    \ = ((u128)u.a[j + n] << 32) | u.a[j + n - 1];\n      u64 qhat = (u64)(numerator\
    \ / v.a[n - 1]);\n      u64 rhat = (u64)(numerator % v.a[n - 1]);\n      if(qhat\
    \ == base) qhat--;\n\n      while(n >= 2 && (u128)qhat * v.a[n - 2] > ((u128)rhat\
    \ << 32) + u.a[j + n - 2]) {\n        qhat--;\n        rhat += v.a[n - 1];\n \
    \       if(rhat >= base) break;\n      }\n\n      u64 borrow = 0;\n      u64 carry\
    \ = 0;\n      for(int i=0; i<n; i++) {\n        u128 prod = (u128)qhat * v.a[i]\
    \ + carry;\n        carry = (u64)(prod >> 32);\n        u64 low = (u32)prod;\n\
    \        u64 sub = low + borrow;\n        u64 cur = u.a[j + i];\n        u.a[j\
    \ + i] = (u32)(cur - sub);\n        borrow = (cur < sub);\n      }\n      u64\
    \ sub = carry + borrow;\n      u64 cur = u.a[j + n];\n      u.a[j + n] = (u32)(cur\
    \ - sub);\n      bool negative = cur < sub;\n\n      if(negative) {\n        qhat--;\n\
    \        u64 c = 0;\n        for(int i=0; i<n; i++) {\n          u64 sum = (u64)u.a[j\
    \ + i] + v.a[i] + c;\n          u.a[j + i] = (u32)sum;\n          c = sum >> 32;\n\
    \        }\n        u.a[j + n] += (u32)c;\n      }\n      q.a[j] = (u32)qhat;\n\
    \    }\n\n    q.trim();\n    u.shr_bits(shift);\n    u.trim();\n    return {q,\
    \ u};\n  }\n\n  friend std::pair<BigInteger, BigInteger> divmod(const BigInteger&\
    \ x, const BigInteger& y) {\n    assert(!y.is_zero());\n    auto [q, r] = divmod_abs(x.abs(),\
    \ y.abs());\n    q.sign = x.sign * y.sign;\n    r.sign = x.sign;\n    q.trim();\n\
    \    r.trim();\n    return {q, r};\n  }\n\n  friend BigInteger operator/(const\
    \ BigInteger& x, const BigInteger& y) {\n    return divmod(x, y).first;\n  }\n\
    \  friend BigInteger operator%(const BigInteger& x, const BigInteger& y) {\n \
    \   return divmod(x, y).second;\n  }\n  BigInteger& operator/=(const BigInteger&\
    \ v) { return *this = *this / v; }\n  BigInteger& operator%=(const BigInteger&\
    \ v) { return *this = *this % v; }\n\n  friend std::istream& operator>>(std::istream&\
    \ is, BigInteger& v) {\n    std::string s;\n    is >> s;\n    v.read(s);\n   \
    \ return is;\n  }\n  friend std::ostream& operator<<(std::ostream& os, const BigInteger&\
    \ v) {\n    return os << v.to_string();\n  }\n};\n\n\n#line 5 \"test/verify/math/yosupo-division-of-big-integers.test.cpp\"\
    \n\nint main() {\n  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);\n\n  int\
    \ T; cin >> T;\n  while(T--) {\n    BigInteger a, b;\n    cin >> a >> b;\n   \
    \ auto [q, r] = divmod(a, b);\n    cout << q << ' ' << r << '\\n';\n  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/division_of_big_integers\"\
    \n\n#include \"template/template.hpp\"\n#include \"math/big_integer.hpp\"\n\n\
    int main() {\n  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);\n\n  int T;\
    \ cin >> T;\n  while(T--) {\n    BigInteger a, b;\n    cin >> a >> b;\n    auto\
    \ [q, r] = divmod(a, b);\n    cout << q << ' ' << r << '\\n';\n  }\n}\n"
  dependsOn:
  - template/template.hpp
  - math/big_integer.hpp
  isVerificationFile: true
  path: test/verify/math/yosupo-division-of-big-integers.test.cpp
  requiredBy: []
  timestamp: '2026-05-11 00:50:29+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/verify/math/yosupo-division-of-big-integers.test.cpp
layout: document
redirect_from:
- /verify/test/verify/math/yosupo-division-of-big-integers.test.cpp
- /verify/test/verify/math/yosupo-division-of-big-integers.test.cpp.html
title: test/verify/math/yosupo-division-of-big-integers.test.cpp
---
