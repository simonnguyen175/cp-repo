#include<bits/stdc++.h>
#define simon "relativnost"
using namespace std;
const int N = 1e5 + 5;
const int MOD = 1e4 + 7;

int n, k, q;
int g[N], c[N];
int st[4*N][22];

int Pow(int a, int b){
    if ( b == 1 ) return a;
    int tmp = Pow(a, b/2);
    if ( b % 2 ) return tmp*tmp%MOD*a%MOD;
    return tmp*tmp%MOD;
}

void pushup(int id){
    for (int i = 0; i < k; i ++) st[id][i] = 0;
    for (int i = 0; i < k; i ++)
    for (int j = 0; j < k-i; j ++)
        st[id][i+j] += st[id*2][i] * st[id*2+1][j] % MOD;
    for (int i = 0; i < k; i ++) st[id][i] %= MOD;
}

void build(int id, int l, int r){
    if ( l == r ){
        st[id][1] = g[l];
        st[id][0] = c[l];
        return;
    }
    int mid = l + r >> 1;
    build(id*2, l, mid);
    build(id*2+1, mid+1, r);
    pushup(id);
}

void update(int id, int l, int r, int u){
    if ( l > u || r < u ) return;
    if ( l == r ) {
        st[id][1] = g[l];
        st[id][0] = c[l];
        return;
    }

    int mid = l + r >> 1;
    if ( u <= mid ) update(id*2, l, mid, u);
    else update(id*2+1, mid+1, r, u);
    pushup(id);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen(simon".inp", "r") ){
        freopen(simon".inp", "r", stdin);
        freopen(simon".out", "w", stdout);
    }

    cin >> n >> k;
    int all = 1;
    for (int i = 1; i <= n; i ++) cin >> g[i], g[i] %= MOD;
    for (int i = 1; i <= n; i ++) cin >> c[i], c[i] %= MOD;
    for (int i = 1; i <= n; i ++){
        all *= ( g[i] + c[i] ) % MOD;
        all %= MOD;
    }
    build(1, 1, n);

    int j, ng, nc, res;
    cin >> q;
    while ( q -- ){
        cin >> j >> ng >> nc;
        ng %= MOD, nc %= MOD;

        all *= Pow((g[j] + c[j])%MOD, MOD-2), all %= MOD;
        g[j] = ng, c[j] = nc;
        all *= (g[j] + c[j]) % MOD, all %= MOD;

        update(1, 1, n, j);

        res = all;
        for (int i = 0; i < k; i ++)
            res -= st[1][i];
        res = ( res % MOD + MOD ) % MOD;
        cout << res << '\n';
    }

    return 0;
}
