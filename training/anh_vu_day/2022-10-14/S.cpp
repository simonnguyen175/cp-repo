#include<bits/stdc++.h>
#define pi pair<int, int>
#define fi first
#define se second
using namespace std;
const int N = 1e5 + 5;

int n, q;
int a[N], lazy[4*N], l[N], r[N], lef[N], rig[N];
pi st[4*N], b[N];
struct query{
    int x, y, id;
} que[N];

pi combine(pi L, pi R, int t){
    if ( L.fi < R.fi ) return L;
    else if ( L.fi > R.fi ) return R;
    else if ( !t ) return L;
    else return R;
}

void build(int id, int l, int r, int t){
    if ( l == r ){
        st[id] = {0, l};
        lazy[id] = 0;
        return;
    }
    int mid = l + r >> 1;
    build(id*2, l, mid, t);
    build(id*2+1, mid+1, r, t);
    st[id] = combine(st[id*2], st[id*2+1], t);
    lazy[id] = 0;
}

void down(int id){
    for (int i = 0; i <= 1; i ++){
        st[id*2+i].fi += lazy[id];
        lazy[id*2+i] += lazy[id];
    }
    lazy[id] = 0;
}

void update(int id, int l, int r, int u, int v, int val, int t){
    if ( l > v || r < u ) return;
    if ( u <= l && r <= v ){
        st[id].fi += val;
        lazy[id] += val;
        return;
    }
    down(id);
    int mid = l + r >> 1;
    update(id*2, l, mid, u, v, val, t);
    update(id*2+1, mid+1, r, u, v, val, t);
    st[id] = combine(st[id*2], st[id*2+1], t);
}

pi get(int id, int l, int r, int u, int v, int t){
    if ( l > v || r < u ) return {2*n, 0};
    if ( u <= l && r <= v ) return st[id];
    down(id);
    int mid = l + r >> 1;
    return combine(get(id*2, l, mid, u, v, t), get(id*2+1, mid+1, r, u, v, t), t);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("L.inp", "r") ){
        freopen("L.inp", "r", stdin);
        freopen("L.out", "w", stdout);
    }

    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];

    build(1, 1, n, 0);
    deque<int> qmx, qmn;
    for (int i = 1; i <= n; i ++){
        int pre;
        while ( qmx.size() && a[qmx.back()] < a[i] ){
            pre = qmx.back();
            qmx.pop_back();
            if ( qmx.size() ) update(1, 1, n, qmx.back()+1, pre, a[i]-a[pre], 0);
            else update(1, 1, n, 1, pre, a[i]-a[pre], 0);
        }

        while ( qmn.size() && a[qmn.back()] > a[i] ){
            pre = qmn.back();
            qmn.pop_back();
            if ( qmn.size() ) update(1, 1, n, qmn.back()+1, pre, a[pre]-a[i], 0);
            else update(1, 1, n, 1, pre, a[pre]-a[i], 0);
        }

        pi tmp = get(1, 1, n, 1, i, 0);
        l[i] = tmp.se;
        update(1, 1, n, 1, i, -1, 0);

        qmx.push_back(i);
        qmn.push_back(i);
    }

    qmn.clear(), qmx.clear();
    build(1, 1, n, 1);

    for (int i = n; i >= 1; i --){
        int pre;
        while ( qmx.size() && a[qmx.back()] < a[i] ){
            pre = qmx.back();
            qmx.pop_back();
            if ( qmx.size() ) update(1, 1, n, pre, qmx.back()-1, a[i]-a[pre], 1);
            else update(1, 1, n, pre, n, a[i]-a[pre], 1);
        }

        while ( qmn.size() && a[qmn.back()] > a[i] ){
            pre = qmn.back();
            qmn.pop_back();
            if ( qmn.size() ) update(1, 1, n, pre, qmn.back()-1, a[pre]-a[i], 1);
            else update(1, 1, n, pre, n, a[pre]-a[i], 1);
        }

        pi tmp = get(1, 1, n, i, n, 1);
        r[i] = tmp.se;
        update(1, 1, n, i, n, -1, 1);

        qmx.push_back(i);
        qmn.push_back(i);
    }

    cin >> q;
    for (int i = 1; i <= q; i ++)
        cin >> que[i].x >> que[i].y, que[i].id = i;

    sort(que + 1, que + 1 + q, [&](query u, query v){
        return u.x < v.x;
    });
    for (int i = 1; i <= n; i ++) b[i] = {l[i], i};
    sort(b + 1, b + 1 + n);
    set<int> s;
    int id = 1;
    for (int i = 1; i <= q; i ++){
        while ( id <= n && b[id].fi <= que[i].x )
            s.insert(b[id].se), id ++;
        auto it = s.lower_bound(que[i].y);
        rig[que[i].id] = *it;
    }

    sort(que + 1, que + 1 + q, [&](query u, query v){
        return u.y > v.y;
    });
    for (int i = 1; i <= n; i ++) b[i] = {r[i], i};
    sort(b + 1, b + 1 + n, greater<pi>());
    s.clear();
    id = 1;
    for (int i = 1; i <= q; i ++){
        while ( id <= n && b[id].fi >= que[i].y )
            s.insert(b[id].se), id ++;
        auto it = s.lower_bound(que[i].x);
        if ( it == s.end() || *it > que[i].x ) it --;
        lef[que[i].id] = *it;
    }

    for (int i = 1; i <= q; i ++)
        cout << lef[i] << ' ' << rig[i] << '\n';

    return 0;
}
