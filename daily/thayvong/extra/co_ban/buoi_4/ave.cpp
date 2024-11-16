#include <bits/stdc++.h>
using namespace std;
long long n,b[1000000],a[1000000],i;
int main()
{
    cin>>n;
    for (i=1; i<=n; i++)
    {
        cin>>b[i];
        b[i]=b[i]*i;
        a[i]=b[i]-b[i-1];
    }
	for (i=1; i<=n; i++)
	{
		cout<<a[i]<<" ";
	}
}
