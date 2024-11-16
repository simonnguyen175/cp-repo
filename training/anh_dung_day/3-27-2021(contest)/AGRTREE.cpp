#include <bits/stdc++.h>
using namespace std;
const int N=1e5+1;

int n, m, a[N], parent[N], dp[N];
vector<int> adj[N];
bool b[N][N];
char ans[N];

void checkleaf(int u){
    if ( u.size() == 1 && u != 1 ) return true;
    else return false;
}

void DFS(int u){
    if ( checkleaf(u) ){
        b[u][a[u]]=1;

    }
    for (int i=0; i<adj[u].size(); i++){
        int v=adj[u][i];
        if ( v == parent[u] ) continue;
        parent[v]=u;
        DFS(v);
        b[u]=b[v];
        b[u].insert(a[u]);
    }
}

int main(){
    ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    cin >> n >> m;
    for (int i=1; i<=n; i++)
        cin >> a[i];
    for (int i=1; i<=n-1; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    memset(b, 0, sizeof b);
    DFS(1);
    //for (int i=1; i<=n; i++) cout << b[i].size() <<' '; cout <<'\n';
    for (int i=1; i<=n; i++)
        if ( b[i].size() == m ) ans[i]='1';
        else ans[i]='0';
    for (int i=1; i<=n; i++)
        cout << ans[i];
    return 0;
}
