#include<bits/stdc++.h>
using namespace std;
int n;
int main()
{
	freopen("ReFormN.inp","r",stdin);
	freopen("ReFormN.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	while(n!=1)
	{
		cout<<n<<" ";
		if (n%2==0) n/=2;
		else n=n*3+1;
	}
	cout<<1;
	return 0;
}
