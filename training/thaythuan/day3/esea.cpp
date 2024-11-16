//TrungNotChung
#include <bits/stdc++.h>
#define pii pair<int , int>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define BIT(x,i) (1&((x)>>(i)))
#define MASK(x)  (1LL<<(x))
#define CNT(x) __builtin_popcountll(x)
#define task "tnc"  

using namespace std;
const int N = (int)1e6+228;
const int INF = (int)1e9+7;
struct rada
{
	struct point
	{
		int x , y;
		bool operator < (const point &p) const
		{
			return x == p.x ? y < p.y : x < p.x;
		}
		bool operator == (const point &p) const
		{
			return (x == p.x && y == p.y);
		}
	};
	point a , b;
	int id;
	bool operator < (const rada &x) const
	{
		if(a == x.a) return b < x.b;
		return a < x.a;
	}
}f[N];
int n , py[N] , inID[N];
vector<int> nodes[N];
priority_queue<pii , vector<pii> , greater<pii> > pq;
void solve()
{
	cin >> n;
	for(int i=1 ; i<=n ; ++i) cin >> f[i].a.x >> f[i].a.y >> f[i].b.x >> f[i].b.y , f[i].id = i;
	sort(f+1 , f+n+1);
	int m = 0;
	for(int i=1 ; i<=n ; ++i) py[i] = INF , nodes[i].clear();
	set<pii> s; set<pii>::iterator itr;
	while(pq.size()) pq.pop();
	for(int i=1 ; i<=n ; ++i)
	{
		while(pq.size() && pq.top().fi < f[i].a.x)
		{
			int id = pq.top().se; pq.pop();
			s.erase(pii(py[inID[id]] , inID[id]));
			py[inID[id]] = min(py[inID[id]] , f[id].b.y);
			s.insert(pii(py[inID[id]] , inID[id]));
		}
		itr = s.lower_bound(pii(f[i].a.y , 0));
		if(itr == s.end())
		{
			++m;
			nodes[m].push_back(f[i].id);
			inID[i] = m;
			s.insert(pii(py[m] , m));
		}
		else 
		{
			int k = (*itr).se;
			nodes[k].push_back(f[i].id);
			inID[i] = k;
		}
		pq.push(pii(f[i].b.x , i));
	}
	cout << m << '\n';
	for(int i=1 ; i<=m ; ++i)
	{
		cout << (int)nodes[i].size() << " ";
		for(int j=0 ; j<(int)nodes[i].size() ; ++j) cout << nodes[i][j] << " ";
			cout << '\n';
	}
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen(task".inp" , "r" , stdin);
    //freopen(task".out" , "w" , stdout);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}