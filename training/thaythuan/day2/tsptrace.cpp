#include<bits/stdc++.h>
#define BIT(x,k) ((x>>k)&1)
using namespace std;
const int N = 21;
const int oo = 1e9;

int n, m, ans = oo;
int c[N][N], f[N][1<<20];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n >> m;

    for (int i = 1; i <= n; i ++)
    for (int j = 1; j <= n; j ++)
        c[i][j] = oo;

    for (int i = 1; i <= n; i ++)
    for (int t = 1; t < (1<<n); t ++)
        f[i][t] = oo;

    for (int i = 1, u, v, w; i <= m; i ++){
        cin >> u >> v >> w;
        c[u][v] = min(c[u][v], w);
    }

    f[1][1] = 0;

    for (int t = 1; t < (1<<n); t ++)
    for (int i = 1; i <= n; i ++) if ( BIT(t, i-1) && f[i][t] != oo )
        for (int j = 1; j <= n; j ++) if ( c[i][j] != oo && !BIT(t, j-1) )
            f[j][t|(1<<(j-1))] = min(f[j][t|(1<<(j-1))], f[i][t] + c[i][j]);

    for (int i = 2; i <= n; i ++)
        ans = min(ans, f[i][(1<<n)-1] + c[i][1]);

    cout << ans;

    return 0;
}
