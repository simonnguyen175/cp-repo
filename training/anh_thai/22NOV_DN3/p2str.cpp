#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5e3 + 5;

string s;
int n;
int f[N][N], pal[N][N], cpal[N][N];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> s;
    n = s.size();
    s = ' ' + s;

    for (int i = 1; i <= n; i ++)
    for (int j = i + 1; j <= n; j ++)
        if ( s[i] == s[j] ) f[i][j] = 1;

    for (int i = 1; i <= n; i ++)
    for (int j = n; j >= i; j --)
        if ( s[i] == s[j] ) f[i][j] = f[i-1][j+1] + 1;

    for (int i = 1; i <= n; i ++)
        pal[i][i] = pal[i][i-1] = 1;
    for (int i = n; i >= 1; i --)
    for (int j = i+1; j <= n; j ++) if ( s[i] == s[j] )
        pal[i][j] = pal[i+1][j-1];

    for (int i = 1; i <= n; i ++) cpal[i][i] = 1;
    for (int i = 1; i <= n; i ++)
    for (int j = i + 1; j <= n; j ++)
        cpal[i][j] = cpal[i][j-1] + pal[i][j];
    for (int i = 1; i <= n; i ++)
    for (int j = i-1; j >= 1; j --)
        cpal[i][j] = cpal[i][j+1] + pal[j][i];

    ll ans = 0;
    for (int i = 1; i < n; i ++)
    for (int j = i+1; j <= n; j ++){
        ans += f[i][j];
        if ( i + 1 < j )
            ans += 1ll * f[i][j] * ( cpal[i+1][j-1] + cpal[j-1][i+1] );
    }

    cout << ans;

    return 0;
}

/*
    hwhwh
*/
