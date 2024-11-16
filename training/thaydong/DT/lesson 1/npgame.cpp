#include<bits/stdc++.h>
#define simon "npgame"
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pb push_back
using namespace std;
const int N = 5e2 + 5;

int n1, n2, m, t;
int visited[N], Left[N], Right[N];
vector<int> adj[N], adje[N];
pair<int, int> edges[N*N];
string res1 = "", res2 = "";

bool visit(int u){
    if ( visited[u] != t )
        visited[u] = t;
    else return false;

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
    if ( visited[u] != t )
        visited[u] = t;
    else return false;

    for (auto v : adje[u])
        if ( !Right[v] || dfs1(Right[v]) ) return true;

    return false;
}

bool dfs2(int u){
    if ( visited[u] != t )
        visited[u] = t;
    else return false;

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

    cin >> n1 >> n2 >> m;
    for (int i = 1; i <= m; i ++){
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adje[v].pb(u);
        edges[i] = {u, v};
    }

    for (int i = 1; i <= n1; i ++){
        t ++;
        visit(i);
    }

    for (int i = 1; i <= n1; i ++){
        t ++;
        if ( !Right[i] || dfs1(Right[i]) ) res1 += 'P';
        else res1 += 'N';
    }

    for (int i = 1; i <= n2; i ++){
        t ++;
        if ( !Left[i] || dfs2(Left[i]) ) res2 += 'P';
        else res2 += 'N';
    }

    cout << res1 << '\n' << res2;

    return 0;
}
