#include<bits/stdc++.h>
#define simon "tree"
#define pb emplace_back
using namespace std;
const int N = 5e5 + 5;

int n, m, k;
vector<int> adj[N];
queue<int> q;
vector<int> todo;
int deny[N], vis[N];
int pre[N], nxt[N];

void Remove(int u){
    vis[u] = 1;
    pre[nxt[u]] = pre[u];
    nxt[pre[u]] = nxt[u];
}

void solve(){
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i ++) adj[i].clear();
    for (int i = 1, u, v; i <= m; i ++){
        cin >> u >> v;
        if ( u == v ) continue;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    for (int i = 1; i <= n; i ++){
        sort(adj[i].begin(), adj[i].end());
        adj[i].erase(unique(adj[i].begin(), adj[i].end()), adj[i].end());
    }
    if ( n-1-adj[1].size() < k ) { cout << "No "; return; }

    /// bfs include node 1
    for (int i = 1; i <= n+1; i ++)
        vis[i] = 0, pre[i] = i-1, nxt[i-1] = i;
    int ccs = 0;
    for (int i = 1; i <= n; i ++) if ( !vis[i] ){
        q.push(i);
        ccs ++;
        Remove(i);
        while ( q.size() ){
            int u = q.front();
            q.pop();
            for (int v : adj[u]) deny[v] = 1;
            todo.clear();
            for (int v = nxt[0]; v <= n; v = nxt[v]) if ( !deny[v] ) todo.pb(v);
            for (int v : todo) Remove(v), q.push(v);
            for (int v : adj[u]) deny[v] = 0;
        }
    }
    if ( ccs != 1 ) { cout << "No "; return; }

    /// bfs not include node 1
    for (int i = 2; i <= n+1; i ++)
        vis[i] = 0, pre[i] = i-1, nxt[i-1] = i;
    ccs = 0;
    for (int i = 2; i <= n; i ++) if ( !vis[i] ){
        q.push(i);
        ccs ++;
        Remove(i);
        while ( q.size() ){
            int u = q.front();
            q.pop();
            todo.clear();
            for (int v : adj[u]) deny[v] = 1;
            for (int v = nxt[1]; v <= n; v = nxt[v]) if ( !deny[v] ) todo.pb(v);
            for (int v : todo) Remove(v), q.push(v);
            for (int v : adj[u]) deny[v] = 0;
        }
    }
    if ( ccs > k ) { cout << "No "; return; }

    cout << "Yes ";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen(simon".inp", "r") ){
        freopen(simon".inp", "r", stdin);
        freopen(simon".out", "w", stdout);
    }

    int sub, test;
    cin >> sub >> test;
    while ( test -- )
        solve();

    return 0;
}
