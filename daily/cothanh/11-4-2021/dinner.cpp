#include<bits/stdc++.h>
#define simon "dinner"
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

int t, n;
ll f[N];

int main(){
    FASTio
    if ( fopen(simon".in", "r") ){
        freopen(simon".in", "r", stdin);
        freopen(simon".ok", "w", stdout);
    }

    cin >> t;
    while ( t -- ){
        cin >> n;
        for (int i = 1; i <= n; i ++) f[i] = 0;
        f[1] = 1;
        for (int i = 1; i < n; i ++){
            ( f[i+1] += f[i] ) %= MOD;
            ( f[i+2] += f[i] * ( n - i - 1) % MOD ) % MOD;
        }
        cout << f[n] << '\n';
    }
    return 0;
}
