#include<bits/stdc++.h>
#define ll long long
#define pi pair<ll, ll>
#define fi first
#define se second
using namespace std;
const int N = 1e5 + 5;
const ll oo = 1e18;

int n, Q;
ll S;
struct query{
    int type, id, x, y, h;
} q[N];
ll a[N], b[N];
struct node{
    ll val, lazy;
} st[4*N];
bool ck1 = 1, ck2 = 1, ck3 = 1;


namespace sub1{
    void down(int id){
        ll t = st[id].lazy;
        st[id*2].lazy += t, st[id*2].val += t;
        st[id*2+1].lazy += t, st[id*2+1].val += t;
        st[id].lazy = 0;
    }

    void update(int id, int l, int r, int u, int v, ll val){
        if ( l > v || r < u ) return;
        if ( u <= l && r <= v ){
            st[id].val += val;
            st[id].lazy += val;
            return;
        }
        int mid = l + r >> 1;
        down(id);
        update(id*2, l, mid, u, v, val);
        update(id*2+1, mid+1, r, u, v, val);
        st[id].val = max(st[id*2].val, st[id*2+1].val);
    }

    ll get(int id, int l, int r, int u, int v){
        if ( l > v || r < u ) return -oo;
        if ( u <= l && r <= v ) return st[id].val;
        int mid = l + r >> 1;
        down(id);
        return max(get(id*2, l, mid, u, v), get(id*2+1, mid+1, r, u, v));
    }

    void solve(){
        ll sum = 0;
        update(1, 0, n, 0, 0, sum);
        for (int i = 1; i <= n; i ++)
            sum += b[i], update(1, 0, n, i, i, sum);

        if ( S <= 0 ) S = 1;

        for (int i = 1; i <= Q; i ++)
            if ( q[i].type == 1 ){
                update(1, 0, n, q[i].id, n, q[i].y-b[q[i].id]);
                b[q[i].id] = q[i].y;
            }
            else{
                if ( q[i].h - S < 0 ) cout << -1 << '\n';
                else{
                    ll t1 = get(1, 0, n, q[i].h, q[i].h);
                    ll t2 = get(1, 0, n, 0, q[i].h-S);
                    cout << t1 - t2  << '\n';
                }
            }
    }
}

namespace sub2 {
	ll st[4*N], lazy[4*N], f[N];

	void build(int id , int l , int r) {
		if(l == r) {
			st[id] = f[l];
			lazy[id] = 0;
			return;
		}
		int mid = (l + r) / 2;
		build(id * 2 , l , mid);
		build(id * 2 + 1 , mid + 1 , r);
		st[id] = min(st[id * 2] , st[id * 2 + 1]);
	}

	void down(int id) {
		ll t = lazy[id];
		lazy[id] = 0;
		st[id * 2] += t; st[id * 2 + 1] += t;
		lazy[id * 2] += t; lazy[id * 2 + 1] += t;
	}

	void update(int id , int l , int r , int u , int v , ll val) {
		if ( l > v || r < u ) return;
		if ( l >= u && r <= v ){
			st[id] += val;
			lazy[id] += val;
			return;
		}

		down(id);
		int mid = (l + r) / 2;
		update(id *2 , l , mid , u , v , val);
		update(id * 2 + 1 , mid + 1 , r , u , v , val);
		st[id] = min(st[id * 2] , st[id * 2 + 1]);
	}

	ll get(int id , int l , int r , int u , int v) {
		if ( l > v || r < u ) return oo;
		if ( l >= u && r <= v ) return st[id];
		down(id);
		int mid = (l + r) / 2;
		return min(get(id*2, l, mid, u, v) , get(id*2+1, mid + 1, r, u, v));
	}

	int go(int id , int l , int r , int u , ll val) {
		if ( st[id] > val ) return -1;
		if ( l > u ) return -1;
		if ( l == r ) 	return l;
		down(id);
		int mid = (l + r) / 2 , res = -1;
		if ( st[id*2+1] <= val )
			res = go(id*2+1, mid+1, r, u, val);
		if ( res == -1 )
			res = go(id*2, l, mid, u, val);
		return res;
	}

