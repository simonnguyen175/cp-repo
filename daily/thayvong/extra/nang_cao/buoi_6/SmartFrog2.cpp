#include<bits/stdc++.h>
using namespace std;
long long n,h[1000001],f[1000001],d[1000001],i,k;
int main(){
	freopen("SmartFrog2.inp","r",stdin);
	freopen("SmartFrog2.out","w",stdout);
	cin>>n>>k;
	for(i=1;i<=n;i++)
		cin>>h[i];
	f[2]=abs(h[1]-h[2]);
	for(i=3;i<=n;i++){
		f[i]=f[i-1]+abs(h[i]-h[i-1]);
		for(int j=2;j<=k;j++){
			if((i-j)>0)
				f[i]=min(f[i],f[i-j]+abs(h[i]-h[i-j]));
		}
	}
	cout<<f[n]<<"\n";
	i=n; d[n]=1;
	while(i!=1){
		for(int j=1;j<=k;j++)
			if(f[i]==f[i-j]+abs(h[i]-h[i-j])){
				d[i-j]++;
				i=i-j;
				break;
			}
	}
	for(int i=1;i<=n;i++)
		cout<<d[i];
}
