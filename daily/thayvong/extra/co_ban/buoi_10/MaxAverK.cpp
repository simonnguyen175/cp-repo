#include <bits/stdc++.h>
using namespace std;

long long a[2000001],s[2000001],tk[2000001] ;
long long n , k;

int main()
{
	freopen("MaxAverK.inp","r",stdin);
	freopen("MaxAverK.out","w",stdout);
	cin >> n >> k;

	for (int i=1; i<=n; i++)
        cin >> a[i];

	s[0] = 0;

	for(int i = 1 ; i <= n ; i++)
			s[i] =  s[i-1] + a[i];

	for(int i = 1 ; i <= n - k + 1 ; i++)
		{
		    tk[i] = s[i+k-1] - s[i-1];
		}

    long long Max=INT_MIN;
	for(int i = 1 ; i <= n - k + 1 ; i++)
        Max=max(Max,tk[i]);

	cout << fixed <<setprecision(6)<< Max*1.0/k;
	return 0;
}

