#include<bits/stdc++.h>
#define pi pair<int, int>
#define fi first
#define se second
#define pb push_back
using namespace std;
const int N = 3e5 + 5;

int sub, n, t, Q;
vector<int> adj[N];
int h[N], p[N][25];
pi q[N];

void dfs(int u, int pu){
    for (int v : adj[u]){
        if ( v == pu ) continue;
        p[v][0] = u;
        h[v] = h[u] + 1;
        dfs(v, u);
    }
}

int lca(int u, int v){
    if ( h[u] < h[v] ) swap(u, v);

    for (int i = 20; i >= 0; i --)
        if ( h[p[u][i]] >= h[v] ){
            u = p[u][i];
        }

    if ( u == v ) return u;

    for (int i = 20; i >= 0; i --)
        if ( p[u][i] != p[v][i] )
            u = p[u][i], v = p[v][i];

    return p[u][0];
}

namespace sub4{
    void solve(){
        int root;
        for (int i = 1; i <= n; i ++)
            if ( adj[i].size() == 1 ){
                root = i;
                break;
            }

        h[root] = 1;
        dfs(root, 0);

        cin >> t;
        while ( t -- ){
            cin >> Q;
            for (int i = 1; i <= Q; i ++){
                cin >> q[i].fi >> q[i].se;
                q[i] = h[q[i].fi]; q[i]
                if ( h[q[i].se] < h[q[i].fi] ) swap(q[i].fi, q[i].se);
            }

            bool ck = 0;
            int r = 0;
            sort(q + 1, q + 1 + Q);

            set<int> cont;
            for (int i = 1; i <= Q; i ++){
                if ( q[i])
                auto it = cont.lower_bound(h[q[i].se]);
                if ( cont.size() == 0 || it == cont.begin() || h[q[i]) { cont.insert(h[q[i].se]); continue; }
                it --;
                if ( *it >= h[q[i].fi] ) { ck = 1; break; }
                cont.insert(h[q[i].se]);
            }

            if ( ck ) cout << "MAP MO\n";
            else cout << "RO RANG\n";
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("tree.inp", "r") ){
        freopen("tree.inp", "r", stdin);
        freopen("tree.out", "w", stdout);
    }

    cin >> sub;

    cin >> n;
    for (int i = 1; i < n; i ++){
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    if ( sub == 4 ) { sub4::solve(); return 0; }

    h[1] = 1;
    dfs(1, 0);

    for (int i = 1; i <= 20; i ++)
    for (int u = 1; u <= n; u ++)
        p[u][i] = p[p[u][i-1]][i-1];

//    cin >> t;
//    while ( t -- ){
//        cin >> Q;
//        for (int i = 1; i <= Q; i ++)
//            cin >> q[i].fi >> q[i].se;
//
//        bool ck = 0;
//        for (int i = 1; i <= Q; i ++)
//        for (int j = i + 1; j <= Q; j ++)
//            if ( check(i, j) )
//                ck = 1;
//
//        if ( !ck ) cout << "RO RANG\n";
//        else cout << "MAP MO\n";
//    }

    return 0;
}
