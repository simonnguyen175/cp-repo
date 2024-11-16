#include<bits/stdc++.h>
#define BIT(x,k) ((x>>k)&1)
#define ll long long
using namespace std;
const int N = 2e6 + 5;
const int MOD = 1e9 + 7;

int n, m, q;
int f[N], pw2[N];

int add(int a, int b){
    a += b;
    if ( a >= MOD ) a -= MOD;
    if ( a < 0 ) a += MOD;
    return a;
}

int mul(int a, int b){
    return 1LL * a * b % MOD;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("trash.inp", "r") ){
        freopen("trash.inp", "r", stdin);
        freopen("trash.out", "w", stdout);
    }

    cin >> n >> m;
    for (int i = 1; i <= n; i ++){
        int k, t = 0;
        cin >> k;
        for (int j = 1, x; j <= k; j ++)
            cin >> x, t |= 1<<(x-1);
        f[t] ++;
    }

    pw2[0] = 1;
    for (int i = 1; i <= n; i ++) pw2[i] = mul(pw2[i-1], 2);

    for (int i = 0; i < m; i ++)
    for (int j = 0; j < (1<<m); j ++) if ( BIT(j, i) )
        f[j] = add(f[j], f[j^(1<<i)]);

    for (int i = 0; i < (1<<m); i ++)
        f[i] = add(pw2[f[i]], -1);

    for (int i = 0; i < m; i ++)
    for (int j = 0; j < (1<<m); j ++) if ( BIT(j, i) )
        f[j] = add(f[j], -f[j^(1<<i)]);

    cin >> q;
    for (int i = 1; i <= q; i ++){
        int k, t = 0;
        cin >> k;
        for (int j = 1, x; j <= k; j ++)
            cin >> x, t |= 1<<(x-1);
        cout << f[t] << '\n';
    }

    return 0;
}
