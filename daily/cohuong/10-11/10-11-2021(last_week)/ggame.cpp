#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define pi pair <int , int>
#define fi first
#define se second
using namespace std;

const int N = 1e5 + 5;

void file() {
	freopen("GGAME.inp" , "r" , stdin);
	freopen("GGAME.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0) , cout.tie(0);
}

int n , m , k , p , ans = 0 , Max = 0 , bit[N];
map<int , int> pos;
vector<int> num;
pi a[N];

void update(int u , int val) {
	for(int i = u ; i <= p ; i += (i & (-i))) bit[i] = max(bit[i] , val);
}

int get(int u) {
	int res = 0;
	for(int i = u ; i >= 1 ; i -= (i & (-i))) res = max(res , bit[i]);
	return res;
}

int LIS(int x) {
	int res = 0;
	vector<int> num;
	memset(bit , 0 , sizeof(bit));
	
	for(int i = 1 ; i <= k ; i++) {
		if(i == x) continue;
		int tmp = get(pos[a[i].se]);
		res = max(res , tmp + 1);
		update(pos[a[i].se] , tmp + 1);
	}
	return res;
}

int main() {
	file();
  cin >> m >> n >> k;
  for(int i = 1 ; i <= k ; i++) cin >> a[i].fi >> a[i].se;
  sort(a + 1 , a + k + 1);
  for(int i = 1 ; i <= k ; i++) num.pb(a[i].se);
  num.erase(unique(num.begin() , num.end()) , num.end());
  sort(num.begin() , num.end());
  p = num.size();
  for(int i = 0 ; i < num.size() ; i++) pos[num[i]] = i + 1;
  Max = LIS(0);
  for(int i = 1 ; i <= k ; i++) if(LIS(i) != Max) ans++;
  cout << ans;
  return 0; 
}
