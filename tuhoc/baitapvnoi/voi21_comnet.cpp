#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
const int N = 1e3 + 5;

int n, k, a, b;
vector<int> adj[N];
ll f[N][N][5], cE[N];

void dfs(int u, int pu){
    f[u][0][0] = f[u][0][1] = 1;
    for (int v : adj[u]) if ( v != pu ){
        dfs(v, u);
        for (int curE = cE[u]; curE >= 0; curE --)
        for (int vE = cE[v]; vE >= 0; vE --)
        for (int curN = k; curN >= 0; curN --)
        for (int vN = 1; vN + curN <= k; vN ++){
            int sumE = curE + vE + ( vN < k );
            int sumN = curN + vN;

            f[u][sumE][sumN] += f[u][curE][curN] * f[v][vE][vN];
        }

        cE[u] += 1 + cE[v];
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n >> k >> a >> b;
    for (int i = 1; i < n; i ++){
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    dfs(1, 0);

    ll ans = 0;
    for (int i = a; i <= b; i ++)
        ans += f[1][i][k];

    cout << ans;

    return 0;
}
