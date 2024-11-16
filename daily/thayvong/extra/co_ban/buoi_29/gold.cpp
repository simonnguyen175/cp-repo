#include<bits/stdc++.h>
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define simon "gold"
#define ll long long
using namespace std;
const int N = 1e5 + 5;

int t, n, a[N];
vector<int> adj[N];
bool vis[N];
ll dp1[N], dp2[N], ans;

void dfs(int V, int pV){
    long long sum1=0, sum2=0;
    for(auto v: adj[V]){
        if(v == pV) continue;
        dfs(v, V);
        sum1 += dp2[v];
        sum2 += max(dp1[v], dp2[v]);
    }
    dp1[V] = a[V] + sum1;
    dp2[V] = sum2;
}

void solve(){
    dfs(1, 0);
    ans = 0;
    ans = max({ans, dp1[1], dp2[1]});
    cout << ans << '\n';
}

void init(){
    cin >> n;
    for (int i=1; i<=n; i++)
        adj[i].clear();
    for (int i=1; i<=n-1; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i=1; i<=n; i++)
        cin >> a[i];
    memset(dp1, 0, sizeof dp1);
    memset(dp2, 0, sizeof dp2);
}

int main(){
    FASTio
    if ( fopen(simon".inp","r") ){
        freopen(simon".inp","r",stdin);
        freopen(simon".out","w",stdout);
    }
    cin >> t;
    for (int i=1; i<=t; i++){
        init();
        solve();
    }
    return 0;
}
