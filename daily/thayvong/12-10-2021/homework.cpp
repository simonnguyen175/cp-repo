#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
const int oo = 1e9;

int t, n;
int a[N], f[N][2];

void solve(){
    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];

    for (int i = 0; i <= n; i ++)
        f[i][0] = f[i][1] = oo;

    // 0 la bac chon, 1 la trung chon
    f[0][1] = 0;
    for (int i = 1; i <= n; i ++){
        f[i][0] = min(f[i][0], f[i-1][1] + (a[i] ? 1 : 0));
        f[i][1] = min(f[i][1], f[i-1][0]);
        if ( i >= 2 ){
            f[i][0] = min(f[i][0], f[i-2][1] + (a[i] ? 1 : 0) + (a[i-1] ? 1 : 0) );
            f[i][1] = min(f[i][1], f[i-2][0]);
        }
    }

    cout << min(f[n][0], f[n][1]) << '\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("homework.inp", "r") ){
        freopen("homework.inp", "r", stdin);
        freopen("homework.out", "w", stdout);
    }

    cin >> t;
    while ( t -- )
        solve();

    return 0;
}
