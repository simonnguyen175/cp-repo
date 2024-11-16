#include<bits/stdc++.h>
#define pb push_back
#define ll long long
#define pi pair<int, int>
#define fi first
#define se second
#define int long long
using namespace std;
const int N = 1e6 + 5;

int n;
vector<int> adj[N];
int a[N], child[N], f[N], g[N];
int ans = 0;


void dfs0(int u){
    child[u] = 1;
    f[u] = a[u];
    for (int v : adj[u]){
        dfs0(v);
        f[u] = max(f[u], f[v]);
        child[u] += child[v];
    }
}

void dfs(int u){
//    cout << u << " : \n";
//    cout << a[u] << ' ' << child[u] << ' ' << g[u] << '\n';
    if ( a[u] * child[u] >= g[u] ){
//        cout << u << ' ' << g[u] << '\n';
        ans ++;
    }

    if ( (int)adj[u].size() ){
        for (int v : adj[u])
            g[v] = max(a[u], g[u]);

        int pre = f[adj[u][0]];
        for (int i = 1; i < (int)adj[u].size(); i ++){
            int v = adj[u][i];
            g[v] = max(g[v], pre);
            pre = max(pre, f[v]);
        }

        int suf = f[adj[u].back()];
        for (int i = adj[i].size()-2; i >= 0; i --){
            int v = adj[u][i];
            g[v] = max(g[v], suf);
            suf = max(suf, g[v]);
        }

        for (int v : adj[u]){
            dfs(v);
        }
    }
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("tmp.inp", "r") ){
        freopen("tmp.inp", "r", stdin);
        freopen("tmp.out", "w", stdout);
    }

    cin >> n;
    for (int i = 2; i <= n; i ++){
        int p;
        cin >> p;
        adj[p].pb(i);
    }

    for (int i = 1; i <= n; i ++)
        cin >> a[i];

    dfs0(1);

    dfs(1);

    cout << ans;

    return 0;
}
