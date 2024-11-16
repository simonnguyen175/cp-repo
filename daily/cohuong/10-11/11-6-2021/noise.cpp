#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll oo = 1e18;

int n, m, k;
int c[101];
ll f[105][505];

ll Get(int n , int k){
	if ( n % (k + 1) == 0 ){
        ll p = n / (k + 1);
        return ( p * (p + 1) / 2) * ( k + 1 );
    }
    else{
        ll x1 = n / (k + 1);
        ll x2 = x1 + 1;
        ll k2 = n - x1 * (k + 1);
        ll k1 = k + 1 - k2;
        return  k1 * x1 * (x1 + 1) / 2 + k2 * x2 * (x2 + 1) / 2;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    freopen("noise.inp", "r", stdin);
    freopen("noise.out", "w", stdout);

    cin >> n >> m >> k;

    for (int i = 1; i <= n; i ++){
        int pos; cin >> pos;
        c[pos] ++;
    }

    for (int i = 0; i <= m; i ++)
        for (int j = 0; j <= k; j ++)
            f[i][j] = oo;
    f[0][0] = 0;

    for (int i = 0; i <= m; i ++)
    for (int j = 0; j <= k; j ++){
        //cout << i << ' ' << j << ' ' << f[i][j] << '\n';
        for (int t = 0; t <= min(c[i+1], k-j); t ++){
            f[i+1][j+t] = min(f[i+1][j+t], f[i][j] + Get(c[i+1], t));
        }
    }

//    ll ans = oo;
//    for (int i = 0; i <= k; i ++)
//        ans = min(ans, f[m][i]);
//
//    cout << ans;
     cout << f[m][k];
    return 0;
}
