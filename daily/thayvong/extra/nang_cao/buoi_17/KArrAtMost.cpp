#include<bits/stdc++.h>
#define ll long long
using namespace std;

map <ll,ll> d;
ll n, k, j, a[200001],ans=0, xk=0;

int main(){
	freopen("KArrAtMost.inp","r",stdin);
	freopen("KArrAtMost.out","w",stdout);
	ios::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);
	cin >> n >> k;
	for(int i=1; i<=n; i++)
		cin>>a[i];
	j=1; xk=0;
	for(int i=1; i<=n; i++){
		d[a[i]]++;
		if( d[a[i]] == 1 ) xk++;
		while ( xk > k ){
			d[a[j]]--;
			if(d[a[j]]==0) xk--;
			j++;
		}
		ans+=i-j+1;
	}
	cout<<ans;
	return 0;
}
