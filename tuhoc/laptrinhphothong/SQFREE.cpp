#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n;
ll Ans(ll n)
{
		ll res=1;
		for (int i=2; i<=sqrt(n); i++)
			{
				if (n % i==0)
					{
					    while (n % i==0)
                            n/=i;
						res*=i;
					}
			}
        if (n != 1) res*=n;
		return res;
}
int main()
{
	freopen("SQFREE.inp","r",stdin);
	freopen("SQFREE.out","w",stdout);
	ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
	while (cin >> n)
		cout << Ans(n) <<"\n";
}
