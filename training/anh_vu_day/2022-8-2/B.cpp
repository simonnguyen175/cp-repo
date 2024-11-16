#include<bits/stdc++.h>
using namespace std;
const int N = 4e6 + 5;
const int MOD = 1e9 + 7;

int R, W, d;
int fact[N], inv[N];

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
    if ( n < k ) return 0;
    if ( k == 0 ) return 1;
    return mul(fact[n], mul(inv[k], inv[n-k]));
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    fact[0] = 1;
    for (int i = 1; i <= N-5; i ++)
        fact[i] = mul(fact[i-1], i);
    inv[N-5] = Pow(fact[N-5], MOD-2);
    for (int i = N-6; i >= 0; i --)
        inv[i] = mul(inv[i+1], i+1);

    cin >> R >> W >> d;

    int ans = 0;
    for (int i = 0; i <= W+1; i ++){
        if ( 1LL * i * (d+1) + 1 > R + W + 1 ) break;
        int tmp = mul(C(W+1, i), C(R+W+1-i*(d+1) -1, W+1 -1));
        ans = add(ans, tmp * ( i % 2 ? -1 : 1 ));
    }

    cout << ans;

    return 0;
}
