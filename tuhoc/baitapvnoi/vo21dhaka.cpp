#include<bits/stdc++.h>
#define ll long long
#define pi pair<int, int>
#define fi first
#define se second
#define pb push_back
using namespace std;
const int N = 1e5 + 5;
const ll oo = 1e15;

int n, m, k, l;
vector<pi> adj[N];
struct node{
    ll du;
    int u, tu;
    bool operator > (const node &a) const{
        return du > a.du;
    }
};
int t[N];
ll d[N][50];

void dijkstra(){
    for (int i = 1; i <= n; i ++)
    for (int j = 0; j < (1<<k); j ++)
        d[i][j] = oo;

    priority_queue<node, vector<node>, greater<node>> heap;
    d[1][t[1]] = 0; heap.push({0, 1, t[1]});

    while ( heap.size() ){
        int u = heap.top().u;
        ll du = heap.top().du;
        int tu = heap.top().tu;

        heap.pop();

        if ( du != d[u][tu] ) continue;

        for (auto it : adj[u]){
            int v = it.fi, w = it.se;
            if ( d[v][tu|t[v]] > du + w ){
                d[v][tu|t[v]] = du + w;
                heap.push({du + w, v, tu|t[v]});
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n >> m >> k >> l;
    for (int i = 1, sl; i <= n; i ++){
        cin >> sl;
        for (int j = 1, x; j <= sl; j ++)
            cin >> x, t[i] += (1<<(x-1));
    }

    for (int i = 1; i <= m; i ++){
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].pb({v, w});
        adj[v].pb({u, w});
    }

    dijkstra();


    ll ans = oo;
    for (int i = 0; i < (1<<k); i ++)
        if ( __builtin_popcount(i) >= l )
            ans = min(ans, d[n][i]);

    cout << ( ans == oo ? -1 : ans );

    return 0;
}
