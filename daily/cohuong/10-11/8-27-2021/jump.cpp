#include<bits/stdc++.h>
#define simon "jump"
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
using namespace std;
const int N = 4e3 + 100;
const ll MOD = 1e9 + 7;

int m, n, k;
ll a[N], b[N];

namespace sub3{
    ll f[N][N];

    void solve(){
        f[1][1] = 1;
        for (int i = 1; i <= m; i ++)
            for (int j = 1; j <= n; j ++){
                ll d = 1 + (a[i] + b[j]) % k;
                for (int x = i + 1; x <= i + d; x ++) (f[x][j]+=f[i][j])%=MOD;
                for (int y = j + 1; y <= j + d; y ++) (f[i][y]+=f[i][j])%=MOD;
            }
        cout << f[m][n] << '\n';
    }
}

namespace sub5{
    ll f[N][N], col[N][N], row[N][N];

    void solve(){
        row[1][1] = 1; row[1][2] = (-1 + MOD) % MOD;

        for (int i = 1; i <= m; i ++)
            for (int j = 1; j <= n; j ++){
            row[i][j] =  (row[i][j] + row[i][j - 1]) % MOD;
            col[j][i] =  (col[j][i] + col[j][i - 1]) % MOD;
            f[i][j] = (col[j][i] + row[i][j]) % MOD;

            ll d = i + (a[i] + b[j]) % k + 2;
            ll r = j +  (a[i] + b[j]) % k + 2;
            if ( d > m ) d = m + 1; if ( r > n ) r = n + 1;

            row[i][j+1]  = (row[i][j+1] + f[i][j]);
            row[i][r] = (row[i][r] - f[i][j] + MOD);

            col[j][i+1] = (col[j][i+1] + f[i][j]);
            col[j][d] = (col[j][d] - f[i][j] + MOD);
        }

        cout << f[m][n] << '\n';
    }
}

int main(){
    FASTio
    if ( fopen(simon".inp", "r") ){
        freopen(simon".inp", "r", stdin);
        freopen(simon".out", "w", stdout);
    }

    cin >> m >> n >> k;
    for (int i = 1; i <= m; i ++) cin >> a[i];
    for (int i = 1; i <= n; i ++) cin >> b[i];

    //if ( k <= 10 ) sub3::solve();
    //else
    sub5::solve();

    return 0;
}
