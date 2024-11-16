#include<bits/stdc++.h>
#define pb push_back
#define ll long long
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

int n, k;
int child[N], c[N];
vector<int> adj[N];
bool flag = 1;

void dfs(int u, int pu){
    for (int v : adj[u]){
        if ( v == pu ) continue;
        child[u] ++;
        if ( c[u] && c[v] && c[u] == c[v] ) {flag = 0; return;}
        dfs(v, u);
    }
}

ll cal(int u, int pu, int color){
    if ( c[u] && c[u] != color ) return 0;

    if ( child[u] == 0 ) return 1;

    ll res = 1;
    for (int v : adj[u]){
        if ( v == pu ) continue;
        ll tmp = 0;
        if ( c[v] && c[v] != color ) tmp = (tmp + cal(v, u, c[v]))%MOD;
        else
            for (int i = 1; i <= 3; i ++)
                if ( i != color )
                    tmp = (tmp + cal(v, u, i)) % MOD;
        res = (res * tmp) % MOD;
    }

    return res;
}

int main(){
    ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

    cin >> n >> k;
    for (int i = 1; i < n; i ++){
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    memset(c, 0, sizeof c);
    for (int i = 1; i <= k; i ++){
        int u;
        cin >> u >> c[u];
    }

    dfs(1, 0);

    if ( !flag ) cout << 0;
    else
        cout << ((cal(1, 0, 1) + cal(1, 0, 2))%MOD + cal(1, 0, 3))%MOD;

    return 0;
}
