#include<bits/stdc++.h>
#define pb push_back
#define pi pair<int, int>
#define fi first
#define se second
using namespace std;
const int N = 4e5 + 5;

int sub, n, q, t, nn;
int h[N], sz[N], p[N][20], lab[N], pos[N];
vector<int> adj[N];
set<pi> cont[N];

void dfs(int u){
    sz[u] = 1;
    for (int v : adj[u]){
        h[v] = h[u] + 1;
        p[v][0] = u;
        dfs(v);
        sz[u] += sz[v];
    }
}

int lca(int u, int v){
    if ( h[u] < h[v] ) swap(u, v);

    for (int i = 19; i >= 0; i --)
        if ( h[p[u][i]] >= h[v] )
            u = p[u][i];

    if ( u == v ) return u;

    for (int i = 19; i >= 0; i --)
        if ( p[u][i] != p[v][i] )
            u = p[u][i], v = p[v][i];

    return p[u][0];
}

void dfs1(int u){
    lab[u] = nn;
    pos[u] = ++t;
    for (int v : adj[u])
        dfs1(v);
}

int get(int id){
    if ( !cont[id].size() ) return 0;

    int u = cont[id].begin()->se;
    int v = cont[id].rbegin()->se;
    int puv = lca(u, v);

//    cout << puv << ' ' << sz[puv] << ' ' << cont[id].size() << '\n';

    return sz[puv] - cont[id].size();
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    freopen("stalingrad.inp", "r", stdin);
    freopen("stalingrad.out", "w", stdout);


    cin >> sub >> n >> q;
    for (int i = 2, p; i <= n; i ++){
        cin >> p;
        adj[p].pb(i);
    }

    h[1] = 1;
    dfs(1);

    for (int j = 1; j <= 19; j ++)
    for (int i = 1; i <= n; i ++)
        p[i][j] = p[p[i][j-1]][j-1];
    for (int u : adj[1]){
        nn ++;
        dfs1(u);
    }

    pi ans = {0, 0};
    while ( q -- ){
        char type;
        int v;
        cin >> type >> v;

        if ( type == '+' ){
            ans.se -= get(lab[v]);

            if ( !cont[lab[v]].size() ) ans.fi ++;
            cont[lab[v]].insert({pos[v], v});

            ans.se += get(lab[v]);
        }
        else{
            ans.se -= get(lab[v]);

            cont[lab[v]].erase({pos[v], v});
            if ( !cont[lab[v]].size() ) ans.fi --;

            ans.se += get(lab[v]);
        }

        cout << ans.fi << ' ' << ans.se << '\n';
    }

    return 0;
}
