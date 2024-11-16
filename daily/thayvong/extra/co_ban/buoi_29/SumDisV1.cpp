#include<bits/stdc++.h>
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define simon "SumDisV1"
#define ll long long
using namespace std;
const int N = 1e5+5;

int n;
vector<int> adj[N];
int f[N];
bool vis[N];

void DFS(int u){
    vis[u] = 1;
    for (auto v : adj[u]){
        if ( vis[v] ) continue;
        f[v] = f[u] + 1;
        DFS(v);
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
        int u, v;
        cin >> u >> v;
        adj[v].push_back(u);
        adj[u].push_back(v);
    }

    memset(vis, 0, sizeof vis);
    memset(f, 0, sizeof f);

    DFS(1);

    ll ans = 0;
    for (int i=2; i<=n; i++)
        ans += f[i];

    cout << ans;
    return 0;
}
