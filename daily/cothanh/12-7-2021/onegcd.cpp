#include<bits/stdc++.h>
#define pi pair<int, int>
#define fi first
#define se second
#define pb push_back
using namespace std;
const int N = 3e5 + 5;

int n, m, cnt = 0;
vector<pi> adj[N];
int vis[N], vis1[N];

void dfs(int u){
    vis1[u] = 1;
    for (auto it : adj[u]) if ( !vis[it.se] ){
        cout << u << ' ' << it.fi << ' ' << ++cnt << '\n';
        vis[it.se] = 1;
        if ( !vis1[it.fi] ) dfs(it.fi);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("onegcd.inp", "r") ){
        freopen("onegcd.inp", "r", stdin);
        freopen("onegcd.out", "w", stdout);
    }

    cin >> n >> m;
    for (int i = 1; i <= m; i ++){
        int u, v;
        cin >> u >> v;
        adj[u].pb({v, i});
        adj[v].pb({u, i});
    }

    dfs(1);

    return 0;
}
