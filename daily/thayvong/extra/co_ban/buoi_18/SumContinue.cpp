#include<bits/stdc++.h>
using namespace std;
long long t,n,a;
int main(){
	ios::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);
	freopen("SumContinue.inp","r",stdin);
	freopen("SumContinue.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>a;
		long long s=n*(n+1)/2;
		long long k=s-a;
		if(s==a){
			cout<<1<<"\n";
			continue;
		}
		if(k<=2*n && k>2 && k%2==0){
			cout<<-k/2<<"\n";
			continue;
		}
		cout<<0<<"\n";
	}
	return 0;
}
