#ifndef HARUILIB_MATH_MODINT_HPP
#define HARUILIB_MATH_MODINT_HPP

template<int MOD>
struct static_modint {
    int value;

    constexpr static_modint() : value(0) {}

    constexpr static_modint(long long v) {
        value = int(((v % MOD) + MOD) % MOD);
    }

    constexpr static_modint& operator+=(const static_modint& other) {
        if ((value += other.value) >= MOD) value -= MOD;
        return *this;
    }

    constexpr static_modint& operator-=(const static_modint& other) {
        if ((value -= other.value) < 0) value += MOD;
        return *this;
    }

    constexpr static_modint& operator*=(const static_modint& other) {
        value = int((long long)value * other.value % MOD);
        return *this;
    }

    constexpr static_modint operator+(const static_modint& other) const {
        return static_modint(*this) += other;
    }

    constexpr static_modint operator-(const static_modint& other) const {
        return static_modint(*this) -= other;
    }

    constexpr static_modint operator*(const static_modint& other) const {
        return static_modint(*this) *= other;
    }

    constexpr static_modint pow(long long exp) const {
        static_modint base = *this, res = 1;
        while (exp > 0) {
            if (exp & 1) res *= base;
            base *= base;
            exp >>= 1;
        }
        return res;
    }

    constexpr static_modint inv() const {
        return pow(MOD - 2);
    }

    constexpr static_modint& operator/=(const static_modint& other) {
        return *this *= other.inv();
    }

    constexpr static_modint operator/(const static_modint& other) const {
        return static_modint(*this) /= other;
    }

    constexpr bool operator!=(const static_modint& other) const {
        return val() != other.val();
    }

    constexpr bool operator==(const static_modint& other) const {
        return val() == other.val();
    }

    int val() const {
      return this->value;
    }

    friend std::ostream& operator<<(std::ostream& os, const static_modint& mi) {
        return os << mi.value;
    }

    friend std::istream& operator>>(std::istream& is, static_modint& mi) {
        long long x;
        is >> x;
        mi = static_modint(x);
        return is;
    }
};

template <int mod>
using modint = static_modint<mod>;
using modint998244353  = modint<998244353>;
using modint1000000007 = modint<1000000007>;

#endif // HARUILIB_MATH_MODINT_HPP