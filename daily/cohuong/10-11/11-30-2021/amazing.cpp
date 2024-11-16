#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pi pair<int , int>
#define fi first
#define se second
#define pb push_back

const int N = 1e6 + 5 , MOD = 1e9 + 7 , inf = 1e9;
const string None = "";

void file() {
    freopen("amazing.inp" , "r" , stdin);
	freopen("amazing.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

string a , b , ans;

string Min(string a , string b) {
	if(a.size() < b.size()) return a;
	if(a.size() == b.size()) return min(a , b);
	return b;
}

string MakeInf(int n) {
	string res;
	for(int i = 1 ; i <= n ; i++) res += 'z';
    return res;
}

bool Palind(string x) {
	string y = x;
	reverse(y.begin() , y.end());
	if(y == x) return true;
	return false;
}

void calc(string s1 , string s2) {
	if(Palind(s1) && !Palind(s2)) {
		ans = min(ans , None);
		return;
	}
	string x = s1;
	reverse(x.begin() , x.end());
	while(x != None) {
		if((Palind(a + x) && !Palind(b + x)) || (Palind(b + x) && !Palind(a + x))) 
			ans = Min(ans , x);
		x.erase(0 , 1);
	}
}

int main() {
	file();
	cin >> a >> b;
	if(a.size() == b.size() && a == b){
		cout << "No Solution.";
		return 0;
	}
	ans = MakeInf(max(a.size() , b.size()) + 1);
    calc(a , b);
    calc(b , a);
    if(a != Min(a , b)) swap(a , b);
    string x = a;
    reverse(x.begin() , x.end());
    for(char i = 'a'; i <= 'z' ; i++) {
    	if(!Palind(b + i + x)) ans = Min(ans , i + x);
	}
	cout << ans;
	return 0;
}


