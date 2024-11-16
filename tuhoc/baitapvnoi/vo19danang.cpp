#include<bits/stdc++.h>
#define ll long long
#define pi pair<ll, ll>
#define fi first
#define se second
#define pb push_back
using namespace std;
const int N = 8e5 + 5;
const ll oo = 1e18;

int n, m, D;
struct edge{
    ll u, v, w, t;
} edges[N];
struct go{
    ll v, w, t;
};
vector<go> adj[N];

namespace sub2{
    ll d[N];
    priority_queue<pi, vector<pi>, greater<pi>> heap;

    void dijkstra(int i, int j){
        for (int k = i; k <= j; k ++)
            adj[edges[k].u].clear();

        for (int k = i; k <= j; k ++)
            adj[edges[k].u].pb({edges[k].v, edges[k].w, edges[k].t});

        for (int k = i; k <= j; k ++)
            heap.push({d[edges[k].u], edges[k].u});

        while ( heap.size() ){
            ll u = heap.top().se, du = heap.top().fi;
            heap.pop();

            if ( du != d[u] ) continue;

            for (auto it : adj[u]){
                int v = it.v, w = it.w;
                if ( d[v] > du + w + it.t * D ){
                    d[v] = du + w + it.t * D;
                    heap.push({d[v], v});
                }
            }
        }
    }

    void solve(){
        if ( D < 0 ){
            for (int i = 1; i <= m; i ++)
                edges[i+m] = {edges[i].u, edges[i].v, edges[i].w - D, 1};
            m *= 2;
        }

        sort(edges + 1, edges + 1 + m, [](edge a, edge b){
            return a.w < b.w;
        });

        for (int i = 1; i <= n; i ++) d[i] = oo;

        d[1] = 0;
        for (int i = 1; i <= m; i ++){
            int j = i;
            while ( edges[j].w == edges[j+1].w ) j ++;
            dijkstra(i, j);
            i = j;
        }

        cout << ( d[n] != oo ? d[n] : -1 );
    }
}

namespace sub4{
    ll d[N], mn[N];

    void solve(){
        sort(edges + 1, edges + 1 + m, [](edge a, edge b){
            return a.w < b.w;
        });

        for (int i = 1; i <= n; i ++) d[i] = oo, mn[i] = oo;
        d[1] = mn[1] = 0;

        int l = 1;
        for (int i = 1; i <= m; i ++){
            while ( l < i && edges[l].w + D <= edges[i].w ){
                ll tmp = d[edges[l].u] + edges[l].w;
                mn[edges[l].v] = min(mn[edges[l].v], ( d[edges[l].u] != oo ? tmp : oo));
                l ++;
            }
            ll tmp = mn[edges[i].u] + edges[i].w;
            d[edges[i].v] = min(d[edges[i].v], ( mn[edges[i].u] != oo ? tmp : oo));
        }

        cout << ( d[n] != oo ? d[n] : -1 );
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("vo19danang.inp", "r") ){
        freopen("vo19danang.inp", "r", stdin);
        freopen("vo19danang.out", "w", stdout);
    }

    cin >> n >> m >> D;

//    assert( D <= 0);

    for (int i = 1; i <= m; i ++){
        ll u, v, w;
        cin >> u >> v >> w;
        edges[i] = {u, v, w, 0};
        edges[i+m] = {v, u, w, 0};
    }
    m *= 2;

    if ( D <= 0 ) sub2::solve();
    else sub4::solve();

    return 0;
}
