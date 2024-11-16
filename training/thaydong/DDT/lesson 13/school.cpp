#include<bits/stdc++.h>
#define pi pair<int, int>
#define pb push_back
#define fi first
#define se second
using namespace std;
const int N = 2e5 + 5;
const int oo = 1e9;

int n, m, q;
vector<int> adj[N];
int a[N], f[N], g[N], vis[N], st[4*N];

void build(int id, int l, int r){
    if ( l == r ){
        st[id] = f[l] + g[l];
        return;
     }
     int mid = ( l + r ) / 2;
     build(id * 2, l, mid);
     build(id * 2 + 1, mid + 1, r);
     st[id] = min(st[id * 2], st[id * 2 + 1]);
}

void update(int id, int l, int r, int u){
    if ( l > u || r < u ) return;
    if ( l == r && l == u ){
        st[id] = f[u] + g[u];
        return;
    }
    int mid = ( l + r ) / 2;
    update(id * 2, l, mid, u);
    update(id * 2 + 1, mid + 1, r, u);
    st[id] = min(st[id * 2], st[id * 2 + 1]);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n >> m >> q;
    for (int i = 1; i <= m; i ++){
        int u, v;
        cin >> u >> v;
        adj[v].pb(u);
    }

    for (int i = 1; i <= n; i ++)
        cin >> a[i];

    f[1] = 0;
    for (int i = 2; i <= n; i ++)
        f[a[i]] = f[a[i-1]] + 1;

    queue<int> qu;
    for (int i = 1; i <= n; i ++) g[i] = oo;
    g[n] = 0; vis[n] = 1; qu.push(n);
    while ( qu.size() ){
        int u = qu.front(); qu.pop();
        for (int v : adj[u]){
            if ( vis[v] ) continue;
            g[v] = g[u] + 1;
            vis[v] = 1;
            qu.push(v);
        }
    }

    build(1, 1, n);

    while ( q -- ){
        int u, v;
        cin >> u >> v;
        swap(f[a[u]], f[a[v]]);
        swap(a[u], a[v]);
        update(1, 1, n, a[u]);
        update(1, 1, n, a[v]);
        cout << st[1] << '\n';
    }

    return 0;
}
