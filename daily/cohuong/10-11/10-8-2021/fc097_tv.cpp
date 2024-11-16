#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;

int n, m, p;
int nxt[N], vis[N];

int main(){
    cin >> n >> m >> p;
    for (int i = 1; i <= n; i ++){
        int u, v;
        cin >> u >> v;
       if ( !nxt[v] ) nxt[v] = u;
    }

    int tmp = p, ans = 0;
    vis[p] = 1;
    while ( nxt[p] ){
        p = nxt[p]; ans ++;
        if ( vis[p] ){cout << -1; return 0;}
        vis[p] = 1;
    }

    if ( p == tmp ) cout << -1;
    else cout << ans;

    return 0;
}
