#include<bits/stdc++.h>
#define ll long long
#define ii pair<ll,ll>
#define fi first
#define se second
using namespace std;

ll t,n,x,y;
ii a[1000001];

int main(){
	freopen("TENT.inp","r",stdin);
	freopen("TENT.out","w",stdout);
	ios::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>x>>y;
		for(int i=1;i<=n;i++)
			cin>>a[i].fi>>a[i].se;
		sort(a+1,a+n+1);
		ll e=x;
		for(int i=1;i<=n;i++)
			if(a[i].fi<=e) e=max(e,a[i].se);
		if(e>=y) cout<<1<<"\n";
		else cout<<0<<"\n";
	}
	return 0;
}
