#include <bits/stdc++.h>
using namespace std;
long long n,x,y,i,j;
int main()
{
    cin>>n;
    for (i=1; i<=(int)sqrt(n); i++)
        if (n % i==0)
            {
                if (i%2==0) y+=i;
                    else x+=i;
                j=n/i;
                if (j!=i)
                    if (j%2==0) y+=j;
                        else x+=j;
            }
    int base = 123456789;
    cout<<((x*x)%base+(y*y)%base)%base;
}
