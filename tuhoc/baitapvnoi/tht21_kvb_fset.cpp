#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;

int n, mod;
int lpf[N], cnt[N];

void sieve(){
    memset(lpf, 0, sizeof lpf);
    for (int i = 2; i * i<= n; i ++)
        if ( !lpf[i] ){
            for (int j = i * i; j <= n; j += i)
                if ( !lpf[j] ) lpf[j] = i;
        }
    for (int i = 2; i <= n; i ++)
        if ( !lpf[i] ) lpf[i] = i;
}

int getmask(int x){
    int mask = 1;
    while ( x != 1 ){
        int p = lpf[x], dem = 0;
        do x /= p, dem ++; while ( p == lpf[x] );
        if ( dem & 1 ) mask *= p;
    }
    return mask;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> mod;
    sieve();
    for (int i = 1; i <= n; i ++)
        cnt[getmask(i)] ++;

    long long ans = 1;
    for (int i = 1; i <= n; i ++)
        ans = ( ans * ( cnt[i] + 1 ) ) % mod;

    cout << ans;

    return 0;
}
