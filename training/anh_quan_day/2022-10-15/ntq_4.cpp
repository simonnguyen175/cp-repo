#include<bits/stdc++.h>
#define ll long long
#define pi pair<int, int>
#define fi first
#define se second
#define pb push_back
using namespace std;
const int N = 5e3 + 5;

int n;
int a[N];
int s, sum[N], f[N][10005];
vector<pi> adj[N];

void dfs(int u, int pu){
    f[u][0] = a[u];

    for (auto it : adj[u]){
        int v = it.fi, w = it.se;

        if ( v == pu ) continue;

        dfs(v, u);

//        cout << "-> " << v << " : ";
        for (int cur = min(s, sum[u]); cur >= 0; cur --)
        for (int add = min(s-cur-w, sum[v]); add >= 0; add --){
            int ncur = cur + add + w;
            f[u][ncur] = max(f[u][ncur], f[u][cur] + f[v][add]);
        }

        sum[u] += w + sum[v];

//        for (int cur = 0; cur <= sum[u]; cur ++)
//            cout << f[u][cur] << ' ';
//        cout << '\n';
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("trash.inp", "r") ){
        freopen("trash.inp", "r", stdin);
        freopen("trash.out", "w", stdout);
    }

    cin >> n >> s;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];

    for (int i = 1, u, v, w; i < n; i ++){
        cin >> u >> v >> w;
        adj[u].pb({v, w});
        adj[v].pb({u, w});
    }

    dfs(1, 0);

    int ans = 0;
    for (int i = 0; i <= s; i ++)
        ans = max(ans, f[1][i]);

    cout << ans;

    return 0;
}
