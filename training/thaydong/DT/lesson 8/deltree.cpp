#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int N = 3e5 + 5;

int n;
int col[N], f[N][2];
vector<int> adj[N];

void dfs(int u, int pu){
    f[u][0] = col[u];
    f[u][1] = 1 - col[u];

    for (int v : adj[u]){
        if ( v == pu ) continue;
        dfs(v, u);
        f[u][0] += min(f[v][0], f[v][1] + 1);
        f[u][1] += min(f[v][1], f[v][0] + 1);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i ++){
        char x; cin >> x;
        col[i] = x - '0';
    }

    for (int i = 1; i < n; i ++){
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    dfs(1, 0);

    cout << min(f[1][0], f[1][1]) + 1;

    return 0;
}
