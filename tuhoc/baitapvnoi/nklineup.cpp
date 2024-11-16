#include<bits/stdc++.h>
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
const int N = 5e4+5;

int n, q, a[N], stmax[4*N], stmin[4*N];

void buildSt(int id, int l, int r, int i, int val){
    if ( i < l || i > r ) return;

    if ( l == r ){
        stmax[id] = val;
        stmin[id] = val;
        return;
    }

    int mid = ( l + r ) / 2;
    buildSt(id*2, l, mid, i, val);
    buildSt(id*2+1, mid+1, r, i, val);

    stmax[id] = max (stmax[id*2], stmax[id*2+1]);
    stmin[id] = min (stmin[id*2], stmin[id*2+1]);
}

int findMax(int id, int l, int r, int u, int v){
    if ( r < u || l > v ) return INT_MIN;
    if ( u <= l && v >= r ) return stmax[id];

    int mid = ( l + r ) / 2;

    return max ( findMax(id*2, l, mid, u, v), findMax(id*2+1, mid+1, r, u, v) );
}

int findMin(int id, int l, int r, int u, int v){
    if ( r < u || l > v ) return INT_MAX;
    if ( u <= l && v >= r ) return stmin[id];

    int mid = ( l + r ) / 2;

    return min ( findMin(id*2, l, mid, u, v), findMin(id*2+1, mid+1, r, u, v) );
}

int main(){
    FASTio
    cin >> n >> q;
    for (int i=1; i<=n; i++){
        cin >> a[i];
        buildSt(1, 1, n, i, a[i]);
    }

    for (int i=1; i<=q; i++){
        int l, r;
        cin >> l >> r;
        // cout << findMax(1, 1, n, l, r) <<' ' << findMin(1, 1, n, l, r) << ' ' ;
        cout << findMax(1, 1, n, l, r) - findMin(1, 1, n, l, r) << '\n';
    }

    return 0;
}
