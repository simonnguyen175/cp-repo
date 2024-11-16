#include<bits/stdc++.h>
using namespace std;
const int N = 5e4 + 5;
const int oo = 1e9;

struct node{
    int val, lazy;
} st[N * 4];
int n, m;

void down(int id){
    int t = st[id].lazy;
    st[id*2].lazy += t;
    st[id*2].val += t;

    st[id*2+1].lazy += t;
    st[id*2+1].val += t;

    st[id].lazy = 0;
}

void update(int id, int l, int r, int u, int v, int val){
    if (v < l || r < u ) return;

    if ( u <= l && r <= v ){
        st[id].val += val;
        st[id].lazy += val;
        return;
    }

    int mid = ( l + r ) / 2;

    down(id);

    update(id * 2, l, mid, u, v, val);
    update(id * 2 + 1, mid + 1, r, u, v ,val);

    st[id].val = max(st[id*2].val, st[id*2+1].val);
}

int get(int id, int l, int r, int u, int v){
    if ( v < l || r < u ) return -oo;

    if ( u <= l && r <= v ) return st[id].val;

    int mid = ( l + r ) / 2;
    down(id);

    return max(get(id * 2, l, mid, u, v), get(id * 2 + 1, mid + 1, r, u, v ));
}

int main(){
    ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= m; i ++){
        bool type;
        int u, v, k;
        cin >> type;
        if ( !type ){
            cin >> u >> v >> k;
            update(1, 1, n, u, v, k);
        }
        else{
            cin >> u >> v;
            cout << get(1, 1, n, u, v) << '\n';
        }
    }
}
