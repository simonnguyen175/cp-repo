#include<bits/stdc++.h>
using namespace std;
const int oo = 1e9;

string s;
int k, n;
int c[130][130], dp[101][101][130];

int main(){
    ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    freopen("strbeauty.inp", "r", stdin);
    freopen("strbeauty.out", "w", stdout);
    cin >> s >> k;
    cin >> n;
    memset(c, 0, sizeof c);
    for (int i = 1; i <= n; i ++){
        char x, y; int z;
        cin >> x >> y >> z;
        c[y][x] = z;
    }

    int m = s.size();
    s = ' ' + s;

    for (int i = 1; i <= m; i ++)
        for (int j = 1; j <= k; j ++)
            for (char t = 'a'; t <= 'z'; t ++)
                dp[i][j][t] = -oo;

    for (int i = 1; i <= m; i ++)
        dp[i][0][s[i]] = dp[i-1][0][s[i-1]] + c[s[i]][s[i-1]];
    for (char i = 'a'; i <= 'z'; i ++)
        if ( i == s[1] ) continue;
        else dp[1][1][i] = 0;

    // dp[i][j][k] la do dep lon nhat neu den ki tu i bien doi
    // j lan va bien doi ki tu i thanh ki tu k

    for (int i = 2; i <= m; i ++)                       // xet den ki tu s[i]
    for (int j = 1; j <= min(i, k); j ++){               // da bien doi j lan
        //cout << i << ' ' << j << " : " << '\n';
        for (char tr = 'a'; tr <= 'z'; tr ++)           // s[i] - > k
        for (char tl = 'a'; tl <= 'z'; tl ++){          // s[i-1] - > t
            //cout << "s[" << i  << "] to " << tr << " & " << "s[" << i - 1  << "] to " << tl << " -> ";
            if ( tr == s[i] ){
                if ( j == i ) continue;
                if ( tl == s[i-1] ){
                    if ( j <= i - 2 )
                        dp[i][j][tr] = max(dp[i][j][tr], dp[i-1][j][tl] + c[tr][tl]);
                }
                else
                    dp[i][j][tr] = max(dp[i][j][tr], dp[i-1][j][tl] + c[tr][tl]);
            }
            else{
                if ( j == 1 ){
                    dp[i][j][tr] = max(dp[i][j][tr], dp[i-1][j-1][s[i-1]] + c[tr][s[i-1]]);
                    continue;
                }

                if ( tl == s[i-1] ){
                    if ( j <= i - 1 )
                        dp[i][j][tr] = max(dp[i][j][tr], dp[i-1][j-1][tl] + c[tr][tl]);
                }
                else{
                    dp[i][j][tr] = max(dp[i][j][tr], dp[i-1][j-1][tl] + c[tr][tl]);
                }
            }
            //cout << dp[i][j][tr] << '\n';
        }
    }

    int ans = dp[m][0][s[m]];
    for (int i = 1; i <= k; i ++)
        for (char k = 'a'; k <= 'z'; k ++){
            if ( k == s[m] ){
                if ( i == m ) continue;
                ans = max(ans, dp[m][i][k]);
            }
            else
                ans = max(ans, dp[m][i][k]);
        }

    cout << ans;
    return 0;
}
