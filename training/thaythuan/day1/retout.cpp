#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

int n;
ll m;
int a[N];

namespace sub2{
    ll ans;

    ll Pow(int a, int b){
        if ( b == 1 ) return a;
        ll tmp = Pow(a, b/2);
        if ( b % 2 ) return tmp * tmp % MOD * a % MOD;
        else return tmp * tmp % MOD;
    }

    void solve(){
        ans = 1;
        for (int i = 1; i < n; i ++)
            ans = ans * i % MOD;
        ans = Pow(ans, MOD-2);

        //C(m-1, n-1) (m-1)! / (m-n)! (n-1)!

        if ( m-n+1 >= m ) { cout << 0; return; }

        for (ll i = m-n+1; i < m; i ++)
            ans = ans * ( i % MOD ) % MOD;

        cout << ans;
    }
}

namespace sub3{
    ll f[1005][5005];

    void solve(){
        f[0][0] = 1;
        for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= m; j ++) if ( j >= a[i] ){
            ( f[i][j] += ( f[i-1][j-a[i]] + f[i][j-a[i]] ) % MOD ) %= MOD;
        }

        cout << f[n][m];
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n >> m;
    bool ck = 1;
    for (int i = 1; i <= n; i ++){
        cin >> a[i];
        ck &= ( a[i] == 1 );
    }

    if ( n <= 1000 && m <= 5000 ) sub3::solve();
    else sub2::solve();

    return 0;
}
