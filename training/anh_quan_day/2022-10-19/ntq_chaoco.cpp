#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> r[i];

    sort(r + 1, r + 1 + n);

    // dp(i, j, k)
    // den thang i, j tplt d, do dai nen k

    dp[0][0][0] = 1;
    for (int i = 0; i <= n; i ++)


    return 0;
}
