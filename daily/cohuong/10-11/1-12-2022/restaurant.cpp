#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int N = 2e5 + 5;

int n, m, ans = 0;
vector<int> adj[N];
bool ruoi[N];
int cnt[N], h[N];

void dfs1(int u, int pu){
    if ( ruoi[u] ) cnt[u] = 1;
    for (int v : adj[u]){
        if ( v == pu ) continue;
//        cout << u << " -> " << v << ' ' << cnt[v] << '\n';
        dfs1(v, u);
        cnt[u] += cnt[v];
    }
}

void dfs2(int u, int pu){
    for (int v : adj[u]){
        if ( v == pu ) continue;
        if ( cnt[v] == 0 ) continue;
        h[v] = h[u] + 1;
        ans += 2;
        dfs2(v, u);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    freopen("restaurant.inp", "r", stdin);
    freopen("restaurant.out", "w", stdout);

    cin >> n >> m;

    int root = 0;
    for (int i = 1, u; i <= m; i ++){
        cin >> u; u ++;
        if ( !root ) root = u;
        ruoi[u] = 1;
    }

    for (int i = 1; i < n; i ++){
        int u, v;
        cin >> u >> v;
        u ++; v ++;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    dfs1(root, 0);
    dfs2(root, 0);

    int cur = 0;
    for (int i = 1; i <= n; i ++)
        if ( h[i] > h[cur] ) cur = i;
    for (int i = 1; i <= n; i ++)
        cnt[i] = h[i] = 0;
    dfs1(cur, 0);

    ans = 0;

    dfs2(cur, 0);

//    cout << ans << '\n';
//
//    for (int i = 1; i <= n; i ++)
//        cout << i << " : " << cnt[i] << ' ' << h[i] << '\n';

    int tmp = 0;
    for (int i = 1; i <= n; i ++)
        tmp = max(tmp, h[i]);

    cout << ans - tmp;

    return 0;
}
