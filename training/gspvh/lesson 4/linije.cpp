#include<bits/stdc++.h>
#define simon "linije"
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pb push_back
using namespace std;
const int N = 5e2 + 5;

int m, t;
int visited[N], Left[N], Right[N];
vector<int> adj[N], adje[N], a, b;

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
    FASTio
    if ( fopen(simon".inp", "r") ){
        freopen(simon".inp", "r", stdin);
        freopen(simon".out", "w", stdout);
    }

    cin >> m;
    for (int i = 1; i <= m; i ++){
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adje[v].pb(u);
        a.pb(u); b.pb(v);
    }

    sort(a.begin(), a.end()); sort(b.begin(), b.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    b.erase(unique(b.begin(), b.end()), b.end());

    for (int i = 0; i < a.size(); i ++){
        t ++;
        visit(a[i]);
    }

    bool ck = 0;
    for (int i = 0; i < a.size(); i ++){
        t ++;
        ck |= ( !Right[a[i]] || dfs1(Right[a[i]]) );
    }

    for (int i = 0; i < b.size(); i ++){
        t ++;
        ck |= ( !Left[b[i]] || dfs2(Left[b[i]]) );
    }

    if ( ck ) cout << "Tanya";
    else cout << "Antonina";

    return 0;
}
