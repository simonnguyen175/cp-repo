#include<bits/stdc++.h>
#define ll long long
#define pi pair<ll, ll>
#define fi first
#define se second
#define pb push_back
#define simon "group"
using namespace std;
const int N = 1e5 + 5;

ll t, n, k, r;
ll a[N], id[N];
pi bit[N];
vector<pi> cont;

void update(int u, ll x){
	for (; u <= n; u += (u & (-u)))
        bit[u].fi += x, bit[u].se++;
}

pi get(int u){
	pi res = {0 , 0};
	for (; u >= 1; u -= (u & (-u)))
        res.fi += bit[u].fi, res.se += bit[u].se;
	return res;
}

bool check(ll g, ll sl){
    int lo = 1, hi = n, p = 0;
    while ( lo <= hi ){
        int mid = ( lo + hi ) / 2;
        if ( cont[mid].fi <= g ) p = mid, lo = mid + 1;
        else hi = mid - 1;
    }
    pi tmp = get(p);
    if ( tmp.fi + (sl-tmp.se) * g >= g * k ) return true;
    return false;
}

void init(){
    cin >> n >> k >> r;

    for (int i = 1; i <= n; i ++) bit[i] = {0, 0};

    cont.clear();
    cont.pb({0 , 0});
	for (int i = 1; i <= n; i ++){
        cin >> a[i];
        cont.pb({a[i] , i});
    }
	sort(cont.begin(), cont.end());
	for (int i = 1; i < cont.size(); i ++)
        id[cont[i].se] = i;

    for (int i = 1; i <= r; i ++)
        update(id[i], a[i]);
}

void solve(){
    ll res = 0;
    for (int i = r + 1; i <= n; i ++){
        update(id[i], a[i]);
        ll lo = res + 1, hi = 1e14;
        while ( lo <= hi ){
            ll mid = ( lo + hi ) / 2;
            if ( check(mid, i) ) lo = mid + 1, res = mid;
            else hi = mid - 1;
        }
        cout << res << ' ';
    }
    cout << '\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen(simon".in", "r") ){
        freopen(simon".in", "r", stdin);
        freopen(simon".out", "w", stdout);
    }

    cin >> t;
    while ( t -- ){
        init();
        solve();
    }

    return 0;
}
