#include<bits/stdc++.h>
#define pb push_back
#define pi pair<int, int>
#define fi first
#define se second
using namespace std;
const int N = 1e5 + 5;

int n, m, q;
int Par[N], ans[N];
set<pi> sque0[N], sque1[N];
set<int> scol[N];
struct edg{
    int u, v, w;
};
vector<edg> edges;

int Find(int u){
    if ( Par[u] == u ) return u;
    else return Par[u] = Find(Par[u]);
}

void Join(int u, int v, int w){
    u = Find(u);
    v = Find(v);
    Par[v] = u;
    if ( v == u ) return;

    // gop mau
    if ( scol[u].size() < scol[v].size() )
        swap(scol[u], scol[v]);
    for (auto it : scol[v]) scol[u].insert(it);

    // gop query chua gap nhau
    if ( sque0[u].size() < sque0[v].size() )
        swap(sque0[u], sque0[v]);
    for (auto it : sque0[v])
        if ( sque0[u].find(it) == sque0[u].end() )
            sque0[u].insert(it);
        else{
            sque0[u].erase(it);
            sque1[u].insert(it);
        }

    // gop query da gap nhau va cap nhat kqua
    if ( sque1[u].size() < sque1[v].size() )
        swap(sque1[u], sque1[v]);
    for (auto it : sque1[v]) sque1[u].insert(it);
    int diff = scol[u].size();
    while ( sque1[u].size() && sque1[u].begin()->fi <= diff ){
        auto it = sque1[u].begin();
        ans[it->se] = w;
        sque1[u].erase(it);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("in.inp", "r") ){
        freopen("in.inp", "r", stdin);
        freopen("out.out", "w", stdout);
    }

    cin >> n >> m >> q;
    for (int i = 1, t; i <= n; i ++){
        cin >> t;
        scol[i].insert(t);
    }

    for (int i = 1; i <= m; i ++){
        int u, v, w;
        cin >> u >> v >> w;
        edges.pb({u, v, w});
    }

    for (int i = 1, x, y, k; i <= q; i ++){
        cin >> x >> y >> k;
        if ( x == y ) sque1[x].insert({k, i});
        else sque0[x].insert({k, i}), sque0[y].insert({k, i});
    }

    sort(edges.begin(), edges.end(), [&](edg a, edg b){
        return a.w < b.w;
    });
    for (int i = 1; i <= n; i ++) Par[i] = i;
    memset(ans, -1, sizeof ans);
    for (auto it : edges)
        Join(it.u, it.v, it.w);

    for (int i = 1; i <= q; i ++)
        cout << ans[i] << '\n';

    return 0;
}
