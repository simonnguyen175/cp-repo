#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MOD = 1e9;

int m, A, B;
pair<int, int> c[20];
ll f[2][1001][1001];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> m >> A >> B;
    for (int i = 1; i <= m; i ++)
        cin >> c[i].first >> c[i].second;

    f[0][0][0] = 1;

    for (int i = 1; i <= m; i ++)
    for (int j = 0; j <= A; j ++)
    for (int k = 0; k <= B; k ++){
        if ( c[i].first > j || c[i].second > k )
            f[i%2][j][k] = f[(i-1)%2][j][k];
        else
            f[i%2][j][k] = (f[(i-1)%2][j][k] + f[i%2][j-c[i].first][k-c[i].second]) % MOD;
    }

    cout << f[m%2][A][B];

    return 0;
}
