#include<bits/stdc++.h>
using namespace std;

long long n, PowNum=0;
map<long long, long long> Pow;

int main(){
	freopen("UnPower.inp","r",stdin);
	freopen("UnPower.out","w",stdout);
	ios::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);
	cin >> n;
	for(int i=2; i <= sqrt(n); i++){
		long long tmp=i;
		while( tmp*i <= n ){
			tmp *= i;
            if ( !Pow[i] ){
                PowNum++;
                Pow[tmp]=1;
            }
		}
	}
	cout << n - PowNum;
    return 0;
}
