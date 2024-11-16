#include<bits/stdc++.h>
using namespace std;
const int N = 3e5 + 5;

int n, m;
int a[N], numDiv[N*10], st_max[4*N];
long long st_sum[4*N];

void build(int id, int l, int r){
    if ( l == r ){
        st_max[id] = a[l];
        st_sum[id] = a[l];
        return;
    }

    int mid = ( l + r ) / 2;

    build(id * 2, l, mid);
    build(id * 2 + 1, mid + 1, r);

    st_max[id] = max(st_max[id * 2], st_max[id * 2 + 1]);
    st_sum[id] = st_sum[id * 2] + st_sum[id * 2 + 1];
}

void update(int id, int l, int r, int u, int v){
    if ( l > v || r < u ) return;

    if ( st_max[id] <= 2 ) return;

    if ( l == r && u <= l && r <= v ){
        st_sum[id] = st_max[id] = numDiv[st_sum[id]];
        return;
    }

    int mid = ( l + r ) / 2;

    update(id * 2, l, mid, u, v);
    update(id * 2 + 1, mid + 1, r, u, v);

    st_max[id] = max(st_max[id * 2], st_max[id * 2 + 1]);
    st_sum[id] = st_sum[id * 2] + st_sum[id * 2 + 1];
}

long long get(int id, int l, int r, int u, int v){
    if ( l > v || r < u ) return 0;

    if ( u <= l && r <= v ) return st_sum[id];

    int mid = (l + r) / 2;

    return get(id * 2, l, mid, u, v) + get(id * 2 + 1, mid + 1, r, u, v);
}

void init(){
    cin >> n >> m;
    for(int i = 1; i <= n; i ++)
        cin >> a[i];

    for (int i = 1; i <= N * 10; i ++)
        for (int j = i; j <= N * 10; j += i)
            numDiv[j] ++;

    build(1, 1, n);
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    init();
    while ( m -- ){
        int t, l, r;
        cin >> t >> l >> r;

        if ( t == 1 ) update(1, 1, n, l, r);
        else cout << get(1, 1, n, l, r) << '\n';
    }
    return 0;
}
