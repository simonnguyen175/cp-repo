#include<bits/stdc++.h>
#define simon "longqueue"
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
const int N = 1e6 + 5;

int n, m, k;
int a[N], st[N];

void build(int id, int l, int r){
    if ( l == r ){
        st[id] = a[l];
        return;
    }
    int mid = ( l + r ) / 2;
    build(id*2, l, mid);
    build(id*2+1, mid+1, r);
    st[id] = st[id*2] + st[id*2+1];
}

void update(int id, int l, int r, int u, int v){
    if ( l > u || r < u ) return;
    if ( l == r ){
        st[id] += v;
        return;
    }
    int mid = ( l + r ) / 2;
    update(id*2, l, mid, u, v);
    update(id*2+1, mid+1, r, u, v);
    st[id] = st[id*2] + st[id*2+1];
}

int get(int id, int l, int r, int u, int v){
    if ( l > v || r < u ) return 0;
    if ( u <= l && r <= v ) return st[id];
    int mid = ( l + r ) / 2;
    return get(id * 2, l, mid, u, v) + get(id * 2 + 1, mid + 1, r, u, v);
}

void solve(){
    cin >> n >> k;
    for (int i = 1; i <= n; i ++){
        int x; cin >> x;
        if ( x >= k ) a[i] = 1;
        else a[i] = 0;
    }

    cin >> m;
    int nn = n + m, base = 1;
    build(1, 1, n + m);

    for (int i = 1; i <= m; i ++){
        int type, x;
        cin >> type;
        if ( type == 1 ){
            cin >> x;
            if ( x >= k ) a[++n] = 1; else a[++n] = 0;
            update(1, 1, nn, n, a[n]);
        }
        if ( type == 2 ){
            update(1, 1, nn, base, -a[base]);
            base ++;
        }
        if ( type == 3 ){
            cin >> x; x ++;
            cout << get(1, 1, nn, base, x + base - 2) << '\n';
        }
    }
}

int main(){
    FASTio
    if ( fopen(simon".inp", "r") ){
        freopen(simon".inp", "r", stdin);
        freopen(simon".out", "w", stdout);
    }

    solve();

    return 0;
}
