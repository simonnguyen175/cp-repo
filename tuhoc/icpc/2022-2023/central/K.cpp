#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>

const int N = 105 , MOD = 1e9 + 7;

void file()
{
    //freopen(".inp" , "r" , stdin);
    //freopen(".out" , "w" , stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

ll n  , mm , nn , k , sum = 0 ;
char s[N][N];

struct Matrix {
    ll v[N][N];
};

Matrix combine(Matrix a , Matrix b) {
    Matrix res;
    for (int i = 1 ; i <= n ; i++)
     for (int j  = 1 ; j <= n ; j++)
      res.v[i][j] = 0;
    for (int i = 1 ; i <= n ; i++)
     for (int j = 1 ; j <= n ; j++)
      for (int l = 1 ; l <= n ; l++)
       res.v[i][j] = (res.v[i][j] + a.v[i][l] * b.v[l][j]) % MOD;
    return res;
}

Matrix Pow(Matrix a , ll b) {
//	cout << b << '\n';
//	for (int i = 1; i <= n; i ++){
//		for (int j = 1; j <= n; j ++)
//			cout << a.v[i][j] << ' ';
//		cout << '\n';
//	}
	if(b == 1) return a;
	Matrix t = Pow(a, b / 2);
	if(b % 2){
		return combine(combine(t, t), a);
	}
	return combine(t, t);
}

int id(int i , int j) {
	return (i - 1) * mm + j;
}

int main() {
	file();
	cin >> nn >> mm >> k;
	n = nn * mm;
	Matrix c , ans;
	for (int i = 1 ; i <= n ; i++)
	 for (int j = 1 ; j <= n ; j++)
	  	c.v[i][j] = ans.v[i][j] = 0;
	for(int i = 1 ; i <= nn ; i++)
	 for(int j = 1 ; j <= mm ; j++) {
			cin >> s[i][j];
			if(s[i][j] != '#') ans.v[1][id(i , j)] = 1;
		}
	for(int i = 1 ; i <= nn ; i++)
	 for(int j = 1 ; j <= mm ; j++) {
	 	if((s[i][j] == 'U' || s[i][j] == '+') && i > 1 && s[i - 1][j] != '#')
	 		c.v[id(i , j)][id(i - 1 , j)] = 1;
	 	if((s[i][j] == 'D' || s[i][j] == '+') && i < nn && s[i + 1][j] != '#')
	 		c.v[id(i , j)][id(i + 1 , j)] = 1;
	 	if((s[i][j] == 'L' || s[i][j] == '+') && j > 1 && s[i][j - 1] != '#')
	 		c.v[id(i , j)][id(i , j - 1)] = 1;
	 	if((s[i][j] == 'R' || s[i][j] == '+') && j < mm && s[i][j + 1] != '#')
	 		c.v[id(i , j)][id(i , j + 1)] = 1;
	}

//	for (int i = 1; i <= n; i ++){
//		for (int j = 1; j <= n; j ++)
//			cout << c.v[i][j] << ' ';
//		cout << '\n';
//	}

	if(k) {
		c = Pow(c , k);
    	ans = combine(ans , c);
	}

	for (int i = 1 ; i <= n ; i++)
		sum = (sum + ans.v[1][i]) % MOD;
	cout << sum;
	return 0;
}
