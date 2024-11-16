#include<bits/stdc++.h>
#define simon "bsquare"
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
using namespace std;
const int N = 1e7 + 5;
const int MOD = 1e9 + 7;

int n;
int lpf[N], cnt[N];
ll ans = 0;

void sieve(){
    memset(lpf, 0, sizeof lpf);
    for (int i = 2; i * i <= n; i ++)
        if ( !lpf[i] )
            for (int j = i * i; j <= n; j += i)
                if ( !lpf[j] ) lpf[j] = i;
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
    FASTio
    if ( fopen(simon".inp", "r") ){
        freopen(simon".inp", "r", stdin);
        freopen(simon".out", "w", stdout);
    }

    cin >> n;

    sieve();

    for (int i = 1; i <= n; i ++)
        cnt[getmask(i)] ++;

    for (int i = 1; i <= n; i ++)
        ans = ( ans + 1LL * cnt[i] * (cnt[i]-1) / 2 );

    cout << ans;

    return 0;
}
