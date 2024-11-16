#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include<bits/stdc++.h>
#define ll long long
#define pi pair<ll, ll>
#define fi first
#define se second
#define pb push_back
#define int ll
using namespace std;
const ll MX = 1e18;

map<ll, vector<pi>> d;

ll Pow(ll a, int b){
    if ( b == 0 ) return 1;
    ll tmp = Pow(a, b/2);

    if ( b % 2 ){
        if ( tmp <= MX / tmp ) tmp *= tmp;
        else return MX + 5;

        if ( tmp <= MX / a ) tmp *= a;
        else return MX + 5;

        return tmp;
    }

    if ( tmp <= MX / tmp ) { tmp *= tmp; return tmp; }
    else return MX + 5;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    freopen("ex.inp", "r", stdin);
    freopen("ex.out", "w", stdout);

    for (ll i = 2; i <= 4000; i ++){
        ll j = i;
        d[j].pb({i, 1});
        int cnt = 1;
//        cerr << i << " : \n";
        while ( j <= MX / i ){
            j *= i;
            cnt ++;
//            cerr << "-> " << cnt << ' ' << j << '\n';
            d[j].pb({i, cnt});
        }
    }

    int test;
    cin >> test;
    ll n;
    while ( test -- ){
        cin >> n;
        vector<pi> cont;
        if ( d.find(n) != d.end() ) cont = d[n];

        if ( n > 4000 ){
            ll pre = n;
            for (int i = 1; i <= 4; i ++){
                ll lo = 1, hi = pre, res = -1;
                while ( lo <= hi ){
                    ll mid = (lo + hi) / 2;
                    if ( Pow(mid, i) <= n ) res = mid, lo = mid + 1;
                    else hi = mid - 1;
                }
                if ( res <= 4000 || res == -1 ) break;
                if ( Pow(res, i) == n ) cont.pb({res, i});
                pre = res;
            }
        }

        vector<pi> ncont;
        ncont = cont;
        for (auto it : cont) if ( it.se % 2 == 0 ) ncont.pb({-it.fi, it.se});

        sort(ncont.begin(), ncont.end());
        for (auto it : ncont) cout << it.fi << ' ' << it.se << '\n';
        cout << '\n';
    }

    return 0;
}
