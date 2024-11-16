#include<bits/stdc++.h>
using namespace std;
int n,m,a[10001][10001],ans=INT_MIN,j=1,d[100001];
int main(){
	freopen("Diagon2.inp","r",stdin);
	freopen("Diagon2.out","w",stdout);
	ios::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>a[i][j];
	for(int i=1;i<=m-2;i++){
		for(int k=1;k<=j;k++)
			d[k]=0;
		j=1; d[1]=a[1][i];
		while(i+j<=m && 1+j<=n){
			d[j+1]=a[1+j][i+j]; j++;
		}
		sort(d+1,d+j+1);
		ans=max(ans,d[j-1]+d[j-2]+d[j]);
	}
	for(int i=2;i<=n-2;i++){
		for(int k=1;k<=j;k++)
			d[k]=0;
		j=1; d[1]=a[i][1];
		while(i+j<=n && 1+j<=m){
			d[j+1]=a[i+j][1+j]; j++;
		}
		sort(d+1,d+j+1);
		ans=max(ans,d[j-1]+d[j-2]+d[j]);
	}
	cout<<ans;
}
