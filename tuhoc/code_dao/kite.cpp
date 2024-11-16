#include<bits/stdc++.h>
using namespace std;
const int N = 4e4 + 5e2 + 5;

int n, a[N], b[N], st[4*N];
map<int, int> q;

void update(int id, int l, int r, int i){
    if ( r < i ) return;
    if ( l >= i ){
        st[id]++;
        return;
    }
    if ( l == r ) return;
    int mid = ( l + r ) / 2;
    update(id*2, l, mid, i);
    update(id*2 + 1, mid+1, r, i);
}

int get(int id, int l, int r, int i){
     if ( l == r ) return st[id];
     int mid = ( l + r ) / 2;
     if ( mid >= i ) return get(id*2, l, mid, i)+st[id];
     else return get(id*2+1, mid+1, r, i)+st[id];
}

int main(){
    //freopen("kite.inp", "r", stdin);
    //freopen("kite.out", "w", stdout);
    cin >> n;
    for (int i=1; i<=n; i++){
        cin >> a[i];
        b[i] = a[i];
    }
    sort(a+1, a+1+n, greater<int>());
    for (int i=1; i<=n; i++)
        q[a[i]] = i;
    for (int i=1; i<=n; i++){
        update(1, 1, n, q[b[i]]);
        cout << get(1, 1, n, q[b[i]]) <<'\n';
    }
    return 0;
}
