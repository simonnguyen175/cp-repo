#include<bits/stdc++.h>
#define pi pair<int, int>
#define fi first
#define se second
#define pb push_back
using namespace std;
const int N = 1e5 + 5;
const int MOD = 1e9 + 7;

int n, m;
vector<int> g[N];
vector<pi> adj[N];
int d[N], f[N], pw[N];

int add(int a, int b){
    a += b;
    if ( a >= MOD ) a -= MOD;
    return a;
}

int mul(int a, int b){
    return 1LL * a * b % MOD;
}

void bfs(){
    queue<int> q;
    d[1] = 0, q.push(1);
    while ( q.size() ){
        int u = q.front();
        q.pop();
        for (int v : g[u]) if ( d[v] == -1 ){
            d[v] = d[u] + 1;
            q.push(v);
        }
    }
}

int pw10(int x){
    int res = 1;
    while ( x ) res = mul(res, 10), x /= 10;
    return res;
}

void go(int u){
//    cout << u << " :\n";
    for (auto it : adj[u]){
        int v = it.se, w = it.fi;
        if ( d[u] + 1 == d[v] && f[v] == -1 ){
            f[v] = add(mul(f[u], pw10(w)), w);
//            cout << u << " -> " << v << '\n';
            go(v);
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("trash.inp", "r") ){
        freopen("trash.inp", "r", stdin);
        freopen("trash.out", "w", stdout);
    }

    cin >> n >> m;
    for (int i = 1; i <= m; i ++){
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
        adj[u].pb({i, v});
        adj[v].pb({i, u});
    }

    memset(d, -1, sizeof d);
    bfs();
//    for (int i = 1; i <= n; i ++) cout << d[i] << ' '; cout << '\n';

    for (int i = 1; i <= n; i ++)
        sort(adj[i].begin(), adj[i].end());
    memset(f, -1, sizeof f);
    f[1] = 0;
    go(1);

    for (int i = 2; i <= n; i ++)
        cout << f[i] << '\n';

    return 0;
}
