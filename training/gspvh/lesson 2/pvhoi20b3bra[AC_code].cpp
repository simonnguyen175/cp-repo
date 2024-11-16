#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pi pair<int , int>
#define fi first
#define se second
#define pb push_back

const int N = 1e6 + 5 , MOD = 998244353 , inf = 1e9;

void file() {
    //freopen(".inp" , "r" , stdin);
	//freopen(".out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

struct node {
	int Min , Max , lazy;
};

int n , q , a[N] , p[N] , sum = 0;
string str;
node st[4 * N];

void dow(int id) {
	int t = st[id].lazy;
	st[id].lazy = 0;
	st[id * 2].Min += t;
	st[id * 2].Max += t;
	st[id * 2 + 1].Max += t;
	st[id * 2 + 1].Min += t;
	st[id * 2].lazy += t;
	st[id * 2 + 1].lazy += t;
}

void update(int id , int l , int r , int u , int v , int val) {
	if(u > r || v < l) return;
	if( u <= l && r <= v ){
		st[id].Min += val;
		st[id].lazy += val;
		st[id].Max += val;
		return;
	}
	int mid = (l + r) / 2;
	dow(id);
	update(id * 2 , l , mid , u , v , val);
	update(id * 2 + 1 , mid + 1 , r , u , v , val);
	st[id].Min = min(st[id * 2].Min , st[id * 2 + 1].Min);
	st[id].Max = max(st[id * 2].Max , st[id * 2 + 1].Max);
}

int Get(int id , int l , int r) {
	if(l == r) {
		if(st[id].Min >= 2) return l;
		else return inf;
	}
	dow(id);
	int mid = (l + r) / 2;
	if(st[id * 2 + 1].Min >= 2) {
		return min(Get(id * 2 , l , mid) , mid + 1);
	}
	else return Get(id * 2 + 1 , mid + 1 , r);
}

int Find(int id , int l , int r) {
	if(l == r) {
		if(st[id].Max == r) return r;
		else return -inf;
	}
	dow(id);
	int mid = (l + r) / 2;
	if(st[id * 2].Max == mid) {
		return max(mid , Find(id * 2 + 1 , mid + 1 , r));
	}
	else return Find(id * 2 , l , mid);
}

void Solve1(int i) {
	if(i == 1) {
		cout << 1 << ' ';
		return ;
	}
	int res;
	a[i] = -a[i];
	update(1 , 1 , n , i , n , -2);
	res = Find(1 , 1 , n) + 1;
	update(1 , 1 , n , res , n , 2);
	a[res] = -a[res];
	cout << res << ' ';
}

void Solve2(int i) {
	int res;
	a[i] = -a[i];
	update(1 , 1 , n , i , n , 2);
	res = Get(1 , 1 , n);
	update(1 , 1 , n , res , n , -2);
	a[res] = -a[res];
	cout << res << ' ';
}

int main() {
	file();
	cin >> n >> q >> str;
	str = ' ' + str;
	for(int i = 1 ; i <= q ; i++) cin >> p[i];
	for(int i = 1 ; i <= n ; i++) {
		if(str[i] == ')')  a[i] = -1;
		else a[i] = 1;
		sum = sum + ((str[i] == ')') ? -1 : 1);
		update(1 , 1 , n , i , i , sum);
    }

    for(int i = 1 ; i <= q ; i++) {
    	if(a[p[i]] == 1) Solve1(p[i]);
    	else Solve2(p[i]);
	}
	return 0;
}
