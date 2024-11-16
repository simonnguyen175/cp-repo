#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5 + 5;
const ll oo = 1e18;

int n, k;
ll a[N], s[N], f[N][2], st[4*N];

void update(int id, int l, int r, int u, ll v){
    if ( l > u || r < u ) return;
    if ( l == r ) { st[id] = v; return; }
    int mid = ( l + r ) / 2;
    update(id*2, l, mid, u, v);
    update(id*2+1, mid+1, r, u, v);
    st[id] = min(st[id*2], st[id*2+1]);
}

ll get(int id, int l, int r, int u, int v){
    if ( l > v || r < u ) return oo;
    if ( u <= l && r <= v ) return st[id];
    int mid = ( l + r ) / 2;
    return min(get(id*2, l, mid, u, v), get(id*2+1, mid+1, r, u, v));
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("discount.in", "r") ){
        freopen("discount.in", "r", stdin);
        freopen("discount.out", "w", stdout);
    }

    cin >> n >> k;
    for (int i = 1; i <= n; i ++){
        cin >> a[i];
        s[i] = s[i-1] + a[i];
    }

    for (int i = 1; i <= 4*n; i ++) st[i] = oo;

    for (int i = 1; i <= n; i ++)
        for (int j = 0; j <= 1; j ++)
            f[i][j] = oo;

    f[1][0] = a[1];
    update(1, 1, n, 1, a[1] - s[1]/2);
    for (int i = 2; i <= n; i ++){
        f[i][0] = min(f[i-1][0] + a[i], f[i-1][1] + a[i]);

        f[i][1] = s[i]/2 + get(1, 1, n, max(1, i-k), i-1);

        update(1, 1, n, i, f[i][0] - s[i]/2);
    }

    cout << min(f[n][0], f[n][1]);

    return 0;
}
