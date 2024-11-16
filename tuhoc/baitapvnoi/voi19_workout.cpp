#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define pi pair<ll, ll>
#define fi first
#define se second
#define BIT(x, k) ((x>>k)&1)
using namespace std;
const int N = 1e5 + 5;
const ll oo = 1e18;

int n, m, k;
int sf[N][2], p[11];
vector<pi> adj[N], ad1[N], ad2[N];
ll d[11][2][N], f[N][6][(1<<6)+5];
struct edge{
    int u, v, w;
};
edge edges[N];
vector<int> topo, ez;

bool cmp(int a, int b){
    return d[0][0][a] < d[0][0][b];
}

void maximum(ll &a, ll b){
    if ( b > a ) a = b;
}

void dijkstra(int id, int t){
    priority_queue<pi, vector<pi>, greater<pi>> heap;
    for (int i = 1; i <= n; i ++) d[id][t][i] = oo;

    d[id][t][sf[id][t]] = 0;
    heap.push({0, sf[id][t]});

    while ( heap.size() ){
        int u = heap.top().se;
        ll du = heap.top().fi;
        heap.pop();

        if ( du != d[id][t][u] ) continue;

        for (auto it : adj[u]){
            int v = it.fi, w = it.se;
            if ( d[id][t][v] > d[id][t][u] + w ){
                d[id][t][v] = d[id][t][u] + w;
                heap.push({d[id][t][v], v});
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("voi19_workout.inp", "r") ){
        freopen("voi19_workout.inp", "r", stdin);
        freopen("voi19_workout.out", "w", stdout);
    }

    cin >> n >> m >> k;
    for (int i = 1; i <= m; i ++){
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].pb({v, w});
        adj[v].pb({u, w});
        edges[i] = {u, v, w};
    }

    cin >> sf[0][0] >> sf[0][1];

    for (int i = 1; i < k; i ++)
        cin >> p[i] >> sf[i][0] >> sf[i][1];

    for (int i = 0; i < k; i ++){
        dijkstra(i, 0);
        dijkstra(i, 1);
    }

    for (int i = 1; i <= m; i ++){
        int u = edges[i].u, v = edges[i].v, w = edges[i].w;
        if ( d[0][0][u] + w + d[0][1][v] == d[0][0][sf[0][1]] )
            ad1[u].pb({v, w});
        if ( d[0][1][u] + w + d[0][0][v] == d[0][0][sf[0][1]] )
            ad1[v].pb({u, w});
    }

    for (int i = 1; i < k; i ++) if ( !p[i] ){
        for (int j = 1; j <= m; j ++){
            int u = edges[j].u, v = edges[j].v, w = edges[j].w;

            if ( d[0][0][u] + w + d[0][1][v] == d[0][0][sf[0][1]]
              && d[i][0][u] + w + d[i][1][v] == d[i][0][sf[i][1]]
              && d[i][0][u] == d[0][0][u] ) ad2[u].pb({v, w});

            if ( d[0][0][v] + w + d[0][1][u] == d[0][0][sf[0][1]]
              && d[i][0][v] + w + d[i][1][u] == d[i][0][sf[i][1]]
              && d[i][0][v] == d[0][0][v] ) ad2[v].pb({u, w});
        }
    }

    for (int i = 1; i <= n; i ++) topo.pb(i);
    sort(topo.begin(), topo.end(), cmp);

    memset(f, -0x3f, sizeof f);

    for (int i = 0; i < k; i ++) if ( p[i] ) ez.pb(i);

    int nn = ez.size();

    f[sf[0][0]][nn][0] = 0;

    ll res = -oo;

    for (int i : topo){
        for (int msk = 0; msk < (1<<nn); msk ++){
//             de tinh
            for (int j = 0; j < nn; j ++) if ( !BIT(msk, j) ){
                int cur = ez[j];
                maximum(res, f[i][cur][msk]);

//                 ko di tiep voi j
                maximum(f[i][nn][msk|(1<<j)], f[i][j][msk]);

//                 di tiep voi j
                for (auto it : ad1[i])
                if ( d[cur][0][i] + it.se + d[cur][1][it.fi] == d[cur][0][sf[cur][1]])
                    maximum(f[it.fi][j][msk], f[i][j][msk] + it.se);
            }

            maximum(res, f[i][nn][msk]);

            // alone
            for (auto it : ad1[i]) maximum(f[it.fi][nn][msk], f[i][nn][msk]);

            // kho tinh
            for (auto it : ad2[i]) maximum(f[it.fi][nn][msk], f[i][nn][msk] + it.se);

            // bat dau di voi 1 thang de tinh
            for (auto it : ad1[i])
            for (int j = 0; j < nn; j ++) if ( !BIT(msk, j) ){
                int cur = ez[j];
                if ( d[cur][0][i] + it.se + d[cur][1][it.fi] == d[cur][0][sf[cur][1]] )
                    maximum(f[it.fi][j][msk], f[i][nn][msk] + it.se);
            }
        }
    }

    cout << res;

    return 0;
}
