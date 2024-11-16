#include<bits/stdc++.h>
using namespace std;
pair<long long,long long> a[200001];
long long x,y,n;
void sol(long long d, long long c){
	long long s=0; bool kt=true;
	sort(a+d,a+c+1);
	for(long long i=d;i<=c;i++){
		s+=a[i].second;
		if(s>a[i].first){
			kt=false;
			break;
		}
	}
	if(kt) cout<<"YES";
	else cout<<"NO";
	cout<<"\n";
}
int main(){
	freopen("WORK.INP","r",stdin);
	freopen("WORK.OUT","w",stdout);
	ios::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);
	cin>>n;
	for(long long i=1;i<=n;i++)
		cin>>a[i].second>>a[i].first;
	cin>>x>>y;
	sol(1,x);
	sol(x+1,y);
	sol(y+1,n);
	return 0;
}
