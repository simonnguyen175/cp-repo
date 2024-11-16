#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
const int N = 5e5 + 5;
const ll oo = 1e15;

int n, mn;
vector<int> adj[N];
int p[N][20], a[N];
ll ans = 0;

void dfs(int u){
    if ( p[u][0] ){
        for (int j = 1; j <= 19; j ++)
            p[u][j] = p[p[u][j-1]][j-1];

        ll tmp = oo;
        int k;
        for (k = 0; k <= 19 && p[u][k]; k ++)
            tmp = min(tmp, 1LL * (k+1) * a[p[u][k]]);
        tmp = min(tmp, 1LL * (k+1) * a[mn]);

        ans += tmp + a[u];
    }

    for (int v : adj[u]) if ( v != p[u][0] ){
        p[v][0] = u;
        dfs(v);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n;
    a[0] = 1e9 + 5;
    for (int i = 1; i <= n; i ++){
        cin >> a[i];
        if ( a[mn] > a[i] ) mn = i;
    }

    for (int i = 1; i < n; i ++){
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    dfs(mn);

    cout << ans;

    return 0;
}
