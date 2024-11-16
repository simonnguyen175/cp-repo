#include <bits/stdc++.h>
using namespace std;
int a,b,c,d,dau,cuoi;
int main()
{
    cin>>a>>b>>c>>d;
    dau=max(a,c); cuoi=min(b,d);
    cout<<(dau+cuoi)*(cuoi-dau+1)/2;
}
