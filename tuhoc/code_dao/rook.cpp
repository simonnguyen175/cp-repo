#include<bits/stdc++.h>
using namespace std;

int m, n, k, l;
long long c[205][205];
long long ans = 0;

int main(){
    cin >> m >> n >> k >> l;

    c[0][0] = 1;
    for (int i = 1; i <= 105; i ++){
        c[i][0] = 1;
        for (int j = 1; j <= i; j ++)
            c[i][j] = c[i-1][j] + c[i-1][j-1];
    }

    for (int i = 1; i <= min(m, k); i ++)
        for (int j = 1; j <= min(n, k); j ++)
            if ( i * j < k ) continue;
            else ans += c[(m-i)*(n-j)][l] * c[m][i] * c[n][j];

    cout << ans;
    return 0;
}
