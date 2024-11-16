#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
const int N = 1e5 + 5;
const ll oo = 1e15;

int n;
vector<int> adj[N];
int a[N], b[N];
ll dp[N][2];

void dfs(int u, int pu){
    /// dp(u, 0/1) dinh u xay dung truoc hay sau cha u

    /// node la'
    if ( adj[u].size() == 1 && pu ){
        dp[u][0] = dp[u][1] = a[u];
        if ( b[u] == 1 ) dp[u][1] = 0;
        return;
    }

    ll tmp = 0;
    vector<ll> cont, cont1;
    for (int v : adj[u]) if ( v != pu ){
        dfs(v, u);
        tmp += dp[v][1];
        cont.pb({dp[v][0] - dp[v][1]});
    }

    dp[u][0] = min(dp[u][0], tmp + a[u]);

    if ( pu && b[u] > 1 ) dp[u][1] = min(dp[u][1], tmp + a[u]);
    else dp[u][1] = min(dp[u][1], tmp);

    sort(cont.begin(), cont.end());
    if ( cont.size() >= b[u] ){
        ll tmp1 = 0;
        for (int i = 0; i < b[u]; i ++) tmp1 += cont[i];
        dp[u][0] = min(dp[u][0], tmp + tmp1);
    }
    if ( pu && cont.size() >= b[u] - 1 ){
        ll tmp1 = 0;
        for (int i = 0; i < b[u]-1; i ++) tmp1 += cont[i];
        dp[u][1] = min(dp[u][1], tmp + tmp1);
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
    for (int i = 1, u, v; i < n; i ++){
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    for (int i = 1; i <= n; i ++) cin >> a[i];
    for (int i = 1; i <= n; i ++) cin >> b[i];

    for (int i = 1; i <= n; i ++) dp[i][0] = dp[i][1] = oo;
    dfs(1, 0);

    cout << dp[1][0];

    return 0;
}
