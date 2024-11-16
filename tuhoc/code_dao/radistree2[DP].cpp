#include<bits/stdc++.h>
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define simon "RadisTree1"
using namespace std;
const int N = 1e5+5;

int n;
vector<pair<int, int>> adj[N];
int f[N], g[N], diameter;

void DFS(int V, int pV){
    vector<int> fValues;

    for (auto v: adj[V]){
        if ( v.first == pV ) continue;
        DFS(v.first, V);
        fValues.push_back(f[v.first]+v.second);
    }

    sort(fValues.begin(), fValues.end());

    f[V]=0;

    if ( !fValues.empty() ) f[V] += fValues.back();
    if ( fValues.size() >= 2 )
        g[V] = fValues.back() + fValues[fValues.size()-2];
    diameter = max(diameter, max(f[V], g[V]) );
}


int main(){
    FASTio
    if ( fopen(simon".inp","r") ){
        freopen(simon".inp","r",stdin);
        freopen(simon".out","w",stdout);
    }
    cin >> n;
    for (int i=1; i<=n-1; i++){
        int u, v, w;
        cin >> u >> v >> w;
        adj[v].push_back({u, w});
        adj[u].push_back({v, w});
    }
    DFS(1, 0);
    cout << diameter;
    return 0;
}
