#include<bits/stdc++.h>
using namespace std;
const int N = 5e3 + 5;
const int MOD = 1e9 + 7;

int n;
int l[N], f[N][N], pw2[N];

int add(int a, int b){
    a += b;
    if ( a >= MOD ) a -= MOD;
    if ( a < 0 ) a += MOD;
    return a;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("trash.inp", "r") ){
        freopen("trash.inp", "r", stdin);
        freopen("trash.out", "w", stdout);
    }

    cin >> n;
    int mxl = 0;
    for (int i = 1; i <= n; i ++){
        cin >> l[i];
        mxl = max(mxl, l[i]);
    }
    sort(l + 1, l + 1 + n);

    for (int i = 1; i <= n; i ++)
    for (int j = 1; j < i; j ++) if ( l[i] + l[j] <= mxl )
        f[i][l[i] + l[j]] = add(f[i][l[i]+l[j]], 1);

    for (int i = 2; i <= n; i ++)
    for (int j = 1; j <= mxl; j ++)
        f[i][j] = add(f[i][j], f[i][j-1]);

    for (int i = 3; i <= n; i ++)
    for (int j = 1; j <= mxl; j ++){
        f[i][j] = add(f[i][j], f[i-1][j]);
        if ( j >= l[i] ) f[i][j] = add(f[i][j], f[i-1][j-l[i]]);
    }

    pw2[0] = 1;
    for (int i = 1; i <= n; i ++)
        pw2[i] = 1ll * pw2[i-1] * 2 % MOD;

    int ans = 0;
    for (int i = 3; i <= n; i ++){
        ans += add(add(pw2[i-1], -i), -f[i-1][l[i]]);
    }

    cout << ans;

    return 0;
}
