#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
const int MOD = 1e9 + 7;

int n, m;
int fact[N], inv[N];

int mul(int a, int b){
    return 1LL * a * b % MOD;
}

int add(int a, int b){
    a += b;
    if ( a >= MOD ) a -= MOD;
    if ( a < 0 ) a += MOD;
    return a;
}

int A(int n, int k){
    if ( k == 0 ) return 1;
    return mul(fact[n], inv[n-k]);
}

int C(int n, int k){
    if ( k == 0 ) return 1;
    return mul(fact[n], mul(inv[k], inv[n-k]));
}

int Pow(int a, int b){
    if ( b == 0 ) return 1;
    int tmp = Pow(a, b/2);
    if ( b % 2 ) return mul(tmp, mul(tmp, a));
    else return mul(tmp, tmp);
}

void solve(){
    cin >> n >> m;
    n *= 2;

    int ans = fact[n];

    for (int i = 1; i <= m; i ++){
        int rem = n - 2*i;

        int tmp = mul(A(m, i), Pow(2, i));

        tmp = mul(tmp, mul(C(rem+i, i), fact[rem]));

        if ( i % 2 ) ans = add(ans, -tmp);
        else ans = add(ans, tmp);
    }

    cout << ans << '\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("trash.inp", "r") ){
        freopen("trash.inp", "r", stdin);
        freopen("trash.out", "w", stdout);
    }

    fact[0] = 1;
    for (int i = 1; i < N; i ++)
        fact[i] = mul(fact[i-1], i);
    inv[N-1] = Pow(fact[N-1], MOD-2);
    for (int i = N-2; i >= 0; i --)
        inv[i] = mul(inv[i+1], i+1);

    int test;
    cin >> test;
    while ( test -- )
        solve();

    return 0;
}
