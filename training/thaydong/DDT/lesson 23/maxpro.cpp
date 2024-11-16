#include<bits/stdc++.h>
using namespace std;

struct bigint : basic_string <int> {

    static const int base = 1000;
    static const int len = log10(base);

    void normalize() {
        push_back(0);
        for (int i = 0; i < int(size()) - 1; i++) {
            at(i + 1) += at(i) / base; at(i) %= base;
            if (at(i) < 0) {
                at(i) += base; at(i + 1)--;
            }
        }
        while (!empty() && back() == 0) pop_back();
    }

    bigint() {}

    bigint(int x) {
        while (x > 0) {
            push_back(x % base); x /= base;
        }
        normalize();
    }

    bigint(long long x) {
        while (x > 0) {
            push_back(x % base); x /= base;
        }
        normalize();
    }

    bigint(const string &s) {
        resize(s.size() / len + 1);
        for (int i = 0, pos; i < int(s.size()); i++) {
            pos = (s.size() - i - 1) / len;
            at(pos) = at(pos) * 10 + s[i] - '0';
        }
        normalize();
    }

    friend int comp(const bigint &a, const bigint &b) {
        if (a.size() != b.size())
            return (a.size() - b.size());
        for (int i = a.size() - 1; i >= 0; i--)
            if (a[i] != b[i]) return (a[i] - b[i]);
        return 0;
    }

    friend ostream& operator << (ostream &os, const bigint &a) {
        if (a.empty()) return os << "0"; os << a.back();
        for (int i = a.size() - 2; i >= 0; i--)
            os << setw(len) << setfill('0') << a[i];
        return os;
    }

    friend istream& operator >> (istream &is, bigint &a) {
        string s; is >> s; a = bigint(s); return is;
    }

    friend bool operator < (const bigint &a, const bigint &b) {
        return comp(a, b) < 0;
    }

    friend bool operator <= (const bigint &a, const bigint &b) {
        return comp(a, b) <= 0;
    }

    friend bool operator > (const bigint &a, const bigint &b) {
        return comp(a, b) > 0;
    }

    friend bool operator >= (const bigint &a, const bigint &b) {
        return comp(a, b) >= 0;
    }

    friend bigint operator + (const bigint &a, const bigint &b) {
        bigint res = a;
        res.resize(max(a.size(), b.size()));
        for (int i = 0; i < int(b.size()); i++)
            res[i] += b[i];
        res.normalize(); return res;
    }

    friend bigint operator - (const bigint &a, const bigint &b) {
        bigint res = a;
        for (int i = 0; i < int(b.size()); i++)
            res[i] -= b[i];
        res.normalize(); return res;
    }

    friend bigint operator * (const bigint &a, const bigint &b) {
        bigint res;
        res.resize(a.size() + b.size());
        for (int i = 0; i < int(a.size()); i++)
            for (int j = 0; j < int(b.size()); j++)
                res[i + j] += a[i] * b[j];
        res.normalize(); return res;
    }

    friend void operator += (bigint &a, const bigint &b) {
        a = a + b;
    }

    friend void operator -= (bigint &a, const bigint &b) {
        a = a - b;
    }

    friend void operator *= (bigint &a, const bigint &b) {
        a = a * b;
    }
};

int n;
bigint ans;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("maxpro.inp", "r") ){
        freopen("maxpro.inp", "r", stdin);
        freopen("maxpro.out", "w", stdout);
    }

    int n;
    cin >> n;

    if ( n <= 2 ) { cout << n; return 0; }

    bigint ans = bigint(2);

    // mn = 2
    bigint sum = bigint(2), cur = bigint(2), fact = bigint(2);
    while ( sum <= n ){
        bigint x = cur + bigint(2);
        bigint t = sum + x;
        bigint tmp = fact * x;
        if ( sum == bigint(n) ) ans = max(ans, fact);

        while ( t + x + bigint(1) <= n ){
            x += bigint(1);
            t += x;
            tmp *= x;
        }

        if ( t == bigint(n) ) ans = max(ans, tmp);

        cur += bigint(1);
        sum += cur;
        fact *= cur;
    }

    // mn = 3
    sum = bigint(3), cur = bigint(3), fact = bigint(3);
    while ( sum <= n ){
        bigint x = cur + bigint(2);
        bigint t = sum + x;
        bigint tmp = fact * x;
        if ( sum == bigint(n) ) ans = max(ans, fact);

        while ( t + x + bigint(1) <= n ){
            x += bigint(1);
            t += x;
            tmp *= x;
        }

        if ( t <= bigint(n) ) ans = max(ans, tmp);

        cur += bigint(1);
        sum += cur;
        fact *= cur;
    }

    cout << ans;

    return 0;
}
