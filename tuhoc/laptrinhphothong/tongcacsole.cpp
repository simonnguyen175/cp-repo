#include <bits/stdc++.h>
using namespace std;
long long n,a[101],s;
int main()
{
    cin>>n;
    s=0;
    for (long long i=1; i<=n; i++)
    {
        cin>>a[i];
        if (a[i]%2!=0)
        {
            s=s+a[i];
        }
    }
    cout<<s;
}
