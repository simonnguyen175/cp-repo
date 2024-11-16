#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a),_b=(b);i<=_b;++i)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;--i)
#define FORE(i,a) for(auto&i:a)
#define rep(i,b) for(int i=0,_b=(b);i<_b;++i)
#define SZ(a) ((int)a.size())
#define ALL(a) a.begin(),a.end()

template<typename A, typename B>
inline bool ckmax(A& a, B b)
{
	return a<b?a=b,1:0;
}

template<typename A, typename B>
inline bool ckmin(A& a, B b)
{
	return a>b?a=b,1:0;
}

typedef long long ll;

const int nmax=440;
int n,a[nmax],dp[nmax][nmax];

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin>>n;
	FOR(i,1,n){
		cin>>a[i]; a[i]+=a[i-1];
		dp[i][i]=1;
	}
	FOR(len,2,n){
		FOR(i,1,n-len+1){
			int j=i+len-1;
			FOR(k,i,j-1){
				int r_k=i+j-k;
				if(k+1<r_k&&a[k]-a[i-1]==a[j]-a[r_k-1]){
					if(dp[i][k]&&dp[r_k][j]&&dp[k+1][r_k-1])dp[i][j]=1;
				}
				if(a[k]-a[i-1]==a[j]-a[k]){
					if(dp[i][k]&&dp[k+1][j])dp[i][j]=1;
				}
			}
		}
	}
	int res=0;
	FOR(i,1,n)FOR(j,i,n)if(dp[i][j])ckmax(res,a[j]-a[i-1]);
	cout<<res;
	return 0;
}
