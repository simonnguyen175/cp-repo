#include<bits/stdc++.h>
#define simon "game"
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
const int N = 5e2 + 5;

int k, n, m;
pair<int, int> edges[N*N];
int Par[N], Rank[N], ans[N*N];

int Find(int u){
    if ( u == Par[u] ) return u;
    else return Par[u] = Find(Par[u]);
}

bool Join(int u, int v){
    u = Find(u); v = Find(v);
    if ( u != v ){
        if ( Rank[u] < Rank[v] ) swap(u, v);
        Par[v] = u;
        if ( Rank[u] == Rank[v] ) Rank[u] ++;
        return true;
    }
    return false;
}

void solve(){
    cin >> n;
    m = n*(n-1)/2;
    for (int i = 1; i <= m; i ++){
        int u, v;
        cin >> u >> v;
        edges[i] = {u, v};
    }

    for (int i = 1; i <= m; i ++) ans[i] = 0;

    for (int i = 1; i <= n; i ++) Par[i] = i, Rank[i] = 0;

    for (int i = m; i >= 1; i --){
        int u = edges[i].first, v = edges[i].second;
        if ( Join(u, v) ) ans[i] = 1;
    }

    for (int i = 1; i <= m; i ++) cout << ans[i] << ' ';
    cout << '\n';
}

int main(){
    FASTio
    if ( fopen(simon".inp", "r") ){
        freopen(simon".inp", "r", stdin);
        freopen(simon".out", "w", stdout);
    }

    cin >> k;
    while ( k -- )
        solve();
    return 0;
}
