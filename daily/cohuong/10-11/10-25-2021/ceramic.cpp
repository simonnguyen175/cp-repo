#include<bits/stdc++.h>
#define simon "ceramic"
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
const int N = 1e3 + 5;

int n, m, s, cnt;
int deg[N], vis[N];
vector<int> adj[N];

void dfs(int u){
    vis[u] = 1;
    for (int v : adj[u]){
        if ( vis[v] ) continue;
        dfs(v);
    }
}

int main(){
    FASTio
    if ( fopen(simon".inp", "r") ){
        freopen(simon".inp", "r", stdin);
        freopen(simon".out", "w", stdout);
    }
    while ( cin >> n >> m >> s ){
        if ( !n ) break;

        for (int i = 1; i <= n; i ++) deg[i] = 0, vis[i] = 0, adj[i].clear();

        for (int i = 1; i <= m; i ++){
            int x, y;
            cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
            deg[x] ++; deg[y] ++;
        }

        dfs(s);
        bool flag = 1;
        for (int i = 1; i <= n; i ++)
            if ( !vis[i] && adj[i].size() > 0 ){
                flag = 0; break;
            }

        if ( !flag ) { cout << "NO" << '\n'; continue; }

        int odd = 0;
        for (int i = 1; i <= n; i ++)
            if ( deg[i] % 2 ) odd ++;

        if ( odd == 0 ){
            cout << "YES" << '\n';
            continue;
        }

        cout << "NO" << '\n';
        continue;
    }

    return 0;
}
