#include<bits/stdc++.h>
#define simon "percnt"
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
const int N = 3e3 + 5;
const int MOD = 1e9 + 7;

int n, k;

namespace sub1{
    int a[N];

    void solve(){
        for (int i = 1; i <= n; i ++) a[i] = i;
        int ans = 0;
        do{
            int cnt = 1;
            for (int i = 2; i <= n; i ++)
                if ( a[i] < a[i-1] ) cnt ++;
            if ( cnt == k ) ans ++;
        }while (next_permutation(a + 1, a + 1 + n));
        cout << ans << '\n';
    }
}

namespace sub3{
    long long f[N][N];

    void solve(){
        f[0][0] = 1;

        for (int i = 0; i < n; i ++)
            for (int j = 0; j <= min(i, k-1); j ++){
                ( f[i+1][j] += f[i][j] * (j+1) % MOD ) %= MOD;
                ( f[i+1][j+1] += f[i][j] * (i + 1 - (j + 1)) % MOD ) %= MOD;
            }

        cout << f[n][k-1] << '\n';
    }
}

int main(){
    FASTio
    if ( fopen(simon".inp", "r") ){
        freopen(simon".inp", "r", stdin);
        freopen(simon".out", "w", stdout);
    }

    cin >> n >> k;

    if ( n <= 10 ) sub1::solve();
        else if ( n <= 3000 )sub3::solve();
            else sub4::solve();
    return 0;
}
