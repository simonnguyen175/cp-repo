#include <bits/stdc++.h>
using namespace std;
long long n,a[1000000],i,l,r,dem;
bool nto(long long n)
    {
        if(n<=1) return false;
        else
            for (long long i=2; i<=sqrt(n); i++)
                if (n % i==0) return false;
        return true;
    }
int main()
{
    cin>>n; dem=0;
    for (i=1; i<=n; i++)cin>>a[i];
    for (i=1; i<=n; i++)
    {
        if (nto(a[i])) {l=i;break;}
    }
    for (i=n; i>=1; i--)
    {
        if (nto(a[i])) {r=i; break;}
    }
    cout<<r-l;
}
