#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e3 + 5;
const int oo = 1e18;

int n;
int x[N], dp[N][N][2];

void ckmn(int &a, int b){
    a = min(a, b);
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    freopen("hdd.inp", "r", stdin);
    freopen("hdd.out", "w", stdout);

    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> x[i];
    x[++n] = 0;
    sort(x + 1, x + 1 + n);
    for (int i = 1; i <= n; i ++)
    for (int j = 1; j <= n; j ++)
        dp[i][j][0] = dp[i][j][1] = oo;

    for (int i = 1; i <= n; i ++) if ( x[i] == 0 )
        dp[i][i][0] = dp[i][i][1] = 0;

    for (int len = 1; len < n; len ++)
    for (int i = 1; i <= n; i ++){
        int j = i + len - 1;
        int w = n - (j-i+1);

        if ( i > 1 ){
            ckmn(dp[i-1][j][0], dp[i][j][0] + w * (x[i]-x[i-1]));
            ckmn(dp[i-1][j][0], dp[i][j][1] + w * (x[j]-x[i-1]));
        }

        if ( j < n ){
            ckmn(dp[i][j+1][1], dp[i][j][0] + w * (x[j+1]-x[i]));
            ckmn(dp[i][j+1][1], dp[i][j][1] + w * (x[j+1]-x[j]));
        }
    }

    cout << min(dp[1][n][0], dp[1][n][1]);

//    int i = 1, j = n, t = 0;
//    if ( dp[1][n][0] > dp[1][n][1] ) t = 1;
//
//    cout << dp[i][j][t];

//    vector<int> ans;
//    while ( i != j ){
//        int w = n - (j-i);
//
//        if ( t == 0 ){
//            ans.push_back(i);
//            if ( dp[i][j][0] == dp[i+1][j][0] + w * (x[i+1]-x[i]) ) i ++;
//            else i ++, t = 1;
//        }
//        else{
//            ans.push_back(j);
//            if ( dp[i][j][1] == dp[i][j-1][1] + w * (x[j]-x[j-1]) ) j --;
//            else j --, t = 0;
//        }
//    }
//
//    reverse(ans.begin(), ans.end());
//    for (int it : ans) cout << x[it] << '\n';

    return 0;
}
