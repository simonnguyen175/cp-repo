#include<bits/stdc++.h>
#define simon "avoidcol"
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
#define pb push_back
#define ii pair<ll, int>
#define fi first
#define se second
using namespace std;
const int N = 5e5 + 5;
const ll oo = 1e18;
const ll MOD = 1e9 + 7;

int n, m;
ll d[5][N], cnt[5][N];
vector<ii> adj[N];
struct canh{
    int u, v;
    ll w;
} edge[N];

ll sqr(ll x){
    return x * x % MOD;
}

void dijkstra(int x){
    priority_queue<ii, vector<ii>, greater<ii>> heap;

    if ( x == 0 ) d[x][1] = 0, cnt[x][1] = 1, heap.push({0, 1});
    if ( x == 1 ) d[x][n] = 0, cnt[x][n] = 1, heap.push({0, n});

    while ( heap.size() ){
        int u = heap.top().se;
        ll du = heap.top().fi;

        heap.pop();

        for (auto it : adj[u]){
            int v = it.se;
            ll w = it.fi;

            if ( d[x][v] > du + w ){
                d[x][v] = du + w;
                cnt[x][v] = cnt[x][u];
                heap.push({d[x][v], v});
            }
            else if ( d[x][v] == du + w ) ( cnt[x][v] += cnt[x][u] ) %= MOD;
        }
    }
}

int main(){
    FASTio
    if ( fopen(simon".inp", "r") ){
        freopen(simon".inp", "r", stdin);
        freopen(simon".out", "w", stdout);
    }

    cin >> n >> m;

    for (int i = 1; i <= m; i ++){
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].pb({w, v});
        adj[v].pb({w, u});
        edge[i] = {u, v, w};
    }

    for (int i = 0; i <= 1; i ++)
        for (int j = 1; j <= n; j ++)
            d[i][j] = oo;

    for (int i = 0; i <= 1; i ++)
        dijkstra(i);

    ll ans = sqr( cnt[0][n] );

    // case 1
    for (int i = 1; i <= n; i ++)
        if ( d[0][i] == d[1][i] && d[0][i] + d[1][i] == d[0][n] ){
            ll tmp = sqr( cnt[0][i] * cnt[1][i] % MOD );
            ans = ( ans - tmp + MOD * MOD ) % MOD;
        }

    // case 2
    for (int i = 1; i <= m; i ++){
        int u = edge[i].u, v = edge[i].v;
        ll w = edge[i].w;

        if ( d[0][u] + w + d[1][v] == d[0][n] && abs(d[0][u]-d[1][v]) < w ){
            ll tmp = sqr( cnt[0][u] * cnt[1][v] % MOD );
            ans = ( ans - tmp + MOD * MOD ) % MOD;
        }

        if ( d[0][v] + w + d[1][u] == d[0][n] && abs(d[0][v]-d[1][u]) < w ){
            ll tmp = sqr( cnt[0][v] * cnt[1][u] % MOD );
            ans = ( ans - tmp + MOD * MOD ) % MOD;
        }
    }

    cout << ans;

    return 0;
}
