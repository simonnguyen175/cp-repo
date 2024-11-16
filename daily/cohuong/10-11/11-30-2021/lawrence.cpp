#include<bits/stdc++.h>
using namespace std;
const int N = 5e2 + 5;
const int oo = 1e9;

int n, m;
int a[N], f[N][N];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("lawrence.inp", "r") ){
        freopen("lawrence.inp", "r", stdin);
        freopen("lawrence.out", "w", stdout);
    }

    cin >> n >> m;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];

    for (int i = 0; i <= n; i ++)
    for (int j = 0; j <= m; j ++)
        f[i][j] = oo;

    f[0][0] = 0;
    int sum = 0;
    for (int i = 1; i <= n; i ++)
        f[i][0] = f[i-1][0] + a[i] * sum, sum += a[i];

    for (int i = 1; i <= n; i ++)
    for (int j = 1; j <= m; j ++){
        int cost = 0;
        sum = a[i];
        for (int k = i - 1; k >= 1; k --){
            f[i][j] = min(f[i][j], f[k][j-1] + cost);
            cost += a[k] * sum;
            sum += a[k];
        }
    }

    cout << f[n][m];

    return 0;
}
