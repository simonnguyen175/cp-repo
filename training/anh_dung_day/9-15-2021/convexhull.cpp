#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
const int N = 1000001;

struct point{
    int x , y;
};

int n;
point pivot;

int dist(point u, point v){
    return (u.x - v.x) * (u.x - v.x) + (u.y - v.y) * (u.y - v.y);
}

int ccw(point a, point b, point c){
    int t = (b.y - a.y) * (c.x - b.x) - (c.y - b.y) * (b.x - a.x);
    if ( t == 0 ) return 0;
    if ( t < 0 ) return -1;
    return 1;
}

bool cmp1(point a , point b){
	if(a.y == b.y) return a.x < b.x;
	return a.y < b.y;
}

bool cmp2(point u , point v){
    int o = ccw(pivot, u, v);
    if ( o == 0 ) return dist(pivot , u) < dist(pivot , v);
    return ( o == -1 );
}

vector<point> convexhull(vector<point> &q){
	vector<point> p;
	sort(q.begin(), q.end(), cmp1);

	for(int i = 0; i < q.size(); i ++){
		p.pb(q[i]);
		while ( i + 1 < q.size() && q[i].x == q[i+1].x && q[i].y == q[i+1].y ) i ++;
	}

	pivot = p[0];
	sort(p.begin() + 1, p.end(), cmp2);

	int m = 0;
	for(int i = 0; i < p.size(); i++){
		while( m >= 2 && ccw(p[m-2], p[m-1], p[i]) >= 0 )
            m--;
	    p[m++] = p[i];
	}

	p.resize(m);
	return p;
}

void solve(){
    if ( n == 0 ) exit(0);
    vector<point> q;
    for(int i = 1 ; i <= n ; i++){
    	int x , y;
    	cin >> x >> y;
    	q.pb({x , y});
	}

	auto res = convexhull(q);
	cout << res.size() << '\n';
	for(auto i : res) cout << i.x << ' ' << i.y << '\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    while ( cin >> n )
        solve();
    return 0;
}
