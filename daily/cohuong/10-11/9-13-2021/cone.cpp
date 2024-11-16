#include<bits/stdc++.h>
#define simon "cone"
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
#define pb push_back
using namespace std;
const int N = 1e5 + 5;

int n , a[N], c[N];
ll f[N], g[N], st[4*N];
map<int, int> id;

int tcs(int x){
	int res = 0;
	while ( x ) { res = res + x % 10; x /= 10; }
	return res;
}

void update(int id, int l, int r, int u, ll v){
	if ( l > u || r < u ) return;
	if ( l == r ) { st[id] = max(v, st[id]); return; }
	int mid = (l + r) / 2;
	update(id*2, l, mid, u, v);
	update(id*2+1, mid + 1, r, u, v);
	st[id] = max(st[id*2], st[id*2+1]);
}

int get(int id , int l , int r , int u , int v){
	if ( l > v || r < u ) return 0;
	if ( l >= u && r <= v ) return st[id];
	int mid = (l + r) / 2;
	return max(get(id*2, l, mid, u, v), get(id*2+1, mid+1, r, u, v));
}

void init(){
    cin >> n;
	vector<int> cont;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        c[i] = tcs(a[i]);
        cont.pb(a[i]);
    }

    sort(cont.begin(), cont.end());
    cont.erase(unique(cont.begin(), cont.end()), cont.end());

    int cnt = 0;
    for(int it : cont) id[it] = ++cnt;
}

void solve(){
    // make up
    for(int i = 1; i <= n; i ++){
        f[i] = get(1, 1, n, 1, id[a[i]]-1) + c[i];
        update(1, 1, n, id[a[i]], f[i]);
    }

    memset(st, 0, sizeof st);

    // make down
    for(int i = n; i >= 1; i --){
        g[i] = get(1, 1, n, 1, id[a[i]]-1) + c[i];
        update(1, 1, n, id[a[i]], g[i]);
    }

    ll ans = 0;
    for(int i = 1; i <= n; i ++)
        ans = max(ans, f[i] + g[i] - c[i]);
    cout << ans;
}

int main(){
    FASTio
    if ( fopen(simon".inp", "r") ){
        freopen(simon".inp", "r", stdin);
        freopen(simon".out", "w", stdout);
    }

    init();
    solve();

    return 0;
}

