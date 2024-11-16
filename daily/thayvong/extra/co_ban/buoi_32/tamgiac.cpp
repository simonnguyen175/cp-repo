#include<bits/stdc++.h>
using namespace std;
const int N = 1e2 + 5;

int n, a[N], s = 0;
bool dp[N][505][505];

bool check(int a, int b, int c){
    if ( a + b > c && b + c > a && c + a > b ) return true;
    else return false;
}

double stg(int a, int b, int c){
    double x = a * 1.0, y = b * 1.0, z = c * 1.0, p = 1.0 * ( x + y + z ) / 2;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}

int main(){
    if ( fopen("tamgiac.inp", "r") ){
        freopen("tamgiac.inp","r",stdin);
        freopen("tamgiac.out","w",stdout);
    }

	ios::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i ++){
        cin >> a[i];
        s += a[i];
    }

    memset(dp, 0, sizeof dp);
    for (int i = 0; i <= n; i ++)
        dp[i][0][0] = true;

    for (int i = 1; i <= n; i ++)
        for (int u = 0; u <= s; u ++)
            for (int v = 0; v <= s; v ++){
                dp[i][u][v] = dp[i-1][u][v];
                if ( a[i] <= u )
                    dp[i][u][v] |= dp[i-1][u - a[i]][v];
                if ( a[i] <= v )
                    dp[i][u][v] |= dp[i-1][u][v - a[i]];

            }
    double ans = -1.00;

    for (int u = 0; u <= s; u ++)
        for (int v = 0; v <= s; v ++){
            if ( dp[n][u][v] && check(u, v, s - u - v) )
                ans = max(ans, stg(u, v, s - u - v));
        }

    cout << fixed << setprecision(2) << ans;

    return 0;
}
