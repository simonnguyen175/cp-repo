#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

int n;
ll b[N], fact[2*N], inv[2*N];

ll Pow(ll a, ll b){
    if ( b == 1 ) return a;
    ll tmp = Pow(a, b/2);
    if ( b % 2 ) return tmp * tmp % MOD * a % MOD;
    else return tmp * tmp % MOD;
}

ll C(ll n, ll k){
    if ( k == 0 ) return 1;
    return fact[n] * inv[k] % MOD * inv[n-k] % MOD;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("lisys.inp", "r") ){
        freopen("lisys.inp", "r", stdin);
        freopen("lisys.out", "w", stdout);
    }

    cin >> n;
    ll sum = 0;
    int cnt = 0;
    for (int i = 1; i <= n; i ++){
        cin >> b[i];
        if ( b[i] != -1 ) sum += b[i];
        else cnt ++;
    }

    if ( sum > 2*(n-1) ) { cout << 0; return 0; }
    if ( sum == 2*(n-1) && cnt == 0 ) { cout << 1; return 0; }
    if ( sum < 2*(n-1) && cnt == 0 ) { cout << 0; return 0; }

    sum = 2*(n-1) - sum;

    fact[0] = 1;
    for (int i = 1; i < N; i ++)
        fact[i] = fact[i-1] * i % MOD;

    inv[N-1] = Pow(fact[N-1], MOD-2);
    for (int i = N-2; i >= 0; i --)
        inv[i] = inv[i+1] * (i+1) % MOD;

    cout << C(sum-1, cnt-1);

    return 0;
}
