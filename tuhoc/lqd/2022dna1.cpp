#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
const int MOD = 20030101;

string s, t;
int n, m;
int f[N][N], g[N][N], ps[N][30], pt[N][30], d[30];

int add(int a, int b){
    a += b;
    if ( a >= MOD ) a -= MOD;
    return a;
}

void solve(){
    cin >> s >> t;
    n = s.size();
    m = t.size();

    s = ' ' + s;
    t = ' ' + t;

    for (int i = 0; i <= n + 1; i ++)
    for (int j = 0; j <= m + 1; j ++)
        f[i][j] = g[i][j] = 0;

    for (int i = 1; i <= n; i ++)
    for (int j = 1; j <= m; j ++){
        f[i][j] = max(f[i-1][j], f[i][j-1]);
        if ( s[i] == t[j] ) f[i][j] = max(f[i][j], f[i-1][j-1] + 1);
        f[n+1][m+1] = max(f[n+1][m+1], f[i][j] + 1);
    }

    for (int i = 0; i <= 25; i ++) d[i] = 0;
    for (int i = 1; i <= n + 1; i ++){
        for (char c = 'a'; c <= 'z'; c ++)
            ps[i][c-'a'] = d[c-'a'];
        d[s[i]-'a'] = i;
    }
    for (int i = 0; i <= 25; i ++) d[i] = 0;
    for (int i = 1; i <= m + 1; i ++){
        for (char c = 'a'; c <= 'z'; c ++)
            pt[i][c-'a'] = d[c-'a'];
        d[t[i]-'a'] = i;
    }

    if ( f[n+1][m+1] == 1 ){
        cout << 0 << ' ' << 0 << '\n';
        return;
    }

    int ans = 0;
    g[n+1][m+1] = 1;
    for (int i = n + 1; i >= 1; i --)
    for (int j = m + 1; j >= 1; j --) if ( g[i][j] ){
        if ( f[i][j] == 1 ) ans = add(ans, g[i][j]);
        for (char c = 'a'; c <= 'z'; c ++){
            int ii = ps[i][c-'a'], jj = pt[j][c-'a'];
            if ( ii && jj && f[ii][jj] + 1 == f[i][j] ){
                g[ii][jj] = add(g[ii][jj], g[i][j]);
            }
        }
    }

    cout << f[n+1][m+1] - 1 << ' ' << ans << '\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int test;
    cin >> test;
    while ( test -- )
        solve();

    return 0;
}
