#include<bits/stdc++.h>
#define simon "sumdiv"
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
using namespace std;

ll a, b;
ll ans = 0;
ll dd[100005];

ll sum(ll l, ll r){
    return (l+r)*(r-l+1)/2;
}

int main(){
    FASTio
    if ( fopen(simon".inp", "r") ){
        freopen(simon".inp", "r", stdin);
        freopen(simon".out", "w", stdout);
    }

    cin >> a >> b;

    ll l, r, pl = 1e9 + 5;
    for (ll d = 1; d <= sqrt(b); d ++){
        ll l = ( a % d == 0 ) ? a / d : a / d + 1;
        ll r = b / d;
        if ( l <= r ) dd[d] = 1;
        r = min(r, pl - 1); pl = l;
        if ( l > r ) continue;
        ans += sum(l, r);
    }

    for (ll i = 1; i <= pl - 1; i ++)
        if ( dd[i] ) ans += i;

    cout << ans;

    return 0;
}
