#include<bits/stdc++.h>
using namespace std;
const int N = 1e3;
const int oo = 1e9;

int n, m;
int d[N][N], sta[N][N], ans[N*N];
struct edg{
    int u, v, w;
} edges[N*N];

void solve(){
    cin >> n >> m;

    for (int u = 1; u <= n; u ++)
    for (int v = 1; v <= n; v ++)
        if ( u == v ) d[u][v] = sta[u][v] = 0;
        else d[u][v] =  oo, sta[u][v] = 0;

    for (int i = 1; i <= m; i ++){
        int u, v, w;
        cin >> u >> v >> w;
        u ++, v ++;
        d[u][v] = d[v][u] = w;
        sta[u][v] = sta[v][u] = i;
        edges[i] = {u, v, w};
    }

    for (int k = 1; k <= n; k ++)
    for (int u = 1; u <= n; u ++)
    for (int v = 1; v <= n; v ++) if ( d[u][v] > d[u][k] + d[k][v] ){
        d[u][v] = d[u][k] + d[k][v];
        sta[u][v] = sta[u][k];
        sta[v][u] = sta[v][k];
    }

    for (int i = 1; i <= m; i ++)
        ans[i] = oo;

    for (int x = 1; x <= n; x ++)
    for (int i = 1; i <= m; i ++){
        int u, v, w;
        u = edges[i].u, v = edges[i].v, w = edges[i].w;
        if ( u == x ){
            if ( sta[x][v] != i )
                ans[i] = min(ans[i], d[x][v] + w);
        }
        else if ( v == x ){
            if ( sta[x][u] != i )
                ans[i] = min(ans[i], d[x][u] + w);
        }
        else if ( sta[x][u] != sta[x][v] ){
            ans[sta[x][u]] = min(ans[sta[x][u]], d[x][u] + d[x][v] + w);
            ans[sta[x][v]] = min(ans[sta[x][v]], d[x][u] + d[x][v] + w);
        }
    }

    for (int i = 1; i <= m; i ++)
        if ( ans[i] != oo ) cout << ans[i] - edges[i].w + 1 << '\n';
        else cout << "impossible\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int t;
    cin >> t;
    for (int i = 1; i <= t; i ++){
        cout << "Case " << i << ": \n";
        solve();
    }

    return 0;
}
