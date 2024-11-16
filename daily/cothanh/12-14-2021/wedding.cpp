#include<bits/stdc++.h>
#define simon "wedding"
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pb push_back
using namespace std;
const int N = 3e5 + 5;

int n, a, b;
vector<int> adj[N], pathab;
bool ck[N];
int d[N], f[N], g[N];

void dfsTrace(int u, int pu){
    for (int v : adj[u]){
        if ( v == pu ) continue;
        if ( v == b ) { pathab.pb(u); ck[u] = 1; return; }
        dfsTrace(v, u);
        if ( ck[v] ) { pathab.pb(u); ck[u] = 1; return; }
    }
}

void dfs(int u, int pu){
    int tmp = 0;
    for (int v : adj[u]){
        if ( v == pu ) continue;
        dfs(v, u);
        if ( ck[v] ) continue;
        tmp = max(tmp, d[v]);
    }
    d[u] = 1 + tmp;
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

    pathab.pb(b); ck[b] = 1;
    dfsTrace(a, 0);

    reverse(pathab.begin(), pathab.end());

    dfs(a, 0);

    for (int i = 0; i < pathab.size(); i ++)
        f[i+1] = max(f[i], i + d[pathab[i]]);

    for (int i = pathab.size(); i >= 1; i --){
        int l = pathab.size();
        g[i] = max(g[i+1], l - i + d[pathab[i-1]]);
    }

    int ans = 0;
    for (int i = 1; i < pathab.size(); i ++){
        ans = max(ans, min(f[i], g[i+1]));
    }
    cout << ans;

    return 0;
}
