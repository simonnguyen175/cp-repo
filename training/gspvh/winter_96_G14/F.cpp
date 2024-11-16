#include<bits/stdc++.h>
#define simon "social-distancing"
using namespace std;

int d, n;
int r[1005], c[1005], rc[1005][1005];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen(simon".inp", "r") ){
        freopen(simon".inp", "r", stdin);
        freopen(simon".out", "w", stdout);
    }

    cin >> d >> n;
    for (int i = 1, x, y; i <= n; i ++){
        cin >> x >> y;
        x = (x%d+d)%d;
        y = (y%d+d)%d;
        r[x] ++;
        c[y] ++;
        rc[x][y] ++;
    }

    int ans = 1e9;

    for (int i = 0; i < d; i ++)
    for (int j = 0; j < d; j ++)
        ans = min(ans, r[i] + c[j] - rc[i][j]);

    cout << ans;


    return 0;
}
