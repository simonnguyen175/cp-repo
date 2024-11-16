#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pi pair<ll,ll>
#define fi first
#define se second
#define pb push_back

const ll N = 2000005 , MOD = 1e9 + 7 , inf = 1e15;

void file() {
	freopen("RESTRING.inp" , "r" , stdin);
	freopen("RESTRING.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

string str;
ll Hash[N] , Pow[N] , c = 0 , n , base = 31;
pi ans;

ll get(int x , int y) {
	return (Hash[y] - Hash[x - 1] * Pow[y - x + 1] + MOD * MOD) % MOD;
}

void Mid() {
	if(get(1 , n /2) == get(n / 2 + 2 , n)) c++ , ans.fi = 1 , ans.se = n / 2;
}

void Suf() {
	int st = n / 2 + 1;
	for(int i = n / 2 + 1 ; i < n ; i++) {
		if(get(st , i) == get(1 , i - st + 1) && get(i - st + 2 , n / 2) == get(i + 2 , n)) {
		     c++;
			if(c >= 1 && get(1 , n / 2) == get(ans.fi ,ans.se)) c--;
			 ans.fi = 1 , ans.se = n / 2;
		}

	}
}

void Pre() {
	int st = n / 2 + 1;
	for(int i = n / 2 + 1 ; i >= 2 ; i--) {
		if(get(i , st) == get(n - st + i , n) && get(1 , i - 2) == get(st + 1 , n - st + i - 1)) {
			  c++;
			if(c >= 1 && get(st + 1 , n) == get(ans.fi ,ans.se)) c--;
			  ans.fi = st + 1 , ans.se = n;
		}
	}
}

int main() {
	file();
 cin >> n >> str;
 str = ' ' + str;
 Pow[0] = 1;
 for(int i = 1 ; i <= n ; i++) Pow[i] = (Pow[i - 1] * base) % MOD;
 for(int i = 1 ; i <= n ; i++) Hash[i] = (Hash[i - 1] * base + str[i] - 'a' + 1) % MOD;
 Mid();
 Pre();
 Suf();
 if(c == 0) cout << "NOT POSSIBLE";
 if(c > 1)  cout << "NOT UNIQUE";
 if(c == 1) for(int i = ans.fi ; i <= ans.se ; i++) cout << str[i];
  return 0;
}



