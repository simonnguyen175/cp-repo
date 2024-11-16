#include<bits/stdc++.h>
#define ll long long
#define pi pair<ll, ll>
#define fi first
#define se second
using namespace std;
const int N = 200316;

int sub, n, q;

pi c25(ll x){
    ll cnt2 = 0, cnt5 = 0;
    while ( x % 2 == 0 ) cnt2 ++, x /= 2;
    while ( x % 5 == 0 ) cnt5 ++, x /= 5;
    return {cnt2, cnt5};
}

namespace sub1{
    pi a[N];

    void solve(){
        for (int i = 1; i <= n; i ++){
            ll x;
            cin >> x;
            a[i] = c25(x);
        }

        char type;
        int l, r;
        ll x, y;
        while ( q -- ){
            cin >> type;
            if ( type == 'A' ){
                cin >> l >> r >> x >> y;
                for (int i = l; i <= r; i ++){
                    ll cur = x + (i-l) * y;
                    pi tmp = c25(cur);
                    a[i].fi += tmp.fi;
                    a[i].se += tmp.se;
                }
            }

            if ( type == 'G' ){
                cin >> l >> r >> x >> y;
                ll c2x = c25(x).fi;
                ll c5x = c25(x).se;
                ll c2y = c25(y).fi;
                ll c5y = c25(y).se;

                for (int i = l; i <= r; i ++){
                    a[i].fi += c2x + (i - l) * c2y;
                    a[i].se += c5x + (i - l) * c5y;
                }
            }

            if ( type == 'C' ){
                cin >> l >> r;
                ll c2 = 0, c5 = 0;
                for (int i = l; i <= r; i ++)
                    c2 += a[i].fi, c5 += a[i].se;
                cout << min(c2, c5) << ' ';
            }
        }
    }
}

namespace sub2{
    pi a[N], st[4*N], lazy[4*N];

    pi add(pi a, pi b){
        a.fi += b.fi;
        a.se += b.se;
        return a;
    }

    void build(int id, int l, int r){
        if ( l == r ){
            st[id] = a[l];
            lazy[id] = {0, 0};
            return;
        }
        int mid = l + r >> 1;
        build(id*2, l, mid);
        build(id*2+1, mid+1, r);
        st[id] = add(st[id*2], st[id*2+1]);
    }

    void push(int id, int l, int r, pi val){
        st[id].fi += (r - l + 1) * val.fi;
        st[id].se += (r - l + 1) * val.se;
        lazy[id] = add(lazy[id], val);
    }

    void down(int id, int l, int r){
        int mid = l + r >> 1;
        push(id*2, l, mid, lazy[id]);
        push(id*2+1, mid+1, r, lazy[id]);
        lazy[id] = {0, 0};
    }

    void update(int id, int l, int r, int u, int v, pi val){
        if ( l > v || r < u ) return;
        if ( u <= l && r <= v ){
            st[id].fi += val.fi * (r - l + 1);
            st[id].se += val.se * (r - l + 1);
            lazy[id] = add(lazy[id], val);
            return;
        }
        down(id, l, r);
        int mid = l + r >> 1;
        update(id*2, l, mid, u, v, val);
        update(id*2+1, mid+1, r, u, v, val);
        st[id] = add(st[id*2], st[id*2+1]);
    }

    pi get(int id, int l, int r, int u, int v){
        if ( l > v || r < u ) return {0, 0};
        if ( u <= l && r <= v ) return st[id];
        down(id, l, r);
        int mid = l + r >> 1;
        pi L = get(id*2, l, mid, u, v);
        pi R = get(id*2+1, mid+1, r, u, v);
        return add(L, R);
    }

    void solve(){
        for (int i = 1; i <= n; i ++){
            ll x;
            cin >> x;
            a[i] = c25(x);
        }

        build(1, 1, n);

        char type;
        int l, r;
        ll x, y;
        while ( q -- ){
            cin >> type;

            if ( type == 'A' || type == 'G' ){
                cin >> l >> r >> x >> y;
                update(1, 1, n, l, r, c25(x));
            }

            if ( type == 'C' ){
                cin >> l >> r;
                pi tmp = get(1, 1, n, l, r);
                cout << min(tmp.fi, tmp.se) << '\n';
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    freopen("khong.inp", "r", stdin);
    freopen("khong.out", "w", stdout);

    cin >> sub >> n >> q;

    if ( sub == 1 ) { sub1::solve(); return 0; }

    if ( sub == 2 ) { sub2::solve(); return 0; }

    return 0;
}
