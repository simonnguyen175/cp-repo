#include<bits/stdc++.h>
using namespace std;
long long n,h[1000001],f[1000001],d[1000001],i;
int main(){
	freopen("SmartFrog1.inp","r",stdin);
	freopen("SmartFrog1.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>h[i];
	f[2]=abs(h[1]-h[2]);
	for(i=3;i<=n;i++){
		f[i]=min(f[i-1]+abs(h[i]-h[i-1]),f[i-2]+abs(h[i]-h[i-2]));
	}
	cout<<f[n]<<"\n";
	i=n; d[n]=1;
	while(i!=1){
		if(f[i]==f[i-1]+abs(h[i]-h[i-1])){
			d[i-1]++; i=i-1;
		}
		else{
			d[i-2]++; i=i-2;
		}
	}
	for(int i=1;i<=n;i++)
		cout<<d[i];
}
