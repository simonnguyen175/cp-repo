#include<bits/stdc++.h>
#define simon "shortest"
#define FASTio ios_base::sync_with_stdio9
#define ll long long
#define ii pair<int, int>
#define fi first
#define se second
using namespace std;
const int oo = 1e12;
const int N = 3e3 + 5;
const int MOD = 1e9 + 7;

struct opt{
    int u, v, w;
};

int n, m;
vector<ii> adj[N];
opt edge[N];
int d[N][N], len[N][N];
ll f[N][N], vis[1005];

void dijkstra(int x){
    priority_queue<ii, vector<ii>, greater<ii>> heap;
    heap.push({0, x});

    while ( !heap.empty() ){
        int u = heap.top().se;
        ll du = heap.top().fi;
        heap.pop();

        if ( du != d[x][u] ) continue;

        for (auto tmp : adj[u]){
            int v = tmp.se;
            ll uv = tmp.fi;
            if ( d[x][v] > du + uv ){
                d[x][v] = du + uv;
                f[x][v] = f[x][u]; f[x][v] %= MOD;
                heap.push({d[x][v], v});
            }
            else
                if ( d[x][v] == du + uv ){
                    f[x][v] += f[x][u]; f[x][v] %= MOD;
                }
        }
    }

}

int main(){
    if ( fopen(simon".inp", "r" ) ){
        freopen(simon".inp", "r", stdin);
        freopen(simon".out", "w", stdout);
    }
    ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

    cin >> n >> m;

    for (int i = 1; i <= m; i ++){
        cin >> edge[i].u >> edge[i].v >> edge[i].w;
        adj[edge[i].u].push_back({edge[i].w, edge[i].v});
    }

    for (int i = 1; i <= n; i ++)
    for (int j = 1; j <= n; j ++){
        if ( i == j ) f[i][i] = 1, d[i][j] = 0;
        else d[i][j] = 1e15, f[i][j] = 0;
    }

    for (int i = 1; i <= n; i ++)
        dijkstra(i);

    for (int k = 1; k <= m; k ++){
        ll res = 0;
        for (int i = 1; i <= n; i ++)
            for (int j = 1; j <= n; j ++){
                if ( i == j ) continue;
                int x = edge[k].u, y = edge[k].v, w = edge[k].w;
                if ( d[i][x] + w + d[y][j] == d[i][j] )
                    res = ( res + f[i][x] * f[y][j] ) % MOD;
            }
        cout << res << '\n';
    }
    return 0;
}
