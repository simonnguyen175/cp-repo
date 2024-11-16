#include<bits/stdc++.h>
#define pb push_back
#define pi pair<int, int>
#define fi first
#define se second
#define ll long long
using namespace std;
const int N = 1e5 + 5;

int n, q, timeDfs = 0;
ll h[N];
int num[N], nchild[N], p[N][25];
ll bit1[N], bit2[N];
vector<int> adj[N];

void dfs(int u, int pu){
    num[u] = ++timeDfs;
    nchild[u] = 1;
    for (int v : adj[u]) if ( v != pu ){
        h[v] = h[u] + 1;
        dfs(v, u);
        p[v][0] = u;
        nchild[u] += nchild[v];
    }
}

int lca(int u, int v){
    if ( h[u] < h[v] ) swap(u, v);

    for (int i = 20; i >= 0; i --)
        if ( h[p[u][i]] >= h[v] )
            u = p[u][i];

    if ( u == v ) return u;

    for (int i = 20; i >= 0; i --)
        if ( p[u][i] != p[v][i] )
            u = p[u][i], v = p[v][i];

    return p[u][0];
}

void update(int u, ll v1, ll v2){
    for (int i = u; i <= n; i += i&(-i))
        bit1[i] += v1, bit2[i] += v2;
}

ll get1(int u){
    ll res = 0;
    for (; u >= 1; u -= u&(-u)) res += bit1[u];
    return res;
}

ll get2(int u){
    ll res = 0;
    for (; u >= 1; u -= u&(-u)) res += bit2[u];
    return res;
}

ll calc(int u){
    return h[u] * get1(num[u]) + get2(num[u]);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("qtree.in", "r") ){
        freopen("qtree.in", "r", stdin);
        freopen("qtree.out", "w", stdout);
    }

    cin >> n;
    for (int i = 1; i < n; i ++){
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    h[1] = 1;
    dfs(1, 0);

    for (int i = 1, x; i <= n; i ++){
        cin >> x;
        update(num[i], 0, x);
        update(num[i]+nchild[i], 0, -x);
    }

    for (int j = 1; j <= 20; j ++)
    for (int i = 1; i <= n; i ++)
        p[i][j] = p[p[i][j-1]][j-1];

    cin >> q;
    for (int i = 1; i <= q; i ++){
        int type, u, v;
        ll c;
        cin >> type;

        if ( type == 1 ){
            cin >> u >> c;
            update(num[u], 0, c);
            update(num[u]+nchild[u], 0, -c);
        }

        if ( type == 2 ){
            cin >> u >> c;
            update(num[u], c, -(h[u]-1)*c);
            update(num[u]+nchild[u], -c, (h[u]-1)*c);
        }

        if ( type == 3 ){
            cin >> u;
            ll du = calc(u);
            ll dpu = calc(p[u][0]);
            cout << du - dpu << '\n';
        }

        if ( type == 4 ){
            cin >> u >> v;
            int puv = lca(u, v);

            ll du = calc(u), dv = calc(v), dpuv = calc(puv);
            ll dppuv = calc(p[puv][0]);

            cout << du + dv - dpuv - dppuv << '\n';
        }
    }

    return 0;
}
