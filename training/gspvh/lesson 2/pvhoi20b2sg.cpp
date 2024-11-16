#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MOD = 998244353;
const ll oo = 1e9;

ll n, lim, t, diff;
ll p[15], f[105][100005], g[105][100005], ans = 0;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("pvhoi20b2sg.inp", "r") ){
        freopen("pvhoi20b2sg.inp", "r", stdin);
        freopen("pvhoi20b2sg.out", "w", stdout);
    }

    cin >> n >> lim >> t >> diff;
    for (int i = 1; i <= n; i ++)
        cin >> p[i];

    for (int i = 0; i <= lim * t; i ++) g[0][i] = 1;

    for (int i = 1; i <= t; i ++)
        for (int j = 0; j <= lim * t; j ++){
            f[i][j] = g[i-1][j];
            if ( j > lim ) f[i][j] = ( f[i][j] - g[i-1][j-lim-1] + MOD ) % MOD;
            g[i][j] = ( g[i][j-1] + f[i][j] ) % MOD;
            //cout << i << ' ' << j << ' ' << g[i][j] << '\n';
        }

    sort(p + 1, p + 1 + n);

    for (int mnval = p[1]; mnval <= p[1] + lim * t; mnval ++){
        ll tmp1 = 1, tmp2 = 1, cost;
        for (int i = 1; i <= n; i ++){
            if ( mnval - p[i] + diff >= 0 ){
                cost = g[t][min(mnval - p[i] + diff, lim * t)];
                if ( mnval - p[i] - 1 >= 0 ) cost -= g[t][mnval - p[i] - 1] - MOD;
                ( tmp1 *= cost ) %= MOD;

                cost = g[t][min(mnval - p[i] + diff, lim * t)];
                if ( mnval - p[i] >= 0 ) cost -= g[t][mnval - p[i]] - MOD;
                ( tmp2 *= cost ) %= MOD;
            }else{
                tmp1 = tmp2 = 0;
                break;
            }
        }

        ( ans += tmp1 - tmp2 + MOD ) %= MOD;
    }

    cout << ans;

    return 0;
}
