#include<bits/stdc++.h>
#define maxl 1200010
using namespace std;

int n,m,ans,cnt,tot;
int b[maxl],num[maxl],in[maxl],out[maxl];
int sum[maxl];
char s[maxl];
struct seg
{
	int l,r;
}a[maxl];

inline void prework()
{
	scanf("%d",&n);
	int l,r;cnt=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&l,&r);
		l=l*2;r=r*2;
		num[++cnt]=l;num[++cnt]=l-1;num[++cnt]=l+1;
		num[++cnt]=r;num[++cnt]=r+1;num[++cnt]=r-1;
		a[i].l=l;a[i].r=r;
	}
	sort(num+1,num+1+cnt);
	tot=unique(num+1,num+1+cnt)-num;
	for(int i=1;i<=tot;i++)
		in[i]=0,out[i]=0;
}


inline void mainwork()
{
	int l,r;
	for(int i=1;i<=n;i++)
	{
		l=lower_bound(num+1,num+1+tot,a[i].l)-num;
		r=lower_bound(num+1,num+1+tot,a[i].r)-num;
		a[i].l=l;a[i].r=r;
		in[l]++;out[r]++;
	}

	int x=0;
	for(int i=1;i<=tot;i++)
	{
		x+=in[i];
		b[i]=x;
		x-=out[i];
	}
	for(int i=1;i<=tot;i++)
	if(b[i]==1 && b[i-1]!=1)
		sum[i]=sum[i-1]+1;
	else
		sum[i]=sum[i-1];
	int bas=0,add;
	for(int i=2;i<=tot;i++)
	if(b[i-1]==0 && b[i]>0)
		bas++;
	ans=bas-1;
	for(int i=1;i<=n;i++)
	{
		add=sum[a[i].r]-sum[a[i].l-1];
		if(b[a[i].l-1]==0 && b[a[i].l]==1)
			add--;
		if(b[a[i].r+1]==0 && b[a[i].r]==1)
			add--;
		ans=max(ans,bas+add);
	}
}

inline void print()
{
	printf("%d\n",ans);
}

int main()
{
	int t=1;
	scanf("%d",&t);
	for(int i=1;i<=t;i++)
	{
		prework();
		mainwork();
		print();
	}
	return 0;
}
