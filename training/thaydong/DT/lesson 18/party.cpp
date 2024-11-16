#include <bits/stdc++.h>
#define pb push_back
using namespace std;
const int N = 1e6 + 5;

int n, p[N], par[N], Rank[N], own[N];
vector<int> adj[N];

int Find(int x) {
	if ( x != par[x] ) par[x] = Find(par[x]);
	return par[x];
}

bool Join(int u, int v) {
	u = Find(u); v = Find(v);
	if (u == v) return 0;
	if (Rank[u] < Rank[v])
		swap(u, v);
	Rank[u] += Rank[v];
	par[v] = u;
	return 1;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++){
    	cin >> p[i];
    	par[i] = i; Rank[i] = 1;
    	if (p[i] != -1) adj[p[i]].pb(i);
    }

    int q; cin >> q;
    while ( q -- ){
    	int t, a, b; cin >> t >> a >> b;
    	if ( t == 1 ){
    		own[a] = b;
    		if (own[p[a]] == b) Join(p[a], a);
    		for (int v : adj[a])
    			if (own[a] == own[v])
    				Join(a, v);
    	}
    	else cout << (Find(a) == Find(b) ? "YES" : "NO") << '\n';
    }
}
