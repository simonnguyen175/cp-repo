#include<bits/stdc++.h>
#define simon ""
#define ll long long
#define pb push_back
#define pi pair<int, int>
#define fi first
#define se second
#define BIT(x, k) ((x>>k)&1)
using namespace std;
random_device dev;
mt19937_64 rng(chrono::steady_clock().now().time_since_epoch().count());

ll range(ll l, ll r){
    return l + rng() % ( r - l + 1 );
}

void file(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen(simon".inp", "r") ){
        freopen(simon".inp", "r", stdin);
        freopen(simon".out", "w", stdout);
    }
}

void build(int id, int l, int r){
    if ( l == r ){
        st[id].cont.pb(a[l]);
        st[id].val = a[l];
        return;
    }
    int mid = l + r >> 1;
    build(id*2, l, mid);
    build(id*2+1, mid+1, r);

    st[id] = combine(st[id*2])
}

int main(){
    file();

    cin >> n >> c;

    for (int i = 1; i <= n; i ++)
        cin >> a[i];

    build(1, 1, n);

    return 0;
}

