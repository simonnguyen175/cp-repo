#include<bits/stdc++.h>
using namespace std;
long long n,a[500001],s1=0,s2=0,c[500001];
int main(){
	ios::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);
	freopen("IncDec.inp","r",stdin);
	freopen("IncDec.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
		c[i]=a[i];
	for(int i=2;i<=n;i++)
		if(a[i]<a[i-1]){
			s1+=a[i-1]-a[i];
			a[i]=a[i-1];
		}
	for(int i=n-1;i>=1;i--)
		if(c[i]<c[i+1]){
			s2+=c[i+1]-c[i];
			c[i]=c[i+1];
		}
	cout<<min(s1,s2);
}
