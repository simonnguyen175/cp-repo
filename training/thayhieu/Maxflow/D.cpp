#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int N = 1e3 + 5;
const int oo = 1e9;

int n, m, a, b;
int C[N], f[N][N], c[N][N], trace[N], vis[N];
vector<int> ans, adj[N];
queue<int> q;

void add(int u, int v, int w){
    c[u][v] = w, c[v][u] = 0;
    adj[u].pb(v), adj[v].pb(u);
}

void incFlow(){
    int delta = oo;
    int v = b+n, u;
    while ( v != a ){
        u = trace[v];
        delta = min(delta, c[u][v] - f[u][v]);
        v = u;
    }
    v = b+n;
    while ( v != a ){
        u = trace[v];
        f[u][v] += delta, f[v][u] -= delta;
        v = u;
    }
}

bool findPath(){
    for (int i = 1; i <= 2*n; i ++) trace[i] = 0;

    trace[a] = 2*n + 1;
    q.push(a);

    while ( q.size() ){
        int u = q.front();
        q.pop();
        for (int v : adj[u])
            if ( !trace[v] && f[u][v] < c[u][v] )
                    trace[v] = u, q.push(v);
    }

    return trace[b+n];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n >> m >> a >> b;
    for (int i = 1; i <= n; i ++)
        cin >> C[i], add(i, i+n, C[i]);

    for (int i = 1, u, v; i <= m; i ++){
        cin >> u >> v;
        add(u+n, v, oo);
        add(v+n, u, oo);
    }

    while ( findPath() )
        incFlow();

    vector<int> ans;
    q.push(a);
    while ( q.size() ){
        int u = q.front();
        vis[u] = 1;
        q.pop();
        bool ck = 0;
        for (int v : adj[u])
            if ( f[u][v] < c[u][v] && !vis[v] )
                 q.push(v);
    }

    for (int i = 1; i <= n; i ++)
        if ( vis[i] && !vis[i+n] )
            ans.pb(i);

    cout << ans.size() << '\n';
    for (auto x : ans) cout << x << ' ';


    return 0;
}
