#include <bits/stdc++.h>
using namespace std;
long long n,m,a[200000],i,ans,s,dem,cou;
int main()
{
	cin>>n>>m;
	for(i=1; i<=n;  i++) cin>>a[i];
	i=1;
	long long d=1,c;
	while (i<=n)
	{
		s+=a[i];
		dem++;
		if (s>m)
		{
			d++;
			s=s-a[i-dem+1];
		}
		if (s==k) cou++;
	}
	cout<<cou;
}
