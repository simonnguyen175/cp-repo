#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MOD = 1e9 + 7;

int t;
ll cnt[15], C[100][15], s[100], f[15][100], ans;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    C[0][0] = 1;
    for (int i = 1; i <= 95; i ++){
        C[i][0] = 1;
        for (int j = 1; j <= 10; j ++){
            C[i][j] = ( C[i-1][j] + C[i-1][j-1] ) % MOD;
        }
    }

    ll cur = 1;
    s[0] = 0;
    for (int i = 1; i <= 82; i ++)
        s[i] = ( s[i-1] + cur ) % MOD, cur = cur * 10 % MOD;

    cin >> t;
    while ( t -- ){
        ans = 0;
        for (int i = 1; i <= 9; i ++)
            cin >> cnt[i];

        for (int x = 1; x <= 9; x ++){
            if ( cnt[x] == 0 ) continue;
            memset(f, 0, sizeof f);

            ll tmp = 0;

            f[0][0] = 1;
            for (int i = 0; i <= 9; i ++)
            for (int j = 0; j <= 82; j ++)
            for (int k = 0; k <= ( i + 1 == x ? cnt[x] - 1 : cnt[i+1] ); k ++)
                ( f[i+1][j+k] += C[j+k][k] * f[i][j] % MOD ) %= MOD;

            for (int i = 1; i <= 82; i ++)
                ( ans += s[i] * x * f[9][i-1] ) %= MOD;
        }

        cout << ans << '\n';
    }

    return 0;
}
