#include<bits/stdc++.h>
using namespace std;
const int N = 3e2 + 5;
const int oo = 1e9;

int t, n, k;
string a[N];
int f[N][N], c[N][N];

int getpre(string s1, string s2){
    int res = 0;
    for (int i = 1; i <= min(s1.size(), s2.size()); i ++)
        if ( s1[i-1] == s2[i-1] ) res = i;
        else break;
    return res;
}

void solve(){
    cin >> n >> k;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];

    sort(a + 1, a + 1 + n);

    for (int i = 1; i <= n; i ++)
        c[0][i] = a[i].size() + 1;

    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= n; j ++)
            c[i][j] = a[i].size() + a[j].size() - 2 * getpre(a[i], a[j]) + 1;

    for (int i = 0; i <= n; i ++)
        for (int j = 1; j <= k; j ++)
            f[i][j] = oo;

    f[0][0] = 0;

    for (int t = 1; t <= k; t ++)
    for (int i = 1; i <= n; i ++)
    for (int j = 0; j < i; j ++)
        f[i][t] = min(f[i][t], f[j][t-1] + c[j][i]);

    int ans = oo;
    for (int i = 1; i <= n; i ++)
        ans = min(ans, f[i][k] + (int)a[i].size());

    cout << ans << '\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> t;
    while ( t -- )
        solve();
    return 0;
}
