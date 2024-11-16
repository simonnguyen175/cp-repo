#include<bits/stdc++.h>
#define simon "escape"
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double
#define pi pair<ld, int>
#define fi first
#define se second
#define pb push_back
using namespace std;
const int N = 1e2 + 5;
const ld oo = 1e9;

int n, m, e, X, Y;
bool esc[N];
ld c[N][N], d[N];
vector<pi> adj[N];

bool check(ld lim){
    priority_queue<pi, vector<pi>, greater<pi>> heap;
    for (int i = 1; i <= n; i ++) d[i] = oo;

    d[X] = 0;
    heap.push({d[X], X});

    while ( heap.size() ){
        int u = heap.top().se; ld du = heap.top().fi;
        heap.pop();
        if ( du != d[u] ) continue;
        for (auto it : adj[u]){
            int v = it.se; ld w = it.fi;
            if ( d[v] > d[u] + w &&  ( d[u] + w ) * 160 <= c[Y][v] * lim ){
                d[v] = d[u] + w;
                heap.push({d[v], v});
            }
        }
    }

    for (int i = 1; i <= n; i ++)
        if ( esc[i] && d[i] != oo ) return true;

    return false;
}

int main(){
    FASTio
    if ( fopen(simon".inp", "r") ){
        freopen(simon".inp", "r", stdin);
        freopen(simon".out", "w", stdout);
    }

    cin >> n >> m >> e;

    for (int i = 1; i <= n; i ++)
    for (int j = 1; j <= n; j ++)
        if ( i == j ) c[i][j] = 0;
        else c[i][j] = oo;


    for (int i = 1; i <= m; i ++){
        int u, v; ld w;
        cin >> u >> v >> w;
        adj[u].pb({w, v});
        adj[v].pb({w, u});
        c[u][v] = c[v][u] = min(c[u][v], w);
    }

    for (int k = 1; k <= n; k ++)
    for (int i = 1; i <= n; i ++)
    for (int j = 1; j <= n; j ++)
        c[i][j] = min(c[i][j], c[i][k] + c[k][j]);

    for (int i = 1, u; i <= e; i ++)
        cin >> u, esc[u] = 1;

    cin >> X >> Y;

    ld lo = 1.0, hi = 1e6, res = -1;
    for (int i = 1; i <= 100; i ++){
        ld mid = ( lo + hi ) / 2;
        if ( check(mid) ) res = mid, hi = mid;
        else lo = mid;
    }

    if ( res == -1 ) cout << "IMPOSSIBLE";
    else cout << fixed << setprecision(6) << res;

    return 0;
}
