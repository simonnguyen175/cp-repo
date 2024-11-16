#include<bits/stdc++.h>
#define ll long long
#define pi pair<int, int>
#define fi first
#define se second
#define pb push_back
using namespace std;
const int N = 1e5 + 5;
const ll oo = 1e18;

int n;
pi l[N], r[N];
ll t[N], it[4*N], f[N];
vector<int> st[N], en[N];

void update(int id, int l, int r, int u, ll v){
    if ( l > u || r < u ) return;
    if ( l == r ){
        it[id] = v;
        return;
    }
    int mid = l + r >> 1;
    update(id*2, l, mid, u, v);
    update(id*2+1, mid+1, r, u, v);
    it[id] = min(it[id*2], it[id*2+1]);
}

ll get(int id, int l, int r, int u, int v){
    if ( l > v || r < u ) return oo;
    if ( u <= l && r <= v ) return it[id];
    int mid = l + r >> 1;
    return min(get(id*2, l, mid, u, v), get(id*2+1, mid+1, r, u, v));
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i ++){
        cin >> t[i] >> l[i].fi >> l[i].se >> r[i].fi >> r[i].se;
        if ( r[i].fi == i ){
            if ( r[i].se != i ) st[r[i].fi+1].pb(i), en[r[i].se].pb(i);
        }
        else st[r[i].fi].pb(i), en[r[i].se].pb(i);
    }

    for (int i = 1; i <= 4*n; i ++) it[i] = oo;

    f[1] = 0;

    for (int i = 2; i <= n; i ++){
        for (int j : st[i])
            if ( f[j] != oo ) update(1, 1, n, j, f[j] + t[j] - j);
        f[i] = get(1, 1, n, l[i].fi, l[i].se);
        if ( f[i] == oo ) cout << -1 << ' ';
        else f[i] += t[i] + i, cout << f[i] << ' ';
        for (int j : en[i]) update(1, 1, n, j, oo);
    }

    return 0;
}
