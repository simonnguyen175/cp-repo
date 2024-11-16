#include<bits/stdc++.h>
#define pb push_back
#define int long long
using namespace std;
const int N = 5e5 + 5;
const int MOD = 998244353;

int sub, n, inv2;
vector<int> adj[N];
int g[N][2], f[N][2];

int add(int a, int b){
    a += b;
    if ( a >= MOD ) a -= MOD;
    if ( a < 0 ) a += MOD;
    return a;
}

int mul(int a, int b){
    return 1ll * a * b % MOD;
}

int Pow(int a, int b){
    if ( b == 0 ) return 1;
    int tmp = Pow(a, b/2);
    if ( b % 2 ) return mul(tmp, mul(tmp, a));
    else return mul(tmp, tmp);
}

void dfs(int u){
    f[u][0] = 1;

    int teve = 1, todd = 1, hodd = 1;
    int tmp[2];
    for (int i = 1; i <= adj[u].size(); i ++){
        int v = adj[u][i-1];
        dfs(v);

        tmp[0] = f[u][0], tmp[1] = f[u][1];
        f[u][0] = add(f[u][0], add(mul(tmp[0], f[v][0]), mul(tmp[1], f[v][1])));
        f[u][1] = add(f[u][1], add(mul(tmp[1], f[v][0]), mul(tmp[0], f[v][1])));

        teve = mul(teve, add(f[v][0], 1));

        todd = mul(todd, add(f[v][1], 1));
        hodd = mul(hodd, add(1, -f[v][1]));
    }

    swap(f[u][0], f[u][1]);

    f[u][0] = mul(f[u][0], 2);
    f[u][1] = mul(f[u][1], 2);
    f[u][1] = add(f[u][1], -teve);
    f[u][0] = add(f[u][0], -mul(add(todd, -hodd), inv2));
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    freopen("rbw.inp", "r", stdin);
    freopen("rbw.out", "w", stdout);

    cin >> sub >> n;
    for (int i = 2; i <= n; i ++){
        int p;
        cin >> p;
        adj[p].pb(i);
    }

    inv2 = Pow(2, MOD-2);

    dfs(1);

    cout << add(f[1][0], f[1][1]);

    return 0;
}
