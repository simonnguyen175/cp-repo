#include<bits/stdc++.h>
#define pi pair<int, int>
#define fi first
#define se second
#define pb push_back
using namespace std;
const int N = 5e5 + 5;

int sub, m, n;
struct edge{
    int u, v, w, id;
    bool operator < (const edge &a) const{
        return w < a.w;
    }
} edges[N];
int Par[N], Rank[N], timedfs;
int used[N], num[N], low[N], all[N];
vector<pi> adj[N];

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

void dfs(int u){
    num[u] = low[u] = ++ timedfs;
    for (auto it : adj[u]) if ( !used[it.se] ){
        int v = it.fi;
        used[it.se] = 1;
        if ( !num[v] ){
            dfs(v);
            low[u] = min(low[u], low[v]);
            if ( low[v] > num[u] ) all[it.se] = 1;
        }
        else low[u] = min(low[u], num[v]);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= m; i ++){
        int u, v, w;
        cin >> u >> v >> w;
        edges[i] = {u, v, w, i};
    }

    sort(edges + 1, edges + 1 + m);

    for (int i = 1; i <= n; i ++) Par[i] = i, Rank[i] = 1;

    memset(used, 0, sizeof used);

    int i = 1;
    while ( i <= m ){
        int st = i;

        while ( edges[i].w == edges[i+1].w && i < m ) i ++;

        vector<int> ver;
        vector<edge> edg;

        for (int j = st; j <= i; j ++)
            if ( ck(edges[j].u, edges[j].v) ){
                int u = Find(edges[j].u), v = Find(edges[j].v);

                ver.pb(u); ver.pb(v);

                edg.pb({u, v, edges[j].w, edges[j].id});
            }

        sort(ver.begin(), ver.end());
        ver.erase(unique(ver.begin(), ver.end()), ver.end());
        timedfs = 0;
        for (int u : ver) low[u] = num[u] = 0, adj[u].clear();

//        cout << "tao cay \n";
        for (auto it : edg){
//            cout << it.u << ' ' << it.v << ' ' << it.id << '\n';
            adj[it.u].pb({it.v, it.id});
            adj[it.v].pb({it.u, it.id});
        }

        for (int u : ver) if ( !num[u] ) dfs(u);

        for (int j = st; j <= i; j ++)
            Join(edges[j].u, edges[j].v);

        i ++;
    }

    for (int i = 1; i <= m; i ++)
        if ( all[i] ) cout << "any\n";
        else if ( used[i] ) cout << "at least one\n";
        else cout << "none\n";

    return 0;
}
