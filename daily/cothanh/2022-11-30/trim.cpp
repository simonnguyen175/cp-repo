#include<bits/stdc++.h>
using namespace std;
const int N = 4e3 + 5;

string a, b, t, s;
int f[N][N], g[N][N], p[2*N];
int n, ans = 0;

void solve(){
    for (int i = 0; i <= a.size()+1; i ++)
    for (int j = 0; j <= b.size()+1; j ++)
        f[i][j] = g[i][j] = 0;

    t = b;
    int pos = 1;
    while ( t.size() ){
        s = t + '#' + a;

        // kmp
        n = s.size();
        s = ' ' + s;

        int k = 0;
        for (int i = 1; i <= n; i ++) p[i] = 0;
        for (int i = 2; i <= n; i ++){
            while ( k && s[k+1] != s[i] ) k = p[k];
            if ( s[k+1] == s[i] ) k ++;
            p[i] = k;
        }

        for (int i = 1; i <= a.size(); i ++)
            f[i][pos] = p[t.size()+1+i];

        t.erase(0, 1);
        pos ++;
    }

    t = a;
    pos = 1;
    while ( t.size() ){
        s = t + '#' + b;

        // kmp
        n = s.size();
        s = ' ' + s;
        int k = 0;
        for (int i = 1; i <= n; i ++) p[i] = 0;
        for (int i = 2; i <= n; i ++){
            while ( k && s[k+1] != s[i] ) k = p[k];
            if ( s[k+1] == s[i] ) k ++;
            p[i] = k;
        }

        for (int i = 1; i <= b.size(); i ++)
            g[pos][i] = p[t.size()+1+i];

        t.erase(0, 1);
        pos ++;
    }

    for (int i = 1; i <= a.size(); i ++)
    for (int j = 1; j <= b.size(); j ++)
        ans = max(ans, f[i][j] + g[i+1][j-1]);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    freopen("trim.in", "r", stdin);
    freopen("trim.out", "w", stdout);

    cin >> a >> b;

    solve();

    reverse(b.begin(), b.end());

    solve();

    cout << ans;

    return 0;
}
