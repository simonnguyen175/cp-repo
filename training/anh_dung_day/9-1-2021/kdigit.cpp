#include<bits/stdc++.h>
#define ll long long
#define BIT(mask, k) ((mask>>k)&1)
#define pi pair<ll, ll>
#define fi first
#define se second
using namespace std;
const ll MOD = 998244353;

ll l, r, k;
ll a[20], Pow[20], f[20][1030][2][2], g[20][1030][2][2];

pi calc(int id, int mask, bool ok1, bool ok2){
    if ( id > 19 ) return {0, 1};

    if ( f[id][mask][ok1][ok2] != -1)
        return {f[id][mask][ok1][ok2], g[id][mask][ok1][ok2]};

    ll s = 0, cnt = 0, num = __builtin_popcount(mask);
    for (int c = 0; c <= max(1LL*ok2*9, a[id]); c ++){
        if ( !BIT(mask, c) && num == k ) continue;
        int nmask = mask|(1<<c);
        if ( !ok1 && c == 0 ) nmask = 0;
        pi tmp = calc(id + 1, nmask, ok1|(c!=0), ok2|(c<a[id]));
        cnt = ( cnt + tmp.se ) % MOD;
        s = ( s + c * Pow[19-id] % MOD * tmp.se % MOD + tmp.fi ) % MOD;
    }

    f[id][mask][ok1][ok2] = s;
    g[id][mask][ok1][ok2] = cnt;

    return {s, cnt};
}

ll get(ll x){
    for (int i = 19; i >= 1; i --) a[i] = x % 10, x /= 10;
    memset(f, -1, sizeof f); memset(g, -1, sizeof g);
    return calc(1, 0, 0, 0).fi;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    Pow[0] = 1;
    for (int i = 1; i <= 19; i ++)
        Pow[i] = Pow[i-1] * 10 % MOD;

    cin >> l >> r >> k;

    cout << (get(r) - get(l-1) + MOD) % MOD;

    return 0;
}
