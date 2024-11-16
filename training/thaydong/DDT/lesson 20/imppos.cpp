#include<bits/stdc++.h>
#define pi pair<int, int>
#define fi first
#define se second
#define pb push_back
using namespace std;
const int N = 1e5 + 5;
const int MOD = 1e9 + 7;

int m, n, k;
pi a[N], st[4*N], f[N], g[N];
vector<int> cont;

int mul(int a, int b){
    return 1LL*a*b%MOD;
}

int add(int a, int b){
    a += b;
    if ( a >= MOD ) a -= MOD;
    return a;
}

int id(int x){
    return upper_bound(cont.begin(), cont.end(), x) - cont.begin();
}

pi combine(pi a, pi b){
    if ( a.fi != b.fi ) return ( a.fi > b.fi ? a : b );
    else return {a.fi, add(a.se, b.se)};
}

void update(int id, int l, int r, int u, pi val){
    if ( l > u || r < u ) return;
    if ( l == r ){
        if ( st[id].fi < val.fi ) st[id] = val;
        else st[id].se = add(st[id].se, val.se);
        return;
    }
    int mid = l + r >> 1;
    update(id*2, l, mid, u, val);
    update(id*2+1, mid+1, r, u, val);
    st[id] = combine(st[id*2], st[id*2+1]);
}

pi get(int id, int l, int r, int u, int v){
    if ( l > v || r < u ) return {-1, 0};
    if ( u <= l && r <= v ) return st[id];
    int mid = l + r >> 1;
    return combine(get(id*2, l, mid, u, v), get(id*2+1, mid+1, r, u, v));
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("imppos.inp", "r") ){
        freopen("imppos.inp", "r", stdin);
        freopen("imppos.out", "w", stdout);
    }

    cin >> m >> n >> k;
    for (int i = 1; i <= k; i ++){
        cin >> a[i].fi >> a[i].se;
        cont.pb(a[i].se);
    }
    sort(cont.begin(), cont.end());
    cont.erase(unique(cont.begin(), cont.end()), cont.end());
    sort(a+1, a+1+k);
    n = cont.size();

    // DOWN
    for (int i = 1; i <= 4*n; i ++) st[i] = {-1, 0};
    update(1, 1, n, 1, {0, 1});
    for (int i = 1; i <= k; i ++){
        f[i] = get(1, 1, n, 1, id(a[i].se));
        f[i].fi ++;
        update(1, 1, n, id(a[i].se), f[i]);
    }

    // UP
    for (int i = 1; i <= 4*n; i ++) st[i] = {-1, 0};
    update(1, 1, n, n, {0, 1});
    for (int i = k; i >= 1; i --){
        g[i] = get(1, 1, n, id(a[i].se), n);
        g[i].fi ++;
        update(1, 1, n, id(a[i].se), g[i]);
    }

    pi ans = get(1, 1, n, 1, n);
    int cnt = 0;
    for (int i = 1; i <= k; i ++)
        if ( f[i].fi + g[i].fi - 1 == ans.fi && mul(f[i].se, g[i].se) == ans.se )
            cnt ++;
    cout << cnt;

    return 0;
}
