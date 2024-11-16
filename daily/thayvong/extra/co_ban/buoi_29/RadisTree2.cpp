#include<bits/stdc++.h>
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define simon "RadisTree2"
#define ll long long
using namespace std;
const int N = 1e5+5;

int n;
vector<pair<int, ll>> adj[N];
ll f[N];
bool vis[N];

void DFS(int u){
    vis[u] = 1;
    for (auto v : adj[u]){
        if ( vis[v.first] ) continue;
        f[v.first] = f[u] + v.second;
        DFS(v.first);
    }
}


int main(){
    FASTio
    if ( fopen(simon".inp","r") ){
        freopen(simon".inp","r",stdin);
        freopen(simon".out","w",stdout);
    }
    cin >> n;
    for (int i=1; i<=n-1; i++){
        int u, v, w;
        cin >> u >> v >> w;
        adj[v].push_back({u, w});
        adj[u].push_back({v, w});
    }

    memset(vis, 0, sizeof vis);
    DFS(1);

    int u = 1;
    for (int i=1; i<=n; i++)
        if ( f[u] < f[i] ) u = i;

    memset(f, 0, sizeof f);
    memset(vis, 0, sizeof vis);

    DFS(u);
    ll ans = f[1];

    for (int i=1; i<=n; i++)
        ans = max(ans, f[i]);

    cout << ans;
    return 0;
}
