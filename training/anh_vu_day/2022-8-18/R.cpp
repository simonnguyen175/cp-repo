#include<bits/stdc++.h>
#define pb push_back
#define BIT(x,k) ((x>>k)&1)
using namespace std;
const int N = 1e2 + 5;
const int M = 1e4 + 5;
const int MOD = 1e9 + 7;

int n, m;
vector<int> adj[N];
int lpf[M], szf[M], fact[M][100];
int f[N][M], g[M];

int add(int a, int b){
    a += b;
    if ( a >= MOD ) a -= MOD;
    if ( a < 0 ) a += MOD;
    return a;
}

int mul(int a, int b){
    return 1LL * a * b % MOD;
}

void sieve(){
    lpf[1] = 0;
    for (int i = 2; i * i <= m; i ++) if ( !lpf[i] )
    for (int j = i; j <= m; j += i)
        lpf[j] = i;

    for (int i = 2; i <= m; i ++)
        if ( !lpf[i] ) lpf[i] = i;

    for (int i = 2; i <= m; i ++){
        int x = i;
        vector<int> cont;
        while ( lpf[x] ){
            if ( !cont.size() || cont.back() != lpf[x] )
                cont.pb(lpf[x]);
            x /= lpf[x];
        }

        x = i;
        szf[x] = cont.size();

//        cout << i << " : ";
//        for (int p : cont) cout << p << ' ';
//        cout << '\n';

        for (int msk = 1; msk < (1<<szf[x]); msk ++){
            fact[x][msk] = 1;
            for (int i = 0; i < szf[x]; i ++) if ( BIT(msk, i) )
                fact[x][msk] *= cont[i];
//            cout << fact[x][msk] << ' ';
        }

//        cout << '\n';
    }
}

void dfs(int u, int pu){
    for (int i = 2; i <= m; i ++)
        f[u][i] = 1;

    for (int v : adj[u]) if ( v != pu )
        dfs(v, u);

    for (int v : adj[u]) if ( v != pu ){

        for (int i = 2; i <= m; i ++){
            g[i] = 0;
            for (int j = i; j <= m; j += i)
                g[i] = add(g[i], f[v][j]);

            int tmp = 0;
            for (int msk = 1; msk < (1<<szf[i]); msk ++)
                if ( __builtin_popcount(msk) % 2 )
                    tmp = add(tmp, g[fact[i][msk]]);
                else tmp = add(tmp, -g[fact[i][msk]]);
            f[u][i] = mul(f[u][i], tmp);
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("treegcd.inp", "r") ){
        freopen("treegcd.inp", "r", stdin);
        freopen("treegcd.out", "w", stdout);
    }

    cin >> n >> m;
    for (int i = 1, u, v; i < n; i ++){
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    sieve();

    dfs(1, 0);

    int ans = 0;
    for (int i = 2; i <= m; i ++)
        ans = add(ans, f[1][i]);

    cout << ans << '\n';

    return 0;
}
