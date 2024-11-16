#include<bits/stdc++.h>
#define ll long long
#define pi pair<ll, ll>
#define fi first
#define se second
using namespace std;
const int N = 2e5 + 5;
const ll oo = 1e15;

int n, D, h;
int a[N], par[N], sz[N], d[N][22];
ll cost[N];
set<int> adj[N];
queue<pi> dis[N];

int dfs(int u, int pu){
    sz[u] = 1;
    for (int v : adj[u]) if ( v != pu )
        sz[u] += dfs(v, u);
    return sz[u];
}

int centroid(int u, int pu, int n){
    for (int v : adj[u]) if ( v != pu )
        if ( sz[v] > n/2 ) return centroid(v, u, n);
    return u;
}

void bfs(int c){
    queue<int> q;
    d[c][h] = 0;
    q.push(c);
    while ( q.size() ){
        int u = q.front();
        dis[c].push({u, d[u][h]});
        q.pop();
        for (int v : adj[u]) if ( d[v][h] == -1 ){
            d[v][h] = d[u][h] + 1;
            q.push(v);
        }
    }
}

void build(int u, int pu){
    int n = dfs(u, pu);
    int c = centroid(u, pu, n);
    par[c] = pu;

    bfs(c);
    h ++;

    vector<int> tmp(adj[c].begin(), adj[c].end());
    for (int v : tmp){
        adj[c].erase(v);
        adj[v].erase(c);
        build(v, c);
    }

    h --;
}

void dijkstra(){
    priority_queue<pi, vector<pi>, greater<pi>> heap;
    for (int i = 1; i <= n; i ++) cost[i] = oo;
    cost[1] = 0;
    heap.push({0, 1});

    while ( heap.size() ){
        int u = heap.top().se;
        ll du = heap.top().fi;
        heap.pop();

        if ( cost[u] != du ) continue;

        int ch = 0;
        while ( d[u][ch] != -1 ) ch ++;
        ch --;

        for (int c = u; c > 0; c = par[c]){
            while ( dis[c].size() && dis[c].front().se + d[u][ch] <= D ){
                int v = dis[c].front().fi;
                if ( cost[v] > du + a[v] ){
                    cost[v] = du + a[v];
                    heap.push({cost[v], v});
                }
                dis[c].pop();
            }
            ch --;
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

    cin >> n >> D;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];

    for (int i = 1, u, v; i < n; i ++){
        cin >> u >> v;
        adj[u].insert(v);
        adj[v].insert(u);
    }

    for (int i = 1; i <= n; i ++)
    for (int j = 0; j <= 20; j ++)
        d[i][j] = -1;

    build(1, 0);
    dijkstra();

    for (int i = 1; i < n; i ++)
        cout << cost[i] << ' ';
    cout << cost[n] << '\n';

    return 0;
}
