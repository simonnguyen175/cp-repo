#include<bits/stdc++.h>
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define simon "RadisTree1"
using namespace std;
const int N = 1e5+5;

int n;
vector<int> adj[N];
int f[N], g[N], diameter;

void DFS(int V, int pV){
    vector<int> fValues;

    for (auto v: adj[V]){
        if ( v == pV ) continue;
        DFS(v, V);
        fValues.push_back(f[v]);
    }

    sort(fValues.begin(), fValues.end());

    f[V]=1;
    if ( !fValues.empty() ) f[V]+=fValues.back();
    if ( fValues.size() >= 2 )
        g[V] = 1 + fValues.back() + fValues[fValues.size()-2];
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
        int u, v;
        cin >> u >> v;
        adj[v].push_back(u);
        adj[u].push_back(v);
    }
    DFS(1, 0);
    cout << diameter - 1;
    return 0;
}
