#include <bits/stdc++.h>
using namespace std;
int a,b,c,x,s,m;
int main()
{
    cin>>a>>b>>c>>x;
    s=a+b+c+x;
    if (s % 3==0)
    {
        m=s/3;
        if (m<a || m<b || m<c) cout<<"No";
        else cout<<"Yes";
    }
    else cout<<"No";
}
