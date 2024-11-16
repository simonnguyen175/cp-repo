#include<bits/stdc++.h>
#define ll long long
using namespace std;

struct chip{
    ll c, f, v;
    bool t;

    bool operator < (const chip& a){
        if ( f == a.f ){
            return (1-t) < (1-a.t);
        }
        else return f < a.f;
    }
};

int n, m;
chip a[4005], b[4005];

namespace subAC{
    ll dp[2][1000005];
    ll schip = 0;
    int nm = 0;

    void solve(){
        for (int i = 1; i <= m; i ++){
            a[++n] = b[i];
            schip += b[i].c;
        }

        sort(a + 1, a + 1 + n);

        dp[0][0] = 0;

        cout << n << ' ' << schip << '\n';

        for (int i = 0; i <= n; i ++)
            for (int j = 0; j <= schip; j ++){
                if ( a[i+1].t ){
                    dp[(i+1)%2][j] = max(dp[(i+1)%2][j], dp[i%2][j]);
                    if ( j + a[i+1].c > 50*m ) continue;
                    dp[(i+1)%2][j+a[i+1].c] = max(dp[(i+1)%2][j+a[i+1].c], dp[i%2][j] + a[i+1].v);
                }
                else{
                    dp[(i+1)%2][j] = max(dp[(i+1)%2][j], dp[i%2][j]);
                    if ( j <= a[i+1].c )
                        dp[(i+1)%2][0] = max(dp[(i+1)%2][0], dp[i%2][j] - a[i+1].v);
                    else
                        dp[(i+1)%2][j-a[i+1].c] = max(dp[(i+1)%2][j-a[i+1].c], dp[i%2][j] - a[i+1].v);
                }
            }

        ll ans = 0;
        for (int i = 1; i <= n; i ++)
            ans = max(dp[i%2][0], ans);

        cout << ans;
    }
}

int main(){
    if ( fopen("cloud.in", "r") ){
        freopen("cloud.in", "r", stdin);
        freopen("cloud.out", "w", stdout);
    }

    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i ++){
        cin >> a[i].c >> a[i].f  >> a[i].v;
        a[i].t = 0;
    }

    cin >> m;
    for (int i = 1; i <= m; i ++){
        cin >> b[i].c >> b[i].f >> b[i].v;
        b[i].t = 1;
    }

    subAC::solve();
}
