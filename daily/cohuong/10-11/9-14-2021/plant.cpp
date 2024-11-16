#include<bits/stdc++.h>
#define simon "plant"
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
const int N = 1e6 + 5;

int n;
struct node{
    int val, lazy;
} st[4*N];

void down(int id){
    int t = st[id].lazy;
    st[id*2].val += t; st[id*2].lazy += t;
    st[id*2+1].val += t; st[id*2+1].lazy += t;
    st[id].lazy = 0;
}

void update(int id, int l, int r, int u, int v, int val){
    if ( v < l || u > r ) return;
    if ( u <= l && r <= v ){
        st[id].val += val;
        st[id].lazy += val;
        return;
    }
    int mid = ( l + r ) / 2;
    down(id);
    update(id*2, l, mid, u, v, val);
    update(id*2+1, mid+1, r, u, v, val);
    st[id].val = st[id*2].val + st[id*2+1].val;
}

int get(int id, int l, int r, int u){
    if ( u < l || r < u ) return 0;
    if ( l == r && l == u ) return st[id].val;
    int mid = (l+r)/2;
    down(id);
    return get(id*2, l, mid, u)+get(id*2+1, mid+1, r, u);
}

int main(){
    FASTio
    if ( fopen(simon".inp", "r") ){
        freopen(simon".inp", "r", stdin);
        freopen(simon".out", "w", stdout);
    }

    cin >> n;

    for (int i = 1; i <= n; i ++){
        int l, r;
        cin >> l >> r;
        int cntl, cntr;
        cntl = get(1, 1, N-1, l);
        cntr = get(1, 1, N-1, r);
        cout << cntl + cntr << '\n';
        update(1, 1, N-1, l, l, -cntl);
        update(1, 1, N-1, r, r, -cntr);
        update(1, 1, N-1, l + 1, r - 1, 1);
    }

    return 0;
}
