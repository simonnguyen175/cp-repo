#include<bits/stdc++.h>
using namespace std;

long long n, a[100001], PowNum=0;
bool Pow[100000001];

int main(){
	freopen("PowABC.inp","r",stdin);
	freopen("PowABC.out","w",stdout);
	ios::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);
	cin >> n;
	for(int i=1; i<=n; i++)cin >> a[i];
	Pow[1]=1;
	for(int i=2; i<=sqrt(1e8); i++){
		long long tmp=i;
		while( tmp*i <= 1e8 ){
			tmp *= i;
			Pow[tmp] = 1;
		}
	}
	for(int i=1;i<=n;i++)
		if( Pow[a[i]] ) PowNum++;
	cout << PowNum << '\n' ;
	for(int i=1; i<=n; i++)
		if ( Pow[a[i]] ) cout << a[i] <<'\n';
    return 0;
}
