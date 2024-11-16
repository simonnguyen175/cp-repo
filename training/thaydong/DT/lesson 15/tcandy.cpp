#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int N = 1e6 + 5;

int n;
int sz[N], d[N];
vector<int> adj[N], ans;

void dfs(int u, int pu){
    sz[u] = 1;
    for (int v : adj[u]) if ( v != pu ){
        dfs(v, u);
        sz[u] += sz[v];
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n;
    for (int i = 1, u, v; i < n; i ++){
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    vector<int> div;
    for (int i = 1; i * i <= n; i ++) if ( n % i == 0 ){
        div.pb(i);
        if ( i != n/i ) div.pb(n/i);
    }

    dfs(1, 0);

    for (int i = 1; i <= n; i ++) d[sz[i]] ++;
    for (int k : div) if ( k != n ){
        int cnt = 0;
        for (int i = k; i <= n; i += k)
            cnt += d[i];
        if ( cnt == n / k ) ans.pb(cnt - 1);
    }

    sort(ans.begin(), ans.end());
    for (int x : ans) cout << x << ' ';

    return 0;
}
