#include<bits/stdc++.h>
#define int long long
using namespace std;

int n, A, B, C, D;

namespace sub1{
    void solve(){
        int ans = 0;

        for (int i = 1; i <= D; i ++)
        for (int j = 1; j <= D; j ++){
            int g = __gcd(i, j);
            int l = i * j / g;
            if ( g >= A && g <= B && l >= C && l <= D )
                ans ++;
        }

        cout << ans;
    }
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    freopen("lucky.inp", "r", stdin);
    freopen("lucky.out", "w", stdout);

    cin >> n;
    cin >> A >> B >> C >> D;

    if ( n == 2 && D <= 1e3 ) sub1::solve();

    return 0;
}
