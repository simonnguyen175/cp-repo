#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;

int n, q;
int a[N], b[N], st[4*N], lazy[4*N];

void down(int id){
    st[id*2] += lazy[id], lazy[id*2] += lazy[id];
    st[id*2+1] += lazy[id], lazy[id*2+1] += lazy[id];
    lazy[id] = 0;
}

void update(int id, int l, int r, int u, int v, int val){
    if ( u > v ) return;
    if ( l > v || r < u ) return;
    if ( u <= l && r <= v ){
        st[id] += val;
        lazy[id] += val;
        return;
    }
    down(id);
    int mid = l + r >> 1;
    update(id*2, l, mid, u, v, val);
    update(id*2+1, mid+1, r, u, v, val);
    st[id] = max(st[id*2], st[id*2+1]);
}

int get(int id, int l, int r, int u, int v){
    if ( l > v || r < u ) return 0;
    if ( u <= l && r <= v ) return st[id];
    down(id);
    int mid = l + r >> 1;
    return max(get(id*2, l, mid, u, v), get(id*2+1, mid+1, r, u, v));
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("trash.inp", "r") ){
        freopen("trash.inp", "r", stdin);
        freopen("trash.out", "w", stdout);
    }

    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    for (int i = 1; i <= n; i ++)
        cin >> b[i];

    for (int i = 1; i <= n; i ++)
        update(1, 1, N-5, a[i], b[i], 1);

    cout << n - st[1] << '\n';
    cin >> q;
    while ( q -- ){
        int id, c, d;
        cin >> id >> c >> d;

        update(1, 1, N-5, a[id], b[id], -1);

        a[id] = c, b[id] = d;

        update(1, 1, N-5, a[id], b[id], 1);

        cout << n - st[1] << '\n';
    }

    return 0;
}
