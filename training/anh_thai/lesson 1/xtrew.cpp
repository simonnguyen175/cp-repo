#include<bits/stdc++.h>
#define ll long long
#define pi pair<ll, ll>
#define fi first
#define se second
#define BIT(x,k) ((x>>k)&1)
#define pb push_back
using namespace std;
const int N = 1e5 + 5;

int n;
ll s[N], cnt[35][2];
vector<pi> adj[N];

void dfs(int u, int pu){
    for (auto it : adj[u]) if ( it.fi != pu ){
        ll v = it.fi, w = it.se;
        s[v] = s[u] ^ w;
        dfs(v, u);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n;
    for (int i = 1; i < n; i ++){
        ll u, v, w;
        cin >> u >> v >> w;
        adj[u].pb({v, w}); adj[v].pb({u, w});
    }

    dfs(1, 0);

    ll ans = 0;

    for (int i = 1; i <= n; i ++){
        for (int j = 0; j <= 31; j ++)
            ans += cnt[j][1-BIT(s[i], j)] * (1<<j);
        for (int j = 0; j <= 31; j ++)
            cnt[j][BIT(s[i], j)] ++;
    }

    cout << ans;

    return 0;
}
