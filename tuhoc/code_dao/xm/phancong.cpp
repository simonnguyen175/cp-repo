#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    freopen("phancong.inp", "r", stdin);
    freopen("phancong.out", "w", stdout);

    int a[4][4];
    for (int i = 1; i <= 3; i ++)
        cin >> a[i][1] >> a[i][2] >> a[i][3];

    int ans = INT_MAX;
    for (int i = 1; i <= 3; i ++)
    for (int j = 1; j <= 3; j ++) if ( j != i )
    for (int k = 1; k <= 3; k ++) if ( k != j && k != i ){
        ans = min(ans, max({a[1][i], a[2][j], a[3][k]}));
    }

    cout << ans;

    return 0;
}
