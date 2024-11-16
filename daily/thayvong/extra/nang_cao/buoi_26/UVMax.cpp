#include<bits/stdc++.h>
#define simon "UVMax"
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
using namespace std;
const int N = 2e5 + 5;
const int oo = 1e20;

int n, u, v, a[N];
ll s[N], st[4 * N];

void build(int id, int l, int r){
    if ( l == r ){
        st[id] = s[l];
        return;
    }

    int mid = ( l + r ) / 2;

    build(id * 2, l, mid);
    build(id * 2 + 1, mid + 1, r);

    st[id] = min(st[id * 2], st[id * 2 + 1]);
}

ll getmin(int id, int l, int r, int u, int v){
    if ( l > v || r < u ) return LLONG_MAX;

    if ( u <= l && r <= v ) return st[id];

    int mid = ( l + r ) / 2;

    return min(getmin(id * 2, l, mid, u, v), getmin(id * 2 + 1, mid + 1, r, u, v));
}

int main(){
    FASTio
    if ( fopen(simon".inp", "r") ){
        freopen(simon".inp", "r", stdin);
        freopen(simon".out", "w", stdout);
    }

    cin >> n >> u >> v;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];

    s[0] = 0;
    for (int i = 1; i <= n; i ++)
        s[i] = s[i-1] + a[i];

    build(1, 0, n);

    ll ans = s[u];

    for (int i = u + 1; i <= v; i ++)
        ans = max(ans, s[i] - getmin(1, 0, n, 0, i - u) );

    for (int i = v + 1; i <= n; i ++)
        ans = max(ans, s[i] - getmin(1, 0, n, i - v, i - u));

    cout << ans;

    return 0;
}
