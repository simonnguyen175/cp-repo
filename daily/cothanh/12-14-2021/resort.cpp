#include<bits/stdc++.h>
#define simon "resort"
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
const int N = 5e3 + 5;

int m, n, p, q, B;
int a[N][N], Less[N][N], Equal[N][N];

bool check(int x, int y, int u, int v){
    int numless = Less[u][v] - Less[u][y-1] - Less[x-1][v] + Less[x-1][y-1];
    int numequal = Equal[u][v] - Equal[u][y-1] - Equal[x-1][v] + Equal[x-1][y-1];
    return ( numless < (p*q+1)/2 && numless + numequal >= (p*q+1)/2 );
}

int main(){
    FASTio
    if ( fopen(simon".inp", "r") ){
        freopen(simon".inp", "r", stdin);
        freopen(simon".out", "w", stdout);
    }

    cin >> m >> n >> p >> q >> B;
    for (int i = 1; i <= m; i ++)
    for (int j = 1; j <= n; j ++)
        cin >> a[i][j];

    for (int i = 1; i <= m; i ++)
    for (int j = 1; j <= n; j ++){
        Less[i][j] = Less[i-1][j] + Less[i][j-1] - Less[i-1][j-1] + ( a[i][j] < B );
        Equal[i][j] = Equal[i-1][j] + Equal[i][j-1] - Equal[i-1][j-1] + ( a[i][j] == B );
    }

    int ans = 0;
    for (int i = 1; i <= m - p + 1; i ++)
    for (int j = 1; j <= n - q + 1; j ++)
        ans += check(i, j, i + p - 1, j + q - 1);

    cout << ans;

    return 0;
}
