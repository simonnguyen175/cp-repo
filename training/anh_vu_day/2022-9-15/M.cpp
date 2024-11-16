#include<bits/stdc++.h>
#define pb push_back
#define pi pair<int, int>
#define fi first
#define se second
using namespace std;
const int N = 3e5 + 5;

int n, m;
vector<pi> adj[N];
pi par[N], edg[N];
int mst[N], root[N], h[N], w[N];

int getroot(int u){
    if ( u == root[u] ) return u;
    else return root[u] = getroot(root[u]);
}

void dfs(int u, int pu){
    for (auto it : adj[u]){
        int v = it.fi;
        if ( v == pu ) continue;
        par[v] = {u, it.se};
        h[v] = h[u] + 1;
        dfs(v, u);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("trash.inp", "r") ){
        freopen("trash.inp", "r", stdin);
        freopen("trash.out", "w", stdout);
    }

    cin >> n >> m;
    for (int i = 1; i <= m; i ++){
        int u, v;
        cin >> u >> v;
        edg[i] = {u, v};
    }

    for (int i = 1; i < n; i ++){
        int id, u, v;
        cin >> id;
        mst[id] = 1;
        u = edg[id].fi, v = edg[id].se;
        adj[u].pb({v, id});
        adj[v].pb({u, id});
    }

    dfs(1, 0);
//    for (int i = 1; i <= n; i ++) cout << par[i].fi << ' ' << par[i].se << '\n';

    for (int i = 1; i <= n; i ++) root[i] = i;

    int cur = 0;
    for (int i = 1; i <= m; i ++) if ( !w[i] ){
        int u = edg[i].fi, v = edg[i].se;
        if ( mst[i] ){
            w[i] = ++cur;
            if ( par[v].fi == u ) root[v] = getroot(u);
            else root[u] = getroot(v);
        }
        else{
//            cout << u << ' ' << v << " : \n";

            u = getroot(u), v = getroot(v);

            vector<int> cont;
            while ( u != v ){
                if ( h[u] < h[v] ) swap(u, v);
                cont.pb(par[u].se);
                root[u] = getroot(par[u].fi);
                u = root[u];
            }

            sort(cont.begin(), cont.end());
            for (int x : cont){
                w[x] = ++cur;
//                cout << x << ' ' << cur << '\n';
            }
//            cout << '\n';
            w[i] = ++cur;
        }
    }

    for (int i = 1; i <= m; i ++)
        cout << w[i] << ' ';

    return 0;
}
