#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define pi pair<ll, ll>
#define fi first
#define se second
using namespace std;
const int N = 1e5 + 5;
const ll oo = 1e16;

int n, q;
int x[N], t[N];
pi st[4*N];
ll res[N];
vector<int> cont;

int id(int x){
    return upper_bound(cont.begin(), cont.end(), x) - cont.begin();
}

void update(int u, int v, int add){
    int id = 1, l = 1, r = n;
    while ( l <= r ){
        st[id].fi += add;
        st[id].se += 1LL * add * v;

        if ( l == r ) break;

        int mid = l + r >> 1;
        if ( u <= mid ) r = mid, id *= 2;
        else l = mid + 1, id = id*2+1;
    }
}

ll get(int k){
    int id = 1, l = 1, r = n;
    ll res = 0;
    if ( st[1].fi < k ) return oo;

    while ( l <= r ){
        if ( l == r ){
            if ( st[id].fi )
                res += 1LL * st[id].se/st[id].fi * k;
            k = 0;
            break;
        }
        int mid = l + r >> 1;
        if ( st[id*2].fi >= k ) id *= 2, r = mid;
        else{
            k -= st[id*2].fi, res += st[id*2].se;
            l = mid + 1, id = id*2+1;
        }
    }

    if ( k ) return oo;
    else return res;
}

void calc(int l, int r, int optl, int optr){
    int mid = l + r >> 1;
    ll cur = oo, tmp;
    int pos = optr;
    for (int i = optr; i >= optl; i --){
        tmp = x[i] + get(mid);
        if ( tmp < cur ) cur = tmp, pos = i;
        update(id(t[i]), t[i], -1);
    }
    res[mid] = cur;

    for (int i = optl; i <= pos; i ++)
        update(id(t[i]), t[i], 1);
    if ( l < mid ) calc(l, mid-1, optl, pos);
    for (int i = pos+1; i <= optr; i ++)
        update(id(t[i]), t[i], 1);
    if ( r > mid ) calc(mid+1, r, pos, optr);
}

void solve(){
    cin >> n;
    cont.clear();
    for (int i = 1; i <= n; i ++){
        cin >> x[i] >> t[i];
        cont.pb(t[i]);
    }

    sort(cont.begin(), cont.end());
    cont.erase(unique(cont.begin(), cont.end()), cont.end());
    for (int i = 1; i <= 4*n; i ++) st[i] = {0, 0};
    for (int i = 1; i <= n; i ++)
        update(id(t[i]), t[i], 1);
    calc(1, n, 1, n);

    cin >> q;
    while ( q -- ){
        ll sta;
        cin >> sta;
        cout << upper_bound(res+1, res+1+n, sta) - res - 1 << ' ';
    }
    cout << '\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("U.inp", "r") ){
        freopen("U.inp", "r", stdin);
        freopen("U.out", "w", stdout);
    }

    int test;
    cin >> test;
    while ( test -- ) solve();

    return 0;
}
