#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int N = 1e5 + 5;

int n, m, r;
vector<int> adj[N];
set<int> cont[N];
int col[N], id[N], res[N];

void dfs(int u, int pu){
    int cur = id[u];

    for (int v : adj[u]){
        if ( v == pu ) continue;
        dfs(v, u);
        if ( cont[cur].size() < cont[id[v]].size() ) cur = id[v];
    }

    for (int v : adj[u]){
        if ( v == pu || id[v] == cur ) continue;
        //cout << u << " gop voi " << v << ' ' << cont[id[v]].size() << '\n';
        for (int x : cont[id[v]])
            cont[cur].insert(x);
    }

    id[u] = cur;
    cont[cur].insert(col[u]);
    res[u] = cont[cur].size();
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    freopen("coltree.inp", "r", stdin);
    freopen("coltree.out", "w", stdout);

    cin >> n >> m >> r;
    for (int i = 1; i < n; i ++){
        int u, v; cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    for (int i = 1; i <= n; i ++){
        int x; cin >> x;
        col[i] = x;
        id[i] = i;
    }

    dfs(r, 0);

    while ( m -- ){
        int s; cin >> s;
        cout << res[s] << '\n';
    }

    return 0;
}
