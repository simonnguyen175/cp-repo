#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int N = 1e3 + 5;

int n, m, s, t, maxflow;
vector<int> adj[N], ans[N];
int c[N][N], f[N][N], trace[N];
queue<int> q;

void incFlow(){
    int delta = N;
    int v = t, u;
    while ( v != s ){
        u = trace[v];
        delta = min(delta, c[u][v] - f[u][v]);
        v = u;
    }
    v = t;
    while ( v != s ){
        u = trace[v];
        f[u][v] += delta, f[v][u] -= delta;
        v = u;
    }
    maxflow += delta;
}

bool findPath(){
    for (int i = 0; i <= n+m+1; i ++) trace[i] = -1;
    trace[s] = n+m+2; q.push(s);
    while ( q.size() ){
        int u = q.front(); q.pop();
        for (int v : adj[u])
            if ( trace[v] == -1 && f[u][v] < c[u][v] )
                trace[v] = u, q.push(v);
    }
    return ( trace[t] != -1 );
}

bool check(int mid){
    for (int i = 1; i <= n; i ++) c[0][i] = mid;
    memset(f, 0, sizeof f);

    maxflow = 0;
    while ( findPath() )
        incFlow();

    if ( maxflow == m ){
        for (int i = 1; i <= n; i ++) ans[i].clear();
//        for (int i = 1; i <= m; i ++)
//            ans[trace[n+i]].pb(i);
        for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= m; j ++)
            if ( f[i][n+j] )
                ans[i].pb(j);

        return true;
    }
    else return false;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> m >> n;
    for (int i = 1, x; i <= n; i ++)
        while ( cin >> x ){
            if ( !x ) break;
            adj[i].pb(n+x); c[i][n+x] = 1;
            adj[n+x].pb(i);
        }

    s = 0, t = n + m + 1;
    for (int i = 1; i <= m; i ++)
        adj[n+i].pb(t), c[n+i][t] = 1;
    for (int i = 1; i <= n; i ++)
        adj[s].pb(i);

    int lo = 1, hi = m, res = -1;
    while ( lo <= hi ){
        int mid = lo + hi >> 1;
        if ( check(mid) ) res = mid, hi = mid - 1;
        else lo = mid + 1;
    }

    if ( res != -1 ){
        cout << "YES\n";
        cout << res << '\n';
        for (int i = 1; i <= n; i ++){
            for (auto x : ans[i]) cout << x << ' ';
            cout << "0\n";
        }
    }
    else cout << "NO\n";

    return 0;
}
