#include<bits/stdc++.h>
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fi first
#define se second
#define ll long long
using namespace std;
const int N = 5e5 + 5;

ll n, m, q;
pair<ll, ll> a[N], qr[N];
ll ans[N], st[4 * N];

void update(ll id, ll l, ll r, ll u){
    if ( l > u || r < u ) return;
    if ( l == r && l == u ){
        st[id] ++;
        return;
    }

    int mid = ( l + r ) / 2;

    update(id * 2, l, mid, u);
    update(id * 2 + 1, mid + 1, r, u);
    st[id] = st[id * 2] + st[id * 2 + 1];
}

int get(ll id, ll l, ll r, ll u, ll sum){
    if ( l == r ) return l;

    int mid = ( l + r ) / 2;

    if ( sum + st[id * 2] >= u ) return get(id * 2, l, mid, u, sum);
    else return get(id * 2 + 1, mid + 1, r, u, sum + st[id * 2]);
}

void init(){
    cin >> n >> m >> q;
    for (int i = 1; i <= m; i ++) a[i].se = i;
    for (int i = 1; i <= n; i ++) {int host; cin >> host; a[host].fi ++;}
    for (int i = 1; i <= q; i ++) cin >> qr[i].fi, qr[i].se = i;
    sort(qr + 1, qr + 1 + q);
    sort(a + 1, a + 1 + m);
}

void solve(){
    a[m+1].fi = INT_MAX;
    int j = 1, current = n;


    for (int i = 1; i <= m; i ++){
        update(1, 1, m, a[i].se);
        while ( a[i].fi == a[i+1].fi ) update(1, 1, m, a[++i].se);

        if ( a[i+1].fi != INT_MAX ){
            int d = a[i+1].fi - a[i].fi;

            while ( j <= q && qr[j].fi - current <= d * i ){
                ll u = ( qr[j].fi - current ) % i;
                if ( u == 0 ) u = i;
                ans[qr[j].se] = get(1, 1, m, u, 0);
                j ++;
            }
            current += d * i;
        }
    }

    while ( j <= q ){
        ans[qr[j].se] = qr[j].fi % m;
        if ( qr[j].fi % m == 0 ) ans[qr[j].se] = m;
        j ++;
    }

    for (int i = 1; i <= q; i ++)
        cout << ans[i] << '\n';
}

int main(){
    FASTio
    init();
    solve();
    return 0;
}
