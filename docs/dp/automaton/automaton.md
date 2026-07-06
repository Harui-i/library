---
title: 決定性有限オートマトン(DFA, Deterministic Finite Automaton)
documentation_of: //dp/automaton/automaton.hpp
---

有限個の状態を `int` で管理する DFA。

桁 DP などで、「上限以下」「余りが 0」「パターンを満たす」のような条件をそれぞれ DFA として書き、それらを積 DFA で合成して使うことを想定している。

## 使い方の流れ

1. 条件を 1 つずつ DFA として書く
2. `AndDfa` や `ProductPolicyDfa` で条件を合成する
3. `count_fixed_length` で長さ固定の列を全部流して数える

「`0 <= x <= N` かつ `x` が条件を満たす数を数える」タイプの桁 DP では、`N` の桁数に合わせて 0 埋めした文字列を考える。

```cpp
vector<int> alphabet = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

DfaPtr<int> less_equal = make_shared<DecimalLessEqualDfa>(N);
DfaPtr<int> condition = make_shared<LeadingZeroSkipDfa<int>>(
    make_shared<MyDecimalConditionDfa>());

DfaPtr<int> whole = make_shared<AndDfa<int>>(less_equal, condition);
mint ans = count_fixed_length<mint>(*whole, alphabet, N.size());
```

`DecimalLessEqualDfa` は 0 埋めされた固定長文字列をそのまま `N` と比較する。
一方で、通常の 10 進表記に対する条件 DFA は先頭 0 を読ませると意味が変わることがあるので、必要なら `LeadingZeroSkipDfa` で包む。

例: `N = "123"` のとき、DP は `"000"` から `"999"` までの長さ 3 の文字列を読む。
`DecimalLessEqualDfa("123")` は `"007"` を 7 として `<= 123` と判定できる。
`LeadingZeroSkipDfa` は内側の DFA に `"007"` を `"7"` として読ませる。

## DFA の書き方

```cpp
template <typename Alphabet = int>
struct Dfa {
  virtual int state_count() const = 0;
  virtual int initial_state() const = 0;
  virtual int next_state(int state, Alphabet c) const = 0;
  virtual bool accept(int state) const = 0;
};
```

状態は `0, 1, ..., state_count() - 1` の整数にエンコードする。

- `state_count()`: 状態数
- `initial_state()`: 初期状態
- `next_state(state, c)`: 状態 `state` で文字 `c` を読んだ後の状態
- `accept(state)`: 最終状態 `state` を受理するか

問題固有の条件はこの 4 つだけ実装すればよい。

```cpp
class Contains3Dfa : public Dfa<int> {
public:
  int state_count() const override { return 2; }
  int initial_state() const override { return 0; }

  int next_state(int state, int digit) const override {
    return state || digit == 3;
  }

  bool accept(int state) const override {
    return state == 1;
  }
};
```

## 合成

- `AndDfa`: 2 つの DFA の両方が受理する文字列を受理する積 DFA
- `ProductPolicyDfa`: 任意個の DFA を積にして、受理状態の真偽列から受理判定を決める DFA

```cpp
DfaPtr<int> a = make_shared<A>();
DfaPtr<int> b = make_shared<B>();
DfaPtr<int> both = make_shared<AndDfa<int>>(a, b);
```

「3 つの条件のうちちょうど 1 つを満たす」のような受理条件は `ProductPolicyDfa` を使う。

```cpp
vector<DfaPtr<int>> conditions = {a, b, c};

DfaPtr<int> exactly_one = make_shared<ProductPolicyDfa<int>>(
    conditions,
    [](const vector<bool>& ok) {
      int cnt = 0;
      for(bool x : ok) if(x) cnt++;
      return cnt == 1;
    });
```

## 用意してある DFA / wrapper

### `DecimalLessEqualDfa`

固定長 0 埋め 10 進文字列として読んだ値が `N` 以下なら受理する。
桁 DP の tight に相当する。

```cpp
DfaPtr<int> less_equal = make_shared<DecimalLessEqualDfa>(N);
```

### `LeadingZeroSkipDfa`

先頭 0 を内側の DFA に流さない wrapper。
全桁が 0 の場合は、内側の DFA に 0 を 1 回だけ読ませた状態で受理判定する。

```cpp
DfaPtr<int> normal_decimal_condition = make_shared<LeadingZeroSkipDfa<int>>(
    make_shared<MyDecimalConditionDfa>());
```

`DecimalRemainderDfa` やジグザグ数 DFA のように「普通の 10 進表記」を読む DFA は、固定長 DP で使うとき基本的にこれで包む。

## 数え上げ

`count_fixed_length<T>(dfa, alphabet, length)` は、長さ `length` の列をすべて DFA に流し、受理されるものの個数を `T` で返す。
`T` は `+=` と `T(0)`, `T(1)` が使えればよいので、`modint` を渡せる。

```cpp
mint ans = count_fixed_length<mint>(*dfa, alphabet, L);
```

## Verify

- `test/verify/aoj-0570.test.cpp`

AOJ 0570 は「`A <= x <= B`」「`x % M == 0`」「`x` がジグザグ数」の 3 条件を DFA として合成して解いている。
区間 `[A, B]` は `count(<= B) - count(<= A - 1)` で処理している。
