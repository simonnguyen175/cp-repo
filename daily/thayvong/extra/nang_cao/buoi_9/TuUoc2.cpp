#include <bits/stdc++.h>
#define emerald "TuUoc2"
#define l2 long long
#define mx 10000000
using namespace std;
l2 l,r,nt[1000005],n=0,t=0;
bool pr[mx+5];
void es()
{
    memset(pr,true,sizeof(pr));
    pr[0]=pr[1]=false;
    for(int i=2; i<=sqrt(mx); i++)
        if(pr[i])
            for(int j=i*i; j<=mx; j+=i)
                pr[j]=false;
}
int tim(l2 k,int d,bool type)
{
    int c=n,g,ans=-1;
    if(type)
    {
        while(d<=c)
        {
            g=d+c >> 1;
            if(nt[g]*k>=l)
            {
                ans=g;
                c=g-1;
            }
            else d=g+1;
        }
    }
    else
    {
        while(d<=c)
        {
            g=d+c >> 1;
            if(nt[g]*k<=r)
            {
                ans=g;
                d=g+1;
            }
            else c=g-1;
        }
    }
    return ans;
}
int main()
{
    freopen(emerald".INP","r",stdin);
    freopen(emerald".OUT","w",stdout);

    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    es();
    for(int i=2; i<=mx; i++)
        if(pr[i]) nt[++n]=i;

    cin>>l>>r;

    for(int i=1; i<=n; i++)
    {
        if(nt[i]*2>r) break;
        int s=tim(nt[i],i+1,true);
        int e=tim(nt[i],i+1,false);
        if(s!=-1&&e!=-1) t+=e-s+1;
    }
    for(l2 i=2; i>=1; i++)
        if(i*i*i>=l&&i*i*i<=r&&pr[i]) t++;
        else if(i*i*i>r) break;
    cout<<t;
}
