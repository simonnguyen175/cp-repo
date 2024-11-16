#include<bits/stdc++.h>
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
const int N = 1e6 + 5;

struct node{
    int mx, amo;
};

int n, m, a[N];
node st[4*N];

void init(int id, int l, int r){
    if ( l == r ){
        st[id].mx = a[l];
        return;
    }

    int mid = ( l + r ) / 2;

    init(id * 2, l, mid);
    init(id * 2 + 1, mid + 1, r);

    st[id].mx = max(st[id * 2].mx, st[id * 2 + 1].mx);
}

int get_kth(int id, int l, int r, int u){
    if ( st[id].amo == 0 && u <= r - l + 1 ) return l + u - 1;

    int mid = ( l + r ) / 2;

    if ( mid - l + 1 - st[id * 2].amo >= u ) return get_kth(id * 2, l, mid, u);
    else return get_kth(id * 2 + 1, mid + 1, r, u - (mid - l + 1 - st[id * 2].amo));
}

void del_update(int id, int l, int r, int u){
    if ( u < l || u > r ) return;

    if ( l == r ){
        st[id].mx = -1;
        st[id].amo =  1;
        return;
    }

    st[id].amo ++;

    int mid  = ( l + r ) / 2;

    del_update(id * 2, l, mid, u);
    del_update(id * 2 + 1, mid + 1, r, u);

    st[id].mx = max(st[id * 2].mx, st[id * 2 + 1].mx);
}

int get_pos(int id, int l, int r, int u){
    if ( l == r ) return l;

    int mid = ( l + r ) / 2;

    if ( st[id * 2].amo >= u ) return get_pos(id * 2, l, mid, u);
    else return get_pos(id * 2 + 1, mid + 1, r, u - st[id * 2].amo);
}

int getmax(int id, int l, int r, int u, int v){
    if ( l > v || r < u ) return 0;

    if ( u <= l && r <= v ) return st[id].mx;

    int mid = ( l + r ) / 2;

    return max(getmax(id * 2, l, mid, u, v), getmax(id * 2 + 1, mid + 1, r, u ,v));
}

int main(){
    FASTio

    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];

    n ++;
    del_update(1, 1, n, n);
    init(1, 1, n);

    cin >> m;
    for (int i = 1; i <= m; i ++){
        char type;
        int u, v;

        cin >> type;
        if ( type == 'Q' ){
            cin >> u >> v;
            u = get_pos(1, 1, n, u);
            v = get_pos(1, 1, n, v + 1) - 1;
            //cout << u << ' ' << v << '\n';
            v = getmax(1, 1, n, u, v);
            if ( v <= 0 ) cout << "NONE" << '\n';
            else cout << v << '\n';
        }
        else{
            cin >> u;
            u = get_kth(1, 1, n, u);
            del_update(1, 1, n, u);
        }
    }

    return 0;
}
