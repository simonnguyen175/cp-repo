#include<bits/stdc++.h>
#define simon "nttree"
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll unsigned long long
#define pi pair<int, ll>
#define fi first
#define se second
#define pb push_back
using namespace std;
const int N = 1e5 + 5;

int n;
vector<pi> adj[N];
ll cnt[N], ans = 0;

void dfs1(int u, int pu){
    if ( u != 1 && adj[u].size() == 1 ) { cnt[u] = 1; return; }

    for (auto it : adj[u]){
        int v = it.fi;
        if ( v == pu ) continue;
        dfs1(v, u);
        cnt[u] += cnt[v];
    }
    cnt[u] ++;
}

void dfs2(int u, int pu){
    for (auto it : adj[u]){
        int v = it.fi; ll w = it.se;
        if ( v == pu ) continue;
        ans += ( n - cnt[v] ) * cnt[v] * w;
        dfs2(v, u);
    }
}


int main(){
    FASTio
    if ( fopen(simon".inp", "r") ){
        freopen(simon".inp", "r", stdin);
        freopen(simon".out", "w", stdout);
    }

    cin >> n;
    for (int i = 1; i < n; i ++){
        int u, v; ll w;
        cin >> u >> v >> w;
        u ++, v ++;
        adj[u].pb({v, w});
        adj[v].pb({u, w});
    }

    dfs1(1, 0);

    dfs2(1, 0);

    cout << ans;

    return 0;
}
