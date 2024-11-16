#include<bits/stdc++.h>
#define simon "games"
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
const int N = 1e5 + 5;

int n, m;
int a[N];
struct node{
    int val, lazy;
} st[4*N];


void down(int id){
    int t = st[id].lazy;
    st[id*2].lazy = max(st[id*2].lazy, t); st[id*2].val = max(st[id*2].val, t);
    st[id*2+1].lazy = max(st[id*2+1].lazy, t); st[id*2+1].val = max(st[id*2+1].val, t);
    st[id].lazy = 0;
}

void build(int id, int l, int r){
    if ( l == r ){
        st[id].val = a[l];
        return;
    }
    int mid = (l+r)/2;
    build(id*2, l, mid);
    build(id*2+1, mid+1, r);
    st[id].val = max(st[id*2].val, st[id*2+1].val);
}

void update(int id, int l, int r, int u, int v, int x){
    if ( l > v || r < u ) return;
    if ( u <= l && r <= v ){
        st[id].val = x;
        st[id].lazy = x;
        return;
    }
    int mid = (l+r)/2;
    down(id);
    update(id*2, l, mid, u, v, x);
    update(id*2+1, mid+1, r, u, v, x);
    st[id].val = max(st[id*2].val, st[id*2+1].val);
}

int get(int id, int l, int r, int u, int v){
    if ( v < l || r < u ) return 0;
    if ( u <= l && r <= v ) return st[id].val;
    int mid = (l+r)/2;
    down(id);
    return max(get(id*2, l, mid, u, v), get(id*2+1, mid+1, r, u, v));
}

int main(){
    FASTio
    if ( fopen(simon".inp", "r") ){
        freopen(simon".inp", "r", stdin);
        freopen(simon".out", "w", stdout);
    }

    cin >> n >> m;
    for (int i = 1; i <= n; i ++) cin >> a[i];

    build(1, 1, n);

    for (int i = 1; i <= m; i ++){
        int p, len;
        cin >> p >> len;
        int l = p, r = p + len - 1;
        int mxh = get(1, 1, n, l, r);
        cout << mxh + 1 << '\n';
        update(1, 1, n, l, r, mxh + 1);
    }

    return 0;
}
