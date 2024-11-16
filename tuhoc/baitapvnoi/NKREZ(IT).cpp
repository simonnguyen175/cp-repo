#include<bits/stdc++.h>
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
const int N = 1e5 + 5;
const int F = 3e4 + 5;
const int oo = 1e9;

int n;
long long st[4*N], ans = 0;
pair<int, int> a[N];

void update(int id, int l, int r, int i, long long v){
    if ( r < i || l > i ) return;
    if ( l == r ){
        st[id] = max (st[id], v);
        return;
    }

    int mid = ( l + r ) / 2;

    update(id * 2, l, mid, i, v);
    update(id * 2 + 1, mid + 1, r, i, v);

    st[id] = max(st[ id * 2 ], st[id * 2 + 1] );
}

long long getmax(int id, int l, int r, int u, int v){
    if ( r < u || l > v ) return -oo;
    if ( l >= u && r <= v ) return st[id];

    int mid = ( l + r ) / 2;

    return max(getmax(id * 2, l, mid, u, v), getmax(id * 2 + 1, mid + 1, r, u, v));
}

int main(){
    FASTio
    cin >> n;
    for (int i = 1; i <= n; i ++)
         cin >> a[i].first >> a[i].second;
    sort(a+1, a+1+n);



    for (int i = 1; i <= n; i ++){
        long long t = getmax(1, 0, F, 0, a[i].first) + a[i].second - a[i].first;
        ans = max(ans, t);
        update(1, 0, F, a[i].second, t);
    }

    cout << ans;

    return 0;
}
