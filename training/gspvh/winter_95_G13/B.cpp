#include<bits/stdc++.h>
#define pb push_back
#define ll long long
using namespace std;
const int N = 3e5 + 5;

int t, n, k, m, p;
struct edges{
    int u, v, w, id;
} edg[N];
int moji[N], par[N], sz[N];
ll ans = 0;
vector<int> des, bui;

int Find(int u){
    if ( u == par[u] ) return u;
    else return par[u] = Find(par[u]);
}

bool Join(int u, int v){
    u = Find(u), v = Find(v);

    if ( ( moji[u] && moji[v] ) || ( u == v ) ) return 0;

    if ( sz[u] < sz[v] ) swap(u, v);
    par[v] = u;
    sz[u] += sz[v];
    moji[u] |= moji[v];

    return 1;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    freopen("moji.inp", "r", stdin);
    freopen("moji.out", "w", stdout);

    cin >> t >> n >> k;
    for (int i = 1, u; i <= k; i ++)
        cin >> u, moji[u] = 1;

    /// destroy
    cin >> m;
    for (int i = 1; i <= m; i ++){
        cin >> edg[i].u >> edg[i].v >> edg[i].w;
        edg[i].id = i;
    }

    sort(edg + 1, edg + 1 + m, [&](edges a, edges b){
        if ( a.w == b.w ) return a.id > b.id;
        else return a.w > b.w;
    });

    for (int i = 1; i <= n; i ++) par[i] = i, sz[i] = 1;
    for (int i = 1; i <= m; i ++)
        if ( !Join(edg[i].u, edg[i].v) )
            ans += edg[i].w, des.pb(edg[i].id);

    /// build
    cin >> p;
    for (int i = 1; i <= p; i ++){
        cin >> edg[i].u >> edg[i].v >> edg[i].w;
        edg[i].id = i;
    }

    sort(edg + 1, edg + 1 + p, [&](edges a, edges b){
        if ( a.w == b.w ) return a.id < b.id;
        else return a.w < b.w;
    });

    for (int i = 1; i <= p; i ++)
        if ( Join(edg[i].u, edg[i].v) )
            ans += edg[i].w, bui.pb(edg[i].id);

    cout << t * ans << '\n';
    sort(des.begin(), des.end());
    cout << des.size() << '\n';
    for (int x : des) cout << x << ' '; cout << '\n';
    sort(bui.begin(), bui.end());
    cout << bui.size() << '\n';
    for (int x : bui) cout << x << ' '; cout << '\n';

    return 0;
}
