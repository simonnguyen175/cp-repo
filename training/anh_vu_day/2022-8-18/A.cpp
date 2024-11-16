#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e2 + 5;
const int K = 1e3 + 5;
const ll oo = 1e15;

int n, m, k;
ll buy[N][K], sell[N][K], d[N][N], c[N][N], f[N][N];

bool check(ll mid){
    for (int i = 1; i <= n; i ++)
    for (int j = 1; j <= n; j ++){
        f[i][j] = oo;
        if ( i != j && d[i][j] != oo )
            f[i][j] = min(f[i][j], -c[i][j]+mid*min(oo/mid, d[i][j]));
    }

    for (int t = 1; t <= n; t ++)
    for (int i = 1; i <= n; i ++)
    for (int j = 1; j <= n; j ++)
        f[i][j] = min(oo, min(f[i][j], f[i][t]+f[t][j]));

    for (int i = 1; i <= n; i ++)
        if ( f[i][i] <= 0 ) return true;

    return false;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n >> m >> k;
    for (int i = 1; i <= n; i ++)
    for (int j = 1; j <= k; j ++)
        cin >> buy[i][j] >> sell[i][j];

    for (int i = 1; i <= n; i ++)
    for (int j = 1; j <= n; j ++)
        if ( i == j ) d[i][j] = 0;
        else d[i][j] = oo;

    for (int i = 1; i <= m; i ++){
        int u, v;
        ll w;
        cin >> u >> v >> w;
        d[u][v] = w;
    }

    for (int t = 1; t <= n; t ++)
    for (int i = 1; i <= n; i ++)
    for (int j = 1; j <= n; j ++)
        d[i][j] = min(d[i][j], d[i][t]+d[t][j]);

    for (int i = 1; i <= n; i ++)
    for (int j = 1; j <= n; j ++) if ( i != j ){
        for (int t = 1; t <= k; t ++) if ( buy[i][t] != -1 && sell[j][t] != -1 )
            c[i][j] = max(c[i][j], sell[j][t]-buy[i][t]);
    }

    ll lo = 1, hi = 1e15, res = 0;
    while ( lo <= hi ){
        ll mid = ( lo + hi ) / 2;
        if ( check(mid) ) res = mid, lo = mid + 1;
        else hi = mid - 1;
    }

    cout << res;

    return 0;
}
