#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],f[200005][3];
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	f[1][0]=0;
	f[1][1]=a[1];
    for(int i=2;i<=n;i++)
	{
		f[i][0]=min(f[i-1][0],f[i-1][1]-a[i]);
		f[i][1]=min(f[i-1][1],f[i-1][0]+a[i]);
	}
	cout<<min(f[n][0],f[n][1]);
}
