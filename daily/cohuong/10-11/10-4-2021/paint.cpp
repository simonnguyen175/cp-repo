#include<bits/stdc++.h>
#define simon "paint"
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define BIT(x, k) ((x>>k)&1)
#define ll long long
#define pb push_back
using namespace std;
const ll oo = 1e10;
const int N = 1e3 + 5;

int m, n;
ll a[20][N], f[N][9000], c[N][9000];
vector<int> adj[9000];

int main(){
    FASTio
    if ( fopen(simon".inp", "r") ){
        freopen(simon".inp", "r", stdin);
        freopen(simon".out", "w", stdout);
    }

    cin >> m >> n;

    for (int i = 1; i <= m; i ++)
    for (int j = 1; j <= n; j ++)
        cin >> a[i][j];

    for (int i = 1; i <= n; i ++)
    for (int mask = 0; mask < (1<<m); mask ++)
        f[i][mask] = -oo;

    for (int i = 1; i <= n; i ++)
    for (int mask = 0; mask < (1<<m); mask ++){
        c[i][mask] = 0;
        for (int j = 1; j <= m; j ++)
            if ( BIT(mask, j-1) ) c[i][mask] += a[j][i];
    }

    for (int masku = 0; masku < (1<<m); masku ++)
    for (int maskv = 0; maskv < (1<<m); maskv ++){
        bool flag = 1;
        for (int i = 1; i < m; i ++){
            int o[5], cnt = 0;
            o[1] = BIT(masku, i-1), o[2] = BIT(maskv, i-1);
            o[3] = BIT(masku, i), o[4] = BIT(maskv, i);
            for (int i = 1; i <= 4; i ++)
                if ( o[i] ) cnt ++;
            if ( cnt % 2 == 0 ) { flag = 0; break; }
        }
        if ( flag ){
            adj[masku].pb(maskv);
        }
    }

    for (int mask = 0; mask < (1<<m); mask ++)
        f[1][mask] = c[1][mask];

    for (int i = 1; i < n; i ++)
    for (int masku = 0; masku < (1<<m); masku ++)
    for (int maskv : adj[masku]){
        //cout << "f["<<i<<"]["<<masku<<"] = " << f[i][masku] << " -> ";
        //cout << c[i+1][maskv] << '\n';
        f[i+1][maskv] = max(f[i+1][maskv], f[i][masku] + c[i+1][maskv]);
        //cout << "f["<<i+1<<"]["<<maskv<<"] = " << f[i+1][maskv] << '\n';
    }

    ll ans = -oo;
    for (int mask = 0; mask < (1<<m); mask ++)
        ans = max(ans, f[n][mask]);

    cout << ans;

    return 0;
}
