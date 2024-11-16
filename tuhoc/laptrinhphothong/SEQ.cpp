#include <bits/stdc++.h>
using namespace std;

int n,m;
long long dp[100001];

int main(){
	cin >> n >> m;
	for (int i=1; i<=n; i++)
        dp[i]=1;
	long long res = 1;
	for (int i=2; i<=n; i++){
		for (int j=1; j < i ; j++){
			if ( i % j == 0 ){
				dp[i] += (m-1) + dp[j] -1;
			}
		}
		res += dp[i];
	}
	cout << res;
	return 0;
}
