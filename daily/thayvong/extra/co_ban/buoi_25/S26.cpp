#include<bits/stdc++.h>
#define ll long long
using namespace std;

string s;
int d[10000],num=0,pos=0,ans=1e15;

int main(){
	freopen("S26.inp","r",stdin);
	freopen("S26.out","w",stdout);
	ios::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);
	cin>>s;
	for(int i=0;i<s.size();i++){
		d[s[i]]++; if(d[s[i]]==1) num++;
		while(num==26){
			d[s[pos]]--;
			if(d[s[pos]]==0) num--;
			pos++;
			if(num==26) ans=min(ans,i-pos+1);
		}
	}
	cout<<ans;
	return 0;
}
