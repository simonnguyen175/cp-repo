#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 5;
const int oo = 1e9;

int n;
int a[N];
struct node{
    int res, ver;
    int mn[2], mx[2];
} st[4*N];

int ckmn(int x, int y){
    if ( a[x] < a[y] ) return x;
    else return y;
}

int ckmx(int x, int y){
    if ( a[x] > a[y] ) return x;
    else return y;
}

node combine(node L, node R){
    node ret;
    ret.res = oo;

    if ( L.res < ret.res ) ret.res = L.res, ret.ver = L.ver;
    if ( R.res < ret.res ) ret.res = R.res, ret.ver = R.ver;
    if ( a[R.mn[0]] - a[L.mx[1]] < ret.res ){
        ret.res = a[R.mn[0]] - a[L.mx[1]];
        ret.ver = R.mn[0];
    }
    if ( a[R.mn[1]] - a[L.mx[0]] < ret.res ){
        ret.res = a[R.mn[1]] - a[L.mx[0]];
        ret.ver = L.mx[0];
    }
    for (int i = 0; i <= 1; i ++){
        ret.mn[i] = ckmn(L.mn[i], R.mn[i]);
        ret.mx[i] = ckmx(L.mx[i], R.mx[i]);
    }

    return ret;
}

void build(int id, int l, int r){
    if ( l == r ){
        st[id].res = oo;
        st[id].ver = l;
        st[id].mn[0] = l; st[id].mx[0] = l;
        st[id].mn[1] = 0, st[id].mx[1] = n+1;
        return;
    }
    int mid = l + r >> 1;
    build(id*2, l, mid);
    build(id*2+1, mid+1, r);
    st[id] = combine(st[id*2], st[id*2+1]);
    st[id].res = oo;
    st[id].ver = -1;
}

void update(int id, int l, int r, int u){
    if ( l > u || r < u ) return;
    if ( l == r ){
        st[id].mn[0] = 0, st[id].mx[0] = n+1;
        st[id].mn[1] = l, st[id].mx[1] = l;
        return;
    }
    int mid = l + r >> 1;
    update(id*2, l, mid, u);
    update(id*2+1, mid+1, r, u);
    st[id] = combine(st[id*2], st[id*2+1]);
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
    a[0] = oo, a[n+1] = -oo;
    build(1, 1, n);
    ll ans = 0;
    update(1, 1, n, 1);
    for (int i = 1; i < n; i ++){
        ans += st[1].res;
        update(1, 1, n, st[1].ver);
    }

    cout << ans;

    return 0;
}
