#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<int , int>
#define eps  1e-6

const int N = 1e3 + 5 , MOD = 1e9 + 7 , inf = 1e9 + 7;

void file() {
	freopen("dg.inp" , "r" , stdin);
	freopen("dg.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

struct Point{
    double x , y;
    Point() {x = y = 0;}
    Point(double x, double y) : x(x), y(y) {}
    Point operator + (const Point &a) const {return Point(x + a.x, y + a.y);}
    Point operator - (const Point &a) const {return Point(x - a.x, y - a.y);}
    double operator % (const Point &a) const {return x * a.y - y * a.x;} // cross product
    bool operator < (const Point&s) const {return x < s.x;};
};

struct line {
	int a , b , c;
};

int n , T_u , T_v;
Point u , v , a[N];

double dist(Point u , Point v){
    return (u.x - v.x) * (u.x - v.x) + (u.y - v.y) * (u.y - v.y);
}

bool check(Point m) {
	double Area = 0;
	for(int i = 1 ; i <= n ; i++) Area += (a[i] % a[i + 1]);
	Area = abs(Area);
	for(int i = 1 ; i <= n ; i++) Area -= abs((a[i] - m) % (a[i + 1] - m));
	if(abs(Area) <= eps) return true;
	return false;
}

line find(Point a , Point b) {
	line res;
	if(a.x == b.x) res = {1 , 0 , int(-a.x)};
	else if(a.y == b.y) res = {0 , 1 , int(-a.y)};
	else {
	res.a = a.y - b.y;
	res.b = b.x - a.x;
	res.c = a.x * b.y - b.x * a.y;
    }
	return res;
}

Point Get(line x1 , line x2) {
	Point res ;
	res.x = (x1.b * x2.c - x2.b * x1.c) * 1.0 / (x1.a * x2.b - x2.a * x1.b);
	res.y = (x2.a * x1.c - x1.a * x2.c) * 1.0 / (x1.a * x2.b - x2.a * x1.b);
	return res;
}

bool IsCut(line x1 , line x2) {
	return (x1.a * x2.b != x2.a * x1.b);
}

bool In(Point a , Point b , Point s) {
	double p1 = sqrt(dist(a , s));
	double p2 = sqrt(dist(b , s));
	double p3 = sqrt(dist(a , b));
	if(abs(p1 + p2 - p3) <= eps) return true;
	return false;
}

void solve() {
	set<Point> P;
    line D = find(u , v);
	for(int i = 1 ; i <= n ; i++) {
		line C = find(a[i] , a[i + 1]);
		if(IsCut(D , C)) {
			Point s = Get(D , C);
			if(In(u , v , s) && In(a[i] , a[i + 1] , s)) P.insert(s);
		}
    }
	if(P.size() == 2) cout << fixed << setprecision(6) << sqrt(dist(*P.begin() , *P.rbegin()));
	else if(P.size() == 1) cout << fixed << setprecision(6) << sqrt(dist(v , *P.begin()));
	else cout << "0.000000";
}

int main() {
	file();
	cin >> n;
	for(int i = 1 ; i <= n ; i++) cin >> a[i].x >> a[i].y;
	a[n + 1] = a[1];
	cin >> u.x >> u.y >> v.x >> v.y;
	T_u = check(u) , T_v = check(v);
	if(T_u > T_v) swap(T_u , T_v) , swap(u , v);
	if(T_u == 1) cout << fixed << setprecision(6) << sqrt(dist(u , v));
	else solve();
	return 0;
}

