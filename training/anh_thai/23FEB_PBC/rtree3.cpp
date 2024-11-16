#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int N = 5e5 + 5;

int n, timeDfs  ;
int tin[N], tout[N], bit[N], ans[N];
vector<int> adj[N], ad[N];

void dfs(int u, int pu){
    tin[u] = ++timeDfs;
    for (int v : adj[u]) if ( v != pu )
        dfs(v, u);
    tout[u] = timeDfs;
}

void upd(int u, int v){
    for (; u <= n; u += u&-u)
        bit[u] += v;
}

int get(int u){
    int res = 0;
    for (; u >= 1; u -= u&-u)
        res += bit[u];
    return res;
}

void dfs1(int u, int pu){
    for (int v : ad[u]) if ( v != pu ){
//        cout << "update " << v << ' ' << tin[v] << ' ' << tout[v] << '\n';
        upd(tin[v], 1);
        upd(tout[v] + 1, -1);

        ans[v] = get(tin[v]);
        dfs1(v, u);

//        cout << "erase " << v << ' ' << tin[v] << ' ' << tout[v] << '\n';
        upd(tin[v], -1);
        upd(tout[v] + 1, +1);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("trash.inp", "r") ){
        freopen("trash.inp", "r", stdin);
        freopen("trash.out", "w", stdout);
    }

    cin >> n;
    for (int i = 1, u, v; i < n; i ++){
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    for (int i = 1, u, v; i < n; i ++){
        cin >> u >> v;
        ad[u].pb(v);
        ad[v].pb(u);
    }

    dfs(1, 0);

//    for (int i = 1; i <= n; i ++)
//        cout << tin[i] << ' ' << tout[i] << '\n';

    upd(1, 1);
    ans[1] = 1;

    dfs1(1, 0);

    for (int i = 1; i <= n; i ++)
        cout << ans[i] << ' ';

    return 0;
}
