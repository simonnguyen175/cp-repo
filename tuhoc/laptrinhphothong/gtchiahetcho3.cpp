#include <bits/stdc++.h>
using namespace std;
long long n,a[1000],dem;
int main()
{
    cin>>n;
    dem=0;
    for (long long i=1; i<=n; i++)
    {
        cin>>a[i];
        if (a[i]%3==0) dem++;
    }
    cout<<dem;
}
