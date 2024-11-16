#include<bits/stdc++.h>
#define pi pair<int, int>
#define fi first
#define se second
#define pb push_back
using namespace std;
const int N = 1e5 + 5;
const int oo = 1e9;

int n, k;
vector<pi> adj[N];
int h[N], p[N][21], mxe[N][21], mne[N][21];

void dfs(int u, int pu){
    for (auto it : adj[u]){
        int v = it.fi;
        if ( v == pu ) continue;
        p[v][0] = u;
        mxe[v][0] = it.se;
        mne[v][0] = it.se;
        h[v] = h[u] + 1;
        dfs(v, u);
    }
}

pi get(int u, int v){
    if ( h[u] < h[v] ) swap(u, v);
    pi res; res.fi = oo; res.se = -oo;

    for (int i = 20; i >= 0; i --)
        if ( h[p[u][i]] >= h[v] ){
            res.fi = min(res.fi, mne[u][i]);
            res.se = max(res.se, mxe[u][i]);
            u = p[u][i];
        }

    if ( u == v ) return res;

    for (int i = 20; i >= 0; i --)
        if ( p[u][i] != p[v][i] ){
            res.fi = min({res.fi, mne[u][i], mne[v][i]});
            res.se = max({res.se, mxe[u][i], mxe[v][i]});
            u = p[u][i]; v = p[v][i];
        }

    res.fi = min({res.fi, mne[u][0], mne[v][0]});
    res.se = max({res.se, mxe[u][0], mxe[v][0]});

    return res;
}

int main(){
    cin >> n;
    for (int i = 1; i < n; i ++){
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].pb({v, w});
        adj[v].pb({u, w});
    }

    h[1] = 1;
    dfs(1, 0);
    for (int i = 1; i <= 20; i ++)
    for (int u = 1; u <= n; u ++){
        p[u][i] = p[p[u][i-1]][i-1];
        mxe[u][i] = max(mxe[u][i-1], mxe[p[u][i-1]][i-1]);
        mne[u][i] = min(mne[u][i-1], mne[p[u][i-1]][i-1]);
    }

    cin >> k;
    while ( k -- ){
        int u, v;
        cin >> u >> v;
        pi res = get(u, v);
        cout << res.fi << ' ' << res.se << '\n';
    }

    return 0;
}
