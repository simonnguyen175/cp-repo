#include<bits/stdc++.h>
#define pi pair<int, int>
#define fi first
#define se second
#define pb push_back
using namespace std;
const int N = 2e5 + 5;

int n, m;
struct edg{
    int u, v;
    string x;
    int c;
} edges[N];
vector<pi> adj[N];
int h[N], p[N][21], mxe[N][21];

void add(int u, int v, int w){
//    cerr << u << ' ' << v << ' ' << w << '\n';
    adj[u].pb({v, w});
    adj[v].pb({u, w});
}

void dfs(int u, int pu){
    for (auto it : adj[u]){
        int v = it.fi;
        if ( v == pu ) continue;
        p[v][0] = u;
        mxe[v][0] = it.se;
        h[v] = h[u] + 1;
        dfs(v, u);
    }
}

int get(int u, int v){
    if ( h[u] < h[v] ) swap(u, v);
    int res = 0;
    for (int i = 20; i >= 0; i --)
        if ( h[p[u][i]] >= h[v] ){
            res = max(res, mxe[u][i]);
            u = p[u][i];
        }

    if ( u == v ) return res;

    for (int i = 20; i >= 0; i --)
    if ( p[u][i] != p[v][i] ){
        res = max({res, mxe[u][i], mxe[v][i]});
        u = p[u][i], v = p[v][i];
    }
    res = max({res, mxe[u][0], mxe[v][0]});
    return res;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

//    if ( fopen(simon".inp", "r") ){
//        freopen(simon".inp", "r", stdin);
//        freopen(simon".out", "w", stdout);
//    }

    cin >> n >> m;
    for (int i = 1; i <= m; i ++){
        int u, v, w = 0, c;
        string x;

        cin >> u >> v >> x >> c;
        edges[i] = {u, v, x, c};
        if ( x == "?" ){
            if ( c ) w = 1;
        }
        else
            for (int i = 0; i < x.size(); i ++)
                w = w * 10 + ( x[i] - '0' );
        if ( c ) add(u, v, w);
    }

    dfs(1, 0);
    for (int j = 1; j <= 20; j ++)
    for (int i = 1; i <= n; i ++){
        p[i][j] = p[p[i][j-1]][j-1];
        mxe[i][j] = max(mxe[i][j-1], mxe[p[i][j-1]][j-1]);
    }

    for (int i = 1; i <= m; i ++)
        if ( edges[i].x == "?" )
            if ( edges[i].c ) cout << 1 << '\n';
            else cout << get(edges[i].u, edges[i].v) << '\n';

    return 0;
}
