#include<bits/stdc++.h>
#define simon "weeding"
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pb push_back
using namespace std;
const int N = 3e5 + 5;

int n, a, b;
vector<int> adj[N], pathab;
bool ck[N];

void dfsTrace(int u, int pu){
    for (int v : adj[u]){
        if ( v == pu ) continue;
        if ( v == b ) { pathab.pb(u); ck[u] = 1; return; }
        dfsTrace(v, u);
        if ( ck[v] ) { pathab.pb(u); ck[u] = 1; return; }
    }
}

void dfs(int u){
    for (int i = 1; i <= n; i ++)
}

int main(){
    FASTio
    if ( fopen(simon".inp", "r") ){
        freopen(simon".inp", "r", stdin);
        freopen(simon".out", "w", stdout);
    }

    cin >> n;
    for (int i = 1; i < n; i ++){
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    cin >> a >> b;

    pathab.pb(b);
    dfsTrace(a, 0);

    reverse(pathab.begin(), pathab.end());
//    for (int u : pathab) cout << u << ' ';
//    cout << '\n';

    for (int i = 0; i < pathab.size(); i ++){
        dfs(pathab[i]);
        f[i+1] = max(f[i], i + d[pathab[i+1]]);
    }

    for (int i = pathab.size(); i >= 0; i --){
        f[i+1] =
    }

    return 0;
}
