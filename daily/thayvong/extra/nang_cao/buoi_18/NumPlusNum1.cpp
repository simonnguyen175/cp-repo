#include<bits/stdc++.h>
using namespace std;
#define simon "NumPlusNum"
#define ll long long
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const string FILE_NAME = "NumPlusNum";
ll d[10001] , t , a , b , m;
bool c[10001];

int main()
{
    FASTio
    if ( fopen(simon".inp","r") ){
        freopen(simon".inp","r",stdin);
        freopen(simon".out","w",stdout);
    }
	cin >> t;
	while(t--)
	{
		cin >> a >> b >> m;
		memset(c , false , sizeof c);
		if (a == m || b == m) {cout << 0 << '\n'; continue;}
		ll nc = 2 , lap = 1 , e = 0 , Tim;
		d[0] = a;
		d[1] = b;
		while(lap)
		{
			lap = 0;
			e++;
			ll u = nc;
			for (ll i = 0 ; i < u ; ++i)
			{
				if (Tim == 1) break;
				for (ll j = i + 1 ; j < u ; j++)
				{
					if (d[i] + d[j] == m)
					{
						cout << e << '\n';
						Tim = 1;
						lap = 0;
						break;
					}
					if (d[i] + d[j] < m && !c[d[i] + d[j]])
					{
						d[nc] = d[i] + d[j];
						nc++;
						lap = 1;
						c[d[i] + d[j]] = true;
					}
				}
			}
		}
		if (Tim == 0) cout << -1  << '\n';
	}
}
