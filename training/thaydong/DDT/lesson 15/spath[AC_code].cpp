#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;
const int N = 1e4;

int n, m, q;
bool c[N][N];
vector<pair<int, int>> que[N];
vector<int> unadj[N];
int res[N*101], deg[N], v[N], d[N], dis[N];

void anal1(int u){
    for (auto it : que[u]){
        if ( it.fi == u ) {res[it.se] = 0; continue;}
        if ( !c[u][it.fi] ) res[it.se] = 2;
        else res[it.se] = 1;
    }
}

void anal2(int u){
    int sl = n;
    for (int i = 0; i < n; i ++)
        v[i] = i, d[i] = 0, dis[i] = 0;

    dis[u] = 0;
    queue<int> q; q.push(u);
    while ( q.size() ){
        int k = q.front(); q.pop();
        for (int x : unadj[k]) d[x] = 1;
        for (int j = 0; j < sl; j ++)
            if ( v[j] != u )
            if ( d[v[j]] == 0 ){
                dis[v[j]] = dis[k] + 1;
                q.push(v[j]);
                swap(v[j], v[sl-1]);
                sl --; j --;
            }
            else d[v[j]] = 0;
    }

    for (auto it : que[u]){
        if ( it.fi == u ) res[it.se] = 0;
        else
            if ( dis[it.fi] != 0 ) res[it.se] = dis[it.fi];
            else res[it.se] = -1;
    }
}

int main(){
    if ( fopen("spath.inp", "r") ){
        freopen("spath.inp", "r", stdin);
        freopen("spath.out", "w", stdout);
    }

    cin >> n >> m;

    memset(c, 1, sizeof c);

    for (int i = 0; i < n; i ++) deg[i] = n - 1;

    for (int i = 1; i <= m; i ++){
        int u, v;
        cin >> u >> v;
        deg[u] --; deg[v] --;
        c[u][v] = c[v][u] = 0;
        unadj[u].pb(v); unadj[v].pb(u);
    }

    cin >> q;
    for (int i = 1; i <= q; i ++){
        int u, v;
        cin >> u >> v;
        if ( deg[u] > deg[v] ) swap(u, v);
        que[u].pb({v, i});
    }

    for (int i = 0; i < n; i ++)
        if ( que[i].size() >= 0 )
            if ( deg[i] >= n / 2 ) anal1(i);
            else anal2(i);

    for (int i = 1; i <= q; i ++)
        cout << res[i] << '\n';

    return 0;
}
