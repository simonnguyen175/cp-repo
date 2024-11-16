#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll oo = 1e15;
const int N = 4e3+5;

int n, m, k;
ll c[N][N], d[N][N];

int main(){
    ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

    cin >> n >> m >> k;
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= n; j ++)
            if ( i == j ) c[i][j] = 0;
            else c[i][j] = oo;
    for (int i = 1; i <= m; i ++){
        int u, v; ll w;
        cin >> u >> v >> w;
        c[u][v] = min(c[u][v], w);
    }

    // foyld
    for (int l = 1; l <= n; l ++)
        for (int i = 1; i <= n; i ++)
            for (int j = 1; j <= n; j ++)
                if ( c[i][l] + c[l][j] < c[i][j] )
                    c[i][j] = c[i][l] + c[l][j];

    while ( k -- ){
        for (int i = 1; i <= n+3; i ++)
            for (int j = 1; j <= n+3; j ++)
                if ( i == j ) d[i][j] = 0;
                else d[i][j] = oo;
        for (int i = 1; i <= n; i ++)
            for (int j = 1; j <= n; j ++)
                d[i][j] = c[i][j];
        int e;
        cin >> e;
        for (int i = 1; i <= e; i ++){
            int u, v; ll w;
            cin >> u >> v >> w;
            d[u][v] = min(d[u][v], w);
        }
        for (int ver = n + 1; ver <= n + 3; ver ++){
            for (int i = 1; i <= ver-1; i ++)
                for (int j = 1; j <= ver-1; j ++)
                    if ( d[i][j] + d[j][ver] < d[i][ver] )
                        d[i][ver] = d[i][j] + d[j][ver];
            for (int i = 1; i <= ver-1; i ++)
                for (int j = 1; j <= ver-1; j ++)
                    if ( d[ver][i] > d[ver][j] + d[j][i] )
                        d[ver][i] = d[ver][j] + d[j][i];
            for (int i = 1; i <= ver-1; i ++)
                for (int j = 1; j <= ver-1; j ++)
                    if ( d[i][j] > d[i][ver] + d[ver][j] )
                        d[i][j] = d[i][ver] + d[ver][j];
        }
        ll ans = 0;
        for (int i = 1; i <= n+3; i ++)
            for (int j = 1; j <= n+3; j ++)
                ans += d[i][j];
        cout << ans << '\n';
    }
    return 0;
}
