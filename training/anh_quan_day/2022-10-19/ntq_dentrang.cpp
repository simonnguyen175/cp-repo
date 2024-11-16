#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
const int N = 1e5 + 5;
const int oo = 1e5;

int n;
vector<int> adj[N], circle;
int par[N], vis[N], incir[N];
ll dp[N][2][2], c[N][2], f[N][2][2];
ll ans = oo;

void dfs_findC(int u){
    if ( circle.size() ) return;
    vis[u] = 1;
    for (int v : adj[u]) if ( v != par[u] ){
        if ( circle.size() ) return;
        if ( !vis[v] ){
            par[v] = u;
            dfs_findC(v);
        }
        else{
            circle.pb(u);
            incir[u] = 1;
            do{
                u = par[u];
                incir[u] = 1;
                circle.pb(u);
            } while ( u != v );
            return;
        }
    }
}

// dp(u, i, j) dinh u, mau i, j 0/1 co con to mau den chua
void dfs(int u, int pu){
    dp[u][0][0] = 0;
    dp[u][1][0] = 1;
    ll mn1 = oo, mn2 = oo;

    for (int v : adj[u]) if ( v != pu && !incir[v] ){
        dfs(v, u);
        dp[u][0][0] += dp[v][0][1];
        mn1 = min(mn1, dp[v][1][1] - dp[v][0][1]);
        dp[u][1][0] += min(dp[v][0][0], dp[v][1][0]);
        mn2 = min(mn2, dp[v][1][0] - min(dp[v][0][0], dp[v][1][0]));
    }

    dp[u][0][1] = dp[u][0][0] + mn1;
    dp[u][1][1] = 1 + dp[u][1][0] + mn2;
}

void solve(int cc, int cd){
    for (int u = 1; u <= n; u ++)
    for (int i = 0; i <= 1; i ++)
    for (int j = 0; j <= 1; j ++)
        f[u][i][j] = oo;



    if ( circle.size() == 2 ){
        ans = min(ans, c[circle[0]][1] + c[circle[1]][1]);
        return;
    }

    for (int i = 1; i < circle.size()-1; i ++){
        int u = circle[i];

        f[i][0][0] = f[i-1][0][1] + dp[u][0][0];
        f[i][0][1] = min(f[i-1][1][1] + dp[u][0][0], f[i-1][0][1] + dp[u][1][1]);

        f[i][1][0] = f[i-1][0][0] + dp[u][1][1];
        f[i][1][1] = min(f[i-1][1][0] + dp[u][1][0], f[i-1][0][0] + dp[u][1][1]);
    }

    int x = circle.size()-2;
    if ( cc == 1 ){
        if ( cd == 1 ) ans = min(ans, f[x][0][0]);
        else ans = min(ans, f[x][1][0]);
    }
    else{
        if ( cd == 1 ) ans = min(ans, f[x][0][1]);
        else ans = min(ans, f[x][1][1]);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("trash.inp", "r") ){
        freopen("trash.inp", "r", stdin);
        freopen("trash.out", "w", stdout);
    }

    cin >> n;
    for (int i = 1; i <= n; i ++){
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    dfs_findC(1);
    for (int u : circle) cout << u << ' ';
    cout << '\n';

    for (int u = 1; u <= n; u ++)
    for (int i = 0; i <= 1; i ++)
    for (int j = 0; j <= 1; j ++)
        dp[u][i][j] = oo;

    for (int u : circle)
        dfs(u, 0);
//
//    for (int cd = 0; cd <= 1; cd ++)
//    for (int cc = 0; cc <= 1; cc ++)
//        solve(cd, cc);
//
//
//    cout << ( ans != oo ? ans : -1 );

    return 0;
}
