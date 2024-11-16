#include<bits/stdc++.h>
#define simon "palinprime"
#define ll long long
using namespace std;
const int N = 1e7 + 5;

int l, r;
bool isPrime[N];

void sieve(){
    memset(isPrime, 1, sizeof isPrime);
    isPrime[1] = 0;
    for (int i = 2; i * i <= N-5; i ++) if ( isPrime[i] )
        for (int j = i*i; j <= N-5; j += i)
            isPrime[j] = 0;
}

bool check(int x){
    int a = x, b = 0;
    while ( x ){
        b = b * 10 + x%10;
        x /= 10;
    }
    return a == b;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen(simon".inp", "r") ){
        freopen(simon".inp", "r", stdin);
        freopen(simon".out", "w", stdout);
    }

    sieve();

    cin >> l >> r;

    ll ans = 0;
    for (int i = l; i <= r; i ++)
        if ( isPrime[i] && check(i) )
            ans += i;

    cout << ans;

    return 0;
}
