#include<bits/stdc++.h>
#define pi pair<int, int>
#define pii pair<pi, int>
#define fi first
#define se second
#define pb push_back
using namespace std;
const int N = 1e6 + 5;
const int oo = 1e9;

int n, timeDfs = 0;
struct rec{
    int x, y, u, v;
} rect[N];
vector<int> contx, conty;
vector<pii> row[N], col[N];
map<int, int> idx, idy;
vector<int> adj[N];
vector<int> bri;
int num[N], low[N], nchild[N];

void dfs(int u, int pu){
    num[u] = low[u] = ++timeDfs;
    nchild[u] = 1;
    for (int v : adj[u]) if ( v != pu ){
        if ( !num[v] ){
            dfs(v, u);
            nchild[u] += nchild[v];
            low[u] = min(low[u], low[v]);
            if ( low[v] >= num[v] ) bri.pb(v);
        }
        else low[u] = min(low[u], num[v]);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("voi20building.inp", "r") ){
        freopen("voi20building.inp", "r", stdin);
        freopen("voi20building.out", "w", stdout);
    }

    cin >> n;
    for (int i = 1; i <= n; i ++){
        int x, y, u, v;
        cin >> x >> y >> u >> v;
        contx.pb(x); contx.pb(u);
        conty.pb(y); conty.pb(v);
        rect[i] = {x, y, u, v};
    }

    sort(contx.begin(), contx.end());
    sort(conty.begin(), conty.end());
    contx.erase(unique(contx.begin(), contx.end()), contx.end());
    conty.erase(unique(conty.begin(), conty.end()), conty.end());

    for (int i = 0; i < contx.size(); i ++) idx[contx[i]] = i + 1;
    for (int i = 0; i < conty.size(); i ++) idy[conty[i]] = i + 1;

    for (int i = 1; i <= n; i ++){
        rect[i].x = idx[rect[i].x], rect[i].u = idx[rect[i].u];
        rect[i].y = idy[rect[i].y], rect[i].v = idy[rect[i].v];

        row[rect[i].v].pb({{rect[i].x, rect[i].u}, i});
        col[rect[i].u].pb({{rect[i].v, rect[i].y}, i});
    }

    for (int i = 1; i <= conty.size(); i ++) sort(row[i].begin(), row[i].end());
    for (int i = 1; i <= contx.size(); i ++) sort(col[i].begin(), col[i].end());

    for (int i = 1; i <= n; i ++){
        int tt = rect[i].y;
        int lo, hi, L = -1, R = -1;

        lo = 0, hi = row[tt].size() - 1;
        while ( lo <= hi ){
            int mid = lo + hi >> 1;
            if ( row[tt][mid].fi.se >= rect[i].x ) L = mid, hi = mid - 1;
            else lo = mid + 1;
        }

        lo = 0, hi = row[tt].size() - 1;
        while ( lo <= hi ){
            int mid = lo + hi >> 1;
            if ( row[tt][mid].fi.fi <= rect[i].u ) R = mid, lo = mid + 1;
            else hi = mid - 1;
        }

        if ( L == -1 || R == -1 || L > R ) continue;

        for (int j = L; j <= R; j ++){
            adj[row[tt][j].se].pb(i);
            adj[i].pb(row[tt][j].se);
        }
    }

    for (int i = 1; i <= n; i ++){
        int tt = rect[i].x;
        int lo, hi, L = -1, R = -1;

        lo = 0, hi = col[tt].size() - 1;
        while ( lo <= hi ){
            int mid = lo + hi >> 1;
            if ( col[tt][mid].fi.se >= rect[i].v ) L = mid, hi = mid - 1;
            else lo = mid + 1;
        }

        lo = 0, hi = col[tt].size() - 1;
        while ( lo <= hi ){
            int mid = lo + hi >> 1;
            if ( col[tt][mid].fi.fi <= rect[i].y ) R = mid, lo = mid + 1;
            else hi = mid - 1;
        }

        if ( L == -1 || R == -1 || L > R ) continue;

        for (int j = L; j <= R; j ++){
            adj[col[tt][j].se].pb(i);
            adj[i].pb(col[tt][j].se);
        }
    }

    for (int i = 1; i <= n; i ++){
        sort(adj[i].begin(), adj[i].end());
        adj[i].erase(unique(adj[i].begin(), adj[i].end()), adj[i].end());

//        cout << i << " : ";
//        for (int x : adj[i]) cout << x << ' '; cout << '\n';
    }

    int ans = oo;

    for (int i = 1; i <= n; i ++) if ( !num[i] ) {
        bri.clear();
        dfs(i, 0);
//        for (int x : bri) cout << x << ' '; cout << '\n';
        for (int x : bri) ans = min(ans, abs(nchild[i]-2*nchild[x]));
    }

    cout << ( ans == oo ? -1 : ans );

    return 0;
}
