#include<bits/stdc++.h>
#define BIT(x, k) ((x>>k)&1)
#define pb push_back
#define pi pair<int, int>
#define fi first
#define se second
#define int long long
using namespace std;
const int N = 25;
const int oo = 2e9;

int n;
int a[N], b[N];
vector<pi> opt;
pi ans = {oo, oo};

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("trash.inp", "r") ){
        freopen("trash.inp", "r", stdin);
        freopen("trash.out", "w", stdout);
    }

    cin >> n;
    int sl = 0, sr = 0;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    for (int i = 1; i <= n; i ++)
        cin >> b[i];

    for (int i = 1; i <= n; i ++)
        if ( !a[i] || !b[i] ){
            sl += a[i];
            sr += b[i];
            swap(a[i], a[n]);
            swap(b[i], b[n]);
            n --;
            i --;
        }

    int sa = 0, sb = 0;
    for (int i = 1; i <= n; i ++) sa += a[i];
    for (int i = 1; i <= n; i ++) sb += b[i];

    for (int msk = 0; msk < (1<<n); msk ++){
        int lef = 0, rig = 0;

        for (int i = 1; i <= n; i ++) if ( BIT(msk, i-1) )
            lef += a[i];
        else rig += b[i];

        opt.pb({lef, rig});
    }

    sort(opt.begin(), opt.end());
    int mx = 0;
    for (int i = opt.size()-1; i >= 0; i --){
        if ( opt[i].fi + (opt[i].fi != sa) + mx + (mx != sb) < ans.fi + ans.se )
            ans = {opt[i].fi + (opt[i].fi != sa), mx + (mx != sb)};

        mx = max(mx, opt[i].se);
    }

    cout << ans.fi + sl << '\n' << ans.se + sr << '\n';

    return 0;
}
