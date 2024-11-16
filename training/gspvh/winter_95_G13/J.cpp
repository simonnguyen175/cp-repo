#include<bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define FORE(i, v) for (__typeof((v).begin()) i = (v).begin(); i != (v).end(); i++)
#define ALL(v) (v).begin(), (v).end()
#define IS_INF(x)   (std::isinf(x))
#define IS_NAN(x)   (std::isnan(x))
#define fi   first
#define se   second
#define MASK(i) (1LL << (i))
#define BIT(x, i) (((x) >> (i)) & 1)
#define div   ___div
#define next   ___next
#define prev   ___prev
#define left   ___left
#define right   ___right
#define __builtin_popcount __builtin_popcountll
using namespace std;
template<class X, class Y>
    bool minimize(X &x, const Y &y) {
        X eps = 1e-9;
        if (x > y + eps) {
            x = y;
            return true;
        } else return false;
    }
template<class X, class Y>
    bool maximize(X &x, const Y &y) {
        X eps = 1e-9;
        if (x + eps < y) {
            x = y;
            return true;
        } else return false;
    }
template<class T>
    T Abs(const T &x) {
        return (x < 0 ? -x : x);
    }

/* Author: Van Hanh Pham */

#define MAX_DIGIT   46
struct Bignum {
    static const int BASE = (int)1e9;
    int digits[MAX_DIGIT], numDigit;

    Bignum(long long x = 0) {
        memset(digits, 0, sizeof digits);
        numDigit = 0;

        if (x == 0) {
            numDigit = 1;
            return;
        }

        while (x > 0) {
            digits[numDigit++] = x % BASE;
            x /= BASE;
        }
    }

    void reset(void) {
        memset(digits, 0, sizeof digits);
        numDigit = 1;
    }

    Bignum& operator += (const Bignum &x) {
        maximize(numDigit, x.numDigit);
        int carry = 0;

        REP(i, x.numDigit) {
            digits[i] += x.digits[i] + carry;
            if (digits[i] >= BASE) {
                digits[i] -= BASE;
                carry = 1;
            } else carry = 0;
        }

        if (carry > 0) {
            int pos = x.numDigit;
            while (true) {
                digits[pos++]++;
                if (digits[pos - 1] == BASE) digits[pos - 1] = 0;
                else break;
            }
            maximize(numDigit, pos);
        }

        return *this;
    }

    Bignum operator + (const Bignum &x) const {
        Bignum res = *this;
        return res += x;
    }

    Bignum& operator -= (const Bignum &x) {
        int remain = 0;
        REP(i, x.numDigit) {
            digits[i] -= x.digits[i] + remain;
            if (digits[i] < 0) {
                digits[i] += BASE;
                remain = 1;
            } else remain = 0;
        }

        if (remain > 0) {
            int pos = x.numDigit;
            while (true) {
                digits[pos++]--;
                if (digits[pos - 1] < 0) digits[pos - 1] += BASE;
                else break;
            }
        }

        while (numDigit > 1 && digits[numDigit - 1] == 0) numDigit--;

        return *this;
    }

    Bignum operator - (const Bignum &x) const {
        Bignum res = *this;
        return res -= x;
    }

    Bignum operator * (const Bignum &x) const {
        if (isZero() || x.isZero()) return 0;
        Bignum res;
        REP(i, numDigit) if (digits[i] > 0) REP(j, x.numDigit) {
            long long tmp = 1LL * digits[i] * x.digits[j];
            int pos = i + j;
            while (tmp > 0) {
                res.digits[pos] += tmp % BASE;
                tmp /= BASE;
                if (res.digits[pos] >= BASE) {
                    res.digits[pos] -= BASE;
                    tmp++;
                }

                pos++;
            }
        }

        res.numDigit = numDigit + x.numDigit;
        if (res.digits[res.numDigit - 1] == 0) res.numDigit--;

        return res;
    }

    Bignum operator / (int k) const {
        Bignum res;
        res.numDigit = 0;

        int remain = 0;
        FORD(i, numDigit - 1, 0) {
            long long tmp = 1LL * remain * BASE + digits[i];
            res.digits[res.numDigit++] = tmp / k;
            remain = tmp % k;
        }

        reverse(res.digits, res.digits + res.numDigit);
        while (res.numDigit > 1 && res.digits[res.numDigit - 1] == 0) res.numDigit--;
        return res;
    }

    bool isZero(void) const {
        return numDigit == 1 && digits[0] == 0;
    }

    #define COMPARE(x, y) (((x) > (y)) - ((x) < (y)))
    int cmp(const Bignum &x) const {
        if (numDigit != x.numDigit) return COMPARE(numDigit, x.numDigit);
        FORD(i, numDigit - 1, 0) if (digits[i] != x.digits[i]) return COMPARE(digits[i], x.digits[i]);
        return 0;
    }

    #define DEFINE_OPERATOR(o) bool operator o (const Bignum &x) const { return cmp(x) o 0; }
    DEFINE_OPERATOR(<) DEFINE_OPERATOR(<=) DEFINE_OPERATOR(==)
    DEFINE_OPERATOR(>) DEFINE_OPERATOR(>=) DEFINE_OPERATOR(!=)
    #undef DEFINE_OPERATOR

    string toDecimal(void) const {
        string res;
        REP(i, numDigit) {
            int tmp = digits[i];
            REP(love, 9) {
                res.push_back(tmp % 10 + '0');
                tmp /= 10;
            }
        }
        while (res.size() > 1 && res.back() == '0') res.pop_back();
        reverse(res.begin(), res.end());
        return res;
    }
};

istream& operator >> (istream &is, Bignum &b) {
    string s; is >> s;

    reverse(ALL(s));
    b = 0;
    b.numDigit = (s.size() + 8) / 9;
    FORD(i, s.size() - 1, 0) b.digits[i / 9] = b.digits[i / 9] * 10 + s[i] - '0';

    return is;
}

ostream& operator << (ostream &os, const Bignum &b) {
    return os << b.toDecimal();
}


