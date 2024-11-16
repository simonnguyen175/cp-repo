#include<bits/stdc++.h>
#define pb push_back
#define pi pair<int, int>
#define fi first
#define se second
using namespace std;
const int N = 1e6 + 5;

int n, k, cur = 0;
int node[N], inset[N], inopt[N], dp[N];
vector<pi> adj[N];
vector<int> opt;

void dfs(int u, int pu){
    if ( u ){
        dp[u] = dp[pu] + 1;

        if ( inset[u] )
            dp[u] = min(dp[u], opt.back() + cur + inset[u]);

        int tmp = dp[u] - cur;
        if ( tmp < opt.back() ) opt.pb(tmp), inopt[u] = 1;
        cur += inset[u];
    }
    else opt.pb(0), inopt[0] = 1;

    for (auto it : adj[u]) if ( it.se != pu )
        dfs(it.se, u);

    if ( inopt[u] ) opt.pop_back(), inopt[u] = 0;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("trash.inp", "r") ){
        freopen("trash.inp", "r", stdin);
        freopen("trash.out", "w", stdout);
    }

    cin >> n;
    for (int i  = 1; i <= n; i ++){
        int p; char c;
        cin >> p >> c;
        c -= 'a';
        adj[p].pb({c, i});
    }

    cin >> k;
    for (int i = 1; i <= k; i ++){
        cin >> node[i];
        inset[node[i]] = 1;
    }

    for (int i = 0; i <= n; i ++)
        sort(adj[i].begin(), adj[i].end());

    dfs(0, 0);

    for (int i = 1; i <= k; i ++)
        cout << dp[node[i]] << ' ';

    return 0;
}
