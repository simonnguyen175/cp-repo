#include<bits/stdc++.h>
#define int long long
#define pi pair<int, int>
#define fi first
#define se second
#define pb push_back
using namespace std;
const int N = 1e4 + 5;
const int oo = 1e15;

int n, k, ans = oo;
vector<int> adj[N];
int f[N], sz[N];
pi st[4*N];

void dfs(int u, int pu){
    for (int v : adj[u]) if ( v != pu ){
        dfs(v, u);
        f[u] += f[v];
        sz[u] += sz[v];
    }
    f[u] += sz[u];
    sz[u] ++;
}

void update(int id, int l, int r, int u, int v){
    if ( l > u || r < u ) return;
    if ( l == r ){
        st[id].fi += v;
        st[id].se += l*v;
        return;
    }
    int mid = l + r >> 1;
    update(id*2, l, mid, u, v);
    update(id*2+1, mid+1, r, u, v);
    st[id].fi = st[id*2].fi + st[id*2+1].fi;
    st[id].se = st[id*2].se + st[id*2+1].se;
}

int getk(){
    int id = 1, l = 1, r = n, cur = k, res = 0;
    while ( true ){
        if ( l == r ) { res += cur * l; break; }
        int mid = l + r >> 1;
        if ( st[id*2+1].fi >= cur ){
            id = id * 2 + 1;
            l = mid + 1;
        }
        else{
            res += st[id*2+1].se;
            cur -= st[id*2+1].fi;
            id *= 2;
            r = mid;
        }
    }
    return res;
}

void go(int u, int pu){
    update(1, 1, n, sz[u], -1);
    ans = min(ans, f[u] - getk());
//    cout << u << ' ' << f[u] << ' ' << getk() << '\n';
    update(1, 1, n, sz[u], 1);

    for (int v : adj[u]) if ( v != pu ){
        int szu = sz[u], szv = sz[v], fu = f[u], fv = f[v];

        update(1, 1, n, szu, -1);
        update(1, 1, n, szv, -1);

        sz[u] -= sz[v]; sz[v] += sz[u];
        f[u] = f[u] - f[v];
        f[v] = f[v] - szv + f[u] + sz[u];

        update(1, 1, n, sz[u], 1);
        update(1, 1, n, sz[v], 1);

        go(v, u);

        update(1, 1, n, sz[u], -1);
        update(1, 1, n, sz[v], -1);

        sz[u] = szu, sz[v] = szv, f[u] = fu, f[v] = fv;

        update(1, 1, n, sz[u], 1);
        update(1, 1, n, sz[v], 1);
    }
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    freopen("cezar.inp", "r", stdin);
    freopen("cezar.out", "w", stdout);

    cin >> n >> k;
    for (int i = 1, u, v; i < n; i ++){
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    dfs(1, 0);
//    cout << f[2] << '\n';
    for (int i = 1; i <= n; i ++)
        update(1, 1, n, sz[i], 1);
    go(1, 0);
    cout << ans << '\n';

    return 0;
}
