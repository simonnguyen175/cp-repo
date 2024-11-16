#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
const int N = 1e5 + 5;

int n;
vector<ll> adj[N], cont[N];
ll a[N], child[N], cnt[N], has[N], ans[N];

void dfs(int u, int pu){
    cont[a[u]].pb(0);
    child[u] = 1;
    for (int v : adj[u]){
        if ( v == pu ) continue;
        dfs(v, u);
        child[u] += child[v];
    }
    cont[a[u]].pop_back();
    if ( cont[a[u]].size() )
        cont[a[u]].back() += child[u];
    else{
        cnt[a[u]] += child[u];
        ans[1] += child[u];
    }

    if ( pu ){
        has[u] = cont[a[pu]].back();
        cont[a[pu]].back() = 0;
    }
}

void go(int u, int pu){
    ll cur, pcur;
    if ( pu ){
        ans[u] = ans[pu];
        if ( a[u] != a[pu] ){
            cur = cnt[a[u]];
            pcur = cnt[a[pu]];
            cnt[a[u]] = n;
            cnt[a[pu]] -= child[u] - has[u];
            ans[u] += cnt[a[u]] - cur + cnt[a[pu]] - pcur;
        }
    }

    for (int v : adj[u])
        if ( v != pu ) go(v, u);

    if ( pu && a[u] != a[pu] ){
        cnt[a[u]] = cur;
        cnt[a[pu]] = pcur;
    }
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

    dfs(1, 0);
    go(1, 0);

    for (int i = 1; i <= n; i ++)
        cout << ans[i] << '\n';

    return 0;
}
