#include<bits/stdc++.h>
#define ll long long
#define ii pair<ll,ll>
#define fi first
#define se second
using namespace std;

ll dp[501][10001],n,s,ans=-1;
ii a[501];

int main(){
	freopen("SSS.inp","r",stdin);
	freopen("SSS.out","w",stdout);
	ios::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);
	cin>>n>>s;
	for(int i=1;i<=n;i++)
		cin>>a[i].fi>>a[i].se;
	memset(dp,0,sizeof dp);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=s;j++){
			dp[i][j]=dp[i-1][j];
			if((j-a[i].fi>0 && dp[i-1][j-a[i].fi]!=0) || (j==a[i].fi))
				dp[i][j]=max(dp[i][j],dp[i-1][j-a[i].fi]+a[i].se);
			if(j==s)
				ans=max(ans,dp[i][j]);
		}
	}
	if(ans==0) ans=-1;
	cout<<ans;
	return 0;
}
