#include<bits/stdc++.h>
#define simon "continuous"
#define ll long long
using namespace std;
const int N = 1e5 + 5;

struct node{
    int l = 0, r = 0, sz = 0, res = 0;
    ll lval = LLONG_MAX, rval = LLONG_MIN, lazy = 0;
};

int n, q;
ll a[N];
node st[4 * N];

node combine(node a, node b){
    node c;
    c.sz = a.sz + b.sz;
    c.lval = a.lval; c.rval = b.rval;
    c.l = a.l; c.r = b.r;

    if ( a.l == a.sz && a.rval == b.lval ) c.l = a.sz + b.l;
    if ( b.r == b.sz && b.lval == a.rval ) c.r = b.sz + a.r;

    if ( a.rval == b.lval ) c.res = a.r + b.l;
    c.res = max({c.res, a.res, b.res});
    return c;
}

void build(int id, int l, int r){
    if ( l == r ){
        st[id].sz = st[id].l = st[id].r = st[id].res = 1;
        st[id].lval = st[id].rval = a[l] - l;
        return;
    }

    int mid = ( l + r ) / 2;
    build(id * 2, l, mid);
    build(id * 2 + 1, mid + 1, r);

    st[id] = combine(st[id * 2], st[id * 2 + 1]);
}

void down(int id){
    ll t = st[id].lazy;

    for (int i = 0; i <= 1; i ++){
        st[id * 2 + i].lazy += t;
        st[id * 2 + i].rval += t;
        st[id * 2 + i].lval += t;
    }

    st[id].lazy = 0;
}

void update(int id, int l, int r, int u, int v, ll d){
    if ( l > v || r < u ) return;
    if ( u <= l && r <= v ){
        st[id].lval += d;
        st[id].rval += d;
        st[id].lazy += d;
        return;
    }

    down(id);

    int mid = ( l + r ) / 2;

    update(id * 2, l, mid, u, v, d);
    update(id * 2 + 1, mid + 1, r, u, v, d);

    st[id] = combine(st[id * 2], st[id * 2 + 1]);
}

node get(int id, int l, int r, int u, int v){
    if ( l > v || r < u ) {node ans; return ans;}

    if ( u <= l && r <= v ) return st[id];

    down(id);

    int mid = ( l + r ) / 2;

    node ans, left, right;

    left = get(id * 2, l, mid, u, v);
    right = get(id * 2 + 1, mid + 1, r, u, v);

    ans = combine(left, right);

    return ans;
}

void solve(){
    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    build(1, 1, n);
    cin >> q;
    for (int i = 1; i <= q; i ++){
        char type;
        int l, r; ll d;
        cin >> type >> l >> r;
        if ( type == '+' ){
            cin >> d;
            update(1, 1, n, l, r, d);
        }
        else cout << get(1, 1, n, l, r).res << '\n';
    }
}

int main(){
    ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    if ( fopen(simon".inp", "r") ){
        freopen(simon".inp", "r", stdin);
        freopen(simon".out", "w", stdout);
    }
    solve();
    return 0;
}
