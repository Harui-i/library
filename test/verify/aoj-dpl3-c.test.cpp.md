---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: dp/largest-rectangle-in-a-histogram.hpp
    title: "\u30D2\u30B9\u30C8\u30B0\u30E9\u30E0\u5185\u306E\u6700\u5927\u9577\u65B9\
      \u5F62"
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
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/all/DPL_3_C
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/all/DPL_3_C
  bundledCode: "#line 1 \"test/verify/aoj-dpl3-c.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/all/DPL_3_C\"\
    \n\n#line 1 \"template/template.hpp\"\n#include <iostream>\n#include <cassert>\n\
    using namespace std;\nusing ll = long long;\ntemplate<class T> inline bool chmax(T&\
    \ a, const T& b) {if (a<b) {a=b; return true;} return false;}\ntemplate<class\
    \ T> inline bool chmin(T& a, const T& b) {if (b<a) {a=b; return true;} return\
    \ false;}\nconst int INTINF = 1000001000;\nconst int INTMAX = 2147483647;\nconst\
    \ ll LLMAX = 9223372036854775807;\nconst ll LLINF = 1000000000000000000;\n#line\
    \ 1 \"dp/largest-rectangle-in-a-histogram.hpp\"\n\n\n#include <stack>\n#include\
    \ <vector>\n\ntemplate <typename T>\nlong long  largest_reactangle_in_a_histogram(std::vector<T>&\
    \ vec) {\n  int N = vec.size();\n  std::stack<T> st; // \u6700\u5F31\u756A\u9577\
    (\u3092index\u3067\u8868\u3057\u305F)\u5F85\u6A5F\u5217\u306E\u30A4\u30E1\u30FC\
    \u30B8\u3002\u5352\u696D\u306B\u3088\u308B\u5F15\u9000\u304C\u306A\u3044\u305F\
    \u3081\u3001deque\u306E\u53F3\u5074\u3057\u304B\u4F7F\u308F\u305A\u3001stack\u3067\
    \u5341\u5206\u3002\n  // stack\u306B\u5BFE\u5FDC\u3059\u308Bvec\u306E\u5024\u306F\
    \u3001\u4E0B\u304B\u3089\u4E0A\u306B\u304B\u3051\u3066\u72ED\u7FA9(!!)\u5358\u8ABF\
    \u5897\u52A0\u306B\u306A\u3063\u3066\u3044\u308B\u3002\n  std::vector<int> ridx(N);\
    \ // ridx[i] := i < j \u3067\u3042\u3063\u3066\u3001vec[i] > vec[j] \u3068\u306A\
    \u308B\u3088\u3046\u306A j\u306E\u3046\u3061\u6700\u3082\u5C0F\u3055\u3044\u3082\
    \u306E\n  // \u305D\u3093\u306Aj\u304C\u5B58\u5728\u3057\u306A\u3044\u5834\u5408\
    \u3001N\u306B\u3057\u3066\u3044\u308B\n\n  std::vector<int> lidx(N, -1); // lidx[i]\
    \ := j<i\u3067\u3042\u3063\u3066 vec[j] < vec[i]\u3068\u306A\u308B\u3088\u3046\
    \u306Aj\u306E\u3046\u3061\u6700\u3082\u5927\u304D\u3044\u3082\u306E \n  // \u305D\
    \u3093\u306Aj\u304C\u5B58\u5728\u3057\u306A\u3044\u5834\u5408\u3001-1\u3068\u3059\
    \u308B\n  // \u3064\u307E\u308A\u3001\u81EA\u5206\u3088\u308A\u5F31\u3044\u5148\
    \u8F29\u306E\u3046\u3061\u3001\u4E00\u756A\u5E74\u304C\u8FD1\u3044\u4EBA\u3001\
    \u307F\u305F\u3044\u306A\n\n  for(int i=0; i<N; i++) {\n    T vi = vec[i];\n \
    \   while (st.size() > 0) {\n\n      // \u81EA\u5206\u3088\u308A\u5F37\u3044(\u3082\
    \u3057\u304F\u306F\u540C\u3058\u5B9F\u529B\u306E)\u5148\u8F29\u306F\u5F15\u9000\
    \u3059\u308B\n      // \u5148\u8F29\u304C\u81EA\u5206\u3088\u308A\u5F37\u3044\u5834\
    \u5408\u306F\u3001\u5148\u8F29\u3092\u5929\u4E95\u3068\u3059\u308B\u3088\u3046\
    \u306A\u6700\u5927\u9577\u65B9\u5F62\u306F\u78BA\u5B9A\u3057\u3066\u3044\u308B\
    \u304B\u3089\u3082\u3046\u51FA\u3066\u3044\u3063\u3066\u3082\u3089\u3063\u3066\
    \u3044\u3044\u3057\u3001\n      // \u540C\u3058\u5B9F\u529B\u306E\u3068\u304D\u306F\
    \u3001\u81EA\u5206\u306E\u6700\u5927\u9577\u65B9\u5F62\u3068\u5148\u8F29\u306E\
    \u6700\u5927\u9577\u65B9\u5F62\u304C\u4E00\u81F4\u3059\u308B\u306E\u3067\u3001\
    \u5148\u8F29\u306F\u5F15\u9000\u3057\u3066\u3082\u3089\u3063\u3066\u3044\u3044\
    \u3002(\u3059\u308B\u3068\u3001\u30B9\u30BF\u30C3\u30AF\u304C\u72ED\u7FA9\u5358\
    \u8ABF\u5897\u52A0\u306B\u306A\u308B) \n      if (vec[st.top()] >= vi) {\n   \
    \     ridx[st.top()] = i; \n        st.pop();\n      }\n\n      else break; \n\
    \    }\n    // st\u306B\u306F\u81EA\u5206\u3088\u308A\u5F31\u3044\u5148\u8F29\u3060\
    \u3051\u304C\u6B8B\u3063\u3066\u3044\u308B\u3002\n    lidx[i] = st.empty() ? -1\
    \ : st.top();\n    st.push(i);\n  }\n\n  // \u81EA\u5206\u3088\u308A\u5F31\u3044\
    \u5F8C\u8F29\u304C\u5165\u3063\u3066\u6765\u306A\u304B\u3063\u305F\u4EBA\u305F\
    \u3061\u306E\u51E6\u7406\n  while (st.size() > 0) {\n    ridx[st.top()] = N;\n\
    \    st.pop();\n  }\n\n  ll ans = 0;\n  for(int i=0; i<N; i++) {\n    chmax(ans,\
    \ (ll)(ridx[i] - (lidx[i] + 1)) * vec[i]);\n  }\n  return ans; \n}\n\n#line 5\
    \ \"test/verify/aoj-dpl3-c.test.cpp\"\n\nint main() {\n  int N; cin >> N;\n  vector<int>h(N);\
    \ for(int i=0; i<N; i++) cin >> h[i];\n  cout << largest_reactangle_in_a_histogram<int>(h)\
    \ << endl;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/all/DPL_3_C\"\
    \n\n#include \"template/template.hpp\"\n#include \"dp/largest-rectangle-in-a-histogram.hpp\"\
    \n\nint main() {\n  int N; cin >> N;\n  vector<int>h(N); for(int i=0; i<N; i++)\
    \ cin >> h[i];\n  cout << largest_reactangle_in_a_histogram<int>(h) << endl;\n\
    }"
  dependsOn:
  - template/template.hpp
  - dp/largest-rectangle-in-a-histogram.hpp
  isVerificationFile: true
  path: test/verify/aoj-dpl3-c.test.cpp
  requiredBy: []
  timestamp: '2024-08-21 21:41:37+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/verify/aoj-dpl3-c.test.cpp
layout: document
redirect_from:
- /verify/test/verify/aoj-dpl3-c.test.cpp
- /verify/test/verify/aoj-dpl3-c.test.cpp.html
title: test/verify/aoj-dpl3-c.test.cpp
---
