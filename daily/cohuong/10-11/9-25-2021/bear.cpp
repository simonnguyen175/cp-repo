#include<bits/stdc++.h>
#define simon "bear"
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
const int M = 1e5 + 5;
const int N = 1e4 + 5;

struct edge{
    int u, v, w;
    bool operator < (const edge& a) const{
        return w < a.w;
    }
} edges[M];
int n, m;
int s[N], Par[N], Rank[N];

int Find(int u){
    if ( u == Par[u] ) return u;
    else return Par[u] = Find(Par[u]);
}

bool Join(int u, int v){
    u = Find(u); v = Find(v);
    if ( u != v ){
        if ( Rank[v] > Rank[u] ) swap(u, v);
        Par[v] = u;
        if ( Rank[u] == Rank[v] ) Rank[u] ++;
        return true;
    }
    else return false;
}

int main(){
    FASTio
    if ( fopen(simon".inp", "r") ){
        freopen(simon".inp", "r", stdin);
        freopen(simon".out", "w", stdout);
    }

    cin >> n >> m;
    for (int i = 1; i <= n; i ++)
        cin >> s[i];
    for (int i = 1; i <= m; i ++){
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
        edges[i].w = 2*edges[i].w + s[edges[i].u] + s[edges[i].v];
    }

    sort(edges + 1, edges + 1 + m);
    for (int i = 1; i <= n; i ++) Rank[i] = 0, Par[i] = i;

    long long ans = 0;
    for (int i = 1; i <= m; i ++){
        int u = edges[i].u, v = edges[i].v, w = edges[i].w;
        if ( Join(u, v) ) ans += w;
    }

    cout << ans + s[1];

    return 0;
}
