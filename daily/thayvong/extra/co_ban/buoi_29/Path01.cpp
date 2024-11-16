#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5 + 5;

int n;
vector<int> adj[N];
bool vis[N];
ll x[N], y[N], xy[N], yx[N];

void DFS(int u){
    vis[u] = 1;
    for (int v : adj[u])
        if ( vis[v.first] ) continue;
        DFS(v);

        if ( v.second ==
    }
}

int main(){
    cin >> n;
    for (int i=1; i<=n; i++){
        int u, v, c;
        cin >> u >> v >> c;
        adj[u].push_back({v, c});
        adj[v].push_back({u, c});
    }
    DFS(1);
    cout << ans;
    return 0;
}
