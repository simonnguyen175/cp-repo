#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll MOD = 1e9 + 7;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("pergraph.inp", "r") ){
        freopen("pergraph.inp", "r", stdin);
        freopen("pergraph.out", "w", stdout);
    }

    int n;
    cin >> n;
    ll ans = 1, tmp = 1;
    for (int i = 1; i <= n - 1; i ++){
        ( ans *= i ) %= MOD;
        ( tmp *= 2 ) %= MOD;
    }
    ans *= n;
    ans = ( ans - tmp + MOD * MOD ) % MOD;
    cout << ans;
    return 0;
}
