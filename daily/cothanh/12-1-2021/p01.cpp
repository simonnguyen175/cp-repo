#include<bits/stdc++.h>
using namespace std;
const int N = 1e2 + 5;

int n;
long double p, C[N][N], pw1[N], pw0[N], ans = 0.0;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("p01.inp", "r") ){
        freopen("p01.inp", "r", stdin);
        freopen("p01.out", "w", stdout);
    }

    cin >> n >> p;

    C[0][0] = 1.0;
    for (int i = 1; i <= n; i ++){
        C[i][0] = 1.0;
        for (int j = 1; j <= i; j ++)
            C[i][j] = C[i-1][j-1] + C[i-1][j];
    }

    pw1[0] = pw0[0] = 1;
    for (int i = 1; i <= n; i ++)
        pw1[i] = pw1[i-1] * p, pw0[i]= pw0[i-1] * (1.0-p);

    for (int i = 0; i <= n; i ++)
        ans += C[n][i] * pw1[i] * pw0[n-i] * i;

    cout << fixed << setprecision(5) << ans;

    return 0;
}
