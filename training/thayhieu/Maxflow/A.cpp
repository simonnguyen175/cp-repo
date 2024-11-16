#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
const int oo = 1e9 + 5;

int n, m, s, t;
int f[N][N], c[N][N], trace[N];
int maxflow;

bool findPath(){
    for (int i = 1; i <= n; i ++) trace[i] = 0;
    trace[s] = n+1;
    queue<int> q; q.push(s);
    while ( q.size() ){
        int u = q.front(); q.pop();
        for (int v = 1; v <= n; v ++)
            if ( !trace[v] && c[u][v] > f[u][v] ){
                trace[v] = u, q.push(v);
            }
    }

    return trace[t];
}

void incFlow(){
    int delta = oo;
    int v = t, u;
    while ( v != s ){
        u = trace[v];
        delta = min(delta, c[u][v] - f[u][v]);
        v = u;
    }
    v = t;
    while ( v != s ){
        u = trace[v];
        f[u][v] += delta;
        f[v][u] -= delta;
        v = u;
    }
    maxflow += delta;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n >> m >> s >> t;

    for (int i = 1, u, v; i <= m; i ++)
        cin >> u >> v >> c[u][v];

    while ( findPath() )
        incFlow();

    cout << maxflow;

    return 0;
}
