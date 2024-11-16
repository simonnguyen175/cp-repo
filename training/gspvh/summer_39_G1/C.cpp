#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e6 + 5;
const ll oo = 1e17;

int n;
ll a[N], s[N], f[N][6];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("divseq.inp", "r") ){
        freopen("divseq.inp", "r", stdin);
        freopen("divseq.out", "w", stdout);
    }

    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];

    for (int i = 1; i <= n; i ++)
    for (int j = 0; j <= 5; j ++)
        f[i][j] = -oo;

    f[0][0] = 0;

    for (int i = 1; i <= n; i ++)
    for (int j = 1; j <= 5; j ++)
    for (int k = 1; k <= j; k ++){
        int c = ( j % 2 ? 1 : -1 );
        f[i][j] = max(f[i][j], f[i-1][k] + c * a[i]);
    }

    cout << max({f[n][1], f[n][2], f[n][3], f[n][4], f[n][5]});

    return 0;
}
