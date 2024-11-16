#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5e2 + 5;

int m, n, q;
ll a[N][N];
struct node{
    ll val, lazy;
} st[N][4*N];

void apply(int t, int id, int l, int r, ll w){
    st[t][id].val += w * (r-l+1);
    st[t][id].lazy += w;
}

void down(int t, int id, int l, int r){
    int mid = l + r >> 1;
    ll w = st[t][id].lazy;

    apply(t, id*2, l, mid, w);
    apply(t, id*2+1, mid+1, r, w);

    st[t][id].lazy = 0;
}

void update(int t, int id, int l, int r, int u, int v, ll w){
    if ( l > v || r < u ) return;
    if ( u <= l && r <= v ){
        apply(t, id, l, r, w);
        return;
    }

    down(t, id, l, r);
    int mid = l + r >> 1;

    update(t, id*2, l, mid, u, v, w);
    update(t, id*2+1, mid+1, r, u, v, w);

    st[t][id].val = st[t][id*2].val + st[t][id*2+1].val;
}

ll get(int t, int id, int l, int r, int u, int v){
    if ( l > v || r < u ) return 0;
    if ( u <= l && r <= v ) return st[t][id].val;

    down(t, id, l, r);

    int mid = l + r >> 1;
    return get(t, id*2, l, mid, u, v) + get(t, id*2+1, mid+1, r, u, v);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("table.inp", "r") ){
        freopen("table.inp", "r", stdin);
        freopen("table.out", "w", stdout);
    }

    cin >> m >> n >> q;
    for (int i = 1; i <= m; i ++)
    for (int j = 1; j <= n; j ++){
        cin >> a[i][j];
        update(i, 1, 1, n, j, j, a[i][j]);
    }

    int type, x, y, u, v;
    ll w;
    while ( q -- ){
        cin >> type;
        if ( type == 1 ){
            cin >> x >> y >> u >> v >> w;
            for (int i = x; i <= u; i ++)
                update(i, 1, 1, n, y, v, w);
        }
        else{
            cin >> x >> y >> u >> v;
            ll res = 0;
            for (int i = x; i <= u; i ++){
//                cerr << i << ' ' << y << ' ' << v << ' ' << get(i, 1, 1, n, y, v) << '\n';
                res += get(i, 1, 1, n, y, v);
            }
            cout << res << '\n';
        }
    }

    return 0;
}
