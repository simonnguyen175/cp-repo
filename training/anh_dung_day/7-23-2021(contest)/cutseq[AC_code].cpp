#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 5;
const int oo = 1e9;

int n, q;
ll a[N], del[N];
struct node{
    ll d, c, res[2][2];
} st[4*N];

void build(int id, int l, int r){
    if ( l == r ){
        st[id].d = st[id].c = del[l];
        st[id].res[1][1] = abs(del[l]);
        return;
    }

    int mid = ( l + r ) / 2;

    build(id*2, l, mid);
    build(id*2+1, mid+1, r);

    st[id].d = st[id*2].d;
    st[id].c = st[id*2+1].c;

    for (int i = 0; i <= 1; i ++)
    for (int j = 0; j <= 1; j ++){
        st[id].res[i][j] = 0;
        for (int k = 0; k <= 1; k ++)
            st[id].res[i][j] = max(st[id].res[i][j], st[id*2].res[i][k] + st[id*2+1].res[1-k][j]);
        if ( st[id*2].c * st[id*2+1].d >= 0 )
            st[id].res[i][j] = max(st[id].res[i][j], st[id*2].res[i][1] + st[id*2+1].res[1][j]);
    }
}

void update(int id, int l, int r, int u){
    if ( l > u || r < u ) return;

     if ( l == r ){
        st[id].d = st[id].c = del[l];
        st[id].res[1][1] = abs(del[l]);
        return;
    }

    int mid = ( l + r ) / 2;

    update(id*2, l, mid, u);
    update(id*2+1, mid+1, r, u);

    st[id].d = st[id*2].d;
    st[id].c = st[id*2+1].c;

    for (int i = 0; i <= 1; i ++)
    for (int j = 0; j <= 1; j ++){
        st[id].res[i][j] = 0;
        for (int k = 0; k <= 1; k ++)
            st[id].res[i][j] = max(st[id].res[i][j], st[id*2].res[i][k] + st[id*2+1].res[1-k][j]);
        if ( st[id*2].c * st[id*2+1].d >= 0 )
            st[id].res[i][j] = max(st[id].res[i][j], st[id*2].res[i][1] + st[id*2+1].res[1][j]);
    }
}

int main(){
    ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

    cin >> n >> q;
    for (int i = 1; i <= n; i ++) cin >> a[i];
    for (int i = 2; i <= n; i ++) del[i] = a[i] - a[i-1];

    build(1, 2, n);

    while ( q -- ){
        int l, r, x;
        cin >> l >> r >> x;

        if ( l > 1 ) del[l] += x, update(1, 2, n, l);
        if ( r + 1 <= n ) del[r+1] -= x, update(1, 2, n, r+1);

        ll ans = 0;
        for (int i = 0; i <= 1; i ++)
            for (int j = 0; j <= 1; j ++)
                ans = max(ans, st[1].res[i][j]);

        cout << ans << '\n';
    }

    return 0;
}
