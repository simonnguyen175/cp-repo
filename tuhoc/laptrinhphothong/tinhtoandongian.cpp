#include <bits/stdc++.h>
using namespace std;
long long n,t,a[1000000];
long long tt(long long x)
    {
        return 5*x*x*x+3*x*x+4*x-11;
    }
int main()
{
    cin>>n;
    for (int i=1; i<=n; i++)
        {
            cin>>t;
            a[i]=tt(t);
        }
    for (int i=1; i<=n; i++)
        {
            cout<<a[i]<<endl;
        }
}
