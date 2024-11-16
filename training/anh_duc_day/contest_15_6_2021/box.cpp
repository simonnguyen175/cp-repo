#include<bits/stdc++.h>
#define ll long long
#define ii pair<ll,ll>
#define fi first
#define se second
#define pb push_back
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

int n, m;
ii a[N], st[4 * N];
unordered_map<ll,int> cmp;
vector<ll> b;

void init(){
    ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i ++){
        cin >> a[i].fi >> a[i].se;
        b.pb(a[i].fi); b.pb(a[i].se);
    }
    sort(b.begin(), b.end());
    b.erase(unique(b.begin(), b.end()), b.end());
    m = b.size();
    for (int i = 0; i < m; i ++)
        cmp[b[i]] = i + 1;
    sort(a + 1, a + 1 + n, greater<ii>());
}

ii combine(ii a, ii b){
    if ( a.fi < b.fi ) return a;
        else if ( a.fi == b.fi ) return {a.fi, (a.se + b.se) % MOD};
            else return b;
}

void update(int id, int l, int r, int u, ii v){
    if ( l > u || r < u ) return;

    if ( l == r ){
        st[id] = combine(st[id], v);
        return;
    }

    int mid = ( l + r ) / 2;

    update(id * 2, l, mid, u, v);
    update(id * 2 + 1, mid + 1, r, u, v);
    st[id] = combine(st[id * 2], st[id * 2 + 1]);
}

ii get(int id, int l, int r, int u){
    if ( r < u ) return {LLONG_MAX, 0};
    if ( l >= u ) return st[id];
    if ( l == r ) return st[id];

    int mid = ( l + r ) / 2;

    ii left = get(id * 2, l, mid, u);
    ii right = get(id * 2 + 1, mid + 1, r, u);

    return combine(left, right);
}

void solve(){
    ll maxIn = 0;
    for (int i = 1; i <= 8 * n; i ++)
        st[i] = {LLONG_MAX, 0};

    ii res;
    for (int i = 1; i <= n; i ++){
        if ( a[i].fi > maxIn ) res = {a[i].se, 1};
        else{
            res = get(1, 1, m, cmp[a[i].fi]);
            res.fi += a[i].se - a[i].fi;
        }
        update(1, 1, m, cmp[a[i].se], res);
        maxIn = max(a[i].se, maxIn);
    }
    cout << st[1].se;
}

int main(){
    init();
    solve();
    return 0;
}
