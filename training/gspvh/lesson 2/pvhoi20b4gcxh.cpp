#include<bits/stdc++.h>
#define pb push_back
#define eb emplace_back
#define pi pair<int, int>
#define fi first
#define se second
#define ll long long
using namespace std;
const int N = 3e5 + 5;
const ll MOD = 998244353;

int sub, n, m, sh = 0;
vector<pi> adj[N];
ll cnt[N], timedfs = 0, vis[N], low[N], num[N], used[N], id[N];
ll sz[N], ans_ver[N], ans_edg[N];

void dfs1(int u){
    cnt[sh] ++; vis[u] = 1; id[u] = sh;
    for (auto it : adj[u])
        if ( !vis[it.fi] )
            dfs1(it.fi);
}

void dfs2(int u, int pu){
    int childs = 0, isJoint = 0;
    vector<ll> cont;
    sz[u] = 1;
    num[u] = low[u] = ++ timedfs;
    ll sv = 0;

    for (auto it : adj[u]) if ( !used[it.se] ){
        int v = it.fi;
        used[it.se] = 1;
        if ( !num[v] ){
            dfs2(v, u);
            childs ++;
            low[u] = min(low[u], low[v]);
            sz[u] += sz[v];

            if ( low[v] == num[v] )
                ans_edg[it.se] = ( cnt[sh] - sz[v] ) * sz[v];

            if ( u == pu ){
                cont.pb(sz[v]);
                if ( childs >= 2 ) isJoint = 1;
                sv += sz[v];
            } else if ( low[v] >= num[u] ){
                isJoint = 1;
                cont.pb(sz[v]);
                sv += sz[v];
            }
        }
        else low[u] = min(low[u], num[v]);
    }

    cont.pb(cnt[sh] - sv - 1);
    ll sum = 0;

    if ( isJoint ){
        for (int i = 0; i < cont.size(); i ++) sum += cont[i];
        ans_ver[u] = sum * sum;
        for (int i = 0; i < cont.size(); i ++)
            ans_ver[u] -= cont[i] * cont[i];
        ans_ver[u] /= 2;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("pvhoi20b4gcxh.inp", "r") ){
        freopen("pvhoi20b4gcxh.inp", "r", stdin);
        freopen("pvhoi20b4gcxh.out", "w", stdout);
    }

    cin >> sub >> n >> m;
    for (int i = 1; i <= m; i ++){
        int u, v; cin >> u >> v;
        adj[u].eb(v, i);
        adj[v].eb(u, i);
    }

    memset(vis, 0, sizeof vis);
    memset(sz, 0, sizeof sz);
    memset(low, 0, sizeof low);
    memset(num, 0, sizeof num);

    for (int u = 1; u <= n; u ++)
        if ( !num[u] ){
            sh ++;
            cnt[sh] = 0, dfs1(u), dfs2(u, u);
        }

    ll base = 1LL * n * n;
    for (int i = 1; i <= sh; i ++)
        base = base - cnt[i] * cnt[i];
    base /= 2;

    for (int i = 1; i <= n; i ++) cout << ( ans_ver[i] + base - ( n - cnt[id[i]] ) ) % MOD << ' '; cout << '\n';
    for (int i = 1; i <= m; i ++) cout << ( ans_edg[i] + base ) % MOD << ' ';

    return 0;
}
