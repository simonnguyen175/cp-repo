#include <bits/stdc++.h>
#define simon "paint"
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
#define fi first
#define se second
#define ii pair<int, int>
using namespace std;
const int N=1e5+1;
const int oo=1e18;

int n;
bool color[N];
vector<int> adj[N], adjComp[N];
int par[N], tag[N], f[N], g[N], diameter;

void DFStoComp(int u){
    for (int i=0; i<adj[u].size(); i++){
        int v=adj[u][i];
        if ( par[u] == v ) continue;
        par[v]=u;
        if ( color[v] == color[u] ){
            tag[v]=tag[u];
            DFStoComp(v);
        }
        else{
            //cout << tag[u] <<' '<<tag[v]<<'\n';
            adjComp[tag[u]].push_back(tag[v]);
            adjComp[tag[v]].push_back(tag[u]);
            DFStoComp(v);
        }
    }
}

void DFStoSolve(int V, int pV){
    vector<int> fValues;

    for (auto v: adjComp[V]){
        if ( v == pV) continue;
        DFStoSolve(v, V);
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
    for (int i=1; i<=n; i++){
        cin >> color[i];
        tag[i]=i;
    }
    for (int i=1; i<n; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    DFStoComp(1);

    /*
    for (int i=1; i<=n; i++)
        cout << tag[i] <<' ';
    cout <<'\n';
    for (int i=1; i<=n; i++)
        cout << adjComp[i].size() <<' ';
    cout <<'\n';
    */

    DFStoSolve(1, 0);
    cout << diameter/2;
    return 0;
}
