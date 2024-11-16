#include <bits/stdc++.h>
using namespace std;
long long n, a[100001],nn;
int main()
{
    cin>>n;
    nn=1000000000;
    for (long long i=1;i<=n;i++)
    {
        cin>>a[i];
        if (a[i]%2!=0)
        {
            nn=min(nn,a[i]);
        }
    }
    cout<<nn;
}
