#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e6 + 5;
const ll oo = 1e15;

int sub, t, n, k, q, cnt, L;
ll F;
ll d[N], l[N], c[N], s[N], st[4*N];
vector<int> b[N];

void update(int id, int l, int r, int u, ll v){
    if ( l > u || r < u ) return;
    if ( l == r ){
        st[id] = v;
        return;
    }
    int mid = l + r >> 1;
    update(id*2, l, mid, u, v);
    update(id*2+1, mid + 1, r, u, v);
    st[id] = min(st[id*2], st[id*2+1]);
}

ll get(int id, int l, int r, int u, int v){
    if ( l > v || r < u ) return oo;
    if ( u <= l && r <= v ) return st[id];
    int mid = l + r >> 1;
    return min(get(id*2, l, mid, u, v), get(id*2+1, mid+1, r, u, v));
}

void solve(){
    cin >> n >> k >> q;
    for (int i = 1; i <= q; i ++)
        cin >> s[i];
    for (int i = 1; i <= q; i ++){
        cin >> c[i];
        b[i].clear(); b[i].resize(c[i]);
        for (int j = 0; j < c[i]; j ++)
            cin >> b[i][j];
    }

    for (int i = 0; i <= 4 * q; i ++) st[i] = oo;
    for (int i = 1; i <= n; i ++) d[i] = 0;

    cnt = 0;
    l[1] = L = 1;
    for (int x : b[1]){
        if ( !d[x] ) cnt ++; d[x] ++;
    }

    for (int i = 2; i <= q; i ++){
        for (int x : b[i]){
            if ( !d[x] ) cnt ++; d[x] ++;
        }
        while ( cnt > k ){
            for (int x : b[L]){
                if ( d[x] == 1 ) cnt --;
                d[x] --;
            }
            L ++;
        }
        l[i] = L;
    }

    F = 0;
    update(1, 0, q, 0, 0);

    for (int i = 1; i <= q; i ++){
        F = get(1, 0, q, l[i]-1, i-1);
        update(1, 0, q, i, F + s[i+1]);
    }

    cout << F << ' ';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    freopen("guard.inp", "r", stdin);
    freopen("guard.out", "w", stdout);

    cin >> sub >> t;
    while ( t -- )
        solve();

    return 0;
}
