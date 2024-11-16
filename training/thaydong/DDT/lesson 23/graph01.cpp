#include<bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define pi pair<int, int>
using namespace std;
const int N = 1e6 + 5;
const int oo = 1e9;

int n, m, ans = oo;
struct node{
    int du, lw, u;
    bool operator > (const node &a) const{
        return du > a.du;
    }
};
int a[N], d[N][2];
vector<pi> adj[N];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("graph01.inp", "r") ){
        freopen("graph01.inp", "r", stdin);
        freopen("graph01.out", "w", stdout);
    }

    cin >> n >> m;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];

    for (int i = 1; i <= m; i ++){
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].pb({v, w});
        adj[v].pb({u, w});
    }

    priority_queue<node, vector<node>, greater<node>> heap;
    for (int i = 1; i <= n; i ++) d[i][0] = d[i][1] = oo;
    d[1][0] = d[1][1] = a[1];
    heap.push({d[1][0], 0, 1});
    heap.push({d[1][1], 1, 1});

    while ( heap.size() ){
        int u = heap.top().u;
        int du = heap.top().du;
        int lw = heap.top().lw;
        heap.pop();

//        cout << u << ' ' << du << ' ' << lw << '\n';

        if ( u == n ) ans = min(ans, du);

        if ( du != d[u][lw] ) continue;

        for (auto it : adj[u]){
            int v = it.fi, w = it.se;
            if ( w == a[u] ^ lw && d[v][w] > d[u][lw] + w + a[v] ){
                d[v][w] = d[u][lw] + w + a[v];
                heap.push({d[v][w], w, v});
            }
        }
    }

    cout << ( ans == oo ? -1 : ans );

    return 0;
}
