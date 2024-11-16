#include<bits/stdc++.h>
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define simon "SumDisTree"
#define ll long long
using namespace std;
const int N = 2e3+5;

int n;
vector<int> adj[N];
bool vis[N];
ll d[N], ans=0;

void DFS(int u){
    vis[u] = 1;
    for (auto v : adj[u] ){
        if ( vis[v] ) continue;
        d[v] = d[u] + 1;
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
        adj[u].push_back(v);
        adj[v].push_back(u);
    }


    for (int i=1; i<=n; i++){
        memset(vis, 0, sizeof vis);
        memset(d, 0, sizeof d);
        DFS(i);
        for (int j=i+1; j<=n; j++){
            ans += d[j];
        }
    }

    cout << ans;
    return 0;
}
