#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;

int n;
char a[N][N];
bool down[N][N], rig[N][N];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    freopen("grid.inp", "r", stdin);
    freopen("grid.out", "w", stdout);

    cin >> n;
    for (int i = 1; i <= n; i ++)
    for (int j = 1; j <= n; j ++){
        cin >> a[i][j];
    }

    for (int i = 1; i <= n; i ++){
        if ( a[n][i] == '.' ) down[n][i] = 1;
    }

    for (int i = 1; i <= n; i ++){
        if ( a[i][n] == '.' ) rig[i][n] = 1;
    }

    for (int i = n-1; i >= 1; i --)
    for (int j = 1; j <= n; j ++){
        if ( a[i][j] == 'S' ) down[i][j] = 0;
        else down[i][j] = down[i+1][j];
    }

    for (int j = n-1; j >= 1; j --)
    for (int i = 1; i <= n; i ++){
        if ( a[i][j] == 'S' ) rig[i][j] = 0;
        else rig[i][j] = rig[i][j+1];
    }

    int ans = 0;
    for (int i = 1; i <= n; i ++){
        for (int j = 1; j <= n; j ++){
            if ( down[i][j] && rig[i][j] )
                ans ++;
        }
    }

    cout << ans;

    return 0;
}
