#include <bits/stdc++.h>
using namespace std;
long long n,a[10000000],dem;
bool ktra(long long n)
{
	long long cs=n%10, temp;
	while (n>0)
	{
		temp=n%10;
		if (cs==temp) n=n/10; else return false;
	}
	return true;
}
int main()
{
    ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    cin>>n;
	dem=0;
	for (long long i=1; i<=n; i++)
		{
			cin>>a[i];
			if (ktra(a[i])) dem++;
        }
	cout<<dem;
}

