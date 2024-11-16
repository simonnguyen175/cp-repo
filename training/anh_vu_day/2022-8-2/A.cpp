#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MOD = 1e9 + 7;

int k, d;
ll A, B;
int ca[20], cb[20], inv[20];
int f[21][1035][2][2], g[1035];

int add(int a, int b){
    a += b;
    if ( a >= MOD ) a -= MOD;
    if ( a < 0 ) a += MOD;
    return a;
}

int mul(int a, int b){
    return 1LL * a * b % MOD;
}

int Pow(int a, int b){
    if ( b == 1 ) return a;
    int tmp = Pow(a, b/2);
    if ( b % 2 ) return mul(tmp, mul(tmp, a));
    else return mul(tmp, tmp);
}

int C(int n, int k){
    if ( k == 0 ) return 1;
    if ( n < k ) return 0;
    int res = inv[k];
    for (int i = 0; i < k; i ++) res = mul(res, n-i);
    return res;
}

void solve(){
    cin >> A >> B >> k >> d;
    for (int i = 19; i >= 1; i --) ca[i] = A % 10, A /= 10;
    for (int i = 19; i >= 1; i --) cb[i] = B % 10, B /= 10;

    // f[i][t][cka][ckb] bao nhieu so co dung mask = t >= A, <= B

    memset(f, 0, sizeof f);
    memset(g, 0, sizeof g);

    f[0][0][0][0] = 1;
    bool ck0 = 0;
    for (int i = 0; i <= 19; i ++)
    for (int t = 0; t < (1<<10); t ++)
    for (int cka = 0; cka <= 1; cka ++)
    for (int ckb = 0; ckb <= 1; ckb ++) if ( f[i][t][cka][ckb] ){
        if ( i == 19 ){
            g[t] = add(g[t], f[i][t][cka][ckb]);
            continue;
        }

        int lo = ( cka ? 0 : ca[i+1] ), hi = ( ckb ? 9 : cb[i+1]);

        for (int c = lo; c <= hi; c ++){
            int ncka = cka, nckb = ckb, nt = t;

            if ( c > ca[i+1] ) ncka |= 1;
            if ( c < cb[i+1] ) nckb |= 1;
            if ( cka || ck0 || c ) nt |= (1<<c);
            if ( ca[i+1] ) ck0 = 1;

            f[i+1][nt][ncka][nckb] = add(f[i+1][nt][ncka][nckb], f[i][t][cka][ckb]);
        }
    }

    for (int t = 0; t < (1<<10); t ++)
    for (int k = t+1; k < (1<<10); k ++) if ( (t&k) == t )
        g[t] = add(g[t], g[k]);

    for (int t = 0; t < (1<<10); t ++)
        g[t] = C(g[t], k);

//    for (int t = 0; t < (1<<10); t ++)
//        cout << t << " : " << g[t] << '\n';

    int ans = 0;
    for (int t = 0; t < (1<<10); t ++) if ( __builtin_popcount(t) == d )
    for (int k = t; k < (1<<10); k ++) if ( (t&k) == t )
        if ( ( __builtin_popcount(k) - d ) % 2 ) ans = add(ans, -g[k]);
        else ans = add(ans, g[k]);

    cout << ans << '\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int tmp = 1;
    for (int i = 1; i <= 10; i ++) tmp = mul(tmp, i);
    inv[10] = Pow(tmp, MOD-2);
    for (int i = 9; i >= 0; i --)
        inv[i] = mul(inv[i+1], i+1);

    int T;
    cin >> T;
    while ( T -- )
        solve();

    return 0;
}
