#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5 + 5;
const ll oo = 1e15;

int n, m, k;
string s;
ll a[30][30], c[30][30], cost[N][30], f[N][30], mn[N];

void init(){
    cin >> n >> m >> k >> s;
    s = ' ' + s;
    for (int i = 1; i <= m; i ++)
    for (int j = 1; j <= m; j ++)
            cin >> a[i][j];

    for (int i = 1; i <= m; i ++)
    for (int j = 1; j <= m; j ++)
        if ( i == j ) c[i][j] = 0;
        else c[i][j] = a[i][j];

    for (int l = 1; l <= m; l ++)
    for (int i = 1; i <= m; i ++)
    for (int j = 1; j <= m; j ++)
        if ( c[i][l] + c[l][j] < c[i][j] )
            c[i][j] = c[i][l] + c[l][j];

    for (int i = 1; i <= m; i ++){
        for (int j = 1; j <= k; j ++)
            cost[k][i] += c[s[j]-'a'+1][i];
        for (int j = k+1; j <= n; j ++)
            cost[j][i] = cost[j-1][i] - c[s[j-k]-'a'+1][i] + c[s[j]-'a'+1][i];
    }
}

void solve(){
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= m; j ++)
            f[i][j] = oo;
    for (int i = 1; i <= n; i ++) mn[i] = oo;

    for (int i = 1; i <= m; i ++) f[0][i] = 0;
    mn[0] = 0;

    for (int i = k; i <= n; i ++)
    for (int j = 1; j <= m; j ++){
            f[i][j] = min(mn[i-k] + cost[i][j], f[i-1][j] + c[s[i]-'a'+1][j]);
            mn[i] = min(mn[i], f[i][j]);
    }

    ll ans = oo;
    for (int i = 1; i <= m; i ++)
        ans = min(ans, f[n][i]);

    cout << ans;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cin.tie(0);
    init();
    solve();
    return 0;
}
