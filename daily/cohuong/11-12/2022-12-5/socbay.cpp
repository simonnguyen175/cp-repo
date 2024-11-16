#include<bits/stdc++.h>
#define int long long
#define pi pair<int, int>
#define fi first
#define se second
#define pb push_back
using namespace std;
const int N = 1e5 + 5;
const int oo = 1e15;

int n, m, x;
vector<pi> adj[N];
int h[N], d[N];
struct node{
    int u, ch, du;
    bool operator > (const node &a) const{
        return du > a.du;
    }
};

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

//    if ( fopen("socbay.inp", "r") ){
//        freopen("socbay.inp", "r", stdin);
//        freopen("socbay.out", "w", stdout);
//    }

    cin >> n >> m >> x;
    for (int i = 1; i <= n; i ++)
        cin >> h[i];
    for (int i = 1, u, v, w; i <= m; i ++){
        cin >> u >> v >> w;
        adj[u].pb({v, w});
        adj[v].pb({u, w});
    }
    for (int i = 1; i <= n; i ++) d[i] = oo;
    priority_queue<node, vector<node>, greater<node>> heap;
    heap.push({1, x, 0});
    d[1] = 0;
    while ( heap.size() ){
        int u = heap.top().u, ch = heap.top().ch, du = heap.top().du;
        heap.pop();

        if ( du != d[u] ) continue;

        if ( u == n ) { cout << du + h[u] - ch << '\n'; return 0; }

        for (auto it : adj[u]){
            int v = it.fi, w = it.se;
            if ( h[u] < w ) continue;
            int nh = ch-w;
            if ( nh > h[v] ) w += nh-h[v], nh = h[v];
            if ( d[v] > d[u] + w ){
                d[v] = d[u] + w;
                heap.push({v, nh, d[v]});
            }
        }
    }

    cout << -1 << '\n';

    return 0;
}
