#include <bits/stdc++.h>
using namespace std;
long long a,b,c,s;
int main()
{
    cin>>a>>b>>c;
    if (a%2!=0) s+=a;
    if (b%2!=0) s+=b;
    if (c%2!=0) s+=c;
    cout<<s;
}
