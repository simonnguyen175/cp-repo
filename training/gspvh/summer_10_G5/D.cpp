#include<bits/stdc++.h>
#define pb push_back
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n >> m;
    for (int i = 1, u, v; i <= m; i ++){
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }

    cin >> k;
    for (int i = 1; i <= k; i ++)
        cin >> a[i].u >> a[i].c >> a[i].p;



    cin >> q;
    while ( q -- ){
        cin >> v >> t >> b;
        int lo = 0, hi = m;
        while ( lo <= hi ){
            int mid = lo + hi >> 1;
        }
    }
}
