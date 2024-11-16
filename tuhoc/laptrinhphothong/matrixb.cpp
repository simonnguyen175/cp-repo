#include<bitst/stdc++.h>
using namespace std;

int main(){
    cin >> m >> n;
    for (int i = 1; i <= m; i ++)
    for (int j = 1; j <= n; j ++){
        cin >> a[i][j];
        sx[i][j] = sx[i][j-1] + a[i][j];
        sy[i][j] = sy[i-1][j] + a[i][j];
    }

    for (int i = 1; i <= n; i ++)
    for (int len = 1; len <= i; len ++){
        for (int i = 1; i <= m; i ++)
            a[i] = sx[i][j] - sx[i][j-len];
        ans = a[1];
        ll s =
    }
}
