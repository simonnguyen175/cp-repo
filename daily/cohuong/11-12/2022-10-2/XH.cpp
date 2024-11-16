#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
const int N = 1e3 + 5;

int n, m;
struct boxes{
    ll x, y, z;
};
struct columns{
    ll r, h;
};
vector<boxes> box;
vector<columns> col;
vector<int> adj[N];
ll w[N], f[N], vis[N], ans = 0;

void dfs(int u){
    vis[u] = 1;
    f[u] = w[u];
    for (int v : adj[u]){
        if ( !vis[v] ) dfs(v);
        f[u] = max(f[u], f[v] + w[u]);
    }
    ans = max(ans, f[u]);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    freopen("XH.inp", "r", stdin);
    freopen("XH.out", "w", stdout);

    cin >> n >> m;
    for (int i = 1; i <= n; i ++){
        ll x, y, z;
        cin >> x >> y >> z;
        box.pb({x, y, z});
        box.pb({x, z, y});
        box.pb({y, x, z});
        box.pb({y, z, x});
        box.pb({z, x, y});
        box.pb({z, y, x});
    }

    for (int i = 1; i <= m; i ++){
        ll r, h;
        cin >> r >> h;
        col.pb({r, h});
    }

    n *= 6;

    // box to box
    for (int i = 0; i < n; i ++)
    for (int j = 0; j < n; j ++) if ( i != j )
        if ( box[i].x > box[j].x && box[i].y > box[j].y )
            adj[i].pb(j);

    // col to col
    for (int i = 0; i < m; i ++)
    for (int j = 0; j < m; j ++) if ( i != j )
        if ( col[i].r > col[j].r )
            adj[n+i].pb(n+j);

    // box to to col
    for (int i = 0; i < n; i ++)
    for (int j = 0; j < m; j ++)
        if ( min(box[i].x, box[i].y) > 2 * col[j].r )
            adj[i].pb(n+j);
        else if ( box[i].x*box[i].x + box[i].y*box[i].y < 4 * col[j].r*col[j].r )
            adj[n+j].pb(i);

    for (int i = 0; i < n; i ++) w[i] = box[i].z;
    for (int i = 0; i < m; i ++) w[n+i] = col[i].h;

    for (int i = 0; i < n+m; i ++)
        if ( ! vis[i] ) dfs(i);

    cout << ans;

    return 0;
}
