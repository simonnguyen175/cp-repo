#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5 + 5;
const ll oo = 1e15;

int n, m;
ll st[4*N];

void update(int id, int l, int r, int u, int v){
    if ( l > u || r < u ) return;
    if ( l == r ){
        st[id] += v;
        return;
    }
    int mid = l + r >> 1;
    update(id*2, l, mid, u, v);
    update(id*2+1, mid+1, r, u, v);
    st[id] = min(st[id*2], st[id*2+1]);
}

ll get(int id, int l, int r, int u, int v){
    if ( l > v || r < u ) return oo;
    if ( u <= l && r <= v ) return st[id];
    int mid = l + r >> 1;
    return min(get(id*2, l, mid, u, v), get(id*2+1, mid+1, r, u, v));
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n >> m;
    int type, l, r;
    while ( m -- ){
        cin >> type >> l >> r;
        if ( type == 1 ) update(1, 1, n, l, r);
        else{
            if ( l <= r ) cout << get(1, 1, n, l, r) << '\n';
            else cout << min(get(1, 1, n, l, n), get(1, 1, n, 1, r)) << '\n';
        }
    }

    return 0;
}
