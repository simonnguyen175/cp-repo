#include<bits/stdc++.h>
#define simon "connected"
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pb push_back
#define pi pair<int, int>
#define fi first
#define se second
using namespace std;
const int N = 1e2 + 5;

int n, m, tt, ans;
bool vis[N];
vector<int> adj[N], tplt[N];
vector<pi> edges;

void dfs(int u){
    vis[u] = 1; tplt[tt].pb(u);
    for (int v : adj[u]){
        if ( !vis[v] ) dfs(v);
    }
}

bool cmp(vector<int> &a, vector<int> &b){
    return a.size() > b.size();
}

int main(){
    FASTio
    if ( fopen(simon".inp", "r") ){
        freopen(simon".inp", "r", stdin);
        freopen(simon".out", "w", stdout);
    }

    cin >> n >> m;
    for (int i = 1; i <= m; i ++){
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    for (int i = 1; i <= n; i ++)
        if ( !vis[i] ) ++ tt, dfs(i);

    sort(tplt + 1, tplt + 1 + tt, cmp);

    priority_queue<pi, vector<pi>, greater<pi>> heap;

    for (int x : tplt[1]) heap.push({0, x});

    for (int i = 2; i <= tt; i ++){
        int u = heap.top().se, deg = heap.top().fi;
        heap.pop();
        edges.pb({tplt[i][0], u});
        ans = max(ans, ++deg);
        heap.push({deg, u}), heap.push({1, tplt[i][0]});
        for (int j = 1; j < tplt[i].size(); j ++)
            heap.push({0, tplt[i][j]});
    }

    cout << ans << '\n';
    cout << edges.size() << '\n';
    for (auto it : edges)
        cout << it.fi << ' ' << it.se << '\n';

    return 0;
}
