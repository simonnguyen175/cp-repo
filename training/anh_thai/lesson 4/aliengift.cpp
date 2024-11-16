#include<bits/stdc++.h>
#define ll long long
#define BIT(x,k) ((x>>k)&1)
using namespace std;
const int N = 1e5 + 5;
const ll oo = 1e15;

int n;
int l[N], h[N], msk[9], go[N];
ll v[N][4], s[N][9], st[9][4*N], lazy[9][4*N], ans = -oo;

void down(int msk, int id){
    ll t = lazy[msk][id];
    if ( st[msk][id*2] < t )
        st[msk][id*2] = lazy[msk][id*2] = t;
    if ( st[msk][id*2+1] < t )
        st[msk][id*2+1] = lazy[msk][id*2+1] = t;
}

void update(int msk, int id, int l, int r, int u, int v, ll val){
    if ( l > v || r < u ) return;
    if ( u <= l && r <= v ){
        if ( st[msk][id] < val ){
            st[msk][id] = val;
            lazy[msk][id] = val;
        }
        return;
    }
    int mid = l + r >> 1;
    down(msk, id);
    update(msk, id*2, l, mid, u, v, val);
    update(msk, id*2+1, mid+1, r, u, v, val);
    st[msk][id] = max(st[msk][id*2], st[msk][id*2+1]);
}

ll get(int msk, int id, int l, int r, int u, int v){
    if ( l > v || r < u ) return -oo;
    if ( u <= l && r <= v ) return st[msk][id];
    int mid = l + r >> 1;
    down(msk, id);
    return max(get(msk, id*2, l, mid, u, v), get(msk, id*2+1, mid+1, r, u, v));
}

bool check(int msk){
    for (int i = 0; i <= 3; i ++)
        if ( BIT(msk, i) && BIT(msk, i+1) ) return false;
    return true;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("aliengift.inp", "r") ){
        freopen("aliengift.inp", "r", stdin);
        freopen("aliengift.out", "w", stdout);
    }

    bool ck = 1;

    go[1] = 1; go[2] = -1;

    cin >> n;
    for (int i = 1; i <= n; i ++){
        cin >> l[i] >> h[i];
        if ( i >= 2 ) go[i] += go[i-1];
        if ( i + l[i] <= n && go[i] > 0 ) go[i+l[i]]++, go[min(n, i+h[i])+1]--;
        for (int j = 0; j <= 3; j ++){
            cin >> v[i][j];
            if ( go[i] > 0 ){
                ck &= ( v[i][j] < 0 );
                ans = max(ans, v[i][j]);
            }
        }
    }

    if ( ck ){
        cout << ans;
        return 0;
    }

    int cnt = 0;
    for (int t = 0; t < (1<<4); t ++)
        if ( check(t) )
            msk[++cnt] = t;

    for (int i = 1; i <= n; i ++)
    for (int j = 1; j <= cnt; j ++){
        for (int k = 0; k <= 3; k ++)
            if ( BIT(msk[j],k) ){
                s[i][j] += v[i][k];
            }
    }

    for (int i = 1; i <= 4*n; i ++)
    for (int j = 1; j <= 8; j ++)
        st[j][i] = lazy[j][i] = -oo;

    for (int j = 1; j <= cnt; j ++)
        update(j, 1, 1, n, 1, 1, 0);

    for (int i = 1; i <= n; i ++) if ( i + l[i] <= n )
    for (int j = 1; j <= 8; j ++){
        ll tmp = get(j, 1, 1, n, i, i) + s[i][j];
        for (int k = 1; k <= 8; k ++)
            if ( !(msk[k]&msk[j]) )
                update(k, 1, 1, n, i+l[i], min(i+h[i], n), tmp);
    }

    for (int i = 1; i <= n; i ++) if ( i + h[i] > n )
    for (int j = 1; j <= 8; j ++){
        ll tmp = get(j, 1, 1, n, i, i) + s[i][j];
        ans = max(ans, tmp);
    }

    cout << ans;

    return 0;
}
