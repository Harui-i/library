---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: '#line 1 "debug.hpp"




    #ifdef LOCAL

    #define dbg(x) cerr << __LINE__ << " : " << #x << " = " << (x) << endl

    #else

    #define dbg(x) true

    #endif



    '
  code: '#ifndef HARUILIB_DEBUG_HPP

    #define HARUILIB_DEBUG_HPP


    #ifdef LOCAL

    #define dbg(x) cerr << __LINE__ << " : " << #x << " = " << (x) << endl

    #else

    #define dbg(x) true

    #endif


    #endif // HARUILIB_DEBUG_HPP

    '
  dependsOn: []
  isVerificationFile: false
  path: debug.hpp
  requiredBy: []
  timestamp: '2025-02-28 00:31:55+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: debug.hpp
layout: document
redirect_from:
- /library/debug.hpp
- /library/debug.hpp.html
title: debug.hpp
---
