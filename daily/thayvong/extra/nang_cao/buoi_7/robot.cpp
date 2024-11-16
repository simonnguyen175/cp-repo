
#include<bits/stdc++.h>
using namespace std;
int a[10001][10001],m,n,s[10001][10001],u,v;
int main(){
	freopen("ROBOT.INP","r",stdin);
	freopen("ROBOT.OUT","w",stdout);
	ios::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);
	cin>>m>>n>>u>>v;
	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++)
			cin>>a[i][j];
	s[1][1]=a[1][1];
	for(int i=2;i<=u;i++)
		s[i][1]=s[i-1][1]+a[i][1];
	for(int i=2;i<=v;i++)
		s[1][i]=s[1][i-1]+a[1][i];
	for(int i=2;i<=u;i++)
		for(int j=2;j<=v;j++)
			s[i][j]=max(s[i-1][j],s[i][j-1])+a[i][j];
	for(int i=u+1;i<=m;i++)
		s[i][v]=s[i-1][v]+a[i][v];
	for(int i=v+1;i<=n;i++)
		s[u][i]=s[u][i-1]+a[u][i];
	for(int i=u+1;i<=m;i++)
		for(int j=v+1;j<=n;j++)
			s[i][j]=max(s[i-1][j],s[i][j-1])+a[i][j];
	cout<<s[m][n];
}
