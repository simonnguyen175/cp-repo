#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 5;
const int MOD = 998244353;

int t, n, k, q;
struct node{
    int mn, sum, smn, lazy;
} st[4*N];
int f0[N], pw[N];

int add(int a, int b){
    a += b;
    if ( a >= MOD ) a -= MOD;
    if ( a < 0 ) a += MOD;
    return a;
}

int mul(int a, int b){
    return 1ll * a * b % MOD;
}

node combine(node L, node R){
    node res;
    res.sum = add(L.sum, R.sum);
    if ( L.mn == R.mn ){
        res.mn = L.mn, res.smn = add(L.smn, R.smn);
    }
    else if ( L.mn < R.mn ){
        res.mn = L.mn, res.smn = L.smn;
    }
    else res.mn = R.mn, res.smn = R.smn;
    res.lazy = n+1;
    return res;
}

void build(int id, int l, int r){
    if ( l == r ){
        if ( f0[l] ) st[id].mn = 0, st[id].sum = 0, st[id].smn = add(pw[l], -pw[l-1]);
        else st[id].mn = n+1, st[id].sum = add(0, -pw[l]+pw[l-1]), st[id].smn = add(pw[l], -pw[l-1]);
        st[id].lazy = n+1;
        return;
    }
    int mid = l + r >> 1;
    build(id*2, l, mid);
    build(id*2+1, mid+1, r);
    st[id] = combine(st[id*2], st[id*2+1]);
}

void upd(int id, int l, int r, int val){
    if ( val == n + 1 ) return;
//    cout << "update node " << id << ' ' << l << ' ' << r << ' ' << val << '\n';
    st[id].lazy = min(st[id].lazy, val);
    if ( st[id].mn < val ){
        st[id].sum = add(mul(st[id].mn, st[id].smn), mul(add(pw[r],-pw[l-1]-st[id].smn), val));
    }
    else{
        st[id].sum = mul(add(pw[r], -pw[l-1]), val);
        st[id].smn = add(pw[r], -pw[l-1]);
        st[id].mn = val;
    }
//    cout << " -> " << st[id].mn << ' ' << st[id].sum << ' ' << st[id].smn << ' ' << st[id].lazy << '\n';
}

void down(int id, int l, int r){
    int mid = l + r >> 1;
    upd(id*2, l, mid, st[id].lazy);
    upd(id*2+1, mid+1, r, st[id].lazy);
    st[id].lazy = n+1;
}

void update(int id, int l, int r, int u, int v, int val){
    if ( l > v || r < u ) return;
    if ( u <= l && r <= v ){
        upd(id, l, r, val);
        return;
    }
    down(id, l, r);
    int mid = l + r >> 1;
    update(id*2, l, mid, u, v, val);
    update(id*2+1, mid+1, r, u, v, val);
    st[id] = combine(st[id*2], st[id*2+1]);
}

node get(int id, int l, int r, int u, int v){
    if ( l > v || r < u ) return {n+1, 0, 0, n+1};
    if ( u <= l && r <= v ) return st[id];
    down(id, l, r);
    int mid = l + r >> 1;
    return combine(get(id*2, l, mid, u, v), get(id*2+1, mid+1, r, u, v));
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    freopen("covid19.inp", "r", stdin);
    freopen("covid19.out", "w", stdout);

    cin >> t >> n >> k >> q;
    pw[0] = 1;
    for (int i = 1; i <= n; i ++)
        pw[i] = mul(pw[i-1], n + 1);
    for (int i = 1; i <= n; i ++)
        pw[i] = add(pw[i], pw[i-1]);
    for (int i = 1, x; i <= k; i ++)
        cin >> x, f0[x] = 1;
    build(1, 1, n);

    cout << st[1].sum << '\n';

    char type;
    int l, r;
    while ( q -- ){
        cin >> type >> l >> r;
        if ( type == 'D' ){
            int mn = min(get(1, 1, n, l, l).mn, get(1, 1, n, r, r).mn);
            if ( mn != n + 1 ){
//            cout << "pair upd " << l << ' ' << r << ' ' << mn+1 << '\n';
                update(1, 1, n, l, l, mn+1);
                update(1, 1, n, r, r, mn+1);
            }
            cout << st[1].sum << '\n';
        }
        else{
            int mn = get(1, 1, n, l, r).mn;
            if ( mn != n + 1 ) update(1, 1, n, l, r, mn+1);
            cout << st[1].sum << '\n';
        }
    }

    return 0;
}
