#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5 + 5;
const int MOD = 1e9 + 7;

int m, n, h1, c1, h2, c2;
ll fact[2*N], inv[2*N];

ll Pow(int a, int b){
    if ( b == 1 ) return a;
    ll tmp = Pow(a, b/2);
    if ( b % 2 ) return tmp * tmp % MOD * a % MOD;
    else return tmp * tmp % MOD;
}

ll C(int n, int k){
    if ( n < k ) return 0;
    if ( n == 0 ) return 0;
    if ( k == 0 ) return 1;
    if ( n == k ) return 1;
    return fact[n] * inv[k] % MOD * inv[n-k] % MOD;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> m >> n >> h1 >> c1 >> h2 >> c2;

    fact[0] = 1;
    for (int i = 1; i <= m + n; i ++)
        fact[i] = fact[i-1] * i % MOD;

    inv[m+n] = Pow(fact[m+n], MOD-2);
    for (int i = m + n - 1; i >= 1; i --)
        inv[i] = inv[i+1] * (i+1) % MOD;

    ll ans = 0;

    for (int i = h2 + 1; i <= m; i ++){
        int a = i, b = c1 - 1;
        int x = m - i + 1, y = n - c1 + 1;
        ans = ( ans + C(a + b - 2, a - 1) * C(x + y - 2, x - 1) ) % MOD;
    }

    for (int i = c2 + 1; i <= n; i ++){
        int a = h1 - 1, b = i;
        int x = n - i + 1, y = m - h1 + 1;
        ans = ( ans + C(a + b - 2, a - 1) * C(x + y - 2, x - 1) ) % MOD;
    }

    cout << ans;

    return 0;
}
