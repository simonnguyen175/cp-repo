#include<bits/stdc++.h>
using namespace std;
int n,k;
string y,x;
bool check(string x,string y){
	int d=0;
	for(int i=0;i<=y.length()-1;i++){
		if(y[i]==x[d]) d++;
	}
	if (d==x.length()) return true;
	else return false;
}
int main(){
	freopen("SUBS.INP","r",stdin);
	freopen("SUBS.OUT","w",stdout);
	cin>>n>>k>>y;
	while(cin>>x){
		cout<<check(x,y)<<"\n";
	}
}

