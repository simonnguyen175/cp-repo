#include <bits/stdc++.h>
using namespace std;
long long n,a[101],i,j,s;
int main()
{
    cin>>n;
    for (i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for (i=1;i<=n-1;i++)
    {
        for (j=i+1;j<=n;j++)
        {
            if (a[i]>a[j]) s++;
        }
    }
    cout<<s;
}
