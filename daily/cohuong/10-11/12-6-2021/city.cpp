#include<bits/stdc++.h>
#define pi pair<int, int>
#define fi first
#define se second
using namespace std;
const int N = 1e5 + 5;

int n, m;
pi a[N];
struct query{
    int l, r, id;
    bool operator > (const query &a) const{
        return r > a.r;
    }
} q[N];
int t[N], ans[N], st[4*N];
map<int, int> d;

void update(int id, int l, int r, int u){
    if ( l > u || r < u ) return;
    if ( l == r ){
        st[id] ++; return;
    }
    int mid = l + r >> 1;
    update(id * 2, l, mid, u);
    update(id * 2 + 1, mid + 1, r, u);
    st[id] = st[id*2] + st[id*2+1];
}

int get(int id, int l, int r, int u, int v){
    if ( l > v || r < u ) return 0;
    if ( u <= l && r <= v ) return st[id];
    int mid = l + r >> 1;
    return get(id * 2, l, mid, u, v) + get(id * 2 + 1, mid + 1, r, u, v);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    freopen("city.inp", "r", stdin);
    freopen("city.out", "w", stdout);

    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> t[i];

    for (int i = n; i >= 1; i --){
        if ( !d[t[i]] ) a[i].fi = n + 1;
        else a[i].fi = d[t[i]];
        a[i].se = i;
        d[t[i]] = i;
    }

    cin >> m;
    for (int i = 1; i <= m; i ++)
        cin >> q[i].l >> q[i].r, q[i].id = i;

    sort(q + 1, q + 1 + m, greater<query>());
    sort(a + 1, a + 1 + n, greater<pi>());

//    for (int i = 1; i <= m; i ++) cout << q[i].l << ' ' << q[i].r << '\n';
//
//    for (int i = 1; i <= n; i ++) cout << a[i].fi << ' ' << a[i].se << " , "; cout << '\n';

    int id = 1;
    for (int i = 1; i <= m; i ++){
        while ( a[id].fi > q[i].r && id <= n ){
            //cout << "update " << a[id].se << '\n';
            update(1, 1, n, a[id].se), id ++;
        }
        ans[q[i].id] = get(1, 1, n, q[i].l, q[i].r);
    }

    for (int i = 1; i <= m; i ++)
        cout << ans[i] << '\n';

    return 0;
}
