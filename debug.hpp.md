---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://harui-i.github.io/library/debug.hpp.html
  bundledCode: "#line 1 \"debug.hpp\"\n\n\n// https://harui-i.github.io/library/debug.hpp.html\n\
    \n#ifdef LOCAL\n#define dbg(x) std::cerr << __LINE__ << \" : \" << #x << \" =\
    \ \" << (x) << std::endl\n#else\n#define dbg(x) true\n#endif\n\n#include <iostream>\n\
    #include <vector>\n#include <utility>\n#include <set>\n#include <array>\n\n\n\
    template <typename T, typename U>\nstd::ostream& operator<<(std::ostream& os,\
    \ const std::pair<T, U>& p) {\n  os << '(' << p.first << \", \" << p.second <<\
    \ ')';\n  return os;\n}\n\ntemplate <typename T>\nstd::ostream& operator<<(std::ostream&\
    \ os, const std::vector<T>& vec) {\n  os << '[';\n  for (int i=0; i<int(vec.size());\
    \ i++) {\n    os << vec[i];\n    if (i != int(vec.size())-1) os << \", \";\n \
    \ }\n  os << ']';\n  return os;\n}\n\ntemplate <typename T, std::size_t N>\nstd::ostream&\
    \ operator<<(std::ostream& os, const std::array<T, N>& arr) {\n  os << '[';\n\
    \  for (int i=0; i<int(N); i++) {\n    os << arr[i];\n    if (i != int(N)-1) os\
    \ << \", \";\n  }\n  os << ']';\n  return os;\n}\n\ntemplate <typename T>\nstd::ostream&\
    \ operator<<(std::ostream& os, const std::set<T>& st) {\n  os << '{';\n  auto\
    \ itr = st.begin();\n  while (itr != st.end()) {\n    os << *itr;\n    itr = next(itr);\n\
    \    if (itr != st.end()) os << \", \";\n  }\n  os << '}';\n  return os;\n}\n\n\
    \n\n"
  code: "#ifndef HARUILIB_DEBUG_HPP\n#define HARUILIB_DEBUG_HPP\n// https://harui-i.github.io/library/debug.hpp.html\n\
    \n#ifdef LOCAL\n#define dbg(x) std::cerr << __LINE__ << \" : \" << #x << \" =\
    \ \" << (x) << std::endl\n#else\n#define dbg(x) true\n#endif\n\n#include <iostream>\n\
    #include <vector>\n#include <utility>\n#include <set>\n#include <array>\n\n\n\
    template <typename T, typename U>\nstd::ostream& operator<<(std::ostream& os,\
    \ const std::pair<T, U>& p) {\n  os << '(' << p.first << \", \" << p.second <<\
    \ ')';\n  return os;\n}\n\ntemplate <typename T>\nstd::ostream& operator<<(std::ostream&\
    \ os, const std::vector<T>& vec) {\n  os << '[';\n  for (int i=0; i<int(vec.size());\
    \ i++) {\n    os << vec[i];\n    if (i != int(vec.size())-1) os << \", \";\n \
    \ }\n  os << ']';\n  return os;\n}\n\ntemplate <typename T, std::size_t N>\nstd::ostream&\
    \ operator<<(std::ostream& os, const std::array<T, N>& arr) {\n  os << '[';\n\
    \  for (int i=0; i<int(N); i++) {\n    os << arr[i];\n    if (i != int(N)-1) os\
    \ << \", \";\n  }\n  os << ']';\n  return os;\n}\n\ntemplate <typename T>\nstd::ostream&\
    \ operator<<(std::ostream& os, const std::set<T>& st) {\n  os << '{';\n  auto\
    \ itr = st.begin();\n  while (itr != st.end()) {\n    os << *itr;\n    itr = next(itr);\n\
    \    if (itr != st.end()) os << \", \";\n  }\n  os << '}';\n  return os;\n}\n\n\
    \n#endif // HARUILIB_DEBUG_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: debug.hpp
  requiredBy: []
  timestamp: '2026-10-17 23:49:45+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: debug.hpp
layout: document
redirect_from:
- /library/debug.hpp
- /library/debug.hpp.html
title: debug.hpp
---
