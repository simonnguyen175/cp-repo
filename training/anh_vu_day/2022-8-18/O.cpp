#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5e2 + 5;
const ll oo = 1e18;

int test;
int n;
string s[N];
ll d[25][N][N];

void solve(){
    cin >> s[2] >> n;

    for (int len = 1; len <= 20; len ++)
    for (int i = 1; i <= 2*n+2; i ++)
    for (int j = 1; j <= 2*n+2; j ++) if ( i != j )
        d[len][i][j] = oo;


    for (int i = 1, j = 3; i <= n; i ++, j += 2){
        cin >> s[j] >> s[j+1];
        d[s[j].size()][j][j+1] = 1;
    }

    n = 2*n+2;
    for (int i = 1; i <= n; i ++)
        reverse(s[i].begin(), s[i].end());

//    for (int i = 1; i <= n; i ++)
//        cout << s[i] << '\n';

    for (int len = 1; len <= 20; len ++){
//        cout << len << ":\n";

        for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= n; j ++)
        if ( s[i].size() >= len && s[j].size() >= len && s[i][len-1] == s[j][len-1] ){
//            cout << s[i] << "-> " << s[j] << '\n';
            d[len][i][j] = min(d[len][i][j], d[len-1][i][j]);
        }

        for (int k = 1; k <= n; k ++) if ( s[k].size() >= len )
        for (int i = 1; i <= n; i ++) if ( s[i].size() >= len )
        for (int j = 1; j <= n; j ++) if ( s[j].size() >= len && d[len][i][j] > d[len][i][k] + d[len][k][j] ){
//            cout << i << "->" << k << "->" << j << '\n';
            d[len][i][j] = d[len][i][k] + d[len][k][j];
        }
    }

    ll ans = d[s[1].size()][1][2];
    cout << "Case " << test << ": ";
    if ( ans == oo ) cout << "No solution\n";
    else cout << ans << '\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("trash.inp", "r") ){
        freopen("trash.inp", "r", stdin);
        freopen("trash.out", "w", stdout);
    }

    while ( cin >> s[1] ){
        test ++;
        if ( s[1] == "." ) break;
        solve();
    }

    return 0;
}
