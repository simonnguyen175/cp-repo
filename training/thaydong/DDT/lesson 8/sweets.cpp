#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e2 + 5;

int n, a[N];

namespace sub1{
    ll f[1<<20], s[1<<20], ans = 1e15;

    bool check(ll sa, ll sb, ll sc){
        return ( sa <= sb && sb <= sc );
    }

    void solve(){
        int mx = (1<<n)-1;

        for (int t = 1; t <= mx; t ++)
            for (int i = 1; i <= n; i ++)
                if ( t&(1<<(i-1)) ) s[t] += a[i];

        for (int t = 1; t <= mx; t ++){
            if ( s[t] <= s[mx]/3 ) f[t] = s[t];
            else{
            for (int i = 1; i <= n; i ++)
                if ( t&(1<<(i-1)) )
                    f[t] = max(f[t], f[t^(1<<(i-1))]);
            }
        }

        for (int t = 1; t <= mx; t ++){
            ll sa = f[t], sc = s[t] - f[t], sb = s[mx] - sc - sa;
            if ( check(sa, sb, sc) ) ans = min(ans, sc - sa);
        }

        cout << ans;
    }
}

namespace sub2{
    bool dp[N][1005][1005];

    bool check(ll sa, ll sb, ll sc){
        return ( sa <= sb && sb <= sc );
    }

    void solve(){
        ll s = 0, ans = 1e15;
        for (int i = 1; i <= n; i ++)
            s += a[i];

        dp[0][0][0] = 1;
        for (int i = 0; i <= n; i++){
            for (int sa = 0; sa <= s/3; sa ++)
                for (int sb = 0; sb <= s/2; sb ++){
                    //cout << "to id " << i << ' ' << "can get sa = " << sa << " and sb = " << sb << " : " << dp[i][sa][sb] << '\n';
                    dp[i+1][sa+a[i]][sb] |= dp[i][sa][sb];
                    dp[i+1][sa][sb+a[i]] |= dp[i][sa][sb];
                    dp[i+1][sa][sb] |= dp[i][sa][sb];
                }
        }

        for (int sa = 1; sa <= s/3; sa ++)
            for (int sb = 1; sb <= s/2; sb ++)
                if ( dp[n][sa][sb] )
                    if ( check(sa, sb, s-sa-sb) )
                        ans = min(ans, s-sb-2*sa);
        cout << ans;
    }
}

int main(){
    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];

    if ( n <= 20 ) sub1::solve();
    else sub2::solve();
}
