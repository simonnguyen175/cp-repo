#include<bits/stdc++.h>
#define pi pair<int, int>
#define fi first
#define se second
#define pb push_back
using namespace std;

int n, m, t = 0;
vector<pi> adj[500];
bool used[500];
vector<int> circuit;

void dfs(int u){
    t ++;
    //cout << "-> " << t << ' ' << u << ' ' << adj[u].size() << '\n';
    while ( adj[u].size() ){
        pi it = adj[u].back();
        adj[u].pop_back();
        if ( !used[it.se] ){
            used[it.se] = 1;
            //cout << "==> " << it.fi << '\n';
            dfs(it.fi);
        }
    }
    //cout << "-> " << t << ' ' << u << ' ' << adj[u].size() << '\n';
    circuit.pb(u);
}

int main(){
    cin >> n >> m;
    for (int i = 1; i <= m; i ++){
        int u, v; cin >> u >> v;
        adj[u].pb({v, i});
        //adj[v].pb({u, i});
    }

    dfs(1);

    for (int u : circuit) cout << u << ' ';
}
