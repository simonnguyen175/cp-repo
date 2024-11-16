#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;

int t, m, n;
int a[N][N];
bitset<4000> f[N][N];

void solve(){
    cin >> m >> n;

    for (int i = 1; i <= m; i ++)
    for (int j = 1; j <= n; j ++){
        char x; cin >> x;
        a[i][j] = x - '0';
    }

    for (int i = 1; i <= m; i ++)
    for (int j = 1; j <= n; j ++)
        f[i][j].reset();

    bitset<4000> tmp;

    f[1][1][a[1][1]] = 1;

    for (int i = 1; i <= m; i ++)
    for (int j = 1; j <= n; j ++){
        tmp = f[i][j] << a[i][j+1];
        f[i][j+1] |= tmp;

        tmp = f[i][j] << a[i+1][j];
        f[i+1][j] |= tmp;
    }

    for (int i = 0; i < 4000; i ++)
        if ( f[m][n][i] ) cout << i << ' ';

    cout << '\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("grid012.in", "r") ){
        freopen("grid012.in", "r", stdin);
        freopen("grid012.out", "w", stdout);
    }

    cin >> t;
    while ( t -- ) solve();
    return 0;
}
