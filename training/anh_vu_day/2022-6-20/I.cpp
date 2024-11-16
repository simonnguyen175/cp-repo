#include<bits/stdc++.h>
#define BIT(x,k) ((x>>k)&1)
using namespace std;
const int N = 2e5 + 5;

int n, q;
int vis[N], len[N], p[N][21];

void dfs(int u){
    if ( vis[u] ) return;
    vis[u] = 1;
    dfs(p[u][0]);
    len[u] = len[p[u][0]] + 1;
}

int bin(int u, int k){
    for (int i = 0; i <= 20; i ++)
        if ( BIT(k, i) )
            u = p[u][i];
    return u;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n >> q;
    for (int i = 1; i <= n; i ++)
        cin >> p[i][0];

    for (int j = 1; j <= 20; j ++)
    for (int i = 1; i <= n; i ++)
        p[i][j] = p[p[i][j-1]][j-1];

    for (int i = 1; i <= n; i ++)
        if ( !vis[i] ) dfs(i);


    while ( q -- ){
        int u, v;
        cin >> u >> v;
        int nu = bin(u, len[u]);
        if ( bin(u, len[u]-len[v]) == v ) cout << len[u]-len[v] << '\n';
        else if ( bin(nu, len[nu]-len[v]) == v ) cout << len[u]+len[nu]-len[v] << '\n';
        else cout << -1 << '\n';
    }

    return 0;
}
