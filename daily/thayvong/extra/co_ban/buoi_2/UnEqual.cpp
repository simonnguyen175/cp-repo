#include <bits/stdc++.h>
using namespace std;
int a,b,c,m[1000],i;
int main()
{
    freopen("UnEqual.inp","r",stdin);
    freopen("UnEqual.out","w",stdout);
    cin>>a>>b>>c;
    for (i=1;i<=30;i++) m[i]=0;
    if (a>0) m[a]++;
    if (b>0) m[b]++;
    if (c>0) m[c]++;
    if (a+b>0) m[a+b]++;
    if (b+c>0) m[b+c]++;
    if (a+c>0) m[a+c]++;
    if (a+b+c>0) m[a+b+c]++;
    for (i=1; i<=30; i++)
    {
        if (m[i]==0) {cout<<i; break;}
    }
}
