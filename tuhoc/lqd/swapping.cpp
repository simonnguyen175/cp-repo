#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll oo = 1e18;

int k, m, n;
multiset<ll> cont;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> k >> m >> n;
    for (int i = 1; i <= n; i ++){
        ll x; cin >> x;
        cont.insert(x);
    }

    ll ans = oo;
    for (int i = 1; i <= m; i ++){
        ll mn = *cont.cbegin();
        ll mx = *cont.rbegin();

        ans = min(ans, mx - mn);
        auto itmn = cont.find(mn), itmx = cont.find(mx);
        cont.erase(itmn); cont.erase(itmx);

        mx -= k; mn += k;
        cont.insert(mx); cont.insert(mn);
    }

    ll mn = *(cont.cbegin());
    ll mx = *(cont.rbegin());
    ans = min(ans, mx - mn);

    cout << ans;

    return 0;
}
