#include <bits/stdc++.h>
#define fi first
#define se second
#define ii pair < int , int >

using namespace std;

const int maxn = 1e4 + 10;

int vs[maxn] , h[maxn] , d[maxn][2] , backedge , be , par[maxn];

vector < ii > g[maxn];
vector < int > ans;

void DFS(int u,int p) {
    vs[u] = 1;
    for (auto v : g[u])
    if (p != v.se) {
        if (!vs[v.fi]) {
            par[v.fi] = v.se;
            h[v.fi] = h[u] + 1;
            DFS(v.fi , v.se);
            d[u][0] += d[v.fi][0];
            d[u][1] += d[v.fi][1];
        } else if (h[u] > h[v.fi]) {
            if (h[v.fi] % 2 == h[u] % 2) {
                backedge++;
                be = v.se;
                d[u][0]++;
                d[v.fi][0]--;
            } else {
                d[u][1]++;
                d[v.fi][1]--;
            }
        }
    }
}

bool BFS(int u) {
    bool ok = 1;
    queue < int > q;
    vs[u] = 1;
    q.push(u);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto v : g[u])
        if (!vs[v.fi]) {
            vs[v.fi] = 3 - vs[u];
            q.push(v.fi);
        } else if (vs[v.fi] == vs[u]) ok = 0;
    }
    return ok;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    if ( fopen("fairy.inp", "r") ){
        freopen("fairy.inp", "r", stdin);
        freopen("fairy.out", "w", stdout);
    }

    int n , m;
    cin >> n >> m;
    for (int u , v , i = 1 ; i <= m ; ++i) {
        cin >> u >> v;
        g[u].emplace_back(v , i);
        g[v].emplace_back(u , i);
    }
    int ver = 0 , cnt = 0 , tplt = 0;
    for (int i = 1 ; i <= n ; ++i)
    if (!vs[i]) {
        if (BFS(i)) cnt++;
        else ver = i;
        tplt++;
    }
    if (cnt == tplt) {
        cout << m << '\n';
        for (int i = 1 ; i <= m ; ++i) cout << i << ' ';
        exit(0);
    }
    if (tplt - cnt > 1) {
        cout << 0;
        exit(0);
    }
    memset(vs,0,sizeof(vs));
    h[ver] = 1;
    DFS(ver , 0);

    for (int i = 1; i <= n; i ++) cout << i << " : " << d[i][0] << ' ' << d[i][1] << '\n';

    for (int i = 1 ; i <= n ; ++i)
    if (par[i] != 0 && (d[i][0] == backedge && d[i][1] == 0)) ans.push_back(par[i]);
    if (backedge == 1) ans.push_back(be);
    cout << ans.size() << '\n';
    sort(ans.begin(),ans.end());
    for (auto v : ans) cout << v << ' ';
}
