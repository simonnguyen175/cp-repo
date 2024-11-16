#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5 + 5;

int n, m;
struct seg{
    int l, r, w;
} a[N];
struct node{
    ll val, lazy;
} st[4*N*10];

void down(int id){
    ll t = st[id].lazy;
    st[id].lazy = 0;

    st[id*2].val += t; st[id*2].lazy += t;
    st[id*2+1].val += t; st[id*2+1].lazy += t;
}

void update(int id, int l, int r, int u, int v, ll w){
    if ( l > v || r < u ) return;
    if ( u <= l && r <= v ){
        st[id].val += w;
        st[id].lazy += w;
        return;
    }
    down(id);
    int mid = l + r >> 1;
    update(id*2, l, mid, u, v, w);
    update(id*2+1, mid+1, r, u, v, w);
    st[id].val = min(st[id*2].val, st[id*2+1].val);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("sseq.inp", "r") ){
        freopen("sseq.inp", "r", stdin);
        freopen("sseq.out", "w", stdout);
    }

    cin >> n;
    for (int i = 1; i <= n; i ++){
        cin >> a[i].l >> a[i].r >> a[i].w;
        m = max(m, a[i].l);
    }

    sort(a + 1, a + 1 + n, [&](seg x, seg y){
        if ( x.r == y.r ) return x.l < y.l;
        else return x.r < y.r;
    });

//    for (int i = 1; i <= n; i ++)
//        cout << a[i].l << ' ' << a[i].r << ' ' << a[i].w << '\n';
//    cout << '\n';

    ll sw = 0, ans = 0;
    for (int i = 1; i <= n; i ++){
        int j = i;
        ll c = a[i].w;
        sw += a[i].w;
        while ( j < n && a[j+1].r == a[j].r && a[j+1].l == a[j].l ){
            j ++;
            c += a[j].w, sw += a[j].w;
        }
//        cerr << i << ' ' << j << " : \n";
        i = j;

        update(1, 0, m, a[i].l, m, c);
//        cout << sw << ' ' << st[1].val << '\n';
        ans = max(ans, sw - st[1].val);
    }

    cout << ans;

    return 0;
}
