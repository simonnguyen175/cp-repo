#include<bits/stdc++.h>
#define pi pair<int, int>
#define fi first
#define se second
#define pb push_back
using namespace std;
const int N = 1e5 + 5;

int n;
int par[N];
vector<int> adj[N];
int f[N][2], dp[N][3];
pi a[N];

// 1 la noi voi cha
// 0 la noi voi con
void dfs(int u){
    int mx = 0;
    for (int v : adj[u]){
        dfs(v);
        f[u][1] += f[v][0];
        mx = max(mx, f[v][1] + 1 - f[v][0]);
    }

    f[u][0] = f[u][1] + mx;
}

int main(){
    cin >> n;
    par[1] = 0;
    for (int i = 2; i <= n; i ++){
        cin >> par[i];
        adj[par[i]].pb(i);
    }

    int m = 0;
    for (int i = 1; i <= n; i ++){
        if ( !par[i] ) dfs(i);
        a[++m] = {f[i][0], f[i][1]};
        cout << i << ' ' << f[i][0] << ' ' << f[i][1] << '\n';
    }

    // 1 la noi
    // 0 la ko noi
    // 2 la ko noi va noi cai sau
    for (int i = 1; i <= m; i ++){
        dp[i][1] = dp[i-1][2] + a[i].se;
        dp[i][0] = max(dp[i-1][1] + a[i].fi, dp[i-1][0] + a[i].fi);
        dp[i][2] = max(dp[i-1][1] + a[i].se, dp[i-1][0] + a[i].se);
    }

    cout << max({dp[m][0], dp[m][1], dp[m][2]});

    return 0;
}
