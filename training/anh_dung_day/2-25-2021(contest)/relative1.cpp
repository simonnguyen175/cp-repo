#include<bits/stdc++.h>
using namespace std;
long long n,a[100001],ans=0,d[(1<<10)];
int main(){
	ios::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++){
		long long x=a[i],temp=0;
		while(x!=0){
			temp |=(1 << (x%10));
			x/=10;
		}
		d[temp]++;
	}
	for(int i=1;i<=(1 << 10);i++){
		ans+=d[i]*(d[i]-1)/2;
		for(int j=i+1;j<=(1 << 10);j++)
			if(i & j) ans+=d[i]*d[j];
	}
	cout<<ans;
	return 0;
}
