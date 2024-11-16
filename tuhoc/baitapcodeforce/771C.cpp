#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
const int N = 2e5 + 2;
const int K = 10;

int n, k, root;
vector<int> adj[N];
ll f[N][K], cnt[N];
ll res = 0;

void dfs(int u, int pu){
    cnt[u] = 1;
    for (int v : adj[u]) if ( v != pu ){
        dfs(v, u);
        cnt[u] += cnt[v];
        for (int i = 1; i <= k; i ++) f[u][i] += f[v][i-1];
    }
    f[u][0] += f[u][k] + cnt[u] - 1;
}

void go(int u, int pu){
    res += f[u][0];
    for (int v : adj[u]) if ( v != pu ){
        cnt[u] -= cnt[v];
        for (int i = 1; i <= k; i ++) f[u][i] -= f[v][i-1];
        f[u][0] = f[u][k] + cnt[u] - 1;
        cnt[v] += cnt[u];
        for (int i = 1; i <= k; i ++) f[v][i] += f[u][i-1];
        f[v][0] = f[v][k] + cnt[v] - 1;
        go(v, u);

        cnt[v] -= cnt[u];
        for (int i = 1; i <= k; i ++) f[v][i] -= f[u][i-1];
        f[v][0] = f[v][k] + cnt[v] - 1;

        cnt[u] += cnt[v];
        for (int i = 1; i <= k; i ++) f[u][i] += f[v][i-1];
        f[u][0] = f[u][k] + cnt[u] - 1;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n >> k;
    for (int i = 1; i < n; i ++){
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    dfs(1, 0);

    go(1, 0);

    cout << res / 2;

    return 0;
}
