#include<bits/stdc++.h>
#define ll long long
#define pi pair<ll, ll>
#define fi first
#define se second
using namespace std;
const int N = 1e5 + 5;
const ll oo = 1e18 + 5;

int n, m;
pi a[N];

bool check(ll d){
    ll cnt = 0, cur = -oo;

    for (int i = 1; i <= m; i ++){
        cur = max(cur, a[i].fi);
        if ( a[i].se < cur ) continue;
        cnt += ( a[i].se - cur ) / d + 1;
        cur += ( a[i].se - cur ) / d * d;
        cur += d;
    }

    return cnt >= n;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("socdist.inp", "r") ){
        freopen("socdist.inp", "r", stdin);
        freopen("socdist.out", "w", stdout);
    }

    cin >> n >> m;
    for (int i = 1; i <= m; i ++)
        cin >> a[i].fi >> a[i].se;
    sort(a + 1, a + 1 + m);

    ll lo = 1, hi = oo, res = 0;
    while ( lo <= hi ){
        ll mid = ( lo + hi ) / 2;
        if ( check(mid) ) res = mid, lo = mid + 1;
        else hi = mid - 1;
    }

    cout << res;

    return 0;
}
