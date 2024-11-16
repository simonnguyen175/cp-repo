#include<bits/stdc++.h>
using namespace std;
const int oo = 1e9;
const int N = 7e2 + 5;

int n, m, t;
int c[N][N];

int main(){
    if ( fopen("spath.inp", "r") ){
        freopen("spath.inp", "r", stdin);
        freopen("spath1.out", "w", stdout);
    }

    cin >> n >> m;

    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= n; j ++)
            if ( i == j ) c[i][j] = 0;
            else c[i][j] = 1;

    for (int i = 1; i <= m; i ++){
        int u, v; cin >> u >> v;
        u ++; v ++;
        c[u][v] = c[v][u] = oo;
    }

    for (int k = 1; k <= n; k ++)
        for (int i = 1; i <= n; i ++)
            for (int j = 1; j <= n; j ++)
                if ( c[i][j] > c[i][k] + c[k][j] )
                    c[i][j] = c[i][k] + c[k][j];

    cin >> t;
    while ( t -- ){
        int u, v; cin >> u >> v;
        u ++; v ++;
        if ( c[u][v] == oo ) cout << -1 << '\n';
        else cout << c[u][v] << '\n';
    }

    return 0;
}
