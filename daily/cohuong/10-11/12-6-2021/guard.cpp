#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
const int N = 1e5 + 5;
const ll oo = 1e9;

int n;
ll f[N][3];
vector<int> adj[N];

void dfs(int u, int pu){
    bool ck = 0;
    ll mn = oo;

    // f[u][0] u co sung
    // f[u][1] u ko co sung, con u co sung
    // f[u][2] u ko co sung, cha u co sung

    if ( adj[u].size() == 1 && u != 1 ){
        f[u][0] = 1;
        f[u][1] = oo;
        f[u][2] = 0;
        return;
    }

    for (int v : adj[u]){
        if ( v == pu ) continue;
        dfs(v, u);
        mn = min(mn, f[v][0] - f[v][1]);
        if ( f[v][0] <= f[v][1] ) ck = 1;
        f[u][2] += f[v][1];
        f[u][1] += min(f[v][0], f[v][1]);
        f[u][0] += min({f[v][2], f[v][1], f[v][0]});
    }

    f[u][0] ++;
    if ( !ck ) f[u][1] += mn;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    freopen("guard.inp", "r", stdin);
    freopen("guard.out", "w", stdout);

    cin >> n;
    for (int i = 1; i < n; i ++){
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    dfs(1, 0);

    cout << min(f[1][0], f[1][1]);

    return 0;
}
