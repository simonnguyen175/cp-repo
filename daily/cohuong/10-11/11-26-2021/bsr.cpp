#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5e2 + 5;

int m, n;
ll a[N][N], sc[N][N], d[10], ans = 0;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("bsr.inp", "r") ){
        freopen("bsr.inp", "r", stdin);
        freopen("bsr.out", "w", stdout);
    }

    cin >> m >> n;
    for (int i = 1; i <= m; i ++)
    for (int j = 1; j <= n; j ++){
        cin >> a[i][j];
        sc[i][j] = sc[i-1][j] + a[i][j];
    }

    //cout << '\n';
    for (int len = 1; len <= m; len ++){
    //cout << len << " : \n";
    for (int i = len; i <= m; i ++){
        ll s = 0; memset(d, 0, sizeof d);
        d[0] = 1;
        for (int j = 1; j <= n; j ++){
            ( s += sc[i][j] - sc[i-len][j] ) %= 9;
            //cout << s << ' ' << d[s] << '\n';
            ans += d[s];
            d[s] ++;
        }
    }
    }

    cout << ans;

    return 0;
}
