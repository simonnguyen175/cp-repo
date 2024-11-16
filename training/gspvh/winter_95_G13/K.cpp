#include<bits/stdc++.h>
#define ull unsigned long long
#define int long long
#define pi pair<int, int>
#define fi first
#define se second
#define pb push_back
#define BIT(x, k) ((x>>k)&1)
using namespace std;

int a, b, c, d;
vector<pi> all_ab, all_cd, all_xor;

vector<pi> gen(int a, int b){
    vector<pi> cont;

    int cur = 0;
    for (int i = 63; i >= 0; i --)
    if ( BIT(a, i) != BIT(b, i) ){
        int tmp = cur;
        for (int j = i-1; j >= 0; j --){
            if ( !BIT(a, j) ) cont.pb({tmp + (1ll<<j), j});
            else tmp += (1ll<<j);
        }
        cont.pb({tmp, 0});

        tmp = cur + (1ll<<i);
        for (int j = i-1; j >= 0; j --)
            if ( BIT(b, j) ){
                cont.pb({tmp, j});
                tmp += (1ll<<j);
            }
        cont.pb({tmp, 0});

        break;
    } else if ( BIT(a, i) ) cur += (1ll<<i);

    if ( a == b ) cont.pb({a, 0});

    return cont;
}

pi get_xor(pi x, pi y){
    if ( x.se < y.se ) swap(x, y);
    y.fi >>= x.se;
    y.fi <<= x.se;
    return {x.fi^y.fi, x.se};
}

bool comp(pi x, pi y){
    if ( x.se < y.se ) swap(x, y);
    y.fi >>= x.se;
    y.fi <<= x.se;
    return x.fi == y.fi;
}

void solve(){
    cin >> a >> b >> c >> d;

    /// gen a -> b & c -> d
    all_ab = gen(a, b);
    all_cd = gen(c, d);

    /// gen xor a_b^c_d
    all_xor.clear();
    for (pi x : all_ab)
    for (pi y : all_cd)
        all_xor.pb(get_xor(x, y));

    sort(all_xor.begin(), all_xor.end(), [&](pi x, pi y){
        if ( x.fi == y.fi ) return x.se > y.se;
        else return x.fi < y.fi;
    });
    all_xor.erase(unique(all_xor.begin(), all_xor.end(), comp), all_xor.end());

    ull cnt = 0;
    for (auto x : all_xor) cnt += (1ll<<x.se);

    int k = ( cnt + 1 ) / 2;
    cnt = 0;
    for (int i = 0; i < all_xor.size(); i ++){
        int ans = all_xor[i].fi;
        if ( cnt + (1ll<<all_xor[i].se) >= k ){
            for (int j = all_xor[i].se-1; j >= 0; j --)
                if ( cnt + (1ll<<j) < k )
                    ans += (1ll<<j), cnt += (1ll<<j);
            cout << ans << '\n';
            return;
        }
        cnt += (1ll<<all_xor[i].se);
    }
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("medxor.inp", "r") ){
        freopen("medxor.inp", "r", stdin);
        freopen("medxor.out", "w", stdout);
    }

    int test;
    cin >> test;
    while ( test -- )
        solve();

    return 0;
}
