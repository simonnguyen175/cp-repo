#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int N = 3e5 + 5;
const int oo = 1e9;

int n, k;
vector<int> adj[N];
bool imp[N];
int p[N], d[N], h[N];

void bfs(){
    queue<int> Q;
    for (int i = 1; i <= n; i ++) d[i] = oo;
    for (int i = 1; i <= k; i ++) d[p[i]] = 0, Q.push(p[i]);
    while ( Q.size() ){
        int u = Q.front();
        Q.pop();
        for (int v : adj[u]) if ( d[v] == oo ){
            d[v] = d[u] + 1;
            Q.push(v);
        }
    }
}

void dfs(int u, int pu){
    for (int v : adj[u]) if ( v != pu ){
        h[v] = h[u] + 1;
        dfs(v, u);
        if ( imp[v] ) imp[u] = 1;
    }
}

bool check(int x){
    int root = 0;
    for (int i = 1; i <= n; i ++) imp[i] = 0, h[i] = 0;
    for (int i = 1; i <= n; i ++) if ( d[i] > x ){
        imp[i] = 1;
        if ( !root ) root = i;
    }

    int cur = 0;
    dfs(root, 0);
    for (int i = 1; i <= n; i ++) if ( imp[i] ){
        if ( h[i] > h[cur] ) cur = i;
    }

    for (int i = 1; i <= n; i ++) h[i] = 0;
    dfs(cur, 0);
    int res = 0;
    for (int i = 1; i <= n; i ++) if ( imp[i] )
        res = max(res, h[i]);
    return ( ( ( res + 1 ) / 2 ) <= x );
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("vo18business.inp", "r") ){
        freopen("vo18business.inp", "r", stdin);
        freopen("vo18business.out", "w", stdout);
    }

    cin >> n >> k;
    for (int i = 1; i <= k; i ++)
        cin >> p[i];
    for (int i = 1; i < n; i ++){
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    bfs();

    int lo = 0, hi = n, res;
    while ( lo <= hi ){
        int mid = lo + hi >> 1;
        if ( check(mid) ) res = mid, hi = mid - 1;
        else lo = mid + 1;
    }

    cout << res;

    return 0;
}
