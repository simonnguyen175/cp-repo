#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define fi first
#define se second
using namespace std;
const int N = 1e3 + 5;
const ll oo = 1e15;

int n, m, q;
vector<int> adj[N];
ll d[N], f[N][N][3];
int nchild[N], mx[N];
bool vis[N];

void dfs(int u, int pu){
    vis[u] = 1;
    for (int v : adj[u]) if ( v != pu )
        dfs(v, u);
}

void dfs1(int u, int pu){
    f[u][0][0] = 0;
    f[u][1][2] = d[u];
    nchild[u] = 1;

    for (int v : adj[u]) if ( v != pu ){
        dfs1(v, u);

        for (int curV = nchild[u]; curV >= 0; curV --)
        for (int addV = nchild[v]; addV >= 0; addV --){
            int nV = curV + addV;
            f[u][nV][0] = min(f[u][nV][0], f[u][curV][0] + min(f[v][addV][0], f[v][addV][1]));
            f[u][nV][1] = min({f[u][nV][1], f[u][curV][2] + min(f[v][addV][2], f[v][addV][1]), f[u][curV][1] + min({f[v][addV][2], f[v][addV][1], f[v][addV][0]})});
            f[u][nV][2] = min(f[u][nV][2], f[u][curV][2] + f[v][addV][0]);
        }

        nchild[u] += nchild[v];
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    freopen("buyver.in", "r", stdin);
    freopen("buyver.out", "w", stdout);

    cin >> n >> m;
    for (int i = 1; i <= n; i ++)
        cin >> d[i];

    for (int i = 1; i <= m; i ++){
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    for (int i = 0; i <= n; i ++)
    for (int j = 0; j <= n; j ++)
        f[i][j][0] = f[i][j][1] = f[i][j][2] = oo;

    for (int u = 1; u <= n; u ++) if ( !vis[u] )
        dfs(u, 0), adj[0].pb(u);

    dfs1(0, 0);

    vector<pair<ll, int>> cont;
    for (int i = 0; i <= n; i ++)
        cont.pb({f[0][i][0], i});
    sort(cont.begin(), cont.end());
    mx[0] = cont[0].se;
    for (int i = 1; i < n; i ++)
        mx[i] = max(mx[i-1], cont[i].se);

    cin >> q;
    while ( q -- ){
        ll s; cin >> s;

        int lo = 0, hi = n, res;
        while ( lo <= hi ){
            int mid = lo + hi >> 1;
            if ( cont[mid].fi <= s ) res = mid, lo = mid + 1;
            else hi = mid -1;
        }

        cout << mx[res] << '\n';
    }

    return 0;
}
