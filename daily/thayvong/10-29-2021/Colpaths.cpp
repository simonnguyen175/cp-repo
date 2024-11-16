#include<bits/stdc++.h>
#define simon "Colpaths"
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pb push_back
#define ll long long
using namespace std;
const int N = 3e5 + 2;

int n, m, k;
int col[N], mask[65];
vector<int> adj[N];
ll f[N][65];

void dfs(int u, int t){
    if ( t & (1<<(col[u]-1)) ){
        for (int v : adj[u])
            f[u][t] += f[v][t^(1<<(col[u]-1))];
    }
}

bool cmp(int a, int b){
    return ( __builtin_popcount(a) < __builtin_popcount(b) );
}

int main(){
    FASTio
    if ( fopen(simon".in", "r") ){
        freopen(simon".in", "r", stdin);
        freopen(simon".out", "w", stdout);
    }

    cin >> n >> m >> k;
    for (int i = 1; i <= n; i ++)
        cin >> col[i];

    for (int i = 1; i <= m; i ++){
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    int cnt = 0;
    for (int i = 1; i <= (1<<k)-1; i ++)
        mask[i] = i, cnt ++;

    sort(mask + 1, mask + 1 + cnt, cmp);

    for (int i = 1; i <= n; i ++)
        f[i][1<<(col[i]-1)] = 1;

    for (int i = k+1; i <= cnt; i ++)
        for (int u = 1; u <= n; u ++)
            dfs(u, mask[i]);

    ll ans = 0;
    for (int u = 1; u <= n; u ++)
    for (int t = 1; t <= cnt; t ++)
        if ( __builtin_popcount(t) >= 2 )
            ans += f[u][t];

    cout << ans;

    return 0;
}
