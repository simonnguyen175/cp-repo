#include<bits/stdc++.h>
#define pi pair<int, int>
#define fi first
#define se second
using namespace std;
const int N = 5e5 + 5;
const int oo = 1e9;

int n, Q;
int a[N], pre[N], last[N], ans[N];
pi st[4*N];
struct query{
    int l, r, id;
} q[N];

pi combine(pi a, pi b){
    if ( a.fi < b.fi ) return a;
    else return b;
}

void update(int id, int l, int r, int u, int v){
    if ( l > u || r < u ) return;
    if ( l == r ){
        st[id] = {v, l};
        return;
    }
    int mid = l + r >> 1;
    update(id*2, l, mid, u, v);
    update(id*2+1, mid+1, r, u, v);
    st[id] = combine(st[id*2], st[id*2+1]);
}

pi get(int id, int l, int r, int u, int v){
    if ( l > v || r < u ) return {oo, 0};
    if ( u <= l && r <= v ) return st[id];
    int mid = l + r >> 1;
    return combine(get(id*2, l, mid, u, v), get(id*2+1, mid+1, r, u, v));
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    // init
    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];

    cin >> Q;
    for (int i = 1; i <= Q; i ++)
        cin >> q[i].l >> q[i].r, q[i].id = i;
    sort(q+1, q+1+Q, [](query a, query b){
        return a.r < b.r;
    });

    for (int i = 1; i <= n; i ++){
        last[i] = pre[a[i]];
        pre[a[i]] = i;
    }

    // solve
    for (int i = 1; i <= 4*n; i ++) st[i] = {oo, 0};
    for (int i = 1; i <= Q; i ++){
        for (int j = q[i-1].r+1; j <= q[i].r; j ++){
            if ( last[j] ) update(1, 1, n, last[j], oo);
            update(1, 1, n, j, last[j]);
        }
        pi tmp = get(1, 1, n, q[i].l, q[i].r);
        ans[q[i].id] = ( tmp.fi >= q[i].l ? 0 : a[tmp.se] );
    }

    for (int i = 1; i <= Q; i ++)
        cout << ans[i] << '\n';

    return 0;
}
