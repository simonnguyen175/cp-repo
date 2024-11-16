#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5 + 5;
const ll oo = 1e15;

int n;
ll a[N];
ll ans = -oo;
map<ll, ll> d;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];

    ll s = a[1];
    d[a[1]] = 0;
    for (int i = 2; i <= n; i ++){
        s += a[i];
        if ( d.find(a[i]) != d.end() ){
            //cout << a[i] << ' ' <<  s << ' '  <<  d[a[i]] << '\n';
            ans = max(ans, s - d[a[i]]);
            d[a[i]] = min(d[a[i]], s - a[i]);
        }
        else {
            d[a[i]] = s - a[i];
            //cout << a[i] << ' ' << d[a[i]] << '\n';
        }
    }

    cout << ans;

    return 0;
}
