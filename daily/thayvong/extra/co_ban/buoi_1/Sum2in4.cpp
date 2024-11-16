#include <bits/stdc++.h>
using namespace std;
long long a,b,c,d,s,k;
int main()
{
    cin>>a>>b>>c>>d>>s;
    k=0;
    if (a+b==s) k=1;
        else
            if (b+c==s) k=1;
                else
                    if (a+c==s) k=1;
                        else
                            if (a+d==s) k=1;
                                else
                                    if (b+d==s) k=1;
                                        else
                                            if (c+d==s) k=1;

    cout<<k;
}
