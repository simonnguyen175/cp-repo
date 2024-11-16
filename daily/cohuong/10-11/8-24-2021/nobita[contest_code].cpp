#include<bits/stdc++.h>
#define simon "nobita"
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
#define pb push_back
#define pi pair<ll, int>
#define fi first
#define se second
using namespace std;
const int N = 1e5 + 5;
const ll oo = 1e15;

int n, m, k;
vector<pi> adj[N];
struct edge{
    int u, v;
    ll w;
};
vector<edge> edges;
vector<int> listdoor;
int door[N];

namespace sub1{
    int Par[N], Rank[N];

    bool cmp (edge a, edge b){
        return a.w < b.w;
    }

    int Find(int u){
        if ( u == Par[u] ) return u;
        else return Par[u] = Find(Par[u]);
    }

    bool Join(int u, int v){
        u = Find(u); v = Find(v);
        if ( u != v ){
            if ( Rank[u] < Rank[v] ) swap(u, v);
            Par[v] = u;
            if ( Rank[u] == Rank[v] ) Rank[u] ++;
            return true;
        }
        else return false;
    }

    void solve(){
        ll ans = 0;
        sort(edges.begin(), edges.end(), cmp);
        for (int i = 1; i <= n; i ++) Par[i] = i, Rank[i] = 0;
        for (auto it : edges){
            if ( Join(it.u, it.v) )
                ans += it.w;
        }
        cout << ans;
    }
}

namespace sub2{
    ll d[N];

    void solve(){
        for (int i = 1; i <= n; i ++) d[i] = oo;
        d[1] = 0;

        priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> heap;

        heap.push({0, 1});

        while ( heap.size() ){
            int u = heap.top().se;
            ll du = heap.top().fi;
            heap.pop();
            for (auto it : adj[u]){
                int v = it.se; ll w = it.fi;
                if ( d[v] > du + w ){
                    d[v] = du + w;
                    heap.push({d[v], v});
                }
            }
        }

        for (int i = 1; i <= n; i ++)
            if ( door[i] ){
                cout << d[i];
                return;
            }
    }
}

namespace sub3{
    ll f[N][(1<<4)];

    struct node{
        ll d;
        int u, mask;
    };

    bool operator > (const node &a, const node &b){
        return a.d > b.d;
    }

    void solve(){
        for (int i = 1; i <= n; i ++)
        for (int j = 0; j < (1<<k); j ++)
                f[i][j] = oo;

        priority_queue<node, vector<node>, greater<node>> heap;

        if ( !door[1] ){
            f[1][0] = 0;
            heap.push({0, 1, 0});

        }
        else{
            f[1][1<<(door[1]-1)] = 0;
            heap.push({0, 1, (1<<(door[1]-1))});
        }

        while ( heap.size() ){
            int u = heap.top().u, mask = heap.top().mask;
            ll du = heap.top().d;
            heap.pop();

            if ( du != f[u][mask] ) continue;

            for (auto it : adj[u]){
                int v = it.se; ll w = it.fi;
                int nmask = mask;
                if ( door[v] ) nmask |= (1<<(door[v]-1));


                if ( f[v][nmask] > du + w ){
                    f[v][nmask] = du + w;
                    heap.push({f[v][nmask], v, nmask});
                }
            }

            for (int v : listdoor)
                if ( mask&(1<<(door[v]-1)) )
                    if ( f[v][mask] > du ){
                        f[v][mask] = du;
                        heap.push({f[v][mask], v, mask});
                    }
        }

        ll ans = oo;
        for (int i = 1; i <= n; i ++)
            ans = min(ans, f[i][(1<<k)-1]);

        cout << ans;
    }
}

int main(){
    FASTio
    if ( fopen(simon".inp", "r") ){
        freopen(simon".inp", "r", stdin);
        freopen(simon".out", "w", stdout);
    }

    cin >> n >> m;

    for (int i = 1; i <= m; i ++){
        int u, v; ll w;
        cin >> u >> v >> w;
        adj[u].pb({w, v});
        adj[v].pb({w, u});
        edges.pb({u, v, w});
    }

    cin >> k;
    memset(door, 0, sizeof door);
    for (int i = 1; i <= k; i ++){
        int u; cin >> u;
        door[u] = i;
        listdoor.pb(u);
    }

    if ( k == n ) { sub1::solve(); return 0; }

    if ( k == 1 ) { sub2::solve(); return 0; }

    if ( k <= 4 ) { sub3::solve(); return 0; }

    return 0;
}
