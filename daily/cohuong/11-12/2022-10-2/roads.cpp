#include<bits/stdc++.h>
using namespace std;
const int N = 3e4 + 5;

int n, m, k;
int row[N], col[N], d[N][5], ans[5];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("roads.inp", "r") ){
        freopen("roads.inp", "r", stdin);
        freopen("roads.out", "w", stdout);
    }

    cin >> n >> m >> k;
    for (int i = 1; i <= k; i ++){
        char type;
        int x;
        cin >> type >> x;
        if ( type == 'H' ) row[x] = 1;
        else col[x] = 1;
    }

    for (int i = 1; i <= n; i ++){
        int j = row[i] + row[i-1];
        d[1][j] ++, d[m+1][j] --;
    }

    for (int i = 1; i <= m; i ++)
    for (int j = 0; j <= 2; j ++){
        d[i][j] += d[i-1][j];
//        cout << i << ' ' << j << ' ' << d[i][j] << '\n';
    }

    for (int i = 1; i <= m; i ++){
        int j = col[i] + col[i-1];
        for (int k = j; k <= 4; k ++)
            ans[k] += d[i][k-j];
    }

    for (int i = 0; i <= 4; i ++)
        cout << ans[i] << ' ';

    return 0;
}
