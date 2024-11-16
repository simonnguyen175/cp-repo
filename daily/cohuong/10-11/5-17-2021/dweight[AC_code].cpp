#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
int t,n;
pair<int,int> a[400];
int main()
{
    freopen("dweight.inp","r",stdin);
    freopen("dweight.out","w",stdout);
    cin>>t;
    while(t--)
    {
        set<pair<long long,int> > f;
        cin>>n;
        for(int i=1;i<=n;i++)
                cin>>a[i].fi>>a[i].se;
        for(int i=1;i<=n;i++)
            for(int j=i+1;j<=n;j++)
                {
                    if(a[i].fi==a[j].fi) continue;
                    long long x=(a[i].se-a[j].se),y=(a[j].fi-a[i].fi);
                    long long k=__gcd(x,y);
                    x=x/k;y=y/k;
                   // cout<<x<<' '<<y<<endl;
                    if((x>0&&y>0)||(x<0&&y<0)) {f.insert({x,y});}
                    //cout<<x<<' '<<y<<endl;
                }
        cout<<f.size()+1<<endl;
    }
    return 0;
}
