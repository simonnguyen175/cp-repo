#include<bits/stdc++.h>
using namespace std;
pair <int,int> a[200001],c[200001];
int ans,n,m,b[200001];
int bin1(pair <int,int> a[],int n,int x){
	int d=1,c=n,g,i;
	if(x<=a[1].first) return a[1].second;
	if(x>=a[n].first) return a[n].second;
	while(d<=c){
		g=(d+c)/2;
		if(a[g].first>x) c=g-1;
		else {i=g; d=g+1;}
	}
	int ct=i;
	if(a[i+1].first-x<x-a[i].first) ct=i+1;
	else if(a[i+1].first-x==x-a[i].first)
		if(a[i+1].second<a[i].second) ct=i+1;
	return a[ct].second;
}
int main(){
	freopen("IndexAB.inp","r",stdin);
	freopen("IndexAB.out","w",stdout);
	ios::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i].first;
	for(int i=1;i<=n;i++) a[i].second=i;
	for(int i=1;i<=m;i++) cin>>b[i];
	sort(a+1,a+n+1);
	int k=1; c[k] = a[1];
	for(int i=2;i<=n;i++)	
		if(a[i].first>a[i-1].first){
			k++; c[k]=a[i];
		}
	for(int i=1;i<=m;i++){
		cout<<bin1(c,k,b[i])<<"\n"; 
	} 
}

