#include<bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define pb push_back
#define pi pair<int, int>
#define fi first
#define se second
using namespace std;
const int N = 4e5 + 100;

int n, k, V = 0;
map<pi, int> id;
vector<int> adj[N];
vector<pi> edg, bor[5];
int vis[N];

void Insert(int x, int y){
    if ( id[{x, y}] ) return;
    id[{x, y}] = ++V;
    if ( x == 0 ) bor[0].pb({x, y});
    if ( y == 0 ) bor[1].pb({x, y});
    if ( x == n ) bor[2].pb({x, y});
    if ( y == n ) bor[3].pb({x, y});
}

void anal(int t){
    sort(bor[t].begin(), bor[t].end());
    bor[t].erase(unique(bor[t].begin(), bor[t].end()), bor[t].end());
    for (int i = 1; i < bor[t].size(); i ++){
        int u = id[bor[t][i-1]], v = id[bor[t][i]];
        edg.pb({u, v});
    }
}

void dfs(int u){
    vis[u] = 1;
    for (int v : adj[u]) if ( !vis[v] )
        dfs(v);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n >> k;

    Insert(0, 0);
    Insert(n, 0);
    Insert(0, n);
    Insert(n, n);
    for (int i = 1; i <= k; i ++){
        int x, y;
        cin >> x >> y;
        Insert(x, y);
        Insert(x-1, y-1);
        Insert(x-1, y);
        Insert(x, y-1);

        edg.pb({id[{x-1, y}], id[{x, y}]});
        edg.pb({id[{x, y-1}], id[{x, y}]});
        edg.pb({id[{x-1, y-1}], id[{x-1, y}]});
        edg.pb({id[{x-1, y-1}], id[{x, y-1}]});
    }

    for (int i = 0; i <= 3; i ++)
        anal(i);

    sort(edg.begin(), edg.end());
    edg.erase(unique(edg.begin(), edg.end()), edg.end());
    for (auto it : edg){
        int u = it.fi, v = it.se;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    int K = 0;
    for (int i = 1; i <= V; i ++) if ( !vis[i] )
        K ++, dfs(i);

    cout << edg.size() - V + K - k;

    return 0;
}
