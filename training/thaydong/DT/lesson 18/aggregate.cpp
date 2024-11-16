#include<bits/stdc++.h>
#define ll long long
#define pi pair<ll, ll>
#define x first
#define y second
using namespace std;
const int N = 3e5 + 5;

int n;
pi a[N];

struct hcn{
    ll x, y, u, v;
} b[N];

hcn giao(hcn a, hcn b){
    hcn res;
    res.x = max(a.x, b.x);
    res.y = max(a.y, b.y);
    res.u = min(a.u, b.u);
    res.v = min(a.v, b.v);
    return res;
}

bool check(ll mid){
    for (int i = 1; i <= n; i ++){
        ll x = a[i].x - mid - a[i].y, y = a[i].x - mid + a[i].y;
        ll u = a[i].x + mid - a[i].y, v = a[i].x + mid + a[i].y;
        b[i] = {x, y, u, v};
    }

//    for (int i = 1 ; i <= n; i ++)
//        cout << b[i].x << ' ' << b[i].y << ' ' << b[i].u << ' ' << b[i].v << '\n';

    hcn cur = b[1];
    for (int i = 2; i <= n; i ++){
        cur = giao(cur, b[i]);
//        cout << cur.x << ' ' << cur.y << ' ' << cur.u << ' ' << cur.v << '\n';
        if ( cur.x > cur.u || cur.y > cur.v ) return 0;
    }

    return 1;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("trash.inp", "r") ){
        freopen("trash.inp", "r", stdin);
        freopen("trash.out", "w", stdout);
    }

    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i].x >> a[i].y;

//    cout << check(2) << '\n';

    ll lo = 0, hi = 2e18, res;
    while ( lo <= hi ){
        ll mid = (lo + hi) / 2;
        if ( check(mid) ) hi = mid - 1, res = mid;
        else lo = mid + 1;
    }

    cout << res;

    return 0;
}
