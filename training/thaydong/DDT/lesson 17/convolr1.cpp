#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5e3 + 5;
const ll oo = 1e12;

int n;
ll a[N], b[N], f[N][N];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i ++) cin >> a[i];
    for (int i = 1; i <= n; i ++) cin >> b[i];

    f[0][0] = 0; ll ans = -oo;
    for (int i = 1; i <= n; i ++)
    for (int j = 1; j <= n; j ++){
        f[i][j] = max(a[i]*b[j], f[i-1][j-1] + a[i]*b[j]);
        ans = max(ans, f[i][j]);
    }

    cout << ans;

    return 0;
}
