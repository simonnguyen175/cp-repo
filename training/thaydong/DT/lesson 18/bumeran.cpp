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

string s;
int n;
int nxt[255][2];
bigint dp[255][255];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("trash.inp", "r") ){
        freopen("trash.inp", "r", stdin);
        freopen("trash.out", "w", stdout);
    }

    cin >> s;
    n = s.size();
    s = ' ' + s;

    nxt[n][0] = nxt[n][1] = n+1;
    for (int i = n-1; i >= 0; i --){
        nxt[i][0] = nxt[i+1][0];
        nxt[i][1] = nxt[i+1][1];

        if ( s[i+1] == 'F' ) nxt[i][0] = i + 1;
        else nxt[i][1] = i + 1;
    }

    dp[0][0] = 1;
    for (int i = 0; i <= n; i ++)
    for (int j = 0; j <= n; j ++) if ( dp[i][j] > 0 ){
        dp[nxt[i][0]][j+1] += dp[i][j];
        if ( j ) dp[nxt[i][1]][j-1] += dp[i][j];
    }

    bigint ans = 0;
    for (int i = 1; i <= n; i ++)
        ans += dp[i][0];

    cout << ans;

    return 0;
}
