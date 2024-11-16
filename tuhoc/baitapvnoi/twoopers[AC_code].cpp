#include <iostream>

using namespace std;

string s, t; int n;
const long long MOD = 1e9 + 7;
long long pow26[100001], hashS[200000], hashT[100000], res;

long long getHashS(int i, int j) {
    if (i > j) return 0;
    if (i == 0) return hashS[j];
    return (hashS[j] - hashS[i - 1] * pow26[j - i + 1] + MOD * MOD) % MOD;
}

long long getHashT(int i, int j) {
    if (i > j) return 0;
    if (i == 0) return hashT[j];
    return (hashT[j] - hashT[i - 1] * pow26[j - i + 1] + MOD * MOD) % MOD;
}

int main() {
    cin >> s >> t;
    if (s.length() != t.length()) {
        cout << 0; return 0;
    }
    n = s.length();
    pow26[0] = 1;
    for (int i = 1; i <= n; i++)
        pow26[i] = pow26[i - 1] * 26 % MOD;
    s = s + s;
    hashS[0] = s[0] - 65;
    for (int i = 1; i < 2 * n; i++)
        hashS[i] = (hashS[i - 1] * 26 + s[i] - 65) % MOD;
    hashT[0] = t[0] - 65;
    for (int i = 1; i < n; i++)
        hashT[i] = (hashT[i - 1] * 26 + t[i] - 65) % MOD;
    for (int i = 0; i < n; i++) {
        int x = i - 1;
        for (int l = i, r = i + n - 1, m; l <= r;) {
            m = (l + r) / 2;
            if (getHashS(i, m) == hashT[m - i])
                x = m, l = m + 1;
            else r = m - 1;
        }
        if (x == i + n - 1) res += n;
        else if (getHashS(x + 2, i + n - 1) == getHashT(x - i + 2, n - 1))
            ++res;
    }
    cout << res;

}
