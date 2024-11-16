#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int N = 1e3 + 5;

int x, y, m, t;
vector<int> adj[N];
int vis[N], lef[N];

bool go(int u){
    if ( vis[u] != t ) vis[u] = t;
    else return false;

    for (int v : adj[u]){
        if ( !lef[v] || go(lef[v]) ){
            lef[v] = u;
            return true;
        }
    }

    return false;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> x >> y >> m;
    for (int i = 1, u, v; i <= m; i ++){
        cin >> u >> v;
        adj[u].pb(v);
    }

    int ans = 0;
    for (int i = 1; i <= x; i ++){
        t ++;
        ans += go(i);
    }

    cout << ans;

    return 0;
}
