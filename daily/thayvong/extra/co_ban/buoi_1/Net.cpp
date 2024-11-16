#include <bits/stdc++.h>
using namespace std;
long long a,b,c,d,e,f,g,h,s1,s2,s3,s4;
int main ()
{
    cin>>a>>b>>c>>d>>e>>f>>g>>h;
    s1=a+c+g;
    s2=a+d+h;
    s3=b+f+h;
    s4=b+e+g;
    s1=min(s1,min(s2,min(s3,s4)));
    cout<<s1;
}
