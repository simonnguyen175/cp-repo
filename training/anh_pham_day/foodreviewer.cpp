#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5 + 5;
const int oo = 1e9;

int n, k, m;
int a[N], st[4*N], mn[N];
ll dp[N][505];

void update(int id, int l, int r, int u, int v, int val){
    if ( l > v || r < u ) return;
    if ( u <= l && r <= v ){
        st[id] = min(st[id], val);
        return;
    }
    int mid = l + r >> 1;
    update(id*2, l, mid, u, v, val);
    update(id*2+1, mid+1, r, u, v, val);
}

int get(int id, int l, int r, int u){
    if ( l > u || r < u ) return oo;
    if ( l == r ) return st[id];
    int mid = l + r >> 1;
    return min({st[id], get(id*2, l, mid, u), get(id*2+1, mid+1, r, u)});
}

void solve(){
    cin >> n >> k >> m;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];

    for (int i = 1; i <= 4*n; i ++) st[i] = oo;
    for (int i = 1; i <= m; i ++){
        int l, r, c;
        cin >> l >> r >> c;
        update(1, 1, n, l, r, c);
    }

    for (int i = 1; i <= n; i ++)
        mn[i] = get(1, 1, n, i);

    for (int i = 0; i <= n; i ++)
    for (int j = 0; j <= k; j ++)
        dp[i][j] = -1e15;

    ll ans = -1e15;
    dp[0][0] = 0;
    for (int i = 1; i <= n; i ++)
    for (int j = 0; j <= k; j ++){
        dp[i][j] = dp[i-1][j] + a[i];
        if ( j >= mn[i] && a[i] < 0 )
            dp[i][j] = max(dp[i][j], dp[i-1][j-mn[i]]);
        if ( i == n ) ans = max(ans, dp[i][j]);
    }

    cout << ans << '\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("trash.inp", "r") ){
        freopen("trash.inp", "r", stdin);
        freopen("trash.out", "w", stdout);
    }

    int test;
    cin >> test;
    while ( test -- )
        solve();

    return 0;
}
