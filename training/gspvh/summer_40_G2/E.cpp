#include<bits/stdc++.h>
using namespace std;

ll Pow(ll a, ll b){}

void sieve(){
    memset(isPrime, 1, sizeof isPrime);
    isPrime[1] = 0;
    for (int i = 1; i*i <= N-5; i ++) if ( isPrime[i] )
    for (int j = i*i; j <= N-5; j ++)
        isPrime[j] = 0;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n;

    for (int i = 1; i * i <= n; i ++) if ( n % i == 0 ){
        int cnt = 0;
        while ( n % i == 0 ){
            n /= i;
            cnt ++;
        }
        pf.pb({i, cnt});
    }

    sieve();
    for (int i = 1; i <= N-5; i ++) if ( isPrime[i] )
        prime.pb(i);

    memset(f, -1, sizeof f);

    rec(0, k);

    cout << f[k];

    return 0;
}
