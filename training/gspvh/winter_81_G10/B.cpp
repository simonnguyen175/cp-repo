#include<bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;

ll k, t = 0;
int d[11];

bool ck(ll x){
    t ++;
    while ( x ){
        if ( d[x%10] == t ) return false;
        d[x%10] = t;
        x /= 10;
    }
    return true;
}

int cnt(ll x){
    int res = 0;
    for (int i = 1; i <= sqrt(x); i ++)
        if ( ck(1LL*i*i) ) res ++;
    return res;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    freopen("squares.inp", "r", stdin);
    freopen("squares.out", "w", stdout);

    cin >> k;
    ll lo = 1, hi = 1e11, res = -1 ;
    while ( lo <= hi ){
        ll mid = ( lo + hi ) / 2;
        if ( cnt(mid) >= k ) res = mid, hi = mid - 1;
        else lo = mid + 1;
    }

    cout << res;

    return 0;
}
