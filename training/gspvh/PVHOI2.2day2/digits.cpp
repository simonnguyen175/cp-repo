#include<bits/stdc++.h>
using namespace std;
const int N = 2e3 + 5;
const int oo = 1e9;

int m, n, p;
int a[N][N];

namespace sub1{
    int f[N][55];

    void solve(){
        for (int i = 1; i <= n; i ++)
        for (int j = 0; j < p; j ++)
             f[i][j] = oo;

        for (int j = 0; j <= 9; j ++)
            if ( j != a[1][1])
                f[1][j%p] = min(f[1][j%p], 1);
            else
                f[1][j%p] = min(f[1][j%p], 0);

        for (int i = 1; i <= n; i ++)
        for (int j = 0; j < p; j ++)
        for (int k = 0; k <= 9; k ++){
            int c;
            if ( a[1][i+1] != k ) c = 1; else c = 0;

            f[i+1][(j*10+k)%p] = min(f[i+1][(j*10+k)%p], f[i][j] + c);
        }

        cout << f[n][0];
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("digits.inp", "r") ){
        freopen("digits.inp", "r", stdin);
        freopen("digits.out", "w", stdout);
    }

    cin >> m >> n >> p;
    for (int i = 1; i <= m; i ++)
    for (int j = 1; j <= n; j ++){
        char x; cin >> x;
        a[i][j] = x - '0';
    }

    if ( m == 1 ) sub1::solve();

    return 0;
}
