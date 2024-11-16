#include<bits/stdc++.h>
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define simon "treeance"
using namespace std;
const int N = 2e5 + 5;

int n, q, p[N][20], d[N];
vector<int> adj[N];

int mu(int x){
    int res = 1;
    for (int i=1; i<=x; i++)
        res *= 2;
    return res;
}

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

int getAnc(int k, int u){
    if ( d[u] < k ) return -1;
    else{
        int res = u;
        while ( k > 0 ){
            int t = log2(k);
            res = p[res][t];
            k -= mu(t);
        }
        return res;
    }
}


int main(){
    FASTio
    if ( fopen(simon".inp","r") ){
        freopen(simon".inp","r",stdin);
        freopen(simon".out","w",stdout);
    }
    cin >> n >> q;

    for (int i=1; i<=n-1; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, 0);

    for (int i=1; i<=q; i++){
        int u, v;
        cin >> u >> v;
        if ( u > v ) swap(u, v);
        int k = d[v] - d[u];
        if ( getAnc(k, v) == u ) cout << 1 << '\n';
        else cout << 0 << '\n';
    }

    return 0;
}
