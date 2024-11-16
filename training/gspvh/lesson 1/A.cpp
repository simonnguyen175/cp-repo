#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;

int sub, m, n;
struct edge{
    int u, v, w, id;
    bool operator < (const edge &a) const{
        return w < a.w;
    }
} edges[N];
int Par[N], Rank[N];

int Find(int u){
    if ( u == Par[u] ) return u;
    else return Par[u] = Find(Par[u]);
}

bool Join(int u, int v){
    u = Find(u); v = Find(v);
    if ( u != v ){
        if ( Rank[u] <  Rank[v] ) swap(u, v);
        Par[v] = u;
        if ( Rank[u] == Rank[v] ) Rank[u] ++;
        return true;
    }
    else return false;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("mst.inp", "r") ){
        freopen("mst.inp", "r", stdin);
        freopen("mst.out", "w", stdout);
    }

    cin >> sub >> n >> m;
    for (int i = 1; i <= m; i ++){
        int u, v, w;
        cin >> u >> v >> w;
        edges[i] = {u, v, w, i};
    }

    sort(edges + 1, edges + 1 + m);

    for (int i = 1; i <= n; i ++) Par[i] = i, Rank[i] = 1;

    for (int i = 1; i <= m; i ++)
        if ( Join(edges[i].u, edges[i].v) )
            cout << edges[i].id << ' ';

    return 0;
}
