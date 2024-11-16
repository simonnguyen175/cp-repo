#include<bits/stdc++.h>
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
#define fi first
#define se second
#define ii pair<int, ll>
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

int n, a[N];
ii b[N], st[4 * N];

void update(int id, int l, int r, int u, int len, int cnt){
    if ( l > u || r < u ) return;
    if ( l == r && l == u ){
        st[id].fi = max(st[id].fi, len);
        st[id].se += cnt % MOD;
        st[id].se %= MOD;
        return;
    }

    int mid = ( l + r ) / 2;

    update(id * 2, l, mid, u, len, cnt);
    update(id * 2 + 1, mid + 1, r, u, len, cnt);

    st[id].fi = max(st[id * 2].fi, st[id * 2 + 1].fi);

    if ( st[id * 2].fi < st[id * 2 + 1].fi ) st[id].se = st[id * 2 + 1].se % MOD;
    if ( st[id * 2].fi > st[id * 2 + 1].fi ) st[id].se = st[id * 2].se % MOD;
    if ( st[id * 2].fi == st[id * 2 + 1].fi ) st[id].se = (st[id * 2].se % MOD + st[id* 2 + 1].se % MOD) % MOD;
    st[id].se %= MOD;
}

ii get(int id, int l, int r, int u, int v){
    if ( l > v || r < u ){
        ii res; res.fi = -1; res.se = 0;
        return res;
    }

    if ( u <= l && r <= v ){
        st[id].se %= MOD;
        return st[id];
    }

    int mid = ( l + r ) / 2;

    ii left = get(id * 2, l, mid, u, v); left.se %= MOD;
    ii right = get(id * 2 + 1, mid + 1, r, u, v); right.se %= MOD;
    ii res;


    res.fi = max(left.fi, right.fi);

    if ( left.fi < right.fi ) res.se = right.se % MOD;
    if ( left.fi > right.fi ) res.se = left.se % MOD;
    if ( left.fi == right.fi ) res.se = ( left.se % MOD + right.se % MOD ) % MOD;
    res.second %= MOD;

    return res;
}


void init(){
    cin >> n;
    for (int i = 1; i <= n; i ++){
        cin >> a[i];
        b[i].first = a[i]; b[i].second = i;
    }

    sort(b + 1, b + 1 + n);

    int cnt = 1;
    a[b[1].second] = 1;

    for (int i = 2; i <= n; i ++)
        if ( b[i].first == b[i-1].first )
            a[b[i].second] = cnt;
        else
            a[b[i].second] = ++cnt;
}

void solve(){
    ii ans;
    update(1, 0, n, 0, 0, 1);

    for (int i = 1; i <= n; i ++){
        ii tmp = get(1, 0, n, 0, a[i] - 1);
        tmp.se %= MOD;
        update(1, 0, n, a[i], tmp.fi + 1, tmp.se);
    }

    ans = get(1, 0, n, 0, n);
    ans.se %= MOD;

    cout << ans.se;
}

int main(){
    FASTio
    init();
    solve();
    return 0;
}
