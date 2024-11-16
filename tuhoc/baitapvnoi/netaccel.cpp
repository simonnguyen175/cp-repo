#include<bits/stdc++.h>
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ii pair<int, int>
#define pb push_back
#define fi first
#define se second
#define ll long long
using namespace std;
const int N = 1e4;
const ll oo = 1e12;

struct net{
    double d;
    int u, ins;
};

bool operator > (const net &a, const net &b){
    return a.d > b.d;
}

int n, m, k;
vector<ii> adj[N];
double d[N][11];

void dijkstra(){
    priority_queue<net, vector<net>, greater<net>>  heap;
    for (int i = 1; i <= n; i ++)
        for (int j = 0; j <= k; j ++)
            d[i][j] = oo;
    d[1][0] = 0;
    heap.push({0, 1, 0});

    while ( heap.size() ){
        int u = heap.top().u;
        double du = heap.top().d;
        int install = heap.top().ins;
        heap.pop();

        //cout << u << '\n';

        for (auto it : adj[u]){
            int v = it.se, w = it.fi;
            double mu = 1.0;
            for (int j = 0; j <= k - install; j ++){
                if ( d[v][install + j] > du + w * 1.0 / mu ){
                    //cout << v << ' ' << install + j << ' ' <<  d[v][install + j] << '\n';
                     d[v][install + j] = du + w * 1.0 / mu;
                    heap.push({d[v][install + j], v, install + j});
                }
                mu *= 2.0;
            }
        }
    }
}

void init(){
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i ++){
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].pb({w, v});
        adj[v].pb({w, u});
    }
}

void solve(){
    dijkstra();
    cout << fixed << setprecision(2) << d[n][k];
}

int main(){
    FASTio
    init();
    solve();
    return 0;
}
