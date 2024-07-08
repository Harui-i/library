---
titel: Fidduciaのアルゴリズム (きたまさ法?)
documentation_of: //formal-power-series/fidducia.hpp
---

なんかLibrary Checkerは通らないが、Typical DP Contest Tのフィボナッチは(NaiveなFPSを使うことで)通った。

提出: [https://atcoder.jp/contests/tdpc/submissions/55372657]

Fiducciaの論文はarchive.orgにあったきがする。ACMのだったはず。

参考にしたもの: [https://qiita.com/ryuhe1/items/da5acbcce4ac1911f47a] のFidduciaのアルゴリズム ~ 二種類の繰り返し二乗法あたりまで。

## Fidducia

```
mint Fidducia(const vector<mint>& a, const vector<mint>& c, unsigned long long N)
```

$a_{n+K}= c_1 a_{n+K-1} + c_2 a_{n+k-2} + \dots + c_{K-1} a_{n+1} + c_K a_n $
という線型漸化式が与えられて、初項

$ a_0, a_1, \dots, a_{K-1} $ がわかっているときに、$a_N$を求める。


### 計算量

畳み込みがFFTなどで高速化されるなら
- $ O(K log K log N) $

ナイーブな畳み込みを使うなら

- $ O(K^2 log N) $
