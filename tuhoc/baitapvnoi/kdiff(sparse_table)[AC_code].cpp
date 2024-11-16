#include<bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define fi first
#define se second
using namespace std;
const ll N=3e5+5;

int n,k,a[N],m1[N][100],m2[N][100];
int g[N],f[N],res=0;

int FindDiff(int l ,int r){
	int Min,Max;
	int cnt=0;
	while(l+(1<<(cnt + 1))-1<=r) cnt++;
    Max=max(a[m2[l][cnt]],a[m2[r-(1 << cnt)+1][cnt]]);
    Min=min(a[m1[l][cnt]],a[m1[r-(1 << cnt)+1][cnt]]);
    return Max-Min;
}

int main(){
//	freopen(".inp","r",stdin);
//	freopen(".out","w",stdout);
	ios::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
		m1[i][0]=m2[i][0]=i;
	for(int j=1;(1<<j)<=n;j++)
		for(int i=0;i+(1<<(j-1))-1<n;i++)
			if(a[m1[i][j-1]]<a[m1[i+(1<<(j-1))][j-1]])
        		m1[i][j]=m1[i][j-1];
      		else m1[i][j]=m1[i+(1<<(j-1))][j-1];
    for(int j=1;(1<<j)<=n;j++)
		for(int i=0;i+(1<<(j-1))-1<n;i++)
			if(a[m2[i][j-1]]>a[m2[i+(1<<(j-1))][j-1]])
        		m2[i][j]=m2[i][j-1];
      		else m2[i][j]=m2[i+(1<<(j-1))][j-1];
    int j=1;
	for(int i=1;i<=n;i++){
		while((j<n)&&(FindDiff(i,j+1)<=k)) j++;
		int l=j-i+1;
		f[i+l-1]=max(f[i+l-1],l);
		g[i]=l;
	}
	for(int i=n;i>=1;i--)
		if(f[i+1]>0 && f[i]==0)
			f[i]=f[i+1]-1;
	for(int i=2;i<=n;i++)
		f[i]=max(f[i-1],f[i]);
	for(int i=1;i<=n;i++)
		res=max(res,g[i]+f[i-1]);
	cout<<res;
}
