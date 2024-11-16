#include<bits/stdc++.h>
#define pi pair<int, int>
#define fi first
#define se second
#define pb push_back
using namespace std;
const int N = 5e5 + 5;

int n, m, ck = 0;
vector<pi> adj[N];
int vis[N], ans[N];

void dfs(int u){
    vis[u] = 1;
    for (auto it : adj[u]){
        int v = it.fi, id = it.se;
        if ( vis[v] == 1 ){
            ck = 1;
            ans[id] = 2;
            continue;
        }
        else{
            ans[id] = 1;
            if ( !vis[v] ) dfs(v);
        }
    }
    vis[u] = 2;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("dag.inp", "r") ){
        freopen("dag.inp", "r", stdin);
        freopen("dag.out", "w", stdout);
    }

    cin >> n >> m;
    for (int i = 1; i <= m; i ++){
        int u, v;
        cin >> u >> v;
        if ( u == v ){
            cout << -1;
            return 0;
        }
        adj[u].pb({v, i});
    }

    memset(vis, 0, sizeof vis);

    for (int i = 1; i <= n; i ++)
        if ( !vis[i] ) dfs(i);

    if ( ck ) cout << "2\n"; else cout << "1\n";
    for (int i = 1; i <= m; i ++)
        cout << ans[i] << ' ';

    return 0;
}
