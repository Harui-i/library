#ifndef HARUILIB_LIBRARY_STRING_ROLLING_HASH_HPP
#define HARUILIB_LIBRARY_STRING_ROLLING_HASH_HPP

#include <iostream>
#include <vector>

#include "math/modint2611.hpp"

struct Hash {
  using mint = modint2611;
  mint hash;
  mint base;
  int len;

  constexpr Hash(mint _hash, mint _base, int _len): hash(_hash), base(_base), len(_len) {
  }

  // 文字列としての結合をしたあとのHashを返す
  constexpr Hash& operator+=(const Hash& rhs) {
    assert(base == rhs.base);
    hash += base.pow(len) * rhs.hash;
    len += rhs.len;
    return *this;
  }

  constexpr Hash operator+(const Hash& rhs) const {
    return Hash(*this) += rhs; 
  }

  constexpr bool operator==(const Hash& rhs) const {
    return len == rhs.len && hash == rhs.hash;
  }

  friend std::ostream& operator<<(std::ostream& os, const Hash& hash) {
    os << "Hash{len: ";
    os << hash.len;
    os << ", hash: ";
    os << hash.hash.val();
    os << ", base: ";
    os << hash.base.val();
    os << "}";
    return os;
  }
};

struct RollingHash {
  using mint = modint2611;
  std::vector<mint> hashes;
  mint base;
  constexpr RollingHash (const std::string& S, mint _base) : base(_base) {
    int N = int(S.size());
    hashes.resize(N+1);
    mint powb = base;
    for (int i=0; i<N; i++) {
      hashes[i+1] = hashes[i] + powb * mint(S[i]);
      powb *= base;
    }
  }

  constexpr Hash get(int l, int r) const {
    assert(0 <= l && l <= r && r < int(hashes.size()));
    mint hash_val = (hashes[r] - hashes[l])*(base.pow(l).inv());
    return Hash(hash_val, base, r-l);
  }

};


#endif // HARUILIB_LIBRARY_STRING_ROLLING_HASH_HPP
