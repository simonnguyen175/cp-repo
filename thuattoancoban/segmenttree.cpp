#include<bits/stdc++.h>
using namespace std;

int n, a[105], STmin[205], STsum[205];

void update(int id, int l, int r, int i, int v){
    if ( i < l || r < i ) return;
    if ( l == r ){
        STmin[id]=v;
        STsum[id]=v;
        return;
    }
    int mid = ( l + r ) / 2;
    update(id*2, l, mid, i, v);
    update(id*2+1, mid+1, r, i, v);
    STmin[id] = min(STmin[id*2], STmin[id*2+1]);
    STsum[id] = STsum[id*2] + STmin[id*2+1];
}

void updateMin(int id, int l, int r) {
    if ( l == r ) {
        STmin[id] = a[l];
        return ;
    }
    int mid = (l + r) / 2;
    updateMin(id*2, l, mid);
    updateMin(id*2 + 1, mid+1, r);
    STmin[id] = min(STmin[id*2], STmin[id*2 + 1]);
}


void updateSum(int id, int l, int r){
    if ( l == r ){
        STsum[id] = a[l];
        return;
    }
    int mid = ( l + r ) / 2 ;
    updateSum(id*2, l, mid);
    updateSum(id*2+1, mid+1, r);
    STsum[id] = STsum[id*2] + STsum[id*2+1];
}

int queryMin(int id, int l, int r, int u, int  v){
    if ( v < l || r < u ) return INT_MAX;
    if ( u <= l && r <= v ) return STmin[id];
    int mid = ( l + r ) / 2;
    return min(queryMin(id*2, l, mid, u, v), queryMin(id*2+1, mid+1, r, u, v));
}

int querySum(int id, int l, int r, int u, int v){
    if ( v < l || r < u ) return 0;
    if ( u <= l && r <= v ) return STsum[id];
    int mid = ( l + r ) / 2;
    return querySum(id*2, l, mid, u, v) + querySum(id*2+1, mid+1, r, u, v);
}

int main(){
    cin >> n;
    for (int i=1; i<=n; i++)
        cin >> a[i];
    updateMin(1, 1, n);
    updateSum(1, 1, n); cout <<'\n';
    for (int i=1; i<=2*n-1; i++)
        cout << STmin[i] <<' '; cout <<'\n';
    for (int i=1; i<=2*n-1; i++)
        cout << STsum[i] <<' '; cout <<'\n';
    update(1, 1, n, 3, 9);
    cout << queryMin(1, 1, n, 1, 3) <<' '<<querySum(1, 1, n, 1, 3);
    return 0;
}
