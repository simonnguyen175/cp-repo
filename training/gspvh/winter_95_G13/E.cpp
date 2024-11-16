#include<bits/stdc++.h>
#define pi pair<int, int>
#define fi first
#define se second
#define pb push_back
using namespace std;
const int N = 5e3 + 5;
const int oo = 1e9 + 7;
const int MOD = 998244353;

int t, n, m;
struct ke{
    int v, w, id;
};
vector<ke> adj[N];
vector<int> ad[N];
struct edges{
    int u, v, id;
};
int d[N], vis[N], f[N][2], ans[N];

int add(int a, int b){
    a += b;
    if ( a >= MOD ) a -= MOD;
    if ( a < 0 ) a += MOD;
    return a;
}

int mul(int a, int b){
    return 1ll * a * b % MOD;
}

void go(int u, int s, int t){
    if ( t ) f[u][t] = ( u == s );
    else f[u][t] = 1;

    for (int v : ad[u]){
        if ( !f[v][t] ) go(v, s, t);
        f[u][t] = add(f[u][t], f[v][t]);
    }
}

void solve(int s){
    priority_queue<pi, vector<pi>, greater<pi>> heap;
    for (int i = 1; i <= n; i ++) d[i] = oo;
    d[s] = 0;
    heap.push({0, s});
    while ( heap.size() ){
        int u = heap.top().se, du = heap.top().fi;
        heap.pop();

        if ( du != d[u] ) continue;

        for (auto it : adj[u]){
            int v = it.v, w = it.w;
            if ( d[v] > d[u] + w ){
                d[v] = d[u] + w;
                heap.push({d[v], v});
            }
        }
    }

    vector<edges> edg;
    queue<int> q;
    for (int i = 1; i <= n; i ++) vis[i] = 0;
    q.push(s);
    vis[s] = 1;
    while ( q.size() ){
        int u = q.front();
        q.pop();

        for (auto it : adj[u]){
            int v = it.v, w = it.w;

            if ( d[v] == d[u] + w ){
                edg.pb({u, v, it.id});
                if ( !vis[v] ) vis[v] = 1, q.push(v);
            }
        }
    }

    /// xuoi
    for (int i = 1; i <= n; i ++) ad[i].clear(), f[i][0] = 0;
    for (auto it : edg) ad[it.u].pb(it.v);
    for (int i = 1; i <= n; i ++)
        if ( !f[i][0] ) go(i, s, 0);

    /// nguoc
    for (int i = 1; i <= n; i ++) ad[i].clear(), f[i][1] = 0;
    for (auto it : edg) ad[it.v].pb(it.u);
    for (int i = 1; i <= n; i ++)
        if ( !f[i][1] ) go(i, s, 1);

    for (auto it : edg){
        ans[it.id] = add(ans[it.id], mul(f[it.u][1], f[it.v][0]));
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    freopen("cauluong.inp", "r", stdin);
    freopen("cauluong.out", "w", stdout);

    cin >> t >> n >> m;
    for (int i = 1; i <= m; i ++){
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].pb({v, w, i});
    }

    for (int i = 1; i <= n; i ++)
        solve(i);

    for (int i = 1; i <= m; i ++)
        cout << ans[i] << '\n';

    return 0;
}
