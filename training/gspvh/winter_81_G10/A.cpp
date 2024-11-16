#include<bits/stdc++.h>
#define int long long
#define simon "eratosthene"
using namespace std;
const int N = 5e6 + 5;

bool isprime[N];

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen(simon".inp", "r") ){
        freopen(simon".inp", "r", stdin);
        freopen(simon".out", "w", stdout);
    }

    memset(isprime, 1, sizeof isprime);
    int l, r;
    cin >> l >> r;
    for (int i = 2; i * i <= r; i ++)
    for (int j = max(i*i, (l+i-1)/i*i); j <= r; j += i)
        isprime[j-l] = 0;

    if ( l <= 1 ) isprime[1-l] = 0;

    int cnt = 0;
    for (int i = l; i <= r; i ++)
        if ( isprime[i-l] ) cnt ++;

    cout << cnt;

    return 0;
}
