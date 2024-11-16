#include<bits/stdc++.h>
#define ll long long
#define pi pair<ll, ll>
#define fi first
#define se second
using namespace std;
const int N = 1e5 + 5;

int n, d, q;
ll a[N];
struct{
    ll mx, lazy;
} st[4*N];

void down(int id){
    ll t = st[id].lazy; st[id].lazy = 0;
    st[id*2].mx += t, st[id*2].lazy += t;
    st[id*2+1].mx += t, st[id*2+1].lazy += t;
}

void build(int id, int l, int r){
    if ( l == r ){
        st[id].mx = a[l], st[id].lazy = 0;
        return;
    }

    int mid = l + r >> 1;

    build(id * 2, l, mid);
    build(id * 2 + 1, mid + 1, r);

    st[id].mx = max(st[id*2].mx, st[id*2+1].mx);
}

void update(int id, int l, int r, int u, int v, ll val){
    if ( l > v || r < u ) return;
    if ( u <= l && r <= v ){
        st[id].mx += val;
        st[id].lazy += val;
        return;
    }

    down(id);

    int mid = l + r >> 1;

    update(id * 2, l, mid, u, v, val);
    update(id * 2 + 1, mid + 1, r, u, v, val);

    st[id].mx = max(st[id*2].mx, st[id*2+1].mx);
}

ll minP(ll x){
    if ( x % d == 0 ) return x / d;
    else return x / d + 1;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n >> d >> q;
    ll sum = 0;
    for (int i = 1; i <= n; i ++)
        cin >> a[i], sum += a[i];

    build(1, 1, n);

    cout << max(st[1].mx, minP(sum)) << '\n';

    for (int i = 1; i <= q; i ++){
        int l, r; cin >> l >> r;
        update(1, 1, n, l, r, -1);
        sum -= ( r - l + 1 );
        cout << max(st[1].mx, minP(sum)) + i << '\n';
    }

    return 0;
}
