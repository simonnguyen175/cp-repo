#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int N = 1e3 + 5;

int t, n, m, cnt;
vector<int> adj[N], cont;
int side[N], L[N], R[N], f[N][N];
bool bipartite;

void dfs(int u){
    cont.pb(u);
    for (int v : adj[u]){
        if ( side[v] == -1 ) side[v] = 1-side[u], dfs(v);
        else bipartite &= ( side[u] != side[v] );
    }
}

void solve(){
    cin >> n >> m;

    for (int i = 1; i <= n; i ++) adj[i].clear();

    for (int i = 1; i <= m; i ++){
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    memset(side, -1, sizeof side);
    memset(L, 0, sizeof L);
    memset(R, 0, sizeof R);
    memset(f, 0, sizeof f);

    bipartite = 1; cnt = 0;
    for (int i = 1; i <= n; i ++)
        if ( side[i] == -1 ){
            cont.clear(); side[i] = 0;
            dfs(i);
            cnt ++;
            for (int u : cont)
                L[cnt] += side[u], R[cnt] += !side[u];
        }

    if ( !bipartite ){
        cout << -1 << '\n'; return;
    }

    f[0][0] = 1;
    for (int i = 0; i < cnt; i ++)
    for (int j = 0; j <= n; j ++) if ( f[i][j] ){
        f[i+1][j+L[i+1]] = 1;
        f[i+1][j+R[i+1]] = 1;
    }

    int ans = 0;
    for (int i = 0; i <= n; i ++)
        if ( f[cnt][i] ) ans = max(ans, i * (n-i) - m);

    cout << ans << '\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("noodd.inp", "r") ){
        freopen("noodd.inp", "r", stdin);
        freopen("noodd.out", "w", stdout);
    }

    cin >> t;
    while ( t -- )
        solve();

    return 0;
}
