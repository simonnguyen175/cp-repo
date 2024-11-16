#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5e4 + 5;
const int MOD = 1234567;

int k, n;
int a[N];
ll f[N][1030], ans = 0;

int add(int a, int b){
    a += b;
    if ( a >= MOD ) a -= b;
    return a;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("kstr.inp", "r") ){
        freopen("kstr.inp", "r", stdin);
        freopen("kstr.out", "w", stdout);
    }

    cin >> k >> n;
    for (int i = 1; i <= n; i ++){
        int t, x;
        cin >> t;
        for (int j = 1; j <= t; j ++){
            cin >> x; a[i] |= (1<<x);
        }
    }

    f[n+1][0] = 1;

    for (int i = n + 1; i >= 1; i --)
    for (int msk = 0; msk < 1024; msk ++) if ( f[i][msk] ){
        f[i-1][msk] = add(f[i-1][msk], f[i][msk]);
        int nmsk = ( a[i-1] ^ msk ) & a[i-1];
        f[i-1][nmsk] = add(f[i-1][nmsk], f[i][msk]);
    }

    for (int msk = 0; msk < 1024; msk ++)
        if ( __builtin_popcount(msk) >= k )
            ans = add(ans, f[1][msk]);

    cout << ans;

    return 0;
}
