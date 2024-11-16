#include <bits/stdc++.h>
using namespace std;
long long n,p[6000],ans=0;
pair<int,int> d[6001];
long long rect(int x,int y){
	int i=p[x], j=p[y]; long long s=0;
	while (i<=p[x+1]-1 && j<=p[y+1]-1){
		if (d[i].second==d[j].second){
			i++; j++; s++;
		}
		else 
			if (d[i].second<d[j].second) 
				i++;
			else 
				j++;
	}
	return s*(s-1)/2;
}
int main(){
	freopen("hcn.inp","r",stdin);
	freopen("hcn.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++)
		cin>>d[i].first>>d[i].second;
	sort(d+1,d+n+1);
	p[1]=1; int sd=1;
	for(long long i=2;i<=n;i++)
		if(d[i].first>d[i-1].first)
			p[++sd]=i;
	p[sd+1]=n+1;
	for(long long i=1;i<sd;i++)
		for(long long j=i+1;j<=sd;j++)
			ans+=rect(i,j);
	cout<<ans;
}
