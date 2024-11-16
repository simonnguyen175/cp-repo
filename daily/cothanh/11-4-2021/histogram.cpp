#include<bits/stdc++.h>
#define simon "histogram"
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define BIT(x,k) ((x>>k)&1)
using namespace std;

int n;
int a[20], f[1<<20][20], cnt[1<<20][20];

int main(){
    FASTio
    if ( fopen(simon".inp", "r") ){
        freopen(simon".inp", "r", stdin);
        freopen(simon".out", "w", stdout);
    }

    while ( cin >> n ){
        if ( !n ) break;
        for (int i = 1; i <= n; i ++)
            cin >> a[i];

        for (int t = 0; t < (1<<n); t ++)
            for (int i = 0; i <= n; i ++)
                f[t][i] = 0, cnt[t][i] = 0;

        for (int i = 1; i <= n; i ++){
            f[1<<(i-1)][i] = 2 * (a[i] + 1);
            cnt[1<<(i-1)][i] = 1;
        }

        for (int t = 1; t < (1<<n); t ++)
            for (int i = 1; i <= n; i ++){
                //cout << t << ' ' << i << ' ' << f[t][i] << '\n';
                if ( BIT(t, i-1) )
                    for (int j = 1; j <= n; j ++)
                        if ( !BIT(t, j-1) )
                            if ( f[t|(1<<(j-1))][j] < f[t][i] + 2 + a[j] - a[i] + abs(a[j]-a[i]) ){
                                f[t|(1<<(j-1))][j] = f[t][i] + 2 + a[j] - a[i] + abs(a[j]-a[i]);
                                cnt[t|(1<<(j-1))][j] = cnt[t][i];
                            }
                            else if ( f[t|(1<<(j-1))][j] == f[t][i] + 2 + a[j] - a[i] + abs(a[j]-a[i]) )
                                cnt[t|(1<<(j-1))][j] += cnt[t][i];

            }

        pair<int, int> ans;
        for (int i = 1; i <= n; i ++)
            if ( f[(1<<n)-1][i] > ans.first ){
                ans.first = f[(1<<n)-1][i];
                ans.second = cnt[(1<<n)-1][i];
            }
            else if ( f[(1<<n)-1][i] == ans.first )
                ans.second += cnt[(1<<n)-1][i];

        cout << ans.first << ' ' << ans.second << '\n';
    }

    return 0;
}
