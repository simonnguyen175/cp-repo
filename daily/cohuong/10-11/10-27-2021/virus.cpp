#include<bits/stdc++.h>
#define simon "virus"
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

int q, n, ans;
string s, t;
int f[10005][505];

int lcs(string &a, string &b){
    for (int i = 0; i <= a.size(); i ++)
    for (int j = 0; j <= b.size(); j ++)
        f[i][j] = 0;
    for (int i = 1; i <= a.size(); i ++)
    for (int j = 1; j <= b.size(); j ++){
        f[i][j] = max(f[i-1][j], f[i][j-1]);
        if ( a[i-1] ==  b[j-1] ){
            f[i][j] = max(f[i][j], f[i-1][j-1] + 1);
        }
    }
    return f[a.size()][b.size()];
}

void solve(){
    cin >> n >> s;
    ans = 0;
    for (int i = 1; i <= n; i ++){
        cin >> t;
        ans = max(ans, lcs(s, t));
    }
    cout << ans << '\n';
}

int main(){
    FASTio
    if ( fopen(simon".inp", "r") ){
        freopen(simon".inp", "r", stdin);
        freopen(simon".out", "w", stdout);
    }

    cin >> q;
    while ( q -- )
        solve();
    return 0;
}
