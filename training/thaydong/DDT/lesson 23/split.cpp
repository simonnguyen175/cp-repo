#include<bits/stdc++.h>
#define pb push_back
#define pi pair<int, int>
#define fi first
#define se second
using namespace std;
const int N = 2e5 + 5;

int n, m, a, b, c;
vector<int> adj[N];
int id[4];

namespace sub1{
    int va = 0, vb = 1, cnta = 0, cntb = 0;
    int sz[N], lab[N], par[N];

    void dfs(int u, int pu){
        sz[u] = 1;
        for (int v : adj[u]) if ( v != pu ){
            dfs(v, u);
            par[v] = u;
            sz[u] += sz[v];
        }

        if ( !va ){
            bool ck = ( sz[u] >= a );
            for (int v : adj[u]) if ( v != pu )
                ck &= ( sz[v] < a );

            if ( ck ) va = u;
        }
    }

    void dfsa(int u){
        if ( cnta == a ) return;
        cnta ++; lab[u] = 1;
        for (int v : adj[u]) if ( v != par[u] && v != vb )
            dfsa(v);
    }

    void dfsb(int u){
        if ( cntb == b ) return;
        cntb ++; lab[u] = 2;
        for (int v : adj[u]) if ( v != par[u] && v != va )
            dfsb(v);
    }

    void solve(){
        dfs(1, 0);
        if ( n - sz[va] < a ){
            for (int i = 1; i <= n; i ++)
                cout << 0 << ' ';
            return;
        }
        else{
            if ( sz[va] >= b ) swap(vb, va);
            for (int i = 1; i <= n; i ++) lab[i] = 3;
            dfsa(va);
            dfsb(vb);
            for (int i = 1; i <= n; i ++)
                cout << id[lab[i]] << ' ';
        }
    }
}

namespace sub2{
    int timeDfs = 0, va = 0, vb = 1, cnta = 0, cntb = 0;
    int num[N], low[N], sz[N], par[N], lab[N], una[N];
    vector<int> g[N];

    void dfs(int u, int pu){
        num[u] = low[u] = ++timeDfs;
        sz[u] = 1;
        par[u] = pu;

        bool ck = 1;

        for (int v : adj[u]) if ( v != pu )
            if ( num[v] ) low[u] = min(low[u], num[v]);
            else{
                dfs(v, u);
                low[u] = min(low[u], low[v]);
                sz[u] += sz[v];
                g[u].pb(v);
                ck &= ( sz[v] < a );
            }

        ck &= ( sz[u] >= a );
        if ( ck && !va ) va = u;
    }

    void dfsa(int u){
        if ( cnta == a ) return;
        cnta ++; lab[u] = 1;
        for (int v : g[u]) if ( v != vb && !una[v] )
            dfsa(v);
    }

    void dfsb(int u){
        if ( cntb == b ) return;
        cntb ++; lab[u] = 2;
        for (int v : g[u]) if ( v != va && !una[v] )
            dfsb(v);
    }

    void solve(){
        dfs(1, 0);

//        for (int i = 1; i <= n; i ++)
//            cout << num[i] << ' ' << low[i] << ' ' << par[i] << ' ' << sz[i] << '\n';
//        cout << va << '\n';

        if ( n - sz[va] >= a ){
//            cout << "here\n";
            for (int i = 1; i <= n; i ++) lab[i] = 3;
            if ( sz[va] >= b ) swap(va, vb);
            dfsa(va);
            dfsb(vb);
            for (int i = 1; i <= n; i ++)
                cout << id[lab[i]] << ' ';
        }
        else{
            for (int i = 1; i <= n; i ++) lab[i] = 3;

            int rem = n - sz[va];
            vector<int> take;
            for (int v : g[va]){
                if ( rem >= a ) break;
                if ( low[v] < num[va] ){
                    take.pb(v);
                    rem += sz[v];
                    una[v] = 1;
                }
            }

            if ( rem < a )
                for (int i = 1; i <= n; i ++) cout << 0 << ' ';
            else{
                if ( sz[va] >= b ){
                    swap(va, vb);
                    dfsa(va);
                    for (int v : take) dfsa(v);
                    dfsb(vb);
                }
                else{
                    dfsa(va);
                    dfsb(1);
                    for (int v : take) dfsb(v);
                }
                for (int i = 1; i <= n; i ++) cout << id[lab[i]] << ' ';
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("split.inp", "r") ){
        freopen("split.inp", "r", stdin);
        freopen("split.out", "w", stdout);
    }

    cin >> n >> m >> a >> b >> c;
    pi gro[4];
    gro[1] = {a, 1};
    gro[2] = {b, 2};
    gro[3] = {c, 3};
    sort(gro + 1, gro + 4);
    a = gro[1].fi, id[1] = gro[1].se;
    b = gro[2].fi, id[2] = gro[2].se;
    c = gro[3].fi, id[3] = gro[3].se;

    for (int i = 1; i <= m; i ++){
        int u, v;
        cin >> u >> v;
        u ++, v ++;
        adj[u].pb(v);
        adj[v].pb(u);
    }

//    if ( m == n - 1 ) sub1::solve();
//    else
        sub2::solve();

    return 0;
}
