#ifndef HARUILIB_DEBUG_HPP
#define HARUILIB_DEBUG_HPP

#ifdef LOCAL
#define dbg(x) cerr << __LINE__ << " : " << #x << " = " << (x) << endl
#else
#define dbg(x) true
#endif

#endif // HARUILIB_DEBUG_HPP
