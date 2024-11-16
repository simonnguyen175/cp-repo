#include<bits/stdc++.h>
#define simon "experience"
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pb push_back
#define ll long long
using namespace std;
const int N = 1e5 + 5;

int n;
vector<int> adj[N];
ll w[N], f[N][2]; // 0 la tang dan , 1 la giam dan

void dfs(int u, int pu){
    ll s = 0;
    for (int v : adj[u]){
        if ( v == pu ) continue;
        dfs(v, u);
        s += max(f[v][0], f[v][1]);
    }

    f[u][0] = f[u][1] = s;

    for (int v : adj[u]){
        if ( v == pu ) continue;
        if ( w[v] <= w[u] )
            f[u][0] = max(f[u][0], s - max(f[v][1], f[v][0]) + f[v][0] + w[u] - w[v]);
        else
            f[u][1] = max(f[u][1], s - max(f[v][1], f[v][0]) + f[v][1] + w[v] - w[u]);
    }
}

int main(){
    FASTio
    if ( fopen(simon".in", "r") ){
        freopen(simon".in", "r", stdin);
        freopen(simon".out", "w", stdout);
    }

    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> w[i];
    for (int i = 1; i < n; i ++){
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    dfs(1, 0);

    cout << max(f[1][0], f[1][1]);

    return 0;
}
