#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll oo = 1e18;

int t, x, a[15], used[15];
long long ans;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("unique.inp", "r") ){
        freopen("unique.inp", "r", stdin);
        freopen("unique.out", "w", stdout);
    }

    cin >> t;

    while ( t -- ){
        cin >> x;
        if ( x == 0 ) { cout << 0 << '\n'; continue; }
        ans = oo;
        for (int t = 1; t <= (1<<9) - 1; t ++){
            ll tmp = 0, tcs = 0;
            for (int i = 1; i <= 9; i ++)
                if ( t&(1<<(i-1)) ) tcs += i, tmp = tmp * 10 + i;
            if ( tcs == x ) ans = min(ans, tmp);
        }
        if ( ans == oo ) cout << -1 << '\n';
        else cout << ans << '\n';
    }

    return 0;
}
