#include<bits/stdc++.h>
using namespace std;

long long n,q=0,a[100001],b[100001],k,res=0;
map<long long,long long> d;

int main()
{
	freopen("SumPK.inp","r",stdin);
	freopen("SumPK.out","w",stdout);
	cin>>n>>k;
	for (ll i=1;i<=n;i++)
	{
		cin>>a[i];
		++d[a[i]];
		if (d[a[i]]==1) b[++q]=a[i];
	}
	for (ll i=1;i<=n;i++)
	{
		if (b[i]==k-b[i])
		{
			long long p=d[a[i]]/2;
			res=res+p*(p-1)/2+(d[a[i]]-p)*(d[a[i]]-p-1)/2;
		}
	}
	cout<<res;
	return 0;
}
