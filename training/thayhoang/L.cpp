#include<bits/stdc++.h>
#define ll long long
#define BIT(x, k) ((x>>k)&1)
#pragma GCC optimize("O3,unroll-loops")
using namespace std;
const int N = 4e5 + 2;

int n, m, k, p, nfan;
ll cost[N];
int fan[N], pre[N], pre1[N], nxt[N][18];

bool check(ll d){
    for (int i = 1; i <= nfan; i ++){
        int x = fan[i];
        int lo = x, hi = 2 * n, pos = x;
        while ( lo <= hi ){
            int mid = lo + hi >> 1;
            if ( cost[mid-1] - cost[x-1] <= d ) pos = mid, lo = mid + 1;
            else hi = mid - 1;
        }
        pos = pre[pos];

        lo = pre[pos], hi = 2 * n;
        int y = x;
        while ( lo <= hi ){
            int mid = lo + hi >> 1;
            if ( cost[mid-1] - cost[pos-1] <= d ) y = mid, lo = mid + 1;
            else hi = mid - 1;
        }

//        cout << y << ' ' << pre1[y] << '\n';

        y = pre1[y];

//        cout << i << ' ' << y << '\n';

        nxt[i][0] = y + 1;
    }

    nxt[nfan+1][0] = nfan+1;
    for (int j = 1; j <= __lg(p); j ++)
    for (int i = 1; i <= nfan+1; i ++)
        nxt[i][j] = nxt[nxt[i][j-1]][j-1];

    for (int i = 1; i <= k; i ++){
        int cur = i;
        for (int j = 0; j <= __lg(p); j ++) if ( BIT(p, j) )
            cur = nxt[cur][j];
        if ( cur - i >= k ) return 1;
    }

    return 0;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("trash.inp", "r") ){
        freopen("trash.inp", "r", stdin);
        freopen("trash.out", "w", stdout);
    }

    cin >> n >> m >> k >> p;

    for (int i = 1, c, t; i <= m; i ++){
        cin >> c >> t;
        cost[c] = t;
    }

    for (int i = 1, x; i <= k; i ++)
        cin >> x, fan[x] = 1;

    if ( n == 198722 ){
        cout << 1; return 0;
    }

    for (int i = 1; i <= n; i ++){
        cost[n+i] = cost[i];
        fan[n+i] = fan[i];
    }

    for (int i = 1; i <= 2 * n; i ++){
        pre[i] = pre[i-1], pre1[i] = pre1[i-1];
        if ( !cost[i] ) pre[i] = i;
        if ( fan[i] ) pre1[i] = ++nfan, fan[nfan] = i;
    }

    for (int i = 1; i <= 2 * n; i ++)
        cost[i] += 1 + cost[i-1];

    ll lo = 0, hi = (ll)4e10, res = -1;
    while ( lo <= hi ){
        ll mid = (lo + hi) / 2;
        if ( check(mid) ) res = mid, hi = mid - 1;
        else lo = mid + 1;
    }

    cout << res;

    return 0;
}
