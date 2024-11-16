#include<bits/stdc++.h>
#define pb push_back
#define ll long long
using namespace std;
const int N = 3e5 + 5;
const ll oo = 1e9;

int t, n, k;
vector<int> g[N];
int imp[N];
ll f[N][2];

void dfs(int u, int pu){
    ll sum = 0, res = 0, mn = oo;

    for (int v : g[u]) if ( v != pu ){
        dfs(v, u);
        sum += f[v][0];
        mn = min(mn, f[v][1] - f[v][0]);
        res += min(f[v][0], f[v][1]);
    }

    if ( !imp[u] ) f[u][0] = min({f[u][0], res+1, sum}), f[u][1] = min(f[u][1], sum + mn);
    else f[u][1] = min(f[u][1], sum);
}

void solve(){
    for (int i = 1; i <= n; i ++){
        g[i].clear();
        imp[i] = 0;
        f[i][0] = f[i][1] = oo;
    }

    for (int i = 1, u; i <= k; i ++)
        cin >> u, imp[u] = 1;

    for (int i = 1, u, v; i < n; i ++){
        cin >> u >> v;
        g[u].pb(v), g[v].pb(u);
        if ( imp[u] && imp[v] ) {
            cout << -1 << '\n';
            return;
        }
    }

    dfs(1, 0);

    cout << min(f[1][0], f[1][1]) << '\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("dienbien.inp", "r") ){
        freopen("dienbien.inp", "r", stdin);
        freopen("dienbien.out", "w", stdout);
    }

    cin >> t;

    while ( cin >> n >> k )
        if ( n == -1 ) break;
        else solve();

    return 0;
}
