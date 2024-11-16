#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5 + 5;

int n, d, q;
int a[N];
struct node{
    int val, lazy;
} st[4*N];

void build(int id, int l, int r){
    if ( l == r ){
        st[id].val = a[l];
        return;
    }
    int mid = l + r >> 1;
    build(id*2, l, mid);
    build(id*2+1, mid+1, r);
    st[id].val = max(st[id*2].val, st[id*2+1].val);
}

void down(int id){
    int t = st[id].lazy;
    st[id].lazy = 0;
    st[id*2].val += t, st[id*2].lazy += t;
    st[id*2+1].val += t, st[id*2+1].lazy += t;
}

void update(int id, int l, int r, int u, int v, int val){
    if ( l > v || r < u ) return;
    if ( u <= l && r <= v ){
        st[id].val += val;
        st[id].lazy += val;
        return;
    }
    down(id);
    int mid = l + r >> 1;
    update(id*2, l, mid, u, v, val);
    update(id*2+1, mid+1, r, u, v, val);
    st[id].val = max(st[id*2].val, st[id*2+1].val);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n >> d >> q;
    ll s = 0;
    for (int i = 1; i <= n; i ++){
        cin >> a[i];
        s += a[i];
    }

    build(1, 1, n);
    cout << max(((s%d) ? s/d+1 : s/d), 1LL*st[1].val) << '\n';
    int pre = 0;
    while ( q -- ){
        int l, r;
        cin >> l >> r;
        update(1, 1, n, l, r, -1);
        s -= r-l+1;
        cout << max(((s%d) ? s/d+1 : s/d), 1LL*st[1].val) + (++pre)<< '\n';
    }

    return 0;
}
