#include<bits/stdc++.h>
using namespace std;
const int N = 1e4 + 1;

int n, k, q, p, ans;
int a[N], f[N][N];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n >> k >> q >> p;

    for (int i = 1; i <= n; i ++)
        cin >> a[i];

    for (int i = 1; i <= n; i ++)
    for (int j = 0; j <= q; j ++){
        int c1 = min(j, p);
        int c2 = j % p;
        f[i][j] = max(f[i-1][j], f[max(0, i-k)][j-c1] + c1 * a[i]);
        f[i][j] = max(f[i][j], f[max(0, i-k)][j-c2] + c2 * a[i]);
        ans = max(ans, f[i][j]);
    }

    cout << ans;

    return 0;
}
