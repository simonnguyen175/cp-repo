#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
const int N = 1e5 + 5;
const ll oo = 1e12;

int n, t;
ll a[N], f[N][3];
vector<int> adj[N];

void dfs(int u, int pu){
    f[u][0] = 0;
    f[u][1] = a[u];

    ll mx = -oo, tmp = 0;
    bool ck = 0;

    for (int v : adj[u]) if ( v != pu ){
        dfs(v, u);
        f[u][0] += max(f[v][0], f[v][2]);
        f[u][1] += max({f[v][1], f[v][2], f[v][0] + a[v]});

        ll c = max({f[v][1], f[v][2], f[v][0]});
        tmp += c;
        mx = max(mx, f[v][1] - c);

        if ( f[v][1] == c ) ck = 1;
    }

    if ( adj[u].size() == 1 && u != 1 ) return;

//    cout << u << ' ' << tmp << ' ' << mx << ' ' << ck << '\n';

    if ( ck ) f[u][2] = tmp + a[u];
    else f[u][2] = tmp + mx + a[u];
}

void solve(){
    cin >> n;
    for (int i = 1; i <= n; i ++) adj[i].clear();
    for (int i = 1; i <= n; i ++) cin >> a[i];
    for (int i = 1; i < n; i ++){
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    for (int i = 1; i <= n; i ++) f[i][2] = -oo;

    dfs(1, 0);

//    for (int i = 1; i <= n; i ++)
//        cout << i << " : " << f[i][0] << ' ' << f[i][1] << ' ' << f[i][2] << '\n';

    cout << max({f[1][0], f[1][1], f[1][2]}) << '\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int test;
    cin >> test;
    while ( test -- ) solve();
    return 0;
}
