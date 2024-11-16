#include <bits/stdc++.h>
using namespace std;
long long a,b,c,d,e,s;
int main()
{
    cin>>a>>b>>c>>d>>e;
    if (a<0) s+=a;
    if (b<0) s+=b;
    if (c<0) s+=c;
    if (d<0) s+=d;
    if (e<0) s+=e;
    cout<<s;
}
