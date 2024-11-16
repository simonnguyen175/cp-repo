#include<bits/stdc++.h>
using namespace std;
const int N = 3e5 + 5;

int n, k;
vector<int> adj[N];
int d[N], f[N], spc[N], cnt[N];

void dfs1(int u, int pu){
    if ( spc[u] ) cnt[u] = 1;
    for (auto v : adj[u]){
        if ( v == pu ) continue;
        d[v] = d[u] + 1;
        dfs1(v, u);
        cnt[u] += cnt[v];
    }
}

void dfs2(int u, int pu){
    for (auto v : adj [u]){
        if ( v == pu ) continue;
        f[v] = f[u] - cnt[v] + k - cnt[v];
        dfs2(v, u);
    }
}

int main(){
    cin >> n >> k;
    for (int i = 1; i < n; i ++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }


    memset(cnt, 0, sizeof cnt);
    memset(spc, 0, sizeof spc);
    for (int i = 1; i <= k; i ++){
        int u; cin >> u; spc[u] = 1;
    }

    d[1] = f[1] = 0;
    dfs1(1, 0);
    for (int i = 1; i <= n; i ++)
        if ( spc[i] ) f[1] += d[i];

    dfs2(1, 0);

    sort(f + 1, f + 1 + n);

    cout << f[n-1];

    return 0;
}
