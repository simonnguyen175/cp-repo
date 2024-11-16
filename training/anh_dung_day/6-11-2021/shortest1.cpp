#include<bits/stdc++.h>
#define simon "shortest1"
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
#define ii pair<ll, int>
using namespace std;
const int N = 1e3 + 5e2 + 5;
const int M = 5e3 + 5;
const ll oo = 1e15;
const int MOD = 1e9 + 7;

struct edg{
    ll w;
    int v, tt;
};

bool operator > (const edg& a, const edg& b){
    return a.w > b.w;
}

int n, m;
vector<edg> adj[N];
ll d[N], f[N], h[N], vis[M];

void dfs(int u){
    for (auto it : adj[u]){
        int v = it.v, tt = it.tt; ll w = it.w;
        if ( d[u] + w == d[v] ){
            if ( h[v] == 1 ) dfs(v);
            h[u] = ( h[u] + h[v] ) % MOD;
            vis[tt] = ( vis[tt] + ( f[u] * h[v] ) % MOD ) % MOD;
        }
    }
}

void dijkstra(int x){
    priority_queue<ii, vector<ii>, greater<ii>> heap;
    for (int i = 1; i <= n; i ++) d[i] = oo, f[i] = 0, h[i] = 1;
    d[x] = 0; f[x] = 1;
    heap.push({0, x});

    while ( !heap.empty() ){
        int u = heap.top().second;
        ll du = heap.top().first;
        heap.pop();

        for (auto tmp : adj[u]){
            int v = tmp.v;
            int uv = tmp.w;
            if ( d[v] > du + uv ){
                d[v] = du + uv;
                f[v] = f[u] % MOD;
                heap.push({d[v], v});
            }
            else if ( d[v] == du + uv ) f[v] = ( f[v] + f[u] ) % MOD;
        }
    }

    dfs(x);
}

int main(){
    FASTio
    if ( fopen(simon".inp", "r" ) ){
        freopen(simon".inp", "r", stdin);
        freopen(simon".out", "w", stdout);
    }
    cin >> n >> m;
    for (int i = 1; i <= m; i ++){
        int u, v; ll w;
        cin >> u >> v >> w;
        adj[u].push_back({w, v, i});
    }

    for (int i = 1; i <= n; i ++)
        dijkstra(i);

    for (int i = 1; i <= m; i ++)
        cout << vis[i] << '\n';

    return 0;
}
