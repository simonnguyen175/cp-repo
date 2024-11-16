#include<bits/stdc++.h>
#define pb push_back
#define pi pair<int, int>
#define fi first
#define se second
#define ll long long
using namespace std;
const int N = 1e3 + 5;
const int oo = 1e9;

int n, m, t;
string s;
int g[N], y[N];
vector<int> adj[N];
int d[N][N];

void BFS(int x){
    queue<int> q; q.push(x); d[x][x] = 0;
    while ( q.size() ){
        int u = q.front(); q.pop();
        for (int v : adj[u]){
            int w = 1; if ( s[u] != s[x] ) w += t;
            if ( d[x][v] > d[x][u] + w ){
                d[x][v] = d[x][u] + w;
                q.push(v);
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n >> m >> t >> s;
    s = ' ' + s;

    int cntg = 0, cnty = 0;
    for (int i = 1; i <= n; i ++)
        if ( s[i] == 'Y' ) y[++cnty] = i;
        else g[++cntg] = i;

    for (int i = 1; i <= m; i ++){
        int u, v, w = 1;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    for (int i = 1; i <= n; i ++)
    for (int j = 1; j <= n; j ++)
        d[i][j] = oo;

    for (int i = 1; i <= n; i ++)
        BFS(i);

    ll ans1 = 0, ans2 = 0;
    for (int i = 1; i <= cntg; i ++)
        for (int j = i + 1; j <= cntg; j ++)
            ans1 += d[g[i]][g[j]];

    for (int i = 1; i <= cnty; i ++)
        for (int j = i + 1; j <= cnty; j ++)
            ans2 += d[y[i]][y[j]];

    cout << ans1 << ' ' << ans2;

    return 0;
}
