#include<bits/stdc++.h>
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<int , int>
using namespace std;

const int N = 1e5 + 5 , MOD = 1e9 + 7 , inf = 1e9 + 7;

void file() {
	freopen("qtree.in" , "r" , stdin);
	freopen("qtree.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0) ; cout.tie(0);
}

int n , nn , q , sz[N] , pos[N] , p[N][25] , h[N];
ll bit1[N] , bit2[N];
vector<int> adj[N];

void Dfs(int u , int pa) {
	pos[u] = ++nn;
	sz[u] = 1;
	for(int i = 1 ; i <= 20 ; i++)
		p[u][i] = p[p[u][i - 1]][i - 1];
	for(int v : adj[u]) {
		if(v == pa) continue;
		h[v] = h[u] + 1 , p[v][0] = u;
		Dfs(v , u);
		sz[u] += sz[v];
	}
}

int lca(int x , int y) {
	if(h[x] < h[y]) swap(x , y);
	for(int i = 20 ; i >= 0 ; i--)
		if(h[x] - (1 << i) >= h[y]) x = p[x][i];
	if(x == y) return x;
	for(int i = 20 ; i >= 0 ; i--)
		if(p[x][i] != p[y][i])
			x = p[x][i] , y = p[y][i];
	return p[x][0];
}

void update(int u , ll val1 , ll val2) {
	for(int i = u ; i <= n ; i += (i & (-i)))
		bit1[i] += val1 , bit2[i] += val2;
}

ll get1(int u){
    ll res = 0;
    for (int i = u; i >= 1; i -= i&(-i)) res += bit1[i];
    return res;
}

ll get2(int u){
    ll res = 0;
    for (int i = u; i >= 1; i -= i&(-i)) res += bit2[i];
    return res;
}

ll get(int id , int u) {
	ll res1 = 0 , res2 = 0;
	for(int i = id ; i >= 1 ; i -= (i & (-i)))
		res1 += bit1[i] , res2 += bit2[i];
	return res1 * h[u] + res2;
}

int main() {
	file();
	cin >> n;
	for(int i = 1 ; i < n ; i++) {
		int u , v ; cin >> u >> v;
		adj[u].pb(v) ; adj[v].pb(u);
	}
	h[1] = 1;
	Dfs(1 , 0);
	for(int i = 1 , x ; i <= n ; i++) {
		cin >> x;
		update(pos[i] , 0 , x);
		update(pos[i] + sz[i] , 0 , -x);
	}
	cin >> q;
	while(q--) {
		int type , u , v;
		ll c;
		cin >> type;
		if(type == 1) {
			cin >> u >> c;
			update(pos[u] , 0 , c);
			update(pos[u] + sz[u] , 0 , -c);
		}
		if(type == 2) {
			cin >> u >> c;
			update(pos[u] , c , -(h[u] - 1) * c);
			update(pos[u] + sz[u] , -c , (h[u] - 1) * c);
		}
		if(type == 3) {
			cin >> u;
			cout << get2(pos[u]) << '\n';
//			cout << get(pos[u] , u) - get(pos[p[u][0]] , p[u][0]) << '\n';
		}
		if(type == 4) {
			cin >> u >> v;
			c = lca(u , v);
//			cout << c << '\n';
//			cout << get(pos[u] , u) + get(pos[v] , v) - get(pos[c] , c) - get(pos[p[c][0]] , p[c][0]) << '\n';
		}
	}
}


