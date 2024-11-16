#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ii pair<ll,ll>
#define fi first
#define se second
#define mp(a,b) make_pair(a,b)
#define pb push_back
const string FILE_NAME = "GAME";
const ll maxx = 1e3 + 5;
ll n , s[maxx] , f[maxx][maxx] , a[maxx] , t;
void file()
{
	FASTio
	if (fopen((FILE_NAME + ".inp").c_str(),"r"))
	{
		freopen((FILE_NAME + ".inp").c_str() , "r" , stdin);
		freopen((FILE_NAME + ".out").c_str() , "w" , stdout);
	}
}
void solve()
{
	cin >> n;
	s[0] = 0;
	for (ll i = 1 ; i <= n ; ++i)
	{
		cin >> a[i];
		s[i] = s[i-1] + a[i];
	}

	for (ll i = 1 ; i <= n ; ++i)
		f[i][i] = a[i];
	for (ll i = 1 ; i <= n ; ++i)
		f[i][i+1] = max(a[i] , a[i+1]);
	for (ll i = n ; i >= 1 ; --i)
	for (ll j = i + 2 ; j <= n ; j++)
		f[i][j] = max(a[i] + s[j] - s[i] - f[i+1][j] , a[j] + s[j-1] - s[i-1] - f[i][j-1]);
	if (f[1][n] > s[n] - f[1][n]) cout << "YES";
	else cout << "NO";
	cout << '\n';
}
int main()
{
	file();
	cin >> t;
	while(t--)
		solve();
	return 0;
}
