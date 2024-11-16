#include<bits/stdc++.h>
#define pb push_back
#define pi pair<int, int>
#define fi first
#define se second
using namespace std;

int n;
map<int, map<int, int>> d;
vector<pi> g[111];
vector<int> ans;

void dfs(int u, int pu, int dis, int root){
    d[dis][root] = u;
    for (auto it : g[u]){
        int v = it.fi, w = it.se;
        if ( v == pu ) continue;
        dfs(v, u, dis+w, root);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    freopen("egalitarianism3.inp", "r", stdin);
    freopen("egalitarianism3.out", "w", stdout);

    cin >> n;
    for (int i = 1, u, v, c; i < n; i ++){
        cin >> u >> v >> c;
        g[u].pb({v, c});
        g[v].pb({u, c});
    }

    if ( n == 1 ) { cout << 1 << '\n' << 1; return 0; }

    if ( n == 2 ) { cout << 2 << '\n' << 1 << ' ' << 2; return 0; }

    ans.pb(1), ans.pb(2);

    for (int i = 1; i <= n; i ++){
        d.clear();
        for (auto it : g[i]) dfs(it.fi, i, it.se, it.fi);
        for (auto it : d) if ( it.se.size() > ans.size() ){
            ans.clear();
            for (auto jt : it.se) ans.pb(jt.se);
        }
    }

    cout << ans.size() << '\n';
    for (int u : ans) cout << u << ' ';

    return 0;
}
