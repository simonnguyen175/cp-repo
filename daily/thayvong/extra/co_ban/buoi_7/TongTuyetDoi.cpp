#include <bits/stdc++.h>
using namespace std;
long long n,a[10000],s=0;
int main()
{
	cin>>n;
	for (long long i=1;i<=n;i++)
		cin>>a[i];
	for (long long i=1;i<=n;i++)
		s+=abs(a[i]);
	cout<<s;
}
