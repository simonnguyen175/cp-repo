#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
const int N = 1e6 + 5;

int n;
ll k;
struct order{
    ll s, d, r;
} a[N];
vector<ll> cont;
ll bit[2*N];

void update(int u, ll v){
    for (; u <= cont.size(); u += u&-u)
        bit[u] = max(bit[u], v);
}

ll get(int u){
    ll res = 0;
    for (; u >= 1; u -= u&-u)
        res = max(res, bit[u]);
    return res;
}

int id(ll x){
    auto it = upper_bound(cont.begin(), cont.end(), x);
    return it - cont.begin();
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n >> k;
    for (int i = 1; i <= n; i ++){
        cin >> a[i].s >> a[i].d >> a[i].r;
        cont.pb(a[i].s); cont.pb(a[i].s+a[i].d+k);
    }

    sort(cont.begin(), cont.end());
    cont.erase(unique(cont.begin(), cont.end()), cont.end());

    sort(a+1, a+1+n, [](order &x, order &y){
        return x.s < y.s;
    });

    ll ans = 0;
    for (int i = 1; i <= n; i ++){
        ll tmp = get(id(a[i].s)) + a[i].r;
        ans = max(ans, tmp);
        update(id(a[i].s+a[i].d+k), tmp);
    }
    cout << ans;

    return 0;
}
