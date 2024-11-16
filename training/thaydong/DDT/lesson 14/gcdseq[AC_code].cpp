#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;

int n, m;
int l[N], r[N], k[N], f[N][16], a[N], st[4*N];

int LCM(int x, int y){
    return ( x * y ) / __gcd(x, y);
}

void build(int id, int l, int r){
    if ( l == r ){
        st[id] = a[l];
        return;
    }
    int mid = (l + r) / 2;
    build(id*2, l, mid);
    build(id*2+1, mid + 1, r);
    st[id] = __gcd(st[id*2], st[id*2+1]);
}

int get(int id, int l, int r, int u, int v){
    if ( l > v || r < u ) return 0;
    if ( u <= l && r <= v ) return st[id];
    int mid = (l+r)/2;
    return __gcd(get(id*2, l, mid, u, v), get(id*2+1, mid+1, r, u, v));
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n >> m;

    for (int i = 1; i <= m; i ++){
        cin >> l[i] >> r[i] >> k[i];
        f[l[i]][k[i]] ++;
        f[r[i]+1][k[i]] --;
    }

    for (int j = 1; j <= 16; j ++)
        for (int i = 1; i <= n; i ++)
            f[i][j] += f[i-1][j];

    for (int i = 1; i <= n; i ++) a[i] = 1;

    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= 16; j ++)
            if ( f[i][j] > 0 ) a[i] = LCM(a[i], j);

    build(1, 1, n);

    for (int i = 1; i <= m; i ++)
        if ( get(1, 1, n, l[i], r[i]) != k[i] ){
            cout << -1;
            return 0;
        }

    for (int i = 1; i <= n; i ++)
        cout << a[i] << ' ';

    return 0;
}
