#ifndef HARUILIB_DEBUG_HPP
#define HARUILIB_DEBUG_HPP

#ifdef LOCAL
#define dbg(x) cerr << __LINE__ << " : " << #x << " = " << (x) << endl
#else
#define dbg(x) true
#endif

#include <iostream>
#include <vector>
#include <utility>
#include <set>

template <typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& vec) {
  os << '[';
  for (int i=0; i<int(vec.size()); i++) {
    os << vec[i];
    if (i != int(vec.size())-1) os << ", ";
  }
  os << ']';
  return os;
}

template <typename T, typename U>
std::ostream& operator<<(std::ostream& os, const std::pair<T, U>& p) {
  os << '(' << p.first << ", " << p.second << ')';
  return os;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const std::set<T>& st) {
  os << '{';
  auto itr = st.begin();
  while (itr != st.end()) {
    os << *itr;
    itr = next(itr);
    if (itr != st.end()) os << ", ";
  }
  os << '}';
  return os;
}


#endif // HARUILIB_DEBUG_HPP
