#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
const int N = 3e5 + 5;

int n;
int a[N], used[N], sz[N], pre[N], suf[N];
map<int, int> d;
vector<int> adj[N];
ll ans = 0;

int dfs_size(int u, int pu){
    sz[u] = 1;
    for (int v : adj[u]) if ( v != pu && !used[v] )
        sz[u] += dfs_size(v, u);
    return sz[u];
}

int centroid(int u, int pu, int nn){
    for (int v : adj[u]) if ( v != pu && !used[v] )
        if ( sz[v] > nn / 2 ) return centroid(v, u, nn);
    return u;
}

void dfs(int u, int pu, int cmx){
//    cout << u << ' ' << pre[u] << ' ' << cmx << '\n';

    if ( pre[u] - cmx >= 0 ) d[pre[u]] ++;

    for (int v : adj[u]) if ( v != pu && !used[v] ){
        pre[v] = pre[u] + a[v];
        dfs(v, u, max(cmx, pre[u]));
    }
}

void add(int u, int pu, int cmx, int delta){
    if ( pre[u] - cmx >= 0 ) d[pre[u]] += delta;

    for (int v : adj[u]) if ( v != pu && !used[v] )
        add(v, u, max(cmx, pre[u]), delta);
}

void dfs1(int u, int pu, int cmn){
    if ( suf[u] - cmn <= 0 ) ans += d[-suf[u]];
    for (int v : adj[u]) if ( v != pu && !used[v] ){
        suf[v] = suf[u] + a[v];
        dfs1(v, u, min(cmn, suf[u]));
    }
}

void build(int u, int pu){
    int nn = dfs_size(u, pu);
    int c = centroid(u, pu, nn);
    used[c] = 1;
    d.clear();

//    cout << "centroid " << c << " : \n";

    pre[c] = a[c];
    dfs(c, pu, 0);

    ans += d[0];

//    cout << "-> " << ans << '\n' ;

    for (int v : adj[c]) if ( v != pu && !used[v] ){
        add(v, c, max(0, pre[c]), -1);

        suf[v] = a[v];
        dfs1(v, c, 0);

        add(v, c, max(0, pre[c]), 1);
    }

//    cout << "-> " << ans << '\n';

    for (int v : adj[c]) if ( v != pu && !used[v] )
        build(v, c);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("trash.inp", "r") ){
        freopen("trash.inp", "r", stdin);
        freopen("trash.out", "w", stdout);
    }

    cin >> n;
    for (int i = 1; i <= n; i ++){
        char x;
        cin >> x;
        if ( x == '(' ) a[i] = 1;
        else a[i] = -1;
    }

    for (int i = 1, u, v; i < n; i ++){
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    build(1, 0);

    cout << ans;

    return 0;
}
