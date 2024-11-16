#include<bits/stdc++.h>
#define simon "gameshow"
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
using namespace std;
const int N = 5e3 + 5;

int n, t;
ll a[N], f[N][N];

int main(){
    FASTio
    if ( fopen(simon".inp", "r") ){
        freopen(simon".inp", "r", stdin);
        freopen(simon".out", "w", stdout);
    }

    cin >> n >> t;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];

    for (int i = 1; i <= n; i ++)
        for (int j = 0; j <= n; j ++)
            f[i][j] = -1;

    f[0][0] = 0;
    for (int i = 1; i < n; i ++)
    for (int j = 1; j < n; j ++){
        if ( f[i-1][j] >= 0 ){
            if ( f[i-1][j-1] < 0 || j == 0 ) f[i][j] = f[i-1][j] - t;
            else f[i][j] = max(f[i-1][j] - t, f[i-1][j-1] + a[i]);
        }
        else
            if ( f[i-1][j-1] >= 0 && j > 0 ) f[i][j] = f[i-1][j-1] + a[i];
    }

    for (int i = 0; i <= n - 1; i ++)
        if ( f[n-1][i] > 0 && f[n-1][i] + a[n] > 0 ){
            cout <<  i + 1;
            return 0;
        }

    cout << -1;

    return 0;
}
