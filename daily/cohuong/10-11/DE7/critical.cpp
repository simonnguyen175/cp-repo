#include<bits/stdc++.h>
#define pb push_back
#define ll long long
using namespace std;
const int N = 2e5 + 5;

int n, m, timeDfs = 0;
vector<int> adj[N];
int vis[N], sum = 0, num[N], low[N], child[N];
ll ans = 0;

void go(int u){
    vis[u] = 1, sum ++;
    for (int v : adj[u]) if ( !vis[v] ) go(v);
}

void dfs(int u, int pu){
    int s = 0;
    child[u] = 1;
    num[u] = low[u] = ++timeDfs;

    ll tmp = 1LL * ( sum - 1 ) *  ( sum - 1 );

    for (int v : adj[u]) if ( v != pu ){
        if ( !num[v] ){
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            child[u] += child[v];
            if ( !pu || low[v] >= num[u]  )
                s += child[v], tmp -= 1LL * child[v] * child[v];
        }
        else low[u] = min(low[u], num[v]);
    }

    tmp -= 1LL * ( sum - 1 - s ) * ( sum - 1 - s );

    ans += tmp / 2;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    freopen("critical.in", "r", stdin);
    freopen("critical.out", "w", stdout);

    cin >> n >> m;
    for (int i = 1; i <= m; i ++){
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    for (int i = 1; i <= n; i ++) if ( !num[i] ){
        sum = 0;
        go(i);
        dfs(i, 0);
    }

    cout << fixed << setprecision(2) << ans * 1.0 / n;

    return 0;
}
