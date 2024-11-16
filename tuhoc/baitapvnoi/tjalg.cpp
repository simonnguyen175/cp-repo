#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int N = 1e5 + 5;

int n, m, timeDfs = 0, scc = 0;
vector<int> adj[N];
int num[N], low[N], del[N];
stack<int> stk;

void dfs(int u){
    num[u] = low[u] = ++timeDfs;
    stk.push(u);

    for (int v : adj[u]){
        if ( del[v] ) continue;
        if ( !num[v] ){
            dfs(v);
            low[u] = min(low[u], low[v]);
        }
        else low[u] = min(low[u], num[v]);
    }

    if ( num[u] == low[u] ){
        scc ++;
        int v;
        do{
            v = stk.top();
            del[v] = 1 ;
            stk.pop();
        } while ( v != u );
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n >> m;
    for (int i = 1, u, v; i <= m; i ++){
        cin >> u >> v;
        adj[u].pb(v);
    }

    for (int i = 1; i <= n; i ++) if ( !num[i] )
        dfs(i);

    cout << scc;

    return 0;
}
