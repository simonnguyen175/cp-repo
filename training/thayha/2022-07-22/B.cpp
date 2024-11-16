#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n >> m;
    for (int i = 1, u, v; i <= m; i ++){
        cin >> u >> v;
        adj[u].pb(v);
    }

    for (int i = 1; i <= n; i ++) Rank[i] = 0, Par[i] = i;

    for (int i = 1; i <= n; i ++) if ( adj[i].size() ){
        q.push(i);
        while ( q.size() ){
            int u = q.front();
            q.pop();
            if ( adj[u].size() <= 1 ) continue;

        }
    }
}
