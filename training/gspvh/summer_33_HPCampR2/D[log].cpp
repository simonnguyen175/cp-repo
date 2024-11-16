#include<bits/stdc++.h>
#define simon "minimum"
#define ll long long
#define pi pair<int, int>
#define fi first
#define se second
using namespace std;
const int N = 5e6 + 5;
const ll oo = 1e18;

int n, x, y;
int a[N], L[N], R[N];
ll s[N];
pi st[4*N];

void build(int id, int l, int r){
    if ( l == r ){
        st[id] = {l, l};
        return;
    }
    int mid = l + r >> 1;
    build(id*2, l, mid);
    build(id*2+1, mid+1, r);
    st[id].fi = ( s[st[id*2].fi] > s[st[id*2+1].fi] ? st[id*2].fi : st[id*2+1].fi );
    st[id].se = ( s[st[id*2].se] < s[st[id*2+1].se] ? st[id*2].se : st[id*2+1].se );
}

pi get(int id, int l, int r, int u, int v){
    if ( l > v || r < u ) return {n+1, n+2};
    if ( u <= l && r <= v ) return st[id];
    int mid = l + r >> 1;
    pi L = get(id*2, l, mid, u, v);
    pi R = get(id*2+1, mid+1, r, u, v);
    pi res;
    res.fi = ( s[L.fi] > s[R.fi] ? L.fi : R.fi );
    res.se = ( s[L.se] < s[R.se] ? L.se : R.se );
    return res;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen(simon".inp", "r") ){
        freopen(simon".inp", "r", stdin);
        freopen(simon".out", "w", stdout);
    }

    cin >> n >> x >> y;
    for (int i = 1; i <= n; i ++){
        cin >> a[i];
        s[i] = s[i-1] + a[i];
    }
    build(1, 0, n);
    s[n+1] = -oo, s[n+2] = oo;

    stack<int> Q;
	for (int i = 1; i <= n; ++i) {
		while (Q.size() && a[i] <= a[Q.top()]) Q.pop();
		if (Q.size()) L[i] = Q.top() + 1;
		else L[i] = 1;
		Q.push(i);
	}
	while (Q.size()) Q.pop();
	for (int i = n; i >= 1; --i) {
		while (Q.size() && a[i] <= a[Q.top()]) Q.pop();
		if (Q.size()) R[i] = Q.top() - 1;
		else R[i] = n;
		Q.push(i);
	}

    ll ans = -oo;
    int rL, rR;
    for (int i = 1; i <= n; i ++) if ( a[i] >= x && a[i] <= y ){
        int pr = get(1, 0, n, i, R[i]).fi;
        int pl = get(1, 0, n, L[i]-1, i-1).se;
        if ( ans < s[pr] - s[pl] ){
            ans = s[pr] - s[pl];
            rL = pl + 1, rR = pr;
        }
    }

    cout << ans << '\n' << rL << ' ' << rR;

    return 0;
}
