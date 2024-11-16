#include<bits/stdc++.h>
using namespace std;

string a, b;
int dp[1005][1005], pos[1005][1005];

int main(){
    cin >> a >> b;
    int na = a.size(), nb = b.size();
    a = ' ' + a; b = ' ' + b;

    for (int i = 1; i <= nb; i ++)
        for (char j = 'a'; j <= 'z'; j ++)
            if ( b[i] == j ) pos[j][i] = i;
            else pos[j][i] = pos[j][i-1];

    for (int i = 1; i <= na; i ++) dp[i][0] = 1;
    for (int i = 1; i <= nb; i ++) dp[0][i] = 1e9;

    for (int i = 1; i <= na; i ++)
        for (int j = 1; j <= nb; j ++){
//            cout << pos[a[i]][j] << ' ';
            if ( pos[a[i]][j] == 0 ) dp[i][j] = 1;
            else{
                dp[i][j] = min(dp[i-1][j], dp[i-1][pos[a[i]][j]-1] + 1);
            }
//                cout << i << ' ' << j << ' ' << dp[i][j] << '\n';
        }

    cout << dp[na][nb];

    return 0;
}
