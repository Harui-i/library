#ifndef HARUILIB_TEMPLATE_TEMPLATE_HPP
#define HARUILIB_TEMPLATE_TEMPLATE_HPP
// https://harui-i.github.io/library/template/template.hpp.html

#include <iostream>
#include <cassert>
using namespace std;
using ll = long long;
template<class T> inline bool chmax(T& a, const T& b) {if (a<b) {a=b; return true;} return false;}
template<class T> inline bool chmin(T& a, const T& b) {if (b<a) {a=b; return true;} return false;}
const int INTINF = 1000001000;
const int INTMAX = 2147483647;
const ll LLMAX = 9223372036854775807;
const ll LLINF = 1000000000000000000;

#endif
