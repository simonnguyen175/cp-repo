#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5; 

int n;
string s; 
int t[N], d[N], f[N]; 

int calc(int len){
	int res = 0;
	for (int i = len; i <= n; i ++) 
		res = max(res, t[i] - t[i-len]); 
	return res;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0); 
	
	cin >> n >> s;
	s = ' ' + s; 
	for (int i = 1; i <= n; i ++)
		t[i] = t[i-1] + (s[i] == '1');
		
	int cur = 1;
	while ( cur <= n ){
		d[cur] = 1;
		cur = (int) cur * 1.05 + 1; 
	} 	
	 
	for (int i = 1; i <= n; i ++) if ( d[i] ) 
		f[i] = calc(i);
	else f[i] = f[i-1]; 
	
	for (int i = 1; i <= n; i ++)
		cout << f[i] << ' '; 
		
	return 0;  
}
