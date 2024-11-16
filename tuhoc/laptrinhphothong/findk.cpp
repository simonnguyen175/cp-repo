#include <bits/stdc++.h>
using namespace std;
bool a[10000005],ok;
long long n,m,maX=INFINITY;
void createEratosthenes(long long n)
{
    a[1]=0;
    for(long long i=2;i<=n;i++)
        a[i]=1;
    for(long long i=2;i<=n/2;i++)
        if(a[i])
        for (long long j=2;j<=n/i;j++)
            a[i*j]=0;
}
long long counT(long long n,long long m)
{
    long long dem=0;
    long long a=m;
    while(m<n)
    {
        dem+=n/m;
        m*=a;
    }
    return dem;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    ok=0;
    createEratosthenes(m);
    for(int i=1;i<=m;i++)
        if((a[i])&&(m%i==0))
        {
            maX=min(maX,counT(n,i));
            ok=1;
        }
    if(maX!=0) cout<<maX; else cout<<-1;
    -11
}
