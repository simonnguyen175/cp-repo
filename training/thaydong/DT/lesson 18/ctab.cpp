#include<bits/stdc++.h>
#define pi pair<int, int>
#define fi first
#define se second
#define pb push_back
using namespace std;
const int N = 2e2 + 5;

int n;
int a[N][N], b[N][N];
vector<pi> adj[N];
int vis[N], col[N], cnt[2];

pi bfs(int u){
    queue<int> q;
    q.push(u);
    cnt[0] = cnt[1] = 0;
    while ( q.size() ){
        int u = q.front();
        q.pop();

        cnt[col[u]] ++;
        vis[u] = 1;

        for (auto it : adj[u]){
            int v = it.fi, w = it.se;
            if ( col[v] != -1 )
                if ( col[v] != col[u] ^ w ) return {-1, -1};
                else continue;

            col[v] = col[u] ^ w;
            q.push(v);
        }
    }

    return {cnt[0], cnt[1]};
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("trash.inp", "r") ){
        freopen("trash.inp", "r", stdin);
        freopen("trash.out", "w", stdout);
    }

    cin >> n;
    for (int i = 1; i <= n; i ++)
    for (int j = 1; j <= n; j ++)
        cin >> a[i][j];

    for (int i = 1; i <= n; i ++)
    for (int j = 1; j <= n; j ++)
        cin >> b[i][j];

    for (int i = 1; i <= n; i ++)
    for (int j = 1; j <= n; j ++){
        if ( !a[i][j] ){
            if ( b[i][j] ) return cout << -1, 0;
        }
        else if ( !b[i][j] ) return cout << -1, 0;

        if ( !a[i][j] ) continue;

        if ( a[i][j] != b[i][j] )
            adj[i].pb({n+j, 1}), adj[n+j].pb({i, 1});
        else adj[i].pb({n+j, 0}), adj[n+j].pb({i, 0});
    }

    for (int i = 1; i <= 2*n; i ++)
        col[i] = -1;

    int ans = 0;
    for (int i = 1; i <= n; i ++) if ( !vis[i] ){
        col[i] = 0;
        pi tmp = bfs(i);

        if ( tmp.fi == -1 ) return cout << -1, 0;
        else ans += min(tmp.fi, tmp.se);
    }

    cout << ans;

    return 0;
}
