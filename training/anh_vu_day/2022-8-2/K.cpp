#include<bits/stdc++.h>
#define pb push_back
#define ll long long
#define pi pair<ll, ll>
#define fi first
#define se second
using namespace std;
const int N = 3e5 + 5;
const ll oo = 1e15;

int n;
vector<pi> adj[N];
ll h[N], d[N], f[N], g[N];
ll ans;
struct options{
    ll st, nd, rd;
};

void dfs(int u, int pu){
    pi mx = {0, 0};
    for (auto it : adj[u]){
        int v = it.fi, w = it.se;
        if ( v == pu ) continue;

        dfs(v, u);

        h[u] = max(h[u], h[v] + w);
        if ( mx.fi < h[v] + w ) mx = {h[v]+w, mx.fi};
        else if ( mx.se < h[v] + w ) mx = {mx.fi, h[v]+w};
        f[u] = max(f[u], f[v]);
    }
    f[u] = max({f[u], h[u], mx.fi + mx.se});
}

void go(int u, int pu){
    options opt = {0, 0, 0};
    for (auto it : adj[u]){
        int v = it.fi, w = it.se;
        if ( v == pu ) continue;
        if ( opt.st < h[v]+w ) opt = {h[v]+w, opt.st, opt.nd};
        else if ( opt.nd < h[v]+w ) opt = {opt.st, h[v]+w, opt.nd};
        else if ( opt.rd < h[v]+w ) opt = {opt.st, opt.nd, h[v]+w};
    }

    for (auto it : adj[u]){
        int v = it.fi, w = it.se;

        if ( v == pu ) continue;

        ll tmp = 0;
        if ( opt.st == h[v]+w ) tmp = opt.nd + w;
        else tmp = opt.st + w;
        d[v] = max(d[u]+w, tmp);

        tmp = opt.st + opt.nd;
        if ( opt.st == h[v]+w ) tmp += -opt.st + opt.rd;
        else if ( opt.nd == h[v]+w ) tmp += -opt.nd + opt.rd;

        g[v] = max({tmp, g[u], d[v]});

        ans = min(ans, abs(max(g[u], tmp)-f[v]));

        go(v, u);
    }
}

void solve(){
    ans = oo;
    for (int i = 1; i <= n; i ++){
        adj[i].clear();
        f[i] = g[i] = d[i] = h[i] = 0;
    }

    for (int i = 2, p, l; i <= n; i ++){
        cin >> p >> l;
        adj[p].pb({i, l});
        adj[i].pb({p, l});
    }

    dfs(1, 0);
    go(1, 0);

    cout << ans << '\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    while ( cin >> n )
        if ( n ) solve();
        else break;

    return 0;
}
