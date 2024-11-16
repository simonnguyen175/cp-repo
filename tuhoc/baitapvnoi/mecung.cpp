#include<bits/stdc++.h>
#define pi pair<int, int>
#define fi first
#define se second
#define pb push_back
using namespace std;
const int N = 2e5 + 5;
const int oo = 1e9 + 7;

int n, m;
vector<pi> adj[N], g[N];
int d[2][N], C[N], vis[N];

void bfs(int t){
    queue<int> Q;
    for (int i = 1; i <= n; i ++) d[t][i] = oo;
    if ( !t ) d[t][1] = 0, Q.push(1);
    else d[t][n] = 0, Q.push(n);
    while ( Q.size() ){
        int u = Q.front();
        Q.pop();
        for (auto it : adj[u]) if ( d[t][it.fi] == oo ){
            d[t][it.fi] = d[t][u] + 1;
            Q.push(it.fi);
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("trash.inp", "r") ){
        freopen("trash.inp", "r", stdin);
        freopen("trash.out", "w", stdout);
    }

    cin >> n >> m;
    for (int i = 1; i <= m; i ++){
        int u, v, c;
        cin >> u >> v >> c;
        adj[u].pb({v, c});
        adj[v].pb({u, c});
    }

    bfs(0);
    bfs(1);

    for (int u = 1; u <= n; u ++){
        for (auto it : adj[u]){
            int v = it.fi, c = it.se;
            if ( d[0][u] + 1 + d[1][v] == d[0][n] )
                g[u].pb({v, c});
        }
    }

    queue<int> Q; vector<int> ans;
    int curD = 0, curC = oo, preC = 0;
    for (int i = 1; i <= n; i ++) C[i] = oo;
    Q.push(1); C[1] = 0; vis[1] = 1;

    while ( Q.size() ){
        int u = Q.front();
        Q.pop();
        if ( curD != d[0][u] ) curD = d[0][u], ans.pb(curC), preC = curC, curC = oo;
        if ( C[u] != preC ) continue;

        for (auto it : g[u]){
            int v = it.fi, c = it.se;
            C[v] = min(C[v], c);
            curC = min(curC, c);
            if ( !vis[v] ) Q.push(v), vis[v] = 1;
        }
    }

    cout << d[0][n] << '\n';
    for (int x : ans) cout << x << ' ';

    return 0;
}
