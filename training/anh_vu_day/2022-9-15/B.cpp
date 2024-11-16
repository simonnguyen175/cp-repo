#include<bits/stdc++.h>
using namespace std;

int n;
string x, y[35];
bitset<255> dp[35][25][255], del[255];
int f[255];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("trash.inp", "r") ){
        freopen("trash.inp", "r", stdin);
        freopen("trash.out", "w", stdout);
    }

    cin >> x >> n;
    int mxl = 0;
    for (int i = 1; i <= n; i ++){
        cin >> y[i];
        mxl = max(mxl, (int)y[i].size());
    }

    for (int i = 0; i < x.size(); i ++)
    for (int j = 1; j <= n; j ++){
        if ( y[j][0] == x[i] ) dp[j][1][i][i] = 1;
        if ( y[j].size() == 1 && y[j][0] == x[i] )
            del[i][i] = 1;
    }

    for (int i = x.size()-1; i >= 0; i --)
    for (int k = 1; k <= n; k ++)
    for (int l = 0; l <= y[k].size(); l ++)
    for (int j = i; j < x.size(); j ++) if ( dp[k][l][i][j] ){
        /// dp -> dp
        dp[k][l][i] |= del[j+1];

        if ( j < x.size()-1 && l < y[k].size() && y[k][l] == x[j+1] )
            dp[k][l+1][i][j+1] = 1;

        /// dp -> del
        del[i] |= dp[k][y[k].size()][i];
    }

    for (int i = 0; i < x.size(); i ++) f[i] = x.size();

    f[0] = !del[0][0];
    for (int i = 1; i < x.size(); i ++){
        f[i] = f[i-1] + 1;
        if ( del[0][i] ) f[i] = 0;
        for (int j = i-1; j >= 0; j --)
            if ( del[j+1][i] )
                f[i] = min(f[i], f[j]);
    }

    cout << f[x.size()-1];

    return 0;
}
