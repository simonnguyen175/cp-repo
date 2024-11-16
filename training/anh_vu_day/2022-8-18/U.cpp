#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;

int n, c, R;
int mx[N][20], st[4*N], win[N];

void update(int id, int l, int r, int u, int v){
    if ( l > u || r < u ) return;
    if ( l == r ){ st[id] = v; return; }
    int mid = l + r >> 1;
    update(id*2, l, mid, u, v);
    update(id*2+1, mid+1, r, u, v);
    st[id] = st[id*2] + st[id*2+1];
}

int bin(int k){
    if ( k == 0 ) return 0;
    int id = 1, l = 1, r = n;
    while ( l <= r ){
        if ( l == r ) break;
        int mid = l + r >> 1;
        if ( st[id*2] >= k ) r = mid, id *= 2;
        else k -= st[id*2], l = mid + 1, id = id*2+1;
    }
    return l;
}

int get(int l, int r){
    int k = __lg(r-l+1);
    return max(mx[l][k], mx[r-(1<<k)+1][k]);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("trash.inp", "r") ){
        freopen("trash.inp", "r", stdin);
        freopen("trash.out", "w", stdout);
    }

    cin >> n >> c >> R;
    for (int i = 1, x; i < n; i ++)
        cin >> x, mx[i][0] = x;

    for (int j = 1; j <= __lg(n); j ++)
    for (int i = 1; i <= n; i ++)
        mx[i][j] = max(mx[i][j-1], mx[i+(1<<(j-1))][j-1]);

    set<int> idx;
    for (int i = 1; i <= n; i ++){
        idx.insert(i);
        update(1, 1, n, i, 1);
    }
    for (int i = 1, l, r; i <= c; i ++){
        cin >> l >> r;
        l ++, r ++;

        l = bin(l-1) + 1;
        r = bin(r);

        if ( get(l, r-1) < R ) win[l] ++, win[r+1] --;

        auto it = idx.lower_bound(l);
        while ( it != idx.end() && *it != r ){
            update(1, 1, n, *it, 0);
            it = idx.erase(it);
        }
    }

    int res = -1, pos = 0;
    for (int i = 1; i <= n; i ++){
        win[i] += win[i-1];
        if ( res < win[i] ) res = win[i], pos = i;
    }

    cout << pos-1;

    return 0;
}
