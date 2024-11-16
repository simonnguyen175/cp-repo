#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;

int n;
int a[N], pre[N], mx[N][21], dp[N];

int get(int l, int r){
    int k = __lg(r-l+1);
    return max(mx[l][k], mx[r-(1<<k)+1][k]);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("trash.inp", "r") ){
        freopen("trash.inp", "r", stdin);
        freopen("trash.out", "w", stdout);
    }

    cin >> n;
    for (int i = 1, x; i <= n; i ++)
        cin >> a[i];

    for (int i = 1; i <= n; i ++){
        pre[i] = max(pre[i-1], a[i]);
        if ( pre[i] == i ) mx[i][0] = i;
    }

    for (int j = 1; j <= __lg(n); j ++)
    for (int i = 1; i <= n - (1<<j) + 1; i ++)
        mx[i][j] = max(mx[i][j-1], mx[i+(1<<(j-1))][j-1]);

    dp[0] = 0;
    int ans = sqrt(n);
    for (int c = 0; c <= sqrt(n); c ++){
        int i = dp[c];
        while ( i < n && a[i+1] == i+1 ) i ++;
        dp[c] = i;

        for (int s = 0; c + s <= sqrt(n); s ++){
            int l = min(n, i + s * s), r = min(n, i + (s+1)*(s+1) - 1);
            dp[c+s] = max(dp[c+s], get(l, r));
        }

        if ( dp[c] == n ) ans = min(ans, c);
    }

    cout << ans;

    return 0;
}
