#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e3 + 5;

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

string N, A, B;
int nxt[maxn][10];
bigint dp[maxn][maxn][2];

bigint get(string A){
    /// add them so 0
    string pre = N;
    string bzero = "";
    for (int i = 1; i <= A.size() - 1; i ++)
        bzero += '0';
    N = bzero + N;
    int n = N.size();
    N = ' ' + N;

    for (int i = 0; i <= 9; i ++)
        nxt[n][i] = n + 1;
    for (int i = n-1; i >= 0; i --){
        for (int j = 0; j <= 9; j ++)
            nxt[i][j] = nxt[i+1][j];
        nxt[i][N[i+1]-'0'] = i + 1;
    }

    /// get ans
    int na = A.size();
    A = ' ' + A;

//    cout << N << '\n' << A << '\n';
//
//    cout << "get " << A << '\n';

    for (int i = 0; i <= n; i ++)
    for (int j = 0; j <= na; j ++)
        dp[i][j][0] = dp[i][j][1] = 0;

    dp[0][0][0] = 1;
    for (int i = 0; i < n; i ++)
    for (int j = 0; j < na; j ++)
    for (int t = 0; t <= 1; t ++) if ( dp[i][j][t] > 0 ){
//        cout << i << ' ' << j << ' ' << t << " : \n";
        for (int k = 0; k <= max(t*9, A[j+1]-'0'); k ++){
            dp[nxt[i][k]][j+1][t|(k < A[j+1]-'0')] += dp[i][j][t];
//            cout << " -> " << nxt[i][k] << ' ' << j+1  << ' ' << (t|(k < A[j+1]-'0')) << '\n';
        }
    }

    bigint ans = 0;
    for (int i = 1; i <= n; i ++)
        ans += dp[i][na][0] + dp[i][na][1];

//    cout << "-> " << ans << '\n';

    N = pre;

    return ans;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("trash.inp", "r") ){
        freopen("trash.inp", "r", stdin);
        freopen("trash.out", "w", stdout);
    }

    cin >> N >> A >> B;
    string bzero = "";

    if ( A.size() == 1 && A[0] == 0 ) cout << get(B);
    else{
        /// A --
        for (int i = A.size() - 1; i >= 0; i --)
            if ( A[i] == '0' ) A[i] = '9';
            else { A[i] --; break; }

        bigint ans = get(B);
        cout << ans - get(A) << '\n';
    }

    return 0;
}
