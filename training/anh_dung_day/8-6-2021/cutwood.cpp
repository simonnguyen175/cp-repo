#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
const int oo = 1e9;

int n, k, mx;
int a[N], dp[N][35];

int tknp(int d, int c, int x){
    int lo = d, hi = c, res = 0;
    while ( lo <= hi ){
        int mid = ( lo + hi ) / 2;
        if ( a[mid] <= x ) {res = mid; lo = mid + 1;}
        else hi = mid - 1;
    }
    return res;
}

int main(){
    if ( fopen("cutwood.inp", "r") ){
        freopen("cutwood.inp", "r", stdin);
        freopen("cutwood.out", "w", stdout);
    }

    ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

    cin >> n >> k;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];

    sort(a + 1, a + 1 + n);

    for (int i = 0; i <= n; i ++)
        for (int j = 0; j <= 30; j ++)
            dp[i][j] = oo;

    dp[0][0] = 0; dp[1][1] = 0; dp[1][0] = 1;

    for (int i = 2; i <= n; i ++){
        dp[i][0] = dp[i-1][0] + 1;
        int nxt = tknp(1, i-1, a[i]/2);
        for (int j = 1; j <= 30; j ++)
            dp[i][j] = min(dp[i-1][j] + 1, dp[nxt][j-1]);
    }

    for (int i = 0; i <= 30; i ++)
        if ( dp[n][i] <= k ) {
            cout << i << ' ' << dp[n][i] << '\n';
            return 0;
        }
}
