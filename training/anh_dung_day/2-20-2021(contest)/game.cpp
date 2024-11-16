#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,a[101],temp=0,mx;

int main(){
	ios::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);
	cin>>n;
	for(ll i=1;i<=n;i++)
		cin>>a[i];
	mx=a[1];
	for(ll i=1;i<=n;i++){
		temp=max(temp,a[i]);
		mx=__gcd(mx,a[i]);
	}
	temp=temp/mx-n;
	if( temp % 2 == 0 ) cout << "Bob";
	else cout << "Alice";
	return 0;
}
