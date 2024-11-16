#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
const int N = 2e5 + 2;
const int K = 5e2 + 2;

int n, k, root;
vector<int> adj[N];
ll f[N][K];
int cnt[N];
ll res = 0;

void dfs(int u){
    cnt[u] = 1;
    for (int v : adj[u]){
        dfs(v);
        cnt[u] += cnt[v];
        for (int i = 1; i <= k; i ++) f[u][i] += f[v][i-1];
    }
    f[u][0] += f[u][k] + cnt[u] - 1;
}

void go(int u){
    res += f[u][0];
    for (int v : adj[u]){
        cnt[u] -= cnt[v];
        for (int i = 1; i <= k; i ++) f[u][i] -= f[v][i-1];
        f[u][0] = f[u][k] + cnt[u] - 1;
        cnt[v] += cnt[u];
        for (int i = 1; i <= k; i ++) f[v][i] += f[u][i-1];
        f[v][0] = f[v][k] + cnt[v] - 1;
        go(v);

        cnt[v] -= cnt[u];
        for (int i = 1; i <= k; i ++) f[v][i] -= f[u][i-1];
        f[v][0] = f[v][k] + cnt[v] - 1;

        cnt[u] += cnt[v];
        for (int i = 1; i <= k; i ++) f[u][i] += f[v][i-1];
        f[u][0] = f[u][k] + cnt[u] - 1;
    }
}

int main(){
    if ( fopen("jumping.inp", "r") ){
        freopen("jumping.inp", "r", stdin);
        freopen("jumping.out", "w", stdout);
    }

    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n >> k;
    for (int i = 1; i <= n; i ++){
        int p; cin >> p;
        if ( p == 0 ) root = i;
        else adj[p].pb(i);
    }

    dfs(root);

    go(root);

    cout << res / 2;

    return 0;
}
