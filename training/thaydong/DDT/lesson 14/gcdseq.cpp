#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;

int n, m;
int a[N], l[N], r[N], k[N];
struct node{
    int val, lazy;
} st[4*N];

void build(int id, int l, int r){
    if ( l == r ){
        st[id].val = a[l];
        st[id].lazy = 1;
        return;
    }
    int mid = (l+r)/2;
    build(id*2, l, mid);
    build(id*2+1, mid+1, r);
    st[id].val = __gcd(st[id*2+1].val, st[id*2].val);
    st[id].lazy = 1;
}

void down(int id){
    int t1 = st[id].lazy, t2 = st[id].lazy;

    t1 = t1 / __gcd(t1, st[2*id].val);
    st[id*2].lazy *= t1;
    st[id*2].val *= t1;

    t2 = t2 / __gcd(t2, st[2*id+1].val);
    st[id*2+1].lazy *= t2;
    st[id*2+1].val *= t2;

    st[id].lazy = 1;
}

void update(int id, int l, int r, int u, int v, int val){
    if ( v < l || r < u ) return;

    if ( u <= l && r <= v ){
        int nval = val / __gcd(st[id].val, val);
        st[id].val *= nval;
        st[id].lazy *= nval;
        return;
    }

    int mid = ( l + r ) / 2;

    down(id);

    update(id * 2, l, mid, u, v, val);
    update(id * 2 + 1, mid + 1, r, u, v, val);

    st[id].val = __gcd(st[id*2].val, st[id*2+1].val);
}

int get(int id, int l, int r, int u, int v){
    if ( l > v || r < u ) return 0;

    if ( u <= l && r <= v ) return st[id].val;

    int mid = ( l + r )/2;
    down(id);

    return __gcd(get(id*2, l, mid, u, v), get(id*2+1, mid+1, r, u, v));
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i ++)
        a[i] = 1;

    build(1, 1, n);

    for (int i = 1; i <= m; i ++){
        cin >> l[i] >> r[i] >> k[i];
        update(1, 1, n, l[i], r[i], k[i]);
    }

    for (int i = 1; i <= m; i ++){
        if ( get(1, 1, n, l[i], r[i]) != k[i] ){
            cout << -1;
            return 0;
        }
    }

    for (int i = 1; i <= n; i ++)
        cout << get(1, 1, n, i, i) << ' ';

    return 0;
}
