#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5 + 5;
const ll oo = 1e10;

int n;
ll x[N], y[N];
ll pre_mnx[N], pre_mxx[N], suf_mnx[N], suf_mxx[N];
ll pre_mny[N], pre_mxy[N], suf_mny[N], suf_mxy[N];
ll ans;

void solve(){
    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> x[i] >> y[i];

    pre_mnx[0] = oo, pre_mxx[0] = 0;
    pre_mny[0] = oo, pre_mxy[0] = 0;
    for (int i = 1; i <= n; i ++){
        pre_mnx[i] = min(pre_mnx[i-1], x[i]);
        pre_mxx[i] = max(pre_mxx[i-1], x[i]);

        pre_mny[i] = min(pre_mny[i-1], y[i]);
        pre_mxy[i] = max(pre_mxy[i-1], y[i]);
    }

    suf_mnx[n+1] = oo, suf_mxx[n+1] = 0;
    suf_mny[n+1] = oo, suf_mxy[n+1] = 0;
    for (int i = n; i >= 1; i --){
        suf_mnx[i] = min(suf_mnx[i+1], x[i]);
        suf_mxx[i] = max(suf_mxx[i+1], x[i]);

        suf_mny[i] = min(suf_mny[i+1], y[i]);
        suf_mxy[i] = max(suf_mxy[i+1], y[i]);
    }

    ans = oo;
    for (int i = 1; i <= n; i ++){
        ll mnx = min(pre_mnx[i-1], suf_mnx[i+1]);
        ll mxx = max(pre_mxx[i-1], suf_mxx[i+1]);

        ll mny = min(pre_mny[i-1], suf_mny[i+1]);
        ll mxy = max(pre_mxy[i-1], suf_mxy[i+1]);

        ans = min(ans, 2*(mxx-mnx+2 + mxy-mny+2));
    }

    cout << ans << '\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    freopen("hangrao.inp", "r", stdin);
    freopen("hangrao.out", "w", stdout);

    int test;
    cin >> test;
    while ( test -- )
        solve();

    return 0;
}
