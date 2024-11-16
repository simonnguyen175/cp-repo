#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
const int N = 5e6 + 5;
const int MOD = 998244353;

ll A, B;
ll lpf[N], di[N];
int d[N];

void sieve(){
    lpf[1] = 0;
    for (int i = 2; i * i < N; i ++) if ( !lpf[i] )
    for (int j = i * i; j < N; j += i) if ( !lpf[j] )
        lpf[j] = i;

    for (int i = 2; i < N; i ++)
        if ( !lpf[i] ) lpf[i] = i;
}

ll add(ll a, ll b){
    a += b;
    if ( a > MOD ) a -= MOD;
    return a;
}

ll mul(ll a, ll b){
    return 1ll * a * b % MOD;
}

ll Pow(ll a, ll b){
    if ( b == 0 ) return 1;
    ll tmp = Pow(a, b/2);
    if ( b % 2 ) return mul(tmp, mul(tmp, a));
    else return mul(tmp, tmp);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("trash.inp", "r") ){
        freopen("trash.inp", "r", stdin);
        freopen("trash.out", "w", stdout);
    }

    sieve();

    cin >> A >> B;

    ll ans = A, cur = A;
    while ( lpf[cur] ){
        int x = lpf[cur];
        if ( !d[x] ){
            ans -= ans / x;
            d[x] = 1;
        }
        while ( lpf[cur] == x ) cur /= x;
    }

    for (int i = 2; i < N; i ++) if ( lpf[i] == i ){
        di[i] = mul(i-1, Pow(i, MOD-2));
    }

    ll res = ans % MOD;
    for (int i = 2; i <= B; i ++){
        cur = i;
        ll tmp = mul(ans, i);

        while ( lpf[cur] ){
            int x = lpf[cur];
            if ( !d[x] ){
                tmp = mul(tmp, di[x]);
            }
            while ( lpf[cur] == x ) cur /= x;
        }

        res = add(res, tmp);
    }

    cout << res;

    return 0;
}
