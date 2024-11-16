#include <bits/stdc++.h>
using namespace std;
unsigned long int n,a[10000000],s;
int main()
{
    s=0;
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
        s+=a[i];
    }
    cout<<s;
}
