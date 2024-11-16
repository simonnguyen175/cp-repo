#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MOD = 1e9 + 7;
const int base = 31;
const int N = 1e5 + 5;
const ll oo = 1e15;

int n;
string s[N][2];
vector<ll> h[N][2];
ll e[N], f[N][2];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("reverse.inp", "r") ){
        freopen("reverse.inp", "r", stdin);
        freopen("reverse.out", "w", stdout);
    }

    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> e[i];

    for (int i = 1; i <= n; i ++){
        cin >> s[i][0];
        s[i][1] = s[i][0];
        reverse(s[i][1].begin(), s[i][1].end());
    }

    for (int i = 1; i <= n; i ++)
        f[i][0] = f[i][1] = oo;

    // 0 la ko dao
    // 1 la dao
    f[1][0] = 0;
    f[1][1] = e[1];

    for (int i = 2; i <= n; i ++)
    for (int j = 0; j <= 1; j ++)
    for (int k = 0; k <= 1; k ++)
        if ( s[i-1][j] <= s[i][k] )
            f[i][k] = min(f[i][k], f[i-1][j] + k * e[i]);

    ll ans = min(f[n][0], f[n][1]);

    cout << ( ans == oo ? -1 : ans );

    return 0;
}
