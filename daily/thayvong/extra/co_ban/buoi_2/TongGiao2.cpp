#include <bits/stdc++.h>
using namespace std;
long long a,b,c,d,dau,cuoi;
int main()
{
    freopen("TongGiao2.inp","r",stdin);
    freopen("TongGiao2.out","w",stdout);
    cin>>a>>b>>c>>d;
    if (b<c) cout<<0;
    dau=max(a,c); cuoi=min(b,d);
    cout<<(dau+cuoi)*(cuoi-dau+1)/2;
}
