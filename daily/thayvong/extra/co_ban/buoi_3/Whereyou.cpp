#include <bits/stdc++.h>
using namespace std;
long long n,t,i,j,h[100000],k[100000],d[10000000];
int main()
{
    cin>>n>>t;
    for (i=1; i<=n; i++) {cin>>h[i]; d[i]=h[i];}
    for (i=1; i<=t; i++) cin>>k[i];
    sort (h+1,h+1+n);
    for (i=1; i<=t; i++)
        for (j=1; j<=n; j++)
            if (d[k[i]]==h[j]) {cout<<j<<"\n";break;}
}
