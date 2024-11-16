#include<bits/stdc++.h>
#define BIT(x,k) ((x>>k)&1)
#define pb push_back
using namespace std;
const int N = 1e4 + 1;
const int MOD = 1e9 + 7;

int n, k;
vector<int> adj[N];
int c[N];
int f[N], ans = 0;

int mul(int a, int b){
    return 1LL * a * b % MOD;
}

int add(int a, int b){
    a += b;
    if ( a >= MOD ) a -= MOD;
    if ( a < 0 ) a += MOD;
    return a;
}

void dfs(int u, int pu, int msk){
    f[u] = 1;
    if ( c[u] < k && !BIT(msk, c[u]) ) f[u] = 0;

    for (int v : adj[u]) if ( v != pu ){
        dfs(v, u, msk);
        f[u] = mul(f[u], add(f[v], 1));
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n >> k;
    for (int i = 1; i <= n; i ++) cin >> c[i], c[i] --;

    for (int i = 1; i < n; i ++){
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    for (int msk = 0; msk < (1<<k); msk ++){
        for (int i = 1; i <= n; i ++) f[i] = 0;
        dfs(1, 0, msk);

        if ( ( __builtin_popcount(msk) + __builtin_popcount((1<<k)-1) ) % 2 == 0 )
            for (int i = 1; i <= n; i ++)
                ans = add(ans, f[i]);
        else for (int i = 1; i <= n; i ++) ans = add(ans, -f[i]);
    }

    cout << ans;

    return 0;
}
