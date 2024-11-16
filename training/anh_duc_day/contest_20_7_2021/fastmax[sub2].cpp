#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MOD = 1e9 + 7;
const int N = 5e3 + 5;

int n, k;
ll c[N][N], gt[N], f[N];

int main(){
    cin >> n >> k;
    c[0][0] = 1;
    for (int i = 1; i <= n; i ++){
        c[i][0] = 1;
        for (int j = 1; j <= i; j ++)
            c[i][j] = (c[i-1][j]+c[i-1][j-1])%MOD;
    }

    gt[0] = 1;
    for (int i = 1; i <= n; i ++)
        gt[i] = (gt[i-1]*i)%MOD;

    for (int i = k + 1; i <= n; i ++){
        f[i] = (f[i] + ((i-k-1)*gt[i-2])%MOD)%MOD;
        for (int j = i - k; j <= i - 1; j ++)
            f[i] = (f[i] + (((f[j]*c[i-2][j-1])%MOD)*gt[i-j-1])%MOD)%MOD;
    }

    ll ans = 0;
    for (int i = k + 1; i <= n; i ++)
        ans = (ans + (((f[i]*c[n-1][i-1])%MOD)*gt[n-i])%MOD)%MOD;

    cout << ans;

    return 0;
}
