#include<bits/stdc++.h>
using namespace std;
string s;
int n,d=0;
bool check(string s){
	if(s.length()==1) return true;
	for(int i=1;i<=s.length()-1;i++)
		if(s[i]!=s[i-1]) return false;
	return true;
}
int main(){
	freopen("numbalance.inp","r",stdin);
	freopen("numbalance.out","w",stdout);
	ios::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s;
		if(check(s)) d++;
	}
	cout<<d;
}
