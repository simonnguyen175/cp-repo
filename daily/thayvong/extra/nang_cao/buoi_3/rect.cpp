#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n,a[1000001],b[1000001];
int main()
{
	freopen("rect.inp","r",stdin);
	freopen("rect.out","w",stdout);
	ios::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);
	ll i,j,dem=0;
	cin >> n ;
	for (i=1; i<=n; i++) cin >> a[i];
	for (i=1; i<=n; i++) cin >> b[i];
	i=1; j=1; dem=0;
	while (i <= n && j <=n)
    {
        if (a[i]==b[j])
        {
            dem++;
            i++;
            j++;
        }
        else
            if (a[i]<b[j]) i++;
                else j++;
    }
	cout << dem*(dem-1)/2;
}
