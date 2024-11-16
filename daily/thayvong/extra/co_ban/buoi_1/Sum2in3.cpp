#include <bits/stdc++.h>
using namespace std;
long long a,b,c,s,d;
int main()
{
    cin>>a>>b>>c>>s; d=0;
    if (a+b==s) d=1;
        else
            if (b+c==s) d=1;
                else
                    if (a+c==s) d=1;

    cout<<d;
}
