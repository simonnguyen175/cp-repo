#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
const int oo = 1e9;

int n;
int a[N];
struct Node{
    int lazy;
    int val;
} st[N*4];

void down(int id){
    int t = st[id].lazy;
    for (int i = 0; i <= 1; i ++){
        st[id*2 + i].lazy = min(st[id*2 + i].lazy, t);
        st[id*2 + i].val = min(st[id*2 + i].val, t);
    }
    st[id].lazy = oo;
}

void update(int id, int l, int r, int u, int v, int val){
    if ( v < l || r < u ) return;

    if ( u <= l && r <= v ){
        st[id].val = min(st[id].val, val);
        st[id].lazy = min(st[id].lazy, val);
        return;
    }

    int mid = l + r >> 1;

    down(id);

    update(id * 2, l, mid, u, v, val);
    update(id * 2 + 1, mid + 1, r, u, v, val);

    st[id].val = min(st[id*2].val, st[id*2+1].val);
}

int get(int id, int l, int r, int u, int v){
    if ( v < l || r < u ) return oo;

    if ( u <= l && r <= v ){
        return st[id].val;
    }

    int mid = l + r >> 1;
    down(id);

    return min(get(id * 2, l, mid, u, v), get(id * 2 + 1, mid + 1, r, u, v));
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i ++)
        cin >> a[i];

    for (int i = 1; i <= 4*n; i ++)
        st[i].val = st[i].lazy = oo;
    update(1, 0, n, 0, 0, 0);

    for (int i = 0; i < n; i ++){
        int v = get(1, 0, n, i, i) + 1;
        update(1, 0, n, i + 1, i + a[i], v);
    }

    int ans = get(1, 0, n, n, n);

    if ( ans == oo ){
        cout << "CANNOT GET DESTINATION";
    }
    else cout << ans;

    return 0;
}
