#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll oo = 1e12;

int n, m;
ll s = 0, w[105], v[105], f[105][100005];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i ++)
        cin >> w[i] >> v[i], s += v[i];

    for (int i = 0; i <= n; i ++)
    for (int j = 0; j <= s; j ++)
        f[i][j] = oo;

    f[0][0] = 0;

    for (int i = 1; i <= n; i ++)
    for (int j = 0; j <= s; j ++){
        f[i][j] = f[i-1][j];
        if ( j >= v[i] && f[i-1][j-v[i]] != oo )
            f[i][j] = min(f[i][j], f[i-1][j-v[i]] + w[i]);
    }

    for (int i = s; i >= 1; i --)
        if ( f[n][i] <= m ){
            cout << i;
            return 0;
        }

    cout << 0;
    return 0;
}
