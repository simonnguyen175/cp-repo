#include<bits/stdc++.h>
#define simon "candy"
#define ll long long
using namespace std;
const int N = 2e5 + 5;
const ll oo = LLONG_MAX;

int n;
ll m, a, b;
ll s[N], f[N], mn[N], st[4*N];

void update(int id, int l, int r, int u, ll w){
    if ( l > u || r < u ) return;
    if ( l == r ){ st[id] = w; return; }
    int mid = l + r >> 1;
    update(id*2, l, mid, u, w);
    update(id*2+1, mid+1, r, u, w);
    st[id] = min(st[id*2], st[id*2+1]);
}

ll get(int id, int l, int r, int u, int v){
    if ( l > v || r < u ) return oo;
    if ( u <= l && r <= v ) return st[id];
    int mid = l + r >> 1;
    return min(get(id*2, l, mid, u, v), get(id*2+1, mid+1, r, u, v));
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen(simon".inp", "r") ){
        freopen(simon".inp", "r", stdin);
        freopen(simon".out", "w", stdout);
    }

    cin >> n >> m >> a >> b;
    for (int i = 1, x; i <= n; i ++)
        cin >> x, s[i] = s[i-1] + x;

    for (int i = 1; i <= 4*n; i ++) st[i] = oo;
    int j = 0;
    for (int i = 1; i <= n; i ++){
        while ( s[i] - s[j+1] >= m ) j ++;

        if ( s[i] - s[j] < m ) f[i] = (m-s[i])*b;
        else f[i] = min(mn[j] + (s[i]-m)*a, get(1, 1, n, j+1, i-1) + (m-s[i])*b);

        update(1, 1, n, i, f[i]+s[i]*b);
        mn[i] = min(mn[i-1], f[i]-s[i]*a);
    }

    cout << f[n];

    return 0;
}
