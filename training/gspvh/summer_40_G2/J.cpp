#include<bits/stdc++.h>
#define ll long long
#define pi pair<ll, ll>
#define fi first
#define se second
using namespace std;
const int N = 5e5 + 5;
const ll oo = 1e15;

int sub, n, Q;
pi a[N], ans[N];
struct node{
    pi pre;
    pi suf;
    ll res;
    int l, r;
    ll sum;
} st[4*N];
struct que{
    int l, r, b, id;
} q[N];

void maxi(pi &x, ll v, int pos){
    if ( x.fi < v ) x = {v, pos};
}

void maxiRes(node &ret, ll v, int l, int r){
    if ( ret.res < v )
        ret.res = v, ret.l = l, ret.r = r;
}

node combine(const node &Lef, const node &Rig){
    node ret = {{-oo, 0}, {-oo, 0}, -oo, 0, 0, -oo};

    if ( Lef.sum != -oo && Rig.sum != -oo )
        ret.sum = Lef.sum + Rig.sum;

    maxi(ret.pre, Lef.pre.fi, Lef.pre.se);
    maxi(ret.pre, Lef.sum + Rig.pre.fi, Rig.pre.se);
    maxi(ret.suf, Rig.suf.fi, Rig.suf.se);
    maxi(ret.suf, Rig.sum + Lef.suf.fi, Lef.suf.se);

    maxiRes(ret, Lef.res, Lef.l, Lef.r);
    maxiRes(ret, Rig.res, Rig.l, Rig.r);
    maxiRes(ret, Lef.suf.fi + Rig.pre.fi, Lef.suf.se, Rig.pre.se);

    return ret;
}

void update(int id, int l, int r, int u, ll v){
    if ( l > u || r < u ) return;
    if ( l == r ) { st[id] = {{v, u}, {v, u}, v, u, u, v}; return; }
    int mid = ( l + r ) / 2;
    update(id*2, l, mid, u, v);
    update(id*2+1, mid+1, r, u, v);
    st[id] = combine(st[id*2], st[id*2+1]);
}

node get(int id, int l, int r, int u, int v){
    if ( l > v || r < u ) return {{-oo, 0}, {-oo, 0}, -oo, 0, 0, -oo};
    if ( u <= l && r <= v ) return st[id];
    int mid = ( l + r ) / 2;
    return combine(get(id*2, l, mid, u, v), get(id*2+1, mid+1, r, u, v));
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("maxsum.inp", "r") ){
        freopen("maxsum.inp", "r", stdin);
        freopen("maxsum.out", "w", stdout);
    }

    cin >> sub >> n >> Q;
    for (int i = 1; i <= n; i ++)
        cin >> a[i].fi, a[i].se = i;

    for (int i = 1; i <= Q; i ++)
        cin >> q[i].l >> q[i].r >> q[i].b, q[i].id = i;

    sort(q+1, q+1+Q, [](que &a, que &b){
        return a.b > b.b;
    });
    sort(a+1, a+1+n, greater<pi>());

    for (int i = 1; i <= 4*n; i ++)
        st[i] = {{-oo, 0}, {-oo, 0}, -oo, 0, 0, -oo};

    int it = 1;
    node tmp;
    for (int i = 1; i <= Q; i ++){
        while ( it <= n && a[it].fi >= q[i].b ){
            update(1, 1, n, a[it].se, a[it].fi);
            it ++;
        }
        tmp = get(1, 1, n, q[i].l, q[i].r);
        if ( tmp.res == -oo ) ans[q[i].id] = {0, 0};
        else ans[q[i].id] = {tmp.l, tmp.r};
    }

    for (int i = 1; i <= Q; i ++)
        if ( !ans[i].fi ) cout << 0 << '\n';
        else cout << ans[i].fi << ' ' << ans[i].se << '\n';

    return 0;
}
