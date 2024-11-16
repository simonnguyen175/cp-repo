#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
const ll N = 55 , MOD = 3 , inf = 1e15;
void file()
{
	//freopen(".inp" , "r" , stdin);
	//freopen(".out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

struct Matrix
{
	ll v[N][N];
};

 ll t , n , d , b[N] , a[N] , c[N][N];


Matrix combine(Matrix a , Matrix b)
{
	Matrix res;
	for (int i = 1 ; i <= d ; i++)
    	for (int j  = 1 ; j <= d ; j++)
           res.v[i][j] = 0;
	for (int i = 1 ; i <= d ; i++)
	for (int j = 1 ; j <= d ; j++)
	for (int l = 1 ; l <= d ; l++)
	res.v[i][j] = (res.v[i][j] + a.v[i][l] * b.v[l][j]) % MOD;
	return res;
}

Matrix pow(Matrix a , ll b)
{
	if (b == 1) return a;
	Matrix t = pow(a , b / 2);
	t = combine(t , t);
	if (b % 2 == 0) return t ;
	return combine(t , a);
}

int main()
{
	cin >> t;
 while (t--)
 {
 	cin >> n >> d;
 	for (int i = 1 ; i <= d ; i++)
	 {
	 	 cin >> b[i] ;
		 if (b[i] == -1) b[i] = 0;
	 }

    	Matrix ans;
	for (int i = 1 ; i <= d ; i++)
 	for (int j = 1 ; j <= d ; j++)
 	ans.v[i][j] = 0;

 	for (int i = d ; i >= 1 ; i--) ans.v[i][d] = 1 ;
	 for (int i = d - 1 ; i >= 1 ; i--) ans.v[i + 1][i] = 1;
 	ans = pow(ans , n - 1);
 	for (int i = 1 ; i <= d ; i++)
 	for (int j = 1 ; j <= d ; j++)
 	cout << ans.v[i][j] << ' ' << i << ' ' << j << endl;
 	for (int i = 1 ; i <= d ; i++)
 	{
 		c[i][d + 1] = b[i];
 		for (int j = 1 ; j <= d ; j++) c[i][j] = ans.v[j][i];
	}

	for (int i = 1 ; i <= d ; i++)
 	for (int j = 1 ; j <= d + 1; j++)
 	cout << c[i][j] << ' ' << i << ' ' << j << endl;

   for (int i = 1 ; i <= d ; i++)
   	for (int j = 1 ; j <= d ; j++)
   	   {
   		 if (c[i][j] != 0)
   		 {
   		 	for (int x = 1 ; x <= d ; x++)
   		 	{
   		 		if (x == i) continue;
   		 		if (c[x][j] != 0)
   		 		{
   		 			int hs;
   		 			if (c[x][j] == c[i][j]) hs = 2;
   		 			else hs = 1;
   		 			for (int y = 1 ; y <= d + 1 ; y++) c[x][y] = (c[x][y] + hs * c[i][y]) % MOD;
				}
			}
			break;
		 }
	   }

   for (int i = 1 ; i <= d ; i++)
   for (int j = 1 ; j <= d ; j++)
   if (c[i][j])
   {
   	for (int k = 1 ; k <= 3 ; k++) if ((k * c[i][j]) % 3 == c[i][d + 1]) a[j] = k;
   }

   for (int i = 1 ; i <= d ; i++) cout << a[i] << ' ';
   cout << '\n';
 }
}

