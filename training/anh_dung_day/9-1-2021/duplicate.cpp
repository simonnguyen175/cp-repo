#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5e2 + 5;
const int MOD = 1e9 + 7;

int n;
string s;
ll fact[N], inv[N], f[N][N];

ll Pow(int a, int b){
    if ( b == 1 ) return a;
    ll tmp = Pow(a, b/2);
    if ( b % 2 ) return tmp * tmp % MOD * a % MOD;
    else return tmp * tmp % MOD;
}

ll C(int n, int k){
    if ( k == 0 ) return 1;
    if ( k > n ) return 0;
    return fact[n] * inv[n-k] % MOD * inv[k] % MOD;
}

ll calc(int l, int r){
    if ( ( r - l + 1 ) % 2 ) return 0;
    if ( f[l][r] != -1 ) return f[l][r];
    if ( l > r ) return 1;

    ll res = 0;
    for (int mid = l + 1; mid < r; mid ++)
        if ( s[l] == s[mid] ){
            int l1 = (mid - l + 1) / 2, l2 = (r - l + 1) / 2;
            res = ( res + C(l2, l1) % MOD * calc(l + 1, mid - 1) % MOD * calc(mid + 1, r) % MOD ) % MOD;
        }

    if ( s[l] == s[r] ) res = ( res + calc(l+1, r-1) ) % MOD;

    f[l][r] = res;

    return res;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    fact[0] = 1;
    for (int i = 1; i < N; i ++)
        fact[i] = fact[i-1] * i % MOD;

    inv[N-1] = Pow(fact[N-1], MOD-2);
    for (int i = N - 2; i >= 1; i --)
        inv[i] = inv[i+1] * (i+1) % MOD;

    cin >> s;
    n = s.size(); s = ' ' + s;
    memset(f, -1, sizeof f);
    cout << calc(1, n);
    return 0;
}
