#include<bits/stdc++.h>
using namespace std;
int x,y,n,a[1000001],b[1000001];
string s;
int main(){
	freopen("ROBOTMV.inp","r",stdin);
	freopen("ROBOTMV.out","w",stdout);
	ios::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);
	cin>>x>>y>>s>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i]>>b[i];
	for(int i=0;i<=s.length();i++){
		if(s[i]=='U') y++;
		if(s[i]=='D') y--;
		if(s[i]=='R') x++;
		if(s[i]=='L') x--;
	}
	cout<<x<<" "<<y<<"\n";
	for(int i=2;i<=n;i++){
		if(a[i]==a[i-1]+1 && b[i]==b[i-1]) cout<<"R";
		if(a[i]==a[i-1]-1 && b[i]==b[i-1]) cout<<"L";
		if(b[i]==b[i-1]+1 && a[i]==a[i-1]) cout<<"U";
		if(b[i]==b[i-1]-1 && a[i]==a[i-1]) cout<<"D";
	}
}
