#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 4e3 + 5;
const int MOD = 1e9 + 7;

int k, n;
ll ans, c[N][N];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> k >> n;

    ll ans = 1;
    for (int i = 1; i <= n; i ++)
        ans = ( ans * i ) % MOD;

    c[0][0] = 1;
    for (int i = 1; i <= n + k; i ++){
        c[i][0] = 1;
        for (int j = 1; j <= i; j ++)
            c[i][j] = ( c[i-1][j-1] + c[i-1][j] ) % MOD;
    }

    ans = ( ans * c[n+k-1][k-1] ) % MOD;

    cout << ans;

    return 0;
}
