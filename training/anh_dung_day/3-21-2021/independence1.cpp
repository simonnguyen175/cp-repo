#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+1;

int n, a[N];
vector<int> adj[N];
ll dp[N], child[N], gchild[N];
bool vis[N];

void DFS(int u, int par, int gpar) {
    for(int v : adj[u]) {
        if (!vis[v]) {
            vis[v] = 1;
            DFS(v, u, par);
        }
    }
    dp[u][0] = max(child[u], a[u] + gchild[u]);
    child[par] += dp[u];
    gchild[gpar] += dp[u];
}

int main(){
    ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    cin >> n;
    for (int i=1; i<=n; i++)
        cin >> a[i];
    for (int i=1; i<n; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    memset(vis, 0, sizeof vis);
    vis[1]=1;
    DFS(1, 0, 0);
    cout << dp[1];
    return 0;
}
