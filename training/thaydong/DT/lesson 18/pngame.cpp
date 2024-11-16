#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int N = 5e2 + 5;

int n1, n2, m, t;
int visited[N], Left[N], Right[N];
vector<int> adj[N], adje[N];

bool visit(int u){
    if ( visited[u] == t ) return false;
    visited[u] = t;

    for (auto v : adj[u]){
        if ( !Left[v] || visit(Left[v]) ){
            Left[v] = u;
            Right[u] = v;
            return true;
        }
    }

    return false;
}

bool dfs1(int u){
    if ( visited[u] == t ) return false;
    visited[u] = t;

    for (auto v : adje[u])
        if ( !Right[v] || dfs1(Right[v]) ) return true;

    return false;
}

bool dfs2(int u){
    if ( visited[u] == t ) return false;
    visited[u] = t;

    for (auto v : adj[u])
        if ( !Left[v] || dfs2(Left[v]) ) return true;

    return false;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("trash.inp", "r") ){
        freopen("trash.inp", "r", stdin);
        freopen("trash.out", "w", stdout);
    }

    cin >> n1 >> n2 >> m;
    for (int i = 1; i <= m; i ++){
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adje[v].pb(u);
    }

    for (int i = 1; i <= n1; i ++){
        t ++;
        visit(i);
    }

    for (int i = 1; i <= n1; i ++){
        t ++;
        if ( !Right[i] || dfs1(Right[i]) ) cout << 'P';
        else cout << 'N';
    }

    cout << '\n';
    for (int i = 1; i <= n2; i ++){
        t ++;
        if ( !Left[i] || dfs2(Left[i]) ) cout << 'P';
        else cout << 'N';
    }

    return 0;
}
