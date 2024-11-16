#include<bits/stdc++.h>
using namespace std;

int n, k;
int a[105];
long long f[105][105];

int main(){
    freopen("CINCSEQ.inp", "r", stdin);
    freopen("CINCSEQ.out", "w", stdout);

    /*
        f(i, j) la so day con tang do dai la j ket thuc tai i
        f(i, j) += f(k, j-1) ( ai > ak)
    */
    cin >> n >> k;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];

    for (int i = 1; i <= n; i ++)
    for (int j = 1; j <= k; j ++){
        f[i][1] = 1;
        for (int l = i-1; l >= 1; l --) if ( a[i] > a[l] )
            f[i][j] += f[l][j-1];
    }

    long long ans = 0;
    for (int i = 1; i <= n; i ++)
        ans += f[i][k];

    cout << ans;

    return 0;
}
