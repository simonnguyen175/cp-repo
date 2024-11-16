#include <bits/stdc++.h>
using namespace std;
long long n,a[10000],d=0,x;
int main()
{
	cin>>n>>x;
	for (long long i=1;i<=n;i++)
		cin>>a[i];
	for (long long i=1;i<=n-1;i++)
		for (long long j=i+1;j<=n;j++)
			if (a[i]+a[j]==x) d++;
	cout<<d;
}
