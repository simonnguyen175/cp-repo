#include<bits/stdc++.h>
#define pi pair<int, int>
#define fi first
#define se second
#define pb push_back
using namespace std;
const int N = 5e5 + 5;
const int MOD = 998244353;

int sub, m, n;
struct edge{
    int u, v, w;
    bool operator < (const edge &a) const{
        return w < a.w;
    }
} edges[N];
int Par[N], Rank[N];
int timedfs = 0, vis[N], tmp[10], flag;
vector<int> adj[N];

int Find(int u){
    if ( u == Par[u] ) return u;
    else return Par[u] = Find(Par[u]);
}

bool ck(int u, int v){
    u = Find(u); v = Find(v);
    return ( u != v );
}

bool Join(int u, int v){
    u = Find(u); v = Find(v);
    if ( u != v ){
        if ( Rank[u] <  Rank[v] ) swap(u, v);
        Par[v] = u;
        if ( Rank[u] == Rank[v] ) Rank[u] ++;
        return true;
    }
    else return false;
}

void dfs(int u, int pu){
    if ( !flag ) return;
    //cout << u << ' ' << vis[u] << '\n';
    if ( vis[u] == timedfs ) { flag = 0; return; }
    vis[u] = timedfs;
    for (int v : adj[u]){
        //cout <<  "-> " << v << '\n';
        if ( v == pu ) continue;
        dfs(v, u);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("cnt-mst.inp", "r") ){
        freopen("cnt-mst.inp", "r", stdin);
        freopen("cnt-mst.out", "w", stdout);
    }

    cin >> sub >> n >> m;
    for (int i = 1; i <= m; i ++){
        int u, v, w;
        cin >> u >> v >> w;
        edges[i] = {u, v, w};
    }

    long long ans = 1;

    sort(edges + 1, edges + 1 + m);

    for (int i = 1; i <= n; i ++) Par[i] = i, Rank[i] = 1;

    int i = 1;
    while ( i <= m ){
        int st = i;

        while ( edges[i].w == edges[i+1].w && i < m ) i ++;

        vector<edge> cont;
        for (int j = st; j <= i; j ++)
            if ( ck(edges[j].u, edges[j].v) )
                cont.pb(edges[j]);

        memset(tmp, 0, sizeof tmp);
        int mxe = 0;

        vector<int> ver; vector<pi> edg;
        for (int t = 1; t < (1<<cont.size()); t ++){
            ver.clear(); edg.clear();
            for (int j = 0; j < cont.size(); j ++)
                if ( (t>>j)&1 ){
                    int u = Find(cont[j].u), v = Find(cont[j].v);
                    ver.pb(u); ver.pb(v);
                    edg.pb({u, v});
                }
            for (int u : ver) adj[u].clear();
            for (auto it : edg){
                adj[it.fi].pb(it.se);
                adj[it.se].pb(it.fi);
            }

            flag = 1;
            timedfs ++;
            //cout << timedfs << '\n';
            for (int u : ver) if ( vis[u] != timedfs )
                dfs(u, 0);

            if ( flag )
                mxe = max(mxe, __builtin_popcount(t)), tmp[__builtin_popcount(t)] ++;

            //cout << "----------------" << '\n';
        }

        if ( tmp[mxe] > 0 ) ( ans *= tmp[mxe] ) %= MOD;

        for (int j = st; j <= i; j ++)
            Join(edges[j].u, edges[j].v);

        i ++;
    }

    cout << ans;

    return 0;
}

