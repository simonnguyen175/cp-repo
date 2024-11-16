#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll oo = 1e15;
const int N = 505;

int n, m, k;
ll c[N][N], l[N];
int sou[N];
vector<int> adj[N];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("service.inp", "r") ){
        freopen("service.inp", "r", stdin);
        freopen("service.out", "w", stdout);
    }

    cin >> n >> m >> k;
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= n; j ++)
            if ( i == j ) c[i][j] = 0;
            else c[i][j] = oo;
    for (int i = 1; i <= m; i ++){
        int u, v; ll w;
        cin >> u >> v >> w;
        c[u][v] = min(c[u][v], w);
        c[v][u] = c[u][v];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int l = 1; l <= n; l ++)
        for (int i = 1; i <= n; i ++)
            for (int j = 1; j <= n; j ++)
                if ( c[i][l] + c[l][j] < c[i][j] )
                    c[i][j] = c[i][l] + c[l][j];

    while ( k -- ){
        int x, y, z;
        cin >> x >> y >> z;

        // pick source
        for (int i = 1; i <= n; i ++)
        l[i] = min({c[i][x], c[i][y], c[i][z]});

        // solve
        ll ans = 0;
        for (int i = 1; i <= n; i ++){
            if ( i == x || i == y || i == z ) continue;
            ll best = oo;
            for (auto j : adj[i]){
                if ( c[j][i] + l[j] == l[i] )
                    best = min(best, c[j][i]);
            }
            ans += best;
        }

        cout << ans*100 << '\n';
    }
}

