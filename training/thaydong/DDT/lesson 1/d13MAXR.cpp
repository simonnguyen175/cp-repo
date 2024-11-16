#include<bits/stdc++.h>
using namespace std;

int n, a[1000];
long long dp[1000][1000];

long long Try(int l, int r){
    if ( dp[l][r] ) return dp[l][r];

    if ( l + 1 == r ) return 0;

    long long best = 0;

    for (int k = l + 1; k <= r - 1; k ++)
        dp[l][r] = max(dp[l][r], Try(l, k) + Try(k, r) + a[l] * a[r]);

    return dp[l][r];
}

int main(){
    ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];

    cout << Try(1, n);
}
