#include<bits/stdc++.h>
using namespace std;
int n,f[500001],g[500001],a[500001],ans=0;
int main(){
	freopen("IncLen.INP","r",stdin);
	freopen("IncLen.OUT","w",stdout);
	ios::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	f[0]=0; g[n+1]=0;
	for(int i=1;i<=n;i++){
		if(a[i]>=a[i-1]) f[i]=f[i-1]+1;
		else f[i]=1;
		ans=max(ans,f[i]);
	}
	for(int i=n;i>=1;i--){
		if(a[i]<=a[i+1]) g[i]=g[i+1]+1;
		else g[i]=1;
		ans=max(ans,g[i]);
	}
	for(int i=2;i<=n-1;i++)
		if(a[i-1]<=a[i+1]) ans=max(f[i-1]+g[i+1],ans);
	cout<<ans;
}

