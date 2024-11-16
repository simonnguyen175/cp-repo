#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
const int N = 5e5 + 5;

int n;
int a[N], d[N], pre[N];
struct node{
    int res = n + 1, lazy, pos;
} st[4 * N];
pair<int, int> res;

void down(int id){
	int t = st[id].lazy;

	st[id*2].lazy += t;
	st[id*2+1].lazy += t;

    st[id*2].res += t;
    st[id*2+1].res += t;

	st[id].lazy = 0;
}

node combine(node left, node right){
    if ( right.res == 0 ) left;
    if ( left.res <= right.res ) return left;
    else return right;
}

void build(int id, int l, int r){
    if ( l == r ){
        st[id].pos = l;
        return;
    }

    int mid = ( l + r ) / 2;

    build(id * 2, l, mid);
    build(id * 2 + 1, mid + 1, r);

    st[id] = combine(st[id*2], st[id*2+1]);
}

void update(int id, int l, int r, int u, int v, int val){
	if ( u > r || v < l ) return;

	if ( u <= l && r <= v ){
		st[id].lazy += val;
        st[id].res += val;
		return;
	}

	down(id);

	int mid = ( l + r ) / 2;

	update(id * 2, l, mid, u, v, val);
	update(id * 2 + 1, mid + 1, r, u, v, val);

    int tmplaz = st[id].lazy;
    st[id] = combine(st[id*2], st[id*2+1]);
    st[id].lazy = tmplaz;
}

void printtree(int id, int l, int r){
    if ( l == r ) return;
    printtree(id*2, l, (l+r)/2);
    printtree(id*2+1, (l+r)/2+1, r);
}

node get(int id, int l, int r, int u, int v){
    if ( u > r || v < l ) {node tmp; return tmp;}

    if ( u <= l && r <= v ) return st[id];

    down(id);

    int mid = ( l + r ) / 2;

    return combine(get(id * 2, l, mid, u, v), get(id * 2 + 1, mid + 1, r, u, v));
}

pair<int, int> minimize(pair<int, int> a, pair<int, int> b){
	if ( a.fi > b.fi ) return b;
	if ( a.fi == b.fi && a.se < b.se) return b;
	return a;
}

void solve(){
    for (int i = 1; i <= n; i ++) d[a[i]] = pre[i] = 0;
    for (int i = 1; i <= 4 * n; i ++) st[i] = {0, 0, 0};

    build(1, 1, n);

    pair<int, int> ans;
    ans = {1, 1};

    for (int i = 1 ; i <= n ; i++){
        update(1, 1, n, d[a[i]] + 1, i, 1);

        if ( d[a[i]] != 0 )
        update(1, 1, n, pre[d[a[i]]] + 1, d[a[i]], -1) ;

        pre[i] = d[a[i]];
        d[a[i]] = i;

        node l = get(1, 1, n, 1, i);

        ans = minimize(ans, make_pair(l.res, i-l.pos+1));
    }

    cout << ans.fi << ' ' << ans.se << '\n';
}

int main(){
    ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

    if ( fopen("repseq.inp", "r") ){
        freopen("repseq.inp", "r", stdin);
        freopen("repseq.out", "w", stdout);
    }

	while( cin >> n ){
        for (int i = 1; i <= n; i ++) cin >> a[i];
        solve();
	}

	return 0;
}

