#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int N = 1e5 + 5;

int n, q, timeDfs;
vector<int> adj[N];
struct edge{
    int u, v, w;
} edg[N];
struct query{
    int u, v, k, id;
} que[N];
int par[N], tin[N], tout[N], st[4*N], ans[N];

void dfs(int u, int pu){
    tin[u] = ++timeDfs;
    for (int v : adj[u]) if ( v != pu ){
        par[v] = u;
        dfs(v, u);
    }
    tout[u] = timeDfs;
}

void update(int id, int l, int r, int u, int v, int val){
    if ( l > v || r < u ) return;
    if ( u <= l && r <= v ){
        st[id] ^= val;
        return;
    }
    int mid = l + r >> 1;
    update(id*2, l, mid, u, v, val);
    update(id*2+1, mid+1, r, u, v, val);
}

int get(int id, int l, int r, int u){
    if ( l > u || r < u ) return 0;
    if ( l == r ) return st[id];
    int mid = l + r >> 1;
    return st[id] ^ get(id*2, l, mid, u) ^ get(id*2+1, mid+1, r, u);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("trash.inp", "r") ){
        freopen("trash.inp", "r", stdin);
        freopen("trash.out", "w", stdout);
    }

    cin >> n >> q;
    for (int i = 1, u, v, w; i < n; i ++){
        cin >> u >> v >> w;
        adj[u].pb(v);
        adj[v].pb(u);
        edg[i] = {u, v, w};
    }

    dfs(1, 0);

    for (int i = 1; i < n; i ++)
        if ( par[edg[i].u] == edg[i].v )
            swap(edg[i].u, edg[i].v);

    for (int i = 1; i <= q; i ++)
        cin >> que[i].u >> que[i].v >> que[i].k, que[i].id = i;

    sort(que + 1, que + 1 + q, [&](query a, query b){
        return a.k < b.k;
    });
    sort(edg + 1, edg + n, [&](edge a, edge b){
        return a.w < b.w;
    });

//    for (int i = 1; i < n; i ++) cout << edg[i].u << ' ' << edg[i].v << ' ' << edg[i].w << '\n';
//    cout << '\n';
//    for (int i = 1; i <= q; i ++) cout << que[i].u << ' ' << que[i].v << ' ' << que[i].k << '\n';

    int ptr = 1;
    for (int i = 1; i <= q; i ++){
        while ( ptr <= n && edg[ptr].w <= que[i].k ){
            update(1, 1, n, tin[edg[ptr].v], tout[edg[ptr].v], edg[ptr].w);
            ptr ++;
        }

//        cout << i << ' ' << ptr << '\n';

        ans[que[i].id] = get(1, 1, n, tin[que[i].u]) ^ get(1, 1, n, tin[que[i].v]);
    }

    for (int i = 1; i <= q; i ++)
        cout << ans[i] << '\n';

    return 0;
}
