#include<bits/stdc++.h>
#define simon "tour"
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
#define pi pair<int, int>
#define fi first
#define se second
#define pb push_back
using namespace std;
const int N = 1e3 + 5;
const ll oo = 1e12;

int n, m, p, s, t;
ll d[N][N];
int D[N];
vector<pi> adj[N];

void dijkstra(int x){
    priority_queue<pi, vector<pi>, greater<pi>> heap;
    for (int i = 1; i <= n; i ++) d[x][i] = oo;
    d[x][x] = 0; heap.push({0, x});

    while ( heap.size() ){
        int u = heap.top().se, du = heap.top().fi;
        heap.pop();
        if ( du != d[x][u] ) continue;
        for (auto it : adj[u]){
            int v = it.fi, w = it.se;
            if ( d[x][v] > du + w ){
                d[x][v] = du + w;
                heap.push({d[x][v], v});
            }
        }
    }
}

int main(){
    FASTio
    if ( fopen(simon".inp", "r") ){
        freopen(simon".inp", "r", stdin);
        freopen(simon".out", "w", stdout);
    }

    cin >> n >> m >> p >> s >> t;
    for (int i = 1; i <= m; i ++){
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].pb({v, w});
        adj[v].pb({u, w});
    }

    for (int i = 1; i <= p; i ++)
        cin >> D[i];


    dijkstra(s); dijkstra(t);

    ll ans = oo;

    //for (int i = 1; i <= n; i ++)
    //    cout << d[s][i] << ' '; cout << '\n';

    for (int i = 1; i <= p; i ++)
        if ( d[s][D[i]] + d[t][D[i]] < ans )
            ans = d[s][D[i]] + d[t][D[i]];

    cout << ans;

    return 0;
}
