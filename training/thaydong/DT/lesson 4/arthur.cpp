#include<bits/stdc++.h>
#define ll long long
#define pi pair<ll, ll>
#define fi first
#define se second
#define pb push_back
using namespace std;
const int N = 900;
const double oo = 1e12;

ll q, n, w1, w2, w3;
pi a[N];

bool cmp(pi a, pi b){
    return a.se > b.se;
}

ll Johnson(ll sa, ll sb, ll st){
    vector<pi> N1, N2;
    for (int i = 1; i <= n; i ++) if ( i!= st )
        if ( a[i].fi <= a[i].se ) N1.pb(a[i]);
        else N2.pb(a[i]);
    sort(N1.begin(), N1.end());
    sort(N2.begin(), N2.end(), cmp);
    for (auto it : N1) sa += it.fi, sb = max(sa, sb) + it.se;
    for (auto it : N2) sa += it.fi, sb = max(sa, sb) + it.se;
    return sb;
}

void sub4(){
    double ans = oo;
    if ( w2 == 0 && w1 * w3 == 0 ){
        cout << fixed << setprecision(1) << 0.0 << '\n';
        return;
    }

    for (int i = 1; i <= n; i ++){
        ll t1, tn;
        t1 = a[i].fi + a[i].se;
        tn = Johnson(a[i].fi, a[i].fi + a[i].se, i);
        double y1 = (w1*w2) * (tn-t1) * 1.0 / (w1+w2);
        double y2 = (w2*w3*tn) * 1.0 / (w2+w3);
        ans = min(ans, max(y1, y2));
    }

    cout << fixed << setprecision(1) << ans << '\n';
}

void solve(){
    cin >> n >> w1 >> w2 >> w3;
    for (int i = 1; i <= n; i ++)
        cin >> a[i].fi >> a[i].se;
    sub4();
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> q;
    while ( q -- )
        solve();
    return 0;
}
