#include<bits/stdc++.h>
#define simon "team"
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
#define fi first
#define se second
using namespace std;
const int N = 2e5 + 5;
const ll oo = 1e15;

int n;
pair<ll, ll> a[N];
ll mna[N];

int main(){
    FASTio
    if ( fopen(simon".inp", "r") ){
        freopen(simon".inp", "r", stdin);
        freopen(simon".out", "w", stdout);
    }

    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i].se >> a[i].fi;

    sort(a + 1, a + 1 + n);

    mna[n+1] = oo;
    for (int i = n; i >= 1; i --)
        mna[i] = min(mna[i+1], a[i].se);


    ll s = 0, f = oo;

    for (int i = 1; i <= n; i ++){
        s += a[i].fi;
        f = min(f, a[i].se - a[i].fi);
        cout << min(s + f, s - a[i].fi + mna[i+1]) << '\n';
    }

    return 0;
}
