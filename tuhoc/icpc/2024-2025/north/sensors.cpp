#include<bits/stdc++.h>
#define pb push_back
#define pi pair<int, int>
#define x first
#define y second
using namespace std;
const int N = 1e3 + 5;
const int oo = 1e9;

int L, W, n, m, s, t, maxflow;
pi a[N];
vector<int> adj[N];
int c[N][N], f[N][N], trace[N];
queue<int> q;

int sqr(int x) { return x*x; }

void add(int u, int v, int w){
    c[u][v] = w;
    c[v][u] = 0;
    adj[u].pb(v);
    adj[v].pb(u);
}

bool findPath(){
    for (int i = 1; i <= 2*n+2; i ++) trace[i] = 0;
    trace[s] = 2*n+3;
    q.push(s);
    while ( q.size() ){
        int u = q.front(); q.pop();
        for (int v : adj[u])
            if ( !trace[v] && c[u][v] > f[u][v] )
                trace[v] = u, q.push(v);
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
        f[u][v] += delta, f[v][u] -= delta;
        v = u;
    }
    maxflow += delta;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> L >> W >> n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i].x >> a[i].y;

    for (int i = 1; i <= n; i ++)
    for (int j = i; j <= n; j ++)
        if ( i != j && sqr(a[i].x-a[j].x)+sqr(a[i].y-a[j].y) <= 40000 )
            add(i+n, j, oo), add(j+n, i, oo);
        else if ( i == j )
            add(i, i+n, 1);

    s = 2*n+1, t = 2*n+2;
    for (int i = 1; i <= n; i ++){
        if ( a[i].y - 100 <= 0 ) add(s, i, oo);
        if ( a[i].y + 100 >= W ) add(i+n, t, oo);
    }

    while ( findPath() )
        incFlow();

    cout << maxflow;

    return 0;
}
