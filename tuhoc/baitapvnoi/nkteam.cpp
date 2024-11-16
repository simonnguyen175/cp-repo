#include<bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define fi first
#define se second
using namespace std;
const ll N=100000+5;

struct student{
	int a,b,c;
} st[N];
int n,a[N],ans=0,f[N];

void update(int i,int u){
	while(i<=100000){
		f[i]=min(f[i],u);
		i+=(i&(-i));
	}
}
int get(int i){
	int ans=1e9;
	while(i>0){
		ans=min(ans,f[i]);
		i-=(i&(-i));
	}
	return ans;
}
bool compair(student x,student y){
	if(x.a<y.a)
		return true;
	return false;
}

int main(){
	ios::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);
	cin>>n;
	int x;
	for(int i=1;i<=n;i++){
		cin>>x;
		st[x].a=i;
	}
	for(int i=1;i<=n;i++){
		cin>>x;
		st[x].b=i;
	}
	for(int i=1;i<=n;i++){
		cin>>x;
		st[x].c=i;
	}
	sort(st+1,st+n+1,compair);

	for(int i=1;i<=n;i++)
		f[i]=1e9;
	for(int i=1;i<=n;i++){
		if(get(st[i].b) < st[i].c)
			ans++;
		update(st[i].b,st[i].c);
	}
	cout<< n - ans;
	return 0;
}
