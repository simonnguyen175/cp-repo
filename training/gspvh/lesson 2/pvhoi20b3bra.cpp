#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
const int oo = 1e9;

int n, q;
string s;
struct node{
    int mn, mx, lazy;
} st[4*N];
int a[N];

void down(int id){
    int t = st[id].lazy;
    st[id].lazy = 0;
    st[id*2].mn += t, st[id*2].mx += t, st[id].lazy += t;
    st[id*2+1].mn += t, st[id*2+1].mx += t, st[id*2+1].lazy += t;
}

void update(int id, int l, int r, int u, int v, int val){
    if ( l > v || r < u ) return;
    if ( u <= l && r <= v ){
        st[id].mn += val;
        st[id].mx += val;
        st[id].lazy += val;
        return;
    }

    int mid = ( l + r ) >> 1;

    down(id);

    update(id * 2, l, mid, u, v, val);
    update(id * 2 + 1, mid + 1, r, u, v, val);

    st[id].mn = min(st[id*2].mn, st[id*2+1].mn);
    st[id].mx = max(st[id*2].mx, st[id*2+1].mx);
}

int get1(int id, int l, int r){
    if ( l == r ){
        if ( st[id].mx == r ) return r;
        else return -oo;
    }
    down(id);
    int mid = ( l + r ) / 2;
    if ( st[id*2].mx == mid )
        return max(mid, get1(id * 2 + 1, mid + 1, r));
    else return get1(id * 2, l, mid);
}

int get2(int id, int l, int r){
    if ( l == r ){
        if ( st[id].mn >= 2 ) return l;
        return oo;
    }
    down(id);
    int mid = ( l + r ) / 2;
    if ( st[id * 2 + 1].mn >= 2 )
        return min(get2(id * 2, l, mid), mid + 1);
    else return get2(id * 2 + 1, mid + 1, r);
}

void query1(int p){
    if ( p == 1 ){
        cout << 1 << ' ';
        return;
    }
    a[p] = -a[p];
    int tmp = get1(1, 1, n) + 1;
    a[tmp] = -a[tmp];
    update(1, 1, n, tmp, p - 1, 2);
    cout << tmp << ' ';
}

void query2(int p){
    a[p] = -a[p];
    int tmp = get2(1, 1, n);
    a[tmp] = -a[tmp];
    update(1, 1, n, tmp, p - 1, -2);
    cout << tmp << ' ';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n >> q >> s;
    int sum = 0;
    for (int i = 1; i <= n; i ++){
        a[i] = ( s[i-1] == '(' ? 1 : -1 );
        sum = sum + a[i];
        update(1, 1, n, i, i, sum);
    }

    while ( q -- ){
        int p; cin >> p;
        if ( a[p] == 1 ) query1(p);
        else query2(p);
    }

    return 0;
}
