#include<bits/stdc++.h>
#define pi pair<int, int>
#define fi first
#define se second
#define pb push_back
using namespace std;
const int N = 1e5 + 5;

int n, m;
vector<pi> adj[N];
int vis[N], h[N], f[N][2], pedg[N];
int wbe, cbe;

bool bfs(int u){
    bool ck = 1;
    queue<int> q;
    vis[u] = 1;
    q.push(u);
    while ( q.size() ){
        int u = q.front();
        q.pop();
        for (auto it : adj[u]){
            int v = it.fi;
            if ( !vis[v] ){
                vis[v] = 3 - vis[u];
                q.push(v);
            }
            else{
                if ( vis[v] == vis[u] ) ck = 0;
            }
        }
    }
    return ck;
}

void dfs(int u, int pu){
    vis[u] = 1;
    for (auto it : adj[u]) if ( it.se != pu ){
        int v = it.fi;
        if ( !vis[v] ){
            pedg[v] = it.se;
            h[v] = h[u] + 1;
            dfs(v, it.se);
            f[u][0] += f[v][0];
            f[u][1] += f[v][1];
        }
        else if ( h[u] > h[v] ){
            if ( h[u] % 2 == h[v] % 2 ){
                wbe ++, cbe = it.se;
                f[u][0] ++, f[v][0] --;
            }
            else f[u][1] ++, f[v][1] --;
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("fairy.inp", "r") ){
        freopen("fairy.inp", "r", stdin);
        freopen("fairy.out", "w", stdout);
    }

    cin >> n >> m;
    for (int i = 1; i <= m; i ++){
        int u, v;
        cin >> u >> v;
        adj[u].pb({v, i});
        adj[v].pb({u, i});
    }

    int root, cnt = 0, bir = 0;
    for (int i = 1; i <= n; i ++)
        if ( !vis[i] ){
            if ( bfs(i) ) bir ++;
            else root = i;
            cnt ++;
        }

    if ( bir == cnt ){
        cout << m << '\n';
        for (int i = 1; i <= m; i ++) cout << i << ' ';
        return 0;
    }

    if ( cnt - bir > 1 ){
        cout << 0;
        return 0;
    }

    memset(vis, 0, sizeof vis);
    h[root] = 1;
    dfs(root, 0);

    vector<int> ans;
    for (int i = 1; i <= n; i ++)
        if ( pedg[i] && f[i][0] == wbe && f[i][1] == 0 ) ans.pb(pedg[i]);

    if ( wbe == 1 ) ans.pb(cbe);

    sort(ans.begin(), ans.end());
    cout << ans.size() << '\n';
    for (int x : ans) cout << x << ' ';

    return 0;
}
