#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5 + 5;

int t, n, m;
ll a[N];
struct node{
    ll res, l, r, lazy;
} st[4*N];

node combine(node a, node b){
    ll l = a.l, r = b.r;
    ll res = a.res + b.res - min(a.r, b.l);
    return {res, l, r, 0};
}

void build(int id, int l, int r){
    if ( l == r ){
        st[id] = {a[l], a[l], a[l], 0};
        return;
    }
    int mid = l + r >> 1;
    build(id*2, l, mid);
    build(id*2+1, mid+1, r);
    st[id] = combine(st[id*2], st[id*2+1]);
}

void down(int id){
    int t = st[id].lazy;
    st[id].lazy = 0;

    st[id*2].lazy += t, st[id*2].res += t, st[id*2].l += t, st[id*2].r += t;
    st[id*2+1].lazy += t, st[id*2+1].res += t, st[id*2+1].l += t, st[id*2+1].r += t;
}

void update(int id, int l, int r, int u, int v, ll val){
    if ( l > v || r < u ) return;
    if ( u <= l && r <= v ){
        st[id].lazy += val; st[id].res += val;
        st[id].l += val; st[id].r += val;
        return;
    }
    int mid = l + r >> 1;
    down(id);
    update(id*2, l, mid, u, v, val);
    update(id*2+1, mid+1, r, u, v, val);
    st[id] = combine(st[id*2], st[id*2+1]);
}

node get(int id, int l, int r, int u, int v){
    if ( l > v || r < u ) return {0, 0, 0, 0};
    if ( u <= l && r <= v ) return st[id];
    int mid = l + r >> 1;
    down(id);
    return combine(get(id*2, l, mid, u, v), get(id*2+1, mid+1, r, u, v));
}

void solve(){
    cin >> n >> m;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];

    build(1, 1, n);

    for (int i = 1; i <= m; i ++){
        int type, L, R, k;
        cin >> type;
        if ( type == 1 ) { cin >> L >> R >> k; update(1, 1, n, L, R, k); }
        else{
            cin >> L >> R;
            auto tmp = get(1, 1, n, L, R);
            cout << tmp.res << '\n';
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("construct.inp", "r") ){
        freopen("construct.inp", "r", stdin);
        freopen("construct.out", "w", stdout);
    }

    cin >> t;
    while ( t -- )
        solve();

    return 0;
}
