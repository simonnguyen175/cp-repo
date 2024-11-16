#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int N = 1e5 + 5;

int n, m, t;
vector<int> adj[N];
bool vis[N], d[N], bri[N];

void bfs(int x){
    queue<int> q; q.push(x);

    while ( q.size() ){
        int u = q.front(); q.pop();
        for (auto v : adj[u]){
            if ( d[v] && v != x )
                if ( vis[v] ) { bri[v] = 0; continue; }
                else bri[v] = 0;

            if ( vis[v] || v == t ) continue;

            q.push(v);
            if ( !d[v] ) vis[v] = 1;
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("footbridge.inp", "r") ){
        freopen("footbridge.inp", "r", stdin);
        freopen("footbridge.out", "w", stdout);
    }

    cin >> n >> m >> t;
    for (int i = 1; i <= m; i ++){
        int u, v;
        cin >> u >> v;
        adj[v].pb(u);
    }

    for (int s : adj[t]) d[s] = bri[s] = 1;

    for (int s : adj[t]) bfs(s), vis[s] = 1;

    vector<int> ans;
    for (int s : adj[t]) if ( bri[s] ) ans.pb(s);

    cout << ans.size() << '\n';
    for (int s : ans) cout << s << '\n';

    return 0;
}
