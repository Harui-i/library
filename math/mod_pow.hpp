#pragma once

template <typename T>
T mod_pow(T x, ll a, const T &p) {
  assert(a >= 0);
  T ret = 1;
  while(a > 0) {
    if (a % 2 == 1) {
      ret = ret * x;
      ret %= p;
    }

    x = x * x;
    x %= p;
    a /= 2;
  }
  return ret;
}
