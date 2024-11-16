#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define ld long double
#define eps 1e-6
#define pb push_back
#define pi pair<int , int>

const int N = 1e4 + 5 , MOD = 1e9 + 7 , inf = 1e9 + 7;

void file() {
    freopen("PROJECT.inp" , "r" , stdin);
	freopen("PROJECT.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

int n , m , u[N] , v[N] , par[N];
vector<int> ans;
ld c[N] , l[N];

struct street {
	ld w;
	int u , v , id;
	street(ld n_w , int n_u , int n_v , int n_id) {
		w = n_w , u = n_u , v = n_v , id = n_id;
	}
	bool operator < (const street&s) const {
		return w <= s.w;
	}
};

int parent(int u) {
	if(par[u] < 0) return u;
	return (par[u] = parent(par[u]));
}

bool merge(int x , int y) {
	if((x = parent(x)) == (y = parent(y))) return false;
	if(par[x] > par[y]) swap(x , y);
	par[x] += par[y];
	par[y] = x;
	return true;
}

ld Kruskal(ld x) {
	ld resW = 0;
	vector<street> Edges;
	memset(par , -1 , sizeof(par));
	ans.clear();
	for(int i = 1 ; i <= m ; i++)
		Edges.pb(street(c[i] - x * l[i] , u[i] , v[i] , i));
	sort(Edges.begin() , Edges.end());
	for(auto x : Edges) 
		if(merge(x.u , x.v)) resW += x.w , ans.pb(x.id);
	return resW;
}

int main() {
	file();
	cin >> n >> m;
	for(int i = 1 ; i <= m ; i++) 
		cin >> u[i] >> v[i] >> l[i] >> c[i];
	ld d = eps , c = 1e5 , g , w;
	while(d <= c) {
		g = (d + c) / 2;
		w = Kruskal(g);
		if(abs(w - eps) <= 0) break;
		if(w < 0) c = g - eps;
		else d = g + eps;
	}
	sort(ans.begin() , ans.end());
	for(auto x : ans)
		cout << x << ' ';
	return 0;
}

