#include <bits/stdc++.h>
using namespace std;
long long a,b,c,d,e,s,k;
int main()
{
    cin>>a>>b>>c>>d>>e>>s;
    if (a+b+c==s||a+b+d==s||a+b+e==s||a+c+d==s||a+c+e==s||b+c+d==s||b+c+e==s||b+d+e==s||c+d+e==s)
        k=1;
    else k=0;
    cout<<k;
}
