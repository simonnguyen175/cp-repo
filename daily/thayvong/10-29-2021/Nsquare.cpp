#include<bits/stdc++.h>
#define simon "Nsquare"
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
using namespace std;
const int MOD = 1e9 + 7;

ll n;
ll ans = 0;

int main(){
    FASTio
    if ( fopen(simon".inp", "r") ){
        freopen(simon".inp", "r", stdin);
        freopen(simon".out", "w", stdout);
    }

    cin >> n;
    for (ll i = 1; i <= sqrt(n); i ++){
        ans = ( ans + ( n - i * i ) / ( 2 * i ) + 1 ) % MOD;
    }
    cout << ans;

    return 0;
}
