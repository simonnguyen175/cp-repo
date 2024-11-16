#include<bits/stdc++.h>
#define simon "gps"
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
#define pi pair<ll, ll>
#define fi first
#define se second
#define pb push_back
using namespace std;
const int N = 5e4 + 5;
const ll oo = 1e12;

int n, m;
vector<pi> adj[N], adju[2][N], adjd[2][N];
struct canh{
    int u, v, w1, w2;
};
vector<canh> g;
ll d[N], d1[2][N], dn[2][N];
int f[N], vis[N];

void dijkstra(int x, int t){
    if ( x == 1 ){
        for (int i = 1; i <= n; i ++) d1[t][i] = oo;
        d1[t][1] = 0;
        priority_queue<pi, vector<pi>, greater<pi>> heap;
        heap.push({0, 1}); d1[t][1] = 0;
        while ( heap.size() ){
            int u = heap.top().se;
            ll du = heap.top().fi;
            heap.pop();

            if ( du != d1[t][u] ) continue;

            for (auto it : adju[t][u]){
                int v = it.fi, w = it.se;
                if ( d1[t][v] > du + w ){
                    d1[t][v] = du + w;
                    heap.push({d1[t][v], v});
                }
            }
        }
    }
    else{
        for (int i = 1; i <= n; i ++) dn[t][i] = oo;
        dn[t][n] = 0;
        priority_queue<pi, vector<pi>, greater<pi>> heap;
        heap.push({0, n}); dn[t][n] = 0;
        while ( heap.size() ){
            int u = heap.top().se;
            ll du = heap.top().fi;
            heap.pop();

            if ( du != dn[t][u] ) continue;

            for (auto it : adjd[t][u]){
                int v = it.fi, w = it.se;
                if ( dn[t][v] > du + w ){
                    dn[t][v] = du + w;
                    heap.push({dn[t][v], v});
                }
            }
        }
    }
}

int main(){
    FASTio
    if ( fopen(simon".in", "r") ){
        freopen(simon".in", "r", stdin);
        freopen(simon".out", "w", stdout);
    }

    cin >> n >> m;
    for (int i = 1; i <= m; i ++){
        int u, v, w1, w2;
        cin >> u >> v >> w1 >> w2;

        g.pb({u, v, w1, w2});

        adju[0][u].pb({v, w1});
        adju[1][u].pb({v, w2});

        adjd[0][v].pb({u, w1});
        adjd[1][v].pb({u, w2});
    }

    dijkstra(1, 0); dijkstra(n, 0);
    dijkstra(1, 1); dijkstra(n, 1);

    for (auto it : g){
        int u = it.u, v = it.v, w1 = it.w1, w2 = it.w2, c = 0;
        if ( w1 + dn[0][v] != dn[0][u] ) c ++;
        if ( w2 + dn[1][v] != dn[1][u] ) c ++;
        adj[u].pb({v, c});
    }

    for (int i = 1; i <= n; i ++) d[i] = oo;
    d[1] = 0;
    priority_queue<pi, vector<pi>, greater<pi>> heap;
    heap.push({0, 1});
    while ( heap.size() ){
        int u = heap.top().se;
        ll du = heap.top().fi;
        heap.pop();

        if ( du != d[u] ) continue;

        for (auto it : adj[u]){
            int v = it.fi, w = it.se;
            if ( d[v] > du + w ){
                d[v] = du + w;
                heap.push({d[v], v});
            }
        }
    }
    cout << d[n];

    return 0;
}
