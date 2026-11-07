---
title : あまりを管理するオートマトン(remainder.hpp)
documentation_of: //dp/automaton/remainder.hpp
---

10 進表記を左から読んで、値の `mod` での余りを状態として持つ DFA。

## `DecimalRemainderDfa`

```cpp
DecimalRemainderDfa dfa(mod);
```

状態数は `mod`。受理状態は余り `0`。

- 引数 `mod`: 正の整数。状態は $0,\ldots,mod-1$。
- `next_state(state, digit)`: `digit` は 10 進数字（$0\le digit\le9$）。次の余りを返す。
- `accept(state)`: 余り 0 の状態だけを受理する。
- 状態遷移の時間計算量: $O(1)$。

```cpp
int next_state(int state, int digit) {
  return (state * 10 + digit) % mod;
}
```

固定長 0 埋めの桁 DP で「通常の 10 進表記としての値」を扱いたい場合は、`LeadingZeroSkipDfa` で包む。

```cpp
DfaPtr<int> multiple_of_m = make_shared<LeadingZeroSkipDfa<int>>(
    make_shared<DecimalRemainderDfa>(m));
```

余りだけなら先頭 0 を読んでも値は変わらないが、他の通常表記向け DFA と同じ形で合成できるので、桁 DP では包んでおくと扱いが揃う。
