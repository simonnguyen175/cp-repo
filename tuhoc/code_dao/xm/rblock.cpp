#include<bits/stdc++.h>
using namespace std;
const int N = 1e2 + 5;

int n, m;
long long d[N][N], dd[N][N];
struct edge{
    int u, v, w;
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n >> m;
    vector<edge> e;
    for (int i = 1; i <= n; i ++)
    for (int j = 1; j <= n; j ++)
        d[i][j] = (long long)1e15;
    for (int i = 1; i <= m; i ++){
        int u, v, w;
        cin >> u >> v >> w;
        d[u][v] = d[v][u] = w;
        c[u][v] = c[v][u] = 1;
        e.push_back({u, v, w});
        e.push_back({v, u, w});
    }

    for (int k = 1; k <= n; k ++)
    for (int i = 1; i <= n; i ++)
    for (int j = 1; j <= n; j ++)
        if ( d[i][j] > d[i][k] + d[k][j] ){
            if ( dd[i][j] > d[i][j] )
            d[i][j] = d[i][k] + d[k][j];
        }
        else if ( dd[i][j] > d[i][k] + d[k][j] ){
            dd[i][j] = d[i][k] + d[k][j];
            if ( d[])
        }


    long long ans = d[1][n];
    for (auto it : e){
        d[it.u
        for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= n; j ++)
            dd[i][j] = d[i][j];

        for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= n; j ++)
            if ( d[i][j] > d[i][it.u] + d[])
    }

    cout << ans - d[1][n];

    return 0;
}
