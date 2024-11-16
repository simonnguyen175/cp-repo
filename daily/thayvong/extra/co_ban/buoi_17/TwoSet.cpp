#include<bits/stdc++.h>
using namespace std;
bool d[1000001];
#define ll long long
ll a[1000001];
int main(){
	freopen("TwoSet.inp","r",stdin);
	freopen("TwoSet.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	ll n;
	cin>>n;
	ll t = (n+1)*n/2;
	if (t%2==1) cout<<-1;
	else{
		ll s=0,k=0;
		bool f[1000001];
		memset(f,true,sizeof(f));
		for (ll i=1;i<=n;i++)
            d[i]=1;
		for (ll i=n;i>=1;--i){
			a[++k]=i;
			s+=i;
			f[i]=false;
			if ( t/2-s >= 1e6 ) continue;
			if ( f[t/2-s] && d[t/2-s]){
				a[++k]=t/2-s;
				f[t/2-s]=false;
				break;
            }
        }
		cout<<k<<"\n";
		for (ll i=k;i>=1;--i)
			cout << a[i] <<" ";
		cout<<"\n"<< n-k <<"\n";
		for (ll i=1;i<=n;++i)
            if (f[i])
                cout << i <<" ";
	}
	return 0;
}
