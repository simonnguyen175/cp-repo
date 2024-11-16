#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
const int N = 2e3 + 5;
const ll oo = 1e15;

int t, n;
vector<int> adj[N];
int child[N], hp[N];
ll f[N][N][2], g[N][2];

void dfs(int u){
    child[u] = 1;
    f[u][0][0] = hp[u];
    f[u][1][1] = 0;

    for (int v : adj[u]){
        dfs(v);

        // f[u][i][0/1] xet den u da phu phep i lan, 0/1 bi phu phep hay ko

        for (int i = 0; i <= child[u]+child[v]; i ++)
            g[i][0] = g[i][1] = oo;

        for (int i = child[u]; i >= 0; i --)
        for (int j = child[v]; j >= 0; j --){
            g[i+j][0] = min(g[i+j][0], f[u][i][0] + min(f[v][j][0] + hp[v], f[v][j][1]));
            g[i+j][1] = min(g[i+j][1], f[u][i][1] + min(f[v][j][0], f[v][j][1]));
        }

//        cerr << v << " -> " << u << '\n';
        for (int i = 0; i <= child[u]+child[v]; i ++){
//            cerr << i << ' ' << g[i][0] << ' ' << g[i][1] << '\n';
            f[u][i][0] = g[i][0], f[u][i][1] = g[i][1];
        }

        child[u] += child[v];
    }
}

void solve(){
    cin >> n;

    for (int i = 1; i <= n; i ++) adj[i].clear(), child[i] = 0;
    for (int i = 1; i <= n; i ++)
    for (int j = 0; j <= n; j ++)
        f[i][j][0] = f[i][j][1] = oo;

    for (int i = 2, u; i <= n; i ++){
        cin >> u;
        adj[u].pb(i);
    }

    for (int i = 1; i <= n; i ++)
        cin >> hp[i];

    dfs(1);

    for (int i = 0; i <= n; i ++)
        cout << min(f[1][i][0], f[1][i][1]) << ' ';
    cout << '\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> t;
    while ( t -- )
        solve();

    return 0;
}
