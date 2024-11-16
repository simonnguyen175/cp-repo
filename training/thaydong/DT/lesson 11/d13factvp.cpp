#include<bits/stdc++.h>
#define int ll
#define ll long long
#define pb push_back
using namespace std;
const int N = 1e6 + 5;
const ll oo = 1e15;

int n;
int lpf[N], s[N];
ll f[N][10][3], ans = -oo;
vector<int> adj[N], pri[N];

void ckmx(ll &a, ll b){
    a = max(a, b);
}

void dfs(int u, int pu){
    for (int i = 0; i < pri[u].size(); i ++){
        f[u][i][1] = 2 * s[u];
        f[u][i][2] = -oo;
    }

    for (int v : adj[u]) if ( v != pu ){
        dfs(v, u);

        int i = 0, j = 0;

        while ( i < pri[u].size() && j < pri[v].size() ){
            if ( pri[u][i] < pri[v][j] ) i ++;
            else if ( pri[u][i] > pri[v][j] ) j ++;
            else{
                // cap nhat ans
                if ( f[v][j][2] != -oo )
                    ckmx(ans, f[u][i][1] + f[v][j][2]);
                if ( f[v][j][1] != -oo && f[u][i][2] != -oo )
                    ckmx(ans, f[u][i][2] + f[v][j][1]);

                // pick 2 cai va tiep tuc
                if ( f[v][j][1] != -oo )
                    ckmx(f[u][i][2], f[u][i][1] + f[v][j][1] + s[u]);
                if ( f[v][j][2] != -oo )
                    ckmx(f[u][i][2], f[v][j][2] + 2 * s[u]);

                // pick 1 cai va tiep tuc
                if ( f[v][j][1] != -oo )
                    ckmx(f[u][i][1], f[v][j][1] + 2 * s[u]);

                i ++, j ++;
            }
        }
    }
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

//    if ( fopen("d13factvp.inp", "r") ){
//        freopen("d13factvp.inp", "r", stdin);
//        freopen("d13factvp.out", "w", stdout);
//    }

    cin >> n;
    for (int i = 1; i <= n; i ++) cin >> s[i];

    for (int i = 2; i * i < N; i ++) if ( !lpf[i] )
    for (int j = i * i; j < N; j += i) if ( !lpf[j] )
        lpf[j] = i;
    for (int i = 2; i < N; i ++) if ( !lpf[i] )
        lpf[i] = i;

    for (int i = 1, c; i <= n; i ++){
//        cout << i << " : \n";
        cin >> c;
        while ( lpf[c] ){
            int x = lpf[c];
            pri[i].pb(x);
            while ( c % x == 0 ) c /= x;
//            cout << x << ' ';
        }
//        cout << '\n';
    }

    for (int i = 1, u, v; i < n; i ++){
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    dfs(1, 0);

    if ( ans == -oo ) cout << "No Solution";
    else cout << ans;

    return 0;
}
