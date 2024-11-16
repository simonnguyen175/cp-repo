#include<bits/stdc++.h>
using namespace std;
string st,s[1000001];
int d;
int main(){
	freopen("CreatString.inp","r",stdin);
	freopen("CreatString.out","w",stdout);
	cin>>st;
	sort(st.begin(),st.end());
	do{
		d++;
		for(int i=0;i<st.size();i++)
			s[d]+=st[i];
	}
	while(next_permutation(st.begin(),st.end()));
	sort(s+1,s+d+1);
	cout<<d<<"\n";
	for(int i=1;i<=d;i++)
		cout<<s[i]<<"\n";
}
