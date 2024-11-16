#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
const long long N=1000000;
long long f[50],d[50],t,n[105],k[105];
long long dequy(ll x,ll y)
{
	if(y==d[x]) return f[x];
	if(y<d[x-2]) return dequy(x-2,y);
	 return f[x-2]+dequy(x-1,y-d[x-2]);
}
int main()
{
  cin>>t;
  for(int i=1;i<=t;i++) cin>>n[i]>>k[i];
  f[0]=1,f[1]=0;
  d[0]=1,d[1]=1;
  for(int i=2;i<=45;i++)
  {
  	f[i]=f[i-2]+f[i-1];
  	d[i]=d[i-2]+d[i-1];
  }
  //cout<<f[45]<<" "<<d[45]<<endl;
  //cout<<INT_MAX;
  for(int i=1;i<=t;i++) cout<<dequy(n[i],k[i])<<endl;
}
