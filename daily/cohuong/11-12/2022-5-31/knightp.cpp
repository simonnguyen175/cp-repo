#include<bits/stdc++.h>
#define ll long long
#define BIT(x, k) ((x>>k)&1)
using namespace std;

int n, m;
ll a[10][3005], c[3005][35], f[3005][35][35];

bool ok1(int t1, int t2){
    for (int i = 1; i <= n; i ++) if ( BIT(t1, i-1) ){
        if ( i + 2 <= n && BIT(t2, i+1) ) return false;
        if ( i - 2 >= 1 && BIT(t2, i-3) ) return false;
    }
    return true;
}

bool ok2(int t1, int t3){
    for (int i = 1; i <= n; i ++) if ( BIT(t1, i-1) ){
        if ( i + 1 <= n && BIT(t3, i) ) return false;
        if ( i - 1 >= 1 && BIT(t3, i-2) ) return false;
    }
    return true;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("knightp.in", "r") ){
        freopen("knightp.in", "r", stdin);
        freopen("knightp.out", "w", stdout);
    }

    cin >> n >> m;
    for (int i = 1; i <= n; i ++)
    for (int j = 1; j <= m; j ++)
        cin >> a[i][j];

    for (int i = 1; i <= m; i ++)
    for (int j = 0; j < (1<<n); j ++)
    for (int k = 1; k <= n; k ++)
        if ( BIT(j, k-1) )
            c[i][j] += a[k][i];

    if ( m == 1 ){
        cout << c[1][(1<<n)-1];
        return 0;
    }

    for (int i = 0; i < (1<<n); i ++)
    for (int j = 0; j < (1<<n); j ++)
        if ( ok1(i, j) )
            f[2][i][j] = c[1][i] + c[2][j];

    ll ans = 0;
    for (int i = 2; i < m; i ++)
    for (int t1 = 0; t1 < (1<<n); t1 ++)
    for (int t2 = 0; t2 < (1<<n); t2 ++) if ( ok1(t1, t2) )
    for (int t3 = 0; t3 < (1<<n); t3 ++) if ( ok1(t2, t3) && ok2(t1, t3) ){
        f[i+1][t2][t3] = max(f[i+1][t2][t3], f[i][t1][t2] + c[i+1][t3]);
        if ( i + 1 == m ) ans = max(ans, f[i+1][t2][t3]);
    }

    cout << ans;

    return 0;
}
