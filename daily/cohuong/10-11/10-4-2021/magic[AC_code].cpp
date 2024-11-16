#include<bits/stdc++.h>
#define int long  long
using namespace std;

const int N = 1e5 + 4, MOD = 1e9+7;
int n, k, a[N], vis[N], CountChar[60];
string str;

struct data {
    int diff[60], k;
    bool operator < (const data &a) const {
        for (int i = 1; i <= k; ++i) {
            if (diff[i] < a.diff[i]) return true;
            if (diff[i] > a.diff[i]) return false;
        }
        return false;
    }
} tmp;
map<data, int> Map;

void sol() {
    tmp.k = k;
    for (int i = 1; i <= k; ++i) tmp.diff[i] = 0; Map[tmp] = 1;

    int res = 0;
    for (int i = 1; i <= n; ++i) {
        CountChar[a[i]]++;
        for (int j = 1; j <= k; ++j) tmp.diff[j] = CountChar[j] - CountChar[1];
        res = (res + Map[tmp]) % MOD;
        Map[tmp] = (Map[tmp] + 1) % MOD;
    }
    cout << res;
}

#undef int
int main() {
#define int             long long
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
   
    freopen("magic.inp", "r", stdin);
    freopen("magic.out", "w", stdout);
    
    cin >> n >> str;
    for (int i = 1; i <= n; ++i) {
        if (!vis[str[i-1]]) vis[str[i-1]] = ++k;
        a[i] = vis[str[i-1]];
    }

    sol();

    return 0;
}
