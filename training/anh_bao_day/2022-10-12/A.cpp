#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int N = 1e5 + 5;

int n;
int a[N], dp[N][2];
vector<int> adj[N];

void ckmn(int &a, int b){
    a = min(a, b);
}

void ckmx(int &a, int b){
    a = max(a, b);
}

void dfs(int u, int pu){
    if ( pu && adj[u].size() == 1 ){
        dp[u][0] = 0;
        dp[u][1] = n+1;
        return;
    }

    int mx = 0, mn = n+1;
    for (int v : adj[u]) if ( v != pu){
        dfs(v, u);

        mx = max(mx, min(( a[u] < a[v] ? dp[v][0] : n+1 ), ( a[u] < dp[v][1] ? a[v] : n+1 )));

        mn = min(mn, max(( a[u] > a[v] ? dp[v][1] : 0), ( a[u] > dp[v][0] ? a[v] : 0)));
    }

    dp[u][0] = mx;
    dp[u][1] = mn;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    for (int i = 1, u, v; i < n; i ++){
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    for (int i = 1; i <= n; i ++)
        dp[i][0] = n+1;
    dfs(1, 0);

    if ( dp[1][0] != n+1 || dp[1][1] ) cout << "YES\n";
    else cout << "NO\n";

    return 0;
}