	void solve() {
		f[0] = 0;
		for(int i = 1; i <= n; i ++)
			f[i] = f[i-1] + a[i];
		build(1, 1, n);
		for(int i = 1; i <= Q; i ++) {
			if(q[i].type == 1) {
				update(1, 1, n, q[i].id, n , q[i].x - a[q[i].id]);
				a[q[i].id] = q[i].x;
			}
			else {
				ll tmp = get(1, 1, n, q[i].h, q[i].h) - S;
				int ans = go(1, 1, n, q[i].h - 1, tmp);
				if ( ans == -1 ){
					if ( tmp >= 0 ) cout << q[i].h << '\n';
					else cout << -1 << '\n';
				}
				else cout << q[i].h - ans << '\n';
			}
		}
	}
}

namespace sub3{
    pi sa[N];
    int Q2 = 0, st;
    struct query2{
        ll v;
        int h, id;
        bool operator < (const query2 &a) const{
            return v < a.v;
        }
    } q2[N];
    ll bit[N], sb[N], ans[N];

    void update(int u, ll v){
        for (; u <= n+1; u += u&(-u))
            bit[u] = max(bit[u], v);
    }

    ll get(int u){
        ll res = -oo;
        for (; u >= 1; u -= u&(-u))
            res = max(res, bit[u]);
        return res;
    }

    void solve(){
        for (int i = 1; i <= Q; i ++){
            if ( q[i].type == 2 ) { st = i; break; }
            a[q[i].id] = q[i].x;
            b[q[i].id] = q[i].y;
        }

        sa[0].fi = 0, sa[0].se = 0;
        for (int i = 1; i <= n; i ++){
            sa[i].fi = sa[i-1].fi + a[i];
            sa[i].se = i;
        }

        sb[0] = 0;
        for (int i = 1; i <= n; i ++)
            sb[i] = sb[i-1] + b[i];

        for (int i = st; i <= Q; i ++){
            if ( q[i].type != 2 ) break;
            q2[++Q2] = {sa[q[i].h].fi-S, q[i].h, Q2};
        }

        sort(sa, sa+n);

        sort(q2+1, q2+1+Q2);

        for (int i = 1; i <= Q2; i ++)
            ans[i] = -1;

        for (int i = 1; i <= n+1; i ++)
            bit[i] = -oo;

        int j = 0;
        for (int i = 1; i <= Q2; i ++){
            while ( j <= n && sa[j].fi <= q2[i].v ){
                update(sa[j].se+1, sb[sa[j].se]);
                j ++;
            }

            ll tmp = get(q2[i].h);
            if ( tmp == -oo ) continue;
            ans[q2[i].id] = sb[q2[i].h] - tmp;
        }

        for (int i = 1; i <= Q2; i ++)
            cout << ans[i] << '\n';
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("2.inp", "r") ){
        freopen("2.inp", "r", stdin);
        freopen("2.out", "w", stdout);
    }

    cin >> n >> S;

    for (int i = 1; i <= n; i ++)
        cin >> a[i], ck1 &= ( a[i] == 1 );

    for (int i = 1; i <= n; i ++)
        cin >> b[i], ck2 &= ( b[i] == 1 );

    cin >> Q;
    for (int i = 1; i <= Q; i ++){
        cin >> q[i].type;
        if ( q[i].type == 1 ){
            cin >> q[i].id >> q[i].x >> q[i].y;
            ck1 &= ( q[i].x == 1 );
            ck2 &= ( q[i].y == 1 );
        }
        else cin >> q[i].h;
    }

    for (int i = 1; i <= Q; i ++)
        if ( q[i].type == 2 )
            ck3 &= (q[i-1].type == q[i].type) || (q[i].type == q[i+1].type );

    if ( ck1 ) { sub1::solve(); return 0; }
    if ( ck2 ) { sub2::solve(); return 0; }
    if ( ck3 ) { sub3::solve(); return 0; }
}
