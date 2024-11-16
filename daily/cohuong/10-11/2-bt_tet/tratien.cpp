#include <bits/stdc++.h>
using namespace std;

int n,m, a[101], b[101], f[101][10001];

int main(){
    freopen("tratien.inp","r",stdin);
    freopen("tratien.out","w",stdout);
	cin >> n >> m;
	for (int i=1; i<=n; i++)
		cin >> a[i];
	for (int i=0; i<=n; i++) f[i][0]=0;
	for (int i=1; i<=m; i++) f[0][i]=1000000000;
	for (int i=1; i<=n; i++)
		for (int j=1; j<=m; j++)
			if ( j >= a[i] )
				f[i][j]= min(f[i-1][j], f[i][j-a[i]]+1);
			else f[i][j]= f[i-1][j];
	cout << f[n][m] << '\n';
	int i=n;
	while (m > 0){
		for (int k=1; k <=n; k++)
			if ( (f[i][m] == f[k][m-a[k]]+1) && m-a[k] >= 0 ){
				i=k;
				m-=a[k];
				b[k]++;
				break;
			}
	}
	for (int i=1; i<=n; i++)
		cout << b[i] << ' ';
}
