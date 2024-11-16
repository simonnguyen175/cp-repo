#include<bits/stdc++.h>
#define simon "cake"
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define BIT(x, k) ((x>>k)&1)
using namespace std;
const int oo = 1e9;

int n;
int a[55];

namespace sub1{
    void solve(){
        int s[55];
        s[0] = 0;
        for (int i = 1; i <= n; i ++)
            s[i] = s[i-1] + a[i];
        int ans = INT_MAX;
        for (int mask = 1; mask < (1<<(n-1)); mask ++){
            int pre = 0, mn = INT_MAX, mx = 0;
            for (int i = 1; i <= n - 1; i ++)
                if ( BIT(mask, i-1) ){
                    mn = min(mn, s[i] - s[pre]);
                    mx = max(mx, s[i] - s[pre]);
                    pre = i;
                }
            mn = min(mn, s[n] - s[pre]);
            mx = max(mx, s[n] - s[pre]);

            ans = min(ans, mx - mn);
        }
        cout << ans;
    }
}

namespace sub3{
    int f[55][55*1000], s[55];

    void solve(){
        for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= 55*1000; j ++)
            f[i][j] = -oo;

        for (int i = 1; i <= n; i ++){
            s[i] += s[i-1] + a[i];
            f[i][s[i]] = 0;
        }

        for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= s[n]; j ++){
            if ( f[i][j] == -oo ) continue;
            int curmn = f[i][j];
            //cout << "f["<<i<<"]["<<j<<"] = " << f[i][j] << '\n';
            for (int k = i + 1; k <= n; k ++){
                int tmp = s[k] - s[i];
                if ( tmp <= j ){
                    if ( f[i][j] == 0 ) f[k][j] = max({f[k][j], tmp});
                    f[k][j] = max({f[k][j], min(tmp, f[i][j])});
                    //cout <<"-> f["<<k<<"]["<<j<<"] = " << f[k][j] << '\n';
                }
                else{
                    if ( f[i][j] == 0 ) f[k][tmp] = max(f[k][tmp], j);
                    else f[k][tmp] = max(f[k][tmp], f[i][j]);
                    //cout <<"-> f["<<k<<"]["<<tmp<<"] = " << f[k][tmp] << '\n';
                }
            }
        }


        int ans = oo;
        for (int j = 1; j < s[n]; j ++)
            if ( f[n][j] > 0 )
                ans = min(ans, j - f[n][j]);
        cout << ans;
    }
}


int main(){
    FASTio
    if ( fopen(simon".inp", "r") ){
        freopen(simon".inp", "r", stdin);
        freopen(simon".out", "w", stdout);
    }

    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];

    //if ( n <= 15 ) sub1::solve();
    //else
        sub3::solve();

    return 0;
}
