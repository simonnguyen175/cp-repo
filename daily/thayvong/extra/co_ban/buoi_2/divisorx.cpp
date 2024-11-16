#include <bits/stdc++.h>
using namespace std;
int a,b,c,x,s;
int main()
{
    cin>>a>>b>>c>>x;
    if (a%x==0) s+=a;
    if (b%x==0) s+=b;
    if (c%x==0) s+=c;
    cout<<s;
}
