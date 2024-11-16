#include<bits/stdc++.h>
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define simon "Ance2T"
using namespace std;
const int N = 2e5 + 5;

int n, q, p[N][20], d[N];
vector<int> adj[N];

void dfs(int u, int pu){
    for (auto v : adj[u]){
        if ( v == pu ) continue;
        d[v] = d[u] + 1;
        p[v][0] = u;
        int e;
        for (int t=1; t<20; t++){
            if ( (1<<t) > d[v] ) break;
            else e = p[v][t-1];
            p[v][t] = p[e][t-1];
        }
        dfs(v, u);
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
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, 0);

    cin >> q;
    for (int i=1; i<=q; i++){
        int t, u;
        cin >> t >> u;
        if ( p[u][t] == 0 ) cout << -1 << '\n';
        else cout << p[u][t] << '\n';
    }

    return 0;
}
