#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
const ll N = 1000001 , MOD = 1e9 +7 , inf = 1e15;
void file()
{
	freopen("team.inp" , "r" , stdin);
	freopen("team.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
 ll n , l[N] , r[N] , Max , s = 0 ;
 pi a[N];
int main()
{
	file();
  cin >> n;
  for (int i = 1 ; i <= n ; i++) cin >> a[i].se >> a[i].fi;
  sort(a + 1 , a + n + 1);
  l[0] = r[n + 1] = inf , Max = 0;
  for (int i = 1 ; i <= n ; i++) l[i] = min(a[i].se - a[i].fi , l[i - 1]); 
  for (int i = n ; i >= 1 ; i--) r[i] = min(a[i].se , r[i + 1]);
  for (int i = 1 ; i <= n ; i++)
  {
  	s += a[i].fi;
  	Max = max(a[i].fi , Max);
    cout << min(s + l[i] , s - Max + r[i + 1]) << '\n';
  }
}
