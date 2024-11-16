#include<bits/stdc++.h>
using namespace std;
const int N = 3e5 + 5;
const int MOD = 998244353;

int n, fact[N], inv[N];

int mul(int a, int b){
    return 1ll * a * b % MOD;
}

int add(int a, int b){
    a += b;
    if ( a >= MOD ) a -= MOD;
    if ( a < 0 ) a += MOD;
    return a;
}

int Pow(int a, int b){
    if ( b == 0 ) return 1;
    int tmp = Pow(a, b/2);
    if ( b % 2 ) return mul(tmp, mul(tmp, a));
    else return mul(tmp, tmp);
}

int C(int n, int k){
    if ( n < k ) return 0;
    if ( k == 0 ) return 1;
    return mul(fact[n], mul(inv[n-k], inv[k]));
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    fact[0] = 1;
    for (int i = 1; i < N; i ++)
        fact[i] = mul(fact[i-1], i);
    inv[N-1] = Pow(fact[N-1], MOD-2);
    for (int i = N-2; i >= 0; i --)
        inv[i] = mul(inv[i+1], i+1);

    cin >> n;
    int ans = fact[n*n];
    for (int i = 1; i <= n*n; i ++){
        int tmp = mul(C(n*n-i, n-1), C(i-1, n-1));
        tmp = mul(tmp, mul(fact[n-1], fact[n-1]));
        tmp = mul(tmp, mul(fact[n*n - 2*n + 1], n*n));
        ans = add(ans, -tmp);
    }

    cout << ans;

    return 0;
}
