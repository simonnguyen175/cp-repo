#include<bits/stdc++.h>
#define pb push_back
#define ll long long
using namespace std;
const int N = 1e5 + 5;

int n, p1, p2, p3, timeDfs;
vector<int> adj[N], les[N], gre[N];
int tin[N], tout[N], par[N], st[4*N];

void dfs(int u, int pu){
    tin[u] = ++timeDfs;
    for (int v : adj[u]) if ( v != pu ){
        dfs(v, u);
        par[v] = u;
    }
    tout[u] = timeDfs;
}

void update(int id, int l, int r, int u){
    if ( l > u || r < u ) return;
    if ( l == r ){
        st[id] = 1;
        return;
    }
    int mid = l + r >> 1;
    update(id*2, l, mid, u);
    update(id*2+1, mid+1, r, u);
    st[id] = st[id*2] + st[id*2+1];
}

int get(int id, int l, int r, int u, int v){
    if ( l > v || r < u ) return 0;
    if ( u <= l && r <= v ) return st[id];
    int mid = l + r >> 1;
    return get(id*2, l, mid, u, v) + get(id*2+1, mid+1, r, u, v);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n;
    cin >> p1 >> p2 >> p3;
    for (int i = 1, u, v; i < n; i ++){
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    for (int i = 1; i <= n; i ++){
        les[i].resize(adj[i].size());
        gre[i].resize(adj[i].size());
    }

    dfs(1, 0);

    for (int u = 1; u <= n; u ++){
        for (int i = 0; i < adj[u].size(); i ++){
            int v = adj[u][i];
            if ( v == par[u] ) les[u][i] = u - 1 - get(1, 1, n, tin[u], tout[u]);
            else les[u][i] = get(1, 1, n, tin[v], tout[v]);
        }
        update(1, 1, n, tin[u]);
    }
    for (int i = 1; i <= 4*n; i ++) st[i] = 0;
    for (int u = n; u >= 1; u --){
        for (int i = 0; i < adj[u].size(); i ++){
            int v = adj[u][i];
            if ( v == par[u] ) gre[u][i] =  n - u - get(1, 1, n, tin[u], tout[u]);
            else gre[u][i] = get(1, 1, n, tin[v], tout[v]);
        }
        update(1, 1, n, tin[u]);
    }

    ll ans = 0;
    for (int u = 1; u <= n; u ++){
        for (int i = 0; i < adj[u].size(); i ++){
            if ( p2 > p1 ){
                if ( p2 > p3 ) ans += 1ll * ( u - 1 - les[u][i] ) * les[u][i];
                else ans += 1ll * ( n - u - gre[u][i] ) * les[u][i];
            }
            else{
                if ( p2 > p3 ) ans += 1ll * ( u - 1 - les[u][i] ) * gre[u][i];
                else ans += 1ll * ( n - u - gre[u][i] ) * gre[u][i];
            }
        }
    }

    if ( ( p1 < p2 && p2 > p3 ) || ( p1 > p2 && p2 < p3 ) ) ans /= 2;

    cout << ans;


    return 0;
}
