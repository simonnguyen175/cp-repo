#include<bits/stdc++.h>
#define pi pair<int, int>
#define fi first
#define se second
#define pb push_back
using namespace std;
const int N = 2e5 + 5;
const int oo = 1e9;

int n, m, q;
vector<pi> adj[N];
int day[N], ans[N], f[N], d[N];

void bfs(){
    queue<int> q;
    for (int i = 1; i <= n; i ++) d[i] = -1, f[i] = 0;
    d[1] = 0, f[1] = oo, q.push(1);

    while ( q.size() ){
        int u = q.front();
        q.pop();
        for (auto it : adj[u]){
            int v = it.fi, id = it.se;

            if ( d[v] != -1 ){
                if ( d[u] + 1 == d[v] )
                    f[v] = max(min(day[id], f[u]), f[v]);
                continue;
            }

            d[v] = d[u] + 1;
            f[v] = min(f[u], day[id]);
            q.push(v);
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("train.in", "r") ){
        freopen("train.in", "r", stdin);
        freopen("train.out", "w", stdout);
    }

    cin >> n >> m >> q;
    for (int i = 1; i <= m; i ++){
        int u, v; cin >> u >> v;
        adj[u].pb({v, i});
        adj[v].pb({u, i});
    }

    for (int i = 1; i <= m; i ++) day[i] = oo;
    for (int i = 1; i <= q; i ++){
        int x; cin >> x;
        day[x] = i;
    }

    bfs();

    for (int i = 2; i <= n; i ++)
        if ( f[i] != oo ) ans[f[i]] ++;

    for (int i = 1; i <= q; i ++)
        ans[i] += ans[i-1];

    for (int i = 1; i <= q; i ++)
        cout << ans[i] << '\n';

    return 0;
}
