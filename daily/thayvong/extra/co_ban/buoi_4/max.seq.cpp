#include <bits/stdc++.h>
using namespace std;
long long a[1000000], n, i,s,ans;
int main()
{
	ios::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);
	i=1;
	while (i<=n)
	{
		s=s+a[i];
		if (s<0)
		{
			i++;
			s=0;
		}
		if (s>ans) ans=s;
		i++;
	}
	cout<<ans;
}
