#include <iostream>
#include <string.h>
#include <vector>
using namespace std;
vector<int> v[500005];
int m=1,a[500005],dp[20][500005];
long long ans;
void dfs(int node,int p)
{
	dp[0][node]=p;
	for (int i=1;i<20;i++)
	{
		if (dp[i-1][node]!=-1)
		dp[i][node]=dp[i-1][dp[i-1][node]];
	}
	int d;
	long long mn=(1LL<<60);
	for (d=0;d<20 && dp[d][node]!=-1;d++)
	mn=min(mn,(long long)(d+1)*a[dp[d][node]]+a[node]);
	mn=min(mn,(long long)(d+1)*a[m]+a[node]);
    cout << node << ' ' << d << '\n';

    if (p!=-1)
	ans+=mn;
	for (int u:v[node])
	{
		if (u!=p){
            dfs(u,node);
        }
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if (a[i]<a[m])
		m=i;
	}
	for (int i=1;i<n;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	memset(dp,-1,sizeof(dp));
	dfs(m,-1);
	printf("%I64d",ans);
}
