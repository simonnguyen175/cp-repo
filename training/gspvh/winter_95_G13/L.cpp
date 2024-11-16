#include<bits/stdc++.h>
#define ull unsigned long long
using namespace std;
const int N = 1e3 + 5;
const ull oo = (ull)9e18 + 7;

int sub, m, n, q;
char a[N][N];
ull k, g[N][N], f[N][N], sway[26];

ull add(ull a, ull b){
    a += b;
    if ( a > oo ) a = oo;
    return a;
}

ull mul(ull a, ull b){
    if ( a == 0 || b == 0 ) return 0;
    return oo / a < b ? oo : a * b;
}

void solve(){
    cin >> k;
    for (int i = 0; i <= m; i ++)
    for (int j = 0; j <= n; j ++) g[i][j] = 0;

    g[1][1] = 1;
    string ans = "";
    ans += a[1][1];
    for (int s = 3; s <= m + n; s ++){
        for (int c = 0; c <= 25; c ++) sway[c] = 0;

        for (int i = max(1, s-n); i <= min(m, s-1); i ++){
            int j = s-i;
            g[i][j] = add(g[i][j], g[i-1][j]);
            g[i][j] = add(g[i][j], g[i][j-1]);
            sway[a[i][j]-'a'] = add(sway[a[i][j]-'a'], mul(g[i][j], f[i][j]));
        }

        for (int c = 0; c <= 25; c ++){
            if ( sway[c] < k ){
                k -= sway[c];
                continue;
            }

            for (int i = max(1, s-n); i <= min(m, s-1); i ++){
                int j = s-i;
                if ( a[i][j]-'a' != c ){
                    g[i][j] = 0;
                }
            }

            ans += (char)(c+'a');
            break;
        }
    }

    cout << ans << '\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("ducvodichworldcup.inp","r") ){
        freopen("ducvodichworldcup.inp", "r", stdin);
        freopen("ducvodichworldcup.out", "w", stdout);
    }

    cin >> sub >> m >> n >> q;
    for (int i = 1; i <= m; i ++)
    for (int j = 1; j <= n; j ++)
        cin >> a[i][j];

    f[m][n] = 1;
    for (int i = m; i >= 1; i --)
    for (int j = n; j >= 1; j --){
        f[i][j] = add(f[i][j], f[i+1][j]);
        f[i][j] = add(f[i][j], f[i][j+1]);
    }

    while ( q -- )
        solve();

    return 0;
}
