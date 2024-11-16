#include<bits/stdc++.h>
#define BIT(x,k) ((x>>k)&1)
using namespace std;
const int N = 1e3 + 5;

int n, k, ans = 0;
int a[N], pw2[11], f[N][(1<<11)];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];

    pw2[0] = 1;
    while ( pw2[k] * 2 <= n ){
        k ++;
        pw2[k] = pw2[k-1] * 2;
    }
    k ++;

    memset(f, -1, sizeof f);

    f[0][0] = 0;


    for (int i = 0; i <= n; i ++)
    for (int t = 0; t < (1<<k); t ++){
        f[i+1][t] = max({f[i+1][t], f[i][t] + a[i+1], a[i+1]});
        for (int j = 0; j < k; j ++) if ( i + pw2[j] <= n && !BIT(t, j) )
            f[i+pw2[j]][t|pw2[j]] = max(f[i+pw2[j]][t|pw2[j]], f[i][t]);
        ans = max(ans, f[i][t]);
    }

    cout << ans;

    return 0;
}
