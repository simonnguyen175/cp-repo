#include<bits/stdc++.h>
#define ll long long
#define pi pair<ll, ll>
#define fi first
#define se second
#define pb push_back
using namespace std;
const int N = 5e5 + 5;

int n[4];
ll n1, n2, n3, ans, res, add;
vector<int> adj[4][N];
int id[4];
ll child[4][N], h[4][N], f[4][N], g[4][N], s[4][N], mx[4], pre[N], suf[N];
pi F[4][N];

void dfs(int t, int u, int pu){
    child[t][u] = 1;
    for (int v : adj[t][u]) if ( v != pu ){
        h[t][v] = h[t][u] + 1;
        dfs(t, v, u);
        f[t][u] += f[t][v] + child[t][v];
        s[t][u] += f[t][v];
        child[t][u] += child[t][v];
    }
}

void go(int t, int u, int pu){
    for (int v : adj[t][u]) if ( v != pu ){
        g[t][v] = g[t][u] + (n[t]-child[t][u]+1);
        g[t][v] += s[t][u] - f[t][v] + (child[t][u]-child[t][v]-1) * 2;
        go(t, v, u);
    }
}

void build(int t){
    dfs(t, 1, 0);
    go(t, 1, 0);

    for (int i = 1; i <= n[t]; i ++){
        f[t][i] += g[t][i];
        mx[t] = max(mx[t], f[t][i]);
    }

//    cout << t << " : " << mx[t] << '\n';
}

void go1(int t, int u, int pu){
    pi tmp = F[t][u];

    for (int v : adj[t][u]) if ( v != pu ){
        go1(t, v, u);
        if ( F[t][u].fi < F[t][v].fi ) F[t][u].fi = F[t][v].fi;
        if ( F[t][u].se < F[t][v].se ) F[t][u].se = F[t][v].se;
    }

    pre[0] = tmp.fi, suf[adj[t][u].size()+1] = tmp.se;
    for (int i = 1, v; i <= adj[t][u].size(); i ++){
        v = adj[t][u][i-1];
        pre[i] = pre[i-1];
        if ( v != pu ) pre[i] = max(pre[i], F[t][v].fi);
    }

//    cerr << u << ":\n";
    for (int i = adj[t][u].size(), v; i >= 1; i --){
        v = adj[t][u][i-1];
//        cerr << pre[i] << ' ' << suf[i+1] << '\n';
        add = max(add, pre[i]+suf[i+1]-2*n1*n3*h[t][u]);
        suf[i] = suf[i+1];
        if ( v != pu ) suf[i] = max(suf[i], F[t][v].se);
    }
    add = max(add, pre[0]+suf[1]-2*n1*n3*h[t][u]);
//    cerr << add << '\n';
}

void solve(){
//    cout << id[1] << ' ' << id[2] << ' ' << id[3] << " : \n";
    n1 = n[id[1]], n2 = n[id[2]], n3 = n[id[3]];
    res = n2 * ( n1 + n3 + mx[id[1]] + mx[id[3]] ) + mx[id[1]]*n3 + mx[id[3]]*n1 + 2*n1*n3;

    for (int i = 1; i <= n2; i ++){
        F[id[2]][i] = {n1*n3*h[id[2]][i] + f[id[2]][i]*n1, n1*n3*h[id[2]][i] + f[id[2]][i]*n3};
//        cout << F[id[2]][i].fi << ' ' << F[id[2]][i].se << '\n';
    }

    add = 0;
    go1(id[2], 1, 0);

    res += add;
//    cout << res << '\n';
    ans = max(ans, res);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n[1] >> n[2] >> n[3];
    for (int t = 1; t <= 3; t ++)
    for (int i = 1, u, v; i < n[t]; i ++){
        cin >> u >> v;
        adj[t][u].pb(v), adj[t][v].pb(u);
    }

//    cout << "----------\n";

    for (int t = 1; t <= 3; t ++)
        build(t);

//    cout << "----------\n";

    for (int i = 1; i <= 3; i ++) id[i] = i;
    do{
        solve();
    }
    while ( next_permutation(id+1, id+4) );

    for (int t = 1; t <= 3; t ++){
        ll tmp = 0;
        for (int i = 1; i <= n[t]; i ++) tmp += f[t][i];
        ans += tmp/2;
    }
    cout << ans;

    return 0;
}
